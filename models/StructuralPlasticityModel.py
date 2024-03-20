from brian2 import *
import numpy as np
import matplotlib.pyplot as plt
from multiprocessing import Pool
import os
 
# cupy support currently not available
backend = 'numpy'
xp = __import__(backend)

import logging

class StructuralPlasticityModel:
    def __init__(self, params):
        """
        Initializes the structural plasticity model.

        Parameters:
        params (dict): A dictionary containing the parameters for the model.

        Returns:
        None
        """
        self.standalone = params.get('standalone', False)
        
        start_scope()

        self.network = Network()

        # Neurons
        self.N_E = 4*params.get('order', 2500)
        self.N_I = 1*params.get('order', 2500)
        self.V_th = params.get('V_th', 20*mV)
        self.V_res = params.get('V_res', 10*mV)
        self.t_ref = params.get('t_ref', 2*ms)
        self.tau_m = params.get('tau_m', 20*ms)
        self.eps = params.get('eps', 0.1)
        self.eta = params.get('eta', 1.5)
        self.CE    = int(self.eps*self.N_E)         # number of incoming excitatory synapses per inhibitory neuron
        self.CI    = int(self.eps*self.N_I)         # number of incoming inhibitory synapses per excitatory neuron  

        # Synapses
        self.J = params.get('J', 0.1*mV)
        self.g = params.get('g', 8)
        self.J_I = - self.J * self.g
        self.delay = params.get('delay', 1*ms)

        # Background Input
        self.nu_ext = params.get('nu_ext', 15*kHz)

        # Plasticity
        self.enable_plasticity = params.get('enable_plasticity', True)
        self.tau_ca = params.get('tau_ca', 1*second)
        self.delta_T_s = params.get('delta_T_s', 100*ms)
        self.nu = params.get('nu', 8*Hz)
        self.beta_d = params.get('beta_d', 2)
        self.beta_a = params.get('beta_a', 2)

        # Equations for neuron dynamics 
        inh_eqs = '''
        dv/dt = (- v / tau_m) : volt (unless refractory)
        nu_ext : 1
        '''
        #RI = poisson(nu_ext) * J: volt (constant over dt)
        exc_eqs = '''
        dv/dt = (- v / tau_m) : volt (unless refractory)
        nu_ext : 1
        dphi/dt = - phi / tau_ca : Hz
        dd/dt = (nu - phi)/beta_d : 1
        da/dt = (nu - phi)/beta_a : 1
        '''
        #RI = poisson(nu_ext) * J: volt (constant over dt)

        # Make class member variables accessable in brian
        self.namespace = {
            'tau_m': self.tau_m, 
            'tau_ca': self.tau_ca, 
            'nu': self.nu, 
            'beta_d': self.beta_d, 
            'beta_a': self.beta_a, 
            'J': self.J, 
            'J_I': self.J_I, 
            'tau_m': self.tau_m, 
            'v_th': self.V_th, 
            'v_res': self.V_res, 
            't_ref': self.t_ref, 
            'delay': self.delay,
            'N_I': self.N_I,
            'N_E': self.N_E,
            'CI': self.CI,
            'CE': self.CE,
        }

        # Create Neurons
        self.I = NeuronGroup(self.N_I, inh_eqs, threshold='v > v_th', reset='v=v_res', refractory=self.t_ref, method='euler', name='I')
        self.E = NeuronGroup(self.N_E, exc_eqs, threshold='v > v_th', reset='v=v_res\nphi+=(1/tau_ca)', refractory=self.t_ref, method='euler', name='E')
        
        #self.E.a = '1'
        #self.E.d = '1'

        self.E.nu_ext = self.nu_ext/ kHz
        self.I.nu_ext = self.nu_ext/ kHz
        
        self.P_E_1 = PoissonInput(self.E[:1000], rate=self.nu_ext/15, target_var='v', N=15, weight=self.J)
        self.P_E_2 = PoissonInput(self.E[1000:], rate=self.nu_ext/15, target_var='v', N=15, weight=self.J)
        self.P_I = PoissonInput(self.I, rate=self.nu_ext/15, target_var='v', N=15, weight=self.J )

        self.network.add(self.P_E_1, self.P_E_2, self.P_I)
        # Static Synapses
        self.S_I_I = Synapses(self.I, self.I, on_pre='v_post += J_I', delay=self.delay, name='S_I_I')
        #self.S_I_I.connect(condition='i != j', p=self.eps)
        self.S_I_I.connect(i='k for k in sample(N_I, size=CI)', namespace=self.namespace)
        
        self.S_I_E = Synapses(self.I, self.E, on_pre='v_post += J_I', delay=self.delay, name='S_I_E')
        #self.S_I_E.connect(condition='i != j', p=self.eps)
        self.S_I_E.connect(i='k for k in sample(N_I, size=CI)', namespace=self.namespace)
        
        self.S_E_I = Synapses(self.E, self.I, on_pre='v_post += J', delay=self.delay, name='S_E_I')
        #self.S_E_I.connect(condition='i != j', p=self.eps)
        self.S_E_I.connect(i='k for k in sample(N_E, size=CE)', namespace=self.namespace)
        
        # Dynamic synapses
        self.S_E_E = Synapses(self.E, self.E, model='''
        c : 1
        '''
        ,on_pre='v_post += c*J', delay=self.delay, name='S_E_E')
        self.S_E_E.connect()

        # Set up recording
        self.E_con = []
        self.E_con_t = []
        #self.spike_mon_I = SpikeMonitor(self.I, name='spikemonitor')
        #self.spike_mon_E = SpikeMonitor(self.E, name='spikemonitor_1')

        self.network.add(self.E, self.I, self.S_I_I, self.S_I_E, self.S_E_I, self.S_E_E)#, self.spike_mon_E, self.spike_mon_I)
        

        if(self.standalone):
            print("standalone")
            self.sp_standalone()

            current_dir = os.path.dirname(os.path.dirname(__file__))

            @implementation('cpp', '', 
            sources=[os.path.join(current_dir, 'cpp', 'rewire.cpp')],
            headers=['"rewire.h"'],
            include_dirs=[os.path.join(current_dir, 'cpp')]
            )
            @check_units(start_g1=1, end_g1=1, start_g2=1, end_g2=1, result=1)
            def record_mean(start_g1, end_g1, start_g2, end_g2):
                return xp.mean(self.S_E_E.c[start_g1:end_g1, start_g2:end_g2])
            
            self.namespace['record_mean'] = record_mean
            
            self.ConMean = NeuronGroup(1, '''
            c_1_1 = record_mean(0, 1000, 0, 100) : 1 (constant over dt)
            c_1_2 = record_mean(0, 1000, 1000, 10000) : 1 (constant over dt)
            c_2_1 = record_mean(1000, 10000, 0, 1000) : 1 (constant over dt)
            c_2_2 = record_mean(1000, 10000, 1000, 10000) : 1 (constant over dt)
            ''', 
            dt=10*second, name='ConMean')
            
            self.network.add(self.ConMean)
        else:
            # Set up structural plasticity
            if self.enable_plasticity:
                self.sp_manager = StructuralPlasticityManager(
                    self.S_E_E, 
                    self.S_E_E.c.variable.get_value(),
                    self.E.a.variable.get_value(), 
                    self.E.d.variable.get_value()
                )
                self.structural_plasticity = network_operation(dt=self.delta_T_s)(self.sp_manager.rewiring)
                self.network.add(self.structural_plasticity)


            
    def sp_standalone(self):
        '''
        Standalone implementation of the structural plasticity mechanism
        '''

        current_dir = os.path.dirname(os.path.dirname(__file__))

        @implementation('cpp', '', 
        sources=[os.path.join(current_dir, 'cpp', 'rewire.cpp')],
        headers=['"rewire.h"'],
        include_dirs=[os.path.join(current_dir, 'cpp')],
        )
        @check_units(result=1)
        def rewire():
            print('rewire', file=sys.stderr)

        self.namespace['rewire'] = rewire 

        self.Test = NeuronGroup(1, '''
        c = rewire() : 1 (constant over dt)
        ''', dt=self.delta_T_s, name='Test')
        
        self.network.add(self.Test)


    def run(self, duration, **kwargs):
        """
        Runs the simulation for a given duration.

        Parameters:
        duration (float): The duration of the simulation.

        Returns:
        None
        """

        self.network.run(duration, namespace=self.namespace, report='text', report_period=20*second, **kwargs)

    def plot(self):
        """
        Plots the spike trains of the excitatory and inhibitory neurons.
        If plasticity is enabled, it also plots the average synaptic weight over time.

        Returns:
        None
        """
#        plt.plot(self.spike_mon_E.t/ms, self.spike_mon_E.i, ',k')
#        plt.xlabel('Time (ms)')
#        plt.ylabel('Neuron index')
#        plt.title('Excitatory neurons')
#        plt.show()
#
#        plt.plot(self.spike_mon_I.t/ms, self.spike_mon_I.i, ',k')
#        plt.xlabel('Time (ms)')
#        plt.ylabel('Neuron index')
#        plt.title('Inhibitory neuron')
#        plt.show()

        if(self.enable_plasticity):
            plt.plot(self.sp_manager.mean_con_t, self.sp_manager.mean_con)
            plt.xlabel('Time (ms)')
            plt.ylabel('Average synaptic weight')
            plt.show()

class StructuralPlasticityManager:
    """
    Class for performing the structural plasticity mechanism of the network.
    """

    def __init__(self, synapses, connectivity, a, d):
        self.synapses = synapses
        self.connectivity = connectivity
        self.a = a
        self.d = d
        self.neuron_count = self.a.shape[0]
        self.mean_con = []
        self.mean_con_t = []

    def _delete_connections(self, num, connections):
        """
        Deletes num random connections for a neuron.

        Parameters:
        num (int): The number of elements to be deleted.
        connections (ndarray): The current connections for one neuron.

        Returns:
        None
        """
        
        if(num > 0):
            gen = np.random.default_rng()
            x =  np.arange(0, self.neuron_count, dtype=int).repeat(connections)   
            gen.shuffle(x)
            idx, cnt = np.unique(x[:min(num, len(x))], return_counts=True)
            connections[idx] -= cnt

    def delete_connections_pre(self, connection_matrix, delta_a):
        """
        Deletes random outgoing connections based on the number of axonal elements to be deleted for each neuron.

        Parameters:
        connection_matrix (ndarray): The current connectivity matrix.
        delta_d (ndarray): The number of dendritic elements to be deleted for each neuron.

        Returns:
        None
        """

        for num, connections in zip(delta_a, connection_matrix):
	        self._delete_connections(num, connections)
        
    def delete_connections_post(self, connection_matrix, delta_d):
        """
        Deletes random incoming connections based on the number of dendritic elements to be deleted for each neuron.

        Parameters:
        connection_matrix (ndarray): The current connectivity matrix.
        delta_d (ndarray): The number of dendritic elements to be deleted for each neuron.

        Returns:
        None
        """

        for num, connections in zip(delta_d, connection_matrix.T):
	        self._delete_connections(num, connections)
        
    def select_connections(self, delta_a, delta_d, skip_self_connections=True):
        """
        Selects new connections between free elements randomly.

        Parameters:
        delta_a (ndarray): The number of free axonal elements
        delta_d (ndarray): The number of free dendritic elements
        skip_self_connections (bool): Whether autapses are allowed.

        Returns:
        ndarray: The chosen connections.
        """

        # Calculate number of new connections
        a_free = xp.floor(delta_a).clip(0).astype(int)
        d_free = xp.floor(delta_d).clip(0).astype(int)
        a_tot = xp.sum(a_free)
        d_tot = xp.sum(d_free)
        num_connections = min(a_tot, d_tot)

        # List all synaptic elements
        a_free = xp.arange(0, self.neuron_count, dtype=int).repeat(a_free.tolist())
        d_free = xp.arange(0, self.neuron_count, dtype=int).repeat(d_free.tolist())
        
        # Shuffle longer list
        if(d_tot <= a_tot):
            xp.random.shuffle(a_free)
        else:
            xp.random.shuffle(d_free)

        # Make sure both arrays have the same length, drop elements from the end
        a_free = a_free[:num_connections]
        d_free = d_free[:num_connections]

        # Make array of tuples of chosen connections
        chosen_connections = xp.column_stack((a_free, d_free))

        # Count duplicates
        chosen_connections, counts = np.unique(chosen_connections, axis=0, return_counts=True)

        # If we want to skip self connections, remove them
        if skip_self_connections and len(chosen_connections) > 0:
            mask = chosen_connections[:,0] != chosen_connections[:,1]
            chosen_connections = chosen_connections[mask]
            counts = counts[mask]
            
        return chosen_connections, counts

    def create_connections(self, connections, delta_a, delta_d):
        """
        Creates new random connections between free elements.

        Parameters:
        connections (ndarray): The current connectivity matrix.
        delta_a (ndarray): The number of free axonal elements.
        delta_d (ndarray): The number of free dendritic elements.

        Returns:
        ndarray: The updated connectivity matrix.
        """
        
        chosen_connections, counts = self.select_connections(delta_a, delta_d)

        # Increase weight of chosen connections
        connections[chosen_connections[:,0], chosen_connections[:,1]] += counts
        
        return connections

    def rewiring(self, t):
        """
        Performs the rewiring process on the connectivity matrix.
    
        Parameters:
        t (float): The current time in the simulation.
    
        Returns:
        None
        """

        # Reshape connectivity matrix
        connections = self.connectivity.reshape(self.neuron_count, self.neuron_count).astype(int)

        # Get number of free/deleted elements
        delta_a = (xp.floor(self.a) - xp.sum(connections, axis=1)).astype(int)
        delta_d = (xp.floor(self.d) - xp.sum(connections, axis=0)).astype(int)

        # Remove connections for deleted axonal elements
        self.delete_connections_pre(connections, -delta_a)

        # Remove connections for deleted dentritic elements
        self.delete_connections_post(connections, -delta_d)

        # Create new connections between free elements
        connections = self.create_connections(connections, delta_a, delta_d)
        
        self.connectivity[:] = connections.flatten()

        # Log mean connnectivity
        self.mean_con_t.append(t/ms)
        self.mean_con.append(xp.mean(self.connectivity))
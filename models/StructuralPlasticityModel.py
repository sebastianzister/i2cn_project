from brian2 import *
#import brian2cuda
#set_device("cuda_standalone")
#import cupy as np
import numpy as np
import matplotlib.pyplot as plt
from multiprocessing import Pool
import time 
 
# TODO: make backend configurable cpu(numpy)/gpu(cupy) 
import numpy as np
backend = 'numpy'# if np.get_device() else 'numpy'
xp = __import__(backend)

import logging

def connect_synases_fixed_indegree(synapses, indegree, N_post, N_pre):
    for j in range(N_post):
        pre_neurons = xp.random.choice(N_pre, indegree, replace=False)
        synapses.connect(i=pre_neurons, j=j)

class StructuralPlasticityModel:
    def __init__(self,
                dt = 0.1*ms,
                order = 25,
                V_th = 20*mV,
                V_res = 10*mV,
                t_ref = 2*ms,
                tau_m = 20*ms,
                nu_ext = 15*kHz,
                J = 0.1*mV,
                g = 8,
                delay = 1*ms,
                tau_ca = 1*second,
                delta_T_s = 100*ms,
                nu = 8*Hz,
                beta_d = 2,
                beta_a = 2,
                enable_plasticity = True,
                allow_autapses = False,
                processes = None):

        start_scope()
        


        self.network = Network()

        # Neurons
        self.N_E = 4*order
        self.N_I = 1*order
        self.V_th = V_th
        self.V_res = V_res
        self.t_ref = t_ref
        self.tau_m = tau_m

        # Background Input
        self.nu_ext = nu_ext/kHz
        # Synapses
        self.J = J# * self.tau_m/ms
        self.g = g
        self.J_I = - J * g
        self.delay = delay

        # Plasticity
        self.tau_ca = tau_ca
        self.delta_T_s = delta_T_s
        self.nu = nu
        self.beta_d = beta_d
        self.beta_a = beta_a

        inh_eqs = '''
        dv/dt = (- v / tau_m) + (RI/ms) : volt (unless refractory)
        RI = poisson(nu_ext) * J: volt (constant over dt)
        nu_ext : 1
        '''
        exc_eqs = '''
        dv/dt = (- v / tau_m) + (RI/ms) : volt (unless refractory)
        RI = poisson(nu_ext) * J: volt (constant over dt)
        nu_ext : 1
        dphi/dt = - phi / tau_ca : Hz
        dd/dt = (nu - phi)/beta_d : 1
        da/dt = (nu - phi)/beta_a : 1
        '''

        self.namespace = {'tau_m': self.tau_m, 'tau_ca': self.tau_ca, 'nu': self.nu, 'beta_d': self.beta_d, 'beta_a': self.beta_a, 'J': self.J, 'J_I': self.J_I, 'tau_m': self.tau_m, 'v_th': self.V_th, 'v_res': self.V_res, 't_ref': self.t_ref, 'delay': self.delay}

        
        # Create Neurons
        self.I = NeuronGroup(self.N_I, inh_eqs, threshold='v > v_th', reset='v=v_res', refractory=self.t_ref, name='I')
        self.E = NeuronGroup(self.N_E, exc_eqs, threshold='v > v_th', reset='v=v_res\nphi+=1*Hz', refractory=self.t_ref, name='E')

        self.network.add(self.E, self.I)
        
        self.E.nu_ext = nu_ext / kHz
        self.I.nu_ext = nu_ext / kHz
        
        # Static Synapses
        #TODO: allow for autapses
        self.S_I_I = Synapses(self.I, self.I, on_pre='v_post += J_I', delay=self.delay, name='S_I_I')
        #TODO: use fixed in-degree instead of probability
        self.S_I_I.connect(condition='i != j', p=0.1)
        #connect_synases_fixed_indegree(self.S_I_I, int(0.1*self.N_I), self.N_I, self.N_I)
        
        self.S_I_E = Synapses(self.I, self.E, on_pre='v_post += J_I', delay=self.delay, name='S_I_E')
        self.S_I_E.connect(condition='i != j', p=0.1)
        #connect_synases_fixed_indegree(self.S_I_E, int(0.1*self.N_I), self.N_E, self.N_I)
        
        self.S_E_I = Synapses(self.E, self.I, on_pre='v_post += J', delay=self.delay, name='S_E_I')
        self.S_E_I.connect(condition='i != j', p=0.1)
        #connect_synases_fixed_indegree(self.S_E_I, int(0.1*self.N_E), self.N_I, self.N_E)
        
        # Dynamic synapses
        self.S_E_E = Synapses(self.E, self.E, model='''
        c : 1
        '''
        ,on_pre='v_post += c*J', delay=self.delay, name='S_E_E')
        self.S_E_E.connect()
        
        self.C_E = []
        self.C_E_t = []
        self.spike_mon_I = SpikeMonitor(self.I, name='spikemonitor')
        self.spike_mon_E = SpikeMonitor(self.E, name='spikemonitor_1')

        self.network.add(self.S_I_I, self.S_I_E, self.S_E_I, self.S_E_E, self.spike_mon_E, self.spike_mon_I)#, self.M2)

        if enable_plasticity:
            self.structural_plasticity = network_operation(dt=self.delta_T_s)(self.rewiring)
            self.network.add(self.structural_plasticity)
            
        if processes is None:
            self.processes = 1#self._test_processes()
        else:
            self.processes = processes
        # debug
        self.rewiring_time = 0

    def run(self, duration):
        self.network.run(duration, namespace=self.namespace, report='text', report_period=20*second)
    
    def _delete_connections(self, num, connections):
        if(num > 0):
            gen = np.random.default_rng()
            x =  np.arange(0, self.N_E, dtype=int).repeat(connections)   
            gen.shuffle(x)
            idx, cnt = np.unique(x[:min(num, len(x))], return_counts=True)
            connections[idx] -= cnt

    def delete_connections_pre(self, connection_matrix, delta_a):
        #with Pool(self.processes) as pool:
	    for num, connections in zip(delta_a, connection_matrix):
	        self._delete_connections(num, connections)
	    #        pool.apply_async(self._delete_connections, (num, connections, ))
        
    def delete_connections_post(self, connection_matrix, delta_d):
	    for num, connections in zip(delta_d, connection_matrix.T):
	        self._delete_connections(num, connections)
#        with Pool(self.processes) as pool:
#	        for num, connections in zip(delta_d, connection_matrix.T):
#	            pool.apply_async(self._delete_connections, (num, connections, ))
        
    def select_connections(self, delta_a, delta_d, skip_self_connections=True):
        # Calculate number of new connections
        a_free = xp.floor(delta_a).clip(0).astype(int)
        d_free = xp.floor(delta_d).clip(0).astype(int)
        a_tot = xp.sum(a_free)
        d_tot = xp.sum(d_free)
        num_connections = min(a_tot, d_tot)
        #print("Creating {} new connections".format(num_connections))

        # List all synaptic elements
        a_free = xp.arange(0, self.N_E, dtype=int).repeat(a_free.tolist())
        d_free = xp.arange(0, self.N_E, dtype=int).repeat(d_free.tolist())
        
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

        if backend == 'numpy':
            # count duplicates
            chosen_connections, counts = np.unique(chosen_connections, axis=0, return_counts=True)

            # If we want to skip self connections, remove them
            if skip_self_connections and len(chosen_connections) > 0:
                mask = chosen_connections[:,0] != chosen_connections[:,1]
                chosen_connections = chosen_connections[mask]
                counts = counts[mask]
                
        # TODO: For cupy or in general => interpret indicies as 16bit, and concatenate to 32bit int, for 1D array
        #       Run unique and cast back
        elif backend == 'cupy':
            if skip_self_connections and len(chosen_connections) > 0:
                mask = chosen_connections[:,0] != chosen_connections[:,1]
                chosen_connections = chosen_connections[mask]
            counts = xp.ones(len(chosen_connections), dtype=int)
            
        return chosen_connections, counts

    def create_connections(self, connections, delta_a, delta_d):
        
        chosen_connections, counts = self.select_connections(delta_a, delta_d)
        # move to cpu 
        if backend == 'cupy':
            chosen_connections = xp.asnumpy(chosen_connections)
            counts = xp.asnumpy(counts)

        # Increase weight of chosen connections
        connections[chosen_connections[:,0], chosen_connections[:,1]] += counts
        
        return connections
    
    def rewiring(self, t):
        logger = logging.getLogger('rewiring')
        logger.debug("")
        logger.debug('Rewiring at t = ' + str(t/ms))

        tmp_time = time.time()
        start_time = time.time()
        # Get connectivity matrix
        connections = xp.array(self.S_E_E.c.variable.get_value()).astype(int).reshape(self.N_E, self.N_E)
        logger.debug("GetTime: " + str(time.time() - start_time))


        tmp_time = time.time()
        # Get number of free/deleted elements
        # TODO: Check if we sum over the right axes for dendritic/axonal elements
        delta_a = (xp.floor(xp.array(self.E.a[:])) - xp.sum(connections, axis=1)).astype(int)
        delta_d = (xp.floor(xp.array(self.E.d[:])) - xp.sum(connections, axis=0)).astype(int)
        logger.debug("DeltaTime: " + str(time.time() - tmp_time))

        tmp_time = time.time()
        # delete axonal elements
        self.delete_connections_pre(connections, -delta_a)
        logger.debug("PreTime: " + str(time.time() - tmp_time))

        tmp_time = time.time()
        # delete dendritic elements
        self.delete_connections_post(connections, -delta_d)
        logger.debug("PostTime: " + str(time.time() - tmp_time))

        tmp_time = time.time()
        # create new connections between free elements
        connections = self.create_connections(connections, delta_a, delta_d)
        logger.debug("CreateTime: " + str(time.time() - tmp_time))

        tmp_time = time.time()
        # log mean connnectivity
        self.S_E_E.c.variable.set_value(connections.flatten())
        self.C_E_t.append(t/ms)

        self.C_E.append(xp.mean(self.S_E_E.c.variable.get_value()))
        logger.debug("RecordTime: " + str(time.time() - tmp_time))
        
        self.rewiring_time += time.time() - start_time
        logger.debug("TotalTime: " + str(time.time() - start_time))

    def plot(self):
        plt.plot(self.spike_mon_E.t/ms, self.spike_mon_E.i, ',k')
        plt.xlabel('Time (ms)')
        plt.ylabel('Neuron index')
        plt.title('Excitatory neurons')
        plt.show()

        plt.plot(self.spike_mon_I.t/ms, self.spike_mon_I.i, ',k')
        plt.xlabel('Time (ms)')
        plt.ylabel('Neuron index')
        plt.title('Inhibitory neurons')
        plt.show()
#
#        plt.plot(self.M2.t/ms, self.M2.V[0]/mV)
#        plt.xlabel('Time (ms)')
#        plt.ylabel('Membrane potential (mV)')
#        plt.show()

        plt.plot(self.C_E_t, self.C_E)
        plt.xlabel('Time (ms)')
        plt.ylabel('Average synaptic weight')
        plt.show()
        
    # Tests how many threads to use in deleting step for network size
    def _test_processes(self, num_trials=1, max_thread=12):
        print("Starting multiprocessing test")
        print("Specify the number of processes when creating the network to skip this")
        num_threads = range(1, max_thread+1)
        times = []
        for i in range(0, num_trials):
            print("Trial: ", i)
            c = np.random.randint(0, 3, size=(self.N_E, self.N_E))
            a = np.random.randint(0, c.sum(axis=1), size=(self.N_E))
        
            for pool_size in num_threads:
                c_bak = c.copy()
                tmp_time = time.time()
                pool = Pool(pool_size)
            
                for num, row in zip(a, c_bak):
                    pool.apply_async(self._delete_connections, (num, row, ))
                
                pool.close()
                pool.join()
                times.append(time.time() - tmp_time)
                #print("Time with ", pool_size, " Threads: ", times[-1])
                
            
        mean_times = np.array(times).reshape((num_trials, -1)).sum(axis=0)/num_trials
        best = argmin(mean_times)
        plt.plot(num_threads, mean_times)
        plt.show()
        print("Best results with ", best + 1, " processes")
        return best + 1
        


    
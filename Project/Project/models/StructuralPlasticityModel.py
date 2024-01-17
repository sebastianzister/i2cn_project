from brian2 import *
#import cupy as np
#import numpy as np
import matplotlib.pyplot as plt
import time 

# TODO: make backend configurable cpu(numpy)/gpu(cupy) 
import numpy as np
backend = 'numpy'# if np.get_device() else 'numpy'
xp = __import__(backend)

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
                allow_autapses = False):

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
        self.nu_ext = nu_ext
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
        dV/dt = - V / tau_m : volt (unless refractory)
        '''
        exc_eqs = '''
        dV/dt = - V / tau_m : volt (unless refractory)
        dphi/dt = - phi / tau_ca : Hz
        dd/dt = (nu - phi)/beta_d : 1
        da/dt = (nu - phi)/beta_a : 1
        '''

        self.namespace = {'tau_m': self.tau_m, 'tau_ca': self.tau_ca, 'nu': self.nu, 'beta_d': self.beta_d, 'beta_a': self.beta_a, 'J': self.J, 'J_I': self.J_I, 'tau_m': self.tau_m, 'V_th': self.V_th, 'V_res': self.V_res, 't_ref': self.t_ref, 'nu_ext': self.nu_ext, 'delay': self.delay}

        
        # Create Neurons
        # TODO: somehow threshold greater equeal does not work
        self.E = NeuronGroup(self.N_E, exc_eqs, threshold='V > V_th', reset='V=V_res\nphi+=1*Hz', refractory=self.t_ref, name='E')
        #\nphi+=1/tau_ca
        self.I = NeuronGroup(self.N_I, inh_eqs, threshold='V > V_th', reset='V=V_res', refractory=self.t_ref, name='I')
        
        # Background Input
        # #(tau_m/ms)*
        self.P_E = PoissonInput(self.E, 'V', 1, self.nu_ext, J, when='before_thresholds')
        self.P_I = PoissonInput(self.I, 'V', 1, self.nu_ext, J, when='before_thresholds')

        self.network.add(self.E, self.I, self.P_E, self.P_I)
        
        # Static Synapses
        #TODO: allow for autapses
        self.S_I_I = Synapses(self.I, self.I, on_pre='V_post += J_I', delay=self.delay, name='S_I_I')
        #TODO: use fixed in-degree instead of probability
        self.S_I_I.connect(condition='i != j', p=0.1)
        #connect_synases_fixed_indegree(self.S_I_I, int(0.1*self.N_I), self.N_I, self.N_I)
        
        self.S_I_E = Synapses(self.I, self.E, on_pre='V_post += J_I', delay=self.delay, name='S_I_E')
        self.S_I_E.connect(condition='i != j', p=0.1)
        #connect_synases_fixed_indegree(self.S_I_E, int(0.1*self.N_I), self.N_E, self.N_I)
        
        self.S_E_I = Synapses(self.E, self.I, on_pre='V_post += J', delay=self.delay, name='S_E_I')
        self.S_E_I.connect(condition='i != j', p=0.1)
        #connect_synases_fixed_indegree(self.S_E_I, int(0.1*self.N_E), self.N_I, self.N_E)
        
        print("S_I_I: ", self.S_I_I.N)
        print("S_I_E: ", self.S_I_E.N)
        print("S_E_I: ", self.S_E_I.N)
        # Dynamic synapses
        self.S_E_E = Synapses(self.E, self.E, model='''
        c : 1
        '''
        ,on_pre='V_post += c*J', delay=self.delay, name='S_E_E')
        self.S_E_E.connect()
        
        self.C_E = []
        self.C_E_t = []
        self.spike_mon_I = SpikeMonitor(self.I)
        self.spike_mon_E = SpikeMonitor(self.E)
        self.M2 = StateMonitor(self.E, ['V', 'phi'], record=True)

        self.network.add(self.S_I_I, self.S_I_E, self.S_E_I, self.S_E_E, self.spike_mon_E, self.spike_mon_I, self.M2)

        if enable_plasticity:
            self.structural_plasticity = network_operation(dt=self.delta_T_s)(self.rewiring)
            self.network.add(self.structural_plasticity)

    def run(self, duration):
        self.network.run(duration, namespace=self.namespace, report='text', report_period=20*second)
    
    def _repeated_hypergeometric(self, colors, nsamples):
        nsamples = xp.clip(nsamples,0, np.sum(colors, axis=0))
        total_objects = xp.sum(colors, axis=0)
        #print("Deleting: ", sum(nsamples))
        gen = xp.random.default_rng()
        for color in colors:
            #print("total_objects_before: ", total_objects)
            total_objects -= color
            #print("color: ", color, "total_objects: ", total_objects, "nsamples: ",nsamples)
            removed_colors = gen.hypergeometric(color, total_objects, nsamples)
            #print("removed_colors: ", removed_colors)
            color -= removed_colors
            nsamples -= removed_colors
        return colors
        
    def delete_connections_post(self, delta_a, delta_d):
        print('Deleting {} pre-synaptic connections'.format(-xp.sum(delta_a[delta_a < 0])))
        gen = xp.random.default_rng()
        for i, d_a in enumerate(delta_a):
            if(d_a < 0): 
                # sample deleted connections without replacement
                delta_Ci = gen.multivariate_hypergeometric(
                    self.S_E_E.c[i, :].astype(int).flatten(), 
                    xp.clip(-d_a, 0, sum(self.S_E_E.c[i, :].astype(int))),
                    method='count'
                )
                # update connectivity matrix and free dentritic elements
                self.S_E_E.c[i, :] -= delta_Ci
                # TODO: Maybe this should be done after rewiring, to delay to next timestep
                delta_d += delta_Ci
        return delta_a, delta_d 
    
    def delete_connections_pre(self, delta_a, delta_d):
        print('Deleting {} post-synaptic connections'.format(-xp.sum(delta_d < 0)))
        gen = xp.random.default_rng()
        for i, d_d in enumerate(delta_d):
            if(d_d < 0):
                # sample deleted connections without replacement
                delta_Ci = gen.multivariate_hypergeometric(
                    self.S_E_E.c[:, i].astype(int).flatten(), 
                    xp.clip(-d_d, 0, sum(self.S_E_E.c[:, i].astype(int))),
                    method='count'
                )
                # update connectivity matrix and free axonal elements
                self.S_E_E.c[:, i] -= delta_Ci
                # TODO: Maybe this should be done after rewiring, to delay to next timestep
                delta_a += delta_Ci
        return delta_a, delta_d

    def select_connections(self, delta_a, delta_d, skip_self_connections=True):
        # Calculate number of new connections
        a_free = xp.floor(delta_a).clip(0).astype(int)
        d_free = xp.floor(delta_d).clip(0).astype(int)
        a_tot = xp.sum(a_free)
        d_tot = xp.sum(d_free)
        num_connections = min(a_tot, d_tot)
        #print("Creating {} new connections".format(num_connections))

        # TODO: Choose random connections -> hypergeometric distribution
#        a_free = xp.arange(0, self.N_E, dtype=int).repeat(a_free.tolist())
#        d_free = xp.arange(0, self.N_E, dtype=int).repeat(d_free.tolist())
#        if(d_tot <= a_tot):
#            xp.random.shuffle(d_free)
#        else:
#            xp.random.shuffle(a_free)
#
#        # Make sure both arrays have the same length, drop elements from the end
#        a_free = a_free[:num_connections]
#        d_free = d_free[:num_connections]
        a_free = xp.arange(0, self.N_E, dtype=int).repeat(a_free.tolist())
        #print("a_free: ", a_free, a_free.shape)
        #print("num_connections: ", num_connections)
        if len(a_free) > 0:
            a_free = xp.random.choice(a_free, num_connections, replace=False)
        d_free = xp.arange(0, self.N_E, dtype=int).repeat(d_free.tolist())
        #print("d_free: ", d_free, d_free.shape)
        if len(d_free) > 0:
            d_free = xp.random.choice(d_free.flatten(), num_connections, replace=False)
   
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
        elif backend == 'cupy':
            if skip_self_connections and len(chosen_connections) > 0:
                mask = chosen_connections[:,0] != chosen_connections[:,1]
                chosen_connections = chosen_connections[mask]
            counts = xp.ones(len(chosen_connections), dtype=int)

        
        return chosen_connections, counts

    def create_connections(self, delta_a, delta_d):
        
        chosen_connections, counts = self.select_connections(delta_a, delta_d)
        # move to cpu 
        if backend == 'cupy':
            chosen_connections = xp.asnumpy(chosen_connections)
            counts = xp.asnumpy(counts)

        # Increase weight of chosen connections
    
        # TODO: This loop should be vectorized
    
        for i in range(len(chosen_connections)):
            self.S_E_E.c[chosen_connections[i][0],chosen_connections[i][1]] += counts[i]
    
    def rewiring(self, t):
        # Calculate the number of new/deleted connections for each neuron
        #print('Rewiring at t = ', t/ms)

        tmp_time = time.time()
        delta_a = (xp.floor(xp.array(self.E.a[:])) - xp.sum(xp.array(self.S_E_E.c[:,:]).reshape(self.N_E, self.N_E), axis=1)).astype(int)
        delta_d = (xp.floor(xp.array(self.E.d[:])) - xp.sum(xp.array(self.S_E_E.c[:,:]).reshape(self.N_E, self.N_E), axis=1)).astype(int)
        #print('Time for calculating delta_a and delta_d: ', time.time() - tmp_time)

        tmp_time = time.time()
        self.S_E_E.c[:,:] = self._repeated_hypergeometric(self.S_E_E.c[:,:].astype(int).reshape(self.N_E, self.N_E), -delta_a).flatten()
        #print('Time for vectoriced hypergeo pre: ', time.time() - tmp_time)

#        tmp_time = time.time()
#        delta_a, delta_d = self.delete_connections_pre(delta_a, delta_d)
#        print('Time for deleting connections: ', time.time() - tmp_time)
        delta_d_bak = delta_d.copy()
        tmp_time = time.time()
        self.S_E_E.c[:,:] = self._repeated_hypergeometric(self.S_E_E.c[:,:].astype(int).reshape(self.N_E, self.N_E).transpose(), -delta_d_bak).transpose().flatten()
        #print('Time for vectoriced hypergeo post: ', time.time() - tmp_time)

#        tmp_time = time.time()
#        delta_a, delta_d = self.delete_connections_post(delta_a, delta_d)
#        print('Time for deleting connections: ', time.time() - tmp_time)

        tmp_time = time.time()
        self.create_connections(delta_a, delta_d)
        #print('Time for creating connections: ', time.time() - tmp_time)

        self.C_E_t.append(t/ms)
        self.C_E.append(xp.sum(self.S_E_E.c[:,:])/self.N_E**2)

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


    
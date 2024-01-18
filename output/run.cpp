#include<stdlib.h>
#include "objects.h"
#include<ctime>
#include "randomkit.h"

#include "code_objects/neurongroup_10_spike_resetter_codeobject.h"
#include "code_objects/neurongroup_10_spike_thresholder_codeobject.h"
#include "code_objects/neurongroup_10_stateupdater_codeobject.h"
#include "code_objects/neurongroup_11_spike_resetter_codeobject.h"
#include "code_objects/neurongroup_11_spike_thresholder_codeobject.h"
#include "code_objects/neurongroup_11_stateupdater_codeobject.h"
#include "code_objects/neurongroup_1_spike_resetter_codeobject.h"
#include "code_objects/neurongroup_1_spike_thresholder_codeobject.h"
#include "code_objects/neurongroup_1_stateupdater_codeobject.h"
#include "code_objects/neurongroup_2_spike_resetter_codeobject.h"
#include "code_objects/neurongroup_2_spike_thresholder_codeobject.h"
#include "code_objects/neurongroup_2_stateupdater_codeobject.h"
#include "code_objects/neurongroup_3_spike_resetter_codeobject.h"
#include "code_objects/neurongroup_3_spike_thresholder_codeobject.h"
#include "code_objects/neurongroup_3_stateupdater_codeobject.h"
#include "code_objects/neurongroup_8_spike_resetter_codeobject.h"
#include "code_objects/neurongroup_8_spike_thresholder_codeobject.h"
#include "code_objects/neurongroup_8_stateupdater_codeobject.h"
#include "code_objects/neurongroup_9_spike_resetter_codeobject.h"
#include "code_objects/neurongroup_9_spike_thresholder_codeobject.h"
#include "code_objects/neurongroup_9_stateupdater_codeobject.h"
#include "code_objects/neurongroup_spike_resetter_codeobject.h"
#include "code_objects/neurongroup_spike_thresholder_codeobject.h"
#include "code_objects/neurongroup_stateupdater_codeobject.h"
#include "code_objects/poissoninput_10_codeobject.h"
#include "code_objects/poissoninput_11_codeobject.h"
#include "code_objects/poissoninput_1_codeobject.h"
#include "code_objects/poissoninput_2_codeobject.h"
#include "code_objects/poissoninput_3_codeobject.h"
#include "code_objects/poissoninput_8_codeobject.h"
#include "code_objects/poissoninput_9_codeobject.h"
#include "code_objects/poissoninput_codeobject.h"
#include "code_objects/spikemonitor_10_codeobject.h"
#include "code_objects/spikemonitor_11_codeobject.h"
#include "code_objects/spikemonitor_2_codeobject.h"
#include "code_objects/spikemonitor_3_codeobject.h"
#include "code_objects/spikemonitor_6_codeobject.h"
#include "code_objects/spikemonitor_7_codeobject.h"
#include "code_objects/spikemonitor_8_codeobject.h"
#include "code_objects/spikemonitor_9_codeobject.h"
#include "code_objects/statemonitor_1_codeobject.h"
#include "code_objects/statemonitor_3_codeobject.h"
#include "code_objects/statemonitor_4_codeobject.h"
#include "code_objects/statemonitor_5_codeobject.h"
#include "code_objects/synapses_13_pre_codeobject.h"
#include "code_objects/synapses_13_pre_push_spikes.h"
#include "code_objects/synapses_13_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_14_pre_codeobject.h"
#include "code_objects/synapses_14_pre_push_spikes.h"
#include "code_objects/synapses_14_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_15_pre_codeobject.h"
#include "code_objects/synapses_15_pre_push_spikes.h"
#include "code_objects/synapses_15_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_16_pre_codeobject.h"
#include "code_objects/synapses_16_pre_push_spikes.h"
#include "code_objects/synapses_16_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_17_pre_codeobject.h"
#include "code_objects/synapses_17_pre_push_spikes.h"
#include "code_objects/synapses_17_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_18_pre_codeobject.h"
#include "code_objects/synapses_18_pre_push_spikes.h"
#include "code_objects/synapses_18_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_19_pre_codeobject.h"
#include "code_objects/synapses_19_pre_push_spikes.h"
#include "code_objects/synapses_19_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_20_pre_codeobject.h"
#include "code_objects/synapses_20_pre_push_spikes.h"
#include "code_objects/synapses_20_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_21_pre_codeobject.h"
#include "code_objects/synapses_21_pre_push_spikes.h"
#include "code_objects/synapses_21_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_22_pre_codeobject.h"
#include "code_objects/synapses_22_pre_push_spikes.h"
#include "code_objects/synapses_22_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_23_pre_codeobject.h"
#include "code_objects/synapses_23_pre_push_spikes.h"
#include "code_objects/synapses_23_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_3_pre_codeobject.h"
#include "code_objects/synapses_3_pre_push_spikes.h"
#include "code_objects/synapses_3_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_4_pre_codeobject.h"
#include "code_objects/synapses_4_pre_push_spikes.h"
#include "code_objects/synapses_4_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_5_pre_codeobject.h"
#include "code_objects/synapses_5_pre_push_spikes.h"
#include "code_objects/synapses_5_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_6_pre_codeobject.h"
#include "code_objects/synapses_6_pre_push_spikes.h"
#include "code_objects/synapses_6_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_7_pre_codeobject.h"
#include "code_objects/synapses_7_pre_push_spikes.h"
#include "code_objects/synapses_7_synapses_create_generator_codeobject.h"


void brian_start()
{
	_init_arrays();
	_load_arrays();
	// Initialize clocks (link timestep and dt to the respective arrays)
    brian::defaultclock.timestep = brian::_array_defaultclock_timestep;
    brian::defaultclock.dt = brian::_array_defaultclock_dt;
    brian::defaultclock.t = brian::_array_defaultclock_t;
    brian::networkoperation_1_clock.timestep = brian::_array_networkoperation_1_clock_timestep;
    brian::networkoperation_1_clock.dt = brian::_array_networkoperation_1_clock_dt;
    brian::networkoperation_1_clock.t = brian::_array_networkoperation_1_clock_t;
    brian::networkoperation_3_clock.timestep = brian::_array_networkoperation_3_clock_timestep;
    brian::networkoperation_3_clock.dt = brian::_array_networkoperation_3_clock_dt;
    brian::networkoperation_3_clock.t = brian::_array_networkoperation_3_clock_t;
    brian::networkoperation_4_clock.timestep = brian::_array_networkoperation_4_clock_timestep;
    brian::networkoperation_4_clock.dt = brian::_array_networkoperation_4_clock_dt;
    brian::networkoperation_4_clock.t = brian::_array_networkoperation_4_clock_t;
    brian::networkoperation_5_clock.timestep = brian::_array_networkoperation_5_clock_timestep;
    brian::networkoperation_5_clock.dt = brian::_array_networkoperation_5_clock_dt;
    brian::networkoperation_5_clock.t = brian::_array_networkoperation_5_clock_t;
    for (int i=0; i<1; i++)
	    rk_randomseed(brian::_mersenne_twister_states[i]);  // Note that this seed can be potentially replaced in main.cpp
}

void brian_end()
{
	_write_arrays();
	_dealloc_arrays();
}



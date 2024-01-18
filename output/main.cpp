#include <stdlib.h>
#include "objects.h"
#include <ctime>
#include <time.h>

#include "run.h"
#include "brianlib/common_math.h"
#include "randomkit.h"

#include "code_objects/neurongroup_10_spike_resetter_codeobject.h"
#include "code_objects/neurongroup_10_spike_thresholder_codeobject.h"
#include "code_objects/after_run_neurongroup_10_spike_thresholder_codeobject.h"
#include "code_objects/neurongroup_10_stateupdater_codeobject.h"
#include "code_objects/neurongroup_11_spike_resetter_codeobject.h"
#include "code_objects/neurongroup_11_spike_thresholder_codeobject.h"
#include "code_objects/after_run_neurongroup_11_spike_thresholder_codeobject.h"
#include "code_objects/neurongroup_11_stateupdater_codeobject.h"
#include "code_objects/neurongroup_1_spike_resetter_codeobject.h"
#include "code_objects/neurongroup_1_spike_thresholder_codeobject.h"
#include "code_objects/after_run_neurongroup_1_spike_thresholder_codeobject.h"
#include "code_objects/neurongroup_1_stateupdater_codeobject.h"
#include "code_objects/neurongroup_2_spike_resetter_codeobject.h"
#include "code_objects/neurongroup_2_spike_thresholder_codeobject.h"
#include "code_objects/after_run_neurongroup_2_spike_thresholder_codeobject.h"
#include "code_objects/neurongroup_2_stateupdater_codeobject.h"
#include "code_objects/neurongroup_3_spike_resetter_codeobject.h"
#include "code_objects/neurongroup_3_spike_thresholder_codeobject.h"
#include "code_objects/after_run_neurongroup_3_spike_thresholder_codeobject.h"
#include "code_objects/neurongroup_3_stateupdater_codeobject.h"
#include "code_objects/neurongroup_8_spike_resetter_codeobject.h"
#include "code_objects/neurongroup_8_spike_thresholder_codeobject.h"
#include "code_objects/after_run_neurongroup_8_spike_thresholder_codeobject.h"
#include "code_objects/neurongroup_8_stateupdater_codeobject.h"
#include "code_objects/neurongroup_9_spike_resetter_codeobject.h"
#include "code_objects/neurongroup_9_spike_thresholder_codeobject.h"
#include "code_objects/after_run_neurongroup_9_spike_thresholder_codeobject.h"
#include "code_objects/neurongroup_9_stateupdater_codeobject.h"
#include "code_objects/neurongroup_spike_resetter_codeobject.h"
#include "code_objects/neurongroup_spike_thresholder_codeobject.h"
#include "code_objects/after_run_neurongroup_spike_thresholder_codeobject.h"
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
#include "code_objects/before_run_synapses_13_pre_push_spikes.h"
#include "code_objects/synapses_13_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_14_pre_codeobject.h"
#include "code_objects/synapses_14_pre_push_spikes.h"
#include "code_objects/before_run_synapses_14_pre_push_spikes.h"
#include "code_objects/synapses_14_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_15_pre_codeobject.h"
#include "code_objects/synapses_15_pre_push_spikes.h"
#include "code_objects/before_run_synapses_15_pre_push_spikes.h"
#include "code_objects/synapses_15_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_16_pre_codeobject.h"
#include "code_objects/synapses_16_pre_push_spikes.h"
#include "code_objects/before_run_synapses_16_pre_push_spikes.h"
#include "code_objects/synapses_16_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_17_pre_codeobject.h"
#include "code_objects/synapses_17_pre_push_spikes.h"
#include "code_objects/before_run_synapses_17_pre_push_spikes.h"
#include "code_objects/synapses_17_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_18_pre_codeobject.h"
#include "code_objects/synapses_18_pre_push_spikes.h"
#include "code_objects/before_run_synapses_18_pre_push_spikes.h"
#include "code_objects/synapses_18_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_19_pre_codeobject.h"
#include "code_objects/synapses_19_pre_push_spikes.h"
#include "code_objects/before_run_synapses_19_pre_push_spikes.h"
#include "code_objects/synapses_19_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_20_pre_codeobject.h"
#include "code_objects/synapses_20_pre_push_spikes.h"
#include "code_objects/before_run_synapses_20_pre_push_spikes.h"
#include "code_objects/synapses_20_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_21_pre_codeobject.h"
#include "code_objects/synapses_21_pre_push_spikes.h"
#include "code_objects/before_run_synapses_21_pre_push_spikes.h"
#include "code_objects/synapses_21_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_22_pre_codeobject.h"
#include "code_objects/synapses_22_pre_push_spikes.h"
#include "code_objects/before_run_synapses_22_pre_push_spikes.h"
#include "code_objects/synapses_22_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_23_pre_codeobject.h"
#include "code_objects/synapses_23_pre_push_spikes.h"
#include "code_objects/before_run_synapses_23_pre_push_spikes.h"
#include "code_objects/synapses_23_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_3_pre_codeobject.h"
#include "code_objects/synapses_3_pre_push_spikes.h"
#include "code_objects/before_run_synapses_3_pre_push_spikes.h"
#include "code_objects/synapses_3_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_4_pre_codeobject.h"
#include "code_objects/synapses_4_pre_push_spikes.h"
#include "code_objects/before_run_synapses_4_pre_push_spikes.h"
#include "code_objects/synapses_4_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_5_pre_codeobject.h"
#include "code_objects/synapses_5_pre_push_spikes.h"
#include "code_objects/before_run_synapses_5_pre_push_spikes.h"
#include "code_objects/synapses_5_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_6_pre_codeobject.h"
#include "code_objects/synapses_6_pre_push_spikes.h"
#include "code_objects/before_run_synapses_6_pre_push_spikes.h"
#include "code_objects/synapses_6_synapses_create_generator_codeobject.h"
#include "code_objects/synapses_7_pre_codeobject.h"
#include "code_objects/synapses_7_pre_push_spikes.h"
#include "code_objects/before_run_synapses_7_pre_push_spikes.h"
#include "code_objects/synapses_7_synapses_create_generator_codeobject.h"


#include <iostream>
#include <fstream>
#include <string>


        std::string _format_time(float time_in_s)
        {
            float divisors[] = {24*60*60, 60*60, 60, 1};
            char letters[] = {'d', 'h', 'm', 's'};
            float remaining = time_in_s;
            std::string text = "";
            int time_to_represent;
            for (int i =0; i < sizeof(divisors)/sizeof(float); i++)
            {
                time_to_represent = int(remaining / divisors[i]);
                remaining -= time_to_represent * divisors[i];
                if (time_to_represent > 0 || text.length())
                {
                    if(text.length() > 0)
                    {
                        text += " ";
                    }
                    text += (std::to_string(time_to_represent)+letters[i]);
                }
            }
            //less than one second
            if(text.length() == 0)
            {
                text = "< 1s";
            }
            return text;
        }
        void report_progress(const double elapsed, const double completed, const double start, const double duration)
        {
            if (completed == 0.0)
            {
                std::cout << "Starting simulation at t=" << start << " s for duration " << duration << " s";
            } else
            {
                std::cout << completed*duration << " s (" << (int)(completed*100.) << "%) simulated in " << _format_time(elapsed);
                if (completed < 1.0)
                {
                    const int remaining = (int)((1-completed)/completed*elapsed+0.5);
                    std::cout << ", estimated " << _format_time(remaining) << " remaining.";
                }
            }

            std::cout << std::endl << std::flush;
        }
        


int main(int argc, char **argv)
{
        

	brian_start();
        

	{
		using namespace brian;

		
                
        _array_defaultclock_dt[0] = 0.0001;
        _array_defaultclock_dt[0] = 0.0001;
        _array_defaultclock_dt[0] = 0.0001;
        
                        
                        for(int i=0; i<_num__array_neurongroup_2_lastspike; i++)
                        {
                            _array_neurongroup_2_lastspike[i] = - 10000.0;
                        }
                        
        
                        
                        for(int i=0; i<_num__array_neurongroup_2_not_refractory; i++)
                        {
                            _array_neurongroup_2_not_refractory[i] = true;
                        }
                        
        
                        
                        for(int i=0; i<_num__array_neurongroup_3_lastspike; i++)
                        {
                            _array_neurongroup_3_lastspike[i] = - 10000.0;
                        }
                        
        
                        
                        for(int i=0; i<_num__array_neurongroup_3_not_refractory; i++)
                        {
                            _array_neurongroup_3_not_refractory[i] = true;
                        }
                        
        _dynamic_array_synapses_4_delay.resize(1);
        _dynamic_array_synapses_4_delay.resize(1);
        _dynamic_array_synapses_4_delay[0] = 0.001;
        _run_synapses_4_synapses_create_generator_codeobject();
        _dynamic_array_synapses_5_delay.resize(1);
        _dynamic_array_synapses_5_delay.resize(1);
        _dynamic_array_synapses_5_delay[0] = 0.001;
        _run_synapses_5_synapses_create_generator_codeobject();
        _dynamic_array_synapses_6_delay.resize(1);
        _dynamic_array_synapses_6_delay.resize(1);
        _dynamic_array_synapses_6_delay[0] = 0.001;
        _run_synapses_6_synapses_create_generator_codeobject();
        _dynamic_array_synapses_7_delay.resize(1);
        _dynamic_array_synapses_7_delay.resize(1);
        _dynamic_array_synapses_7_delay[0] = 0.001;
        _run_synapses_7_synapses_create_generator_codeobject();
        
                        
                        for(int i=0; i<_num__array_statemonitor_1__indices; i++)
                        {
                            _array_statemonitor_1__indices[i] = _static_array__array_statemonitor_1__indices[i];
                        }
                        
        _array_networkoperation_1_clock_dt[0] = 1.0;
        _array_networkoperation_1_clock_dt[0] = 1.0;
        _array_networkoperation_1_clock_timestep[0] = 0;
        _array_networkoperation_1_clock_t[0] = 0.0;
        _array_defaultclock_timestep[0] = 0;
        _array_defaultclock_t[0] = 0.0;
        _before_run_synapses_4_pre_push_spikes();
        _before_run_synapses_5_pre_push_spikes();
        _before_run_synapses_6_pre_push_spikes();
        _before_run_synapses_7_pre_push_spikes();
        network_1.clear();
        network_1.add(&defaultclock, _run_statemonitor_1_codeobject);
        network_1.add(&defaultclock, _run_neurongroup_2_stateupdater_codeobject);
        network_1.add(&defaultclock, _run_neurongroup_3_stateupdater_codeobject);
        network_1.add(&defaultclock, _run_poissoninput_2_codeobject);
        network_1.add(&defaultclock, _run_poissoninput_3_codeobject);
        network_1.add(&defaultclock, _run_neurongroup_2_spike_thresholder_codeobject);
        network_1.add(&defaultclock, _run_neurongroup_3_spike_thresholder_codeobject);
        network_1.add(&defaultclock, _run_spikemonitor_2_codeobject);
        network_1.add(&defaultclock, _run_spikemonitor_3_codeobject);
        network_1.add(&defaultclock, _run_synapses_4_pre_push_spikes);
        network_1.add(&defaultclock, _run_synapses_4_pre_codeobject);
        network_1.add(&defaultclock, _run_synapses_5_pre_push_spikes);
        network_1.add(&defaultclock, _run_synapses_5_pre_codeobject);
        network_1.add(&defaultclock, _run_synapses_6_pre_push_spikes);
        network_1.add(&defaultclock, _run_synapses_6_pre_codeobject);
        network_1.add(&defaultclock, _run_synapses_7_pre_push_spikes);
        network_1.add(&defaultclock, _run_synapses_7_pre_codeobject);
        network_1.add(&defaultclock, _run_neurongroup_2_spike_resetter_codeobject);
        network_1.add(&defaultclock, _run_neurongroup_3_spike_resetter_codeobject);
        network_1.add(&networkoperation_1_clock, NULL);
        network_1.run(600.0, report_progress, 20.0);
        _after_run_neurongroup_2_spike_thresholder_codeobject();
        _after_run_neurongroup_3_spike_thresholder_codeobject();
        _array_defaultclock_dt[0] = 0.0001;
        
                        
                        for(int i=0; i<_num__array_neurongroup_lastspike; i++)
                        {
                            _array_neurongroup_lastspike[i] = - 10000.0;
                        }
                        
        
                        
                        for(int i=0; i<_num__array_neurongroup_not_refractory; i++)
                        {
                            _array_neurongroup_not_refractory[i] = true;
                        }
                        
        
                        
                        for(int i=0; i<_num__array_neurongroup_1_lastspike; i++)
                        {
                            _array_neurongroup_1_lastspike[i] = - 10000.0;
                        }
                        
        
                        
                        for(int i=0; i<_num__array_neurongroup_1_not_refractory; i++)
                        {
                            _array_neurongroup_1_not_refractory[i] = true;
                        }
                        
        _dynamic_array_synapses_3_delay.resize(1);
        _dynamic_array_synapses_3_delay.resize(1);
        _dynamic_array_synapses_3_delay[0] = 0.001;
        _run_synapses_3_synapses_create_generator_codeobject();
        _dynamic_array_synapses_13_delay.resize(1);
        _dynamic_array_synapses_13_delay.resize(1);
        _dynamic_array_synapses_13_delay[0] = 0.001;
        _run_synapses_13_synapses_create_generator_codeobject();
        _dynamic_array_synapses_14_delay.resize(1);
        _dynamic_array_synapses_14_delay.resize(1);
        _dynamic_array_synapses_14_delay[0] = 0.001;
        _run_synapses_14_synapses_create_generator_codeobject();
        _dynamic_array_synapses_15_delay.resize(1);
        _dynamic_array_synapses_15_delay.resize(1);
        _dynamic_array_synapses_15_delay[0] = 0.001;
        _run_synapses_15_synapses_create_generator_codeobject();
        
                        
                        for(int i=0; i<_num__array_statemonitor_3__indices; i++)
                        {
                            _array_statemonitor_3__indices[i] = _static_array__array_statemonitor_3__indices[i];
                        }
                        
        _array_networkoperation_3_clock_dt[0] = 1.0;
        _array_networkoperation_3_clock_dt[0] = 1.0;
        _array_networkoperation_3_clock_timestep[0] = 0;
        _array_networkoperation_3_clock_t[0] = 0.0;
        _array_defaultclock_timestep[0] = 0;
        _array_defaultclock_t[0] = 0.0;
        _before_run_synapses_13_pre_push_spikes();
        _before_run_synapses_14_pre_push_spikes();
        _before_run_synapses_15_pre_push_spikes();
        _before_run_synapses_3_pre_push_spikes();
        network.clear();
        network.add(&defaultclock, _run_statemonitor_3_codeobject);
        network.add(&defaultclock, _run_neurongroup_1_stateupdater_codeobject);
        network.add(&defaultclock, _run_neurongroup_stateupdater_codeobject);
        network.add(&defaultclock, _run_poissoninput_codeobject);
        network.add(&defaultclock, _run_poissoninput_1_codeobject);
        network.add(&defaultclock, _run_neurongroup_1_spike_thresholder_codeobject);
        network.add(&defaultclock, _run_neurongroup_spike_thresholder_codeobject);
        network.add(&defaultclock, _run_spikemonitor_6_codeobject);
        network.add(&defaultclock, _run_spikemonitor_7_codeobject);
        network.add(&defaultclock, _run_synapses_13_pre_push_spikes);
        network.add(&defaultclock, _run_synapses_13_pre_codeobject);
        network.add(&defaultclock, _run_synapses_14_pre_push_spikes);
        network.add(&defaultclock, _run_synapses_14_pre_codeobject);
        network.add(&defaultclock, _run_synapses_15_pre_push_spikes);
        network.add(&defaultclock, _run_synapses_15_pre_codeobject);
        network.add(&defaultclock, _run_synapses_3_pre_push_spikes);
        network.add(&defaultclock, _run_synapses_3_pre_codeobject);
        network.add(&defaultclock, _run_neurongroup_1_spike_resetter_codeobject);
        network.add(&defaultclock, _run_neurongroup_spike_resetter_codeobject);
        network.add(&networkoperation_3_clock, NULL);
        network.run(600.0, report_progress, 20.0);
        _after_run_neurongroup_1_spike_thresholder_codeobject();
        _after_run_neurongroup_spike_thresholder_codeobject();
        _array_defaultclock_dt[0] = 0.0001;
        
                        
                        for(int i=0; i<_num__array_neurongroup_8_lastspike; i++)
                        {
                            _array_neurongroup_8_lastspike[i] = - 10000.0;
                        }
                        
        
                        
                        for(int i=0; i<_num__array_neurongroup_8_not_refractory; i++)
                        {
                            _array_neurongroup_8_not_refractory[i] = true;
                        }
                        
        
                        
                        for(int i=0; i<_num__array_neurongroup_9_lastspike; i++)
                        {
                            _array_neurongroup_9_lastspike[i] = - 10000.0;
                        }
                        
        
                        
                        for(int i=0; i<_num__array_neurongroup_9_not_refractory; i++)
                        {
                            _array_neurongroup_9_not_refractory[i] = true;
                        }
                        
        _dynamic_array_synapses_16_delay.resize(1);
        _dynamic_array_synapses_16_delay.resize(1);
        _dynamic_array_synapses_16_delay[0] = 0.001;
        _run_synapses_16_synapses_create_generator_codeobject();
        _dynamic_array_synapses_17_delay.resize(1);
        _dynamic_array_synapses_17_delay.resize(1);
        _dynamic_array_synapses_17_delay[0] = 0.001;
        _run_synapses_17_synapses_create_generator_codeobject();
        _dynamic_array_synapses_18_delay.resize(1);
        _dynamic_array_synapses_18_delay.resize(1);
        _dynamic_array_synapses_18_delay[0] = 0.001;
        _run_synapses_18_synapses_create_generator_codeobject();
        _dynamic_array_synapses_19_delay.resize(1);
        _dynamic_array_synapses_19_delay.resize(1);
        _dynamic_array_synapses_19_delay[0] = 0.001;
        _run_synapses_19_synapses_create_generator_codeobject();
        
                        
                        for(int i=0; i<_num__array_statemonitor_4__indices; i++)
                        {
                            _array_statemonitor_4__indices[i] = _static_array__array_statemonitor_4__indices[i];
                        }
                        
        _array_networkoperation_4_clock_dt[0] = 1.0;
        _array_networkoperation_4_clock_dt[0] = 1.0;
        _array_defaultclock_timestep[0] = 0;
        _array_defaultclock_t[0] = 0.0;
        _array_networkoperation_4_clock_timestep[0] = 0;
        _array_networkoperation_4_clock_t[0] = 0.0;
        _before_run_synapses_16_pre_push_spikes();
        _before_run_synapses_17_pre_push_spikes();
        _before_run_synapses_18_pre_push_spikes();
        _before_run_synapses_19_pre_push_spikes();
        network_4.clear();
        network_4.add(&defaultclock, _run_statemonitor_4_codeobject);
        network_4.add(&defaultclock, _run_neurongroup_8_stateupdater_codeobject);
        network_4.add(&defaultclock, _run_neurongroup_9_stateupdater_codeobject);
        network_4.add(&defaultclock, _run_poissoninput_8_codeobject);
        network_4.add(&defaultclock, _run_poissoninput_9_codeobject);
        network_4.add(&defaultclock, _run_neurongroup_8_spike_thresholder_codeobject);
        network_4.add(&defaultclock, _run_neurongroup_9_spike_thresholder_codeobject);
        network_4.add(&defaultclock, _run_spikemonitor_8_codeobject);
        network_4.add(&defaultclock, _run_spikemonitor_9_codeobject);
        network_4.add(&defaultclock, _run_synapses_16_pre_push_spikes);
        network_4.add(&defaultclock, _run_synapses_16_pre_codeobject);
        network_4.add(&defaultclock, _run_synapses_17_pre_push_spikes);
        network_4.add(&defaultclock, _run_synapses_17_pre_codeobject);
        network_4.add(&defaultclock, _run_synapses_18_pre_push_spikes);
        network_4.add(&defaultclock, _run_synapses_18_pre_codeobject);
        network_4.add(&defaultclock, _run_synapses_19_pre_push_spikes);
        network_4.add(&defaultclock, _run_synapses_19_pre_codeobject);
        network_4.add(&defaultclock, _run_neurongroup_8_spike_resetter_codeobject);
        network_4.add(&defaultclock, _run_neurongroup_9_spike_resetter_codeobject);
        network_4.add(&networkoperation_4_clock, NULL);
        network_4.run(600.0, report_progress, 20.0);
        _after_run_neurongroup_8_spike_thresholder_codeobject();
        _after_run_neurongroup_9_spike_thresholder_codeobject();
        _array_defaultclock_dt[0] = 0.0001;
        
                        
                        for(int i=0; i<_num__array_neurongroup_10_lastspike; i++)
                        {
                            _array_neurongroup_10_lastspike[i] = - 10000.0;
                        }
                        
        
                        
                        for(int i=0; i<_num__array_neurongroup_10_not_refractory; i++)
                        {
                            _array_neurongroup_10_not_refractory[i] = true;
                        }
                        
        
                        
                        for(int i=0; i<_num__array_neurongroup_11_lastspike; i++)
                        {
                            _array_neurongroup_11_lastspike[i] = - 10000.0;
                        }
                        
        
                        
                        for(int i=0; i<_num__array_neurongroup_11_not_refractory; i++)
                        {
                            _array_neurongroup_11_not_refractory[i] = true;
                        }
                        
        _dynamic_array_synapses_20_delay.resize(1);
        _dynamic_array_synapses_20_delay.resize(1);
        _dynamic_array_synapses_20_delay[0] = 0.001;
        _run_synapses_20_synapses_create_generator_codeobject();
        _dynamic_array_synapses_21_delay.resize(1);
        _dynamic_array_synapses_21_delay.resize(1);
        _dynamic_array_synapses_21_delay[0] = 0.001;
        _run_synapses_21_synapses_create_generator_codeobject();
        _dynamic_array_synapses_22_delay.resize(1);
        _dynamic_array_synapses_22_delay.resize(1);
        _dynamic_array_synapses_22_delay[0] = 0.001;
        _run_synapses_22_synapses_create_generator_codeobject();
        _dynamic_array_synapses_23_delay.resize(1);
        _dynamic_array_synapses_23_delay.resize(1);
        _dynamic_array_synapses_23_delay[0] = 0.001;
        _run_synapses_23_synapses_create_generator_codeobject();
        
                        
                        for(int i=0; i<_num__array_statemonitor_5__indices; i++)
                        {
                            _array_statemonitor_5__indices[i] = _static_array__array_statemonitor_5__indices[i];
                        }
                        
        _array_networkoperation_5_clock_dt[0] = 1.0;
        _array_networkoperation_5_clock_dt[0] = 1.0;
        _array_defaultclock_timestep[0] = 0;
        _array_defaultclock_t[0] = 0.0;
        _array_networkoperation_5_clock_timestep[0] = 0;
        _array_networkoperation_5_clock_t[0] = 0.0;
        _before_run_synapses_20_pre_push_spikes();
        _before_run_synapses_21_pre_push_spikes();
        _before_run_synapses_22_pre_push_spikes();
        _before_run_synapses_23_pre_push_spikes();
        network_5.clear();
        network_5.add(&defaultclock, _run_statemonitor_5_codeobject);
        network_5.add(&defaultclock, _run_neurongroup_10_stateupdater_codeobject);
        network_5.add(&defaultclock, _run_neurongroup_11_stateupdater_codeobject);
        network_5.add(&defaultclock, _run_poissoninput_10_codeobject);
        network_5.add(&defaultclock, _run_poissoninput_11_codeobject);
        network_5.add(&defaultclock, _run_neurongroup_10_spike_thresholder_codeobject);
        network_5.add(&defaultclock, _run_neurongroup_11_spike_thresholder_codeobject);
        network_5.add(&defaultclock, _run_spikemonitor_10_codeobject);
        network_5.add(&defaultclock, _run_spikemonitor_11_codeobject);
        network_5.add(&defaultclock, _run_synapses_20_pre_push_spikes);
        network_5.add(&defaultclock, _run_synapses_20_pre_codeobject);
        network_5.add(&defaultclock, _run_synapses_21_pre_push_spikes);
        network_5.add(&defaultclock, _run_synapses_21_pre_codeobject);
        network_5.add(&defaultclock, _run_synapses_22_pre_push_spikes);
        network_5.add(&defaultclock, _run_synapses_22_pre_codeobject);
        network_5.add(&defaultclock, _run_synapses_23_pre_push_spikes);
        network_5.add(&defaultclock, _run_synapses_23_pre_codeobject);
        network_5.add(&defaultclock, _run_neurongroup_10_spike_resetter_codeobject);
        network_5.add(&defaultclock, _run_neurongroup_11_spike_resetter_codeobject);
        network_5.add(&networkoperation_5_clock, NULL);
        network_5.run(600.0, report_progress, 20.0);
        _after_run_neurongroup_10_spike_thresholder_codeobject();
        _after_run_neurongroup_11_spike_thresholder_codeobject();
        #ifdef DEBUG
        _debugmsg_spikemonitor_2_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_spikemonitor_3_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_synapses_4_pre_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_synapses_5_pre_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_synapses_6_pre_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_synapses_7_pre_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_spikemonitor_6_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_spikemonitor_7_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_synapses_13_pre_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_synapses_14_pre_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_synapses_15_pre_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_synapses_3_pre_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_spikemonitor_8_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_spikemonitor_9_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_synapses_16_pre_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_synapses_17_pre_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_synapses_18_pre_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_synapses_19_pre_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_spikemonitor_10_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_spikemonitor_11_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_synapses_20_pre_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_synapses_21_pre_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_synapses_22_pre_codeobject();
        #endif
        
        #ifdef DEBUG
        _debugmsg_synapses_23_pre_codeobject();
        #endif

	}
        

	brian_end();
        

	return 0;
}
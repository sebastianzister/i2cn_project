
#ifndef _BRIAN_OBJECTS_H
#define _BRIAN_OBJECTS_H

#include "synapses_classes.h"
#include "brianlib/clocks.h"
#include "brianlib/dynamic_array.h"
#include "brianlib/stdint_compat.h"
#include "network.h"
#include "randomkit.h"
#include<vector>


namespace brian {

// In OpenMP we need one state per thread
extern std::vector< rk_state* > _mersenne_twister_states;

//////////////// clocks ///////////////////
extern Clock defaultclock;
extern Clock networkoperation_1_clock;
extern Clock networkoperation_3_clock;
extern Clock networkoperation_4_clock;
extern Clock networkoperation_5_clock;

//////////////// networks /////////////////
extern Network network;
extern Network network_1;
extern Network network_4;
extern Network network_5;

//////////////// dynamic arrays ///////////
extern std::vector<int32_t> _dynamic_array_spikemonitor_10_i;
extern std::vector<double> _dynamic_array_spikemonitor_10_t;
extern std::vector<int32_t> _dynamic_array_spikemonitor_11_i;
extern std::vector<double> _dynamic_array_spikemonitor_11_t;
extern std::vector<int32_t> _dynamic_array_spikemonitor_2_i;
extern std::vector<double> _dynamic_array_spikemonitor_2_t;
extern std::vector<int32_t> _dynamic_array_spikemonitor_3_i;
extern std::vector<double> _dynamic_array_spikemonitor_3_t;
extern std::vector<int32_t> _dynamic_array_spikemonitor_6_i;
extern std::vector<double> _dynamic_array_spikemonitor_6_t;
extern std::vector<int32_t> _dynamic_array_spikemonitor_7_i;
extern std::vector<double> _dynamic_array_spikemonitor_7_t;
extern std::vector<int32_t> _dynamic_array_spikemonitor_8_i;
extern std::vector<double> _dynamic_array_spikemonitor_8_t;
extern std::vector<int32_t> _dynamic_array_spikemonitor_9_i;
extern std::vector<double> _dynamic_array_spikemonitor_9_t;
extern std::vector<double> _dynamic_array_statemonitor_1_t;
extern std::vector<double> _dynamic_array_statemonitor_3_t;
extern std::vector<double> _dynamic_array_statemonitor_4_t;
extern std::vector<double> _dynamic_array_statemonitor_5_t;
extern std::vector<int32_t> _dynamic_array_synapses_13__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses_13__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_13_delay;
extern std::vector<int32_t> _dynamic_array_synapses_13_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_13_N_outgoing;
extern std::vector<int32_t> _dynamic_array_synapses_14__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses_14__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_14_delay;
extern std::vector<int32_t> _dynamic_array_synapses_14_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_14_N_outgoing;
extern std::vector<int32_t> _dynamic_array_synapses_15__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses_15__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_15_c;
extern std::vector<double> _dynamic_array_synapses_15_delay;
extern std::vector<int32_t> _dynamic_array_synapses_15_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_15_N_outgoing;
extern std::vector<int32_t> _dynamic_array_synapses_16__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses_16__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_16_delay;
extern std::vector<int32_t> _dynamic_array_synapses_16_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_16_N_outgoing;
extern std::vector<int32_t> _dynamic_array_synapses_17__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses_17__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_17_delay;
extern std::vector<int32_t> _dynamic_array_synapses_17_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_17_N_outgoing;
extern std::vector<int32_t> _dynamic_array_synapses_18__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses_18__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_18_delay;
extern std::vector<int32_t> _dynamic_array_synapses_18_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_18_N_outgoing;
extern std::vector<int32_t> _dynamic_array_synapses_19__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses_19__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_19_c;
extern std::vector<double> _dynamic_array_synapses_19_delay;
extern std::vector<int32_t> _dynamic_array_synapses_19_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_19_N_outgoing;
extern std::vector<int32_t> _dynamic_array_synapses_20__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses_20__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_20_delay;
extern std::vector<int32_t> _dynamic_array_synapses_20_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_20_N_outgoing;
extern std::vector<int32_t> _dynamic_array_synapses_21__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses_21__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_21_delay;
extern std::vector<int32_t> _dynamic_array_synapses_21_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_21_N_outgoing;
extern std::vector<int32_t> _dynamic_array_synapses_22__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses_22__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_22_delay;
extern std::vector<int32_t> _dynamic_array_synapses_22_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_22_N_outgoing;
extern std::vector<int32_t> _dynamic_array_synapses_23__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses_23__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_23_c;
extern std::vector<double> _dynamic_array_synapses_23_delay;
extern std::vector<int32_t> _dynamic_array_synapses_23_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_23_N_outgoing;
extern std::vector<int32_t> _dynamic_array_synapses_3__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses_3__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_3_delay;
extern std::vector<int32_t> _dynamic_array_synapses_3_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_3_N_outgoing;
extern std::vector<int32_t> _dynamic_array_synapses_4__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses_4__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_4_delay;
extern std::vector<int32_t> _dynamic_array_synapses_4_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_4_N_outgoing;
extern std::vector<int32_t> _dynamic_array_synapses_5__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses_5__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_5_delay;
extern std::vector<int32_t> _dynamic_array_synapses_5_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_5_N_outgoing;
extern std::vector<int32_t> _dynamic_array_synapses_6__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses_6__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_6_delay;
extern std::vector<int32_t> _dynamic_array_synapses_6_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_6_N_outgoing;
extern std::vector<int32_t> _dynamic_array_synapses_7__synaptic_post;
extern std::vector<int32_t> _dynamic_array_synapses_7__synaptic_pre;
extern std::vector<double> _dynamic_array_synapses_7_c;
extern std::vector<double> _dynamic_array_synapses_7_delay;
extern std::vector<int32_t> _dynamic_array_synapses_7_N_incoming;
extern std::vector<int32_t> _dynamic_array_synapses_7_N_outgoing;

//////////////// arrays ///////////////////
extern double *_array_defaultclock_dt;
extern const int _num__array_defaultclock_dt;
extern double *_array_defaultclock_t;
extern const int _num__array_defaultclock_t;
extern int64_t *_array_defaultclock_timestep;
extern const int _num__array_defaultclock_timestep;
extern double *_array_networkoperation_1_clock_dt;
extern const int _num__array_networkoperation_1_clock_dt;
extern double *_array_networkoperation_1_clock_t;
extern const int _num__array_networkoperation_1_clock_t;
extern int64_t *_array_networkoperation_1_clock_timestep;
extern const int _num__array_networkoperation_1_clock_timestep;
extern double *_array_networkoperation_3_clock_dt;
extern const int _num__array_networkoperation_3_clock_dt;
extern double *_array_networkoperation_3_clock_t;
extern const int _num__array_networkoperation_3_clock_t;
extern int64_t *_array_networkoperation_3_clock_timestep;
extern const int _num__array_networkoperation_3_clock_timestep;
extern double *_array_networkoperation_4_clock_dt;
extern const int _num__array_networkoperation_4_clock_dt;
extern double *_array_networkoperation_4_clock_t;
extern const int _num__array_networkoperation_4_clock_t;
extern int64_t *_array_networkoperation_4_clock_timestep;
extern const int _num__array_networkoperation_4_clock_timestep;
extern double *_array_networkoperation_5_clock_dt;
extern const int _num__array_networkoperation_5_clock_dt;
extern double *_array_networkoperation_5_clock_t;
extern const int _num__array_networkoperation_5_clock_t;
extern int64_t *_array_networkoperation_5_clock_timestep;
extern const int _num__array_networkoperation_5_clock_timestep;
extern int32_t *_array_neurongroup_10__spikespace;
extern const int _num__array_neurongroup_10__spikespace;
extern double *_array_neurongroup_10_a;
extern const int _num__array_neurongroup_10_a;
extern double *_array_neurongroup_10_d;
extern const int _num__array_neurongroup_10_d;
extern int32_t *_array_neurongroup_10_i;
extern const int _num__array_neurongroup_10_i;
extern double *_array_neurongroup_10_lastspike;
extern const int _num__array_neurongroup_10_lastspike;
extern char *_array_neurongroup_10_not_refractory;
extern const int _num__array_neurongroup_10_not_refractory;
extern double *_array_neurongroup_10_phi;
extern const int _num__array_neurongroup_10_phi;
extern double *_array_neurongroup_10_V;
extern const int _num__array_neurongroup_10_V;
extern int32_t *_array_neurongroup_11__spikespace;
extern const int _num__array_neurongroup_11__spikespace;
extern int32_t *_array_neurongroup_11_i;
extern const int _num__array_neurongroup_11_i;
extern double *_array_neurongroup_11_lastspike;
extern const int _num__array_neurongroup_11_lastspike;
extern char *_array_neurongroup_11_not_refractory;
extern const int _num__array_neurongroup_11_not_refractory;
extern double *_array_neurongroup_11_V;
extern const int _num__array_neurongroup_11_V;
extern int32_t *_array_neurongroup_1__spikespace;
extern const int _num__array_neurongroup_1__spikespace;
extern int32_t *_array_neurongroup_1_i;
extern const int _num__array_neurongroup_1_i;
extern double *_array_neurongroup_1_lastspike;
extern const int _num__array_neurongroup_1_lastspike;
extern char *_array_neurongroup_1_not_refractory;
extern const int _num__array_neurongroup_1_not_refractory;
extern double *_array_neurongroup_1_V;
extern const int _num__array_neurongroup_1_V;
extern int32_t *_array_neurongroup_2__spikespace;
extern const int _num__array_neurongroup_2__spikespace;
extern double *_array_neurongroup_2_a;
extern const int _num__array_neurongroup_2_a;
extern double *_array_neurongroup_2_d;
extern const int _num__array_neurongroup_2_d;
extern int32_t *_array_neurongroup_2_i;
extern const int _num__array_neurongroup_2_i;
extern double *_array_neurongroup_2_lastspike;
extern const int _num__array_neurongroup_2_lastspike;
extern char *_array_neurongroup_2_not_refractory;
extern const int _num__array_neurongroup_2_not_refractory;
extern double *_array_neurongroup_2_phi;
extern const int _num__array_neurongroup_2_phi;
extern double *_array_neurongroup_2_V;
extern const int _num__array_neurongroup_2_V;
extern int32_t *_array_neurongroup_3__spikespace;
extern const int _num__array_neurongroup_3__spikespace;
extern int32_t *_array_neurongroup_3_i;
extern const int _num__array_neurongroup_3_i;
extern double *_array_neurongroup_3_lastspike;
extern const int _num__array_neurongroup_3_lastspike;
extern char *_array_neurongroup_3_not_refractory;
extern const int _num__array_neurongroup_3_not_refractory;
extern double *_array_neurongroup_3_V;
extern const int _num__array_neurongroup_3_V;
extern int32_t *_array_neurongroup_8__spikespace;
extern const int _num__array_neurongroup_8__spikespace;
extern double *_array_neurongroup_8_a;
extern const int _num__array_neurongroup_8_a;
extern double *_array_neurongroup_8_d;
extern const int _num__array_neurongroup_8_d;
extern int32_t *_array_neurongroup_8_i;
extern const int _num__array_neurongroup_8_i;
extern double *_array_neurongroup_8_lastspike;
extern const int _num__array_neurongroup_8_lastspike;
extern char *_array_neurongroup_8_not_refractory;
extern const int _num__array_neurongroup_8_not_refractory;
extern double *_array_neurongroup_8_phi;
extern const int _num__array_neurongroup_8_phi;
extern double *_array_neurongroup_8_V;
extern const int _num__array_neurongroup_8_V;
extern int32_t *_array_neurongroup_9__spikespace;
extern const int _num__array_neurongroup_9__spikespace;
extern int32_t *_array_neurongroup_9_i;
extern const int _num__array_neurongroup_9_i;
extern double *_array_neurongroup_9_lastspike;
extern const int _num__array_neurongroup_9_lastspike;
extern char *_array_neurongroup_9_not_refractory;
extern const int _num__array_neurongroup_9_not_refractory;
extern double *_array_neurongroup_9_V;
extern const int _num__array_neurongroup_9_V;
extern int32_t *_array_neurongroup__spikespace;
extern const int _num__array_neurongroup__spikespace;
extern double *_array_neurongroup_a;
extern const int _num__array_neurongroup_a;
extern double *_array_neurongroup_d;
extern const int _num__array_neurongroup_d;
extern int32_t *_array_neurongroup_i;
extern const int _num__array_neurongroup_i;
extern double *_array_neurongroup_lastspike;
extern const int _num__array_neurongroup_lastspike;
extern char *_array_neurongroup_not_refractory;
extern const int _num__array_neurongroup_not_refractory;
extern double *_array_neurongroup_phi;
extern const int _num__array_neurongroup_phi;
extern double *_array_neurongroup_V;
extern const int _num__array_neurongroup_V;
extern int32_t *_array_spikemonitor_10__source_idx;
extern const int _num__array_spikemonitor_10__source_idx;
extern int32_t *_array_spikemonitor_10_count;
extern const int _num__array_spikemonitor_10_count;
extern int32_t *_array_spikemonitor_10_N;
extern const int _num__array_spikemonitor_10_N;
extern int32_t *_array_spikemonitor_11__source_idx;
extern const int _num__array_spikemonitor_11__source_idx;
extern int32_t *_array_spikemonitor_11_count;
extern const int _num__array_spikemonitor_11_count;
extern int32_t *_array_spikemonitor_11_N;
extern const int _num__array_spikemonitor_11_N;
extern int32_t *_array_spikemonitor_2__source_idx;
extern const int _num__array_spikemonitor_2__source_idx;
extern int32_t *_array_spikemonitor_2_count;
extern const int _num__array_spikemonitor_2_count;
extern int32_t *_array_spikemonitor_2_N;
extern const int _num__array_spikemonitor_2_N;
extern int32_t *_array_spikemonitor_3__source_idx;
extern const int _num__array_spikemonitor_3__source_idx;
extern int32_t *_array_spikemonitor_3_count;
extern const int _num__array_spikemonitor_3_count;
extern int32_t *_array_spikemonitor_3_N;
extern const int _num__array_spikemonitor_3_N;
extern int32_t *_array_spikemonitor_6__source_idx;
extern const int _num__array_spikemonitor_6__source_idx;
extern int32_t *_array_spikemonitor_6_count;
extern const int _num__array_spikemonitor_6_count;
extern int32_t *_array_spikemonitor_6_N;
extern const int _num__array_spikemonitor_6_N;
extern int32_t *_array_spikemonitor_7__source_idx;
extern const int _num__array_spikemonitor_7__source_idx;
extern int32_t *_array_spikemonitor_7_count;
extern const int _num__array_spikemonitor_7_count;
extern int32_t *_array_spikemonitor_7_N;
extern const int _num__array_spikemonitor_7_N;
extern int32_t *_array_spikemonitor_8__source_idx;
extern const int _num__array_spikemonitor_8__source_idx;
extern int32_t *_array_spikemonitor_8_count;
extern const int _num__array_spikemonitor_8_count;
extern int32_t *_array_spikemonitor_8_N;
extern const int _num__array_spikemonitor_8_N;
extern int32_t *_array_spikemonitor_9__source_idx;
extern const int _num__array_spikemonitor_9__source_idx;
extern int32_t *_array_spikemonitor_9_count;
extern const int _num__array_spikemonitor_9_count;
extern int32_t *_array_spikemonitor_9_N;
extern const int _num__array_spikemonitor_9_N;
extern int32_t *_array_statemonitor_1__indices;
extern const int _num__array_statemonitor_1__indices;
extern int32_t *_array_statemonitor_1_N;
extern const int _num__array_statemonitor_1_N;
extern double *_array_statemonitor_1_phi;
extern const int _num__array_statemonitor_1_phi;
extern double *_array_statemonitor_1_V;
extern const int _num__array_statemonitor_1_V;
extern int32_t *_array_statemonitor_3__indices;
extern const int _num__array_statemonitor_3__indices;
extern int32_t *_array_statemonitor_3_N;
extern const int _num__array_statemonitor_3_N;
extern double *_array_statemonitor_3_phi;
extern const int _num__array_statemonitor_3_phi;
extern double *_array_statemonitor_3_V;
extern const int _num__array_statemonitor_3_V;
extern int32_t *_array_statemonitor_4__indices;
extern const int _num__array_statemonitor_4__indices;
extern int32_t *_array_statemonitor_4_N;
extern const int _num__array_statemonitor_4_N;
extern double *_array_statemonitor_4_phi;
extern const int _num__array_statemonitor_4_phi;
extern double *_array_statemonitor_4_V;
extern const int _num__array_statemonitor_4_V;
extern int32_t *_array_statemonitor_5__indices;
extern const int _num__array_statemonitor_5__indices;
extern int32_t *_array_statemonitor_5_N;
extern const int _num__array_statemonitor_5_N;
extern double *_array_statemonitor_5_phi;
extern const int _num__array_statemonitor_5_phi;
extern double *_array_statemonitor_5_V;
extern const int _num__array_statemonitor_5_V;
extern int32_t *_array_synapses_13_N;
extern const int _num__array_synapses_13_N;
extern int32_t *_array_synapses_14_N;
extern const int _num__array_synapses_14_N;
extern int32_t *_array_synapses_15_N;
extern const int _num__array_synapses_15_N;
extern int32_t *_array_synapses_16_N;
extern const int _num__array_synapses_16_N;
extern int32_t *_array_synapses_17_N;
extern const int _num__array_synapses_17_N;
extern int32_t *_array_synapses_18_N;
extern const int _num__array_synapses_18_N;
extern int32_t *_array_synapses_19_N;
extern const int _num__array_synapses_19_N;
extern int32_t *_array_synapses_20_N;
extern const int _num__array_synapses_20_N;
extern int32_t *_array_synapses_21_N;
extern const int _num__array_synapses_21_N;
extern int32_t *_array_synapses_22_N;
extern const int _num__array_synapses_22_N;
extern int32_t *_array_synapses_23_N;
extern const int _num__array_synapses_23_N;
extern int32_t *_array_synapses_3_N;
extern const int _num__array_synapses_3_N;
extern int32_t *_array_synapses_4_N;
extern const int _num__array_synapses_4_N;
extern int32_t *_array_synapses_5_N;
extern const int _num__array_synapses_5_N;
extern int32_t *_array_synapses_6_N;
extern const int _num__array_synapses_6_N;
extern int32_t *_array_synapses_7_N;
extern const int _num__array_synapses_7_N;

//////////////// dynamic arrays 2d /////////
extern DynamicArray2D<double> _dynamic_array_statemonitor_1_phi;
extern DynamicArray2D<double> _dynamic_array_statemonitor_1_V;
extern DynamicArray2D<double> _dynamic_array_statemonitor_3_phi;
extern DynamicArray2D<double> _dynamic_array_statemonitor_3_V;
extern DynamicArray2D<double> _dynamic_array_statemonitor_4_phi;
extern DynamicArray2D<double> _dynamic_array_statemonitor_4_V;
extern DynamicArray2D<double> _dynamic_array_statemonitor_5_phi;
extern DynamicArray2D<double> _dynamic_array_statemonitor_5_V;

/////////////// static arrays /////////////
extern int32_t *_static_array__array_statemonitor_1__indices;
extern const int _num__static_array__array_statemonitor_1__indices;
extern int32_t *_static_array__array_statemonitor_3__indices;
extern const int _num__static_array__array_statemonitor_3__indices;
extern int32_t *_static_array__array_statemonitor_4__indices;
extern const int _num__static_array__array_statemonitor_4__indices;
extern int32_t *_static_array__array_statemonitor_5__indices;
extern const int _num__static_array__array_statemonitor_5__indices;

//////////////// synapses /////////////////
// synapses_13
extern SynapticPathway synapses_13_pre;
// synapses_14
extern SynapticPathway synapses_14_pre;
// synapses_15
extern SynapticPathway synapses_15_pre;
// synapses_16
extern SynapticPathway synapses_16_pre;
// synapses_17
extern SynapticPathway synapses_17_pre;
// synapses_18
extern SynapticPathway synapses_18_pre;
// synapses_19
extern SynapticPathway synapses_19_pre;
// synapses_20
extern SynapticPathway synapses_20_pre;
// synapses_21
extern SynapticPathway synapses_21_pre;
// synapses_22
extern SynapticPathway synapses_22_pre;
// synapses_23
extern SynapticPathway synapses_23_pre;
// synapses_3
extern SynapticPathway synapses_3_pre;
// synapses_4
extern SynapticPathway synapses_4_pre;
// synapses_5
extern SynapticPathway synapses_5_pre;
// synapses_6
extern SynapticPathway synapses_6_pre;
// synapses_7
extern SynapticPathway synapses_7_pre;

// Profiling information for each code object
}

void _init_arrays();
void _load_arrays();
void _write_arrays();
void _dealloc_arrays();

#endif



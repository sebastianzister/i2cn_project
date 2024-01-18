
#include "objects.h"
#include "synapses_classes.h"
#include "brianlib/clocks.h"
#include "brianlib/dynamic_array.h"
#include "brianlib/stdint_compat.h"
#include "network.h"
#include "randomkit.h"
#include<vector>
#include<iostream>
#include<fstream>

namespace brian {

std::vector< rk_state* > _mersenne_twister_states;

//////////////// networks /////////////////
Network network;
Network network_1;
Network network_4;
Network network_5;

//////////////// arrays ///////////////////
double * _array_defaultclock_dt;
const int _num__array_defaultclock_dt = 1;
double * _array_defaultclock_t;
const int _num__array_defaultclock_t = 1;
int64_t * _array_defaultclock_timestep;
const int _num__array_defaultclock_timestep = 1;
double * _array_networkoperation_1_clock_dt;
const int _num__array_networkoperation_1_clock_dt = 1;
double * _array_networkoperation_1_clock_t;
const int _num__array_networkoperation_1_clock_t = 1;
int64_t * _array_networkoperation_1_clock_timestep;
const int _num__array_networkoperation_1_clock_timestep = 1;
double * _array_networkoperation_3_clock_dt;
const int _num__array_networkoperation_3_clock_dt = 1;
double * _array_networkoperation_3_clock_t;
const int _num__array_networkoperation_3_clock_t = 1;
int64_t * _array_networkoperation_3_clock_timestep;
const int _num__array_networkoperation_3_clock_timestep = 1;
double * _array_networkoperation_4_clock_dt;
const int _num__array_networkoperation_4_clock_dt = 1;
double * _array_networkoperation_4_clock_t;
const int _num__array_networkoperation_4_clock_t = 1;
int64_t * _array_networkoperation_4_clock_timestep;
const int _num__array_networkoperation_4_clock_timestep = 1;
double * _array_networkoperation_5_clock_dt;
const int _num__array_networkoperation_5_clock_dt = 1;
double * _array_networkoperation_5_clock_t;
const int _num__array_networkoperation_5_clock_t = 1;
int64_t * _array_networkoperation_5_clock_timestep;
const int _num__array_networkoperation_5_clock_timestep = 1;
int32_t * _array_neurongroup_10__spikespace;
const int _num__array_neurongroup_10__spikespace = 401;
double * _array_neurongroup_10_a;
const int _num__array_neurongroup_10_a = 400;
double * _array_neurongroup_10_d;
const int _num__array_neurongroup_10_d = 400;
int32_t * _array_neurongroup_10_i;
const int _num__array_neurongroup_10_i = 400;
double * _array_neurongroup_10_lastspike;
const int _num__array_neurongroup_10_lastspike = 400;
char * _array_neurongroup_10_not_refractory;
const int _num__array_neurongroup_10_not_refractory = 400;
double * _array_neurongroup_10_phi;
const int _num__array_neurongroup_10_phi = 400;
double * _array_neurongroup_10_V;
const int _num__array_neurongroup_10_V = 400;
int32_t * _array_neurongroup_11__spikespace;
const int _num__array_neurongroup_11__spikespace = 101;
int32_t * _array_neurongroup_11_i;
const int _num__array_neurongroup_11_i = 100;
double * _array_neurongroup_11_lastspike;
const int _num__array_neurongroup_11_lastspike = 100;
char * _array_neurongroup_11_not_refractory;
const int _num__array_neurongroup_11_not_refractory = 100;
double * _array_neurongroup_11_V;
const int _num__array_neurongroup_11_V = 100;
int32_t * _array_neurongroup_1__spikespace;
const int _num__array_neurongroup_1__spikespace = 101;
int32_t * _array_neurongroup_1_i;
const int _num__array_neurongroup_1_i = 100;
double * _array_neurongroup_1_lastspike;
const int _num__array_neurongroup_1_lastspike = 100;
char * _array_neurongroup_1_not_refractory;
const int _num__array_neurongroup_1_not_refractory = 100;
double * _array_neurongroup_1_V;
const int _num__array_neurongroup_1_V = 100;
int32_t * _array_neurongroup_2__spikespace;
const int _num__array_neurongroup_2__spikespace = 401;
double * _array_neurongroup_2_a;
const int _num__array_neurongroup_2_a = 400;
double * _array_neurongroup_2_d;
const int _num__array_neurongroup_2_d = 400;
int32_t * _array_neurongroup_2_i;
const int _num__array_neurongroup_2_i = 400;
double * _array_neurongroup_2_lastspike;
const int _num__array_neurongroup_2_lastspike = 400;
char * _array_neurongroup_2_not_refractory;
const int _num__array_neurongroup_2_not_refractory = 400;
double * _array_neurongroup_2_phi;
const int _num__array_neurongroup_2_phi = 400;
double * _array_neurongroup_2_V;
const int _num__array_neurongroup_2_V = 400;
int32_t * _array_neurongroup_3__spikespace;
const int _num__array_neurongroup_3__spikespace = 101;
int32_t * _array_neurongroup_3_i;
const int _num__array_neurongroup_3_i = 100;
double * _array_neurongroup_3_lastspike;
const int _num__array_neurongroup_3_lastspike = 100;
char * _array_neurongroup_3_not_refractory;
const int _num__array_neurongroup_3_not_refractory = 100;
double * _array_neurongroup_3_V;
const int _num__array_neurongroup_3_V = 100;
int32_t * _array_neurongroup_8__spikespace;
const int _num__array_neurongroup_8__spikespace = 401;
double * _array_neurongroup_8_a;
const int _num__array_neurongroup_8_a = 400;
double * _array_neurongroup_8_d;
const int _num__array_neurongroup_8_d = 400;
int32_t * _array_neurongroup_8_i;
const int _num__array_neurongroup_8_i = 400;
double * _array_neurongroup_8_lastspike;
const int _num__array_neurongroup_8_lastspike = 400;
char * _array_neurongroup_8_not_refractory;
const int _num__array_neurongroup_8_not_refractory = 400;
double * _array_neurongroup_8_phi;
const int _num__array_neurongroup_8_phi = 400;
double * _array_neurongroup_8_V;
const int _num__array_neurongroup_8_V = 400;
int32_t * _array_neurongroup_9__spikespace;
const int _num__array_neurongroup_9__spikespace = 101;
int32_t * _array_neurongroup_9_i;
const int _num__array_neurongroup_9_i = 100;
double * _array_neurongroup_9_lastspike;
const int _num__array_neurongroup_9_lastspike = 100;
char * _array_neurongroup_9_not_refractory;
const int _num__array_neurongroup_9_not_refractory = 100;
double * _array_neurongroup_9_V;
const int _num__array_neurongroup_9_V = 100;
int32_t * _array_neurongroup__spikespace;
const int _num__array_neurongroup__spikespace = 401;
double * _array_neurongroup_a;
const int _num__array_neurongroup_a = 400;
double * _array_neurongroup_d;
const int _num__array_neurongroup_d = 400;
int32_t * _array_neurongroup_i;
const int _num__array_neurongroup_i = 400;
double * _array_neurongroup_lastspike;
const int _num__array_neurongroup_lastspike = 400;
char * _array_neurongroup_not_refractory;
const int _num__array_neurongroup_not_refractory = 400;
double * _array_neurongroup_phi;
const int _num__array_neurongroup_phi = 400;
double * _array_neurongroup_V;
const int _num__array_neurongroup_V = 400;
int32_t * _array_spikemonitor_10__source_idx;
const int _num__array_spikemonitor_10__source_idx = 100;
int32_t * _array_spikemonitor_10_count;
const int _num__array_spikemonitor_10_count = 100;
int32_t * _array_spikemonitor_10_N;
const int _num__array_spikemonitor_10_N = 1;
int32_t * _array_spikemonitor_11__source_idx;
const int _num__array_spikemonitor_11__source_idx = 400;
int32_t * _array_spikemonitor_11_count;
const int _num__array_spikemonitor_11_count = 400;
int32_t * _array_spikemonitor_11_N;
const int _num__array_spikemonitor_11_N = 1;
int32_t * _array_spikemonitor_2__source_idx;
const int _num__array_spikemonitor_2__source_idx = 100;
int32_t * _array_spikemonitor_2_count;
const int _num__array_spikemonitor_2_count = 100;
int32_t * _array_spikemonitor_2_N;
const int _num__array_spikemonitor_2_N = 1;
int32_t * _array_spikemonitor_3__source_idx;
const int _num__array_spikemonitor_3__source_idx = 400;
int32_t * _array_spikemonitor_3_count;
const int _num__array_spikemonitor_3_count = 400;
int32_t * _array_spikemonitor_3_N;
const int _num__array_spikemonitor_3_N = 1;
int32_t * _array_spikemonitor_6__source_idx;
const int _num__array_spikemonitor_6__source_idx = 100;
int32_t * _array_spikemonitor_6_count;
const int _num__array_spikemonitor_6_count = 100;
int32_t * _array_spikemonitor_6_N;
const int _num__array_spikemonitor_6_N = 1;
int32_t * _array_spikemonitor_7__source_idx;
const int _num__array_spikemonitor_7__source_idx = 400;
int32_t * _array_spikemonitor_7_count;
const int _num__array_spikemonitor_7_count = 400;
int32_t * _array_spikemonitor_7_N;
const int _num__array_spikemonitor_7_N = 1;
int32_t * _array_spikemonitor_8__source_idx;
const int _num__array_spikemonitor_8__source_idx = 100;
int32_t * _array_spikemonitor_8_count;
const int _num__array_spikemonitor_8_count = 100;
int32_t * _array_spikemonitor_8_N;
const int _num__array_spikemonitor_8_N = 1;
int32_t * _array_spikemonitor_9__source_idx;
const int _num__array_spikemonitor_9__source_idx = 400;
int32_t * _array_spikemonitor_9_count;
const int _num__array_spikemonitor_9_count = 400;
int32_t * _array_spikemonitor_9_N;
const int _num__array_spikemonitor_9_N = 1;
int32_t * _array_statemonitor_1__indices;
const int _num__array_statemonitor_1__indices = 400;
int32_t * _array_statemonitor_1_N;
const int _num__array_statemonitor_1_N = 1;
double * _array_statemonitor_1_phi;
const int _num__array_statemonitor_1_phi = (0, 400);
double * _array_statemonitor_1_V;
const int _num__array_statemonitor_1_V = (0, 400);
int32_t * _array_statemonitor_3__indices;
const int _num__array_statemonitor_3__indices = 400;
int32_t * _array_statemonitor_3_N;
const int _num__array_statemonitor_3_N = 1;
double * _array_statemonitor_3_phi;
const int _num__array_statemonitor_3_phi = (0, 400);
double * _array_statemonitor_3_V;
const int _num__array_statemonitor_3_V = (0, 400);
int32_t * _array_statemonitor_4__indices;
const int _num__array_statemonitor_4__indices = 400;
int32_t * _array_statemonitor_4_N;
const int _num__array_statemonitor_4_N = 1;
double * _array_statemonitor_4_phi;
const int _num__array_statemonitor_4_phi = (0, 400);
double * _array_statemonitor_4_V;
const int _num__array_statemonitor_4_V = (0, 400);
int32_t * _array_statemonitor_5__indices;
const int _num__array_statemonitor_5__indices = 400;
int32_t * _array_statemonitor_5_N;
const int _num__array_statemonitor_5_N = 1;
double * _array_statemonitor_5_phi;
const int _num__array_statemonitor_5_phi = (0, 400);
double * _array_statemonitor_5_V;
const int _num__array_statemonitor_5_V = (0, 400);
int32_t * _array_synapses_13_N;
const int _num__array_synapses_13_N = 1;
int32_t * _array_synapses_14_N;
const int _num__array_synapses_14_N = 1;
int32_t * _array_synapses_15_N;
const int _num__array_synapses_15_N = 1;
int32_t * _array_synapses_16_N;
const int _num__array_synapses_16_N = 1;
int32_t * _array_synapses_17_N;
const int _num__array_synapses_17_N = 1;
int32_t * _array_synapses_18_N;
const int _num__array_synapses_18_N = 1;
int32_t * _array_synapses_19_N;
const int _num__array_synapses_19_N = 1;
int32_t * _array_synapses_20_N;
const int _num__array_synapses_20_N = 1;
int32_t * _array_synapses_21_N;
const int _num__array_synapses_21_N = 1;
int32_t * _array_synapses_22_N;
const int _num__array_synapses_22_N = 1;
int32_t * _array_synapses_23_N;
const int _num__array_synapses_23_N = 1;
int32_t * _array_synapses_3_N;
const int _num__array_synapses_3_N = 1;
int32_t * _array_synapses_4_N;
const int _num__array_synapses_4_N = 1;
int32_t * _array_synapses_5_N;
const int _num__array_synapses_5_N = 1;
int32_t * _array_synapses_6_N;
const int _num__array_synapses_6_N = 1;
int32_t * _array_synapses_7_N;
const int _num__array_synapses_7_N = 1;

//////////////// dynamic arrays 1d /////////
std::vector<int32_t> _dynamic_array_spikemonitor_10_i;
std::vector<double> _dynamic_array_spikemonitor_10_t;
std::vector<int32_t> _dynamic_array_spikemonitor_11_i;
std::vector<double> _dynamic_array_spikemonitor_11_t;
std::vector<int32_t> _dynamic_array_spikemonitor_2_i;
std::vector<double> _dynamic_array_spikemonitor_2_t;
std::vector<int32_t> _dynamic_array_spikemonitor_3_i;
std::vector<double> _dynamic_array_spikemonitor_3_t;
std::vector<int32_t> _dynamic_array_spikemonitor_6_i;
std::vector<double> _dynamic_array_spikemonitor_6_t;
std::vector<int32_t> _dynamic_array_spikemonitor_7_i;
std::vector<double> _dynamic_array_spikemonitor_7_t;
std::vector<int32_t> _dynamic_array_spikemonitor_8_i;
std::vector<double> _dynamic_array_spikemonitor_8_t;
std::vector<int32_t> _dynamic_array_spikemonitor_9_i;
std::vector<double> _dynamic_array_spikemonitor_9_t;
std::vector<double> _dynamic_array_statemonitor_1_t;
std::vector<double> _dynamic_array_statemonitor_3_t;
std::vector<double> _dynamic_array_statemonitor_4_t;
std::vector<double> _dynamic_array_statemonitor_5_t;
std::vector<int32_t> _dynamic_array_synapses_13__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses_13__synaptic_pre;
std::vector<double> _dynamic_array_synapses_13_delay;
std::vector<int32_t> _dynamic_array_synapses_13_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_13_N_outgoing;
std::vector<int32_t> _dynamic_array_synapses_14__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses_14__synaptic_pre;
std::vector<double> _dynamic_array_synapses_14_delay;
std::vector<int32_t> _dynamic_array_synapses_14_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_14_N_outgoing;
std::vector<int32_t> _dynamic_array_synapses_15__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses_15__synaptic_pre;
std::vector<double> _dynamic_array_synapses_15_c;
std::vector<double> _dynamic_array_synapses_15_delay;
std::vector<int32_t> _dynamic_array_synapses_15_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_15_N_outgoing;
std::vector<int32_t> _dynamic_array_synapses_16__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses_16__synaptic_pre;
std::vector<double> _dynamic_array_synapses_16_delay;
std::vector<int32_t> _dynamic_array_synapses_16_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_16_N_outgoing;
std::vector<int32_t> _dynamic_array_synapses_17__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses_17__synaptic_pre;
std::vector<double> _dynamic_array_synapses_17_delay;
std::vector<int32_t> _dynamic_array_synapses_17_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_17_N_outgoing;
std::vector<int32_t> _dynamic_array_synapses_18__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses_18__synaptic_pre;
std::vector<double> _dynamic_array_synapses_18_delay;
std::vector<int32_t> _dynamic_array_synapses_18_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_18_N_outgoing;
std::vector<int32_t> _dynamic_array_synapses_19__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses_19__synaptic_pre;
std::vector<double> _dynamic_array_synapses_19_c;
std::vector<double> _dynamic_array_synapses_19_delay;
std::vector<int32_t> _dynamic_array_synapses_19_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_19_N_outgoing;
std::vector<int32_t> _dynamic_array_synapses_20__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses_20__synaptic_pre;
std::vector<double> _dynamic_array_synapses_20_delay;
std::vector<int32_t> _dynamic_array_synapses_20_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_20_N_outgoing;
std::vector<int32_t> _dynamic_array_synapses_21__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses_21__synaptic_pre;
std::vector<double> _dynamic_array_synapses_21_delay;
std::vector<int32_t> _dynamic_array_synapses_21_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_21_N_outgoing;
std::vector<int32_t> _dynamic_array_synapses_22__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses_22__synaptic_pre;
std::vector<double> _dynamic_array_synapses_22_delay;
std::vector<int32_t> _dynamic_array_synapses_22_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_22_N_outgoing;
std::vector<int32_t> _dynamic_array_synapses_23__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses_23__synaptic_pre;
std::vector<double> _dynamic_array_synapses_23_c;
std::vector<double> _dynamic_array_synapses_23_delay;
std::vector<int32_t> _dynamic_array_synapses_23_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_23_N_outgoing;
std::vector<int32_t> _dynamic_array_synapses_3__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses_3__synaptic_pre;
std::vector<double> _dynamic_array_synapses_3_delay;
std::vector<int32_t> _dynamic_array_synapses_3_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_3_N_outgoing;
std::vector<int32_t> _dynamic_array_synapses_4__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses_4__synaptic_pre;
std::vector<double> _dynamic_array_synapses_4_delay;
std::vector<int32_t> _dynamic_array_synapses_4_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_4_N_outgoing;
std::vector<int32_t> _dynamic_array_synapses_5__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses_5__synaptic_pre;
std::vector<double> _dynamic_array_synapses_5_delay;
std::vector<int32_t> _dynamic_array_synapses_5_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_5_N_outgoing;
std::vector<int32_t> _dynamic_array_synapses_6__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses_6__synaptic_pre;
std::vector<double> _dynamic_array_synapses_6_delay;
std::vector<int32_t> _dynamic_array_synapses_6_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_6_N_outgoing;
std::vector<int32_t> _dynamic_array_synapses_7__synaptic_post;
std::vector<int32_t> _dynamic_array_synapses_7__synaptic_pre;
std::vector<double> _dynamic_array_synapses_7_c;
std::vector<double> _dynamic_array_synapses_7_delay;
std::vector<int32_t> _dynamic_array_synapses_7_N_incoming;
std::vector<int32_t> _dynamic_array_synapses_7_N_outgoing;

//////////////// dynamic arrays 2d /////////
DynamicArray2D<double> _dynamic_array_statemonitor_1_phi;
DynamicArray2D<double> _dynamic_array_statemonitor_1_V;
DynamicArray2D<double> _dynamic_array_statemonitor_3_phi;
DynamicArray2D<double> _dynamic_array_statemonitor_3_V;
DynamicArray2D<double> _dynamic_array_statemonitor_4_phi;
DynamicArray2D<double> _dynamic_array_statemonitor_4_V;
DynamicArray2D<double> _dynamic_array_statemonitor_5_phi;
DynamicArray2D<double> _dynamic_array_statemonitor_5_V;

/////////////// static arrays /////////////
int32_t * _static_array__array_statemonitor_1__indices;
const int _num__static_array__array_statemonitor_1__indices = 400;
int32_t * _static_array__array_statemonitor_3__indices;
const int _num__static_array__array_statemonitor_3__indices = 400;
int32_t * _static_array__array_statemonitor_4__indices;
const int _num__static_array__array_statemonitor_4__indices = 400;
int32_t * _static_array__array_statemonitor_5__indices;
const int _num__static_array__array_statemonitor_5__indices = 400;

//////////////// synapses /////////////////
// synapses_13
SynapticPathway synapses_13_pre(
		_dynamic_array_synapses_13__synaptic_pre,
		0, 100);
// synapses_14
SynapticPathway synapses_14_pre(
		_dynamic_array_synapses_14__synaptic_pre,
		0, 400);
// synapses_15
SynapticPathway synapses_15_pre(
		_dynamic_array_synapses_15__synaptic_pre,
		0, 400);
// synapses_16
SynapticPathway synapses_16_pre(
		_dynamic_array_synapses_16__synaptic_pre,
		0, 100);
// synapses_17
SynapticPathway synapses_17_pre(
		_dynamic_array_synapses_17__synaptic_pre,
		0, 100);
// synapses_18
SynapticPathway synapses_18_pre(
		_dynamic_array_synapses_18__synaptic_pre,
		0, 400);
// synapses_19
SynapticPathway synapses_19_pre(
		_dynamic_array_synapses_19__synaptic_pre,
		0, 400);
// synapses_20
SynapticPathway synapses_20_pre(
		_dynamic_array_synapses_20__synaptic_pre,
		0, 100);
// synapses_21
SynapticPathway synapses_21_pre(
		_dynamic_array_synapses_21__synaptic_pre,
		0, 100);
// synapses_22
SynapticPathway synapses_22_pre(
		_dynamic_array_synapses_22__synaptic_pre,
		0, 400);
// synapses_23
SynapticPathway synapses_23_pre(
		_dynamic_array_synapses_23__synaptic_pre,
		0, 400);
// synapses_3
SynapticPathway synapses_3_pre(
		_dynamic_array_synapses_3__synaptic_pre,
		0, 100);
// synapses_4
SynapticPathway synapses_4_pre(
		_dynamic_array_synapses_4__synaptic_pre,
		0, 100);
// synapses_5
SynapticPathway synapses_5_pre(
		_dynamic_array_synapses_5__synaptic_pre,
		0, 100);
// synapses_6
SynapticPathway synapses_6_pre(
		_dynamic_array_synapses_6__synaptic_pre,
		0, 400);
// synapses_7
SynapticPathway synapses_7_pre(
		_dynamic_array_synapses_7__synaptic_pre,
		0, 400);

//////////////// clocks ///////////////////
Clock defaultclock;  // attributes will be set in run.cpp
Clock networkoperation_1_clock;  // attributes will be set in run.cpp
Clock networkoperation_3_clock;  // attributes will be set in run.cpp
Clock networkoperation_4_clock;  // attributes will be set in run.cpp
Clock networkoperation_5_clock;  // attributes will be set in run.cpp

// Profiling information for each code object
}

void _init_arrays()
{
	using namespace brian;

    // Arrays initialized to 0
	_array_defaultclock_dt = new double[1];
    
	for(int i=0; i<1; i++) _array_defaultclock_dt[i] = 0;

	_array_defaultclock_t = new double[1];
    
	for(int i=0; i<1; i++) _array_defaultclock_t[i] = 0;

	_array_defaultclock_timestep = new int64_t[1];
    
	for(int i=0; i<1; i++) _array_defaultclock_timestep[i] = 0;

	_array_networkoperation_1_clock_dt = new double[1];
    
	for(int i=0; i<1; i++) _array_networkoperation_1_clock_dt[i] = 0;

	_array_networkoperation_1_clock_t = new double[1];
    
	for(int i=0; i<1; i++) _array_networkoperation_1_clock_t[i] = 0;

	_array_networkoperation_1_clock_timestep = new int64_t[1];
    
	for(int i=0; i<1; i++) _array_networkoperation_1_clock_timestep[i] = 0;

	_array_networkoperation_3_clock_dt = new double[1];
    
	for(int i=0; i<1; i++) _array_networkoperation_3_clock_dt[i] = 0;

	_array_networkoperation_3_clock_t = new double[1];
    
	for(int i=0; i<1; i++) _array_networkoperation_3_clock_t[i] = 0;

	_array_networkoperation_3_clock_timestep = new int64_t[1];
    
	for(int i=0; i<1; i++) _array_networkoperation_3_clock_timestep[i] = 0;

	_array_networkoperation_4_clock_dt = new double[1];
    
	for(int i=0; i<1; i++) _array_networkoperation_4_clock_dt[i] = 0;

	_array_networkoperation_4_clock_t = new double[1];
    
	for(int i=0; i<1; i++) _array_networkoperation_4_clock_t[i] = 0;

	_array_networkoperation_4_clock_timestep = new int64_t[1];
    
	for(int i=0; i<1; i++) _array_networkoperation_4_clock_timestep[i] = 0;

	_array_networkoperation_5_clock_dt = new double[1];
    
	for(int i=0; i<1; i++) _array_networkoperation_5_clock_dt[i] = 0;

	_array_networkoperation_5_clock_t = new double[1];
    
	for(int i=0; i<1; i++) _array_networkoperation_5_clock_t[i] = 0;

	_array_networkoperation_5_clock_timestep = new int64_t[1];
    
	for(int i=0; i<1; i++) _array_networkoperation_5_clock_timestep[i] = 0;

	_array_neurongroup_10__spikespace = new int32_t[401];
    
	for(int i=0; i<401; i++) _array_neurongroup_10__spikespace[i] = 0;

	_array_neurongroup_10_a = new double[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_10_a[i] = 0;

	_array_neurongroup_10_d = new double[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_10_d[i] = 0;

	_array_neurongroup_10_i = new int32_t[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_10_i[i] = 0;

	_array_neurongroup_10_lastspike = new double[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_10_lastspike[i] = 0;

	_array_neurongroup_10_not_refractory = new char[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_10_not_refractory[i] = 0;

	_array_neurongroup_10_phi = new double[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_10_phi[i] = 0;

	_array_neurongroup_10_V = new double[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_10_V[i] = 0;

	_array_neurongroup_11__spikespace = new int32_t[101];
    
	for(int i=0; i<101; i++) _array_neurongroup_11__spikespace[i] = 0;

	_array_neurongroup_11_i = new int32_t[100];
    
	for(int i=0; i<100; i++) _array_neurongroup_11_i[i] = 0;

	_array_neurongroup_11_lastspike = new double[100];
    
	for(int i=0; i<100; i++) _array_neurongroup_11_lastspike[i] = 0;

	_array_neurongroup_11_not_refractory = new char[100];
    
	for(int i=0; i<100; i++) _array_neurongroup_11_not_refractory[i] = 0;

	_array_neurongroup_11_V = new double[100];
    
	for(int i=0; i<100; i++) _array_neurongroup_11_V[i] = 0;

	_array_neurongroup_1__spikespace = new int32_t[101];
    
	for(int i=0; i<101; i++) _array_neurongroup_1__spikespace[i] = 0;

	_array_neurongroup_1_i = new int32_t[100];
    
	for(int i=0; i<100; i++) _array_neurongroup_1_i[i] = 0;

	_array_neurongroup_1_lastspike = new double[100];
    
	for(int i=0; i<100; i++) _array_neurongroup_1_lastspike[i] = 0;

	_array_neurongroup_1_not_refractory = new char[100];
    
	for(int i=0; i<100; i++) _array_neurongroup_1_not_refractory[i] = 0;

	_array_neurongroup_1_V = new double[100];
    
	for(int i=0; i<100; i++) _array_neurongroup_1_V[i] = 0;

	_array_neurongroup_2__spikespace = new int32_t[401];
    
	for(int i=0; i<401; i++) _array_neurongroup_2__spikespace[i] = 0;

	_array_neurongroup_2_a = new double[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_2_a[i] = 0;

	_array_neurongroup_2_d = new double[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_2_d[i] = 0;

	_array_neurongroup_2_i = new int32_t[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_2_i[i] = 0;

	_array_neurongroup_2_lastspike = new double[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_2_lastspike[i] = 0;

	_array_neurongroup_2_not_refractory = new char[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_2_not_refractory[i] = 0;

	_array_neurongroup_2_phi = new double[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_2_phi[i] = 0;

	_array_neurongroup_2_V = new double[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_2_V[i] = 0;

	_array_neurongroup_3__spikespace = new int32_t[101];
    
	for(int i=0; i<101; i++) _array_neurongroup_3__spikespace[i] = 0;

	_array_neurongroup_3_i = new int32_t[100];
    
	for(int i=0; i<100; i++) _array_neurongroup_3_i[i] = 0;

	_array_neurongroup_3_lastspike = new double[100];
    
	for(int i=0; i<100; i++) _array_neurongroup_3_lastspike[i] = 0;

	_array_neurongroup_3_not_refractory = new char[100];
    
	for(int i=0; i<100; i++) _array_neurongroup_3_not_refractory[i] = 0;

	_array_neurongroup_3_V = new double[100];
    
	for(int i=0; i<100; i++) _array_neurongroup_3_V[i] = 0;

	_array_neurongroup_8__spikespace = new int32_t[401];
    
	for(int i=0; i<401; i++) _array_neurongroup_8__spikespace[i] = 0;

	_array_neurongroup_8_a = new double[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_8_a[i] = 0;

	_array_neurongroup_8_d = new double[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_8_d[i] = 0;

	_array_neurongroup_8_i = new int32_t[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_8_i[i] = 0;

	_array_neurongroup_8_lastspike = new double[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_8_lastspike[i] = 0;

	_array_neurongroup_8_not_refractory = new char[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_8_not_refractory[i] = 0;

	_array_neurongroup_8_phi = new double[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_8_phi[i] = 0;

	_array_neurongroup_8_V = new double[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_8_V[i] = 0;

	_array_neurongroup_9__spikespace = new int32_t[101];
    
	for(int i=0; i<101; i++) _array_neurongroup_9__spikespace[i] = 0;

	_array_neurongroup_9_i = new int32_t[100];
    
	for(int i=0; i<100; i++) _array_neurongroup_9_i[i] = 0;

	_array_neurongroup_9_lastspike = new double[100];
    
	for(int i=0; i<100; i++) _array_neurongroup_9_lastspike[i] = 0;

	_array_neurongroup_9_not_refractory = new char[100];
    
	for(int i=0; i<100; i++) _array_neurongroup_9_not_refractory[i] = 0;

	_array_neurongroup_9_V = new double[100];
    
	for(int i=0; i<100; i++) _array_neurongroup_9_V[i] = 0;

	_array_neurongroup__spikespace = new int32_t[401];
    
	for(int i=0; i<401; i++) _array_neurongroup__spikespace[i] = 0;

	_array_neurongroup_a = new double[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_a[i] = 0;

	_array_neurongroup_d = new double[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_d[i] = 0;

	_array_neurongroup_i = new int32_t[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_i[i] = 0;

	_array_neurongroup_lastspike = new double[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_lastspike[i] = 0;

	_array_neurongroup_not_refractory = new char[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_not_refractory[i] = 0;

	_array_neurongroup_phi = new double[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_phi[i] = 0;

	_array_neurongroup_V = new double[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_V[i] = 0;

	_array_spikemonitor_10__source_idx = new int32_t[100];
    
	for(int i=0; i<100; i++) _array_spikemonitor_10__source_idx[i] = 0;

	_array_spikemonitor_10_count = new int32_t[100];
    
	for(int i=0; i<100; i++) _array_spikemonitor_10_count[i] = 0;

	_array_spikemonitor_10_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_spikemonitor_10_N[i] = 0;

	_array_spikemonitor_11__source_idx = new int32_t[400];
    
	for(int i=0; i<400; i++) _array_spikemonitor_11__source_idx[i] = 0;

	_array_spikemonitor_11_count = new int32_t[400];
    
	for(int i=0; i<400; i++) _array_spikemonitor_11_count[i] = 0;

	_array_spikemonitor_11_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_spikemonitor_11_N[i] = 0;

	_array_spikemonitor_2__source_idx = new int32_t[100];
    
	for(int i=0; i<100; i++) _array_spikemonitor_2__source_idx[i] = 0;

	_array_spikemonitor_2_count = new int32_t[100];
    
	for(int i=0; i<100; i++) _array_spikemonitor_2_count[i] = 0;

	_array_spikemonitor_2_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_spikemonitor_2_N[i] = 0;

	_array_spikemonitor_3__source_idx = new int32_t[400];
    
	for(int i=0; i<400; i++) _array_spikemonitor_3__source_idx[i] = 0;

	_array_spikemonitor_3_count = new int32_t[400];
    
	for(int i=0; i<400; i++) _array_spikemonitor_3_count[i] = 0;

	_array_spikemonitor_3_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_spikemonitor_3_N[i] = 0;

	_array_spikemonitor_6__source_idx = new int32_t[100];
    
	for(int i=0; i<100; i++) _array_spikemonitor_6__source_idx[i] = 0;

	_array_spikemonitor_6_count = new int32_t[100];
    
	for(int i=0; i<100; i++) _array_spikemonitor_6_count[i] = 0;

	_array_spikemonitor_6_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_spikemonitor_6_N[i] = 0;

	_array_spikemonitor_7__source_idx = new int32_t[400];
    
	for(int i=0; i<400; i++) _array_spikemonitor_7__source_idx[i] = 0;

	_array_spikemonitor_7_count = new int32_t[400];
    
	for(int i=0; i<400; i++) _array_spikemonitor_7_count[i] = 0;

	_array_spikemonitor_7_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_spikemonitor_7_N[i] = 0;

	_array_spikemonitor_8__source_idx = new int32_t[100];
    
	for(int i=0; i<100; i++) _array_spikemonitor_8__source_idx[i] = 0;

	_array_spikemonitor_8_count = new int32_t[100];
    
	for(int i=0; i<100; i++) _array_spikemonitor_8_count[i] = 0;

	_array_spikemonitor_8_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_spikemonitor_8_N[i] = 0;

	_array_spikemonitor_9__source_idx = new int32_t[400];
    
	for(int i=0; i<400; i++) _array_spikemonitor_9__source_idx[i] = 0;

	_array_spikemonitor_9_count = new int32_t[400];
    
	for(int i=0; i<400; i++) _array_spikemonitor_9_count[i] = 0;

	_array_spikemonitor_9_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_spikemonitor_9_N[i] = 0;

	_array_statemonitor_1__indices = new int32_t[400];
    
	for(int i=0; i<400; i++) _array_statemonitor_1__indices[i] = 0;

	_array_statemonitor_1_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_statemonitor_1_N[i] = 0;

	_array_statemonitor_3__indices = new int32_t[400];
    
	for(int i=0; i<400; i++) _array_statemonitor_3__indices[i] = 0;

	_array_statemonitor_3_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_statemonitor_3_N[i] = 0;

	_array_statemonitor_4__indices = new int32_t[400];
    
	for(int i=0; i<400; i++) _array_statemonitor_4__indices[i] = 0;

	_array_statemonitor_4_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_statemonitor_4_N[i] = 0;

	_array_statemonitor_5__indices = new int32_t[400];
    
	for(int i=0; i<400; i++) _array_statemonitor_5__indices[i] = 0;

	_array_statemonitor_5_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_statemonitor_5_N[i] = 0;

	_array_synapses_13_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_synapses_13_N[i] = 0;

	_array_synapses_14_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_synapses_14_N[i] = 0;

	_array_synapses_15_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_synapses_15_N[i] = 0;

	_array_synapses_16_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_synapses_16_N[i] = 0;

	_array_synapses_17_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_synapses_17_N[i] = 0;

	_array_synapses_18_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_synapses_18_N[i] = 0;

	_array_synapses_19_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_synapses_19_N[i] = 0;

	_array_synapses_20_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_synapses_20_N[i] = 0;

	_array_synapses_21_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_synapses_21_N[i] = 0;

	_array_synapses_22_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_synapses_22_N[i] = 0;

	_array_synapses_23_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_synapses_23_N[i] = 0;

	_array_synapses_3_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_synapses_3_N[i] = 0;

	_array_synapses_4_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_synapses_4_N[i] = 0;

	_array_synapses_5_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_synapses_5_N[i] = 0;

	_array_synapses_6_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_synapses_6_N[i] = 0;

	_array_synapses_7_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_synapses_7_N[i] = 0;

	_dynamic_array_synapses_13_delay.resize(1);
    
	for(int i=0; i<1; i++) _dynamic_array_synapses_13_delay[i] = 0;

	_dynamic_array_synapses_14_delay.resize(1);
    
	for(int i=0; i<1; i++) _dynamic_array_synapses_14_delay[i] = 0;

	_dynamic_array_synapses_15_delay.resize(1);
    
	for(int i=0; i<1; i++) _dynamic_array_synapses_15_delay[i] = 0;

	_dynamic_array_synapses_16_delay.resize(1);
    
	for(int i=0; i<1; i++) _dynamic_array_synapses_16_delay[i] = 0;

	_dynamic_array_synapses_17_delay.resize(1);
    
	for(int i=0; i<1; i++) _dynamic_array_synapses_17_delay[i] = 0;

	_dynamic_array_synapses_18_delay.resize(1);
    
	for(int i=0; i<1; i++) _dynamic_array_synapses_18_delay[i] = 0;

	_dynamic_array_synapses_19_delay.resize(1);
    
	for(int i=0; i<1; i++) _dynamic_array_synapses_19_delay[i] = 0;

	_dynamic_array_synapses_20_delay.resize(1);
    
	for(int i=0; i<1; i++) _dynamic_array_synapses_20_delay[i] = 0;

	_dynamic_array_synapses_21_delay.resize(1);
    
	for(int i=0; i<1; i++) _dynamic_array_synapses_21_delay[i] = 0;

	_dynamic_array_synapses_22_delay.resize(1);
    
	for(int i=0; i<1; i++) _dynamic_array_synapses_22_delay[i] = 0;

	_dynamic_array_synapses_23_delay.resize(1);
    
	for(int i=0; i<1; i++) _dynamic_array_synapses_23_delay[i] = 0;

	_dynamic_array_synapses_3_delay.resize(1);
    
	for(int i=0; i<1; i++) _dynamic_array_synapses_3_delay[i] = 0;

	_dynamic_array_synapses_4_delay.resize(1);
    
	for(int i=0; i<1; i++) _dynamic_array_synapses_4_delay[i] = 0;

	_dynamic_array_synapses_5_delay.resize(1);
    
	for(int i=0; i<1; i++) _dynamic_array_synapses_5_delay[i] = 0;

	_dynamic_array_synapses_6_delay.resize(1);
    
	for(int i=0; i<1; i++) _dynamic_array_synapses_6_delay[i] = 0;

	_dynamic_array_synapses_7_delay.resize(1);
    
	for(int i=0; i<1; i++) _dynamic_array_synapses_7_delay[i] = 0;


	// Arrays initialized to an "arange"
	_array_neurongroup_10_i = new int32_t[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_10_i[i] = 0 + i;

	_array_neurongroup_11_i = new int32_t[100];
    
	for(int i=0; i<100; i++) _array_neurongroup_11_i[i] = 0 + i;

	_array_neurongroup_1_i = new int32_t[100];
    
	for(int i=0; i<100; i++) _array_neurongroup_1_i[i] = 0 + i;

	_array_neurongroup_2_i = new int32_t[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_2_i[i] = 0 + i;

	_array_neurongroup_3_i = new int32_t[100];
    
	for(int i=0; i<100; i++) _array_neurongroup_3_i[i] = 0 + i;

	_array_neurongroup_8_i = new int32_t[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_8_i[i] = 0 + i;

	_array_neurongroup_9_i = new int32_t[100];
    
	for(int i=0; i<100; i++) _array_neurongroup_9_i[i] = 0 + i;

	_array_neurongroup_i = new int32_t[400];
    
	for(int i=0; i<400; i++) _array_neurongroup_i[i] = 0 + i;

	_array_spikemonitor_10__source_idx = new int32_t[100];
    
	for(int i=0; i<100; i++) _array_spikemonitor_10__source_idx[i] = 0 + i;

	_array_spikemonitor_11__source_idx = new int32_t[400];
    
	for(int i=0; i<400; i++) _array_spikemonitor_11__source_idx[i] = 0 + i;

	_array_spikemonitor_2__source_idx = new int32_t[100];
    
	for(int i=0; i<100; i++) _array_spikemonitor_2__source_idx[i] = 0 + i;

	_array_spikemonitor_3__source_idx = new int32_t[400];
    
	for(int i=0; i<400; i++) _array_spikemonitor_3__source_idx[i] = 0 + i;

	_array_spikemonitor_6__source_idx = new int32_t[100];
    
	for(int i=0; i<100; i++) _array_spikemonitor_6__source_idx[i] = 0 + i;

	_array_spikemonitor_7__source_idx = new int32_t[400];
    
	for(int i=0; i<400; i++) _array_spikemonitor_7__source_idx[i] = 0 + i;

	_array_spikemonitor_8__source_idx = new int32_t[100];
    
	for(int i=0; i<100; i++) _array_spikemonitor_8__source_idx[i] = 0 + i;

	_array_spikemonitor_9__source_idx = new int32_t[400];
    
	for(int i=0; i<400; i++) _array_spikemonitor_9__source_idx[i] = 0 + i;


	// static arrays
	_static_array__array_statemonitor_1__indices = new int32_t[400];
	_static_array__array_statemonitor_3__indices = new int32_t[400];
	_static_array__array_statemonitor_4__indices = new int32_t[400];
	_static_array__array_statemonitor_5__indices = new int32_t[400];

	// Random number generator states
	for (int i=0; i<1; i++)
	    _mersenne_twister_states.push_back(new rk_state());
}

void _load_arrays()
{
	using namespace brian;

	ifstream f_static_array__array_statemonitor_1__indices;
	f_static_array__array_statemonitor_1__indices.open("static_arrays/_static_array__array_statemonitor_1__indices", ios::in | ios::binary);
	if(f_static_array__array_statemonitor_1__indices.is_open())
	{
		f_static_array__array_statemonitor_1__indices.read(reinterpret_cast<char*>(_static_array__array_statemonitor_1__indices), 400*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_statemonitor_1__indices." << endl;
	}
	ifstream f_static_array__array_statemonitor_3__indices;
	f_static_array__array_statemonitor_3__indices.open("static_arrays/_static_array__array_statemonitor_3__indices", ios::in | ios::binary);
	if(f_static_array__array_statemonitor_3__indices.is_open())
	{
		f_static_array__array_statemonitor_3__indices.read(reinterpret_cast<char*>(_static_array__array_statemonitor_3__indices), 400*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_statemonitor_3__indices." << endl;
	}
	ifstream f_static_array__array_statemonitor_4__indices;
	f_static_array__array_statemonitor_4__indices.open("static_arrays/_static_array__array_statemonitor_4__indices", ios::in | ios::binary);
	if(f_static_array__array_statemonitor_4__indices.is_open())
	{
		f_static_array__array_statemonitor_4__indices.read(reinterpret_cast<char*>(_static_array__array_statemonitor_4__indices), 400*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_statemonitor_4__indices." << endl;
	}
	ifstream f_static_array__array_statemonitor_5__indices;
	f_static_array__array_statemonitor_5__indices.open("static_arrays/_static_array__array_statemonitor_5__indices", ios::in | ios::binary);
	if(f_static_array__array_statemonitor_5__indices.is_open())
	{
		f_static_array__array_statemonitor_5__indices.read(reinterpret_cast<char*>(_static_array__array_statemonitor_5__indices), 400*sizeof(int32_t));
	} else
	{
		std::cout << "Error opening static array _static_array__array_statemonitor_5__indices." << endl;
	}
}

void _write_arrays()
{
	using namespace brian;

	ofstream outfile__array_defaultclock_dt;
	outfile__array_defaultclock_dt.open("results/_array_defaultclock_dt_1978099143", ios::binary | ios::out);
	if(outfile__array_defaultclock_dt.is_open())
	{
		outfile__array_defaultclock_dt.write(reinterpret_cast<char*>(_array_defaultclock_dt), 1*sizeof(_array_defaultclock_dt[0]));
		outfile__array_defaultclock_dt.close();
	} else
	{
		std::cout << "Error writing output file for _array_defaultclock_dt." << endl;
	}
	ofstream outfile__array_defaultclock_t;
	outfile__array_defaultclock_t.open("results/_array_defaultclock_t_2669362164", ios::binary | ios::out);
	if(outfile__array_defaultclock_t.is_open())
	{
		outfile__array_defaultclock_t.write(reinterpret_cast<char*>(_array_defaultclock_t), 1*sizeof(_array_defaultclock_t[0]));
		outfile__array_defaultclock_t.close();
	} else
	{
		std::cout << "Error writing output file for _array_defaultclock_t." << endl;
	}
	ofstream outfile__array_defaultclock_timestep;
	outfile__array_defaultclock_timestep.open("results/_array_defaultclock_timestep_144223508", ios::binary | ios::out);
	if(outfile__array_defaultclock_timestep.is_open())
	{
		outfile__array_defaultclock_timestep.write(reinterpret_cast<char*>(_array_defaultclock_timestep), 1*sizeof(_array_defaultclock_timestep[0]));
		outfile__array_defaultclock_timestep.close();
	} else
	{
		std::cout << "Error writing output file for _array_defaultclock_timestep." << endl;
	}
	ofstream outfile__array_networkoperation_1_clock_dt;
	outfile__array_networkoperation_1_clock_dt.open("results/_array_networkoperation_1_clock_dt_2362319888", ios::binary | ios::out);
	if(outfile__array_networkoperation_1_clock_dt.is_open())
	{
		outfile__array_networkoperation_1_clock_dt.write(reinterpret_cast<char*>(_array_networkoperation_1_clock_dt), 1*sizeof(_array_networkoperation_1_clock_dt[0]));
		outfile__array_networkoperation_1_clock_dt.close();
	} else
	{
		std::cout << "Error writing output file for _array_networkoperation_1_clock_dt." << endl;
	}
	ofstream outfile__array_networkoperation_1_clock_t;
	outfile__array_networkoperation_1_clock_t.open("results/_array_networkoperation_1_clock_t_260408168", ios::binary | ios::out);
	if(outfile__array_networkoperation_1_clock_t.is_open())
	{
		outfile__array_networkoperation_1_clock_t.write(reinterpret_cast<char*>(_array_networkoperation_1_clock_t), 1*sizeof(_array_networkoperation_1_clock_t[0]));
		outfile__array_networkoperation_1_clock_t.close();
	} else
	{
		std::cout << "Error writing output file for _array_networkoperation_1_clock_t." << endl;
	}
	ofstream outfile__array_networkoperation_1_clock_timestep;
	outfile__array_networkoperation_1_clock_timestep.open("results/_array_networkoperation_1_clock_timestep_85940369", ios::binary | ios::out);
	if(outfile__array_networkoperation_1_clock_timestep.is_open())
	{
		outfile__array_networkoperation_1_clock_timestep.write(reinterpret_cast<char*>(_array_networkoperation_1_clock_timestep), 1*sizeof(_array_networkoperation_1_clock_timestep[0]));
		outfile__array_networkoperation_1_clock_timestep.close();
	} else
	{
		std::cout << "Error writing output file for _array_networkoperation_1_clock_timestep." << endl;
	}
	ofstream outfile__array_networkoperation_3_clock_dt;
	outfile__array_networkoperation_3_clock_dt.open("results/_array_networkoperation_3_clock_dt_2285630509", ios::binary | ios::out);
	if(outfile__array_networkoperation_3_clock_dt.is_open())
	{
		outfile__array_networkoperation_3_clock_dt.write(reinterpret_cast<char*>(_array_networkoperation_3_clock_dt), 1*sizeof(_array_networkoperation_3_clock_dt[0]));
		outfile__array_networkoperation_3_clock_dt.close();
	} else
	{
		std::cout << "Error writing output file for _array_networkoperation_3_clock_dt." << endl;
	}
	ofstream outfile__array_networkoperation_3_clock_t;
	outfile__array_networkoperation_3_clock_t.open("results/_array_networkoperation_3_clock_t_561228782", ios::binary | ios::out);
	if(outfile__array_networkoperation_3_clock_t.is_open())
	{
		outfile__array_networkoperation_3_clock_t.write(reinterpret_cast<char*>(_array_networkoperation_3_clock_t), 1*sizeof(_array_networkoperation_3_clock_t[0]));
		outfile__array_networkoperation_3_clock_t.close();
	} else
	{
		std::cout << "Error writing output file for _array_networkoperation_3_clock_t." << endl;
	}
	ofstream outfile__array_networkoperation_3_clock_timestep;
	outfile__array_networkoperation_3_clock_timestep.open("results/_array_networkoperation_3_clock_timestep_2193587698", ios::binary | ios::out);
	if(outfile__array_networkoperation_3_clock_timestep.is_open())
	{
		outfile__array_networkoperation_3_clock_timestep.write(reinterpret_cast<char*>(_array_networkoperation_3_clock_timestep), 1*sizeof(_array_networkoperation_3_clock_timestep[0]));
		outfile__array_networkoperation_3_clock_timestep.close();
	} else
	{
		std::cout << "Error writing output file for _array_networkoperation_3_clock_timestep." << endl;
	}
	ofstream outfile__array_networkoperation_4_clock_dt;
	outfile__array_networkoperation_4_clock_dt.open("results/_array_networkoperation_4_clock_dt_1793584980", ios::binary | ios::out);
	if(outfile__array_networkoperation_4_clock_dt.is_open())
	{
		outfile__array_networkoperation_4_clock_dt.write(reinterpret_cast<char*>(_array_networkoperation_4_clock_dt), 1*sizeof(_array_networkoperation_4_clock_dt[0]));
		outfile__array_networkoperation_4_clock_dt.close();
	} else
	{
		std::cout << "Error writing output file for _array_networkoperation_4_clock_dt." << endl;
	}
	ofstream outfile__array_networkoperation_4_clock_t;
	outfile__array_networkoperation_4_clock_t.open("results/_array_networkoperation_4_clock_t_1158858279", ios::binary | ios::out);
	if(outfile__array_networkoperation_4_clock_t.is_open())
	{
		outfile__array_networkoperation_4_clock_t.write(reinterpret_cast<char*>(_array_networkoperation_4_clock_t), 1*sizeof(_array_networkoperation_4_clock_t[0]));
		outfile__array_networkoperation_4_clock_t.close();
	} else
	{
		std::cout << "Error writing output file for _array_networkoperation_4_clock_t." << endl;
	}
	ofstream outfile__array_networkoperation_4_clock_timestep;
	outfile__array_networkoperation_4_clock_timestep.open("results/_array_networkoperation_4_clock_timestep_2135328135", ios::binary | ios::out);
	if(outfile__array_networkoperation_4_clock_timestep.is_open())
	{
		outfile__array_networkoperation_4_clock_timestep.write(reinterpret_cast<char*>(_array_networkoperation_4_clock_timestep), 1*sizeof(_array_networkoperation_4_clock_timestep[0]));
		outfile__array_networkoperation_4_clock_timestep.close();
	} else
	{
		std::cout << "Error writing output file for _array_networkoperation_4_clock_timestep." << endl;
	}
	ofstream outfile__array_networkoperation_5_clock_dt;
	outfile__array_networkoperation_5_clock_dt.open("results/_array_networkoperation_5_clock_dt_2233828458", ios::binary | ios::out);
	if(outfile__array_networkoperation_5_clock_dt.is_open())
	{
		outfile__array_networkoperation_5_clock_dt.write(reinterpret_cast<char*>(_array_networkoperation_5_clock_dt), 1*sizeof(_array_networkoperation_5_clock_dt[0]));
		outfile__array_networkoperation_5_clock_dt.close();
	} else
	{
		std::cout << "Error writing output file for _array_networkoperation_5_clock_dt." << endl;
	}
	ofstream outfile__array_networkoperation_5_clock_t;
	outfile__array_networkoperation_5_clock_t.open("results/_array_networkoperation_5_clock_t_1382666852", ios::binary | ios::out);
	if(outfile__array_networkoperation_5_clock_t.is_open())
	{
		outfile__array_networkoperation_5_clock_t.write(reinterpret_cast<char*>(_array_networkoperation_5_clock_t), 1*sizeof(_array_networkoperation_5_clock_t[0]));
		outfile__array_networkoperation_5_clock_t.close();
	} else
	{
		std::cout << "Error writing output file for _array_networkoperation_5_clock_t." << endl;
	}
	ofstream outfile__array_networkoperation_5_clock_timestep;
	outfile__array_networkoperation_5_clock_timestep.open("results/_array_networkoperation_5_clock_timestep_3509457942", ios::binary | ios::out);
	if(outfile__array_networkoperation_5_clock_timestep.is_open())
	{
		outfile__array_networkoperation_5_clock_timestep.write(reinterpret_cast<char*>(_array_networkoperation_5_clock_timestep), 1*sizeof(_array_networkoperation_5_clock_timestep[0]));
		outfile__array_networkoperation_5_clock_timestep.close();
	} else
	{
		std::cout << "Error writing output file for _array_networkoperation_5_clock_timestep." << endl;
	}
	ofstream outfile__array_neurongroup_10__spikespace;
	outfile__array_neurongroup_10__spikespace.open("results/_array_neurongroup_10__spikespace_2041327750", ios::binary | ios::out);
	if(outfile__array_neurongroup_10__spikespace.is_open())
	{
		outfile__array_neurongroup_10__spikespace.write(reinterpret_cast<char*>(_array_neurongroup_10__spikespace), 401*sizeof(_array_neurongroup_10__spikespace[0]));
		outfile__array_neurongroup_10__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_10__spikespace." << endl;
	}
	ofstream outfile__array_neurongroup_10_a;
	outfile__array_neurongroup_10_a.open("results/_array_neurongroup_10_a_2582701594", ios::binary | ios::out);
	if(outfile__array_neurongroup_10_a.is_open())
	{
		outfile__array_neurongroup_10_a.write(reinterpret_cast<char*>(_array_neurongroup_10_a), 400*sizeof(_array_neurongroup_10_a[0]));
		outfile__array_neurongroup_10_a.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_10_a." << endl;
	}
	ofstream outfile__array_neurongroup_10_d;
	outfile__array_neurongroup_10_d.open("results/_array_neurongroup_10_d_3919188629", ios::binary | ios::out);
	if(outfile__array_neurongroup_10_d.is_open())
	{
		outfile__array_neurongroup_10_d.write(reinterpret_cast<char*>(_array_neurongroup_10_d), 400*sizeof(_array_neurongroup_10_d[0]));
		outfile__array_neurongroup_10_d.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_10_d." << endl;
	}
	ofstream outfile__array_neurongroup_10_i;
	outfile__array_neurongroup_10_i.open("results/_array_neurongroup_10_i_2536205864", ios::binary | ios::out);
	if(outfile__array_neurongroup_10_i.is_open())
	{
		outfile__array_neurongroup_10_i.write(reinterpret_cast<char*>(_array_neurongroup_10_i), 400*sizeof(_array_neurongroup_10_i[0]));
		outfile__array_neurongroup_10_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_10_i." << endl;
	}
	ofstream outfile__array_neurongroup_10_lastspike;
	outfile__array_neurongroup_10_lastspike.open("results/_array_neurongroup_10_lastspike_2819232347", ios::binary | ios::out);
	if(outfile__array_neurongroup_10_lastspike.is_open())
	{
		outfile__array_neurongroup_10_lastspike.write(reinterpret_cast<char*>(_array_neurongroup_10_lastspike), 400*sizeof(_array_neurongroup_10_lastspike[0]));
		outfile__array_neurongroup_10_lastspike.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_10_lastspike." << endl;
	}
	ofstream outfile__array_neurongroup_10_not_refractory;
	outfile__array_neurongroup_10_not_refractory.open("results/_array_neurongroup_10_not_refractory_652447205", ios::binary | ios::out);
	if(outfile__array_neurongroup_10_not_refractory.is_open())
	{
		outfile__array_neurongroup_10_not_refractory.write(reinterpret_cast<char*>(_array_neurongroup_10_not_refractory), 400*sizeof(_array_neurongroup_10_not_refractory[0]));
		outfile__array_neurongroup_10_not_refractory.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_10_not_refractory." << endl;
	}
	ofstream outfile__array_neurongroup_10_phi;
	outfile__array_neurongroup_10_phi.open("results/_array_neurongroup_10_phi_1010026381", ios::binary | ios::out);
	if(outfile__array_neurongroup_10_phi.is_open())
	{
		outfile__array_neurongroup_10_phi.write(reinterpret_cast<char*>(_array_neurongroup_10_phi), 400*sizeof(_array_neurongroup_10_phi[0]));
		outfile__array_neurongroup_10_phi.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_10_phi." << endl;
	}
	ofstream outfile__array_neurongroup_10_V;
	outfile__array_neurongroup_10_V.open("results/_array_neurongroup_10_V_558711573", ios::binary | ios::out);
	if(outfile__array_neurongroup_10_V.is_open())
	{
		outfile__array_neurongroup_10_V.write(reinterpret_cast<char*>(_array_neurongroup_10_V), 400*sizeof(_array_neurongroup_10_V[0]));
		outfile__array_neurongroup_10_V.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_10_V." << endl;
	}
	ofstream outfile__array_neurongroup_11__spikespace;
	outfile__array_neurongroup_11__spikespace.open("results/_array_neurongroup_11__spikespace_2755324163", ios::binary | ios::out);
	if(outfile__array_neurongroup_11__spikespace.is_open())
	{
		outfile__array_neurongroup_11__spikespace.write(reinterpret_cast<char*>(_array_neurongroup_11__spikespace), 101*sizeof(_array_neurongroup_11__spikespace[0]));
		outfile__array_neurongroup_11__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_11__spikespace." << endl;
	}
	ofstream outfile__array_neurongroup_11_i;
	outfile__array_neurongroup_11_i.open("results/_array_neurongroup_11_i_2531853343", ios::binary | ios::out);
	if(outfile__array_neurongroup_11_i.is_open())
	{
		outfile__array_neurongroup_11_i.write(reinterpret_cast<char*>(_array_neurongroup_11_i), 100*sizeof(_array_neurongroup_11_i[0]));
		outfile__array_neurongroup_11_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_11_i." << endl;
	}
	ofstream outfile__array_neurongroup_11_lastspike;
	outfile__array_neurongroup_11_lastspike.open("results/_array_neurongroup_11_lastspike_1770311067", ios::binary | ios::out);
	if(outfile__array_neurongroup_11_lastspike.is_open())
	{
		outfile__array_neurongroup_11_lastspike.write(reinterpret_cast<char*>(_array_neurongroup_11_lastspike), 100*sizeof(_array_neurongroup_11_lastspike[0]));
		outfile__array_neurongroup_11_lastspike.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_11_lastspike." << endl;
	}
	ofstream outfile__array_neurongroup_11_not_refractory;
	outfile__array_neurongroup_11_not_refractory.open("results/_array_neurongroup_11_not_refractory_2290818164", ios::binary | ios::out);
	if(outfile__array_neurongroup_11_not_refractory.is_open())
	{
		outfile__array_neurongroup_11_not_refractory.write(reinterpret_cast<char*>(_array_neurongroup_11_not_refractory), 100*sizeof(_array_neurongroup_11_not_refractory[0]));
		outfile__array_neurongroup_11_not_refractory.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_11_not_refractory." << endl;
	}
	ofstream outfile__array_neurongroup_11_V;
	outfile__array_neurongroup_11_V.open("results/_array_neurongroup_11_V_546253090", ios::binary | ios::out);
	if(outfile__array_neurongroup_11_V.is_open())
	{
		outfile__array_neurongroup_11_V.write(reinterpret_cast<char*>(_array_neurongroup_11_V), 100*sizeof(_array_neurongroup_11_V[0]));
		outfile__array_neurongroup_11_V.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_11_V." << endl;
	}
	ofstream outfile__array_neurongroup_1__spikespace;
	outfile__array_neurongroup_1__spikespace.open("results/_array_neurongroup_1__spikespace_3155027917", ios::binary | ios::out);
	if(outfile__array_neurongroup_1__spikespace.is_open())
	{
		outfile__array_neurongroup_1__spikespace.write(reinterpret_cast<char*>(_array_neurongroup_1__spikespace), 101*sizeof(_array_neurongroup_1__spikespace[0]));
		outfile__array_neurongroup_1__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_1__spikespace." << endl;
	}
	ofstream outfile__array_neurongroup_1_i;
	outfile__array_neurongroup_1_i.open("results/_array_neurongroup_1_i_3674354357", ios::binary | ios::out);
	if(outfile__array_neurongroup_1_i.is_open())
	{
		outfile__array_neurongroup_1_i.write(reinterpret_cast<char*>(_array_neurongroup_1_i), 100*sizeof(_array_neurongroup_1_i[0]));
		outfile__array_neurongroup_1_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_1_i." << endl;
	}
	ofstream outfile__array_neurongroup_1_lastspike;
	outfile__array_neurongroup_1_lastspike.open("results/_array_neurongroup_1_lastspike_1163579662", ios::binary | ios::out);
	if(outfile__array_neurongroup_1_lastspike.is_open())
	{
		outfile__array_neurongroup_1_lastspike.write(reinterpret_cast<char*>(_array_neurongroup_1_lastspike), 100*sizeof(_array_neurongroup_1_lastspike[0]));
		outfile__array_neurongroup_1_lastspike.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_1_lastspike." << endl;
	}
	ofstream outfile__array_neurongroup_1_not_refractory;
	outfile__array_neurongroup_1_not_refractory.open("results/_array_neurongroup_1_not_refractory_897855399", ios::binary | ios::out);
	if(outfile__array_neurongroup_1_not_refractory.is_open())
	{
		outfile__array_neurongroup_1_not_refractory.write(reinterpret_cast<char*>(_array_neurongroup_1_not_refractory), 100*sizeof(_array_neurongroup_1_not_refractory[0]));
		outfile__array_neurongroup_1_not_refractory.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_1_not_refractory." << endl;
	}
	ofstream outfile__array_neurongroup_1_V;
	outfile__array_neurongroup_1_V.open("results/_array_neurongroup_1_V_1835278216", ios::binary | ios::out);
	if(outfile__array_neurongroup_1_V.is_open())
	{
		outfile__array_neurongroup_1_V.write(reinterpret_cast<char*>(_array_neurongroup_1_V), 100*sizeof(_array_neurongroup_1_V[0]));
		outfile__array_neurongroup_1_V.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_1_V." << endl;
	}
	ofstream outfile__array_neurongroup_2__spikespace;
	outfile__array_neurongroup_2__spikespace.open("results/_array_neurongroup_2__spikespace_29854467", ios::binary | ios::out);
	if(outfile__array_neurongroup_2__spikespace.is_open())
	{
		outfile__array_neurongroup_2__spikespace.write(reinterpret_cast<char*>(_array_neurongroup_2__spikespace), 401*sizeof(_array_neurongroup_2__spikespace[0]));
		outfile__array_neurongroup_2__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_2__spikespace." << endl;
	}
	ofstream outfile__array_neurongroup_2_a;
	outfile__array_neurongroup_2_a.open("results/_array_neurongroup_2_a_3617522910", ios::binary | ios::out);
	if(outfile__array_neurongroup_2_a.is_open())
	{
		outfile__array_neurongroup_2_a.write(reinterpret_cast<char*>(_array_neurongroup_2_a), 400*sizeof(_array_neurongroup_2_a[0]));
		outfile__array_neurongroup_2_a.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_2_a." << endl;
	}
	ofstream outfile__array_neurongroup_2_d;
	outfile__array_neurongroup_2_d.open("results/_array_neurongroup_2_d_2817912913", ios::binary | ios::out);
	if(outfile__array_neurongroup_2_d.is_open())
	{
		outfile__array_neurongroup_2_d.write(reinterpret_cast<char*>(_array_neurongroup_2_d), 400*sizeof(_array_neurongroup_2_d[0]));
		outfile__array_neurongroup_2_d.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_2_d." << endl;
	}
	ofstream outfile__array_neurongroup_2_i;
	outfile__array_neurongroup_2_i.open("results/_array_neurongroup_2_i_3645148396", ios::binary | ios::out);
	if(outfile__array_neurongroup_2_i.is_open())
	{
		outfile__array_neurongroup_2_i.write(reinterpret_cast<char*>(_array_neurongroup_2_i), 400*sizeof(_array_neurongroup_2_i[0]));
		outfile__array_neurongroup_2_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_2_i." << endl;
	}
	ofstream outfile__array_neurongroup_2_lastspike;
	outfile__array_neurongroup_2_lastspike.open("results/_array_neurongroup_2_lastspike_3703093007", ios::binary | ios::out);
	if(outfile__array_neurongroup_2_lastspike.is_open())
	{
		outfile__array_neurongroup_2_lastspike.write(reinterpret_cast<char*>(_array_neurongroup_2_lastspike), 400*sizeof(_array_neurongroup_2_lastspike[0]));
		outfile__array_neurongroup_2_lastspike.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_2_lastspike." << endl;
	}
	ofstream outfile__array_neurongroup_2_not_refractory;
	outfile__array_neurongroup_2_not_refractory.open("results/_array_neurongroup_2_not_refractory_474782549", ios::binary | ios::out);
	if(outfile__array_neurongroup_2_not_refractory.is_open())
	{
		outfile__array_neurongroup_2_not_refractory.write(reinterpret_cast<char*>(_array_neurongroup_2_not_refractory), 400*sizeof(_array_neurongroup_2_not_refractory[0]));
		outfile__array_neurongroup_2_not_refractory.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_2_not_refractory." << endl;
	}
	ofstream outfile__array_neurongroup_2_phi;
	outfile__array_neurongroup_2_phi.open("results/_array_neurongroup_2_phi_3718322428", ios::binary | ios::out);
	if(outfile__array_neurongroup_2_phi.is_open())
	{
		outfile__array_neurongroup_2_phi.write(reinterpret_cast<char*>(_array_neurongroup_2_phi), 400*sizeof(_array_neurongroup_2_phi[0]));
		outfile__array_neurongroup_2_phi.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_2_phi." << endl;
	}
	ofstream outfile__array_neurongroup_2_V;
	outfile__array_neurongroup_2_V.open("results/_array_neurongroup_2_V_1864540625", ios::binary | ios::out);
	if(outfile__array_neurongroup_2_V.is_open())
	{
		outfile__array_neurongroup_2_V.write(reinterpret_cast<char*>(_array_neurongroup_2_V), 400*sizeof(_array_neurongroup_2_V[0]));
		outfile__array_neurongroup_2_V.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_2_V." << endl;
	}
	ofstream outfile__array_neurongroup_3__spikespace;
	outfile__array_neurongroup_3__spikespace.open("results/_array_neurongroup_3__spikespace_3696317062", ios::binary | ios::out);
	if(outfile__array_neurongroup_3__spikespace.is_open())
	{
		outfile__array_neurongroup_3__spikespace.write(reinterpret_cast<char*>(_array_neurongroup_3__spikespace), 101*sizeof(_array_neurongroup_3__spikespace[0]));
		outfile__array_neurongroup_3__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_3__spikespace." << endl;
	}
	ofstream outfile__array_neurongroup_3_i;
	outfile__array_neurongroup_3_i.open("results/_array_neurongroup_3_i_3632719579", ios::binary | ios::out);
	if(outfile__array_neurongroup_3_i.is_open())
	{
		outfile__array_neurongroup_3_i.write(reinterpret_cast<char*>(_array_neurongroup_3_i), 100*sizeof(_array_neurongroup_3_i[0]));
		outfile__array_neurongroup_3_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_3_i." << endl;
	}
	ofstream outfile__array_neurongroup_3_lastspike;
	outfile__array_neurongroup_3_lastspike.open("results/_array_neurongroup_3_lastspike_490105039", ios::binary | ios::out);
	if(outfile__array_neurongroup_3_lastspike.is_open())
	{
		outfile__array_neurongroup_3_lastspike.write(reinterpret_cast<char*>(_array_neurongroup_3_lastspike), 100*sizeof(_array_neurongroup_3_lastspike[0]));
		outfile__array_neurongroup_3_lastspike.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_3_lastspike." << endl;
	}
	ofstream outfile__array_neurongroup_3_not_refractory;
	outfile__array_neurongroup_3_not_refractory.open("results/_array_neurongroup_3_not_refractory_2988706500", ios::binary | ios::out);
	if(outfile__array_neurongroup_3_not_refractory.is_open())
	{
		outfile__array_neurongroup_3_not_refractory.write(reinterpret_cast<char*>(_array_neurongroup_3_not_refractory), 100*sizeof(_array_neurongroup_3_not_refractory[0]));
		outfile__array_neurongroup_3_not_refractory.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_3_not_refractory." << endl;
	}
	ofstream outfile__array_neurongroup_3_V;
	outfile__array_neurongroup_3_V.open("results/_array_neurongroup_3_V_1860226022", ios::binary | ios::out);
	if(outfile__array_neurongroup_3_V.is_open())
	{
		outfile__array_neurongroup_3_V.write(reinterpret_cast<char*>(_array_neurongroup_3_V), 100*sizeof(_array_neurongroup_3_V[0]));
		outfile__array_neurongroup_3_V.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_3_V." << endl;
	}
	ofstream outfile__array_neurongroup_8__spikespace;
	outfile__array_neurongroup_8__spikespace.open("results/_array_neurongroup_8__spikespace_999877925", ios::binary | ios::out);
	if(outfile__array_neurongroup_8__spikespace.is_open())
	{
		outfile__array_neurongroup_8__spikespace.write(reinterpret_cast<char*>(_array_neurongroup_8__spikespace), 401*sizeof(_array_neurongroup_8__spikespace[0]));
		outfile__array_neurongroup_8__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_8__spikespace." << endl;
	}
	ofstream outfile__array_neurongroup_8_a;
	outfile__array_neurongroup_8_a.open("results/_array_neurongroup_8_a_3657990408", ios::binary | ios::out);
	if(outfile__array_neurongroup_8_a.is_open())
	{
		outfile__array_neurongroup_8_a.write(reinterpret_cast<char*>(_array_neurongroup_8_a), 400*sizeof(_array_neurongroup_8_a[0]));
		outfile__array_neurongroup_8_a.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_8_a." << endl;
	}
	ofstream outfile__array_neurongroup_8_d;
	outfile__array_neurongroup_8_d.open("results/_array_neurongroup_8_d_2858579335", ios::binary | ios::out);
	if(outfile__array_neurongroup_8_d.is_open())
	{
		outfile__array_neurongroup_8_d.write(reinterpret_cast<char*>(_array_neurongroup_8_d), 400*sizeof(_array_neurongroup_8_d[0]));
		outfile__array_neurongroup_8_d.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_8_d." << endl;
	}
	ofstream outfile__array_neurongroup_8_i;
	outfile__array_neurongroup_8_i.open("results/_array_neurongroup_8_i_3570600250", ios::binary | ios::out);
	if(outfile__array_neurongroup_8_i.is_open())
	{
		outfile__array_neurongroup_8_i.write(reinterpret_cast<char*>(_array_neurongroup_8_i), 400*sizeof(_array_neurongroup_8_i[0]));
		outfile__array_neurongroup_8_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_8_i." << endl;
	}
	ofstream outfile__array_neurongroup_8_lastspike;
	outfile__array_neurongroup_8_lastspike.open("results/_array_neurongroup_8_lastspike_1041756043", ios::binary | ios::out);
	if(outfile__array_neurongroup_8_lastspike.is_open())
	{
		outfile__array_neurongroup_8_lastspike.write(reinterpret_cast<char*>(_array_neurongroup_8_lastspike), 400*sizeof(_array_neurongroup_8_lastspike[0]));
		outfile__array_neurongroup_8_lastspike.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_8_lastspike." << endl;
	}
	ofstream outfile__array_neurongroup_8_not_refractory;
	outfile__array_neurongroup_8_not_refractory.open("results/_array_neurongroup_8_not_refractory_3909034361", ios::binary | ios::out);
	if(outfile__array_neurongroup_8_not_refractory.is_open())
	{
		outfile__array_neurongroup_8_not_refractory.write(reinterpret_cast<char*>(_array_neurongroup_8_not_refractory), 400*sizeof(_array_neurongroup_8_not_refractory[0]));
		outfile__array_neurongroup_8_not_refractory.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_8_not_refractory." << endl;
	}
	ofstream outfile__array_neurongroup_8_phi;
	outfile__array_neurongroup_8_phi.open("results/_array_neurongroup_8_phi_2534473821", ios::binary | ios::out);
	if(outfile__array_neurongroup_8_phi.is_open())
	{
		outfile__array_neurongroup_8_phi.write(reinterpret_cast<char*>(_array_neurongroup_8_phi), 400*sizeof(_array_neurongroup_8_phi[0]));
		outfile__array_neurongroup_8_phi.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_8_phi." << endl;
	}
	ofstream outfile__array_neurongroup_8_V;
	outfile__array_neurongroup_8_V.open("results/_array_neurongroup_8_V_1656038407", ios::binary | ios::out);
	if(outfile__array_neurongroup_8_V.is_open())
	{
		outfile__array_neurongroup_8_V.write(reinterpret_cast<char*>(_array_neurongroup_8_V), 400*sizeof(_array_neurongroup_8_V[0]));
		outfile__array_neurongroup_8_V.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_8_V." << endl;
	}
	ofstream outfile__array_neurongroup_9__spikespace;
	outfile__array_neurongroup_9__spikespace.open("results/_array_neurongroup_9__spikespace_3859690656", ios::binary | ios::out);
	if(outfile__array_neurongroup_9__spikespace.is_open())
	{
		outfile__array_neurongroup_9__spikespace.write(reinterpret_cast<char*>(_array_neurongroup_9__spikespace), 101*sizeof(_array_neurongroup_9__spikespace[0]));
		outfile__array_neurongroup_9__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_9__spikespace." << endl;
	}
	ofstream outfile__array_neurongroup_9_i;
	outfile__array_neurongroup_9_i.open("results/_array_neurongroup_9_i_3574686477", ios::binary | ios::out);
	if(outfile__array_neurongroup_9_i.is_open())
	{
		outfile__array_neurongroup_9_i.write(reinterpret_cast<char*>(_array_neurongroup_9_i), 100*sizeof(_array_neurongroup_9_i[0]));
		outfile__array_neurongroup_9_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_9_i." << endl;
	}
	ofstream outfile__array_neurongroup_9_lastspike;
	outfile__array_neurongroup_9_lastspike.open("results/_array_neurongroup_9_lastspike_4288229451", ios::binary | ios::out);
	if(outfile__array_neurongroup_9_lastspike.is_open())
	{
		outfile__array_neurongroup_9_lastspike.write(reinterpret_cast<char*>(_array_neurongroup_9_lastspike), 100*sizeof(_array_neurongroup_9_lastspike[0]));
		outfile__array_neurongroup_9_lastspike.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_9_lastspike." << endl;
	}
	ofstream outfile__array_neurongroup_9_not_refractory;
	outfile__array_neurongroup_9_not_refractory.open("results/_array_neurongroup_9_not_refractory_1184346344", ios::binary | ios::out);
	if(outfile__array_neurongroup_9_not_refractory.is_open())
	{
		outfile__array_neurongroup_9_not_refractory.write(reinterpret_cast<char*>(_array_neurongroup_9_not_refractory), 100*sizeof(_array_neurongroup_9_not_refractory[0]));
		outfile__array_neurongroup_9_not_refractory.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_9_not_refractory." << endl;
	}
	ofstream outfile__array_neurongroup_9_V;
	outfile__array_neurongroup_9_V.open("results/_array_neurongroup_9_V_1668763184", ios::binary | ios::out);
	if(outfile__array_neurongroup_9_V.is_open())
	{
		outfile__array_neurongroup_9_V.write(reinterpret_cast<char*>(_array_neurongroup_9_V), 100*sizeof(_array_neurongroup_9_V[0]));
		outfile__array_neurongroup_9_V.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_9_V." << endl;
	}
	ofstream outfile__array_neurongroup__spikespace;
	outfile__array_neurongroup__spikespace.open("results/_array_neurongroup__spikespace_3522821529", ios::binary | ios::out);
	if(outfile__array_neurongroup__spikespace.is_open())
	{
		outfile__array_neurongroup__spikespace.write(reinterpret_cast<char*>(_array_neurongroup__spikespace), 401*sizeof(_array_neurongroup__spikespace[0]));
		outfile__array_neurongroup__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup__spikespace." << endl;
	}
	ofstream outfile__array_neurongroup_a;
	outfile__array_neurongroup_a.open("results/_array_neurongroup_a_2470410674", ios::binary | ios::out);
	if(outfile__array_neurongroup_a.is_open())
	{
		outfile__array_neurongroup_a.write(reinterpret_cast<char*>(_array_neurongroup_a), 400*sizeof(_array_neurongroup_a[0]));
		outfile__array_neurongroup_a.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_a." << endl;
	}
	ofstream outfile__array_neurongroup_d;
	outfile__array_neurongroup_d.open("results/_array_neurongroup_d_3814034749", ios::binary | ios::out);
	if(outfile__array_neurongroup_d.is_open())
	{
		outfile__array_neurongroup_d.write(reinterpret_cast<char*>(_array_neurongroup_d), 400*sizeof(_array_neurongroup_d[0]));
		outfile__array_neurongroup_d.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_d." << endl;
	}
	ofstream outfile__array_neurongroup_i;
	outfile__array_neurongroup_i.open("results/_array_neurongroup_i_2649026944", ios::binary | ios::out);
	if(outfile__array_neurongroup_i.is_open())
	{
		outfile__array_neurongroup_i.write(reinterpret_cast<char*>(_array_neurongroup_i), 400*sizeof(_array_neurongroup_i[0]));
		outfile__array_neurongroup_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_i." << endl;
	}
	ofstream outfile__array_neurongroup_lastspike;
	outfile__array_neurongroup_lastspike.open("results/_array_neurongroup_lastspike_1647074423", ios::binary | ios::out);
	if(outfile__array_neurongroup_lastspike.is_open())
	{
		outfile__array_neurongroup_lastspike.write(reinterpret_cast<char*>(_array_neurongroup_lastspike), 400*sizeof(_array_neurongroup_lastspike[0]));
		outfile__array_neurongroup_lastspike.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_lastspike." << endl;
	}
	ofstream outfile__array_neurongroup_not_refractory;
	outfile__array_neurongroup_not_refractory.open("results/_array_neurongroup_not_refractory_1422681464", ios::binary | ios::out);
	if(outfile__array_neurongroup_not_refractory.is_open())
	{
		outfile__array_neurongroup_not_refractory.write(reinterpret_cast<char*>(_array_neurongroup_not_refractory), 400*sizeof(_array_neurongroup_not_refractory[0]));
		outfile__array_neurongroup_not_refractory.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_not_refractory." << endl;
	}
	ofstream outfile__array_neurongroup_phi;
	outfile__array_neurongroup_phi.open("results/_array_neurongroup_phi_979203446", ios::binary | ios::out);
	if(outfile__array_neurongroup_phi.is_open())
	{
		outfile__array_neurongroup_phi.write(reinterpret_cast<char*>(_array_neurongroup_phi), 400*sizeof(_array_neurongroup_phi[0]));
		outfile__array_neurongroup_phi.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_phi." << endl;
	}
	ofstream outfile__array_neurongroup_V;
	outfile__array_neurongroup_V.open("results/_array_neurongroup_V_729996477", ios::binary | ios::out);
	if(outfile__array_neurongroup_V.is_open())
	{
		outfile__array_neurongroup_V.write(reinterpret_cast<char*>(_array_neurongroup_V), 400*sizeof(_array_neurongroup_V[0]));
		outfile__array_neurongroup_V.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_V." << endl;
	}
	ofstream outfile__array_spikemonitor_10__source_idx;
	outfile__array_spikemonitor_10__source_idx.open("results/_array_spikemonitor_10__source_idx_3415040676", ios::binary | ios::out);
	if(outfile__array_spikemonitor_10__source_idx.is_open())
	{
		outfile__array_spikemonitor_10__source_idx.write(reinterpret_cast<char*>(_array_spikemonitor_10__source_idx), 100*sizeof(_array_spikemonitor_10__source_idx[0]));
		outfile__array_spikemonitor_10__source_idx.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_10__source_idx." << endl;
	}
	ofstream outfile__array_spikemonitor_10_count;
	outfile__array_spikemonitor_10_count.open("results/_array_spikemonitor_10_count_2076851952", ios::binary | ios::out);
	if(outfile__array_spikemonitor_10_count.is_open())
	{
		outfile__array_spikemonitor_10_count.write(reinterpret_cast<char*>(_array_spikemonitor_10_count), 100*sizeof(_array_spikemonitor_10_count[0]));
		outfile__array_spikemonitor_10_count.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_10_count." << endl;
	}
	ofstream outfile__array_spikemonitor_10_N;
	outfile__array_spikemonitor_10_N.open("results/_array_spikemonitor_10_N_755706081", ios::binary | ios::out);
	if(outfile__array_spikemonitor_10_N.is_open())
	{
		outfile__array_spikemonitor_10_N.write(reinterpret_cast<char*>(_array_spikemonitor_10_N), 1*sizeof(_array_spikemonitor_10_N[0]));
		outfile__array_spikemonitor_10_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_10_N." << endl;
	}
	ofstream outfile__array_spikemonitor_11__source_idx;
	outfile__array_spikemonitor_11__source_idx.open("results/_array_spikemonitor_11__source_idx_370916129", ios::binary | ios::out);
	if(outfile__array_spikemonitor_11__source_idx.is_open())
	{
		outfile__array_spikemonitor_11__source_idx.write(reinterpret_cast<char*>(_array_spikemonitor_11__source_idx), 400*sizeof(_array_spikemonitor_11__source_idx[0]));
		outfile__array_spikemonitor_11__source_idx.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_11__source_idx." << endl;
	}
	ofstream outfile__array_spikemonitor_11_count;
	outfile__array_spikemonitor_11_count.open("results/_array_spikemonitor_11_count_3720164676", ios::binary | ios::out);
	if(outfile__array_spikemonitor_11_count.is_open())
	{
		outfile__array_spikemonitor_11_count.write(reinterpret_cast<char*>(_array_spikemonitor_11_count), 400*sizeof(_array_spikemonitor_11_count[0]));
		outfile__array_spikemonitor_11_count.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_11_count." << endl;
	}
	ofstream outfile__array_spikemonitor_11_N;
	outfile__array_spikemonitor_11_N.open("results/_array_spikemonitor_11_N_751387350", ios::binary | ios::out);
	if(outfile__array_spikemonitor_11_N.is_open())
	{
		outfile__array_spikemonitor_11_N.write(reinterpret_cast<char*>(_array_spikemonitor_11_N), 1*sizeof(_array_spikemonitor_11_N[0]));
		outfile__array_spikemonitor_11_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_11_N." << endl;
	}
	ofstream outfile__array_spikemonitor_2__source_idx;
	outfile__array_spikemonitor_2__source_idx.open("results/_array_spikemonitor_2__source_idx_1793786228", ios::binary | ios::out);
	if(outfile__array_spikemonitor_2__source_idx.is_open())
	{
		outfile__array_spikemonitor_2__source_idx.write(reinterpret_cast<char*>(_array_spikemonitor_2__source_idx), 100*sizeof(_array_spikemonitor_2__source_idx[0]));
		outfile__array_spikemonitor_2__source_idx.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_2__source_idx." << endl;
	}
	ofstream outfile__array_spikemonitor_2_count;
	outfile__array_spikemonitor_2_count.open("results/_array_spikemonitor_2_count_3621222387", ios::binary | ios::out);
	if(outfile__array_spikemonitor_2_count.is_open())
	{
		outfile__array_spikemonitor_2_count.write(reinterpret_cast<char*>(_array_spikemonitor_2_count), 100*sizeof(_array_spikemonitor_2_count[0]));
		outfile__array_spikemonitor_2_count.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_2_count." << endl;
	}
	ofstream outfile__array_spikemonitor_2_N;
	outfile__array_spikemonitor_2_N.open("results/_array_spikemonitor_2_N_2352936276", ios::binary | ios::out);
	if(outfile__array_spikemonitor_2_N.is_open())
	{
		outfile__array_spikemonitor_2_N.write(reinterpret_cast<char*>(_array_spikemonitor_2_N), 1*sizeof(_array_spikemonitor_2_N[0]));
		outfile__array_spikemonitor_2_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_2_N." << endl;
	}
	ofstream outfile__array_spikemonitor_3__source_idx;
	outfile__array_spikemonitor_3__source_idx.open("results/_array_spikemonitor_3__source_idx_3078478065", ios::binary | ios::out);
	if(outfile__array_spikemonitor_3__source_idx.is_open())
	{
		outfile__array_spikemonitor_3__source_idx.write(reinterpret_cast<char*>(_array_spikemonitor_3__source_idx), 400*sizeof(_array_spikemonitor_3__source_idx[0]));
		outfile__array_spikemonitor_3__source_idx.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_3__source_idx." << endl;
	}
	ofstream outfile__array_spikemonitor_3_count;
	outfile__array_spikemonitor_3_count.open("results/_array_spikemonitor_3_count_1906342983", ios::binary | ios::out);
	if(outfile__array_spikemonitor_3_count.is_open())
	{
		outfile__array_spikemonitor_3_count.write(reinterpret_cast<char*>(_array_spikemonitor_3_count), 400*sizeof(_array_spikemonitor_3_count[0]));
		outfile__array_spikemonitor_3_count.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_3_count." << endl;
	}
	ofstream outfile__array_spikemonitor_3_N;
	outfile__array_spikemonitor_3_N.open("results/_array_spikemonitor_3_N_2382143331", ios::binary | ios::out);
	if(outfile__array_spikemonitor_3_N.is_open())
	{
		outfile__array_spikemonitor_3_N.write(reinterpret_cast<char*>(_array_spikemonitor_3_N), 1*sizeof(_array_spikemonitor_3_N[0]));
		outfile__array_spikemonitor_3_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_3_N." << endl;
	}
	ofstream outfile__array_spikemonitor_6__source_idx;
	outfile__array_spikemonitor_6__source_idx.open("results/_array_spikemonitor_6__source_idx_2857528290", ios::binary | ios::out);
	if(outfile__array_spikemonitor_6__source_idx.is_open())
	{
		outfile__array_spikemonitor_6__source_idx.write(reinterpret_cast<char*>(_array_spikemonitor_6__source_idx), 100*sizeof(_array_spikemonitor_6__source_idx[0]));
		outfile__array_spikemonitor_6__source_idx.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_6__source_idx." << endl;
	}
	ofstream outfile__array_spikemonitor_6_count;
	outfile__array_spikemonitor_6_count.open("results/_array_spikemonitor_6_count_597185504", ios::binary | ios::out);
	if(outfile__array_spikemonitor_6_count.is_open())
	{
		outfile__array_spikemonitor_6_count.write(reinterpret_cast<char*>(_array_spikemonitor_6_count), 100*sizeof(_array_spikemonitor_6_count[0]));
		outfile__array_spikemonitor_6_count.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_6_count." << endl;
	}
	ofstream outfile__array_spikemonitor_6_N;
	outfile__array_spikemonitor_6_N.open("results/_array_spikemonitor_6_N_2335661448", ios::binary | ios::out);
	if(outfile__array_spikemonitor_6_N.is_open())
	{
		outfile__array_spikemonitor_6_N.write(reinterpret_cast<char*>(_array_spikemonitor_6_N), 1*sizeof(_array_spikemonitor_6_N[0]));
		outfile__array_spikemonitor_6_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_6_N." << endl;
	}
	ofstream outfile__array_spikemonitor_7__source_idx;
	outfile__array_spikemonitor_7__source_idx.open("results/_array_spikemonitor_7__source_idx_2009379431", ios::binary | ios::out);
	if(outfile__array_spikemonitor_7__source_idx.is_open())
	{
		outfile__array_spikemonitor_7__source_idx.write(reinterpret_cast<char*>(_array_spikemonitor_7__source_idx), 400*sizeof(_array_spikemonitor_7__source_idx[0]));
		outfile__array_spikemonitor_7__source_idx.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_7__source_idx." << endl;
	}
	ofstream outfile__array_spikemonitor_7_count;
	outfile__array_spikemonitor_7_count.open("results/_array_spikemonitor_7_count_2247055444", ios::binary | ios::out);
	if(outfile__array_spikemonitor_7_count.is_open())
	{
		outfile__array_spikemonitor_7_count.write(reinterpret_cast<char*>(_array_spikemonitor_7_count), 400*sizeof(_array_spikemonitor_7_count[0]));
		outfile__array_spikemonitor_7_count.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_7_count." << endl;
	}
	ofstream outfile__array_spikemonitor_7_N;
	outfile__array_spikemonitor_7_N.open("results/_array_spikemonitor_7_N_2331326399", ios::binary | ios::out);
	if(outfile__array_spikemonitor_7_N.is_open())
	{
		outfile__array_spikemonitor_7_N.write(reinterpret_cast<char*>(_array_spikemonitor_7_N), 1*sizeof(_array_spikemonitor_7_N[0]));
		outfile__array_spikemonitor_7_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_7_N." << endl;
	}
	ofstream outfile__array_spikemonitor_8__source_idx;
	outfile__array_spikemonitor_8__source_idx.open("results/_array_spikemonitor_8__source_idx_1354000210", ios::binary | ios::out);
	if(outfile__array_spikemonitor_8__source_idx.is_open())
	{
		outfile__array_spikemonitor_8__source_idx.write(reinterpret_cast<char*>(_array_spikemonitor_8__source_idx), 100*sizeof(_array_spikemonitor_8__source_idx[0]));
		outfile__array_spikemonitor_8__source_idx.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_8__source_idx." << endl;
	}
	ofstream outfile__array_spikemonitor_8_count;
	outfile__array_spikemonitor_8_count.open("results/_array_spikemonitor_8_count_1940334781", ios::binary | ios::out);
	if(outfile__array_spikemonitor_8_count.is_open())
	{
		outfile__array_spikemonitor_8_count.write(reinterpret_cast<char*>(_array_spikemonitor_8_count), 100*sizeof(_array_spikemonitor_8_count[0]));
		outfile__array_spikemonitor_8_count.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_8_count." << endl;
	}
	ofstream outfile__array_spikemonitor_8_N;
	outfile__array_spikemonitor_8_N.open("results/_array_spikemonitor_8_N_2175365250", ios::binary | ios::out);
	if(outfile__array_spikemonitor_8_N.is_open())
	{
		outfile__array_spikemonitor_8_N.write(reinterpret_cast<char*>(_array_spikemonitor_8_N), 1*sizeof(_array_spikemonitor_8_N[0]));
		outfile__array_spikemonitor_8_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_8_N." << endl;
	}
	ofstream outfile__array_spikemonitor_9__source_idx;
	outfile__array_spikemonitor_9__source_idx.open("results/_array_spikemonitor_9__source_idx_2367864535", ios::binary | ios::out);
	if(outfile__array_spikemonitor_9__source_idx.is_open())
	{
		outfile__array_spikemonitor_9__source_idx.write(reinterpret_cast<char*>(_array_spikemonitor_9__source_idx), 400*sizeof(_array_spikemonitor_9__source_idx[0]));
		outfile__array_spikemonitor_9__source_idx.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_9__source_idx." << endl;
	}
	ofstream outfile__array_spikemonitor_9_count;
	outfile__array_spikemonitor_9_count.open("results/_array_spikemonitor_9_count_3587187465", ios::binary | ios::out);
	if(outfile__array_spikemonitor_9_count.is_open())
	{
		outfile__array_spikemonitor_9_count.write(reinterpret_cast<char*>(_array_spikemonitor_9_count), 400*sizeof(_array_spikemonitor_9_count[0]));
		outfile__array_spikemonitor_9_count.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_9_count." << endl;
	}
	ofstream outfile__array_spikemonitor_9_N;
	outfile__array_spikemonitor_9_N.open("results/_array_spikemonitor_9_N_2154502837", ios::binary | ios::out);
	if(outfile__array_spikemonitor_9_N.is_open())
	{
		outfile__array_spikemonitor_9_N.write(reinterpret_cast<char*>(_array_spikemonitor_9_N), 1*sizeof(_array_spikemonitor_9_N[0]));
		outfile__array_spikemonitor_9_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_9_N." << endl;
	}
	ofstream outfile__array_statemonitor_1__indices;
	outfile__array_statemonitor_1__indices.open("results/_array_statemonitor_1__indices_2504039125", ios::binary | ios::out);
	if(outfile__array_statemonitor_1__indices.is_open())
	{
		outfile__array_statemonitor_1__indices.write(reinterpret_cast<char*>(_array_statemonitor_1__indices), 400*sizeof(_array_statemonitor_1__indices[0]));
		outfile__array_statemonitor_1__indices.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_1__indices." << endl;
	}
	ofstream outfile__array_statemonitor_1_N;
	outfile__array_statemonitor_1_N.open("results/_array_statemonitor_1_N_2754233271", ios::binary | ios::out);
	if(outfile__array_statemonitor_1_N.is_open())
	{
		outfile__array_statemonitor_1_N.write(reinterpret_cast<char*>(_array_statemonitor_1_N), 1*sizeof(_array_statemonitor_1_N[0]));
		outfile__array_statemonitor_1_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_1_N." << endl;
	}
	ofstream outfile__array_statemonitor_3__indices;
	outfile__array_statemonitor_3__indices.open("results/_array_statemonitor_3__indices_2444577512", ios::binary | ios::out);
	if(outfile__array_statemonitor_3__indices.is_open())
	{
		outfile__array_statemonitor_3__indices.write(reinterpret_cast<char*>(_array_statemonitor_3__indices), 400*sizeof(_array_statemonitor_3__indices[0]));
		outfile__array_statemonitor_3__indices.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_3__indices." << endl;
	}
	ofstream outfile__array_statemonitor_3_N;
	outfile__array_statemonitor_3_N.open("results/_array_statemonitor_3_N_2813237209", ios::binary | ios::out);
	if(outfile__array_statemonitor_3_N.is_open())
	{
		outfile__array_statemonitor_3_N.write(reinterpret_cast<char*>(_array_statemonitor_3_N), 1*sizeof(_array_statemonitor_3_N[0]));
		outfile__array_statemonitor_3_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_3_N." << endl;
	}
	ofstream outfile__array_statemonitor_4__indices;
	outfile__array_statemonitor_4__indices.open("results/_array_statemonitor_4__indices_1936282001", ios::binary | ios::out);
	if(outfile__array_statemonitor_4__indices.is_open())
	{
		outfile__array_statemonitor_4__indices.write(reinterpret_cast<char*>(_array_statemonitor_4__indices), 400*sizeof(_array_statemonitor_4__indices[0]));
		outfile__array_statemonitor_4__indices.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_4__indices." << endl;
	}
	ofstream outfile__array_statemonitor_4_N;
	outfile__array_statemonitor_4_N.open("results/_array_statemonitor_4_N_2732687708", ios::binary | ios::out);
	if(outfile__array_statemonitor_4_N.is_open())
	{
		outfile__array_statemonitor_4_N.write(reinterpret_cast<char*>(_array_statemonitor_4_N), 1*sizeof(_array_statemonitor_4_N[0]));
		outfile__array_statemonitor_4_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_4_N." << endl;
	}
	ofstream outfile__array_statemonitor_5__indices;
	outfile__array_statemonitor_5__indices.open("results/_array_statemonitor_5__indices_2628467375", ios::binary | ios::out);
	if(outfile__array_statemonitor_5__indices.is_open())
	{
		outfile__array_statemonitor_5__indices.write(reinterpret_cast<char*>(_array_statemonitor_5__indices), 400*sizeof(_array_statemonitor_5__indices[0]));
		outfile__array_statemonitor_5__indices.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_5__indices." << endl;
	}
	ofstream outfile__array_statemonitor_5_N;
	outfile__array_statemonitor_5_N.open("results/_array_statemonitor_5_N_2737040235", ios::binary | ios::out);
	if(outfile__array_statemonitor_5_N.is_open())
	{
		outfile__array_statemonitor_5_N.write(reinterpret_cast<char*>(_array_statemonitor_5_N), 1*sizeof(_array_statemonitor_5_N[0]));
		outfile__array_statemonitor_5_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_statemonitor_5_N." << endl;
	}
	ofstream outfile__array_synapses_13_N;
	outfile__array_synapses_13_N.open("results/_array_synapses_13_N_2350281973", ios::binary | ios::out);
	if(outfile__array_synapses_13_N.is_open())
	{
		outfile__array_synapses_13_N.write(reinterpret_cast<char*>(_array_synapses_13_N), 1*sizeof(_array_synapses_13_N[0]));
		outfile__array_synapses_13_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_13_N." << endl;
	}
	ofstream outfile__array_synapses_14_N;
	outfile__array_synapses_14_N.open("results/_array_synapses_14_N_2304336496", ios::binary | ios::out);
	if(outfile__array_synapses_14_N.is_open())
	{
		outfile__array_synapses_14_N.write(reinterpret_cast<char*>(_array_synapses_14_N), 1*sizeof(_array_synapses_14_N[0]));
		outfile__array_synapses_14_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_14_N." << endl;
	}
	ofstream outfile__array_synapses_15_N;
	outfile__array_synapses_15_N.open("results/_array_synapses_15_N_2291861575", ios::binary | ios::out);
	if(outfile__array_synapses_15_N.is_open())
	{
		outfile__array_synapses_15_N.write(reinterpret_cast<char*>(_array_synapses_15_N), 1*sizeof(_array_synapses_15_N[0]));
		outfile__array_synapses_15_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_15_N." << endl;
	}
	ofstream outfile__array_synapses_16_N;
	outfile__array_synapses_16_N.open("results/_array_synapses_16_N_2329785886", ios::binary | ios::out);
	if(outfile__array_synapses_16_N.is_open())
	{
		outfile__array_synapses_16_N.write(reinterpret_cast<char*>(_array_synapses_16_N), 1*sizeof(_array_synapses_16_N[0]));
		outfile__array_synapses_16_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_16_N." << endl;
	}
	ofstream outfile__array_synapses_17_N;
	outfile__array_synapses_17_N.open("results/_array_synapses_17_N_2334121001", ios::binary | ios::out);
	if(outfile__array_synapses_17_N.is_open())
	{
		outfile__array_synapses_17_N.write(reinterpret_cast<char*>(_array_synapses_17_N), 1*sizeof(_array_synapses_17_N[0]));
		outfile__array_synapses_17_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_17_N." << endl;
	}
	ofstream outfile__array_synapses_18_N;
	outfile__array_synapses_18_N.open("results/_array_synapses_18_N_2151914260", ios::binary | ios::out);
	if(outfile__array_synapses_18_N.is_open())
	{
		outfile__array_synapses_18_N.write(reinterpret_cast<char*>(_array_synapses_18_N), 1*sizeof(_array_synapses_18_N[0]));
		outfile__array_synapses_18_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_18_N." << endl;
	}
	ofstream outfile__array_synapses_19_N;
	outfile__array_synapses_19_N.open("results/_array_synapses_19_N_2172776739", ios::binary | ios::out);
	if(outfile__array_synapses_19_N.is_open())
	{
		outfile__array_synapses_19_N.write(reinterpret_cast<char*>(_array_synapses_19_N), 1*sizeof(_array_synapses_19_N[0]));
		outfile__array_synapses_19_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_19_N." << endl;
	}
	ofstream outfile__array_synapses_20_N;
	outfile__array_synapses_20_N.open("results/_array_synapses_20_N_2632279362", ios::binary | ios::out);
	if(outfile__array_synapses_20_N.is_open())
	{
		outfile__array_synapses_20_N.write(reinterpret_cast<char*>(_array_synapses_20_N), 1*sizeof(_array_synapses_20_N[0]));
		outfile__array_synapses_20_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_20_N." << endl;
	}
	ofstream outfile__array_synapses_21_N;
	outfile__array_synapses_21_N.open("results/_array_synapses_21_N_2636582773", ios::binary | ios::out);
	if(outfile__array_synapses_21_N.is_open())
	{
		outfile__array_synapses_21_N.write(reinterpret_cast<char*>(_array_synapses_21_N), 1*sizeof(_array_synapses_21_N[0]));
		outfile__array_synapses_21_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_21_N." << endl;
	}
	ofstream outfile__array_synapses_22_N;
	outfile__array_synapses_22_N.open("results/_array_synapses_22_N_2673979692", ios::binary | ios::out);
	if(outfile__array_synapses_22_N.is_open())
	{
		outfile__array_synapses_22_N.write(reinterpret_cast<char*>(_array_synapses_22_N), 1*sizeof(_array_synapses_22_N[0]));
		outfile__array_synapses_22_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_22_N." << endl;
	}
	ofstream outfile__array_synapses_23_N;
	outfile__array_synapses_23_N.open("results/_array_synapses_23_N_2661538587", ios::binary | ios::out);
	if(outfile__array_synapses_23_N.is_open())
	{
		outfile__array_synapses_23_N.write(reinterpret_cast<char*>(_array_synapses_23_N), 1*sizeof(_array_synapses_23_N[0]));
		outfile__array_synapses_23_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_23_N." << endl;
	}
	ofstream outfile__array_synapses_3_N;
	outfile__array_synapses_3_N.open("results/_array_synapses_3_N_1780393473", ios::binary | ios::out);
	if(outfile__array_synapses_3_N.is_open())
	{
		outfile__array_synapses_3_N.write(reinterpret_cast<char*>(_array_synapses_3_N), 1*sizeof(_array_synapses_3_N[0]));
		outfile__array_synapses_3_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_3_N." << endl;
	}
	ofstream outfile__array_synapses_4_N;
	outfile__array_synapses_4_N.open("results/_array_synapses_4_N_1867624580", ios::binary | ios::out);
	if(outfile__array_synapses_4_N.is_open())
	{
		outfile__array_synapses_4_N.write(reinterpret_cast<char*>(_array_synapses_4_N), 1*sizeof(_array_synapses_4_N[0]));
		outfile__array_synapses_4_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_4_N." << endl;
	}
	ofstream outfile__array_synapses_5_N;
	outfile__array_synapses_5_N.open("results/_array_synapses_5_N_1855183539", ios::binary | ios::out);
	if(outfile__array_synapses_5_N.is_open())
	{
		outfile__array_synapses_5_N.write(reinterpret_cast<char*>(_array_synapses_5_N), 1*sizeof(_array_synapses_5_N[0]));
		outfile__array_synapses_5_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_5_N." << endl;
	}
	ofstream outfile__array_synapses_6_N;
	outfile__array_synapses_6_N.open("results/_array_synapses_6_N_1825924330", ios::binary | ios::out);
	if(outfile__array_synapses_6_N.is_open())
	{
		outfile__array_synapses_6_N.write(reinterpret_cast<char*>(_array_synapses_6_N), 1*sizeof(_array_synapses_6_N[0]));
		outfile__array_synapses_6_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_6_N." << endl;
	}
	ofstream outfile__array_synapses_7_N;
	outfile__array_synapses_7_N.open("results/_array_synapses_7_N_1830227677", ios::binary | ios::out);
	if(outfile__array_synapses_7_N.is_open())
	{
		outfile__array_synapses_7_N.write(reinterpret_cast<char*>(_array_synapses_7_N), 1*sizeof(_array_synapses_7_N[0]));
		outfile__array_synapses_7_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_synapses_7_N." << endl;
	}

	ofstream outfile__dynamic_array_spikemonitor_10_i;
	outfile__dynamic_array_spikemonitor_10_i.open("results/_dynamic_array_spikemonitor_10_i_1859548046", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_10_i.is_open())
	{
        if (! _dynamic_array_spikemonitor_10_i.empty() )
        {
			outfile__dynamic_array_spikemonitor_10_i.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_10_i[0]), _dynamic_array_spikemonitor_10_i.size()*sizeof(_dynamic_array_spikemonitor_10_i[0]));
		    outfile__dynamic_array_spikemonitor_10_i.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_10_i." << endl;
	}
	ofstream outfile__dynamic_array_spikemonitor_10_t;
	outfile__dynamic_array_spikemonitor_10_t.open("results/_dynamic_array_spikemonitor_10_t_231743319", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_10_t.is_open())
	{
        if (! _dynamic_array_spikemonitor_10_t.empty() )
        {
			outfile__dynamic_array_spikemonitor_10_t.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_10_t[0]), _dynamic_array_spikemonitor_10_t.size()*sizeof(_dynamic_array_spikemonitor_10_t[0]));
		    outfile__dynamic_array_spikemonitor_10_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_10_t." << endl;
	}
	ofstream outfile__dynamic_array_spikemonitor_11_i;
	outfile__dynamic_array_spikemonitor_11_i.open("results/_dynamic_array_spikemonitor_11_i_1863588281", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_11_i.is_open())
	{
        if (! _dynamic_array_spikemonitor_11_i.empty() )
        {
			outfile__dynamic_array_spikemonitor_11_i.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_11_i[0]), _dynamic_array_spikemonitor_11_i.size()*sizeof(_dynamic_array_spikemonitor_11_i[0]));
		    outfile__dynamic_array_spikemonitor_11_i.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_11_i." << endl;
	}
	ofstream outfile__dynamic_array_spikemonitor_11_t;
	outfile__dynamic_array_spikemonitor_11_t.open("results/_dynamic_array_spikemonitor_11_t_202536288", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_11_t.is_open())
	{
        if (! _dynamic_array_spikemonitor_11_t.empty() )
        {
			outfile__dynamic_array_spikemonitor_11_t.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_11_t[0]), _dynamic_array_spikemonitor_11_t.size()*sizeof(_dynamic_array_spikemonitor_11_t[0]));
		    outfile__dynamic_array_spikemonitor_11_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_11_t." << endl;
	}
	ofstream outfile__dynamic_array_spikemonitor_2_i;
	outfile__dynamic_array_spikemonitor_2_i.open("results/_dynamic_array_spikemonitor_2_i_2642822512", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_2_i.is_open())
	{
        if (! _dynamic_array_spikemonitor_2_i.empty() )
        {
			outfile__dynamic_array_spikemonitor_2_i.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_2_i[0]), _dynamic_array_spikemonitor_2_i.size()*sizeof(_dynamic_array_spikemonitor_2_i[0]));
		    outfile__dynamic_array_spikemonitor_2_i.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_2_i." << endl;
	}
	ofstream outfile__dynamic_array_spikemonitor_2_t;
	outfile__dynamic_array_spikemonitor_2_t.open("results/_dynamic_array_spikemonitor_2_t_4269812137", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_2_t.is_open())
	{
        if (! _dynamic_array_spikemonitor_2_t.empty() )
        {
			outfile__dynamic_array_spikemonitor_2_t.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_2_t[0]), _dynamic_array_spikemonitor_2_t.size()*sizeof(_dynamic_array_spikemonitor_2_t[0]));
		    outfile__dynamic_array_spikemonitor_2_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_2_t." << endl;
	}
	ofstream outfile__dynamic_array_spikemonitor_3_i;
	outfile__dynamic_array_spikemonitor_3_i.open("results/_dynamic_array_spikemonitor_3_i_2621714247", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_3_i.is_open())
	{
        if (! _dynamic_array_spikemonitor_3_i.empty() )
        {
			outfile__dynamic_array_spikemonitor_3_i.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_3_i[0]), _dynamic_array_spikemonitor_3_i.size()*sizeof(_dynamic_array_spikemonitor_3_i[0]));
		    outfile__dynamic_array_spikemonitor_3_i.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_3_i." << endl;
	}
	ofstream outfile__dynamic_array_spikemonitor_3_t;
	outfile__dynamic_array_spikemonitor_3_t.open("results/_dynamic_array_spikemonitor_3_t_4282532766", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_3_t.is_open())
	{
        if (! _dynamic_array_spikemonitor_3_t.empty() )
        {
			outfile__dynamic_array_spikemonitor_3_t.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_3_t[0]), _dynamic_array_spikemonitor_3_t.size()*sizeof(_dynamic_array_spikemonitor_3_t[0]));
		    outfile__dynamic_array_spikemonitor_3_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_3_t." << endl;
	}
	ofstream outfile__dynamic_array_spikemonitor_6_i;
	outfile__dynamic_array_spikemonitor_6_i.open("results/_dynamic_array_spikemonitor_6_i_2593123756", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_6_i.is_open())
	{
        if (! _dynamic_array_spikemonitor_6_i.empty() )
        {
			outfile__dynamic_array_spikemonitor_6_i.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_6_i[0]), _dynamic_array_spikemonitor_6_i.size()*sizeof(_dynamic_array_spikemonitor_6_i[0]));
		    outfile__dynamic_array_spikemonitor_6_i.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_6_i." << endl;
	}
	ofstream outfile__dynamic_array_spikemonitor_6_t;
	outfile__dynamic_array_spikemonitor_6_t.open("results/_dynamic_array_spikemonitor_6_t_4186538357", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_6_t.is_open())
	{
        if (! _dynamic_array_spikemonitor_6_t.empty() )
        {
			outfile__dynamic_array_spikemonitor_6_t.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_6_t[0]), _dynamic_array_spikemonitor_6_t.size()*sizeof(_dynamic_array_spikemonitor_6_t[0]));
		    outfile__dynamic_array_spikemonitor_6_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_6_t." << endl;
	}
	ofstream outfile__dynamic_array_spikemonitor_7_i;
	outfile__dynamic_array_spikemonitor_7_i.open("results/_dynamic_array_spikemonitor_7_i_2605549467", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_7_i.is_open())
	{
        if (! _dynamic_array_spikemonitor_7_i.empty() )
        {
			outfile__dynamic_array_spikemonitor_7_i.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_7_i[0]), _dynamic_array_spikemonitor_7_i.size()*sizeof(_dynamic_array_spikemonitor_7_i[0]));
		    outfile__dynamic_array_spikemonitor_7_i.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_7_i." << endl;
	}
	ofstream outfile__dynamic_array_spikemonitor_7_t;
	outfile__dynamic_array_spikemonitor_7_t.open("results/_dynamic_array_spikemonitor_7_t_4165724994", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_7_t.is_open())
	{
        if (! _dynamic_array_spikemonitor_7_t.empty() )
        {
			outfile__dynamic_array_spikemonitor_7_t.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_7_t[0]), _dynamic_array_spikemonitor_7_t.size()*sizeof(_dynamic_array_spikemonitor_7_t[0]));
		    outfile__dynamic_array_spikemonitor_7_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_7_t." << endl;
	}
	ofstream outfile__dynamic_array_spikemonitor_8_i;
	outfile__dynamic_array_spikemonitor_8_i.open("results/_dynamic_array_spikemonitor_8_i_2417082534", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_8_i.is_open())
	{
        if (! _dynamic_array_spikemonitor_8_i.empty() )
        {
			outfile__dynamic_array_spikemonitor_8_i.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_8_i[0]), _dynamic_array_spikemonitor_8_i.size()*sizeof(_dynamic_array_spikemonitor_8_i[0]));
		    outfile__dynamic_array_spikemonitor_8_i.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_8_i." << endl;
	}
	ofstream outfile__dynamic_array_spikemonitor_8_t;
	outfile__dynamic_array_spikemonitor_8_t.open("results/_dynamic_array_spikemonitor_8_t_4078414975", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_8_t.is_open())
	{
        if (! _dynamic_array_spikemonitor_8_t.empty() )
        {
			outfile__dynamic_array_spikemonitor_8_t.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_8_t[0]), _dynamic_array_spikemonitor_8_t.size()*sizeof(_dynamic_array_spikemonitor_8_t[0]));
		    outfile__dynamic_array_spikemonitor_8_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_8_t." << endl;
	}
	ofstream outfile__dynamic_array_spikemonitor_9_i;
	outfile__dynamic_array_spikemonitor_9_i.open("results/_dynamic_array_spikemonitor_9_i_2446568081", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_9_i.is_open())
	{
        if (! _dynamic_array_spikemonitor_9_i.empty() )
        {
			outfile__dynamic_array_spikemonitor_9_i.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_9_i[0]), _dynamic_array_spikemonitor_9_i.size()*sizeof(_dynamic_array_spikemonitor_9_i[0]));
		    outfile__dynamic_array_spikemonitor_9_i.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_9_i." << endl;
	}
	ofstream outfile__dynamic_array_spikemonitor_9_t;
	outfile__dynamic_array_spikemonitor_9_t.open("results/_dynamic_array_spikemonitor_9_t_4074096200", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_9_t.is_open())
	{
        if (! _dynamic_array_spikemonitor_9_t.empty() )
        {
			outfile__dynamic_array_spikemonitor_9_t.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_9_t[0]), _dynamic_array_spikemonitor_9_t.size()*sizeof(_dynamic_array_spikemonitor_9_t[0]));
		    outfile__dynamic_array_spikemonitor_9_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_9_t." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_1_t;
	outfile__dynamic_array_statemonitor_1_t.open("results/_dynamic_array_statemonitor_1_t_3600064330", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_1_t.is_open())
	{
        if (! _dynamic_array_statemonitor_1_t.empty() )
        {
			outfile__dynamic_array_statemonitor_1_t.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_1_t[0]), _dynamic_array_statemonitor_1_t.size()*sizeof(_dynamic_array_statemonitor_1_t[0]));
		    outfile__dynamic_array_statemonitor_1_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_1_t." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_3_t;
	outfile__dynamic_array_statemonitor_3_t.open("results/_dynamic_array_statemonitor_3_t_3574614820", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_3_t.is_open())
	{
        if (! _dynamic_array_statemonitor_3_t.empty() )
        {
			outfile__dynamic_array_statemonitor_3_t.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_3_t[0]), _dynamic_array_statemonitor_3_t.size()*sizeof(_dynamic_array_statemonitor_3_t[0]));
		    outfile__dynamic_array_statemonitor_3_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_3_t." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_4_t;
	outfile__dynamic_array_statemonitor_4_t.open("results/_dynamic_array_statemonitor_4_t_3495910817", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_4_t.is_open())
	{
        if (! _dynamic_array_statemonitor_4_t.empty() )
        {
			outfile__dynamic_array_statemonitor_4_t.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_4_t[0]), _dynamic_array_statemonitor_4_t.size()*sizeof(_dynamic_array_statemonitor_4_t[0]));
		    outfile__dynamic_array_statemonitor_4_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_4_t." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_5_t;
	outfile__dynamic_array_statemonitor_5_t.open("results/_dynamic_array_statemonitor_5_t_3516741526", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_5_t.is_open())
	{
        if (! _dynamic_array_statemonitor_5_t.empty() )
        {
			outfile__dynamic_array_statemonitor_5_t.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_5_t[0]), _dynamic_array_statemonitor_5_t.size()*sizeof(_dynamic_array_statemonitor_5_t[0]));
		    outfile__dynamic_array_statemonitor_5_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_5_t." << endl;
	}
	ofstream outfile__dynamic_array_synapses_13__synaptic_post;
	outfile__dynamic_array_synapses_13__synaptic_post.open("results/_dynamic_array_synapses_13__synaptic_post_10564918", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_13__synaptic_post.is_open())
	{
        if (! _dynamic_array_synapses_13__synaptic_post.empty() )
        {
			outfile__dynamic_array_synapses_13__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_synapses_13__synaptic_post[0]), _dynamic_array_synapses_13__synaptic_post.size()*sizeof(_dynamic_array_synapses_13__synaptic_post[0]));
		    outfile__dynamic_array_synapses_13__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_13__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_synapses_13__synaptic_pre;
	outfile__dynamic_array_synapses_13__synaptic_pre.open("results/_dynamic_array_synapses_13__synaptic_pre_2783420191", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_13__synaptic_pre.is_open())
	{
        if (! _dynamic_array_synapses_13__synaptic_pre.empty() )
        {
			outfile__dynamic_array_synapses_13__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_synapses_13__synaptic_pre[0]), _dynamic_array_synapses_13__synaptic_pre.size()*sizeof(_dynamic_array_synapses_13__synaptic_pre[0]));
		    outfile__dynamic_array_synapses_13__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_13__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_synapses_13_delay;
	outfile__dynamic_array_synapses_13_delay.open("results/_dynamic_array_synapses_13_delay_1312750707", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_13_delay.is_open())
	{
        if (! _dynamic_array_synapses_13_delay.empty() )
        {
			outfile__dynamic_array_synapses_13_delay.write(reinterpret_cast<char*>(&_dynamic_array_synapses_13_delay[0]), _dynamic_array_synapses_13_delay.size()*sizeof(_dynamic_array_synapses_13_delay[0]));
		    outfile__dynamic_array_synapses_13_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_13_delay." << endl;
	}
	ofstream outfile__dynamic_array_synapses_13_N_incoming;
	outfile__dynamic_array_synapses_13_N_incoming.open("results/_dynamic_array_synapses_13_N_incoming_3068814614", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_13_N_incoming.is_open())
	{
        if (! _dynamic_array_synapses_13_N_incoming.empty() )
        {
			outfile__dynamic_array_synapses_13_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_synapses_13_N_incoming[0]), _dynamic_array_synapses_13_N_incoming.size()*sizeof(_dynamic_array_synapses_13_N_incoming[0]));
		    outfile__dynamic_array_synapses_13_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_13_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_synapses_13_N_outgoing;
	outfile__dynamic_array_synapses_13_N_outgoing.open("results/_dynamic_array_synapses_13_N_outgoing_2448823756", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_13_N_outgoing.is_open())
	{
        if (! _dynamic_array_synapses_13_N_outgoing.empty() )
        {
			outfile__dynamic_array_synapses_13_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_synapses_13_N_outgoing[0]), _dynamic_array_synapses_13_N_outgoing.size()*sizeof(_dynamic_array_synapses_13_N_outgoing[0]));
		    outfile__dynamic_array_synapses_13_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_13_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_synapses_14__synaptic_post;
	outfile__dynamic_array_synapses_14__synaptic_post.open("results/_dynamic_array_synapses_14__synaptic_post_4250455363", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_14__synaptic_post.is_open())
	{
        if (! _dynamic_array_synapses_14__synaptic_post.empty() )
        {
			outfile__dynamic_array_synapses_14__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_synapses_14__synaptic_post[0]), _dynamic_array_synapses_14__synaptic_post.size()*sizeof(_dynamic_array_synapses_14__synaptic_post[0]));
		    outfile__dynamic_array_synapses_14__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_14__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_synapses_14__synaptic_pre;
	outfile__dynamic_array_synapses_14__synaptic_pre.open("results/_dynamic_array_synapses_14__synaptic_pre_1055297541", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_14__synaptic_pre.is_open())
	{
        if (! _dynamic_array_synapses_14__synaptic_pre.empty() )
        {
			outfile__dynamic_array_synapses_14__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_synapses_14__synaptic_pre[0]), _dynamic_array_synapses_14__synaptic_pre.size()*sizeof(_dynamic_array_synapses_14__synaptic_pre[0]));
		    outfile__dynamic_array_synapses_14__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_14__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_synapses_14_delay;
	outfile__dynamic_array_synapses_14_delay.open("results/_dynamic_array_synapses_14_delay_2342109949", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_14_delay.is_open())
	{
        if (! _dynamic_array_synapses_14_delay.empty() )
        {
			outfile__dynamic_array_synapses_14_delay.write(reinterpret_cast<char*>(&_dynamic_array_synapses_14_delay[0]), _dynamic_array_synapses_14_delay.size()*sizeof(_dynamic_array_synapses_14_delay[0]));
		    outfile__dynamic_array_synapses_14_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_14_delay." << endl;
	}
	ofstream outfile__dynamic_array_synapses_14_N_incoming;
	outfile__dynamic_array_synapses_14_N_incoming.open("results/_dynamic_array_synapses_14_N_incoming_3262287001", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_14_N_incoming.is_open())
	{
        if (! _dynamic_array_synapses_14_N_incoming.empty() )
        {
			outfile__dynamic_array_synapses_14_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_synapses_14_N_incoming[0]), _dynamic_array_synapses_14_N_incoming.size()*sizeof(_dynamic_array_synapses_14_N_incoming[0]));
		    outfile__dynamic_array_synapses_14_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_14_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_synapses_14_N_outgoing;
	outfile__dynamic_array_synapses_14_N_outgoing.open("results/_dynamic_array_synapses_14_N_outgoing_3849256003", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_14_N_outgoing.is_open())
	{
        if (! _dynamic_array_synapses_14_N_outgoing.empty() )
        {
			outfile__dynamic_array_synapses_14_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_synapses_14_N_outgoing[0]), _dynamic_array_synapses_14_N_outgoing.size()*sizeof(_dynamic_array_synapses_14_N_outgoing[0]));
		    outfile__dynamic_array_synapses_14_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_14_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_synapses_15__synaptic_post;
	outfile__dynamic_array_synapses_15__synaptic_post.open("results/_dynamic_array_synapses_15__synaptic_post_1395678418", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_15__synaptic_post.is_open())
	{
        if (! _dynamic_array_synapses_15__synaptic_post.empty() )
        {
			outfile__dynamic_array_synapses_15__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_synapses_15__synaptic_post[0]), _dynamic_array_synapses_15__synaptic_post.size()*sizeof(_dynamic_array_synapses_15__synaptic_post[0]));
		    outfile__dynamic_array_synapses_15__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_15__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_synapses_15__synaptic_pre;
	outfile__dynamic_array_synapses_15__synaptic_pre.open("results/_dynamic_array_synapses_15__synaptic_pre_2266844141", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_15__synaptic_pre.is_open())
	{
        if (! _dynamic_array_synapses_15__synaptic_pre.empty() )
        {
			outfile__dynamic_array_synapses_15__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_synapses_15__synaptic_pre[0]), _dynamic_array_synapses_15__synaptic_pre.size()*sizeof(_dynamic_array_synapses_15__synaptic_pre[0]));
		    outfile__dynamic_array_synapses_15__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_15__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_synapses_15_c;
	outfile__dynamic_array_synapses_15_c.open("results/_dynamic_array_synapses_15_c_1825434461", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_15_c.is_open())
	{
        if (! _dynamic_array_synapses_15_c.empty() )
        {
			outfile__dynamic_array_synapses_15_c.write(reinterpret_cast<char*>(&_dynamic_array_synapses_15_c[0]), _dynamic_array_synapses_15_c.size()*sizeof(_dynamic_array_synapses_15_c[0]));
		    outfile__dynamic_array_synapses_15_c.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_15_c." << endl;
	}
	ofstream outfile__dynamic_array_synapses_15_delay;
	outfile__dynamic_array_synapses_15_delay.open("results/_dynamic_array_synapses_15_delay_770623817", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_15_delay.is_open())
	{
        if (! _dynamic_array_synapses_15_delay.empty() )
        {
			outfile__dynamic_array_synapses_15_delay.write(reinterpret_cast<char*>(&_dynamic_array_synapses_15_delay[0]), _dynamic_array_synapses_15_delay.size()*sizeof(_dynamic_array_synapses_15_delay[0]));
		    outfile__dynamic_array_synapses_15_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_15_delay." << endl;
	}
	ofstream outfile__dynamic_array_synapses_15_N_incoming;
	outfile__dynamic_array_synapses_15_N_incoming.open("results/_dynamic_array_synapses_15_N_incoming_1507311862", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_15_N_incoming.is_open())
	{
        if (! _dynamic_array_synapses_15_N_incoming.empty() )
        {
			outfile__dynamic_array_synapses_15_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_synapses_15_N_incoming[0]), _dynamic_array_synapses_15_N_incoming.size()*sizeof(_dynamic_array_synapses_15_N_incoming[0]));
		    outfile__dynamic_array_synapses_15_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_15_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_synapses_15_N_outgoing;
	outfile__dynamic_array_synapses_15_N_outgoing.open("results/_dynamic_array_synapses_15_N_outgoing_2127278124", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_15_N_outgoing.is_open())
	{
        if (! _dynamic_array_synapses_15_N_outgoing.empty() )
        {
			outfile__dynamic_array_synapses_15_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_synapses_15_N_outgoing[0]), _dynamic_array_synapses_15_N_outgoing.size()*sizeof(_dynamic_array_synapses_15_N_outgoing[0]));
		    outfile__dynamic_array_synapses_15_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_15_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_synapses_16__synaptic_post;
	outfile__dynamic_array_synapses_16__synaptic_post.open("results/_dynamic_array_synapses_16__synaptic_post_2063132704", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_16__synaptic_post.is_open())
	{
        if (! _dynamic_array_synapses_16__synaptic_post.empty() )
        {
			outfile__dynamic_array_synapses_16__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_synapses_16__synaptic_post[0]), _dynamic_array_synapses_16__synaptic_post.size()*sizeof(_dynamic_array_synapses_16__synaptic_post[0]));
		    outfile__dynamic_array_synapses_16__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_16__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_synapses_16__synaptic_pre;
	outfile__dynamic_array_synapses_16__synaptic_pre.open("results/_dynamic_array_synapses_16__synaptic_pre_2522882452", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_16__synaptic_pre.is_open())
	{
        if (! _dynamic_array_synapses_16__synaptic_pre.empty() )
        {
			outfile__dynamic_array_synapses_16__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_synapses_16__synaptic_pre[0]), _dynamic_array_synapses_16__synaptic_pre.size()*sizeof(_dynamic_array_synapses_16__synaptic_pre[0]));
		    outfile__dynamic_array_synapses_16__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_16__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_synapses_16_delay;
	outfile__dynamic_array_synapses_16_delay.open("results/_dynamic_array_synapses_16_delay_470209492", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_16_delay.is_open())
	{
        if (! _dynamic_array_synapses_16_delay.empty() )
        {
			outfile__dynamic_array_synapses_16_delay.write(reinterpret_cast<char*>(&_dynamic_array_synapses_16_delay[0]), _dynamic_array_synapses_16_delay.size()*sizeof(_dynamic_array_synapses_16_delay[0]));
		    outfile__dynamic_array_synapses_16_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_16_delay." << endl;
	}
	ofstream outfile__dynamic_array_synapses_16_N_incoming;
	outfile__dynamic_array_synapses_16_N_incoming.open("results/_dynamic_array_synapses_16_N_incoming_776540678", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_16_N_incoming.is_open())
	{
        if (! _dynamic_array_synapses_16_N_incoming.empty() )
        {
			outfile__dynamic_array_synapses_16_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_synapses_16_N_incoming[0]), _dynamic_array_synapses_16_N_incoming.size()*sizeof(_dynamic_array_synapses_16_N_incoming[0]));
		    outfile__dynamic_array_synapses_16_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_16_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_synapses_16_N_outgoing;
	outfile__dynamic_array_synapses_16_N_outgoing.open("results/_dynamic_array_synapses_16_N_outgoing_156590812", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_16_N_outgoing.is_open())
	{
        if (! _dynamic_array_synapses_16_N_outgoing.empty() )
        {
			outfile__dynamic_array_synapses_16_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_synapses_16_N_outgoing[0]), _dynamic_array_synapses_16_N_outgoing.size()*sizeof(_dynamic_array_synapses_16_N_outgoing[0]));
		    outfile__dynamic_array_synapses_16_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_16_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_synapses_17__synaptic_post;
	outfile__dynamic_array_synapses_17__synaptic_post.open("results/_dynamic_array_synapses_17__synaptic_post_3566238129", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_17__synaptic_post.is_open())
	{
        if (! _dynamic_array_synapses_17__synaptic_post.empty() )
        {
			outfile__dynamic_array_synapses_17__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_synapses_17__synaptic_post[0]), _dynamic_array_synapses_17__synaptic_post.size()*sizeof(_dynamic_array_synapses_17__synaptic_post[0]));
		    outfile__dynamic_array_synapses_17__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_17__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_synapses_17__synaptic_pre;
	outfile__dynamic_array_synapses_17__synaptic_pre.open("results/_dynamic_array_synapses_17__synaptic_pre_798751356", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_17__synaptic_pre.is_open())
	{
        if (! _dynamic_array_synapses_17__synaptic_pre.empty() )
        {
			outfile__dynamic_array_synapses_17__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_synapses_17__synaptic_pre[0]), _dynamic_array_synapses_17__synaptic_pre.size()*sizeof(_dynamic_array_synapses_17__synaptic_pre[0]));
		    outfile__dynamic_array_synapses_17__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_17__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_synapses_17_delay;
	outfile__dynamic_array_synapses_17_delay.open("results/_dynamic_array_synapses_17_delay_3128023136", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_17_delay.is_open())
	{
        if (! _dynamic_array_synapses_17_delay.empty() )
        {
			outfile__dynamic_array_synapses_17_delay.write(reinterpret_cast<char*>(&_dynamic_array_synapses_17_delay[0]), _dynamic_array_synapses_17_delay.size()*sizeof(_dynamic_array_synapses_17_delay[0]));
		    outfile__dynamic_array_synapses_17_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_17_delay." << endl;
	}
	ofstream outfile__dynamic_array_synapses_17_N_incoming;
	outfile__dynamic_array_synapses_17_N_incoming.open("results/_dynamic_array_synapses_17_N_incoming_3052166761", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_17_N_incoming.is_open())
	{
        if (! _dynamic_array_synapses_17_N_incoming.empty() )
        {
			outfile__dynamic_array_synapses_17_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_synapses_17_N_incoming[0]), _dynamic_array_synapses_17_N_incoming.size()*sizeof(_dynamic_array_synapses_17_N_incoming[0]));
		    outfile__dynamic_array_synapses_17_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_17_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_synapses_17_N_outgoing;
	outfile__dynamic_array_synapses_17_N_outgoing.open("results/_dynamic_array_synapses_17_N_outgoing_2465214131", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_17_N_outgoing.is_open())
	{
        if (! _dynamic_array_synapses_17_N_outgoing.empty() )
        {
			outfile__dynamic_array_synapses_17_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_synapses_17_N_outgoing[0]), _dynamic_array_synapses_17_N_outgoing.size()*sizeof(_dynamic_array_synapses_17_N_outgoing[0]));
		    outfile__dynamic_array_synapses_17_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_17_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_synapses_18__synaptic_post;
	outfile__dynamic_array_synapses_18__synaptic_post.open("results/_dynamic_array_synapses_18__synaptic_post_1517952651", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_18__synaptic_post.is_open())
	{
        if (! _dynamic_array_synapses_18__synaptic_post.empty() )
        {
			outfile__dynamic_array_synapses_18__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_synapses_18__synaptic_post[0]), _dynamic_array_synapses_18__synaptic_post.size()*sizeof(_dynamic_array_synapses_18__synaptic_post[0]));
		    outfile__dynamic_array_synapses_18__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_18__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_synapses_18__synaptic_pre;
	outfile__dynamic_array_synapses_18__synaptic_pre.open("results/_dynamic_array_synapses_18__synaptic_pre_2064857569", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_18__synaptic_pre.is_open())
	{
        if (! _dynamic_array_synapses_18__synaptic_pre.empty() )
        {
			outfile__dynamic_array_synapses_18__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_synapses_18__synaptic_pre[0]), _dynamic_array_synapses_18__synaptic_pre.size()*sizeof(_dynamic_array_synapses_18__synaptic_pre[0]));
		    outfile__dynamic_array_synapses_18__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_18__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_synapses_18_delay;
	outfile__dynamic_array_synapses_18_delay.open("results/_dynamic_array_synapses_18_delay_1278847113", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_18_delay.is_open())
	{
        if (! _dynamic_array_synapses_18_delay.empty() )
        {
			outfile__dynamic_array_synapses_18_delay.write(reinterpret_cast<char*>(&_dynamic_array_synapses_18_delay[0]), _dynamic_array_synapses_18_delay.size()*sizeof(_dynamic_array_synapses_18_delay[0]));
		    outfile__dynamic_array_synapses_18_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_18_delay." << endl;
	}
	ofstream outfile__dynamic_array_synapses_18_N_incoming;
	outfile__dynamic_array_synapses_18_N_incoming.open("results/_dynamic_array_synapses_18_N_incoming_3346579736", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_18_N_incoming.is_open())
	{
        if (! _dynamic_array_synapses_18_N_incoming.empty() )
        {
			outfile__dynamic_array_synapses_18_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_synapses_18_N_incoming[0]), _dynamic_array_synapses_18_N_incoming.size()*sizeof(_dynamic_array_synapses_18_N_incoming[0]));
		    outfile__dynamic_array_synapses_18_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_18_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_synapses_18_N_outgoing;
	outfile__dynamic_array_synapses_18_N_outgoing.open("results/_dynamic_array_synapses_18_N_outgoing_3764695490", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_18_N_outgoing.is_open())
	{
        if (! _dynamic_array_synapses_18_N_outgoing.empty() )
        {
			outfile__dynamic_array_synapses_18_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_synapses_18_N_outgoing[0]), _dynamic_array_synapses_18_N_outgoing.size()*sizeof(_dynamic_array_synapses_18_N_outgoing[0]));
		    outfile__dynamic_array_synapses_18_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_18_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_synapses_19__synaptic_post;
	outfile__dynamic_array_synapses_19__synaptic_post.open("results/_dynamic_array_synapses_19__synaptic_post_4094856986", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_19__synaptic_post.is_open())
	{
        if (! _dynamic_array_synapses_19__synaptic_post.empty() )
        {
			outfile__dynamic_array_synapses_19__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_synapses_19__synaptic_post[0]), _dynamic_array_synapses_19__synaptic_post.size()*sizeof(_dynamic_array_synapses_19__synaptic_post[0]));
		    outfile__dynamic_array_synapses_19__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_19__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_synapses_19__synaptic_pre;
	outfile__dynamic_array_synapses_19__synaptic_pre.open("results/_dynamic_array_synapses_19__synaptic_pre_3270042121", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_19__synaptic_pre.is_open())
	{
        if (! _dynamic_array_synapses_19__synaptic_pre.empty() )
        {
			outfile__dynamic_array_synapses_19__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_synapses_19__synaptic_pre[0]), _dynamic_array_synapses_19__synaptic_pre.size()*sizeof(_dynamic_array_synapses_19__synaptic_pre[0]));
		    outfile__dynamic_array_synapses_19__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_19__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_synapses_19_c;
	outfile__dynamic_array_synapses_19_c.open("results/_dynamic_array_synapses_19_c_1708593721", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_19_c.is_open())
	{
        if (! _dynamic_array_synapses_19_c.empty() )
        {
			outfile__dynamic_array_synapses_19_c.write(reinterpret_cast<char*>(&_dynamic_array_synapses_19_c[0]), _dynamic_array_synapses_19_c.size()*sizeof(_dynamic_array_synapses_19_c[0]));
		    outfile__dynamic_array_synapses_19_c.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_19_c." << endl;
	}
	ofstream outfile__dynamic_array_synapses_19_delay;
	outfile__dynamic_array_synapses_19_delay.open("results/_dynamic_array_synapses_19_delay_3931022141", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_19_delay.is_open())
	{
        if (! _dynamic_array_synapses_19_delay.empty() )
        {
			outfile__dynamic_array_synapses_19_delay.write(reinterpret_cast<char*>(&_dynamic_array_synapses_19_delay[0]), _dynamic_array_synapses_19_delay.size()*sizeof(_dynamic_array_synapses_19_delay[0]));
		    outfile__dynamic_array_synapses_19_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_19_delay." << endl;
	}
	ofstream outfile__dynamic_array_synapses_19_N_incoming;
	outfile__dynamic_array_synapses_19_N_incoming.open("results/_dynamic_array_synapses_19_N_incoming_1558023543", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_19_N_incoming.is_open())
	{
        if (! _dynamic_array_synapses_19_N_incoming.empty() )
        {
			outfile__dynamic_array_synapses_19_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_synapses_19_N_incoming[0]), _dynamic_array_synapses_19_N_incoming.size()*sizeof(_dynamic_array_synapses_19_N_incoming[0]));
		    outfile__dynamic_array_synapses_19_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_19_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_synapses_19_N_outgoing;
	outfile__dynamic_array_synapses_19_N_outgoing.open("results/_dynamic_array_synapses_19_N_outgoing_2076310957", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_19_N_outgoing.is_open())
	{
        if (! _dynamic_array_synapses_19_N_outgoing.empty() )
        {
			outfile__dynamic_array_synapses_19_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_synapses_19_N_outgoing[0]), _dynamic_array_synapses_19_N_outgoing.size()*sizeof(_dynamic_array_synapses_19_N_outgoing[0]));
		    outfile__dynamic_array_synapses_19_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_19_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_synapses_20__synaptic_post;
	outfile__dynamic_array_synapses_20__synaptic_post.open("results/_dynamic_array_synapses_20__synaptic_post_2062801472", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_20__synaptic_post.is_open())
	{
        if (! _dynamic_array_synapses_20__synaptic_post.empty() )
        {
			outfile__dynamic_array_synapses_20__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_synapses_20__synaptic_post[0]), _dynamic_array_synapses_20__synaptic_post.size()*sizeof(_dynamic_array_synapses_20__synaptic_post[0]));
		    outfile__dynamic_array_synapses_20__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_20__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_synapses_20__synaptic_pre;
	outfile__dynamic_array_synapses_20__synaptic_pre.open("results/_dynamic_array_synapses_20__synaptic_pre_2639413652", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_20__synaptic_pre.is_open())
	{
        if (! _dynamic_array_synapses_20__synaptic_pre.empty() )
        {
			outfile__dynamic_array_synapses_20__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_synapses_20__synaptic_pre[0]), _dynamic_array_synapses_20__synaptic_pre.size()*sizeof(_dynamic_array_synapses_20__synaptic_pre[0]));
		    outfile__dynamic_array_synapses_20__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_20__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_synapses_20_delay;
	outfile__dynamic_array_synapses_20_delay.open("results/_dynamic_array_synapses_20_delay_4049199373", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_20_delay.is_open())
	{
        if (! _dynamic_array_synapses_20_delay.empty() )
        {
			outfile__dynamic_array_synapses_20_delay.write(reinterpret_cast<char*>(&_dynamic_array_synapses_20_delay[0]), _dynamic_array_synapses_20_delay.size()*sizeof(_dynamic_array_synapses_20_delay[0]));
		    outfile__dynamic_array_synapses_20_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_20_delay." << endl;
	}
	ofstream outfile__dynamic_array_synapses_20_N_incoming;
	outfile__dynamic_array_synapses_20_N_incoming.open("results/_dynamic_array_synapses_20_N_incoming_2092882728", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_20_N_incoming.is_open())
	{
        if (! _dynamic_array_synapses_20_N_incoming.empty() )
        {
			outfile__dynamic_array_synapses_20_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_synapses_20_N_incoming[0]), _dynamic_array_synapses_20_N_incoming.size()*sizeof(_dynamic_array_synapses_20_N_incoming[0]));
		    outfile__dynamic_array_synapses_20_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_20_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_synapses_20_N_outgoing;
	outfile__dynamic_array_synapses_20_N_outgoing.open("results/_dynamic_array_synapses_20_N_outgoing_1537387506", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_20_N_outgoing.is_open())
	{
        if (! _dynamic_array_synapses_20_N_outgoing.empty() )
        {
			outfile__dynamic_array_synapses_20_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_synapses_20_N_outgoing[0]), _dynamic_array_synapses_20_N_outgoing.size()*sizeof(_dynamic_array_synapses_20_N_outgoing[0]));
		    outfile__dynamic_array_synapses_20_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_20_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_synapses_21__synaptic_post;
	outfile__dynamic_array_synapses_21__synaptic_post.open("results/_dynamic_array_synapses_21__synaptic_post_3566947281", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_21__synaptic_post.is_open())
	{
        if (! _dynamic_array_synapses_21__synaptic_post.empty() )
        {
			outfile__dynamic_array_synapses_21__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_synapses_21__synaptic_post[0]), _dynamic_array_synapses_21__synaptic_post.size()*sizeof(_dynamic_array_synapses_21__synaptic_post[0]));
		    outfile__dynamic_array_synapses_21__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_21__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_synapses_21__synaptic_pre;
	outfile__dynamic_array_synapses_21__synaptic_pre.open("results/_dynamic_array_synapses_21__synaptic_pre_615094908", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_21__synaptic_pre.is_open())
	{
        if (! _dynamic_array_synapses_21__synaptic_pre.empty() )
        {
			outfile__dynamic_array_synapses_21__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_synapses_21__synaptic_pre[0]), _dynamic_array_synapses_21__synaptic_pre.size()*sizeof(_dynamic_array_synapses_21__synaptic_pre[0]));
		    outfile__dynamic_array_synapses_21__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_21__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_synapses_21_delay;
	outfile__dynamic_array_synapses_21_delay.open("results/_dynamic_array_synapses_21_delay_1462692537", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_21_delay.is_open())
	{
        if (! _dynamic_array_synapses_21_delay.empty() )
        {
			outfile__dynamic_array_synapses_21_delay.write(reinterpret_cast<char*>(&_dynamic_array_synapses_21_delay[0]), _dynamic_array_synapses_21_delay.size()*sizeof(_dynamic_array_synapses_21_delay[0]));
		    outfile__dynamic_array_synapses_21_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_21_delay." << endl;
	}
	ofstream outfile__dynamic_array_synapses_21_N_incoming;
	outfile__dynamic_array_synapses_21_N_incoming.open("results/_dynamic_array_synapses_21_N_incoming_3877345095", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_21_N_incoming.is_open())
	{
        if (! _dynamic_array_synapses_21_N_incoming.empty() )
        {
			outfile__dynamic_array_synapses_21_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_synapses_21_N_incoming[0]), _dynamic_array_synapses_21_N_incoming.size()*sizeof(_dynamic_array_synapses_21_N_incoming[0]));
		    outfile__dynamic_array_synapses_21_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_21_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_synapses_21_N_outgoing;
	outfile__dynamic_array_synapses_21_N_outgoing.open("results/_dynamic_array_synapses_21_N_outgoing_3221743517", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_21_N_outgoing.is_open())
	{
        if (! _dynamic_array_synapses_21_N_outgoing.empty() )
        {
			outfile__dynamic_array_synapses_21_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_synapses_21_N_outgoing[0]), _dynamic_array_synapses_21_N_outgoing.size()*sizeof(_dynamic_array_synapses_21_N_outgoing[0]));
		    outfile__dynamic_array_synapses_21_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_21_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_synapses_22__synaptic_post;
	outfile__dynamic_array_synapses_22__synaptic_post.open("results/_dynamic_array_synapses_22__synaptic_post_4250140451", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_22__synaptic_post.is_open())
	{
        if (! _dynamic_array_synapses_22__synaptic_post.empty() )
        {
			outfile__dynamic_array_synapses_22__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_synapses_22__synaptic_post[0]), _dynamic_array_synapses_22__synaptic_post.size()*sizeof(_dynamic_array_synapses_22__synaptic_post[0]));
		    outfile__dynamic_array_synapses_22__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_22__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_synapses_22__synaptic_pre;
	outfile__dynamic_array_synapses_22__synaptic_pre.open("results/_dynamic_array_synapses_22__synaptic_pre_903147525", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_22__synaptic_pre.is_open())
	{
        if (! _dynamic_array_synapses_22__synaptic_pre.empty() )
        {
			outfile__dynamic_array_synapses_22__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_synapses_22__synaptic_pre[0]), _dynamic_array_synapses_22__synaptic_pre.size()*sizeof(_dynamic_array_synapses_22__synaptic_pre[0]));
		    outfile__dynamic_array_synapses_22__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_22__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_synapses_22_delay;
	outfile__dynamic_array_synapses_22_delay.open("results/_dynamic_array_synapses_22_delay_1724313636", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_22_delay.is_open())
	{
        if (! _dynamic_array_synapses_22_delay.empty() )
        {
			outfile__dynamic_array_synapses_22_delay.write(reinterpret_cast<char*>(&_dynamic_array_synapses_22_delay[0]), _dynamic_array_synapses_22_delay.size()*sizeof(_dynamic_array_synapses_22_delay[0]));
		    outfile__dynamic_array_synapses_22_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_22_delay." << endl;
	}
	ofstream outfile__dynamic_array_synapses_22_N_incoming;
	outfile__dynamic_array_synapses_22_N_incoming.open("results/_dynamic_array_synapses_22_N_incoming_2424653239", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_22_N_incoming.is_open())
	{
        if (! _dynamic_array_synapses_22_N_incoming.empty() )
        {
			outfile__dynamic_array_synapses_22_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_synapses_22_N_incoming[0]), _dynamic_array_synapses_22_N_incoming.size()*sizeof(_dynamic_array_synapses_22_N_incoming[0]));
		    outfile__dynamic_array_synapses_22_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_22_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_synapses_22_N_outgoing;
	outfile__dynamic_array_synapses_22_N_outgoing.open("results/_dynamic_array_synapses_22_N_outgoing_3080271213", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_22_N_outgoing.is_open())
	{
        if (! _dynamic_array_synapses_22_N_outgoing.empty() )
        {
			outfile__dynamic_array_synapses_22_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_synapses_22_N_outgoing[0]), _dynamic_array_synapses_22_N_outgoing.size()*sizeof(_dynamic_array_synapses_22_N_outgoing[0]));
		    outfile__dynamic_array_synapses_22_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_22_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_synapses_23__synaptic_post;
	outfile__dynamic_array_synapses_23__synaptic_post.open("results/_dynamic_array_synapses_23__synaptic_post_1396403890", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_23__synaptic_post.is_open())
	{
        if (! _dynamic_array_synapses_23__synaptic_post.empty() )
        {
			outfile__dynamic_array_synapses_23__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_synapses_23__synaptic_post[0]), _dynamic_array_synapses_23__synaptic_post.size()*sizeof(_dynamic_array_synapses_23__synaptic_post[0]));
		    outfile__dynamic_array_synapses_23__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_23__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_synapses_23__synaptic_pre;
	outfile__dynamic_array_synapses_23__synaptic_pre.open("results/_dynamic_array_synapses_23__synaptic_pre_2351901677", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_23__synaptic_pre.is_open())
	{
        if (! _dynamic_array_synapses_23__synaptic_pre.empty() )
        {
			outfile__dynamic_array_synapses_23__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_synapses_23__synaptic_pre[0]), _dynamic_array_synapses_23__synaptic_pre.size()*sizeof(_dynamic_array_synapses_23__synaptic_pre[0]));
		    outfile__dynamic_array_synapses_23__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_23__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_synapses_23_c;
	outfile__dynamic_array_synapses_23_c.open("results/_dynamic_array_synapses_23_c_2062891009", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_23_c.is_open())
	{
        if (! _dynamic_array_synapses_23_c.empty() )
        {
			outfile__dynamic_array_synapses_23_c.write(reinterpret_cast<char*>(&_dynamic_array_synapses_23_c[0]), _dynamic_array_synapses_23_c.size()*sizeof(_dynamic_array_synapses_23_c[0]));
		    outfile__dynamic_array_synapses_23_c.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_23_c." << endl;
	}
	ofstream outfile__dynamic_array_synapses_23_delay;
	outfile__dynamic_array_synapses_23_delay.open("results/_dynamic_array_synapses_23_delay_3232889744", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_23_delay.is_open())
	{
        if (! _dynamic_array_synapses_23_delay.empty() )
        {
			outfile__dynamic_array_synapses_23_delay.write(reinterpret_cast<char*>(&_dynamic_array_synapses_23_delay[0]), _dynamic_array_synapses_23_delay.size()*sizeof(_dynamic_array_synapses_23_delay[0]));
		    outfile__dynamic_array_synapses_23_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_23_delay." << endl;
	}
	ofstream outfile__dynamic_array_synapses_23_N_incoming;
	outfile__dynamic_array_synapses_23_N_incoming.open("results/_dynamic_array_synapses_23_N_incoming_186649048", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_23_N_incoming.is_open())
	{
        if (! _dynamic_array_synapses_23_N_incoming.empty() )
        {
			outfile__dynamic_array_synapses_23_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_synapses_23_N_incoming[0]), _dynamic_array_synapses_23_N_incoming.size()*sizeof(_dynamic_array_synapses_23_N_incoming[0]));
		    outfile__dynamic_array_synapses_23_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_23_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_synapses_23_N_outgoing;
	outfile__dynamic_array_synapses_23_N_outgoing.open("results/_dynamic_array_synapses_23_N_outgoing_742160642", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_23_N_outgoing.is_open())
	{
        if (! _dynamic_array_synapses_23_N_outgoing.empty() )
        {
			outfile__dynamic_array_synapses_23_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_synapses_23_N_outgoing[0]), _dynamic_array_synapses_23_N_outgoing.size()*sizeof(_dynamic_array_synapses_23_N_outgoing[0]));
		    outfile__dynamic_array_synapses_23_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_23_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_synapses_3__synaptic_post;
	outfile__dynamic_array_synapses_3__synaptic_post.open("results/_dynamic_array_synapses_3__synaptic_post_4035665760", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_3__synaptic_post.is_open())
	{
        if (! _dynamic_array_synapses_3__synaptic_post.empty() )
        {
			outfile__dynamic_array_synapses_3__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_synapses_3__synaptic_post[0]), _dynamic_array_synapses_3__synaptic_post.size()*sizeof(_dynamic_array_synapses_3__synaptic_post[0]));
		    outfile__dynamic_array_synapses_3__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_3__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_synapses_3__synaptic_pre;
	outfile__dynamic_array_synapses_3__synaptic_pre.open("results/_dynamic_array_synapses_3__synaptic_pre_2149485967", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_3__synaptic_pre.is_open())
	{
        if (! _dynamic_array_synapses_3__synaptic_pre.empty() )
        {
			outfile__dynamic_array_synapses_3__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_synapses_3__synaptic_pre[0]), _dynamic_array_synapses_3__synaptic_pre.size()*sizeof(_dynamic_array_synapses_3__synaptic_pre[0]));
		    outfile__dynamic_array_synapses_3__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_3__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_synapses_3_delay;
	outfile__dynamic_array_synapses_3_delay.open("results/_dynamic_array_synapses_3_delay_451066579", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_3_delay.is_open())
	{
        if (! _dynamic_array_synapses_3_delay.empty() )
        {
			outfile__dynamic_array_synapses_3_delay.write(reinterpret_cast<char*>(&_dynamic_array_synapses_3_delay[0]), _dynamic_array_synapses_3_delay.size()*sizeof(_dynamic_array_synapses_3_delay[0]));
		    outfile__dynamic_array_synapses_3_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_3_delay." << endl;
	}
	ofstream outfile__dynamic_array_synapses_3_N_incoming;
	outfile__dynamic_array_synapses_3_N_incoming.open("results/_dynamic_array_synapses_3_N_incoming_586590565", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_3_N_incoming.is_open())
	{
        if (! _dynamic_array_synapses_3_N_incoming.empty() )
        {
			outfile__dynamic_array_synapses_3_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_synapses_3_N_incoming[0]), _dynamic_array_synapses_3_N_incoming.size()*sizeof(_dynamic_array_synapses_3_N_incoming[0]));
		    outfile__dynamic_array_synapses_3_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_3_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_synapses_3_N_outgoing;
	outfile__dynamic_array_synapses_3_N_outgoing.open("results/_dynamic_array_synapses_3_N_outgoing_99277247", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_3_N_outgoing.is_open())
	{
        if (! _dynamic_array_synapses_3_N_outgoing.empty() )
        {
			outfile__dynamic_array_synapses_3_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_synapses_3_N_outgoing[0]), _dynamic_array_synapses_3_N_outgoing.size()*sizeof(_dynamic_array_synapses_3_N_outgoing[0]));
		    outfile__dynamic_array_synapses_3_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_3_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_synapses_4__synaptic_post;
	outfile__dynamic_array_synapses_4__synaptic_post.open("results/_dynamic_array_synapses_4__synaptic_post_225617685", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_4__synaptic_post.is_open())
	{
        if (! _dynamic_array_synapses_4__synaptic_post.empty() )
        {
			outfile__dynamic_array_synapses_4__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_synapses_4__synaptic_post[0]), _dynamic_array_synapses_4__synaptic_post.size()*sizeof(_dynamic_array_synapses_4__synaptic_post[0]));
		    outfile__dynamic_array_synapses_4__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_4__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_synapses_4__synaptic_pre;
	outfile__dynamic_array_synapses_4__synaptic_pre.open("results/_dynamic_array_synapses_4__synaptic_pre_455049877", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_4__synaptic_pre.is_open())
	{
        if (! _dynamic_array_synapses_4__synaptic_pre.empty() )
        {
			outfile__dynamic_array_synapses_4__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_synapses_4__synaptic_pre[0]), _dynamic_array_synapses_4__synaptic_pre.size()*sizeof(_dynamic_array_synapses_4__synaptic_pre[0]));
		    outfile__dynamic_array_synapses_4__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_4__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_synapses_4_delay;
	outfile__dynamic_array_synapses_4_delay.open("results/_dynamic_array_synapses_4_delay_3745875037", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_4_delay.is_open())
	{
        if (! _dynamic_array_synapses_4_delay.empty() )
        {
			outfile__dynamic_array_synapses_4_delay.write(reinterpret_cast<char*>(&_dynamic_array_synapses_4_delay[0]), _dynamic_array_synapses_4_delay.size()*sizeof(_dynamic_array_synapses_4_delay[0]));
		    outfile__dynamic_array_synapses_4_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_4_delay." << endl;
	}
	ofstream outfile__dynamic_array_synapses_4_N_incoming;
	outfile__dynamic_array_synapses_4_N_incoming.open("results/_dynamic_array_synapses_4_N_incoming_1450066154", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_4_N_incoming.is_open())
	{
        if (! _dynamic_array_synapses_4_N_incoming.empty() )
        {
			outfile__dynamic_array_synapses_4_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_synapses_4_N_incoming[0]), _dynamic_array_synapses_4_N_incoming.size()*sizeof(_dynamic_array_synapses_4_N_incoming[0]));
		    outfile__dynamic_array_synapses_4_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_4_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_synapses_4_N_outgoing;
	outfile__dynamic_array_synapses_4_N_outgoing.open("results/_dynamic_array_synapses_4_N_outgoing_1903308848", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_4_N_outgoing.is_open())
	{
        if (! _dynamic_array_synapses_4_N_outgoing.empty() )
        {
			outfile__dynamic_array_synapses_4_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_synapses_4_N_outgoing[0]), _dynamic_array_synapses_4_N_outgoing.size()*sizeof(_dynamic_array_synapses_4_N_outgoing[0]));
		    outfile__dynamic_array_synapses_4_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_4_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_synapses_5__synaptic_post;
	outfile__dynamic_array_synapses_5__synaptic_post.open("results/_dynamic_array_synapses_5__synaptic_post_2736404100", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_5__synaptic_post.is_open())
	{
        if (! _dynamic_array_synapses_5__synaptic_post.empty() )
        {
			outfile__dynamic_array_synapses_5__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_synapses_5__synaptic_post[0]), _dynamic_array_synapses_5__synaptic_post.size()*sizeof(_dynamic_array_synapses_5__synaptic_post[0]));
		    outfile__dynamic_array_synapses_5__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_5__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_synapses_5__synaptic_pre;
	outfile__dynamic_array_synapses_5__synaptic_pre.open("results/_dynamic_array_synapses_5__synaptic_pre_2732874109", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_5__synaptic_pre.is_open())
	{
        if (! _dynamic_array_synapses_5__synaptic_pre.empty() )
        {
			outfile__dynamic_array_synapses_5__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_synapses_5__synaptic_pre[0]), _dynamic_array_synapses_5__synaptic_pre.size()*sizeof(_dynamic_array_synapses_5__synaptic_pre[0]));
		    outfile__dynamic_array_synapses_5__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_5__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_synapses_5_delay;
	outfile__dynamic_array_synapses_5_delay.open("results/_dynamic_array_synapses_5_delay_2033356777", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_5_delay.is_open())
	{
        if (! _dynamic_array_synapses_5_delay.empty() )
        {
			outfile__dynamic_array_synapses_5_delay.write(reinterpret_cast<char*>(&_dynamic_array_synapses_5_delay[0]), _dynamic_array_synapses_5_delay.size()*sizeof(_dynamic_array_synapses_5_delay[0]));
		    outfile__dynamic_array_synapses_5_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_5_delay." << endl;
	}
	ofstream outfile__dynamic_array_synapses_5_N_incoming;
	outfile__dynamic_array_synapses_5_N_incoming.open("results/_dynamic_array_synapses_5_N_incoming_3452636293", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_5_N_incoming.is_open())
	{
        if (! _dynamic_array_synapses_5_N_incoming.empty() )
        {
			outfile__dynamic_array_synapses_5_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_synapses_5_N_incoming[0]), _dynamic_array_synapses_5_N_incoming.size()*sizeof(_dynamic_array_synapses_5_N_incoming[0]));
		    outfile__dynamic_array_synapses_5_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_5_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_synapses_5_N_outgoing;
	outfile__dynamic_array_synapses_5_N_outgoing.open("results/_dynamic_array_synapses_5_N_outgoing_3939990623", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_5_N_outgoing.is_open())
	{
        if (! _dynamic_array_synapses_5_N_outgoing.empty() )
        {
			outfile__dynamic_array_synapses_5_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_synapses_5_N_outgoing[0]), _dynamic_array_synapses_5_N_outgoing.size()*sizeof(_dynamic_array_synapses_5_N_outgoing[0]));
		    outfile__dynamic_array_synapses_5_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_5_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_synapses_6__synaptic_post;
	outfile__dynamic_array_synapses_6__synaptic_post.open("results/_dynamic_array_synapses_6__synaptic_post_2329051766", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_6__synaptic_post.is_open())
	{
        if (! _dynamic_array_synapses_6__synaptic_post.empty() )
        {
			outfile__dynamic_array_synapses_6__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_synapses_6__synaptic_post[0]), _dynamic_array_synapses_6__synaptic_post.size()*sizeof(_dynamic_array_synapses_6__synaptic_post[0]));
		    outfile__dynamic_array_synapses_6__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_6__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_synapses_6__synaptic_pre;
	outfile__dynamic_array_synapses_6__synaptic_pre.open("results/_dynamic_array_synapses_6__synaptic_pre_3013161732", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_6__synaptic_pre.is_open())
	{
        if (! _dynamic_array_synapses_6__synaptic_pre.empty() )
        {
			outfile__dynamic_array_synapses_6__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_synapses_6__synaptic_pre[0]), _dynamic_array_synapses_6__synaptic_pre.size()*sizeof(_dynamic_array_synapses_6__synaptic_pre[0]));
		    outfile__dynamic_array_synapses_6__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_6__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_synapses_6_delay;
	outfile__dynamic_array_synapses_6_delay.open("results/_dynamic_array_synapses_6_delay_1222284660", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_6_delay.is_open())
	{
        if (! _dynamic_array_synapses_6_delay.empty() )
        {
			outfile__dynamic_array_synapses_6_delay.write(reinterpret_cast<char*>(&_dynamic_array_synapses_6_delay[0]), _dynamic_array_synapses_6_delay.size()*sizeof(_dynamic_array_synapses_6_delay[0]));
		    outfile__dynamic_array_synapses_6_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_6_delay." << endl;
	}
	ofstream outfile__dynamic_array_synapses_6_N_incoming;
	outfile__dynamic_array_synapses_6_N_incoming.open("results/_dynamic_array_synapses_6_N_incoming_3126189685", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_6_N_incoming.is_open())
	{
        if (! _dynamic_array_synapses_6_N_incoming.empty() )
        {
			outfile__dynamic_array_synapses_6_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_synapses_6_N_incoming[0]), _dynamic_array_synapses_6_N_incoming.size()*sizeof(_dynamic_array_synapses_6_N_incoming[0]));
		    outfile__dynamic_array_synapses_6_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_6_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_synapses_6_N_outgoing;
	outfile__dynamic_array_synapses_6_N_outgoing.open("results/_dynamic_array_synapses_6_N_outgoing_2638851759", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_6_N_outgoing.is_open())
	{
        if (! _dynamic_array_synapses_6_N_outgoing.empty() )
        {
			outfile__dynamic_array_synapses_6_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_synapses_6_N_outgoing[0]), _dynamic_array_synapses_6_N_outgoing.size()*sizeof(_dynamic_array_synapses_6_N_outgoing[0]));
		    outfile__dynamic_array_synapses_6_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_6_N_outgoing." << endl;
	}
	ofstream outfile__dynamic_array_synapses_7__synaptic_post;
	outfile__dynamic_array_synapses_7__synaptic_post.open("results/_dynamic_array_synapses_7__synaptic_post_616174567", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_7__synaptic_post.is_open())
	{
        if (! _dynamic_array_synapses_7__synaptic_post.empty() )
        {
			outfile__dynamic_array_synapses_7__synaptic_post.write(reinterpret_cast<char*>(&_dynamic_array_synapses_7__synaptic_post[0]), _dynamic_array_synapses_7__synaptic_post.size()*sizeof(_dynamic_array_synapses_7__synaptic_post[0]));
		    outfile__dynamic_array_synapses_7__synaptic_post.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_7__synaptic_post." << endl;
	}
	ofstream outfile__dynamic_array_synapses_7__synaptic_pre;
	outfile__dynamic_array_synapses_7__synaptic_pre.open("results/_dynamic_array_synapses_7__synaptic_pre_174254316", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_7__synaptic_pre.is_open())
	{
        if (! _dynamic_array_synapses_7__synaptic_pre.empty() )
        {
			outfile__dynamic_array_synapses_7__synaptic_pre.write(reinterpret_cast<char*>(&_dynamic_array_synapses_7__synaptic_pre[0]), _dynamic_array_synapses_7__synaptic_pre.size()*sizeof(_dynamic_array_synapses_7__synaptic_pre[0]));
		    outfile__dynamic_array_synapses_7__synaptic_pre.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_7__synaptic_pre." << endl;
	}
	ofstream outfile__dynamic_array_synapses_7_c;
	outfile__dynamic_array_synapses_7_c.open("results/_dynamic_array_synapses_7_c_1894007561", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_7_c.is_open())
	{
        if (! _dynamic_array_synapses_7_c.empty() )
        {
			outfile__dynamic_array_synapses_7_c.write(reinterpret_cast<char*>(&_dynamic_array_synapses_7_c[0]), _dynamic_array_synapses_7_c.size()*sizeof(_dynamic_array_synapses_7_c[0]));
		    outfile__dynamic_array_synapses_7_c.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_7_c." << endl;
	}
	ofstream outfile__dynamic_array_synapses_7_delay;
	outfile__dynamic_array_synapses_7_delay.open("results/_dynamic_array_synapses_7_delay_4004355776", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_7_delay.is_open())
	{
        if (! _dynamic_array_synapses_7_delay.empty() )
        {
			outfile__dynamic_array_synapses_7_delay.write(reinterpret_cast<char*>(&_dynamic_array_synapses_7_delay[0]), _dynamic_array_synapses_7_delay.size()*sizeof(_dynamic_array_synapses_7_delay[0]));
		    outfile__dynamic_array_synapses_7_delay.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_7_delay." << endl;
	}
	ofstream outfile__dynamic_array_synapses_7_N_incoming;
	outfile__dynamic_array_synapses_7_N_incoming.open("results/_dynamic_array_synapses_7_N_incoming_569414170", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_7_N_incoming.is_open())
	{
        if (! _dynamic_array_synapses_7_N_incoming.empty() )
        {
			outfile__dynamic_array_synapses_7_N_incoming.write(reinterpret_cast<char*>(&_dynamic_array_synapses_7_N_incoming[0]), _dynamic_array_synapses_7_N_incoming.size()*sizeof(_dynamic_array_synapses_7_N_incoming[0]));
		    outfile__dynamic_array_synapses_7_N_incoming.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_7_N_incoming." << endl;
	}
	ofstream outfile__dynamic_array_synapses_7_N_outgoing;
	outfile__dynamic_array_synapses_7_N_outgoing.open("results/_dynamic_array_synapses_7_N_outgoing_116187840", ios::binary | ios::out);
	if(outfile__dynamic_array_synapses_7_N_outgoing.is_open())
	{
        if (! _dynamic_array_synapses_7_N_outgoing.empty() )
        {
			outfile__dynamic_array_synapses_7_N_outgoing.write(reinterpret_cast<char*>(&_dynamic_array_synapses_7_N_outgoing[0]), _dynamic_array_synapses_7_N_outgoing.size()*sizeof(_dynamic_array_synapses_7_N_outgoing[0]));
		    outfile__dynamic_array_synapses_7_N_outgoing.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_synapses_7_N_outgoing." << endl;
	}

	ofstream outfile__dynamic_array_statemonitor_1_phi;
	outfile__dynamic_array_statemonitor_1_phi.open("results/_dynamic_array_statemonitor_1_phi_3049029054", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_1_phi.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_1_phi.n; n++)
        {
            if (! _dynamic_array_statemonitor_1_phi(n).empty())
            {
                outfile__dynamic_array_statemonitor_1_phi.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_1_phi(n, 0)), _dynamic_array_statemonitor_1_phi.m*sizeof(_dynamic_array_statemonitor_1_phi(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_1_phi.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_1_phi." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_1_V;
	outfile__dynamic_array_statemonitor_1_V.open("results/_dynamic_array_statemonitor_1_V_66379438", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_1_V.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_1_V.n; n++)
        {
            if (! _dynamic_array_statemonitor_1_V(n).empty())
            {
                outfile__dynamic_array_statemonitor_1_V.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_1_V(n, 0)), _dynamic_array_statemonitor_1_V.m*sizeof(_dynamic_array_statemonitor_1_V(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_1_V.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_1_V." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_3_phi;
	outfile__dynamic_array_statemonitor_3_phi.open("results/_dynamic_array_statemonitor_3_phi_3481022174", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_3_phi.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_3_phi.n; n++)
        {
            if (! _dynamic_array_statemonitor_3_phi(n).empty())
            {
                outfile__dynamic_array_statemonitor_3_phi.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_3_phi(n, 0)), _dynamic_array_statemonitor_3_phi.m*sizeof(_dynamic_array_statemonitor_3_phi(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_3_phi.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_3_phi." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_3_V;
	outfile__dynamic_array_statemonitor_3_V.open("results/_dynamic_array_statemonitor_3_V_7342784", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_3_V.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_3_V.n; n++)
        {
            if (! _dynamic_array_statemonitor_3_V(n).empty())
            {
                outfile__dynamic_array_statemonitor_3_V.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_3_V(n, 0)), _dynamic_array_statemonitor_3_V.m*sizeof(_dynamic_array_statemonitor_3_V(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_3_V.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_3_V." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_4_phi;
	outfile__dynamic_array_statemonitor_4_phi.open("results/_dynamic_array_statemonitor_4_phi_2103243470", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_4_phi.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_4_phi.n; n++)
        {
            if (! _dynamic_array_statemonitor_4_phi(n).empty())
            {
                outfile__dynamic_array_statemonitor_4_phi.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_4_phi(n, 0)), _dynamic_array_statemonitor_4_phi.m*sizeof(_dynamic_array_statemonitor_4_phi(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_4_phi.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_4_phi." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_4_V;
	outfile__dynamic_array_statemonitor_4_V.open("results/_dynamic_array_statemonitor_4_V_88022085", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_4_V.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_4_V.n; n++)
        {
            if (! _dynamic_array_statemonitor_4_V(n).empty())
            {
                outfile__dynamic_array_statemonitor_4_V.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_4_V(n, 0)), _dynamic_array_statemonitor_4_V.m*sizeof(_dynamic_array_statemonitor_4_V(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_4_V.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_4_V." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_5_phi;
	outfile__dynamic_array_statemonitor_5_phi.open("results/_dynamic_array_statemonitor_5_phi_1077730174", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_5_phi.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_5_phi.n; n++)
        {
            if (! _dynamic_array_statemonitor_5_phi(n).empty())
            {
                outfile__dynamic_array_statemonitor_5_phi.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_5_phi(n, 0)), _dynamic_array_statemonitor_5_phi.m*sizeof(_dynamic_array_statemonitor_5_phi(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_5_phi.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_5_phi." << endl;
	}
	ofstream outfile__dynamic_array_statemonitor_5_V;
	outfile__dynamic_array_statemonitor_5_V.open("results/_dynamic_array_statemonitor_5_V_83719794", ios::binary | ios::out);
	if(outfile__dynamic_array_statemonitor_5_V.is_open())
	{
        for (int n=0; n<_dynamic_array_statemonitor_5_V.n; n++)
        {
            if (! _dynamic_array_statemonitor_5_V(n).empty())
            {
                outfile__dynamic_array_statemonitor_5_V.write(reinterpret_cast<char*>(&_dynamic_array_statemonitor_5_V(n, 0)), _dynamic_array_statemonitor_5_V.m*sizeof(_dynamic_array_statemonitor_5_V(0, 0)));
            }
        }
        outfile__dynamic_array_statemonitor_5_V.close();
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_statemonitor_5_V." << endl;
	}
	// Write last run info to disk
	ofstream outfile_last_run_info;
	outfile_last_run_info.open("results/last_run_info.txt", ios::out);
	if(outfile_last_run_info.is_open())
	{
		outfile_last_run_info << (Network::_last_run_time) << " " << (Network::_last_run_completed_fraction) << std::endl;
		outfile_last_run_info.close();
	} else
	{
	    std::cout << "Error writing last run info to file." << std::endl;
	}
}

void _dealloc_arrays()
{
	using namespace brian;


	// static arrays
	if(_static_array__array_statemonitor_1__indices!=0)
	{
		delete [] _static_array__array_statemonitor_1__indices;
		_static_array__array_statemonitor_1__indices = 0;
	}
	if(_static_array__array_statemonitor_3__indices!=0)
	{
		delete [] _static_array__array_statemonitor_3__indices;
		_static_array__array_statemonitor_3__indices = 0;
	}
	if(_static_array__array_statemonitor_4__indices!=0)
	{
		delete [] _static_array__array_statemonitor_4__indices;
		_static_array__array_statemonitor_4__indices = 0;
	}
	if(_static_array__array_statemonitor_5__indices!=0)
	{
		delete [] _static_array__array_statemonitor_5__indices;
		_static_array__array_statemonitor_5__indices = 0;
	}
}


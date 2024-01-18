#include "code_objects/neurongroup_8_stateupdater_codeobject.h"
#include "objects.h"
#include "brianlib/common_math.h"
#include "brianlib/stdint_compat.h"
#include<cmath>
#include<ctime>
#include<iostream>
#include<fstream>
#include<climits>

////// SUPPORT CODE ///////
namespace {
        
    static inline int64_t _timestep(double t, double dt)
    {
        return (int64_t)((t + 1e-3*dt)/dt);
    }
    template < typename T1, typename T2 > struct _higher_type;
    template < > struct _higher_type<int,int> { typedef int type; };
    template < > struct _higher_type<int,long> { typedef long type; };
    template < > struct _higher_type<int,long long> { typedef long long type; };
    template < > struct _higher_type<int,float> { typedef float type; };
    template < > struct _higher_type<int,double> { typedef double type; };
    template < > struct _higher_type<int,long double> { typedef long double type; };
    template < > struct _higher_type<long,int> { typedef long type; };
    template < > struct _higher_type<long,long> { typedef long type; };
    template < > struct _higher_type<long,long long> { typedef long long type; };
    template < > struct _higher_type<long,float> { typedef float type; };
    template < > struct _higher_type<long,double> { typedef double type; };
    template < > struct _higher_type<long,long double> { typedef long double type; };
    template < > struct _higher_type<long long,int> { typedef long long type; };
    template < > struct _higher_type<long long,long> { typedef long long type; };
    template < > struct _higher_type<long long,long long> { typedef long long type; };
    template < > struct _higher_type<long long,float> { typedef float type; };
    template < > struct _higher_type<long long,double> { typedef double type; };
    template < > struct _higher_type<long long,long double> { typedef long double type; };
    template < > struct _higher_type<float,int> { typedef float type; };
    template < > struct _higher_type<float,long> { typedef float type; };
    template < > struct _higher_type<float,long long> { typedef float type; };
    template < > struct _higher_type<float,float> { typedef float type; };
    template < > struct _higher_type<float,double> { typedef double type; };
    template < > struct _higher_type<float,long double> { typedef long double type; };
    template < > struct _higher_type<double,int> { typedef double type; };
    template < > struct _higher_type<double,long> { typedef double type; };
    template < > struct _higher_type<double,long long> { typedef double type; };
    template < > struct _higher_type<double,float> { typedef double type; };
    template < > struct _higher_type<double,double> { typedef double type; };
    template < > struct _higher_type<double,long double> { typedef long double type; };
    template < > struct _higher_type<long double,int> { typedef long double type; };
    template < > struct _higher_type<long double,long> { typedef long double type; };
    template < > struct _higher_type<long double,long long> { typedef long double type; };
    template < > struct _higher_type<long double,float> { typedef long double type; };
    template < > struct _higher_type<long double,double> { typedef long double type; };
    template < > struct _higher_type<long double,long double> { typedef long double type; };
    template < typename T1, typename T2 >
    static inline typename _higher_type<T1,T2>::type
    _brian_mod(T1 x, T2 y)
    {{
        return x-y*floor(1.0*x/y);
    }}
    template < typename T1, typename T2 >
    static inline typename _higher_type<T1,T2>::type
    _brian_floordiv(T1 x, T2 y)
    {{
        return floor(1.0*x/y);
    }}
    #ifdef _MSC_VER
    #define _brian_pow(x, y) (pow((double)(x), (y)))
    #else
    #define _brian_pow(x, y) (pow((x), (y)))
    #endif

}

////// HASH DEFINES ///////



void _run_neurongroup_8_stateupdater_codeobject()
{
    using namespace brian;


    ///// CONSTANTS ///////////
    const int64_t N = 400;
const size_t _numV = 400;
const size_t _numa = 400;
const int64_t beta_a = 2;
const int64_t beta_d = 2;
const size_t _numd = 400;
const size_t _numdt = 1;
const size_t _numlastspike = 400;
const size_t _numnot_refractory = 400;
const double nu = 8.0;
const size_t _numphi = 400;
const size_t _numt = 1;
const double tau_ca = 5.0;
const double tau_m = 0.02;
    ///// POINTERS ////////////
        
    double* __restrict  _ptr_array_neurongroup_8_V = _array_neurongroup_8_V;
    double* __restrict  _ptr_array_neurongroup_8_a = _array_neurongroup_8_a;
    double* __restrict  _ptr_array_neurongroup_8_d = _array_neurongroup_8_d;
    double*   _ptr_array_defaultclock_dt = _array_defaultclock_dt;
    double* __restrict  _ptr_array_neurongroup_8_lastspike = _array_neurongroup_8_lastspike;
    char* __restrict  _ptr_array_neurongroup_8_not_refractory = _array_neurongroup_8_not_refractory;
    double* __restrict  _ptr_array_neurongroup_8_phi = _array_neurongroup_8_phi;
    double*   _ptr_array_defaultclock_t = _array_defaultclock_t;


    //// MAIN CODE ////////////
    // scalar code
    const size_t _vectorisation_idx = -1;
        
    const double dt = _ptr_array_defaultclock_dt[0];
    const double t = _ptr_array_defaultclock_t[0];
    const int64_t _lio_1 = _timestep(0.002, dt);
    const double _lio_2 = 1.0f*dt/tau_m;
    const double _lio_3 = 1.0f*dt/beta_a;
    const double _lio_4 = 1.0f*dt/beta_d;
    const double _lio_5 = 1.0f*(- dt)/tau_ca;


    const int _N = N;
    
    for(int _idx=0; _idx<_N; _idx++)
    {
        // vector code
        const size_t _vectorisation_idx = _idx;
                
        double V = _ptr_array_neurongroup_8_V[_idx];
        double a = _ptr_array_neurongroup_8_a[_idx];
        double d = _ptr_array_neurongroup_8_d[_idx];
        const double lastspike = _ptr_array_neurongroup_8_lastspike[_idx];
        char not_refractory = _ptr_array_neurongroup_8_not_refractory[_idx];
        double phi = _ptr_array_neurongroup_8_phi[_idx];
        not_refractory = _timestep(t - lastspike, dt) >= _lio_1;
        double _V;
        if(!not_refractory)
            _V = V;
        else 
            _V = (_lio_2 * (- V)) + V;
        const double _a = a + (_lio_3 * (nu - phi));
        const double _d = d + (_lio_4 * (nu - phi));
        const double _phi = (_lio_5 * phi) + phi;
        if(not_refractory)
            V = _V;
        a = _a;
        d = _d;
        phi = _phi;
        _ptr_array_neurongroup_8_V[_idx] = V;
        _ptr_array_neurongroup_8_a[_idx] = a;
        _ptr_array_neurongroup_8_d[_idx] = d;
        _ptr_array_neurongroup_8_not_refractory[_idx] = not_refractory;
        _ptr_array_neurongroup_8_phi[_idx] = phi;

    }

}



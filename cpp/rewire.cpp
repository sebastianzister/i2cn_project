#include "rewire.h"

#include <vector>
#include <random>
#include <unordered_map>
#include <numeric>

#include <chrono>
template <typename T>
void print_as_2d(const std::vector<T>& vec, int num_cols) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << ' ';
        if ((i + 1) % num_cols == 0) {
            std::cout << '\n';
        }
    }
}

template <typename T>
void print_vec(const std::vector<T>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << ' ';
    }
    std::cout << '\n';
}

void _delete_connections_rowwise(int num, std::vector<double>& connections, int row_start_index, int num_rows, int num_cols, int num_connections) {
    if(num > 0) {
        std::random_device rd;
        std::mt19937 g(rd());

        std::vector<int> x;

        int element_index;
        // Repeat each index by the corresponding element in connections
        for (int i = 0; i < num_cols; ++i) {
            int repeat = connections[row_start_index + i];
            for (int j = 0; j < repeat; ++j) {
                x.push_back(i);
            }
        }

        // Shuffle to get random connections to delete
        std::shuffle(x.begin(), x.end(), g);

        // Delete the first num elements from x
        for(int i = 0; i < min(num, (int)x.size()); i++) {
            connections[row_start_index + x[i]] -= 1;
        }
    }
}

//#define DEBUG
void _delete_connections_columnwise(int num, std::vector<double>& connections, int col_start_index, int num_rows, int num_cols, int num_connections) {
    //int num_delete = min(num, num_connections);
    //if(num_delete > 0) {
    if(num > 0){
        #ifdef DEBUG
            std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
            std::chrono::steady_clock::time_point end;
        #endif
        std::random_device rd;
        std::mt19937 g(rd());

        std::vector<int> x;

        #ifdef DEBUG
        if(col_start_index==0){
            end = std::chrono::steady_clock::now();
            std::cout << "\t\tDelete_post_iter_init = " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "[µs]" << std::endl;
            start=end;
        }
        #endif

        // Repeat each index by the corresponding element in connections
        for (int i = 0; i < num_rows; ++i) {
            int index = col_start_index + i * num_rows;
            int repeat = connections[index];
            for (int j = 0; j < repeat; ++j) {
                x.push_back(i);
            }
        }
        #ifdef DEBUG
        if(col_start_index==0){
            end = std::chrono::steady_clock::now();
            std::cout << "\t\tDelete_post_iter_count= " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "[µs]" << std::endl;
            start=end;
        }
        #endif

        // Shuffle to get random connections to delete
        std::shuffle(x.begin(), x.end(), g);
        #ifdef DEBUG
        if(col_start_index==0){
            end = std::chrono::steady_clock::now();
            std::cout << "\t\tDelete_post_iter_shuffle= " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "[µs]" << std::endl;
            start=end;
        }
        #endif

        // Delete the first num elements from x
        for(int i = 0; i < min(num, (int)x.size()); i++) {
            int index = col_start_index + x[i] * num_rows;
            connections[index] -= 1;
        }
        #ifdef DEBUG
        if(col_start_index==0){
            end = std::chrono::steady_clock::now();
            std::cout << "\t\tDelete_post_iter_delete= " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "[µs]" << std::endl;
            start=end;
        }
        #endif
    }
}

void delete_connections_pre(std::vector<double>& connection_matrix, std::vector<int>& delta_a, int n_e) {
    #pragma omp parallel for simd
    for (int i = 0; i < n_e; ++i) {
        _delete_connections_rowwise(-delta_a[i], connection_matrix, i * n_e, n_e, n_e, 0);
    }
}

void delete_connections_post(std::vector<double>& connection_matrix, std::vector<int>& delta_d, int n_e) {
    #pragma omp parallel for simd
    for (int i = 0; i < n_e; ++i) {
        #ifdef DEBUG
            std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
            std::chrono::steady_clock::time_point end;
        #endif
        _delete_connections_columnwise(-delta_d[i], connection_matrix, i, n_e, n_e, 0);
        #ifdef DEBUG
        if(i==0){
            end = std::chrono::steady_clock::now();
            std::cout << "\tDelete_post_iter = " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "[µs]" << std::endl;
        }
        #endif
    }
}

void create_connections(std::vector<double>& connections, std::vector<int>& delta_a, std::vector<int>& delta_d, int n_e) {
    std::random_device rd;
    std::mt19937 g(rd());

    std::vector<int> free_a;
    std::vector<int> free_d;

    for (int i = 0; i < delta_a.size(); ++i) {
        for (int j = 0; j < delta_a[i]; ++j) {
            free_a.push_back(i);
        }
    }
    
    for (int i = 0; i < delta_d.size(); ++i) {
        for (int j = 0; j < delta_d[i]; ++j) {
            free_d.push_back(i);
        }
    }
    
    std::shuffle(free_d.begin(), free_d.end(), g);
    std::shuffle(free_a.begin(), free_a.end(), g);
    
    int num_connections = std::min(free_a.size(), free_d.size());
    
    for (int i = 0; i < num_connections; ++i) {
        int a = free_a[i];
        int d = free_d[i];
        if (a!=d) connections[a * n_e + d] += 1;
    }
}

double rewire() {
    try{
    using namespace brian;

    #ifdef DEBUG
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point begin = start;
    std::chrono::steady_clock::time_point end;
    #endif
    //cout << "rewire" << endl;
    // Get connectivity matrix
    std::vector<double>& connections = _dynamic_array_S_E_E_c;
    
    //print_as_2d(connections, _dynamic_array_S_E_E_N_incoming[0]);
    
    int n_e = _dynamic_array_S_E_E_N_incoming[0];

    // Get number of free/deleted elements
    std::vector<int> delta_a(n_e);
    std::vector<int> delta_d(n_e);
    

    #ifdef DEBUG
    end = std::chrono::steady_clock::now();
    std::cout << "Init = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    begin = end;
    #endif
    
    int temp_neg = 0;
    int temp_pos = 0;
    int temp_con = 0;
    
    // Calculate delta_a
    #pragma omp parallel for reduction(+:temp_neg, temp_pos)
    for (int i = 0; i < n_e; ++i) {
        int row_sum = 0;
        #pragma omp parallel for simd reduction(+:row_sum)
        for (int j = 0; j < n_e; ++j) {
            row_sum += connections[i * n_e + j];
        }
        delta_a[i] = std::floor(_array_E_a[i]) - row_sum;
    }

    #ifdef DEBUG
    end = std::chrono::steady_clock::now();
    std::cout << "Delta_a = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    begin = end;
    #endif
    
    temp_neg = 0;
    temp_pos = 0;
    temp_con = 0;

    
    // Calculate delta_d
    #pragma omp parallel for simd reduction(+:temp_neg, temp_pos)
    for (int i = 0; i < n_e; ++i) {
        int column_sum = 0;
        #pragma omp simd reduction(+:column_sum)
        for (int j = 0; j < n_e; ++j) {
            column_sum += connections[j*n_e + i];
        }
        delta_d[i] = std::floor(_array_E_d[i]) - column_sum;//k_out[i];
        if(delta_d[i] > 0){
            temp_pos += delta_d[i];
        }else{
            temp_neg += delta_d[i];
        }
    }

    #ifdef DEBUG
    end = std::chrono::steady_clock::now();
    std::cout << "Deltas = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    begin = end;
    #endif

    // delete axonal elements
    delete_connections_pre(connections, delta_a, n_e);

    #ifdef DEBUG
    end = std::chrono::steady_clock::now();
    std::cout << "Delete_pre = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    begin = end;
    #endif

    // delete dendritic elements
    delete_connections_post(connections, delta_d, n_e);

    #ifdef DEBUG
    end = std::chrono::steady_clock::now();
    std::cout << "Delete_post = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    begin = end;
    #endif

    // create new connections between free elements
    create_connections(connections, delta_a, delta_d, n_e);

    #ifdef DEBUG
    end = std::chrono::steady_clock::now();
    std::cout << "Create = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    begin = end;
    
    std::cout << "Total = " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "[µs]" << std::endl;
    #endif

    // TODO: make void
    return 0;
    }catch(std::exception& e){
        cout << e.what() << endl;
    }
}

double record_mean(int start_g1, int end_g1, int start_g2, int end_g2){
    using namespace brian;

    double mean = 0;
    std::vector<double>& connections = _dynamic_array_S_E_E_c;
    int n_e = _dynamic_array_S_E_E_N_incoming[0];
    
    for (int i = start_g1; i < end_g1; ++i) {
        for (int j = start_g2; j < end_g2; ++j) {
            mean += connections[i * n_e + j];
        }
    }

    mean /= (end_g1 - start_g1) * (end_g2 - start_g2);
    
    return mean;
}
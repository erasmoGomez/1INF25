//
// Created by erasmo on 4/23/26.
//

#ifndef QUICKSORT_FUNCIONES_HPP
#define QUICKSORT_FUNCIONES_HPP

#include "Utils.hpp"

void quick_sort(int *arreglo, int left, int right, int level);

void my_swap(int &x, int &y);

void print_array(const int *arreglo, int from, int n);

void print_indent(int level);

void print_separator(int level);

void print_array_with_indent(const int *arreglo, int left, int right, int level);

void print_base_case(int left, int right, int level);

void print_start_call(const int *arreglo, int left, int right, int pivot, int level);

void print_after_pivot_swap(const int *arreglo, int left, int right, int level);

void print_after_partition(const int *arreglo, int left, int right, int level);

void print_after_pivot_final_position(const int *arreglo, int left, int right,
                                      int limit, int level);

void print_recursive_calls(int left, int right, int limit, int level);
#endif //QUICKSORT_FUNCIONES_HPP

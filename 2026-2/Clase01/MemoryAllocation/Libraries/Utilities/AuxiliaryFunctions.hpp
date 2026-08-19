//
// Created by erasmo on 8/19/26.
//

#ifndef MEMORYALLOCATION_AUXILIARYFUNCTIONS_HPP
#define MEMORYALLOCATION_AUXILIARYFUNCTIONS_HPP
#include "Utils.hpp"

void print_line(ostream &out, char, int);

void print_centered_text(ostream &out, const char *);

char *allocate_string(const char *);

char **create_string_array(int);

void delete_string_array(char **&, int);

void allocated_ptr(int *&, int);
#endif //MEMORYALLOCATION_AUXILIARYFUNCTIONS_HPP

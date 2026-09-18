//
// Created by erasmo on 9/17/26.
//

#ifndef PUNTEROSGENERICOS_AUXILIARYFUNCTIONS_HPP
#define PUNTEROSGENERICOS_AUXILIARYFUNCTIONS_HPP
#include "Utils.hpp"

void open_file_read(ifstream &input, const char *file_name);

void open_file_write(ofstream &output, const char *file_name);

int read_date(ifstream &input);

char *read_str(ifstream &input_file, char='\n');

int read_int(ifstream &input_file, bool=false);

double read_double(ifstream &input_file, bool=false);

bool read_bool(ifstream &input_file, bool=false);

void print_line(ofstream &output_file, char character, int size);

char *assign_str(const char *text);
#endif //PUNTEROSGENERICOS_AUXILIARYFUNCTIONS_HPP

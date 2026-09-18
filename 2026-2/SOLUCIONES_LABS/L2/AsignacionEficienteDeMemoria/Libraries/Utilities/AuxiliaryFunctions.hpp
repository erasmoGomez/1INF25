//
// Created by erasmo on 9/17/26.
//

#ifndef ASIGNACIONEFICIENTEDEMEMORIA_AUXILIARYFUNCTIONS_HPP
#define ASIGNACIONEFICIENTEDEMEMORIA_AUXILIARYFUNCTIONS_HPP
#include "Utils.hpp"

void open_file_read(ifstream &input, const char *file_name);

void open_file_write(ofstream &output, const char *file_name);

int read_date(ifstream &input);

char *read_str(ifstream &input_file, char='\n');

int read_int(ifstream &input_file, bool=false);

double read_double(ifstream &input_file, bool=false);

bool read_bool(ifstream &input_file, bool=false);
#endif //ASIGNACIONEFICIENTEDEMEMORIA_AUXILIARYFUNCTIONS_HPP

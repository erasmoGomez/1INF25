//
// Created by Erasmo on 2/09/25.
//

#ifndef TWEETS_AUCILIARYFUNCTIONS_HPP
#define TWEETS_AUCILIARYFUNCTIONS_HPP

#include "Utils.hpp"

void open_file_read(ifstream &input, const char *nombre_archivo);

void open_file_write(ofstream &output, const char *nombre_archivo);

int read_int(ifstream &input);

double read_double(ifstream &input);

char *read_str(ifstream &input, char delim);

int lookup_int(int to_look, int *source);

char *assign_str(char* source);

#endif //TWEETS_AUCILIARYFUNCTIONS_HPP

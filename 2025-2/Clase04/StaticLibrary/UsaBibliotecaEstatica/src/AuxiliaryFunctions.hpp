//
// Created by Erasmo on 22/08/25.
//

#ifndef OPERATOROVERLOADINGREVIEWS_AUXILIARYFUNCTIONS_HPP
#define OPERATOROVERLOADINGREVIEWS_AUXILIARYFUNCTIONS_HPP

#include "Utils.hpp"
#include "Reviews.hpp"

void open_file_read(ifstream &input, const char *file_name);

void open_file_write(ofstream &output, const char *file_name);

int read_date(ifstream &input);

void qsort(struct Review *reviews, int izq, int der);

#endif //OPERATOROVERLOADINGREVIEWS_AUXILIARYFUNCTIONS_HPP

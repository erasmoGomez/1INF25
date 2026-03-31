//
// Created by Erasmo on 20/08/25.
//

#ifndef STATICUSES_FUNCTIONS_HPP
#define STATICUSES_FUNCTIONS_HPP
#include "Utils.hpp"
void print_line(size_t, char);
bool get_next_token(const char* input, char* word);
char* get_next_token(const char* input_string);
void tokenize(const char* input_string, int,  bool = false);
#endif //STATICUSES_FUNCTIONS_HPP

//
// Created by erasmo on 8/25/26.
//

#ifndef OPERATOROVERLOADINGREVIEWSDYNAMIC_REVIEWCONTROLLER_HPP
#define OPERATOROVERLOADINGREVIEWSDYNAMIC_REVIEWCONTROLLER_HPP
#include "../Overloads.hpp"
void  load_reviews(const char*, struct Review*&, int&);
void  print_reviews(const char*, const struct Review*, int);
void fill_stats(Review* , int, int*);
void print_stats(const int*, int);

#endif //OPERATOROVERLOADINGREVIEWSDYNAMIC_REVIEWCONTROLLER_HPP
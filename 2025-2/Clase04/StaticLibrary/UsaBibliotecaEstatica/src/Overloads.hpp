//
// Created by Erasmo on 22/08/25.
//

#ifndef OPERATOROVERLOADINGREVIEWS_OVERLOADS_HPP
#define OPERATOROVERLOADINGREVIEWS_OVERLOADS_HPP

#include "AuxiliaryFunctions.hpp"
#include "Reviews.hpp"

//"Data/reviews.csv"<<reviews;
void operator<<(const char *file_name, struct Reviews &reviews);

void operator>>(ifstream &input, struct Review &review);

void operator<<(struct Reviews &reviews, const char *file_name);

void operator<<(ofstream &output, const struct Review review);

void operator*=(struct Reviews &reviews, double aumento);

void operator++(struct Reviews &reviews);

void operator!(struct Reviews &reviews);

#endif //OPERATOROVERLOADINGREVIEWS_OVERLOADS_HPP

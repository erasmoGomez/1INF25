//
// Created by Erasmo on 22/08/25.
//

#ifndef OPERATOROVERLOADINGREVIEWS_OVERLOADS_HPP
#define OPERATOROVERLOADINGREVIEWS_OVERLOADS_HPP

#include "Utils/AuxiliaryFunctions.hpp"
#include "Model/Review.hpp"

bool operator>>(ifstream &input, struct Review &review);
void operator<<(ofstream &output, const struct Review &review);
void operator+=(const struct Review &, int*);


#endif //OPERATOROVERLOADINGREVIEWS_OVERLOADS_HPP

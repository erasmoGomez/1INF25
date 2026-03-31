//
// Created by erasmo on 3/31/26.
//

#ifndef FUENTESBIBLIOTECA_REVIEW_HPP
#define FUENTESBIBLIOTECA_REVIEW_HPP
#include "Utils.hpp"
//2024-10-17,Horrible experience,0.29
struct Review {
    int date;
    char review[REVIEW_SIZE];
    double rating;
};
#endif //FUENTESBIBLIOTECA_REVIEW_HPP
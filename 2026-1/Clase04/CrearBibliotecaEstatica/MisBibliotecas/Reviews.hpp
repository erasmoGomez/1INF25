//
// Created by erasmo on 3/31/26.
//

#ifndef FUENTESBIBLIOTECA_REVIEWS_HPP
#define FUENTESBIBLIOTECA_REVIEWS_HPP

#include "Review.hpp"

struct Reviews {
    struct Review reviews[REVIEWS_MAX];
    int n_reviews; //Cantidad real de datos
};

#endif //FUENTESBIBLIOTECA_REVIEWS_HPP
//
// Created by Erasmo on 22/08/25.
//

#ifndef OPERATOROVERLOADINGREVIEWS_REVIEWS_HPP
#define OPERATOROVERLOADINGREVIEWS_REVIEWS_HPP

#include "Review.hpp"

struct Reviews {
    struct Review reviews[REVIEWS_MAX];
    int n_reviews; //Cantidad real de datos
    int n_negatives;
    int n_positives;
    int n_neutrals;
};

#endif //OPERATOROVERLOADINGREVIEWS_REVIEWS_HPP

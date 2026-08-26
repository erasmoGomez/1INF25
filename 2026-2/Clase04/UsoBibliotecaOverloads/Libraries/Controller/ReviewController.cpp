//
// Created by erasmo on 8/25/26.
//

#include "ReviewController.hpp"

void load_reviews(const char *file_name, struct Review *&reviews, int& n_reviews) {
    ifstream input;
    open_file_read(input, file_name);
    reviews = new Review[REVIEWS_MAX]{};
    while (true) {
        struct Review review{};
        if (!(input >> review)) break;
        reviews[n_reviews] = review;
        n_reviews++;
    }
}

void print_reviews(const char *file_name, const struct Review *reviews, int n_reviews) {
    ofstream output;
    open_file_write(output, file_name);
    for (int i = 0; i<n_reviews; i++) {
        output << reviews[i];
    }
}

void fill_stats(Review *reviews, int n_reviews, int *stats) {
    for (int i = 0; i<n_reviews; i++) {
        reviews[i]+=stats;
    }
}

void print_stats(const int *stats, int n_reviews) {
    cout<<"Cantidad de Reviews NEGATIVOS "<<stats[0]<<endl;
    cout<<"Cantidad de Reviews NEUTRALES "<<stats[1]<<endl;
    cout<<"Cantidad de Reviews POSITIVOS "<<stats[2]<<endl;
    cout<<"Cantidad de Reviews TOTALES "<<n_reviews<<endl;
}

//
// Created by Erasmo on 22/08/25.
//

#include "Overloads.hpp"

void operator<<(const char *file_name, struct Reviews &reviews) {
    cout << "Me llamaron desde la sobrecarga en el main" << endl;
    ifstream input;
    open_file_read(input, file_name);
    struct Review review{};
    int &n_reviews = reviews.n_reviews;
    while (true) {
        input >> review; //Necesita otra sobrecarga para leer un solo review
        //input >> review;
        //tipo_dato_resultando operator (operando1, operando2)
        //void operator >> (input, review)
        //void operator >> (ifstream& input, struct Review& review);
        if (input.eof())break;
        reviews.reviews[n_reviews] = review;
        n_reviews++;
    }
}

void operator>>(ifstream &input, struct Review &review) {
    //2024-10-21,Stopped working quickly,0.1
    review.date = read_date(input);
    if (input.eof()) return;
    input.get();
    input.getline(review.review, REVIEW_SIZE, ',');
    input >> review.rating;
}

void operator<<(ofstream &output, const struct Review review) {
    output << fixed;
    output << setprecision(2) << endl;
    output << setw(REPORT_WITH / 3) << review.date;
    output << setw(REPORT_WITH / 3) << review.review;
    output << setw(REPORT_WITH / 3) << review.rating << endl;
}

void operator<<(struct Reviews &reviews, const char *file_name) {
    ofstream output;
    open_file_write(output, file_name);
    for (int i = 0; i < reviews.n_reviews; i++) {
        output << reviews.reviews[i]; // Esto necesita otra sobrecarga para imprimir un solo review
    }
}

void operator*=(Reviews &reviews, double aumento) {
    for (int i = 0; i < reviews.n_reviews; i++) reviews.reviews[i].rating *= (1 + aumento);
}

void operator++(struct Reviews &reviews) {
    qsort(reviews.reviews, 0, reviews.n_reviews - 1);
}

void operator!(Reviews &reviews) {
    for (int i = 0; i < reviews.n_reviews; i++) {
        if (reviews.reviews[i].rating < 0.4) reviews.n_negatives++;
        if (reviews.reviews[i].rating >= 0.4 and reviews.reviews[i].rating < 0.6) reviews.n_neutrals++;
        if (reviews.reviews[i].rating >= 0.6) reviews.n_positives++;
    }
}

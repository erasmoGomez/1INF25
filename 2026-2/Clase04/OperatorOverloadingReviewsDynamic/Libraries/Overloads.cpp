//
// Created by Erasmo on 22/08/25.
//

#include "Overloads.hpp"
bool operator>>(ifstream &input, struct Review &review) {
    //2024-10-21,Stopped working quickly,0.1
    review.date = read_date(input);
    if(input.eof()) return false;
    input.get();
    review.review = read_str(input);
    review.rating = read_double(input);
    return true;
}

void operator<<(ofstream &output, const struct Review& review) {
    output<<fixed;
    output<<setprecision(2)<<endl;
    output<<setw(OUTPUT_WIDTH/3)<<review.date;
    output<<setw(OUTPUT_WIDTH/3)<<review.review;
    output<<setw(OUTPUT_WIDTH/3)<<review.rating<<endl;
}

void operator+=(const struct Review &r, int *stats) {
    if(r.rating < 0.4) stats[0]++;
    if(r.rating >= 0.4 and r.rating < 0.6 ) stats[1]++;
    if(r.rating >= 0.6) stats[2]++;
}


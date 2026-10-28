//
// Created by erasmo on 9/29/26.
//

#include "Utils.hpp"

void Utils::open_read_file(ifstream &input, const char *filename) {
    input.open(filename, ios::in);
    if (!input) {
        cout << "Error opening file " << filename << endl;
        exit(1);
    }
}

void Utils::open_write_file(ofstream &output, const char *filename) {
    output.open(filename, ios::out);
    if (!output) {
        cout << "Error opening file " << filename << endl;
        exit(1);
    }
}

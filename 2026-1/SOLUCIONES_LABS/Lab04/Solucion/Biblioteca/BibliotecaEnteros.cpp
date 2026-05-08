//
// Created by Daniel Sanchez on 8/05/26.
//

#include "BibliotecaEnteros.h"

#include <fstream>

void *leenum(std::ifstream &file) {
    int num;
    file >> num;
    if (file.eof()) return nullptr;
    int *num_ptr = new int(num);
    return num_ptr;
}

int comparanum(const void *a, const void *b) {
    void **a_ptr = (void **) a;
    void **b_ptr = (void **) b;

    void *a_data = *a_ptr;
    void *b_data = *b_ptr;

    return verificanum(a_data, b_data);
}

int verificanum(const void *a, const void *b) {
    int num1 = *(int *) a;
    int num2 = *(int *) b;
    return num1 - num2;
}

void imprimenum(std::ostream &file, void *data) {
    int num = *(int *) data;
    file << num << std::endl;
}

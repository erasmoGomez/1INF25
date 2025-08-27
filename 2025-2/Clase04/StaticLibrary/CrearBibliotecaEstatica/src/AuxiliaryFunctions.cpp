//
// Created by Erasmo on 22/08/25.
//

#include "AuxiliaryFunctions.hpp"

void open_file_read(ifstream &input, const char *file_name) {
    input.open(file_name, ios::in);
    if (!input.is_open()) {
        cout << "The file can not open: " << file_name;
        exit(1);
    }
}

void open_file_write(ofstream &output, const char *file_name) {
    output.open(file_name, ios::out);
    if (!output.is_open()) {
        cout << "The file can not open: " << file_name;
        exit(1);
    }
}

int read_date(ifstream &input) {
    int date, aa, mm, dd;
    char c;
    input >> aa >> c >> mm >> c >> dd;
    date = aa * 10000 + mm * 100 + dd;
    return date;
}

void cambiar(struct Review &reviewI, struct Review &reviewK) {
    struct Review aux;
    aux = reviewI;
    reviewI = reviewK;
    reviewK = aux;
}

void qsort(struct Review *reviews, int izq, int der) {
    int limite, pMedio;
    if (izq >= der) return;
    pMedio = (izq + der) / 2;
    cambiar(reviews[izq], reviews[pMedio]);
    limite = izq;
    for (int i = izq + 1; i <= der; ++i) {
        if (strcmp(reviews[i].review, reviews[izq].review) < 0)
            //reviews[i]<reviews[izq] <====== Tarea sobrecargar
            cambiar(reviews[i], reviews[++limite]);
        // reviews[i] == reviews[++limite]; <====== Tarea sobrecargar
    }
    cambiar(reviews[izq], reviews[limite]);
    qsort(reviews, izq, limite - 1);
    qsort(reviews, limite + 1, der);
}
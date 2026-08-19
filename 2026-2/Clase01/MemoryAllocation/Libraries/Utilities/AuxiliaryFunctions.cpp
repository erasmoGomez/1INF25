//
// Created by erasmo on 8/19/26.
//

#include "AuxiliaryFunctions.hpp"

void print_line(ostream &out, const char c, const int n) {
    for (int i=0; i<n; i++)
        out << c;
    out << endl;
}

void print_centered_text(ostream &out, const char *text) {
    cout << setw((OUTPUT_WIDTH+static_cast<int>(strlen(text)))/2)<<text << endl;
}

char * allocate_string(const char * source) {
    char* destination = new char[strlen(source)+1];
    strcpy(destination, source);
    return destination;
}

char ** create_string_array(int size) {
    char **strings = new char *[size];

    for (int i = 0; i < size; i++)
        strings[i] = nullptr;

    return strings;
}

void delete_string_array(char **&strings, int size) {

    if (strings == nullptr)
        return;

    // First release every individual string.

    for (int i = 0; i < size; i++) {

        delete[] strings[i];

        strings[i] = nullptr;
    }

    // Then release the array of pointers.

    delete[] strings;

    strings = nullptr;
}

void allocated_ptr(int *&ptr, int value) {
    ptr = new int;
    *ptr = value;
}

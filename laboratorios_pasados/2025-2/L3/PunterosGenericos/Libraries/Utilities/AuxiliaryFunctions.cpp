//
// Created by erasmo on 9/17/26.
//

#include "AuxiliaryFunctions.hpp"


void open_file_read(ifstream &input, const char *file_name) {
    //cout << file_name << endl;
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

char *read_str(ifstream &input_file, char delimiter) {
    char buffer[100];

    input_file.getline(buffer, 100, delimiter);
    if (input_file.eof()) return nullptr;

    char *string = new char[strlen(buffer) + 1];
    strcpy(string, buffer);
    return string;
}

int read_int(ifstream &input_file, bool read_del) {
    int number;
    input_file >> number;
    if (read_del) input_file.get();
    return number;
}

double read_double(ifstream &input_file, bool read_del) {
    double real;
    input_file >> real;
    if (read_del) input_file.get();
    return real;
}

bool read_bool(ifstream &input_file, bool read_del) {
    bool opt;
    input_file >> opt;
    if (read_del) input_file.get();
    return opt;
}

void print_line(ofstream &output_file, char character, int size) {
    for (int i = 0; i < size; i++)
        output_file.put(character);
    output_file << endl;
}

char *assign_str(const char *text) {
    char *copy = new char[strlen(text) + 1];
    strcpy(copy, text);
    return copy;
}
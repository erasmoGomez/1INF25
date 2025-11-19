#include <cstring>
#include "comunes.h"
#include <iostream>

using namespace std;

void *clone_string(void *pointer) {
    char *string = (char *) pointer;
    int lenght = strlen(string);
    char *new_string = new char[lenght + 1];
    strcpy(new_string, string);
    return new_string;
}

void *clone_int(void *pointer){
    int integer = *(int *) pointer;
    int *ptrInteger = new int;
    *ptrInteger = integer;
    return ptrInteger;
}

void *clone_real(void *pointer){
    double real = *(double *) pointer;
    double *ptrReal = new double;
    *ptrReal = real;
    return ptrReal;
}

void print_string(void *pointer) {
    char *string = (char *) pointer;
    cout << string;
}

void print_int(void *pointer) {
    int integer = *(int *) pointer;
    cout << integer;
}

void print_real(void *pointer) {
    double real = *(double *) pointer;
    cout << real;
}

bool compare_string(void *pointer_1, void *pointer_2) {
    char *string_1 = (char *) pointer_1;
    char *string_2 = (char *) pointer_2;
    return strcmp(string_1, string_2)==0;
}

bool compare_int(void *pointer_1, void *pointer_2) {
    int integer_1 = *(int *) pointer_1;
    int integer_2 = *(int *) pointer_2;
    return integer_1 == integer_2;
}

bool compare_real(void *pointer_1, void *pointer_2) {
    double real_1 = *(double *) pointer_1;
    double real_2 = *(double *) pointer_2;
    return real_1 == real_2;
}
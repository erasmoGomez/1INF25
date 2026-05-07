#ifndef CODIGO_COMUNES_H
#define CODIGO_COMUNES_H

void *clone_string(void *pointer);

void *clone_int(void *pointer);

void *clone_real(void *pointer);

void print_string(void *pointer);

void print_int(void *pointer);

void print_real(void *pointer);

bool compare_string(void *pointer_1, void *pointer_2);

bool compare_int(void *pointer_1, void *pointer_2);

bool compare_real(void *pointer_1, void *pointer_2);

#endif //CODIGO_COMUNES_H
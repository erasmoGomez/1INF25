#ifndef CODIGO_VECTOR_H
#define CODIGO_VECTOR_H

typedef struct {
    int size;
    void *front;
    void *back;
} list;

enum ListFields {
    DATA,
    NEXT,
};

void new_list(list &lst);

void push_front(list &lst, void *data, void *(*clone)(void *));

void push_back(list &lst, void *data, void *(*clone)(void *));

void *begin(list &lst);

void *end(list &lst);

void *next(void *it);

void *getValue(void *it);

void foreach(list &lst, void (*fun)(void *));

bool findIf(list &lst, bool (*compare_fun)(void *, void*), void *data);

#endif //CODIGO_VECTOR_H

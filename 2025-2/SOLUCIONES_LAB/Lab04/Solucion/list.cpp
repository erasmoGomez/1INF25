#include <iostream>
#include "list.h"

using namespace std;

void new_list(list &lst) {
    lst.size = 0;
    lst.front = nullptr;
    lst.back = nullptr;
}

void push_front(list &lst, void *data, void *(*clone)(void *)) {
    void **node = new void *[2]{};
    node[DATA] = clone(data);
    node[NEXT] = nullptr;

    if (lst.front == nullptr && lst.back == nullptr) {
        lst.front = node;
        lst.back = node;
    } else {
        node[NEXT] = lst.front;
        lst.front = node;
    }
    lst.size += 1;
}

void push_back(list &lst, void *data, void *(*clone)(void *)) {
    void **node = new void *[2]{};
    node[DATA] = clone(data);
    node[NEXT] = nullptr;

    if (lst.front == nullptr && lst.back == nullptr) {
        lst.front = node;
        lst.back = node;
    } else {
        void **back = (void **) lst.back;
        back[NEXT] = node;
        lst.back = node;
    }
    lst.size += 1;
}

void *begin(list &lst) {
    return lst.front;
}

void *end(list &lst) {
    return nullptr;
}

void *next(void *it) {
    void **node = (void **) it;
    return node[NEXT];
}

void *getValue(void *it) {
    void **node = (void **) it;
    return node[DATA];
}

void foreach(list &lst, void (*fun)(void *)) {
    for (void *it = begin(lst); it != end(lst); it = next(it)) {
        void *valor = getValue(it);
        fun(valor);
        if (next(it) != nullptr) {
            cout << ", ";
        }
    }
}

bool findIf(list &lst, bool (*compare_fun)(void *, void *), void *data) {
    for (void *it = begin(lst); it != end(lst); it = next(it)) {
        void *valor = getValue(it);
        if (compare_fun(valor, data)) {
            return true;
        }
    }
    return false;
}

//
// Created by erasmo on 5/5/26.
//

#include "BibliotecaGenerica.hpp"

void construir(void *&list) {
    void **lista = new void *[3]{};
    int *num = new int;
    *num = 0;
    lista[NUM_NODOS] = num;
    list = lista;
}

bool eslitavacia(void *list) {
    void **lista = (void **) list;
    return lista[INICIO] == nullptr and lista[FIN] == nullptr;
}

void creaDupla(void *&dup, void *dato) {
    void **arreglo = new void *[20]{};
    void **dupla = new void *[2]{};
    dupla[DATO] = dato;
    dupla[ARREGLO] = arreglo;
    dup = dupla;
}

void insertafinal(void *&list, void *dato) {
    void **lista = (void **) list;
    void **nodo = new void *[2]{};

    void *dupla, **ultimo;
    creaDupla(dupla, dato);
    nodo[DUPLA] = dupla;
    nodo[SIGUIENTE] = nullptr;

    if (eslitavacia(list)) {
        lista[INICIO] = nodo;
        lista[FIN] = nodo;
    } else {
        ultimo = (void **) lista[FIN];
        ultimo[SIGUIENTE] = nodo;
        lista[FIN] = nodo;
    }
    (*(int *) lista[NUM_NODOS])++;
}

void crealista(void *&lista, void *(*leenumeros)(ifstream &), const char *nomArch) {
    ifstream arch(nomArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el  archivo: " << nomArch << endl;
        exit(1);
    }
    void *dato;
    construir(lista);
    while (true) {
        dato = leenumeros(arch);
        if (arch.eof())break;
        insertafinal(lista, dato);
    }
}

void cargaArreglo(void *&arreglo, void *dato) {
    void **recorrido = (void **) arreglo;
    int pos = 0;
    while (recorrido[pos])pos++;
    if (pos < 20)recorrido[pos] = dato;
}

void cargaDupla(void *&lista, void *d, bool (*compruebanumero)(void *, void *)) {
    void **cabeza = (void **) lista;
    void **nodo = (void **) cabeza[INICIO];
    void **dato = (void **) d;
    // dato tiene en 0 tiene 6 y en 1 tiene 2;
    while (nodo) {
        void **dupla = (void **) nodo[DUPLA];
        void **datoDupla = (void **) dupla;
        if (compruebanumero(datoDupla[DATO], dato[0])) {
            cargaArreglo(datoDupla[ARREGLO], dato[1]);
        }
        nodo = (void **) nodo[SIGUIENTE];
    }
}

void cargalista(void *&lista, bool (*compruebanumero)(void *, void *), void *(*leeregnumeros)(ifstream &),
                const char *nomArch) {
    ifstream arch(nomArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el  archivo: " << nomArch << endl;
        exit(1);
    }
    void *dato;

    while (true) {
        dato = leeregnumeros(arch);
        if (arch.eof())break;
        cargaDupla(lista, dato, compruebanumero);
    }
}

void muestralista(void *lista, void (*imprimenumeros)(ofstream &, void *, void *), const char *nomArch) {
    ofstream arch(nomArch, ios::out);
    if (not arch.is_open()) {
        cout << "Error al abrir el  archivo: " << nomArch << endl;
        exit(1);
    }
    void **cabeza = (void **) lista;
    void **nodo = (void **) cabeza[INICIO];

    while (nodo) {
        void **dupla = (void **) nodo[DUPLA];
        void **datoDupla = (void **) dupla;
        imprimenumeros(arch, datoDupla[DATO], datoDupla[ARREGLO]);
        nodo = (void **) nodo[SIGUIENTE];
    }
}

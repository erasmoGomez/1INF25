#include "BibliotecaGenerica.hpp"

void insertalista(void *&lista, void *dato, int (*cmp)(void *, void *)) {
    void **nuevo, **ant = nullptr;
    void **ptr;

    void **recorrido = (void **) lista;
    nuevo = new void *[2];
    nuevo[DATO] = dato;
    nuevo[SIGUIENTE] = nullptr;
    ant = ptr;

    if (recorrido[INICIO] == nullptr)
        recorrido[INICIO] = nuevo;
    else {
        ptr = (void **) recorrido[INICIO];
        while (ptr) {
            if (cmp(ptr[DATO], dato) > 0)break;
            ant = ptr;
            ptr = (void **) ptr[SIGUIENTE];
        }
        nuevo[SIGUIENTE] = ptr;
        if (ant == nullptr) recorrido[INICIO] = nuevo;
        else {
            ant[SIGUIENTE] = nuevo;
        }
    }
}

void imprimelista(void *lista, void (*imprime)(ofstream &, void *),
                  const char *nombre) {
    void **llista = (void **) lista;
    void **aux = (void **) llista[0];
    ofstream arch(nombre, ios::out);
    if (!arch) {
        cout << "No se puede abrir Faltas";
        exit(1);
    }
    while (aux) {
        imprime(arch, aux[0]);
        aux = (void **) aux[1];
    }
}

void imprimelistaint(void *lista, void (*imprime)(ofstream &, void *),
                     ofstream &arch) {
    void **llista = (void **) lista;
    void **aux = (void **) llista[0];

    while (aux) {
        imprime(arch, aux[0]);
        aux = (void **) aux[1];
    }
}

void generaLista(void *&lista) {
    void **unico;
    unico = new void *;
    unico[INICIO] = nullptr;
    lista = unico;
}

void creaLista(void *&lista, void *(*lee)(ifstream &),
               int (*cmp)(void *, void *), void *(*busca)(void *, void *), const char *nombre) {
    void *dato;
    ifstream arch(nombre, ios::in);
    if (!arch) {
        cout << "No se puede abrir el archivo " << nombre;
        exit(1);
    }
    void *llista;
    while (true) {
        dato = lee(arch);
        if (dato == nullptr or arch.eof()) break;
        llista = busca(lista, dato);
        if (lista == llista)
            insertalista(lista, dato, cmp);
        else
            insertalista(llista, dato, cmp);
    }
}

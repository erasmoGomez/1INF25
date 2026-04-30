/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "ListaGenerica.hpp"

#include "Helpers.hpp"

void crear_lista(const char *nombre_archivo,
                 void *&lista,
                 void *(*leer)(ifstream &),
                 int (*compara)(const void *, const void *)) {
    ifstream input;
    apertura_archivo_entrada(input, nombre_archivo);
    lista = nullptr; //Importante inicializar lista
    while (true) {
        void *registro = leer(input);
        if (input.eof())break;
        insertar(registro, lista, compara);
    }
}

void insertar(void *registro, void *&lista,
              int (*compara)(const void *, const void *)) {
    //construir un NODO NUEVO
    void **nuevo = new void *[2];
    nuevo[DATO] = registro;
    nuevo[SIGUIENTE] = nullptr;
    //Algoritmo de insercion
    void **recorrido = (void **) lista;
    void **anterior = nullptr;

    while (recorrido != nullptr) {
        if (compara(recorrido[DATO], registro) > 0)break;
        anterior = recorrido;
        recorrido = (void **) recorrido[SIGUIENTE];
    }
    nuevo[SIGUIENTE] = recorrido;
    if (anterior == nullptr)
        lista = nuevo;
    else
        anterior[SIGUIENTE] = nuevo;
}

void imprimir_lista(const char* nombre_archivo, void *lista, void (*imprime)(void *, ofstream&)) {
    ofstream output;
    apertura_archivo_salida(output, nombre_archivo);
    void **recorrido = (void **) lista;
    while (recorrido) {
        imprime(recorrido[DATO], output);
        recorrido = (void **) recorrido[SIGUIENTE];
    }
    cout << endl;
}

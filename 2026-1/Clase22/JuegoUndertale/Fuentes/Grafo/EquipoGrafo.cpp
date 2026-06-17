//
// Created by erasmo on 6/10/26.
//

#include "EquipoGrafo.hpp"

EquipoGrafo::EquipoGrafo() {
    vertices = nullptr;
    cantidad_vertices = 0;
}

EquipoGrafo::~EquipoGrafo() {
}

NodoVertice *EquipoGrafo::buscarVertice(const Personaje &p) {
    for (int i = 0; i < cantidad_vertices; i++)
        if (vertices[i]->dato == p) // Sobrecarga
            return vertices[i];

    return nullptr;
}

void EquipoGrafo::insertarVertice(const Personaje &p) {
    if (buscarVertice(p) != nullptr)
        return;

    NodoVertice *nuevo = new NodoVertice;

    nuevo->dato = p;
    nuevo->adyacentes = nullptr;
    nuevo->cantidad_adyacentes = 0;

    NodoVertice **aux = new NodoVertice *[cantidad_vertices + 1];

    for (int i = 0; i < cantidad_vertices; i++)
        aux[i] = vertices[i];

    aux[cantidad_vertices] = nuevo;

    delete [] vertices;

    vertices = aux;
    cantidad_vertices++;
}

void EquipoGrafo::insertarArista( const Personaje &origen, const Personaje &destino) {
    NodoVertice *vOrigen = buscarVertice(origen);

    NodoVertice *vDestino = buscarVertice(destino);

    if (vOrigen == nullptr or vDestino == nullptr)
        return;

    NodoVertice **aux = new NodoVertice *[vOrigen->cantidad_adyacentes + 1];

    for (int i = 0; i < vOrigen->cantidad_adyacentes; i++)
        aux[i] = vOrigen->adyacentes[i];

    aux[vOrigen->cantidad_adyacentes] = vDestino;

    delete [] vOrigen->adyacentes;

    vOrigen->adyacentes = aux;

    vOrigen->cantidad_adyacentes++;
}

void EquipoGrafo::imprimir() {
    cout << cantidad_vertices << endl;
    for (int i = 0; i < cantidad_vertices; i++) {
        cout << vertices[i]->dato;

        cout << "\t\t";

        for (int j = 0; j < vertices[i]->cantidad_adyacentes;j++) {
            cout << vertices[i]->adyacentes[j]->dato;

            cout << "\t\t";
        }

        cout << endl;
    }
}

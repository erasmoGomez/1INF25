//
// Created by Erasmo on 4/11/25.
//

#ifndef PLANTILLAS_PLANTILLA_HPP
#define PLANTILLAS_PLANTILLA_HPP

#include "Utils.hpp"

template<typename T>
class Plantilla {
private:
    T dato;
public:
    void SetDato(T dato);

    T GetDato();

    void leer();

    void imprimir();
};

//SetDato
template<typename T>
void Plantilla<T>::SetDato(T dato) {
    this->dato = dato;
}

//GetDato
template<typename T>
T Plantilla<T>::GetDato() {
    return dato;
}

//Leer
template<typename T>
void Plantilla<T>::leer() {
    cin >> dato;
}

//Imprimir
template<typename T>
void Plantilla<T>::imprimir() {
    cout << dato << endl;
}

#endif //PLANTILLAS_PLANTILLA_HPP

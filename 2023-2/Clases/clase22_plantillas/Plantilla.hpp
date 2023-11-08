/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Plantilla.hpp
 * Author: ASUS
 *
 * Created on November 7, 2023, 7:25 AM
 */

#ifndef PLANTILLA_HPP
#define PLANTILLA_HPP
#include "utils.hpp"
using namespace std;

template <typename T>
class Plantilla {
private:
    T dato;
public:
    plantilla();
    void SetDato(const T &dato);
    T GetDato()const;
    void leer_dato();
    void imprimir_dato();

};

template <typename T>
void Plantilla<T>::SetDato(const T &dato) {
    this->dato = dato;
}

template <typename T>
T Plantilla<T>::GetDato() const {
    return dato;
}

template <typename T>
void Plantilla<T>::leer_dato() {
    cin>>dato;
}

template <typename T>
void Plantilla<T>::imprimir_dato() {
    cout<<dato<<endl;
}
#endif /* PLANTILLA_HPP */


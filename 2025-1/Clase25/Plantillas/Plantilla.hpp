/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Plantilla.hpp
 * Author: hecto
 *
 * Created on June 11, 2025, 4:34 PM
 */

#ifndef PLANTILLA_HPP
#define PLANTILLA_HPP
#include "Utils.hpp"

template <typename T>
class Plantilla{
    private:
        T dato;
    public:
        void SetDato(T dato);
        T GetDato();
        void leer();
        void imprimir();      
};

//SetDato
template <typename T>
void Plantilla<T>::SetDato(T dato){
    this->dato = dato;
}

//GetDato
template <typename T>
T Plantilla<T>::GetDato(){
    return dato;
}

//Leer
template <typename T>
void Plantilla<T>::leer(){
    cin>>dato;
}

//Leer
template <typename T>
void Plantilla<T>::imprimir(){
    cout<<dato<<endl;
}

#endif /* PLANTILLA_HPP */


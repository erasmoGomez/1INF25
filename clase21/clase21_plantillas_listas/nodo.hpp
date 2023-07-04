/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   nodo.hpp
 * Author: erasmog
 *
 * Created on June 27, 2023, 9:06 PM
 */

#ifndef NODO_HPP
#define NODO_HPP
#include "lista.hpp"

template<typename T>class Lista;

template<typename T>
class Nodo {
private:
    T dato;
    class Nodo<T> *sig;
public:

    Nodo() {sig = nullptr;}
    friend class Lista<T>;
};

#endif /* NODO_HPP */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.hpp
 * Author: ASUS
 *
 * Created on October 31, 2023, 8:57 AM
 */

#ifndef LISTA_HPP
#define LISTA_HPP
#include "utils.hpp"
#include "Node.hpp"
class Lista {
public:
    Lista();
    Lista(const Lista& orig);
    virtual ~Lista();
    void crear();
    void insertar_elemento(const class hero &);
    void imprimir();
    void imprimir_recursivo();
private:
    class Node *lista;
    void imprime_recursivo(ofstream &, class Node*); //Metodo recursiuvo privado
};

#endif /* LISTA_HPP */


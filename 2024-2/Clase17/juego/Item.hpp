/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Item.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on October 22, 2024, 6:12 PM
 */

#ifndef ITEM_HPP
#define ITEM_HPP
#include "Utils.hpp"
using namespace std;
class Item {
public:
    Item();
    virtual ~Item();
    void SetDescripcion(const char* descripcion);
    void GetDescripcion(char*) const;
    void SetNombre(const char* nombre);
    void GetNombre(char*) const;
    void mostrar();
    void leer(ifstream &);
private:
    char* nombre;
    char* descripcion;
};

#endif /* ITEM_HPP */


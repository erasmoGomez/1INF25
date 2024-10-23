/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Item.hpp
 * Author: ASUS
 *
 * Created on May 22, 2024, 7:40 AM
 */

#ifndef ITEM_HPP
#define ITEM_HPP
#include "Utils.hpp"
using namespace std;
class Item{
private:
    char* nombre;
    char* descripcion;
public:
    Item();
    virtual ~Item();
    void SetDescripcion(const char* descripcion);
    void GetDescripcion(char*) const;
    void SetNombre(const char* nombre);
    void GetNombre(char*) const;
    void mostrar();
    void leer(ifstream &);
};

#endif /* ITEM_HPP */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Item.hpp
 * Author: hecto
 *
 * Created on May 14, 2025, 5:37 PM
 */

#ifndef ITEM_HPP
#define ITEM_HPP
#include "utils.hpp"
class Item {
public:
    Item();
    Item(const Item& orig);
    virtual ~Item();
    void SetNombre(const char* nombre);
    void GetNombre(char* nombre) const;
    void SetDescripcion(const char* descripcion);
    void GetDescripcion(char* descripcion) const;
    
private:
    char* descripcion;
    char* nombre;
};

#endif /* ITEM_HPP */


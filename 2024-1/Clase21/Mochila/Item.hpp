/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Item.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on May 27, 2024, 5:38 PM
 */

#ifndef ITEM_HPP
#define ITEM_HPP
#include "Utils.hpp"
using namespace std;
class Item {
public:
    
    Item();
    Item(const Item& orig);
    virtual ~Item();
    void SetEquipadoQ(bool equipadoQ);
    bool GetEquipadoQ() const;
    void SetDescripcion(const char* );
    void GetDescripcion(char *) const;
    void SetNombre(const char* );
    void GetNombre(char *) const;
    void leer(ifstream&);
    void mostrar(ofstream &);
private:
    char* nombre;
    char* descripcion;
    bool equipadoQ;
};

#endif /* ITEM_HPP */


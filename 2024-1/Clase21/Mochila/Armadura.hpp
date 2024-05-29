/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Armadura.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on May 27, 2024, 5:41 PM
 */

#ifndef ARMADURA_HPP
#define ARMADURA_HPP
#include "Item.hpp"
class Armadura:public Item {
public:
    Armadura();
    Armadura(const Armadura& orig);
    virtual ~Armadura();
    void SetModificador_def(int modificador_def);
    int GetModificador_def() const;
    void leer(ifstream &);
private:
    int modificador_def;
};

#endif /* ARMADURA_HPP */


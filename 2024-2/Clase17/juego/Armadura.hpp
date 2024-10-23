/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Armadura.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on October 22, 2024, 6:12 PM
 */

#ifndef ARMADURA_HPP
#define ARMADURA_HPP
#include "Utils.hpp"
#include "Item.hpp"
using namespace std;

class Armadura: public Item {
public:
    Armadura();
    Armadura(const Armadura& orig);
    virtual ~Armadura();
    void SetModificador_defensa(int modificador_defensa);
    int GetModificador_defensa() const;
    void leer(ifstream&);
private:
    int modificador_defensa;
};

#endif /* ARMADURA_HPP */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClaseDerivada.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on May 29, 2024, 8:26 AM
 */

#ifndef CLASEDERIVADA_HPP
#define CLASEDERIVADA_HPP
#include "ClaseBase.hpp"
class ClaseDerivada : public ClaseBase{
public:
    ClaseDerivada();
    ClaseDerivada(const ClaseDerivada& orig);
    virtual ~ClaseDerivada();
    void SetD(int d);
    int GetD() const;
    void mostrar();
private:
    int d;

};

#endif /* CLASEDERIVADA_HPP */


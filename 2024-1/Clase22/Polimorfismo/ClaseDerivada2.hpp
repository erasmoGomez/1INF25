/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClaseDerivada2.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on May 29, 2024, 8:27 AM
 */

#ifndef CLASEDERIVADA2_HPP
#define CLASEDERIVADA2_HPP
#include "ClaseBase.hpp"

class ClaseDerivada2 : public ClaseBase {
public:
    ClaseDerivada2();
    ClaseDerivada2(const ClaseDerivada2& orig);
    virtual ~ClaseDerivada2();
    void SetD2(int d2);
    int GetD2() const;
    void mostrar();
private:
    int d2;
};

#endif /* CLASEDERIVADA2_HPP */


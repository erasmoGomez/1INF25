/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClaseBase.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on May 29, 2024, 8:24 AM
 */

#ifndef CLASEBASE_HPP
#define CLASEBASE_HPP

class ClaseBase {
public:
    ClaseBase();
    ClaseBase(const ClaseBase& orig);
    virtual ~ClaseBase();
    void SetB(int b);
    int GetB() const;
    virtual void mostrar() = 0; //2. Metodo polimorficos ... Si le pongo = 0 se convierte en método ABSTRACTO
private:
    int b;
};

#endif /* CLASEBASE_HPP */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ficha.hpp
 * Author: erasmog
 *
 * Created on June 14, 2023, 10:45 PM
 */

#ifndef FICHA_HPP
#define FICHA_HPP
#include <fstream>
using namespace std;

class Ficha {
private:
    char * id;
    int fil;
    int col;
public:
    Ficha();
    virtual ~Ficha();
    void SetCol(int col);
    int GetCol() const;
    void SetFil(int fil);
    int GetFil() const;
    void SetId(const char* );
    void GetId(char *) const;
    void asigna(char*, int, int);
    virtual void imprime(ofstream &) = 0;
    virtual void mover(char, int) = 0;
};

#endif /* FICHA_HPP */


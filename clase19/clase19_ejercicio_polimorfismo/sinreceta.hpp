/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sinreceta.hpp
 * Author: erasmog
 *
 * Created on June 20, 2023, 9:23 PM
 */

#ifndef SINRECETA_HPP
#define SINRECETA_HPP
#include "medicamento.hpp"

class SinReceta:public Medicamento{
private:
    int dni;
    char* nombreP;
public:
    SinReceta();
    SinReceta(const SinReceta&);
    virtual ~SinReceta();
    void SetNombreP(char*);
    void GetNombreP(char*);
    void SetDni(int);
    int GetDni() const;
    void lee_medicamento(int, int, char*);
    void imprime_medicamento(ofstream&);
};


#endif /* SINRECETA_HPP */


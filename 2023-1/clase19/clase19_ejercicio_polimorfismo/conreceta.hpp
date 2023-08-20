/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   conreceta.hpp
 * Author: erasmog
 *
 * Created on June 20, 2023, 9:19 PM
 */

#ifndef CONRECETA_HPP
#define CONRECETA_HPP
#include "medicamento.hpp"

class ConReceta:public Medicamento{
private:
    int codmed;
    char* especialidad;
public:
    ConReceta();
    ConReceta(const ConReceta& );
    virtual ~ConReceta();
    void SetEspecialidad(char* );
    void GetEspecialidad(char* );
    void SetCodMed(int );
    int GetCodMed() const;
    void lee_medicamento(int, int, char*);
    void imprime_medicamento(ofstream&);
};
#endif /* CONRECETA_HPP */


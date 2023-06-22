/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   oferta.hpp
 * Author: erasmog
 *
 * Created on June 20, 2023, 9:25 PM
 */

#ifndef OFERTA_HPP
#define OFERTA_HPP
#include <fstream>
#include <iostream>
#include <iomanip>
#include "medicamento.hpp"
#include "sinreceta.hpp"
#include "conreceta.hpp"
using namespace std;

class Oferta{
private:
    class Medicamento *poferta;
public:
        Oferta();
        Oferta(const Oferta& orig);
        virtual ~Oferta();
        void SetPoferta(Medicamento*);
        Medicamento* GetPoferta() const;
        void operator=(class Medicamento *);
        bool operator!=(class Medicamento *);
        void obtener_especialidad_medico(int, char*);
        void asigna_medicamento(ifstream &);
        void imprime_medicamento(ofstream&);
};


#endif /* OFERTA_HPP */


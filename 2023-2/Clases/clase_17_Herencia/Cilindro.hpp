/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cilindro.hpp
 * Author: ASUS
 *
 * Created on October 17, 2023, 9:25 AM
 */

#ifndef CILINDRO_HPP
#define CILINDRO_HPP
#include "circulo.hpp"

class Cilindro: public Circulo {
public:
    Cilindro();
    Cilindro(const Cilindro& orig);
    virtual ~Cilindro();
    void SetAltura(double);
    double GetAltura() const;
    double Volumen();
    double Area_Superficie();
    void MostrarResultados();
    
private:
    double altura;
};

#endif /* CILINDRO_HPP */


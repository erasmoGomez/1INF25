/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   circulo.hpp
 * Author: ASUS
 *
 * Created on October 17, 2023, 9:14 AM
 */

#ifndef CIRCULO_HPP
#define CIRCULO_HPP

class Circulo {
public:
    Circulo();
    Circulo(const Circulo& orig);
    virtual ~Circulo();
    void SetRadio(double);
    double GetRadio();
    double Area();
    double Circunferencia();
    void MostrarResultados();
private:
    double radio;

};

#endif /* CIRCULO_HPP */


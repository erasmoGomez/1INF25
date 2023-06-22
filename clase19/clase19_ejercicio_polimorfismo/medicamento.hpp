/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   medicamento.hpp
 * Author: erasmog
 *
 * Created on June 20, 2023, 9:04 PM
 */

#ifndef MEDICAMENTO_HPP
#define MEDICAMENTO_HPP
#include <fstream>
using namespace std;

class Medicamento{
private:
    int codigo;
    char * nombre;
    int cantidad;
    double precio;
    int fecha;
    double total;
public:
    Medicamento();
    virtual ~Medicamento();
    void SetTotal(double total);
    double GetTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetNombre(const char* nombre);
    void GetNombre(char* nombre) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    virtual void lee_medicamento(int, int, char*);
    virtual void imprime_medicamento(ofstream&);
    void separa_fecha(int, int&, int&, int&);
};

#endif /* MEDICAMENTO_HPP */


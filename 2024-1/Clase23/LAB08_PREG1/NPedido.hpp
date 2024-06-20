/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NPedido.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on June 12, 2024, 7:22 AM
 */

#ifndef NPEDIDO_HPP
#define NPEDIDO_HPP
#include "Vehiculo.hpp"
class NPedido {
public:
    NPedido();
    NPedido(const NPedido& orig);
    virtual ~NPedido();
    friend class Vehiculo;
    void getCodigo(char *codigo) const;
    void setCodigo(const char *codigo);
private:
    char* codigo;
    int cantidad;
    double peso;
    class NPedido* sig;
};

#endif /* NPEDIDO_HPP */


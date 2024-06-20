/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NPedido.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on June 12, 2024, 7:22 AM
 */

#include "NPedido.hpp"
#include "Utils.hpp"
using namespace std;
NPedido::NPedido() {
    codigo = nullptr;
    cantidad = 0;
    peso = 0.0;
    sig = nullptr;
}

NPedido::NPedido(const NPedido& orig) {
}

NPedido::~NPedido() {
}

void NPedido::getCodigo(char *codigo) const {
    if(this->codigo== nullptr) codigo[0] = 0;
    else strcpy(codigo,this->codigo);
}

void NPedido::setCodigo(const char *codigo) {
    if(this->codigo!= nullptr) delete this->codigo;
    this->codigo = new char[strlen(codigo)+1];
    strcpy(this->codigo, codigo);
}
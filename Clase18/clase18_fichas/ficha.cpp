/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <cstring>
#include "ficha.hpp"

Ficha::Ficha(){
    id = nullptr;
}

void Ficha::SetCol(int col) {
    this->col = col;
}

int Ficha::GetCol() const {
    return col;
}

void Ficha::SetFil(int fil) {
    this->fil = fil;
}

int Ficha::GetFil() const {
    return fil;
}

void Ficha::SetId(const char* cad) {
    if(id!=nullptr) delete id;
    id = new char[strlen(cad)+1];
    strcpy(id,cad);
}

void Ficha::GetId(char* cad) const {
    if(id==nullptr) cad[0] = '\0';
    else strcpy(cad,this->id);
}

void Ficha::asigna(char* ident, int f, int c){
    SetId(ident);
    SetFil(f);
    SetCol(c);
}
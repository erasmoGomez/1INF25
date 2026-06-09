//
// Created by USUARIO on 3/06/2026.
//

#include "Espacio.hpp"

Espacio::Espacio(){
    inicializar();
}

Espacio::Espacio(const class Espacio& espacio){
    inicializar();
    *this = espacio;
}

char Espacio::get_contenido() const{
    return contenido;
}

void Espacio::set_contenido(char contenido){
    this->contenido = contenido;
}

int Espacio::get_posx() const{
    return posx;
}

void Espacio::set_posx(int posx){
    this->posx = posx;
}

int Espacio::get_posy() const{
    return posy;
}

void Espacio::set_posy(int posy){
    this->posy = posy;
}

void Espacio::inicializar(){
    contenido = ' ';
    posx = 0;
    posy = 0;
}

Espacio& Espacio::operator=(const Espacio& espacio){
    if (this !=&espacio){
        set_contenido(espacio.get_contenido());
        set_posx(espacio.get_posx());
    }
    return *this;
}




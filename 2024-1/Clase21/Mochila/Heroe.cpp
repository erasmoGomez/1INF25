/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Heroe.hpp"
Heroe::Heroe(){
    nombre = nullptr;
}

void Heroe::setDefensa(int defensa) {
    this->defensa = defensa;
}

int Heroe::getDefensa() const {
    return defensa;
}

void Heroe::setAtaque(int ataque) {
    this->ataque = ataque;
}

int Heroe::getAtaque() const {
    return ataque;
}

void Heroe::setVida(int vida) {
    this->vida = vida;
}

int Heroe::getVida() const {
    return vida;
}

void Heroe::setNombre(const char* nombre) {
    if(this->nombre!=nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Heroe::getNombre(char *nombre) const {
    if(this->nombre==nullptr) nombre[0] = 0;
    else strcpy(nombre, this->nombre);
}

void Heroe::agregar_mochila(ifstream& input_items, char *tipo){
    mochila.agregar_item(input_items, tipo);
}

//HEROE -> Mochila -> CONSUMIBLE
//CONSUMIBLE -> HEROE
void Heroe::equipar(const char*tipo, const char*nombre){
    int valor_incrementar = 0;
    if(strcmp(tipo, "Consumable")==0){
        valor_incrementar = mochila.buscar_consumible(nombre);
        if(valor_incrementar!=-1)
            vida += valor_incrementar;
    }
    if(strcmp(tipo, "Weapon")==0){
        valor_incrementar = mochila.buscar_arma(nombre);
        if(valor_incrementar!=-1)
            ataque += valor_incrementar;
    }
    if(strcmp(tipo, "Armor")==0){
        valor_incrementar = mochila.buscar_armadura(nombre);
        if(valor_incrementar!=-1)
            defensa += valor_incrementar;
    }
}

void Heroe::mostrar(ofstream&out){
    char *nombre;
    int vida;
    int ataque;
    int defensa;
    out<<"Nombre: "<<nombre<<endl;
    out<<"Vida: "<<vida<<endl;
    out<<"Ataque: "<<ataque<<endl;
    out<<"Defensa: "<<defensa<<endl;
    mochila.mostrar(out);
}

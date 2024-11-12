/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Heroe.hpp"

Heroe::Heroe() {
    nombre = nullptr;
    hp = 0;
    ataque = 0;
    defensa = 0;
}

void Heroe::setPosy(int posy) {
    this->posy = posy;
}

int Heroe::getPosy() const {
    return posy;
}

void Heroe::setPosx(int posx) {
    this->posx = posx;
}

int Heroe::getPosx() const {
    return posx;
}

void Heroe::setMana(double mana) {
    this->mana = mana;
}

double Heroe::getMana() const {
    return mana;
}

void Heroe::setHp(int hp) {
    this->hp = hp;
}

int Heroe::getHp() const {
    return hp;
}

void Heroe::setNombre(const char* nombre) {
    if(this->nombre!=nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Heroe::getNombre(char* nombre) const {
    if(this->nombre==nullptr) nombre[0] = 0;
    else strcpy(nombre, this->nombre);
}

void Heroe::leer(ifstream &input){
    char buffer[20],extra;
    //Teemo,500, 25.3, 15, 15, 100, 100
    input.getline(buffer, 20, ',');
    input>>hp>>extra;
    input>>mana>>extra;
    input>>posx>>extra;
    input>>posy>>extra;
    input>>ataque>>extra;
    input>>defensa;
    input.get();
    setNombre(buffer);
}

void Heroe::mostrar(){
    cout<<"Nombre: " << nombre<<endl;
    cout<<"Vida: " << hp<<endl;
    cout<<"Ataque: " << ataque<<endl;
    cout<<"Defensa: " << defensa<<endl;
    //mochila.mostrar();
    mochila.mostrar_items();
}

void Heroe::operator++(int){
    //W
    //setPosx(this->posx-1);
    setPosx(posx-1);
    //setPosx(getPosx()-1);
}

void Heroe::operator++(){
    //S
    setPosx(posx+1);
}

void Heroe::operator--(int){
    //D
    setPosy(posy+1);
}

void Heroe::operator--(){
    //A
    setPosy(posy-1);
}

void Heroe::agregar_mochila(ifstream& input, char* tipo){
    //Heroe- Mochila- Item - Consumible/Armadura/Arma
    //mochila.agregar_item(input, tipo);
    mochila.cargar_items(input, tipo);
}

void Heroe::equipar(const char* nombre_item, const char* tipo){
    int valor_incrementar = 0;
    if(strcmp(tipo, "Consumable")==0){
        valor_incrementar = mochila.buscar_consumible(nombre_item);
        if(valor_incrementar != -1)
            hp += valor_incrementar;
    }
    if(strcmp(tipo, "Weapon")==0){
        valor_incrementar = mochila.buscar_arma(nombre_item);
        if(valor_incrementar != -1)
            ataque += valor_incrementar;
    }
    if(strcmp(tipo, "Armor")==0){
        valor_incrementar = mochila.buscar_armadura(nombre_item);
        if(valor_incrementar != -1)
            defensa += valor_incrementar;
    }
}

void Heroe::equipar(int indice_item, const char* tipo){
    int valor_incrementar = 0;
    if(strcmp(tipo, "Consumable")==0){
        valor_incrementar = mochila.buscar_consumible(indice_item);
        if(valor_incrementar != -1)
            hp += valor_incrementar;
    }
    if(strcmp(tipo, "Weapon")==0){
        valor_incrementar = mochila.buscar_arma(indice_item);
        if(valor_incrementar != -1)
            ataque += valor_incrementar;
    }
    if(strcmp(tipo, "Armor")==0){
        valor_incrementar = mochila.buscar_armadura(indice_item);
        if(valor_incrementar != -1)
            defensa += valor_incrementar;
    }
}


void Heroe::equipar_item(const char* nombre, int opt){
    int valor_incrementar = mochila.buscar_item(nombre);
    if (valor_incrementar == -1){
        cout<<"No se encontro el item a equipar"<<endl;
        return;
    }
    
    if(opt == 0)
        hp += valor_incrementar;
    if(opt == 1)
        ataque += valor_incrementar;
    if(opt == 2)
        defensa += valor_incrementar;
}

void operator>>(ifstream& input, Heroe& h){
    h.leer(input);
}
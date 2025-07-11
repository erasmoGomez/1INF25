/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Heroe.cpp
 * Author: hecto
 * 
 * Created on May 6, 2025, 5:55 PM
 */

#include "Heroe.hpp"

Heroe::Heroe() {
    //cout << "Constructor por Defecto" << endl;
    hp = 100;
    id = nullptr;
    nombre = nullptr;
    posX = 0;
    posY = 0;
    kills = 0;
}

Heroe::Heroe(int hp, double fuerza, double defensa) {
    //cout << "Constructor por Parametros" << endl;
    this->hp = hp;
    this->fuerza = fuerza;
    this->defensa = defensa;
}

Heroe::Heroe(const Heroe& orig) {
    nombre = nullptr;
    *this = orig; //Esto llama a la sobrecarga del operador =
}
//
//Heroe::~Heroe() {
//}

void Heroe::dibujar_barra(int valor, int max_valor, const char* etiqueta, ofstream& output) const {
    const int ancho_barra = 20;
    int cantidad = (valor * ancho_barra) / max_valor;

    output << etiqueta << ": [";
    for (int i = 0; i < ancho_barra; ++i) {
        if (i < cantidad) output << "#";
        else output << " ";
    }
    output << "] " << valor << "/" << max_valor << endl;
}

void Heroe::dibujar_barra(int valor, int max_valor, const char* etiqueta, ostream& output) const {
    const int ancho_barra = 20;
    int cantidad = (valor * ancho_barra) / max_valor;

    output << etiqueta << ": [";
    for (int i = 0; i < ancho_barra; ++i) {
        if (i < cantidad) output << "#";
        else output << " ";
    }
    output << "] " << valor << "/" << max_valor << endl;
}

void Heroe::mostrar_heroe(ofstream &output) const {
    const int ancho_barra = 20;

    output << "===============================" << endl;
    output << "|         HEROE FICHA         |" << endl;
    output << "===============================" << endl;
    output << "Nombre : " << nombre << endl;
    output << "ID     : " << id << endl;
    output << "Posición: (" << posX << ", " << posY << ")" << endl;
    output << "-------------------------------" << endl;
    dibujar_barra(hp, 100, "HP     ", output);
    dibujar_barra(fuerza, 20, "Fuerza ", output);
    dibujar_barra(defensa, 20, "Defensa", output);
    output << "===============================" << endl;
}

void Heroe::mostrar_heroe(ostream &output) const {
    const int ancho_barra = 20;

    output << "===============================" << endl;
    output << "|         HEROE FICHA         |" << endl;
    output << "===============================" << endl;
    output << "Nombre : " << nombre << endl;
    output << "ID     : " << id << endl;
    output << "Posición: (" << posX << ", " << posY << ")" << endl;
    output << "-------------------------------" << endl;
    dibujar_barra(hp, 100, "HP     ", output);
    dibujar_barra(fuerza, 20, "Fuerza ", output);
    dibujar_barra(defensa, 20, "Defensa", output);
    output << "===============================" << endl;
    inventario.mostrar_items(output);
}

void Heroe::setPosY(int posY) {
    this->posY = posY;
}

int Heroe::getPosY() const {
    return posY;
}

void Heroe::setPosX(int posX) {
    this->posX = posX;
}

int Heroe::getPosX() const {
    return posX;
}

void Heroe::setDefensa(double defensa) {
    this->defensa = defensa;
}

double Heroe::getDefensa() const {
    return defensa;
}

void Heroe::setFuerza(double fuerza) {
    this->fuerza = fuerza;
}

double Heroe::getFuerza() const {
    return fuerza;
}

void Heroe::setHp(int hp) {
    this->hp = hp;
}

int Heroe::getHp() const {
    return hp;
}

void Heroe::setNombre(const char* nombre) {
    if (this->nombre != nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

void Heroe::getNombre(char* nombre) const {
    if (this->nombre == nullptr) nombre[0] = '\0';
    else strcpy(nombre, this->nombre);
}

void Heroe::setId(const char* id) {
    if (this->id != nullptr) delete this->id;
    this->id = new char[strlen(id) + 1];
    strcpy(this->id, id);
}

void Heroe::getId(char* id) const {
    if (this->id == nullptr) id[0] = '\0';
    else strcpy(id, this->id);
}

void Heroe::cargar_info(ifstream& input) {
    //H001,Ayla,100,15,5,1,0
    char buffer[20];
    input.getline(buffer, 20, ',');
    setId(buffer);
    input.getline(buffer, 20, ',');
    setNombre(buffer);
    input>>hp;
    input.get();
    input>>fuerza;
    input.get();
    input>>defensa;
    input.get();
    input>>posX;
    input.get();
    input>>posY;
    input.get();
}

void Heroe::mostrar_info(ofstream&output) {
    this->mostrar_heroe(output);
}

bool Heroe::mover(char mov, Mapa &mapa) {
    int nuevoX = posX, nuevoY = posY;
    if (mov == 'W') nuevoX -= 1;
    if (mov == 'S') nuevoX += 1;
    if (mov == 'D') nuevoY += 1;
    if (mov == 'A') nuevoY -= 1;
    //NUEVOX NUEVOY
    if (mapa.dentro(nuevoX, nuevoY) and mapa.es_transitable(nuevoX, nuevoY)) return true;
    return false;
}

void Heroe::agregar_inventario(ifstream &input, char*tipo) {
    inventario.cargar_items(input, tipo);
}

void Heroe::operator++() {
    //w
    setPosX(posX - 1);
}

void Heroe::operator++(int) {
    //S
    setPosX(posX + 1);
}

void Heroe::operator--() {
    //D
    setPosY(posY + 1);
}

void Heroe::operator--(int) {
    //A
    setPosY(posY - 1);
}

void Heroe::operator = (const Heroe& h){
    //Priorizar los char*
    char _nombre[60];
    char _id[10];
    hp = h.getHp();
    fuerza = h.getFuerza();
    defensa = h.getDefensa();
    h.getNombre(_nombre); //Aca sacamos una copia de la cadena
    setNombre(_nombre);
    h.getId(_id);
    setId(_id);
    posX = h.getPosX();
    posY = h.getPosY();
}

bool Heroe::operator >(const class Heroe& h){
    char _nombre[60];
    h.getNombre(_nombre);
    return strcmp(nombre, _nombre)>0;
}

void Heroe::setKills(int kills) {
    this->kills = kills;
}

int Heroe::getKills() const {
    return kills;
}

//void Heroe::equipar(const char* nombre_item, int ventana) {
//    int modificador = 0; //Esto es lo que voy a traer desde las clases intermedias.
//
//    switch (ventana) {
//        case 0:
//            modificador = inventario.equipar_consumible(nombre_item);
//            hp += modificador;
//            break;
//        case 1:
//            modificador = inventario.equipar_arma(nombre_item);
//            fuerza += modificador;
//            break;
//        case 2:
//            modificador = inventario.equipar_armadura(nombre_item);
//            defensa += modificador;
//            break;
//        default:
//            break;
//    }
//}

void Heroe::equipar(const char* nombre_item, int tipo) {
    //Necesito sacar el valor a incrementar;
    //0 Consumibles , 1 Armas, 2 Armaduras
    //Heroe -> Inventario -> Item -> Arma/Armadura/Consumible
    int valor_incrementar = inventario.buscar_item(nombre_item);
    if (valor_incrementar == -1) {
        cout<<"No se encontro el Item"<<endl;
        return;
    }
    if(tipo == 0) hp += valor_incrementar;
    if(tipo == 1) fuerza += valor_incrementar;
    if(tipo == 2) defensa += valor_incrementar;
}

void operator<<(ostream& output, const class Heroe& h) {
    h.mostrar_heroe(output);
}

void operator<<(ofstream& output, const class Heroe& h) {
    h.mostrar_heroe(output);
}

void operator>>(ifstream& input, class Heroe& h) {
    h.cargar_info(input);
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Personaje.cpp
 * Author: hecto
 * 
 * Created on May 30, 2025, 5:20 AM
 */

#include "Personaje.hpp"

Personaje::Personaje(const char* nombre_in, int nivel_in) {
    nombre = new char[strlen(nombre_in) + 1];
    strcpy(nombre, nombre_in);
    nivel = nivel_in;
}

Personaje::Personaje() {
    nombre = nullptr;
}

Personaje::Personaje(const Personaje& otro) {
    cout<<"Constructor Copia Personaje"<<endl;
    //delete[]nombre;
    nombre = new char[strlen(otro.nombre) + 1];
    strcpy(nombre, otro.nombre);
    nivel = otro.nivel;
}

Personaje::~Personaje() {
    delete[] nombre;
}

void Personaje::mostrar() const {
    std::cout << "Nombre: " << nombre << ", Nivel: " << nivel << std::endl;
}

void Personaje::setNivel(int nivel) {
    this->nivel = nivel;
}

int Personaje::getNivel() const {
    return nivel;
}

void Personaje::setNombre(const char* nombre) {
    if (this->nombre != nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

void Personaje::getNombre(char* nombre) const {
    if (this->nombre == nullptr) nombre[0] = '\0';
    else strcpy(nombre, this->nombre);
}

void Personaje::operator=(const Personaje& otro) {
    if (this != &otro) {
        cout<<"Sobrecarga Operador ="<<endl;
        delete[] nombre;
        nombre = new char[strlen(otro.nombre) + 1];
        strcpy(nombre, otro.nombre);
        nivel = otro.nivel;
    }
}

void Personaje::leer(ifstream& input){
    //Mago,Gandalf,85,120
    char buffer[20];
    input.getline(buffer, 20,',');
    setNombre(buffer);
    setNivel(1);
}

void Personaje::realizar_accion(){
    
}

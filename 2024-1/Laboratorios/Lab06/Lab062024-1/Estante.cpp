/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estante.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on May 23, 2024, 10:18 PM
 */

#include "Estante.hpp"

Estante::Estante() {
    codigo = nullptr;
    cantidad_libros = 0;
    espacios = nullptr;
}

void Estante::getCodigo(char* codigo) const {
    if (this->codigo == nullptr) codigo[0] = 0;
    else strcpy(codigo, this->codigo);
}

void Estante::setCodigo(const char *codigo) {
    if (this->codigo != nullptr) delete this->codigo;
    this->codigo = new char[strlen(codigo) + 1];
    strcpy(this->codigo, codigo);
}

int Estante::getAnchura() const {
    return anchura;
}

void Estante::setAnchura(int anchura) {
    Estante::anchura = anchura;
}

int Estante::getAltura() const {
    return altura;
}

void Estante::setAltura(int altura) {
    Estante::altura = altura;
}

int Estante::getCantidadLibros() const {
    return cantidad_libros;
}

void Estante::setCantidadLibros(int cantidadLibros) {
    cantidad_libros = cantidadLibros;
}

void Estante::lee(ifstream &input) {
    char codigo[10], c;
    input.getline(codigo, 10, ',');
    input >> anchura >> c>>altura;
    setCodigo(codigo);
    input.get();
    espacios = new Espacio[anchura * altura]{};
}

void Estante::imprime_linea(ofstream& output, int n, char c) {
    output << setfill(c) << setw(n) << " " << endl;
    output << setfill(' ');
}

void Estante::pinta_estante(ofstream& output) {
    imprime_linea(output, 50, '-');
    output << endl;
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < anchura; j++) {
            espacios[i * anchura + j].muestra(output);
        }
        output << endl;
    }
}

void Estante::muestra(ofstream &output) {
    imprime_linea(output, 50, '-');
    output << setw(15) << left << "Codigo Estante: " << setw(10) << codigo << setw(20) << "Cantidad de Libros: " << cantidad_libros << endl;
    output << setw(15) << left << "Anchura del Estante: " << setw(5) << anchura << setw(15) << "Altura del Estante: " << altura << endl;

    pinta_estante(output);
    output << endl;
    output << setw(11) << "CODIGO" << setw(27) << "NOMBRE" << setw(8) << "ANCHO" << setw(5) << "ALTO" << endl;
    imprime_linea(output, 50, '.');
    for (int i = 0; i < cantidad_libros; i++)
        output << libros[i];
}

int Estante::get_espacios_restantes() {
    int ancho_utilizado = 0;
    for (int i = 0; i < cantidad_libros; i++)
        ancho_utilizado += libros[i].getAncho();
    return ancho_utilizado;
}

void Estante::colocar_libro(int ancho_utilizado, Libro &l) {
    for (int i = altura - 1; i > (altura - l.getAlto() - 1); i--) {
        for (int j = ancho_utilizado; j < ancho_utilizado + l.getAncho(); j++) {
            espacios[i * anchura + j].setPosx(i);
            espacios[i * anchura + j].setPosx(j);
            espacios[i * anchura + j].setContenido('*');
        }
    }
    l.setColocado(true);
    libros[cantidad_libros] = l;
    cantidad_libros++;
}

bool Estante::operator+=(Libro &l) {

    int alto_libro = l.getAlto();
    int ancho_libro = l.getAncho();
    int ancho_utilizado = get_espacios_restantes();
    if (alto_libro <= altura and ancho_libro <= (anchura - ancho_utilizado)) {
        colocar_libro(ancho_utilizado, l);
        return true;
    } else
        return false;
}

void operator>>(ifstream& input, Estante& e) {
    e.lee(input);
}

void operator<<(ofstream& output, Estante e) {
    e.muestra(output);
}


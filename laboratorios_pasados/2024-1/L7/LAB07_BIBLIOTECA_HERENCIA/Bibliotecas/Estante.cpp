//
// Created by USUARIO on 3/06/2026.
//

#include "Estante.hpp"

Estante::Estante(){
    inicializar();
}

Estante::Estante(const class Estante& estante){
    inicializar();
    *this = estante;
}

char* Estante::get_codigo() const{
    char *copia = Utils::asignar_cadena(this->codigo);
    return copia;
}

void Estante::set_codigo(char* codigo){
    delete [] this->codigo;
    this->codigo = Utils::asignar_cadena(codigo);
}

int Estante::get_anchura() const{
    return anchura;
}

void Estante::set_anchura(int anchura){
    this->anchura = anchura;
}

int Estante::get_altura() const{
    return altura;
}

void Estante::set_altura(int altura){
    this->altura = altura;
}

double Estante::get_peso_soportado() const{
    return pesoSoportado;
}

void Estante::set_peso_soportado(double peso_soportado){
    pesoSoportado = peso_soportado;
}

double Estante::get_peso_actual() const{
    return pesoActual;
}

void Estante::set_peso_actual(double peso_actual){
    pesoActual = peso_actual;
}

void Estante::inicializar(){
    codigo = nullptr;
    anchura = 0;
    altura = 0;
    espacios = nullptr;
    pesoSoportado = 0;
    pesoActual = 0;
}

//TODO: Y ESE PUNTERO???
Estante& Estante::operator=(const Estante& estante){
    if (this != &estante){
        //NO ES HIJO, POR ESO NO SE PUEDE
        //Espacio::operator=(estante);
        delete [] this->codigo;
        this->codigo = estante.get_codigo();

        this->anchura = estante.get_anchura();
        this->altura = estante.get_altura();

        //DUDA CON ESE PUNTERO
        // this->espacios = estante.espacios;

        this->pesoSoportado = estante.get_peso_soportado();
        this->pesoActual = estante.get_peso_actual();

    }
    return *this;
}

void Estante::leer(ifstream& in){
    codigo = Utils::leer_cadena(in, ',');
    anchura = Utils::leer_int(in);
    altura = Utils::leer_int(in);
}

bool Estante::esta_vacio() const{
    return espacios == nullptr;
}

void Estante::reservar_memoria_espacios(){
    espacios = new class Espacio[anchura * altura];
}



void Estante::imprimir_grafico_fisico(ofstream& out) const{
    int anchura = get_anchura();
    int altura = get_altura();
    for (int i = 0; i < altura; i++){
        for (int j = 0; j < anchura; j++){
            char caracter = conseguir_contenido(i*anchura + j);
            out << "[" << caracter << "] ";
        }
        out << endl;
    }
    Utils::imprimir_linea(out, '-');
}



void Estante::pintar_horizontal(int i, int j, int alto_utilizado,char caracter){
    int altura = get_altura();
    int anchura = get_anchura();

    int x = altura - alto_utilizado - i - 1;
    int y = anchura - j - 1;

    espacios[y + x*anchura].set_posx(x);
    espacios[y + x*anchura].set_posy(y);
    espacios[y + x*anchura].set_contenido(caracter);
}


void Estante::pintar_vertical(int i, int j, int ancho_utilizado, char caracter){
    int altura = get_altura();
    int anchura = get_anchura();

    int x = altura - i - 1;
    int y = ancho_utilizado + j;

    espacios[y + x*anchura].set_posx(x);
    espacios[y + x*anchura].set_posy(y);
    espacios[y + x*anchura].set_contenido(caracter);

}

char Estante::conseguir_contenido(int idx) const{
    return espacios[idx].get_contenido();
}

Estante::~Estante(){
    delete [] codigo;
    delete [] espacios;
}





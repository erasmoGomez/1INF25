//
// Created by erasmo on 5/6/26.
//

#ifndef JUEGOUNDERTALE_HEROE_HPP
#define JUEGOUNDERTALE_HEROE_HPP

#include "Utils2.hpp"

class Personaje {
public:
    Personaje(); // Constructor por defecto - Constructor sin parametros;
    void imprimir();

    void imprimir(ofstream &);

    void leer(ifstream &);

    void get_nombre(char* nombre) const;

    void set_nombre(const char*nombre) ;

    int get_vida() const;

    void set_vida(int vida);

    int get_vida_maxima() const;

    void set_vida_maxima(int vida_maxima);

    int get_ataque() const;

    void set_ataque(int ataque);

    int get_defensa() const;

    void set_defensa(int defensa);

    int get_fila() const;

    void set_fila(int fila);

    int get_columna() const;

    void set_columna(int columna);
    //Sobrecargas
    void operator++(); //w
    void operator++(int); //S
    void operator--(); //D
    void operator--(int); //I

private:
    char *nombre;
    int vida;
    int vida_maxima;
    int ataque;
    int defensa;
    int fila;
    int columna;
};

//Seccion FUERA DE LA CLASE
void operator >>(ifstream& input, class Personaje& personaje);
void operator <<(ofstream& output, class Personaje& personaje);
#endif //JUEGOUNDERTALE_HEROE_HPP

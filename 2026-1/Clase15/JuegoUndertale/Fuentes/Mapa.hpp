//
// Created by erasmo on 5/12/26.
//

#ifndef JUEGOUNDERTALE_MAPA_HPP
#define JUEGOUNDERTALE_MAPA_HPP
#include "Casilla.hpp"
#include "Personaje.hpp"

class Mapa {
private:
    int ancho;
    int alto;
    class Casilla *casillas;
    char* nombre;
    int cantidad_personajes;

public:
    Mapa();
    Mapa(int, int);
    Mapa(const Mapa& orig);
    virtual ~Mapa();
    void get_nombre(char* nombre) const;
    void set_nombre(const char *nombre);
    void cargar_mapa(ifstream&);
    void mostrar_mapa();
    //Sobrecarga de +=
    void operator+=(class Personaje);
};


#endif //JUEGOUNDERTALE_MAPA_HPP
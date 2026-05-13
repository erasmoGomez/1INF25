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
    Mapa(); // CONSTRUCTOR DEFECTO
    Mapa(int, int, const char*); // CONSTRUCTOR PARAMETROS
    Mapa(const Mapa& orig); // CONSTRUCTOR COPIA
    virtual ~Mapa(); // DESTRUCTOR
    void get_nombre(char* nombre) const;
    void set_nombre(const char *nombre);
    int get_ancho() const;
    void set_ancho(int ancho);
    int get_alto() const;
    void set_alto(int alto);
    void cargar_mapa(ifstream&);
    void mostrar_mapa();
    //Sobrecarga de +=
    void operator+=(class Personaje);
};


#endif //JUEGOUNDERTALE_MAPA_HPP
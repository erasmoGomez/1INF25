//
// Created by Erasmo on 24/09/25.
//

#ifndef JUEGO_HEROE_HPP
#define JUEGO_HEROE_HPP

#include "Utils.hpp"

class Heroe {
private:
    char *id;
    char *nombre;
    int hp;
    double fuerza;
    double defensa;
    int posx;
    int posy;

public:
    //Constructores
    //Constructor por defecto. class Heroe h; Otros lo llaman, constructor sin parametros
    Heroe();

    void getId(char * id) const;

    void setId(const char *id);

    void getNombre(char *nombre) const;

    void setNombre(const char *nombre);

    int getHp() const;

    void setHp(int hp);

    double getFuerza() const;

    void setFuerza(double fuerza);

    double getDefensa() const;

    void setDefensa(double defensa);

    int getPosx() const;

    void setPosx(int posx);

    int getPosy() const;

    void setPosy(int posy);

};


#endif //JUEGO_HEROE_HPP

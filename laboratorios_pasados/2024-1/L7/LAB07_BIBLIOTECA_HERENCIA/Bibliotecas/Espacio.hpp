//
// Created by USUARIO on 3/06/2026.
//

#ifndef LAB07_BIBLIOTECA_HERENCIA_ESPACIO_HPP
#define LAB07_BIBLIOTECA_HERENCIA_ESPACIO_HPP

#include "Utils.hpp"

class Espacio{

private:
    char contenido;
    int posx;
    int posy;
public:
    Espacio();
    Espacio(const class Espacio &espacio);

    char get_contenido() const;
    void set_contenido(char contenido);
    int get_posx() const;
    void set_posx(int posx);
    int get_posy() const;
    void set_posy(int posy);

    void inicializar();
    Espacio& operator=(const Espacio& espacio);

};




#endif //LAB07_BIBLIOTECA_HERENCIA_ESPACIO_HPP

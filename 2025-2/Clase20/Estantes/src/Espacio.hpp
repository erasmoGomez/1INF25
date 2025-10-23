//
// Created by Erasmo on 22/10/25.
//

#ifndef ESTANTES_ESPACIO_HPP
#define ESTANTES_ESPACIO_HPP


#include "Utils.hpp"

class Espacio {
public:
    Espacio();
    Espacio(const Espacio& orig);
    virtual ~Espacio();
    void SetPosY(int posY);
    int GetPosY() const;
    void SetPosX(int posX);
    int GetPosX() const;
    void SetContenido(char contenido);
    char GetContenido() const;

    void mostrar(ofstream&) const;
private:
    char contenido;
    int posX;
    int posY;
};

void operator<<(ofstream&, const Espacio&);


#endif //ESTANTES_ESPACIO_HPP

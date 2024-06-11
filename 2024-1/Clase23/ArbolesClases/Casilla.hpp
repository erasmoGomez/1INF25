//
// Created by Erasmo on 8/05/24.
//

#ifndef JUEGO_CASILLA_HPP
#define JUEGO_CASILLA_HPP
#include "Utils.hpp"
using namespace std;
class Casilla{
private:
    int x;
    int y;
    char elemento;
public:
    Casilla();

    Casilla(int, int, char);

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    char getElemento() const;

    void setElemento(char elemento);

    void leer(ifstream&);

    void mostrar(ostream&);
};

void operator << (ostream&, Casilla);

void operator >> (ifstream&, Casilla&);
#endif //JUEGO_CASILLA_HPP

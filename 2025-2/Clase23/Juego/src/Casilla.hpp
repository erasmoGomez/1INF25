//
// Created by Erasmo on 30/09/25.
//

#ifndef JUEGO_CASILLA_HPP
#define JUEGO_CASILLA_HPP

#include "Utils.hpp"

class Casilla {
public:
    Casilla();

    Casilla(bool);

    //Constructor Copia
    Casilla(const Casilla &orig);

    //Destructor
    virtual ~Casilla();

    char getSprite() const;

    void setSprite(char sprite);

    bool isTransitable() const;

    void setTransitable(bool transitable);

    bool isContieneheroe() const;

    void setContieneheroe(bool contieneheroe);

    void mostrar_info(ostream &out) const;

private:
    bool transitable;
    bool contieneheroe;
    char sprite;
};

void operator<<(ostream &, const class Casilla &);

#endif //JUEGO_CASILLA_HPP

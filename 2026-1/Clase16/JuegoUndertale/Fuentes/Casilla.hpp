//
// Created by erasmo on 5/13/26.
//

#ifndef JUEGOUNDERTALE_CASILLA_HPP
#define JUEGOUNDERTALE_CASILLA_HPP

#include "Utils2.hpp"

class Casilla {
private:
    bool transitable;
    char sprite;

public:
    bool is_transitable() const;

    void set_transitable(bool transitable);

    char get_sprite() const;

    void set_sprite(char sprite);

    Casilla();

    Casilla(bool transitable, char sprite);

    virtual ~Casilla(); //Destructor

    void imprimir(ostream& output) const;
};

void operator<<(ostream &, const class Casilla &);

#endif //JUEGOUNDERTALE_CASILLA_HPP

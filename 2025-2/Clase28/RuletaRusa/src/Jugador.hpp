//
// Created by Erasmo on 19/11/25.
//

#ifndef RULETARUSA_JUGADOR_HPP
#define RULETARUSA_JUGADOR_HPP

#include "Utils.hpp"

class Jugador {
private:
    string nombre;
public:
    Jugador();

public:
    const string &getNombre() const;

    void setNombre(const string &nombre);

    bool isEstado() const;

    void setEstado(bool estado);

private:
    bool estado;
public:
    virtual ~Jugador();

    virtual void leer(ifstream &input);

    virtual void imprimir(ofstream &output);

    // true = derecha (sig), false = izquierda (ant)
    virtual bool eligeDerecha() const = 0;

};


#endif //RULETARUSA_JUGADOR_HPP

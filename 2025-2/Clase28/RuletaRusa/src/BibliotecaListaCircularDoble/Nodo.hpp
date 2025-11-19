//
// Created by Erasmo on 19/11/25.
//

#ifndef RULETARUSA_NODO_HPP
#define RULETARUSA_NODO_HPP

#include "../Jugador.hpp"
#include "../Deudor.hpp"
#include "../Pagador.hpp"
#include "ListaCircularDoble.hpp"

class Nodo {
private:
    class Jugador* jugador;
    class Nodo *sig;
    class Nodo *ant;
public:
    Nodo();
    friend class ListaCircularDoble;
};


#endif //RULETARUSA_NODO_HPP

//
// Created by Erasmo on 19/11/25.
//

#ifndef RULETARUSA_LISTACIRCULARDOBLE_HPP
#define RULETARUSA_LISTACIRCULARDOBLE_HPP

#include "../Utils.hpp"
#include "Nodo.hpp"

class ListaCircularDoble {
private:
    class Nodo *cola; // apunta al ÚLTIMO nodo; la cabeza es cola->sig
    int tam;
public:
    ListaCircularDoble();

    void leer(char tipo, ifstream &input);

    void asignar_memoria(class Jugador *&j, char tipo);

    void insertar(class Jugador *j);

    int get_size();

    void imprimir_jugadores(ofstream& output);

    void jugar();

    void lista_avanzar(Nodo* p, int pasos);
};


#endif //RULETARUSA_LISTACIRCULARDOBLE_HPP

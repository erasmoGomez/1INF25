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

    void imprimir_jugadores(ofstream &output);

    void jugar(ofstream& output);

    void avanzar(Nodo* &p, int pasos, bool derecha);

    void eliminarNodo(Nodo *victima);
};


#endif //RULETARUSA_LISTACIRCULARDOBLE_HPP

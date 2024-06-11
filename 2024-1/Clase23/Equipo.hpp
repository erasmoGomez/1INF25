//
// Created by Erasmo on 8/06/24.
//

#ifndef JUEGO_EQUIPO_HPP
#define JUEGO_EQUIPO_HPP
#include "Heroe.hpp"
#include "Nodo.hpp"

class Equipo {
public:
    Equipo();
    Equipo(const Equipo&);
    virtual ~Equipo();
    void crear(const char *); //Esto es equivalente a Crear Arbol
    void mostrar_en_orden();
    void mostrar_post_orden();
private:
    class Nodo *equipo;
    void insertar_recursivo(Nodo *&, const class Heroe &);
    void mostrar_en_orden_recursivo(Nodo *&);
    void mostrar_post_orden_recursivo(Nodo *&);
};


#endif //JUEGO_EQUIPO_HPP

//
// Created by Erasmo on 30/09/25.
//

#ifndef JUEGO_MAPA_HPP
#define JUEGO_MAPA_HPP
#include "Casilla.hpp"
#include "Heroe.hpp"
class Mapa {
private:
    int ancho;
    int alto;
    class Casilla *casillas;
public:
    Mapa();
    Mapa(int, int);
    Mapa(const Mapa& orig);
    virtual ~Mapa();
    void cargar_mapa(ifstream&);
    void mostrar_mapa();
    //Sobrecarga de +=
    void operator+=(class Heroe);
};


#endif //JUEGO_MAPA_HPP

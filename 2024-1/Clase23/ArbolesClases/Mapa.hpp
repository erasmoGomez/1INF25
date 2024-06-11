//
// Created by Erasmo on 8/05/24.
//

#ifndef JUEGO_MAPA_HPP
#define JUEGO_MAPA_HPP
#include "Casilla.hpp"
#include "Heroe.hpp"
using namespace std;
class Mapa {
private:
    int filas;
    int columnas;
    Casilla *casillas;
public:
    Mapa();
    virtual ~Mapa();
    void leer(ifstream&);
    void mostrar();
    void inicializar();
    void operator +=(Heroe&);
};
#endif //JUEGO_MAPA_HPP

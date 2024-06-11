//
// Created by Erasmo on 8/05/24.
//

#ifndef JUEGO_JUEGO_HPP
#define JUEGO_JUEGO_HPP
#include "Mapa.hpp"
#include "Heroe.hpp"
#include "Equipo.hpp"
class Juego{
private:
    Mapa mapa;
    Heroe heroes[20];
    int n_heroes;
    Equipo equipo1;
    Equipo equipo2;
public:
    Juego();
    void cargar_mapa();
    void cargar_heroes();
    void cargar_datos();
    void mostrar_mapa();
    void mostrar_heroes();
    void colocar_heroes();
    void jugar();
    int get_indice(char);
    void pintar();
    void carga_items();
    void mostrar_datos();
    void mostrar_heroe(int);
    void muestra_menu();
    void mover_jugadores();
    void info_jugadores();
    void crear_equipo();
};
#endif //JUEGO_JUEGO_HPP

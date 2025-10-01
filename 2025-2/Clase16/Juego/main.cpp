#include "src/Juego.hpp"

int main() {
    class Juego juego;
    juego.cargar_heroes();
    juego.mostrar_heroes();

    juego.cargar_mapa();
    juego.colocar_heroes();
    juego.mostrar_mapa();
    //Sobrecarga de operadores para Objetos
//    heroe ++; // Moverse hacia arriba
//    ++ heroe; // Moverse hacia abajo
//    heroe --; // Moverse hacia la derecha
//    -- heroe; // Moverse hacia la izq
    return 0;
}

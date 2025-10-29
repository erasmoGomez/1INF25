#include "src/Juego.hpp"

int main() {
    class Juego juego;
    juego.cargar_heroes();
    juego.cargar_items();


    //juego.cargar_mapa();
    //juego.colocar_heroes();

    juego.equipar_heroes();
    juego.mostrar_heroes();
    //juego.jugar();

    return 0;
}

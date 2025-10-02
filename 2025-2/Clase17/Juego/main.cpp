#include "src/Juego.hpp"

int main() {
    class Juego juego;
    juego.cargar_heroes();
    juego.mostrar_heroes();

    juego.cargar_mapa();
    juego.colocar_heroes();
    juego.mostrar_mapa();

    juego.jugar();

    return 0;
}

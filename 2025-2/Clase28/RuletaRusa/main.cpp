#include "src/GestorRussianRoulette.hpp"

int main() {
    GestorRussianRoulette grr;
    grr.cargar_jugadores("Data/jugadores.csv");
    grr.imrprimir_jugadores("Reports/ruleta_rusa.txt");
    //grr.jugar();
    return 0;
}

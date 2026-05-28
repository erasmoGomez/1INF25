#include "Fuentes/Juego.hpp"
int main() {
    // Personaje erasmo;
    // erasmo.imprimir();
    // Personaje personajes[10]{};
    //
    // char nombre[20]{};
    // erasmo.get_nombre(nombre);
    // cout<<nombre<<endl;
    class Juego juego;
    juego.cargar_personajes("ArchivosEntrada/Personajes/heroes_undertale.csv");
    juego.cargar_items("ArchivosEntrada/Items/items.csv");
    juego.cargar_mapas("ArchivosEntrada/Mapas/mapas.txt");
    juego.colocar_personajes();
    juego.imprimir_mapa(0);

    juego.jugar();
    return 0;
}
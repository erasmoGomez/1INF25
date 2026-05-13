#include "Fuentes/Juego.hpp"
int main() {
    // Personaje erasmo;
    // erasmo.imprimir();
    // Personaje personajes[10]{};
    //
    // char nombre[20]{};
    // erasmo.get_nombre(nombre);
    // cout<<nombre<<endl;
    Juego juego;
    juego.cargar_personajes("ArchivosEntrada/Personajes/heroes_undertale.csv");
    juego.imprimir_personajes("ArchivosSalida/reporte_personajes.txt");
    juego.cargar_mapas("ArchivosEntrada/Mapas/mapas.txt");
    juego.imprimir_mapa(1);
    juego.colocar_heroes();
    juego.imprimir_mapa(1);
    return 0;
}
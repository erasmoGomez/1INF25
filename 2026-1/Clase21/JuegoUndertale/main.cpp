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

    juego.equipar_personaje();
    //juego.jugar();
    Item* item;
    item = new Consumible;
    int modificador = item->get_modificador();
    cout<<modificador<<endl;

    //
    //
    // Personaje p1;
    // Personaje* p;
    // Guerrero g;
    // p->atacar(); // Hace referencia un puntero.
    // p1.atacar();
    // p = g;
    // void funcion() {
    //     Personaje* p2;
    //     p2->atacar(); // A QUIEN LLAMA?
    // }
    // Polimorfismo
    // 1. Herencia SI
    // 2. Exista el Puntero a la clase Padre. SI


    return 0;
}
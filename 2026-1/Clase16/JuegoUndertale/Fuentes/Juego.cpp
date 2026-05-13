//
// Created by erasmo on 5/12/26.
//

#include "Juego.hpp"

Juego::Juego() {
    cantidad_personajes = 0;
    cantidad_mapas = 0;
    //codigos = nullptr;
    //codigos = new int[20];
}


void Juego::cargar_personajes(const char *nombre_archivo) {
    ifstream input(nombre_archivo, ios::in);
    Personaje p;
    while (true) {
        // Leer Personaje
        input>>p;
        // Validar EOF
        if (input.eof()) break;
        // Insertar Personaje
        personajes[cantidad_personajes] = p;
        cantidad_personajes++;
    }
}

void Juego::imprimir_personajes(const char *nombre_archivo) {
    ofstream output(nombre_archivo, ios::out);
    for (int i = 0; i < cantidad_personajes; i++) {
        output << personajes[i];
    }
}

void Juego::cargar_mapas(const char *nombre_archivo) {
    ifstream input(nombre_archivo, ios::in);
    char nombre_mapa[20];
    while (true) {
        input.getline(nombre_mapa, 20, '\n');
        if (input.eof()) break;
        char ruta_mapa[100] = "ArchivosEntrada/Mapas/";
        strcat(ruta_mapa, nombre_mapa);
        strcat(ruta_mapa, ".txt");
        //cout<<ruta_mapa<<endl;
        ifstream input_mapa;
        input_mapa.open(ruta_mapa, ios::in);
        mapas[cantidad_mapas].set_nombre(nombre_mapa);
        mapas[cantidad_mapas].cargar_mapa(input_mapa);
        cantidad_mapas++;
    }

}

void Juego::imprimir_mapa(int indice) {
    mapas[indice].mostrar_mapa();
}

void Juego::jugar() {

}



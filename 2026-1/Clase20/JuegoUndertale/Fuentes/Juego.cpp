//
// Created by erasmo on 5/12/26.
//

#include "Juego.hpp"

#include "Guerrero.hpp"

Juego::Juego() {
    cantidad_personajes = 0;
    cantidad_mapas = 0;
    mapa_actual = 0;
    // personajes_ptr = nullptr;
    // personajes_ptr = new Personaje[20];
    //codigos = nullptr;
    //codigos = new int[20];
}


void Juego::cargar_personajes(const char *nombre_archivo) {
    ifstream input;
    Utils::apertura_archivo_lectura(input, nombre_archivo);
    while (true) {
        // Leer Personaje
        Personaje p;
        input >> p;
        // Validar EOF
        if (input.eof()) break;
        // Reserva de memoria (Con el metodo q uds quieran)
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
        input_mapa.close();
    }
    input.close();
}

void Juego::imprimir_mapa(int indice) {
    mapas[indice].mostrar_mapa();
}


void Juego::colocar_personajes() {
    for (int i = 0; i < cantidad_personajes; i++) {
        int indice_mapa = i % cantidad_mapas;
        // personajes[i].imprimir();
        mapas[indice_mapa] += personajes[i];
    }
}

void Juego::pintar() {
    cargar_mapas("ArchivosEntrada/Mapas/mapas.txt");
    colocar_personajes();
    imprimir_mapa(0);
}

void Juego::cargar_items(const char * nombre_archivo) {
    ifstream input;
    input.open(nombre_archivo, ios::in);
    char tipo[15];
    int indice_personaje = 0;
    while (true) {
        //Weapon,3,Sword,A sharp and sturdy sword.,147
        input.getline(tipo, 15, ',' );
        if (input.eof())break;
        input>>indice_personaje;
        input.get();
        personajes[indice_personaje-1].leer_item(tipo, input);
        input.get();
    }
}

void Juego::equipar_personaje() {
    int personaje_seleccionado = 0; // Frisk
    int tipo_seleccionado = 0;// 0 Arma, 1 Armadura, 2 Consumible
    personajes[personaje_seleccionado].equipar(tipo_seleccionado, "Bow");
    ofstream output;
    output.open("ArchivosEntrada/Mapas/mapas.txt", ios::out);
    personajes[personaje_seleccionado].imprimir(output);
}

int Juego::conseguir_indice(char p) {
    char buffer[20];
    for (int i = 0; i < cantidad_personajes; i++) {
        personajes[i].get_nombre(buffer);
        if (buffer[0] == p) return i;
    }
    return -1;
}

void Juego::jugar() {
    // cargar_personajes("ArchivosEntrada/Personajes/heroes_undertale.csv");
    // imprimir_personajes("ArchivosSalida/reporte_personajes.txt");
    // cargar_mapas("ArchivosEntrada/Mapas/mapas.txt");
    // imprimir_mapa(1);
    // colocar_heroes();
    // imprimir_mapa(1);
    // Personaje p;
    // p.set_nombre("Erasmo");
    // Guerrero g;
    // Mago m;
    // g.set_nombre("Erasmito");
    // g.set_n_muertes(45);
    // ofstream output;
    // output.open("ArchivosSalida/Erasmo.txt", ios::out);
    // g.imprimir(output);
    // g.atacar();
    // m.atacar();
    char heroe_seleccionado;
    char movimiento;
    while (true) {
        cout << "Ingrese un Persona (Primera letra del nombre) o coloque 0 para salir;" << endl;
        cin >> heroe_seleccionado;
        if (heroe_seleccionado == '0') break;
        const int indice_seleccionado = conseguir_indice(heroe_seleccionado);
        if (indice_seleccionado == -1) {
            cout << "No se encontro el Personaje" << endl;
            break;
        }
        cout << "Ingrese la direccion hacia donde desea moverse W S D A, para salir 0" << endl;
        while (true) {
            cin >> movimiento;
            cout<<"INDICE_SELECCIONADO: "<<indice_seleccionado<<endl;
            if (personajes[indice_seleccionado].mover(movimiento, mapas[mapa_actual])) {
                if (movimiento == '0') break;
                if (movimiento == 'W') ++personajes[indice_seleccionado];
                if (movimiento == 'S') personajes[indice_seleccionado]++;
                if (movimiento == 'D') --personajes[indice_seleccionado];
                if (movimiento == 'A') personajes[indice_seleccionado]--;
            } else
                cout << "No m puedo mover a la posicion que pides" << endl;
            pintar();
        }
    }
}

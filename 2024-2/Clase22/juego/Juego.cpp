/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Utils.hpp"
#include "Juego.hpp"
using namespace std;

Juego::Juego() {
    n_heroes = 0;
}

void Juego::carga_mapa() {
    ifstream input_mapa("map_dataset.csv", ios::in);
    mapa.leer(input_mapa);

}

void Juego::cargar_items() {
   ifstream input("items_dataset.csv", ios::in);
   char tipo[30], c;
   int n_heroe;
   //Weapon,3,Sword,A sharp and sturdy sword.,147
   //Juego - Heroe- Mochila- Item - Consumible/Armadura/Arma
   while(true){
       input.getline(tipo, 30,',');
       if(input.eof())break;
       input>>n_heroe;
       input.get();
       heroes[n_heroe-1].agregar_mochila(input, tipo);
   }
}

void Juego::cargar_juego() {
    carga_mapa();
    carga_heroes();
    cargar_items();
}

void Juego::mostrar_mapa() {
    mapa.mostrar();
}

void Juego::carga_heroes() {
    ifstream input_heroes("heroes_dataset.csv", ios::in);
    while (true) {
        //heroes[n_heroes].leer(input_heroes);
        input_heroes >> heroes[n_heroes];
        if (input_heroes.eof())break;
        n_heroes++;
    }
}

void Juego::colocar_heroes() {
    for (int i = 0; i < n_heroes; i++)
        mapa += heroes[i];
}

int Juego::conseguir_indice(char c) {
    char buffer[20];
    for (int i = 0; i < n_heroes; i++) {
        heroes[i].getNombre(buffer);
        if (buffer[0] == c) return i;
    }
    return -1;
}

void Juego::pintar() {
    mapa.inicializar();
    carga_mapa();
    colocar_heroes();
    mostrar_mapa();
}

void Juego::jugar() {
//    char heroe_seleccionado;
//    char movimiento;
//    int indice_seleccionado;
//    while (true) {
//        //mostrar_mapa();
//        cout << "Ingrese un heroe(Primera Letra MAYUSCULA) a mover, coloque 0 para salir" << endl;
//        cin>>heroe_seleccionado;
//        if (heroe_seleccionado == '0')break;
//        indice_seleccionado = conseguir_indice(heroe_seleccionado);
//        if (indice_seleccionado == -1) {
//            cout << "No se encontro error, chau" << endl;
//            break;
//        }
//        cout << "Ingrese la direccion hacia donde desea mover: W S D A, para salir 0" << endl;
//        while (true) {
//            cin>>movimiento;
//            if (movimiento == '0') break;
//            if (movimiento == 'W') heroes[indice_seleccionado]++;
//            if (movimiento == 'S') ++heroes[indice_seleccionado];
//            if (movimiento == 'D') heroes[indice_seleccionado]--;
//            if (movimiento == 'A') --heroes[indice_seleccionado];
//            pintar();
//        }
//    }
    int indice_heroe = 3;
    //heroes[indice_heroe-1].mostrar();
//    heroes[indice_heroe-1].equipar("Sword", "Weapon");
//    heroes[indice_heroe-1].equipar("Health Elixir", "Consumable");
//    heroes[indice_heroe-1].equipar(1, "Consumable");
    heroes[indice_heroe-1].equipar_item("Sword", 1);
    heroes[indice_heroe-1].equipar_item("Gold Coin", 0);
    heroes[indice_heroe-1].mostrar();
}
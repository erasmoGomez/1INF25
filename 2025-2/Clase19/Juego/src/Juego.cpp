//
// Created by Erasmo on 26/09/25.
//

#include "Juego.hpp"

Juego::Juego() {
    cantidad_heroes = 0;
}

void Juego::cargar_heroes() {
    ifstream input("Data/heroes.csv", ios::in);

    while (true) {
        class Heroe h;
        input>>h;
        if (input.eof())break;
        heroes[cantidad_heroes] = h;
        cantidad_heroes++;
    }
}

void Juego::mostrar_heroes() {
    ofstream output("Reports/reporte_heroes_juego.txt", ios::out);
    for(int i=0; i<cantidad_heroes; i++)
        output<<heroes[i];
}

void Juego::cargar_mapa() {
    ifstream input("Data/mapa_grande.csv", ios::in);
    mapa.cargar_mapa(input);
}

void Juego::mostrar_mapa() {
    mapa.mostrar_mapa();
}

void Juego::colocar_heroes() {
    for(int i = 0; i<cantidad_heroes; i++)
        mapa += heroes[i];
}

void Juego::pintar(){
    cargar_mapa();
    colocar_heroes();
    mostrar_mapa();
}

int Juego::conseguir_indice(char h){
    char buffer[20];
    for(int i=0; i<cantidad_heroes; i++){
        heroes[i].getNombre(buffer);
        if(buffer[0] == h) return i;
    }
    return -1;
}

void Juego::jugar(){
    char heroe_seleccionado;
    char movimiento;
    int indice_seleccionado;
    while(true){
        cout<<"Ingrese un Heroe (Primera letra del nombre) o coloque 0 para salir;"<<endl;
        cin>>heroe_seleccionado;
        if(heroe_seleccionado == '0') break;
        indice_seleccionado = conseguir_indice(heroe_seleccionado);
        if(indice_seleccionado == -1){
            cout<<"No se encontro el Heroe"<<endl;
            break;
        }
        cout<<"Ingrese la direccion hacia donde desea moverse W S D A, para salir 0"<<endl;
        while(true){
            cin>>movimiento;
            if(heroes[indice_seleccionado].mover(movimiento, mapa)){
                if(movimiento == '0') break;
                if(movimiento == 'W') ++heroes[indice_seleccionado];
                if(movimiento == 'S') heroes[indice_seleccionado]++;
                if(movimiento == 'D') --heroes[indice_seleccionado];
                if(movimiento == 'A') heroes[indice_seleccionado]--;
            }
            else
                cout<< "No m puedo mover a la posicion que pides"<<endl;
            pintar();
        }
    }
}

void Juego::cargar_items() {
    ifstream input("Data/items.csv", ios::in);
    //1,Sword,Weapon,A sharp and sturdy sword.,147,3
    int indice_heroe = 0;
    while(true){
        // heroes[n].mochila no se puede x q mochila es privado
        input>>indice_heroe;
        if(input.eof())break;
        input.get();
        heroes[indice_heroe-1].leer_item(input);
    }
}

void Juego::equipar_heroes(){
    int heroe_seleccionado = 0;
    int tipo = 0;
    heroes[heroe_seleccionado].equipar(tipo, "Scroll of Healing"); // 0:consumible, 1: armadura, 2: arma
    heroes[heroe_seleccionado].equipar(1, "Plate Armor"); //0 Consumibles , 1 Armas, 2 Armaduras
    heroes[heroe_seleccionado].equipar(2, "Bow"); //0 Consumibles , 1 Armas, 2 Armaduras
    // heroes[heroe_seleccionado].mostrar_heroe(cout);
}

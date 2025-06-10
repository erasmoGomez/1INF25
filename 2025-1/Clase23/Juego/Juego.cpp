/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.cpp
 * Author: hecto
 * 
 * Created on May 7, 2025, 4:20 PM
 */

#include "Juego.hpp"
#include "Mapa.hpp"

Juego::Juego() {
    cantidad_heroes = 0;
}

Juego::Juego(const Juego& orig) {
    *this = orig;
}

Juego::~Juego() {
}

void Juego::cargar_heroes(){
    ifstream input("heroes.csv", ios::in);
    while(true){
        class Heroe h;
        input>>h;
        if(input.eof())break;
        heroes[cantidad_heroes] = h;
        cantidad_heroes++;
    }
}

void Juego::cargar_items(){
    ifstream input("items_dataset.csv", ios::in);
    char tipo[30];
    int n_heroe;
    //Weapon,3,Sword,A sharp and sturdy sword.,147
    //Juego -> Heroe -> Inventario -> Item -> Consumible/Armadura/Arma
    while(true){
        input.getline(tipo, 30, ',');
        if(input.eof())break;
        input>>n_heroe;
        input.get();
        heroes[n_heroe-1].agregar_inventario(input, tipo);
    }
}

void Juego::mostrar_heroes(){
    ofstream output("reporte_heroes.txt", ios::out);
    for(int i = 0; i< cantidad_heroes; i++)
        output<<heroes[i];
}

void Juego::cargar_mapa(){
    ifstream input("mapa_grande.csv", ios::in);
    mapa.cargar_mapa(input);
}

void Juego::mostrar_mapa(){
    mapa.mostrar_mapa();
}

void Juego::colocar_heroes(){
    for(int i = 0; i< cantidad_heroes; i++)
        mapa += heroes[i];
}

int Juego::conseguir_indice(char h){
    char buffer[20];
    for(int i=0; i<cantidad_heroes;i++){
        heroes[i].getNombre(buffer);
        if(buffer[0] == h) return i;
    }
    return -1;
}

void Juego::pintar(){
    cargar_mapa();
    colocar_heroes();
    mostrar_mapa();
}
void Juego::jugar(){
//    char heroe_seleccionado;
//    char movimiento;
//    int indice_seleccionado;
//    while(true){
//        //mostrar_mapa();
//        cout<<"Ingrese un heroe(PRIMERA LETRA MAYUSCULA) a mover, coloque 0 para salir"<<endl;
//        cin>>heroe_seleccionado;
//        if(heroe_seleccionado == '0') break;
//        indice_seleccionado = conseguir_indice(heroe_seleccionado);
//        if(indice_seleccionado == -1){
//            cout<<"No se encontro Heroe, chau!"<<endl;
//            break;
//        }
//        cout<<"Ingrese la direccion hacia donde desea moverse: W S D A, para salir 0"<<endl;
//        while(true){
//            cin>>movimiento;
//            if(heroes[indice_seleccionado].mover(movimiento, mapa)){
//                if(movimiento == '0') break;
//                if(movimiento == 'S') heroes[indice_seleccionado]++;
//                if(movimiento == 'W') ++heroes[indice_seleccionado];
//                if(movimiento == 'A') heroes[indice_seleccionado]--;
//                if(movimiento == 'D') --heroes[indice_seleccionado];
//            }
//            else
//                cout<<"NO SE PUEDE MOVER A ESA CASILLA :("<<endl;
//            pintar();
//        }
//    }
    
    Equipo equipo1, equipo2;
    equipo1.crear("heroes_dataset_1.csv");
    equipo2.crear("heroes_dataset_2.csv");
    cout<<"EQUIPO1"<<endl;
    equipo1.imprimir("equipo1.txt");
    cout<<"EQUIPO2"<<endl;
    equipo2.imprimir("equipo2.txt");
    
    EquipoArbol equipo_arbol1, equipo_arbol_2;
    equipo1.crear("heroes_dataset_1.csv");
    equipo2.crear("heroes_dataset_2.csv");
    equipo1.mostrar_en_orden("equipo1_arbol.txt");
    equipo2.mostrar_post_orden("equipo2_arbol.txt");
}

void Juego::mostrar_items(int indice_heroe){
    heroes[indice_heroe].equipar("Bow", 1); //0 Consumibles , 1 Armas, 2 Armaduras
    heroes[indice_heroe].equipar("Plate Armor", 2); //0 Consumibles , 1 Armas, 2 Armaduras
    heroes[indice_heroe].mostrar_heroe(cout);
}
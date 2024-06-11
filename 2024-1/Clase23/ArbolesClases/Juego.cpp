//
// Created by Erasmo on 8/05/24.
//
#include "Utils.hpp"
#include "Juego.hpp"
using namespace std;
Juego::Juego(){
    n_heroes=0;
}

void Juego::cargar_heroes() {
    ifstream input_heroes("heroes_dataset.csv", ios::in);

    while(true){
        heroes[n_heroes].leer(input_heroes);
        if(input_heroes.eof())break;
        n_heroes++;
    }
}

void Juego::cargar_mapa() {
    ifstream input_mapa("map_dataset.csv", ios::in);
    mapa.leer(input_mapa);
}

void Juego::cargar_datos() {
    cargar_mapa();
    cargar_heroes();
    carga_items();
}

void Juego::mostrar_mapa() {
    mapa.mostrar();
}

void Juego::mostrar_heroes() {
    for(int i = 0;i<n_heroes;i++)
        cout<<heroes[i];
}

void Juego::mostrar_heroe(int i) {
    cout<<heroes[i];
}

void Juego::colocar_heroes() {
    for(int i = 0;i<n_heroes;i++)
        mapa+=heroes[i];
}

int Juego::get_indice(char c) {
    char buffer[20];
    for(int i=0; i<n_heroes; i++){
        heroes[i].getNombre(buffer);
        if(buffer[0]==c) return i;
    }
    return -1;

}

void Juego::pintar() {
    mapa.inicializar();
    cargar_mapa();
    colocar_heroes();
    mostrar_mapa();
}

void Juego::muestra_menu(){
    cout<<"Ingrese lo que necesita hacer"<<endl;
    cout<<"1: Mover Jugadores"<<endl;
    cout<<"2: Mostrar Informacion"<<endl;
    cout<<"3: Cargar Equipos"<<endl;
    cout<<"4: Cargar Equipos en Lista"<<endl;
    cout<<"5: Salir"<<endl;
}

void Juego::mover_jugadores(){
    char heroe_seleccionado;
    char movimiento;
    int indice;
    while(true){
        pintar();
        cout<<"Ingrese un heroe(PRIMERA LETRA MAYUSCULA) a mover, coloque 0 para salir"<<endl;
        cin>>heroe_seleccionado;
        if(heroe_seleccionado=='0')break;
        indice = get_indice(heroe_seleccionado);
        if (indice==-1){
            cout<<"Heroe no encontrado"<<endl;
            break;
        }
        cout<<"Ingrese la direccion hacia donde desea mover: W S D A, para salir 0"<<endl;
        while(true){
            cin>>movimiento;
            if(movimiento=='0')break;
            if(movimiento=='W') heroes[indice]++;
            if(movimiento=='S') ++heroes[indice];
            if(movimiento=='D') heroes[indice]--;
            if(movimiento=='A') --heroes[indice];
            pintar();
        }
    }
}

void Juego::info_jugadores() {
    int indice_heroe, tipo_item;
    char opcion;
    char nombre_item[30];
    cout<<"Ingrese el indice del jugador: "<<endl;
    cin>>indice_heroe;
    mostrar_heroe(indice_heroe-1);
    cout<<"Desea equipar algun item?"<<endl;
    cin>>opcion;
    if (opcion == 'S'){
        cout<<"Ingrese el tipo y el nombre: 0 CONSUMIBLE, 1 ARMA, 2 ARMADURA "<<endl;
        cin>>tipo_item>>nombre_item;
        heroes[indice_heroe-1].equipar(nombre_item, 1); //0 CONSUMIBLE, 1 ARMA, 2 ARMADURA
        mostrar_heroe((indice_heroe-1));
    }
}
//Equipo
//Jugadores 5 - Insertados en un arbol - Nombre
//Nodo(Dato, IZQ, DER) , Equipo/ARBOL(Nodo*)

void Juego::jugar() {
    char opt;
    while(true){
        muestra_menu();
        cin>>opt;

        switch(opt){
            case '1':
                mover_jugadores();
                break;
            case '2':
                info_jugadores();
                break;
            case '3':
                crear_equipo();
                break;
            case '4':
                crear_equipo_lista();
                break;
            default:
                exit(0);
        }
    }

}

void Juego::carga_items() {
    ifstream input("items.csv", ios::in);
    char tipo[20], c;
    int n_heroe=0;
    int cont = 0;
    //Weapon,3,Sword,A sharp and sturdy sword.,147
    //JUEGO - ITEM - CONSUMIBLE/ARMADURA/ARMA
    while(true){
        input.getline(tipo, 20, ',');
        cout<<tipo<<endl; 
       if(input.eof())break;
        input>>n_heroe>>c;
        cout<<n_heroe<<endl;
        heroes[n_heroe-1].agregar_mochila(input, tipo);
        cont++;
    }
}

void Juego::mostrar_datos() {
    int indice_heroe = 3;
    ofstream output("reporte.txt",ios::out);
    heroes[indice_heroe-1].mostrar(output);
}

void Juego::crear_equipo() {
    char heroe_selecionado[20];
    Heroe heroe_obtenido;
    equipo1.crear("heroes_dataset_1.csv");
    equipo2.crear("heroes_dataset_2.csv");
    
    equipo1.mostrar_en_orden();
    equipo2.mostrar_post_orden();
    
    cout<<"Ingrese el heroe a buscar: "<<endl;
    cin>>heroe_selecionado;
    
    heroe_obtenido = equipo1.buscar(heroe_selecionado);
    heroe_obtenido.mostrar(cout);
}

void Juego::crear_equipo_lista() {
    equipo3.crear();
    equipo3.imprimir();
}
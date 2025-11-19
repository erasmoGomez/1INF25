//
// Created by Erasmo on 19/11/25.
//

#include "ListaCircularDoble.hpp"

void ListaCircularDoble::asignar_memoria(class Jugador *&j, char tipo) {
    if (tipo == 'D')
        j = new class Deudor;
    else if (tipo == 'P')
        j = new class Pagador;
}

void ListaCircularDoble::insertar(class Jugador *j){
    Nodo* nuevo = new Nodo;
    nuevo->jugador = j; // La palabra friend me permite hacer esto
    nuevo->sig = nullptr;
    nuevo->ant = nullptr;

    if (!cola) {
        nuevo->sig = nuevo;      // primer nodo: apunta a sí mismo
        nuevo->ant = nuevo;
        cola = nuevo;
        tam = 1;
        return;
    }
    nuevo->ant = cola; // Apunra a lo anterior
    nuevo->sig = cola->sig; // cabeza actual
    cola->sig = nuevo;      // enlazar después de cola
    cola = nuevo;           // nuevo último
    tam++;
}

void ListaCircularDoble::leer(char tipo, ifstream &input) {
    class Jugador *j = nullptr;
    asignar_memoria(j, tipo);
    j->leer(input); //Poliformismo
    insertar(j); //TAD
}

ListaCircularDoble::ListaCircularDoble() {
    cola = nullptr;
    tam = 0;
}

int ListaCircularDoble::get_size() {
    return tam;
}

void ListaCircularDoble::imprimir_jugadores(ofstream& output){
    class Nodo* recorrido;
    recorrido = cola;
    for(int i=0; i<tam;i++){
        recorrido->jugador->imprimir(output);
        recorrido = recorrido->sig;
    }

}

void ListaCircularDoble::lista_avanzar(Nodo* p, int pasos) {
    // p debe pertenecer al anillo (no nulo si lista no está vacía)
    while (pasos-- > 0) p = p->sig;
}

void ListaCircularDoble::jugar() {
    srand(0); // o srand((unsigned)time(NULL));
    Nodo* p = cola; // previo al primero
    while (tam > 1) {
        int k   = 1 + (rand() % tam);     // k ∈ [1, tam]
        cout<<setw(5)<<k;
        int pasos = (k - 1) % tam;        // reducir vueltas
        cout<<setw(5)<<pasos<<endl;
        lista_avanzar(p, pasos);
        //lista_borrar_siguiente(p);
    }

}


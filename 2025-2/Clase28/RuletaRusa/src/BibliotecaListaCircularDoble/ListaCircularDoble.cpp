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

void ListaCircularDoble::insertar(Jugador *j) {
    Nodo *nuevo = new Nodo;
    nuevo->jugador = j;   // gracias a friend
    nuevo->sig = nullptr;
    nuevo->ant = nullptr;

    if (!cola) {
        // Lista vacía: el nodo se apunta a sí mismo
        nuevo->sig = nuevo;
        nuevo->ant = nuevo;
        cola = nuevo;
        tam = 1;
        return;
    }

    Nodo *cabeza = cola->sig; // primer nodo actual

    // Enlazar nuevo al final (después de cola)
    nuevo->ant = cola;
    nuevo->sig = cabeza;

    cola->sig = nuevo;    // la antigua cola apunta al nuevo
    cabeza->ant = nuevo;  // la cabeza ahora apunta hacia atrás al nuevo

    cola = nuevo;         // actualizar la cola
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

void ListaCircularDoble::imprimir_jugadores(ofstream &output) {
    class Nodo *recorrido;
    recorrido = cola;
    for (int i = 0; i < tam; i++) {
        recorrido->jugador->imprimir(output);
        recorrido = recorrido->sig;
    }

}

void ListaCircularDoble::avanzar(Nodo *&p, int pasos, bool derecha) {
    while (pasos-- > 0) {
        p = derecha ? p->sig : p->ant;
    }
}

void ListaCircularDoble::jugar(ofstream &output) {
    if (!cola || tam <= 1) return;

    srand(time(nullptr));

    // empezamos en la cabeza
    Nodo *actual = cola->sig; // cabeza

    while (tam > 1) {
        Jugador *j = actual->jugador;

        // dirección elegida por el jugador polimórfico
        bool derecha = j->eligeDerecha(); //Metodo Virtual Puro que devuelve true si es Pagador y false si es Deudor

        int k = 1 + (rand() % tam);    // k ∈ [1, tam]
        int pasos = (k - 1) % tam;         // reducir vueltas

        output << "Turno de " << j->getNombre()
               << " | pasos = " << pasos
               << " | dir = " << (derecha ? "derecha" : "izquierda")
               << endl;

        Nodo *victima = actual; // inicializamos desde el jugador actual
        avanzar(victima, pasos, derecha); // avanzamos hasta la victima, sin perder el puntero al actual

        output << "   -> Muere: "
               << victima->jugador->getNombre() << endl;

        // Este nuevo_actual nos sirve para ver desde donde se sigue contando según la dirección
        Nodo *nuevo_actual =
                derecha ? victima->sig   // siguiente a la derecha
                        : victima->ant;  // siguiente a la izquierda

        // eliminar a la víctima de la lista circular doble
        eliminarNodo(victima);

        // si ya no queda nadie, salimos
        if (tam == 0) break;

        // siguiente ronda: el nodo vecino en la dirección usada
        actual = nuevo_actual;
    }

    if (cola and tam == 1) {
        output << "Sobreviviente: "
               << cola->jugador->getNombre() << endl;
    }
}

void ListaCircularDoble::eliminarNodo(Nodo *victima) {
    if (!victima or tam == 0) return;

    if (tam == 1) {
        delete victima->jugador;
        delete victima;
        cola = nullptr;
        tam = 0;
        return;
    }

    Nodo *siguiente = victima->sig;
    Nodo *anterior = victima->ant;

    anterior->sig = siguiente;
    siguiente->ant = anterior;

    if (victima == cola) {
        cola = anterior;
    }

    delete victima->jugador;
    delete victima;
    tam--;
}




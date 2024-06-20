/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 15 de junio de 2024, 08:53 AM
 */
#include "Persona.h"
#include "GrafoDirigido.h"
int main() {
    // Crear algunas personas
    Persona persona1("Alice", 30);
    Persona persona2("Bob", 25);
    Persona persona3("Charlie", 35);
    Persona persona4("Miguel", 55);
    Persona persona5("Rony", 50);
    Persona persona6("Erasmo", 32);
    // Crear el grafo dirigido
    GrafoDirigido grafo;

    // Agregar aristas entre personas
    grafo.agregarArista(persona1, persona2);
    grafo.agregarArista(persona1, persona3);
    grafo.agregarArista(persona2, persona3);
    grafo.agregarArista(persona3, persona4);
    grafo.agregarArista(persona5, persona6);
    grafo.agregarArista(persona5, persona1);
    grafo.agregarArista(persona6, persona5);
    grafo.agregarArista(persona6, persona4);
    grafo.agregarArista(persona6, persona3);

    // Imprimir el grafo
    grafo.imprimirGrafo();

    return 0;
}



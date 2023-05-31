/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "funciones.hpp"

void ordenar_chevere(void*arr, int izq, int der, int (*cmp)(const void*, const void*)) {
    void **arreglo = (void**) arr;
    int limite;

    if (izq >= der)return;
    cambiar_chevere(arreglo, izq, (izq + der) / 2);
    limite = izq;
    for (int i = izq + 1; i <= der; i++)
        if (cmp(arreglo[izq], arreglo[i]) > 0)
            cambiar_chevere(arreglo, ++limite, i);
    cambiar_chevere(arreglo, izq, limite);
    ordenar_chevere(arreglo, izq, limite - 1, cmp);
    ordenar_chevere(arreglo, limite + 1, der, cmp);
}

void cambiar_chevere(void **arreglo, int i, int k) {
    void *aux;
    aux = arreglo[i];
    arreglo[i] = arreglo[k];
    arreglo[k] = aux;
}
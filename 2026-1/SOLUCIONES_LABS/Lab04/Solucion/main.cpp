#include "Biblioteca/BibliotecaGenerica.h"
#include "Biblioteca/BibliotecaRegistros.h"
#include "Biblioteca/BibliotecaEnteros.h"

#include <iostream>

constexpr int MAX = 30;

int main() {
    void *arreglo1[MAX]{}, *arreglo2[MAX]{};
    void *lista1, *lista2;

    procesaArreglo(arreglo1, leenum, "Data/numeros1.txt");
    creaLista(arreglo1, lista1, comparanum);
    //imprimeLista(lista1, imprimenum, std::cout);
    procesaArreglo(arreglo2, leenum, "Data/numeros2.txt");
    creaLista(arreglo2, lista2, comparanum);
    //imprimeLista(lista2, imprimenum, std::cout);
    fusionaListas(lista1, lista2, verificanum);
    imprimeLista(lista1, imprimenum, std::cout);
    imprimeLista(lista1, imprimenum, "Reports/Repnum.txt");

    procesaArreglo(arreglo1, leeregistro, "Data/Atenciones1.csv");
    creaLista(arreglo1, lista1, comparareg);
    //imprimeLista(lista1, imprimeregistro, std::cout);
    procesaArreglo(arreglo2, leeregistro, "Data/Atenciones2.csv");
    creaLista(arreglo2, lista2, comparareg);
    //imprimeLista(lista2, imprimeregistro, std::cout);
    fusionaListas(lista1, lista2, verificareg);
    imprimeLista(lista1, imprimeregistro, std::cout);
    imprimeLista(lista1, imprimeregistro, "Reports/Repreg.txt");

    return 0;
}

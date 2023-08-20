/* 
 * File:   Auxiliar.cpp
 * Author: Jorge Fatama Vera (20143258)
 *
 * Created on 18 de agosto de 2023, 08:30 AM
 */
#include <iostream>
#include <iomanip>
using namespace std;
#include "Auxiliar.h"

void leerLibros(){
    char codigo[10];
    char nombreLibro[50];
    char nombreAutor[50];
    int nEjemplares;
    double precio;
    char aux;
    /* Leer cada libro hasta que encontremos el fin de archivo*/
    imprimirCabecera();
    while(true){
        /* Lectura de código */
        cin.getline(codigo, 10, ',');
        if(cin.eof())
            break;
        /* Lectura de nombre del libro */
        cin.getline(nombreLibro, 100, ',');
        /* Lectura de nombre del autor */
        cin.getline(nombreAutor, 100, ',');
        // Opción 1: Trabajar con get()
        /*cin >> nEjemplares;
        cin.get();
        cin >> precio;*/
        // Opción 2: Usar cin
        cin >> nEjemplares >> aux >> precio;
		// Necesario para leer el fin de línea ('\n')
        cin.get();
        
		/* Por el momento, no podemos imprimir todos los libros al
		 *	mismo tiempo, dado que aún no podemos guardar lo leído.
		 */
        imprimirLibro(codigo, nombreLibro, nombreAutor,
            nEjemplares, precio);
    }
}

void imprimirCabecera(){
	/* Por favor, tratar que sus reportes estén bien tabulados y
	 * organizados (no usar por NINGÚN MOTIVO '\t', solo por medio
	 * de setw, setfill, left y right)
	 */
    cout << setw(10) << left << "CODIGO" << setw(40) << "LIBRO"
            << setw(40) <<  "AUTOR" << setw(12) << "EJEMPLARES"
            << setw(14) << right << "PRECIO (S/.)" << endl;
    imprimirLinea(116, '=');
}

void imprimirLibro(const char * codigo, const char * nombreLibro,
        const char * nombreAutor, int ejemplares, double precio){
	/* Necesario junto con fixed para imprimir valores de tipo double
	 * con el formato correcto.
	 */
    cout.precision(2);
    cout << setw(10) << left << codigo << setw(40) << nombreLibro
                 << setw(40) << nombreAutor
                 << setw(8) << ' ' << setw(2) << right
                 << setfill('0') << ejemplares << setfill(' ')
                 << setw(16) << fixed << precio << endl;
}

void imprimirLinea(int nCaracteres, char repetidor){
    for(int i=0; i<nCaracteres; i++)
        cout << repetidor;
    cout << endl;
}
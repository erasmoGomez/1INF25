/* 
 * File:   Auxiliar.h
 * Author: Jorge Fatama Vera (20143258)
 *
 * Created on 18 de agosto de 2023, 08:30 AM
 */

#ifndef AUXILIAR_H
#define AUXILIAR_H

/* RECORDAR: Desde TP vemos diseño descendente, por lo que en LP1 seguiremos
 * insistiendo en esto. Al menos en el archivo de cabecera (.h) tratar de
 * colocar las funciones según diseño descendente.
 */

void leerLibros(ifstream&, ofstream&);
void imprimirCabecera(ofstream&);
void imprimirLibro(ofstream&, const char *, const char *, const char *,
        int, double);
void imprimirLinea(ofstream&, int, char);
void imprimirCadena(ofstream&, const char *);

#endif /* AUXILIAR_H */


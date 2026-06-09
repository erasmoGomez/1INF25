//
// Created by USUARIO on 3/06/2026.
//

#ifndef LAB07_BIBLIOTECA_HERENCIA_UTILS_HPP
#define LAB07_BIBLIOTECA_HERENCIA_UTILS_HPP

#include <iostream>
using namespace std;
#include <iomanip>
#include <fstream>
#include <cstring>

#define ANCHO_REPORTE 70
#define MAX_CAR 100

#define MAX_NOVELAS 10
#define MAX_ENCICLOPEDIAS 10
#define MAX_VERTICALES 10
#define MAX_HORIZONTALES 10

class Utils{
public:
    static void abrir_arch_lectura(ifstream &in, const char *arch);
    static void abrir_arch_escritura(ofstream &out, const char *arch);

    static int leer_int(ifstream &in);
    static double leer_double(ifstream &in);
    static char leer_char(ifstream &in);

    static char* leer_cadena(ifstream &in, char del);
    static char *asignar_cadena(const char *origen);
    static char obtener_caracter_no_repetir();

    static void imprimir_linea(ofstream &out, char c);
    static void imprimir_mensaje_centrado(ofstream& out, const char* mensaje);
};




#endif //LAB07_BIBLIOTECA_HERENCIA_UTILS_HPP

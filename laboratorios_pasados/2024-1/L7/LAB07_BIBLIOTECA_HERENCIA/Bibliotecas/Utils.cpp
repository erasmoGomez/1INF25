//
// Created by USUARIO on 3/06/2026.
//

#include "Utils.hpp"

void Utils::abrir_arch_lectura(ifstream& in, const char* arch){
    in.open(arch, ios::in);
    if (!in.is_open()){
        cout << "ERROR AL ABRIR EL ARCHIVO: " << arch << endl;
        exit(1);
    }
}

void Utils::abrir_arch_escritura(ofstream& out, const char* arch){
    out.open(arch, ios::out);
    if (!out.is_open()){
        cout << "ERROR AL ABRIR EL ARCHIVO: " << arch << endl;
        exit(1);
    }
    out << fixed << setprecision(2);
}

int Utils::leer_int(ifstream& in){
    int num;
    in >> num;
    in.get();
    return num;
}

double Utils::leer_double(ifstream& in){
    double num;
    in >> num;
    in.get();
    return num;
}

char Utils::leer_char(ifstream& in){
    char c;
    in >> c;
    in.get();
    return c;
}

char* Utils::leer_cadena(ifstream& in, char del){
    char buffer[MAX_CAR]{};
    in.getline(buffer, MAX_CAR, del);
    if (in.eof()) return nullptr;
    char *puntero = new char [strlen(buffer) + 1]{};
    strcpy(puntero, buffer);
    return puntero;
}

char* Utils::asignar_cadena(const char* origen){
    if (origen == nullptr) return nullptr;
    char *copia = new char [strlen(origen) + 1];
    strcpy(copia, origen);
    return copia;
}

char Utils::obtener_caracter_no_repetir(){
    static char caracteres[] = {'+', '*', '@', '#', '%', '&', 'O', '-', '=', '8'};
    static int N = sizeof(caracteres) / sizeof(caracteres[0]);
    static int i = 0;

    if (i >= N) return ' ';

    return caracteres[i++];
}

void Utils::imprimir_linea(ofstream& out, char c){
    out << setfill(c) << setw(ANCHO_REPORTE) << "" << endl;
    out << setfill(' ');
}

void Utils::imprimir_mensaje_centrado(ofstream& out, const char *mensaje){
    int longitud = strlen(mensaje);
    int espacio = (ANCHO_REPORTE - longitud) / 2;
    out << setw(espacio) << "" << mensaje << endl;
}

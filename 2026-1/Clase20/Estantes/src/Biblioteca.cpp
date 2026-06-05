//
// Created by Erasmo on 22/10/25.
//

#include "Biblioteca.hpp"

Biblioteca::Biblioteca() {
    cantidad_estantes = 0;
    cantidad_libros = 0;
    cantidad_total_enciclopedias = 0;
    cantidad_total_novelas = 0;
    capacidad_enciclopedias = 0;
}

Biblioteca::Biblioteca(const Biblioteca& orig) {
    *this = orig;
}

Biblioteca::~Biblioteca() {
    //delete[] novelas; No funciona porque es arreglo estatico
    //delete[] enciclopedias; Solamente cuando son dinámicos
    /*Si fueran arreglos dinámicos, se debe hacer de la siguiente manera
     *for (int i=0; i < cantidad_total_enciclopedias; ++i)
        delete enciclopedias[i];
    */
}

void Biblioteca::SetCantidad_libros(int cantidad_libros) {
    this->cantidad_libros = cantidad_libros;
}

int Biblioteca::GetCantidad_libros() const {
    return cantidad_libros;
}

void Biblioteca::SetCantidad_estantes(int cantidad_estantes) {
    this->cantidad_estantes = cantidad_estantes;
}

int Biblioteca::GetCantidad_estantes() const {
    return cantidad_estantes;
}

void Biblioteca::cargar_libros() {
    ifstream input("ArchivosEntrada/libros.csv", ios::in);
    int n=0;
    char tipo;
    while(true){
        input.get(tipo);
        if (input.eof()) break;
        input.get();
        if (tipo == 'N') {
            //Si fuera estático
            novelas[cantidad_total_novelas].leer(input);
            //Si fuera dinámico.
            // if (cantidad_total_novelas == cantidad_total_novelas) reserva_memoria();
            // novelas[cantidad_total_novelas].leer(input);
        }
        else if (tipo == 'E') enciclopedias[cantidad_total_enciclopedias].leer(input);

    }
}

void Biblioteca::cargar_estantes() {
    ifstream input("ArchivosEntrada/estantes2.csv", ios::in);
    int n=0;
    char tipo;
    while(true){
        input.get(tipo);
        if (input.eof())break;
        input.get();
        if (tipo == 'H') {
            estantes_horizontales[cantidad_estantes_h].leer(input);
        }
        else
            estantes_verticales[cantidad_estantes_v].leer(input);
        input.get();
    }
}

void Biblioteca::posicionar_libros() {
    for (int j = 0; j < cantidad_libros; ++j) {
        for (int i = 0; i < cantidad_estantes; ++i) {
            if (estantes[i] += libros[j]) {
                break; // Libro colocado, pasa al siguiente
            }
        }
    }
}

void Biblioteca::imprime_linea(ofstream& output, int n, char c) {
    output << setfill(c) << setw(n) << " " << endl;
    output << setfill(' ');
}

void Biblioteca::reserva_memoria() {
    // capacidad_enciclopedias+=5;
    // if (enciclopedias == nullptr) {
    //     enciclopedias = new Enciclopedia[capacidad_enciclopedias+1];
    // }
    // else {
    //     for (int i=0; i < cantidad_total_enciclopedias; i++) {
    //         aux[i] = enciclopedias[i];
    //     }
    //     delete [] enciclopedias;
    //     enciclopedias = aux;
    // }
}

void Biblioteca::mostrar_datos() {

    ofstream output("reporte.txt", ios::out);
    imprime_linea(output, 50, '=');
    output << right << setw(45) << "Informacion del posicionamiento de Libros" << endl;
    output << right << setw(40) << "en los estantes de la Biblioteca " << endl;
    imprime_linea(output, 50, '=');
    output << "Cantidad de Estantes: " << cantidad_estantes << endl;
    for (int i = 0; i < cantidad_estantes; i++)
        output << estantes[i];
    imprime_linea(output, 50, '=');
    output << "Informacion de todos los Libros: " << endl;
    output << "Cantidad de Libros Total: " << cantidad_libros << endl;
    for (int i = 0; i < cantidad_libros; i++)
        output<<libros[i];
    imprime_linea(output, 50, '=');
    output << endl;
}

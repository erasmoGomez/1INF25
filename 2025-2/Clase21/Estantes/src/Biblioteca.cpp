//
// Created by Erasmo on 22/10/25.
//

#include "Biblioteca.hpp"

Biblioteca::Biblioteca() {
    cantidad_estantes_horizontales = 0;
    cantidad_estantes_verticales = 0;
    cantidad_total_enciclopedias = 0;
    cantidad_total_novelas = 0;
}

Biblioteca::Biblioteca(const Biblioteca &orig) {
}

Biblioteca::~Biblioteca() {
}

int Biblioteca::getCantidadEstantesVerticales() const {
    return cantidad_estantes_verticales;
}

void Biblioteca::setCantidadEstantesVerticales(int cantidadEstantesVerticales) {
    cantidad_estantes_verticales = cantidadEstantesVerticales;
}

int Biblioteca::getCantidadEstantesHorizontales() const {
    return cantidad_estantes_horizontales;
}

void Biblioteca::setCantidadEstantesHorizontales(int cantidadEstantesHorizontales) {
    cantidad_estantes_horizontales = cantidadEstantesHorizontales;
}

int Biblioteca::getCantidadTotalEnciclopedias() const {
    return cantidad_total_enciclopedias;
}

void Biblioteca::setCantidadTotalEnciclopedias(int cantidadTotalEnciclopedias) {
    cantidad_total_enciclopedias = cantidadTotalEnciclopedias;
}

int Biblioteca::getCantidadTotalNovelas() const {
    return cantidad_total_novelas;
}

void Biblioteca::setCantidadTotalNovelas(int cantidadTotalNovelas) {
    cantidad_total_novelas = cantidadTotalNovelas;
}

void Biblioteca::cargar_libros() {
    ifstream input("Data/libros2.csv", ios::in);
    //N, ABC123, El libro de la Selva, 2, 5, Aventura, 0.75
    //E, EFG123, La enciclopedia de la Vida, 2, 4, 1, 6.30
    char tipo;
    while (true) {
        input >> tipo;
        if (input.eof()) break;
        input.get();
        input >> ws;
        if (tipo == 'E') {
            enciclopedias[cantidad_total_enciclopedias].leer(input);
            //input>>enciclopedias[cantidad_total_enciclopedias];
            cantidad_total_enciclopedias++;

        } else {
            novelas[cantidad_total_novelas].leer(input);
            cantidad_total_novelas++;
        }
    }
    cout << "Enciclopedias: " << cantidad_total_enciclopedias << endl;
    cout << "Novelas: " << cantidad_total_novelas << endl;
}

void Biblioteca::cargar_estantes() {
    ifstream input("Data/estantes2.csv", ios::in);
    char tipo;
    //H, AAA, 6, 4, 3
    //V, BBB,  4, 6, 10
    while (true) {
        input >> tipo;
        if (input.eof())break;
        input.get();
        input >> ws;
        if (tipo == 'H') {
            estantesHorizontales[cantidad_estantes_horizontales].leer(input);
            cantidad_estantes_horizontales++;
        } else {
            estantesVerticales[cantidad_estantes_verticales].leer(input);
            cantidad_estantes_verticales++;
        }
    }
    cout << "Verticales: " << cantidad_estantes_verticales << endl;
    cout << "Horizontales: " << cantidad_estantes_horizontales << endl;
}

void Biblioteca::posicionar_libros() {
    //Insertar Enciclopedias
    int f = 0;
    for (int j = 0; j < cantidad_total_enciclopedias; ++j) {
        for (int i = 0; i < cantidad_estantes_verticales; ++i) {
            if (estantesVerticales[i] += enciclopedias[j]) {
                estantesVerticales[i].setEstadoColocado(f, true);
                f++;
                enciclopedias[j].SetColocado(true);
                break; // Enciclopedia colocado, pasa al siguiente
            }
            else {
                f = 0;
            }
        }
    }
    int h = 0;
    for (int k = 0; k < cantidad_total_novelas; ++k) {
        for (int z = 0; z < cantidad_estantes_horizontales; ++z) {

            if (estantesHorizontales[z] += novelas[k]) {
                estantesHorizontales[z].setEstadoColocado(h, true);
                h++;
                novelas[k].SetColocado(true);
                break; // Novela colocado, pasa al siguiente
            }
            else{
                h = 0;
            }
        }
    }
}

void Biblioteca::imprime_linea(ofstream &output, int n, char c) {
    output << setfill(c) << setw(n) << " " << endl;
    output << setfill(' ');
}

void Biblioteca::mostrar_datos() {

    ofstream output("Reports/reporte.txt", ios::out);
    imprime_linea(output, 50, '=');
    output << right << setw(45) << "Informacion del posicionamiento de Libros" << endl;
    output << right << setw(40) << "en los estantes de la Biblioteca " << endl;
    imprime_linea(output, 50, '=');
    output << "Cantidad de Estantes Verticales: " << cantidad_estantes_verticales << endl;
    for (int i = 0; i < cantidad_estantes_verticales; i++)
        output << estantesVerticales[i];
    imprime_linea(output, 50, '=');
    output << "Informacion de todas las Enciclopedias" << endl;
    int sin_colocar_enciclopedias = 0;
    for (int i = 0; i < cantidad_total_enciclopedias; i++)
        if (!enciclopedias[i].IsColocado()) {
            output << enciclopedias[i];
            sin_colocar_enciclopedias++;
        }

    output << "Sin Colocar: " << sin_colocar_enciclopedias << endl;

    imprime_linea(output, 50, '=');
    output << endl;

    imprime_linea(output, 50, '=');
    output << "Cantidad de Estantes Horizontales: " << cantidad_estantes_horizontales << endl;
    for (int i = 0; i < cantidad_estantes_horizontales; i++)
        output << estantesHorizontales[i];
    imprime_linea(output, 50, '=');
    output << "Informacion de todas las Novelas" << endl;
    int sin_colocar_novelas = 0;
    for (int i = 0; i < cantidad_total_novelas; i++)
        if (!novelas[i].IsColocado()) {
            output << novelas[i];
            sin_colocar_novelas++;
        }

    output << "Sin Colocar: " << sin_colocar_novelas << endl;

    imprime_linea(output, 50, '=');
    output << endl;
}
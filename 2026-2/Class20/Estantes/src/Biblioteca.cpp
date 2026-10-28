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
    cantidad_estantes_h = 0;
    cantidad_estantes_v = 0;
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
    ifstream input("ArchivosEntrada/libros2.csv", ios::in);
    char tipo; //tipificacion
    /*N, Se lee en BIBLIOTECA
     *ABC123,El libro de la Selva,2,5, Se lee en LIBRO
     *Aventura,0.75 Se lee en NOVELA/ENCICLOPEDIA
    */
    while(true){
        input.get(tipo);
        if (input.eof()) break;
        input.get();
        if (tipo == 'N') {
            //Si fuera estático
            novelas[cantidad_total_novelas].leer(input); //PRIMERO VA A LEER LIBRO Y LUEGO VA A LEER NOVELA
            cantidad_total_novelas++;
            //Si fuera dinámico. RESERVA DE MEMORIA
            // if (cantidad_total_novelas == capacidad_total_novelas) reserva_memoria();
            // novelas[cantidad_total_novelas].leer(input);
        }
        else if (tipo == 'E') {
            enciclopedias[cantidad_total_enciclopedias].leer(input);
            cantidad_total_enciclopedias++;
        }

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
            cantidad_estantes_h++;
        }
        else{
            estantes_verticales[cantidad_estantes_v].leer(input);
            cantidad_estantes_v++;
        }
        //input.get();
    }
}

void Biblioteca::posicionar_libros() {
    //cout<<cantidad_estantes_h<<endl;
    //cout<<cantidad_total_enciclopedias<<endl;
    for (int j = 0; j < cantidad_total_enciclopedias; ++j) {
        for (int i = 0; i < cantidad_estantes_h; ++i) {
            if (estantes_horizontales[i] += enciclopedias[j]) { // PUEDO O NO PUEDO INGRESAR EL LIBRO EN EL ESTANTE
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
    // if (enciclopedias_dinamico == nullptr) {
    //     enciclopedias_dinamico = new Enciclopedia[capacidad_enciclopedias+1];
    // }
    // else {
    //     for (int i=0; i < cantidad_total_enciclopedias; i++) {
    //         aux[i] = enciclopedias_dinamico[i];
    //     }
    //     delete [] enciclopedias_dinamico;
    //     enciclopedias = aux;
    // }
}

void Biblioteca::mostrar_datos() {

    ofstream output("ArchivosSalida/reporte.txt", ios::out);
    imprime_linea(output, 50, '=');
    output << right << setw(45) << "Informacion del posicionamiento de Libros" << endl;
    output << right << setw(40) << "en los estantes de la Biblioteca " << endl;
    imprime_linea(output, 50, '=');
    output << "Cantidad de Estantes Horizontales: " << cantidad_estantes_h << endl;
    for (int i = 0; i < cantidad_estantes_h; i++)
        output << estantes_horizontales[i];
    imprime_linea(output, 50, '=');
    //
    // output << "Informacion de todos los Libros: " << endl;
    // output << "Cantidad de Libros Total: " << cantidad_libros << endl;
    // for (int i = 0; i < cantidad_libros; i++)
    //     output<<libros[i];
    // imprime_linea(output, 50, '=');
    // output << endl;
}

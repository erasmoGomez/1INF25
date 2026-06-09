//
// Created by USUARIO on 3/06/2026.
//

#include "Biblioteca.hpp"

Biblioteca::Biblioteca(){
    inicializar();
}

int Biblioteca::get_cantidad_estantes_verticales() const{
    return cantidad_estantes_verticales;
}

void Biblioteca::set_cantidad_estantes_verticales(int cantidad_estantes_verticales){
    this->cantidad_estantes_verticales = cantidad_estantes_verticales;
}

int Biblioteca::get_cantidad_estantes_horizontales() const{
    return cantidad_estantes_horizontales;
}

void Biblioteca::set_cantidad_estantes_horizontales(int cantidad_estantes_horizontales){
    this->cantidad_estantes_horizontales = cantidad_estantes_horizontales;
}

int Biblioteca::get_cantidad_total_enciclopedias() const{
    return cantidad_total_enciclopedias;
}

void Biblioteca::set_cantidad_total_enciclopedias(int cantidad_total_enciclopedias){
    this->cantidad_total_enciclopedias = cantidad_total_enciclopedias;
}

int Biblioteca::get_cantidad_total_novelas() const{
    return cantidad_total_novelas;
}

void Biblioteca::set_cantidad_total_novelas(int cantidad_total_novelas){
    this->cantidad_total_novelas = cantidad_total_novelas;
}

void Biblioteca::agregar_novela(ifstream& in){
    Novela novela;
    novela.leer(in);
    novelas[cantidad_total_novelas] = novela;
    cantidad_total_novelas++;
}

void Biblioteca::agregar_enciclopedia(ifstream& in){
    Enciclopedia enciclopedia;
    enciclopedia.leer(in);
    enciclopedias[cantidad_total_enciclopedias] = enciclopedia;
    cantidad_total_enciclopedias++;
}

void Biblioteca::cargar_libros(const char* arch){
    ifstream in;
    Utils::abrir_arch_lectura(in, arch);
    while (true){
        char tipo_libro = Utils::leer_char(in);
        if (in.eof()) break;
        if (tipo_libro == 'N'){
            agregar_novela(in);
        }
        else if (tipo_libro == 'E'){
            agregar_enciclopedia(in);
        }
        else in.ignore(500, '\n');
    }


    in.close();
}

void Biblioteca::agregar_estante_horizontal(ifstream& in){
    EstanteHorizontal eh;
    eh.leer(in);
    estantesHorizontales[cantidad_estantes_horizontales] = eh;
    cantidad_estantes_horizontales++;
}

void Biblioteca::agregar_estante_vertical(ifstream& in){
    EstanteVertical ev;
    ev.leer(in);
    estantesVerticales[cantidad_estantes_verticales] = ev;
    cantidad_estantes_verticales++;
}

/*
H, AAA, 8, 5
V, BBB, 4, 6
…
*/

void Biblioteca::cargar_estantes(const char* arch){
    ifstream in;
    Utils::abrir_arch_lectura(in, arch);
    while (true){
        char tipo_estante = Utils::leer_char(in);
        if (in.eof()) break;
        in.get(); //por ese espacio
        if (tipo_estante == 'H'){
            agregar_estante_horizontal(in);
        }
        else if (tipo_estante == 'V'){
            agregar_estante_vertical(in);
        }
        else in.ignore(500, '\n');
    }
}


void Biblioteca::posicionar_libros_estantes_horizontales(){
    for (int i = 0; i < cantidad_estantes_horizontales; i++){
        for (int j = 0; j < cantidad_total_novelas; j++){
            estantesHorizontales[i].verificar_posicionar_novela_estante_horizontal(novelas[j]);
        }
    }
}

void Biblioteca::posicionar_libros_estantes_verticales(){
    for (int i = 0; i < cantidad_estantes_verticales; i++){
        for (int j = 0; j < cantidad_total_enciclopedias; j++){
            estantesVerticales[i].verificar_posicionar_estante_vertical(enciclopedias[j]);
        }
    }
}

void Biblioteca::posicionar_libros(){
    //LA REPRESENTACIÓN GRÁFICA/FÍSICA SE DARÁ CON LOS ESPACIOS

    posicionar_libros_estantes_horizontales();
    posicionar_libros_estantes_verticales();

}

/*
N, ABC123, El libro de la Selva, 2, 5, Aventura, 0.75
E, EFG123, La enciclopedia de la Vida, 2, 4, 1, 6.30
…
Tipo de libro, código de libro, descripción de libro, ancho, alto, tipo/volumen, peso
 */

void Biblioteca::inicializar(){
    cantidad_estantes_horizontales = 0;
    cantidad_estantes_verticales = 0;
    cantidad_total_enciclopedias = 0;
    cantidad_total_novelas = 0;
}

void Biblioteca::imprimir_titulo_informe(ofstream& out) const{
    Utils::imprimir_linea(out, '=');
    Utils::imprimir_mensaje_centrado(out, "INFORMACION DEL POSICIONAMIENTO DE LIBROS");
    Utils::imprimir_mensaje_centrado(out, "EN LOS ESTANTES DE LA BIBLIOTECA");
    Utils::imprimir_linea(out, '=');
    int total_estantes = cantidad_estantes_horizontales + cantidad_estantes_verticales;
    out << "CANTIDAD DE ESTANTES: " << total_estantes << endl;
    Utils::imprimir_linea(out, '-');
}


void Biblioteca::mostrar_datos() const{
    ofstream out;
    Utils::abrir_arch_escritura(out, "ArchivosDeReporte/InformeBiblioteca.txt");
    imprimir_titulo_informe(out);
    for (int i = 0; i < cantidad_estantes_horizontales; i++){
        estantesHorizontales[i].imprimir_informe_horizontal(out);
    }
    for (int j = 0; j < cantidad_estantes_verticales; j++){
        estantesVerticales[j].imprimir_informe_vertical(out);
    }
    out.close();
}
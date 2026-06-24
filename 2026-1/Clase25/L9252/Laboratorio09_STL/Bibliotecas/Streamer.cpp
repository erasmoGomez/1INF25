//
// Created by erasmo on 6/23/26.
//

#include "Streamer.hpp"

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "Categoria.hpp"
#include "Etiqueta.hpp"
#include "Comentario.hpp"

Streamer::Streamer() {
    fecha = 0;
}

string Streamer::get_canal() const {
    return canal;
}

void Streamer::set_canal(const string &canal) {
    this->canal = canal;
}

int Streamer::get_fecha() const {
    return fecha;
}

void Streamer::set_fecha(int fecha) {
    this->fecha = fecha;
}

string Streamer::get_etiquetas_str() const {
    return etiquetasStr;
}

void Streamer::set_etiquetas_str(const string &etiquetas_str) {
    etiquetasStr = etiquetas_str;
}

string Streamer::get_idioma() const {
    return idioma;
}

void Streamer::set_idioma(const string &idioma) {
    this->idioma = idioma;
}

void Streamer::leer(ifstream &arch) {
    int dia, mes, anio;
    char c;
    string codCat;

    getline(arch, canal, ',');
    arch >> dia >> c >> mes >> c >> anio;
    fecha = dia + mes * 100 + anio * 10000;
    arch.get();
    getline(arch, codCat, ',');
    categoria.set_codigo(codCat);
    getline(arch, etiquetasStr, ',');
    getline(arch, idioma);
}

void Streamer::imprimir(ofstream &arch) const {
    arch << "CANAL : " << canal << endl;
    arch << "FECHA : " << fecha << endl;
    arch << "LENGUAJE: " << idioma << endl;
    arch << "CATEGORIA:" << endl;
    arch << "  CODIGO: " << categoria.get_codigo() << endl;
    arch << "  NOMBRE: " << categoria.get_nombre() << endl;
    arch << "  DESCRIPCION: " << categoria.get_descripcion() << endl;
    arch << "ETIQUETAS STR: " << etiquetasStr << endl;
    arch << "ETIQUETAS: " << endl;
    int i = 0;
    for (class Etiqueta e: etiquetasVector)
        arch << setw(2) << ++i << ") CODIGO: " << e.get_codigo()
             << " NOMBRE: " << e.get_nombre() << endl;

    arch << "COMENTARIOS: " << endl;
    i = 0;
    for (string c: comentarios)
        arch << setw(2) << ++i << ") " << c << endl;
}

void operator>>(ifstream &arch, class Streamer &str) {
    str.leer(arch);
}

void operator<<(ofstream &arch, const class Streamer &str) {
    str.imprimir(arch);
}

string Streamer::get_codCat() {
    return categoria.get_codigo();
}

void Streamer::setNomDesc(string nomb, string desc) {
    categoria.set_nombre(nomb);
    categoria.set_descripcion(desc);
}

void Streamer::asignarEtiqueta(const class Etiqueta &eti) {
    etiquetasVector.push_back(eti);
}

void Streamer::setComentario(string coment) {
    comentarios.push_back(coment);
}

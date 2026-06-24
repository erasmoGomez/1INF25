//
// Created by erasmo on 6/23/26.
//



#include <iostream>
#include <fstream>
#include <iomanip>
#include <iterator>
using namespace std;
#include "SistemaDeGestion.hpp"
#include "Categoria.hpp"
#include "Comentario.hpp"
#include "Etiqueta.hpp"
#include "Streamer.hpp"

void SistemaDeGestion::cargarCategoria(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    class Categoria cat;
    while (true) {
        arch >> cat;
        if (arch.eof()) break;
        categorias.push_back(cat);
    }
    categorias.sort();
}

void SistemaDeGestion::cargarComentarios(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    class Comentario com;
    while (true) {
        arch >> com;
        if (arch.eof()) break;
        comentarios.push_back(com);
    }
    comentarios.sort();
}

void SistemaDeGestion::cargarEtiquetas(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    class Etiqueta eti;
    while (true) {
        arch >> eti;
        if (arch.eof()) break;
        etiquetas[eti.get_codigo()] = eti;
        //etiquetas.insert({eti.get_codigo(), eti});
        // pair<string, class Etiqueta>
        // {key,value}
    }
}

void SistemaDeGestion::cargarStreamers(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    class Streamer str;
    while (true) {
        arch >> str;
        if (arch.eof()) break;
        streamers.push_back(str);
    }
}

void SistemaDeGestion::mostrarReporte(const char *nombArch) {
    ofstream arch(nombArch, ios::out);
    if (not arch.is_open()) {
        cout << "Error: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }

    arch << endl << "COMENTARIOS:" << endl;
    for (class Comentario c: comentarios)
        c.imprimir(arch);

    arch << endl << setw(25) << "RELACION DE STREAMERS:" << endl;
    for (class Streamer s: streamers) {
        imprimeLinea(arch, '-', 50);
        s.imprimir(arch);
    }
}

void SistemaDeGestion::completarStreamers() {
    string codCat, sgEtiqutas, eti, can;
    for (class Streamer &s: streamers) {
        codCat = s.get_codCat();
        for (class Categoria c: categorias)
            if (codCat == c.get_codigo()) {
                s.setNomDesc(c.get_nombre(), c.get_descripcion());
                break;
            }

        sgEtiqutas = s.get_etiquetas_str();
        for (int i = 0; i < (int)sgEtiqutas.length(); i += 7) {
            eti = sgEtiqutas.substr(i, 6);
            map<string, class Etiqueta>::iterator it;
            it = etiquetas.find(eti);
            if (it != etiquetas.end()) {
                s.asignarEtiqueta(it->second);
            }
        }

        can = s.get_canal();
        for (class Comentario c: comentarios) {
            if (can == c.get_canal())
                s.setComentario(c.get_comentario());
        }
    }
}

void SistemaDeGestion::imprimeLinea(ofstream &arch, char c, int n) {
    for (int i = 0; i < n; i++)
        arch.put(c);
    arch << endl;
}

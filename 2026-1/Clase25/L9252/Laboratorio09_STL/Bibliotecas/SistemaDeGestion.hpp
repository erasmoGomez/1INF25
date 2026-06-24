//
// Created by erasmo on 6/23/26.
//

#ifndef LABORATORIO09_STL_SISTEMADEGESTION_HPP
#define LABORATORIO09_STL_SISTEMADEGESTION_HPP

#include <list>
#include <map>
#include <fstream>
using namespace std;
#include "Categoria.hpp"
#include "Comentario.hpp"
#include "Etiqueta.hpp"
#include "Streamer.hpp"
class SistemaDeGestion {
private:
    list<class Categoria> categorias;
    list<class Comentario> comentarios;
    map<string, class Etiqueta> etiquetas;
    list<class Streamer> streamers;
public:
    void cargarCategoria(const char *nombArch);
    void cargarComentarios(const char *nombArch);
    void cargarEtiquetas(const char *nombArch);
    void cargarStreamers(const char *nombArch);
    void completarStreamers();
    void mostrarReporte(const char *nombArch);
    void imprimeLinea(ofstream &arch, char c, int n);
};



#endif //LABORATORIO09_STL_SISTEMADEGESTION_HPP
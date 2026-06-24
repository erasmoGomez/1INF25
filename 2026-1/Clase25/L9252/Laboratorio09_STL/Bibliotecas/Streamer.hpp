//
// Created by erasmo on 6/23/26.
//

#ifndef LABORATORIO09_STL_STREAMER_HPP
#define LABORATORIO09_STL_STREAMER_HPP
#include <string>
#include <vector>
#include <map>
#include <fstream>
using namespace std;
#include "Categoria.hpp"
#include "Etiqueta.hpp"

class Streamer {
private:
    string canal;
    int fecha;
    class Categoria categoria;
    string etiquetasStr;
    vector<class Etiqueta> etiquetasVector;
    string idioma;
    vector<string> comentarios;
public:
    Streamer();
    string get_canal() const;
    void set_canal(const string &canal);
    int get_fecha() const;
    void set_fecha(int fecha);
    string get_etiquetas_str() const;
    void set_etiquetas_str(const string &etiquetas_str);
    string get_idioma() const;
    void set_idioma(const string &idioma);
    string get_codCat();
    void setNomDesc(string nomb, string desc);
    void leer(ifstream &arch);
    void imprimir(ofstream &arch) const;
    void asignarEtiqueta(const class Etiqueta &eti);
    void setComentario(string coment);
};

void operator>>(ifstream &arch, class Streamer &str);
void operator<<(ofstream &arch, const class Streamer &str);


#endif //LABORATORIO09_STL_STREAMER_HPP
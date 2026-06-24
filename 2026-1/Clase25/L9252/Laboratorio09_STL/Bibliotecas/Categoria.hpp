//
// Created by erasmo on 6/23/26.
//

#ifndef LABORATORIO09_STL_CATEGORIA_HPP
#define LABORATORIO09_STL_CATEGORIA_HPP

#include <string>
#include <fstream>
using namespace std;
class Categoria {
private:
    string codigo;
    string nombre;
    string descripcion;
public:
    string get_codigo() const;
    void set_codigo(const string &codigo);
    string get_nombre() const;
    void set_nombre(const string &nombre);
    string get_descripcion() const;
    void set_descripcion(const string &descripcion);
    void leer(ifstream &arch);
    void imprimir(ofstream &arch) const;
    bool operator<(const Categoria &cat) const;
};

void operator>>(ifstream &arch, class Categoria &cat);
void operator<<(ofstream &arch, const class Categoria &cat);


#endif //LABORATORIO09_STL_CATEGORIA_HPP
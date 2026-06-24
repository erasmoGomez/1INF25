//
// Created by erasmo on 6/23/26.
//

#ifndef LABORATORIO09_STL_ETIQUETA_HPP
#define LABORATORIO09_STL_ETIQUETA_HPP

#include <string>
#include <fstream>
using namespace std;
class Etiqueta {
private:
    string codigo;
    string nombre;
public:
    string get_codigo() const;
    void set_codigo(const string &codigo);
    string get_nombre() const;
    void set_nombre(const string &nombre);
    void leer(ifstream &arch);
    void imprimir(ofstream &arch) const;
};

void operator>>(ifstream &arch, class Etiqueta &eti);
void operator<<(ofstream &arch, const class Etiqueta &eti);


#endif //LABORATORIO09_STL_ETIQUETA_HPP
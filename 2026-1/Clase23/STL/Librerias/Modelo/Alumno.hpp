//
// Created by erasmo on 6/16/26.
//

#ifndef STL_ALUMNO_HPP
#define STL_ALUMNO_HPP
#include "../Util/Utils.hpp"

class Alumno {
private:
    int codigo;
    string nombre;
    vector<int> notas;
    bool aprobado;

public:
    Alumno();

    ~Alumno();

    int get_codigo() const;

    void set_codigo(int codigo);

    string get_nombre() const;

    void set_nombre(const string &nombre);

    bool is_aprobado() const;

    void set_aprobado(bool aprobado);

    void imprimir(ostream&);

};

void operator<<(ostream &,Alumno& alumno);
#endif //STL_ALUMNO_HPP

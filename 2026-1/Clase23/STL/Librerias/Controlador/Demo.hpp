//
// Created by erasmo on 6/17/26.
//

#ifndef STL_DEMO_HPP
#define STL_DEMO_HPP
#include "../Modelo/Alumno.hpp"


class Demo {
private:
    vector <int> codigos;
    vector <string> nombres;
    vector <Alumno> alumnos;
    list <Alumno*> lista_alumnos;
    map<string, Alumno> dicionario_alumnos;
public:
    void demo_vector_lectura();

    void demo_lectura();

    void demo_vector_escritura();

    void demo_escritura();
};


#endif //STL_DEMO_HPP
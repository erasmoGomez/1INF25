//
// Created by erasmo on 6/17/26.
//

#include "Demo.hpp"

void Demo::demo_vector_lectura() {
    cout<<"Demo Lectura en Vectors"<<endl;
    //Funciona como un arreglo dinámico
    int codigo;
    codigos.push_back(codigo);
    cout<<"El size del vector es:"<<codigos.size()<<endl;
    cout<<"La capacidad del vector es:"<<codigos.capacity()<<endl;
    codigos.push_back(codigo);
    codigos.push_back(codigo);
    codigos.push_back(codigo);
    codigos.push_back(codigo);
    cout<<"El size del vector es:"<<codigos.size()<<endl;
    cout<<"La capacidad del vector es:"<<codigos.capacity()<<endl;
    codigos.shrink_to_fit();
    cout<<"El size del vector es:"<<codigos.size()<<endl;
    cout<<"La capacidad del vector es:"<<codigos.capacity()<<endl;

    //string
    string nombre;
    nombre = "erasmo gomez";
    nombres.push_back(nombre);
    char* nombre_ptr;
    nombre_ptr = new char[nombre.length()+1];
    strcpy(nombre_ptr,nombre.c_str());
    nombres.push_back(nombre_ptr);
    char nombre_buffer[30] = "Erasmo Gomez";
    nombres.push_back(nombre_buffer);

    //Objetos
    Alumno alumno;
    alumno.set_codigo(20082060);
    alumno.set_nombre("Erasmo Gomez");
    alumno.set_aprobado(true); //obvio ?
    alumnos.push_back(alumno);
}

void Demo::demo_lectura() {
    cout<<"Demo Lectura"<<endl;
    demo_vector_lectura();

}

void Demo::demo_vector_escritura() {
    cout<<"Demo Lectura en Vectors"<<endl;
    for (Alumno& alumno : alumnos) {
        cout << alumno;
    }
    cout << endl;
}

void Demo::demo_escritura() {
    demo_vector_escritura();
}

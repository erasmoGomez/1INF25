#include <iostream>
#include <ostream>

#include "Librerias/Funciones.hpp"

int main() {
    cout<<"Hello World!"<<endl;
    int a = suma(50);
    cout<<a<<endl;
    char *nombre;
    nombre = leer_cadena(' ');
    cout<<nombre<<endl;
    return 0;
}
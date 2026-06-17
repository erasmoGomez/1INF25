#include "src/Plantilla.hpp"
#include "src/Persona.hpp"

int main() {
//    class Plantilla<int> obj_int;
//    obj_int.leer();
//    obj_int.imprimir();
//
//    class Plantilla<double> obj_double;
//    obj_double.leer();
//    obj_double.imprimir();
//
//    class Plantilla<string> obj_string;
//    obj_string.leer();
//    obj_string.imprimir();

//    class Plantilla<int*> obj_pointer; //No se puede hacer
//    obj_pointer.leer();
//    obj_pointer.imprimir();

    class Plantilla<class Persona> obj_persona;
    obj_persona.leer();
    obj_persona.imprimir();

//    Persona p;
//    cin>>p;
//    cout<<p;
    return 0;
}

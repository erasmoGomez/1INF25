#include "src/Persona.hpp"

int main() {
//    list<int> codigos{20082060, 20082061, 20082131};
//    list<string> nombres{"Erasmo", "Marcia", "Cyndi"};
//
//    for(int codigo: codigos) // Qué es esto? For Each
//        cout<<codigo<<endl;
//
//    for(auto &nombre: nombres)
//        cout<<nombre<<endl;
//
//    list<list<list<string>>> empresa{
//            {   // Departamento 1: Ingeniería
//                    {{"Carlos", "María", "Erasmo"}},       // Equipo Backend
//                    {{"Lucía", "José", "Rony"}}            // Equipo Frontend
//            },
//            {   // Departamento 2: Ventas
//                    {{"Diana", "Rafael", "Esteban"}},      // Equipo Lima
//                    {{"Martina", "Kevin", "Camila"}}       // Equipo Cusco
//            },
//            {   // Departamento 3: Soporte
//                    {{"Rosa", "Jorge", "Patricia"}},       // Equipo Telefónico
//                    {{"Pedro", "Andrea", "Valeria"}}       // Equipo en campo
//            }
//    };
//
//    // Mostrar todo el contenido
//    int d = 1;
//    for (auto &departamento : empresa) {
//        cout << "Departamento " << d++ << ":" << endl;
//        int e = 1;
//        for (auto &equipo : departamento) {
//            cout << "  Equipo " << e++ << ": ";
//            for (auto &nombre : equipo) {
//                cout << nombre << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }

    list<class Persona> personas;
    Persona p1, p2, p3;
    p1.SetNombre("Erasmo");
    p1.SetDni(454646656);
    p1.SetSueldo(2.5);
    p2.SetNombre("Charly");
    p2.SetDni(1111111);
    p2.SetSueldo(500);
    p3.SetNombre("Huarote");
    p3.SetDni(777777);
    p3.SetSueldo(450);
//    cout<<p2<<endl;
    personas.push_back(p1);
    personas.push_back(p2);
    personas.push_back(p3);

    //cout<<personas.size()<<endl;
//
    //cout<<personas.front();
    for(auto& persona: personas)
        cout<<persona;
    cout<<endl;

    personas.sort();

    for(auto& persona: personas)
        cout<<persona;
    cout<<endl;
    return 0;
}

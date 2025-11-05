#include <list>
#include <iterator>
#include <string>
#include <iostream>
using namespace std;

int main() {
    list<int> codigos{20082060, 20082061, 20082131};
    list<string> nombres{"Erasmo", "Marcia", "Cyndi"};

    for(int codigo: codigos) // Qué es esto? For Each
        cout<<codigo<<endl;

    for(auto &nombre: nombres)
        cout<<nombre<<endl;

    list<list<list<string>>> empresa{
            {   // Departamento 1: Ingeniería
                    {{"Carlos", "María", "Erasmo"}},       // Equipo Backend
                    {{"Lucía", "José", "Rony"}}            // Equipo Frontend
            },
            {   // Departamento 2: Ventas
                    {{"Diana", "Rafael", "Esteban"}},      // Equipo Lima
                    {{"Martina", "Kevin", "Camila"}}       // Equipo Cusco
            },
            {   // Departamento 3: Soporte
                    {{"Rosa", "Jorge", "Patricia"}},       // Equipo Telefónico
                    {{"Pedro", "Andrea", "Valeria"}}       // Equipo en campo
            }
    };

    // Mostrar todo el contenido
    int d = 1;
    for (auto &departamento : empresa) {
        cout << "Departamento " << d++ << ":" << endl;
        int e = 1;
        for (auto &equipo : departamento) {
            cout << "  Equipo " << e++ << ": ";
            for (auto &nombre : equipo) {
                cout << nombre << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

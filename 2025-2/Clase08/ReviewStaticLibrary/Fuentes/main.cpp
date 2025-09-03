#include "src/SobrecargasPersona.hpp"

int main() {
//    Persona p, p2;
//    p.dni = 12345321;
//    strcpy(p.name,"Erasmo_Gomez");
//    p.weight = 100.5;
//    p.height = 1.67;
//    add_headers();
//    cout<<p;

//    ifstream input("personas.txt", ios::in);
////    input>>p2;
//    cout<<p2;
//    ofstream output("reporte.txt", ios::out);
//    struct Persona people[20];
//    read_people(input, people);
//    display_people(output, people);
    ifstream input("Data/personas.txt", ios::in);
    ofstream output("Reports/reporte.txt", ios::out);
    struct Persona people[20];
    struct Persona p;
    input >> p;
    people[0] = p;
    return 0;
}

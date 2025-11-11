#include "src/Persona.hpp"

int main() {
//    vector <int> codigos;
//    cout<<"Size: "<<codigos.size()<<endl;
//    cout<<"Capacity: "<<codigos.capacity()<<endl;
//
//    codigos.push_back(20082060);
//    cout<<"Size: "<<codigos.size()<<endl;
//    cout<<"Capacity: "<<codigos.capacity()<<endl;
//    codigos.push_back(20082062);
//    cout<<"Size: "<<codigos.size()<<endl;
//    cout<<"Capacity: "<<codigos.capacity()<<endl;
//    codigos.push_back(20082031);
//    cout<<"Size: "<<codigos.size()<<endl;
//    cout<<"Capacity: "<<codigos.capacity()<<endl;
//    codigos.push_back(20082101);
//    cout<<"Size: "<<codigos.size()<<endl;
//    cout<<"Capacity: "<<codigos.capacity()<<endl;
//    codigos.push_back(20082096);
//    cout<<"Size: "<<codigos.size()<<endl;
//    cout<<"Capacity: "<<codigos.capacity()<<endl;
//    codigos.shrink_to_fit();
//    cout<<"Size: "<<codigos.size()<<endl;
//    cout<<"Capacity: "<<codigos.capacity()<<endl;
//
//    for(int dato: codigos)
//        cout<<dato<<endl;
//
//    for(int i=0; i<codigos.size();i++)
//        cout<<codigos[i]<<endl;
//
//    //codigos.assign(2, 19);
//    for(int i=0; i<codigos.size();i++)
//        cout<<codigos[i]<<endl;
//
//    vector<int> notas;
//    cout<<notas.empty()<<endl;
//    if(notas.empty())
//        notas.push_back(20);
//    else
//        notas.push_back(10);
//
//    for(int dato: notas)
//        cout<<dato<<endl;
//
//    //Ordenar
//    sort(codigos.begin(), codigos.end());
//    for(int dato: codigos)
//        cout<<dato<<endl;

    vector<class Persona> personas;
    ifstream input("Data/personal.csv", ios::in);
    ofstream output("Reports/reporte.txt", ios::out);

    Persona persona;
    while(true){
        input>>persona;
        if(input.eof())break;
        personas.push_back(persona);
    }
    sort(personas.begin(), personas.end());
    //personas

    for(const Persona& p: personas)
        output<<p;
    output<<endl;
    return 0;
}

#include "src/Persona.hpp"

int main() {
    vector<string> edades;
    map<string, int> edades_profesores;
    map<int, string> profesores_edades;
    // map<class Persona, string> personas;  // Sobrecargar <
    //insertar datos por default inserta de manera ascendente por el KEY
    edades_profesores.insert({"erasmo", 32});
    edades_profesores.insert({"rony", 52});
    edades_profesores.insert({"miguel", 62});

    profesores_edades.insert({32, "erasmo"});
    profesores_edades.insert({52, "rony"});

    //imprimir un solo elemento
    cout << edades_profesores["erasmo"] << endl;
    cout << profesores_edades[32] << endl;
    //imprimir todo el mapa
    cout<<"Imprimiendo el mapa"<<endl;
    for(auto& elemento:edades_profesores){
        cout<<setw(20)<<elemento.first; //Devolver el KEY
        cout<<setw(5)<<elemento.second<<endl; //Devolver el VALUE
    }
//
//    edades_profesores["erasmo"] = 50;
//    edades_profesores["erasmos"] = 50;
//    cout<<"Imprimiendo el mapa 2"<<endl;
//    for(auto& elemento:edades_profesores){
//        cout<<setw(20)<<elemento.first; //Devolver el KEY
//        cout<<setw(5)<<elemento.second<<endl; //Devolver el VALUE
//    }
//
    cout<<edades_profesores.size()<<endl;
    auto it = edades_profesores.find("rony");
    cout<<"La edad del profesor Rony es : "<< it->second <<endl;
//
    map<string, Persona>personas;

    Persona h1, h2, h3;
    h1.SetSueldo(500);
    h2.SetSueldo(600);
    h1.SetNombre("Andres");
    h2.SetNombre("Eric");
    h3.SetSueldo(800);
    h3.SetNombre("Ana");
    personas.insert({h1.GetNombre(), h1});
    personas.insert({h2.GetNombre(), h2});
    personas.insert({h3.GetNombre(), h3});
////    personas["Andres"] = h1;
////    personas["Huiza"] = h2;
//
    cout<<"Imprimiendo el mapa 3"<<endl;
    for(auto& elemento:personas){
        cout<<setw(20)<<elemento.first; //Devolver el KEY
        cout<<setw(5)<<elemento.second<<endl; //Devolver el VALUE
    }
    return 0;
}

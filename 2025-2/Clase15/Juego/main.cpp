#include "src/Juego.hpp"

int main() {
    //Uso constructor por DEFECTO
//    class Heroe h; //Instanciar un Objeto a partir de una clase
//    //Usar getter y setters;
//    //Setters para guardar informacion dentro de mi objeto instanciado
//    h.setId("H01");
//    h.setNombre("Teemo");
//    h.setHp(100);
//    h.setDefensa(50);
//    h.setFuerza(45.77);
//    //h.setPosx(10);
//    //h.setPosy(20);
//
//    char id[10], nombre[20];
//    h.getId(id);
//    h.getNombre(nombre);
//    cout<<"El ID del Heroe es : "<<id<<endl;
//    cout<<"El NOMBRE del Heroe es : "<<nombre<<endl;
//    cout<<"La POSICION del Heroe es : "<<h.getPosx()<<" : "<<h.getPosy()<<endl;
    //Uso constructor con Parametros
//    class Heroe h2("Ash", 150, 50, 50, 10, 10);
//    char nombre[20];
//    h2.getNombre(nombre);
//    cout<<"HP: "<<h2.getHp()<<endl;
//    cout<<"Nombre: "<<nombre<<endl;
//
//    class Heroe h3("Erasmo");
//    char nombre_1[20];
//    h3.getNombre(nombre_1);
//    cout<<"HP: "<<h3.getHp()<<endl;
//    cout<<"Nombre: "<<nombre_1<<endl;
//
//    ofstream output("Reports/info_heroes.txt", ios::out);
//
//    h2.mostrar_info(output);
    // Carga de un heroe
//    ifstream input("Data/heroes.csv", ios::in);
//    ofstream output("Reports/reporte_heroes.txt", ios::out);
//
//    class Heroe heroes[10]; // Declara un arreglo de heroes.
//    int n_heroes = 0;
//    //cout<<"La fuerza del Heroe 2 es: "<<heroes[2].getFuerza()<<endl;
//
//    while(true){
//        class Heroe h;
//        h.cargar_datos(input);
//        if(input.eof())break;
//        heroes[n_heroes] = h;
//        n_heroes++;
//    }
//    cout<<n_heroes<<endl;
//
//    for(int i=0; i<n_heroes; i++)
//        heroes[i].mostrar_info(output);
    class Juego juego;
    juego.cargar_heroes();
//    juego.ordenar_heroes();
//    juego.clonar_cristo();
    juego.mostrar_heroes();
    //Sobrecarga de operadores para Objetos
//    heroe ++; // Moverse hacia arriba
//    ++ heroe; // Moverse hacia abajo
//    heroe --; // Moverse hacia la derecha
//    -- heroe; // Moverse hacia la izq
    return 0;
}

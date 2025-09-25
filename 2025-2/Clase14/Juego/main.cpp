#include "src/Heroe.hpp"

int main() {
    class Heroe h; //Instanciar un Objeto a partir de una clase
    //Usar getter y setters;
    //Setters para guardar informacion dentro de mi objeto instanciado
    h.setId("H01");
    h.setNombre("Teemo");
    h.setHp(100);
    h.setDefensa(50);
    h.setFuerza(45.77);
    //h.setPosx(10);
    //h.setPosy(20);

    char id[10], nombre[20];
    h.getId(id);
    h.getNombre(nombre);
    cout<<"El ID del Heroe es : "<<id<<endl;
    cout<<"El NOMBRE del Heroe es : "<<nombre<<endl;
    cout<<"La POSICION del Heroe es : "<<h.getPosx()<<" : "<<h.getPosy()<<endl;
    return 0;
}

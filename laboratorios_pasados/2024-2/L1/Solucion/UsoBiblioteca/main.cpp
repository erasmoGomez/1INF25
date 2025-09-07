#include "src/Sobrecargas.hpp"

int main() {
    ifstream input_platos;
    input_platos.open("Data/PlatosOfrecidos.csv", ios::in);
    struct Plato plato{};
    input_platos >> plato; //Sobrecarga
    input_platos >> plato1; //Sobrecarga
    input_platos >> plato2; //Sobrecarga
    input_platos >> plato3; //Sobrecarga
    input_platos >> plato4; //Sobrecarga
    struct Plato platos[20];
    platos+=plato1;
    plato2.cambi = 0;
    platos+=platos2;
    //Prueba de la sobrecarga
    cout<<"Este es el nombre del plato: "<<plato.nombre<< " Este es esu precio: "<<plato.precio<<endl;
    return 0;
}

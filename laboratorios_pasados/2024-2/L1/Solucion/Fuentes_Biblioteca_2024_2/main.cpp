#include "src/AperturaDeArchivos.hpp"
#include "src/Sobrecargas.hpp"

int main() {
    ifstream input_platos;
    AperturaDeUnArchivoDeTextosParaLeer(input_platos, "Data/PlatosOfrecidos.txt");
    struct Plato plato{};
    input_platos >> plato; //Sobrecarga
    //Prueba de la sobrecarga
    cout<<"Este es el nombre del plato: "<<plato.nombre<< " Este es esu precio: "<<plato.precio<<endl;
    return 0;
}

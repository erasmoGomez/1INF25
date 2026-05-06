#include "Librerias/BibliotecaGenerica.hpp"
#include "Librerias/ListaConEnteros.hpp"
#include "Librerias/ListaConRegistros.hpp"
int main() {
    void*lista;
    crealista(lista,leenumeros,"numeros1.txt");
    cargalista(lista,compruebanumero,leeregnumeros,"numeros2.txt");
    muestralista(lista,imprimenumeros,"repnum.txt");

    crealista(lista,leeregistros,"repartidores.csv");
    cargalista(lista,compruebaregistro,leeordenes,"ordenes.csv");
    muestralista(lista,imprimeregistros,"repregistros.txt");

    return 0;
}
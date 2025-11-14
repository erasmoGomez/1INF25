#include <iostream>
#include "GestorCanales.h"

using namespace std;

int main() {
    GestorCanales gestor_canales;
    gestor_canales.lista_categorias(cout);
    gestor_canales.lista_etiquetas(cout);
    !gestor_canales;
    gestor_canales.lista_canales(cout);
    *gestor_canales;
    gestor_canales.lista_canales(cout);
    //cout << gestor_canales;
    //cout << gestor_canales;
    return 0;
}

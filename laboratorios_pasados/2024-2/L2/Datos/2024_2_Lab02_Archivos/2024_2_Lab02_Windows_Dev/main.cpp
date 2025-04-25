#include <iostream>
#include <iomanip>
#include <cstring>
#include <assert.h>
#include "ConjuntoDePlatos.hpp"
#include "ConjuntoDeRepartidores.hpp"
#include "Pedido.hpp"

using namespace std;

void test01();
void test02();
void test03();

int main(int argc, char** argv) {
    test01();
    test02();
    test03();
    return 0;
}

void test03() {
    ifstream archivo_de_pedidos("pedidos.txt", ios::in);

    if (not archivo_de_pedidos.is_open()) {
        cout << "El archivo \"pedidos.txt\" no ha podido ser aperturado." << endl;
        exit(30);
    }

    Pedido pedido;
    while (archivo_de_pedidos >> pedido) {
        cout << pedido << endl;
    }

    archivo_de_pedidos.close();
}

void test02() {
    ConjuntoDeRepartidores conjuntoDeRepartidores;
    cargar_conjunto_de_repartidores(conjuntoDeRepartidores, "repartidores.csv");

    assert(conjuntoDeRepartidores.cantidad == 35);
    assert(strcmp(conjuntoDeRepartidores.conjunto_de_datos[0].codigo, "JNV387") == 0);
    assert(strcmp(conjuntoDeRepartidores.conjunto_de_datos[0].nombre, "Justino Norabuena Virginia Karina") == 0);
    assert(strcmp(conjuntoDeRepartidores.conjunto_de_datos[0].vehiculo, "Motocicleta") == 0);

    assert(strcmp(conjuntoDeRepartidores.conjunto_de_datos[1].codigo, "PRT150") == 0);
    assert(strcmp(conjuntoDeRepartidores.conjunto_de_datos[1].nombre, "Pairazaman Raffo Tatiana Delicia") == 0);
    assert(strcmp(conjuntoDeRepartidores.conjunto_de_datos[1].vehiculo, "Bicicleta") == 0);

    assert(strcmp(conjuntoDeRepartidores.conjunto_de_datos[34].codigo, "LVW759") == 0);
    assert(strcmp(conjuntoDeRepartidores.conjunto_de_datos[34].nombre, "Luna Vargas Waldemar") == 0);
    assert(strcmp(conjuntoDeRepartidores.conjunto_de_datos[34].vehiculo, "Motocicleta") == 0);

    liberar_conjunto_de_repartidores(conjuntoDeRepartidores);
}

void test01() {
    ConjuntoDePlatos conjuntoDePlatos;
    cargar_conjunto_de_platos(conjuntoDePlatos, "platos.csv");

    assert(conjuntoDePlatos.cantidad == 110);
    assert(strcmp(conjuntoDePlatos.conjunto_de_datos[0].codigo, "AP-500") == 0);
    assert(strcmp(conjuntoDePlatos.conjunto_de_datos[0].nombre, "CHORIZOS COCKTAIL") == 0);
    assert(conjuntoDePlatos.conjunto_de_datos[0].precio == 12.90);
    assert(strcmp(conjuntoDePlatos.conjunto_de_datos[0].tipo, "APERITIVO") == 0);

    assert(strcmp(conjuntoDePlatos.conjunto_de_datos[1].codigo, "AP-410") == 0);
    assert(strcmp(conjuntoDePlatos.conjunto_de_datos[1].nombre, "ANTICUCHO") == 0);
    assert(conjuntoDePlatos.conjunto_de_datos[1].precio == 12.90);
    assert(strcmp(conjuntoDePlatos.conjunto_de_datos[1].tipo, "APERITIVO") == 0);

    assert(strcmp(conjuntoDePlatos.conjunto_de_datos[109].codigo, "PO-283") == 0);
    assert(strcmp(conjuntoDePlatos.conjunto_de_datos[109].nombre, "2 BOLAS DE HELADO") == 0);
    assert(conjuntoDePlatos.conjunto_de_datos[109].precio == 14.90);
    assert(strcmp(conjuntoDePlatos.conjunto_de_datos[109].tipo, "POSTRES") == 0);

    liberar_conjunto_de_platos(conjuntoDePlatos);
}
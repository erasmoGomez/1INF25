#include <iostream>
#include <iomanip>
#include <cstring>
#include <assert.h>
#include "ConjuntoDePlatos.hpp"
#include "ConjuntoDeRepartidores.hpp"
#include "ConjuntoDePedidos.hpp"
#include "Pedido.hpp"

using namespace std;

void test01();
void test02();
void test03();
void test04();
void test05();
void test06();
void test07();

int main(int argc, char** argv) {
    test01();
    test02();
    test03();
    test04();
    test05();
    test06();
    test07();
    return 0;
}

void test07() {
    ConjuntoDePedidos conjuntoDePedidos;
    cargar_conjunto_de_pedidos(conjuntoDePedidos, "pedidos.txt");

    ++conjuntoDePedidos;
    !conjuntoDePedidos;
    *conjuntoDePedidos;
    
    liberar_conjunto_de_pedidos(conjuntoDePedidos);
}

void test06() {
    ConjuntoDePedidos conjuntoDePedidos;
    cargar_conjunto_de_pedidos(conjuntoDePedidos, "pedidos.txt");

    !conjuntoDePedidos;
    
    assert(obtener_cantidad_cliente(conjuntoDePedidos) == 75);      
    assert(strcmp(conjuntoDePedidos.cadenas[0][0], "LAF361") == 0);
    assert(strcmp(conjuntoDePedidos.cadenas[0][1], "CHOCLO") == 0);
    assert(strcmp(conjuntoDePedidos.cadenas[0][2], "MAZAMORRA MORADA") == 0);
    assert(strcmp(conjuntoDePedidos.cadenas[0][3], "ANTICUCHO DE CORAZON") == 0);
    assert(strcmp(conjuntoDePedidos.cadenas[0][4], "SPRITE 1 LITRO") == 0);
    
    assert(strcmp(conjuntoDePedidos.cadenas[1][0], "LVW759") == 0);
    assert(strcmp(conjuntoDePedidos.cadenas[1][1], "PLATANO-HUEVO") == 0);
    assert(strcmp(conjuntoDePedidos.cadenas[1][2], "COCIDA GRANDE") == 0);
    assert(strcmp(conjuntoDePedidos.cadenas[1][3], "1/2 POLLO PARRILLERO ORIGINAL - ENCAMOTADO") == 0);
    
    assert(strcmp(conjuntoDePedidos.cadenas[74][0], "VSM267") == 0);
    assert(strcmp(conjuntoDePedidos.cadenas[74][1], "INTIPALKA SYRAH") == 0);
    assert(strcmp(conjuntoDePedidos.cadenas[74][2], "PARRILLA PARA DOS") == 0);
    assert(strcmp(conjuntoDePedidos.cadenas[74][3], "1/2 POLLO  PARRILLERO ORIGINAL- ARROCERO") == 0);
    assert(strcmp(conjuntoDePedidos.cadenas[74][4], "CERVEZA CUSQUENA") == 0);
    
    liberar_conjunto_de_pedidos(conjuntoDePedidos);
}

void test05() {
    ConjuntoDePedidos conjuntoDePedidos;
    cargar_conjunto_de_pedidos(conjuntoDePedidos, "pedidos.txt");

    conjuntoDePedidos++;
    assert(conjuntoDePedidos.reales[0][0] == 9.90 * 2 + 8.90 * 1 + 25.90 * 3 + 15.50 * 3);
    assert(conjuntoDePedidos.reales[0][1] == 9.90 * 2);
    assert(conjuntoDePedidos.reales[0][2] == 8.90 * 1);
    assert(conjuntoDePedidos.reales[0][3] == 25.90 * 3);
    assert(conjuntoDePedidos.reales[0][4] == 15.50 * 3);

    assert(conjuntoDePedidos.reales[1][0] == 6.90 * 2 + 22.90 * 1 + 50.90 * 3);
    assert(conjuntoDePedidos.reales[1][1] == 6.90 * 2);
    assert(conjuntoDePedidos.reales[1][2] == 22.90 * 1);
    assert(conjuntoDePedidos.reales[1][3] == 50.90 * 3);

    assert(conjuntoDePedidos.reales[74][0] == 71.90 * 1 + 89.90 * 3 + 48.90 * 1 + 12.50 * 2);
    assert(conjuntoDePedidos.reales[74][1] == 71.90 * 1);
    assert(conjuntoDePedidos.reales[74][2] == 89.90 * 3);
    assert(conjuntoDePedidos.reales[74][3] == 48.90 * 1);
    assert(conjuntoDePedidos.reales[74][4] == 12.50 * 2);

    liberar_conjunto_de_pedidos(conjuntoDePedidos);
}

void test04() {
    ConjuntoDePedidos conjuntoDePedidos;
    cargar_conjunto_de_pedidos(conjuntoDePedidos, "pedidos.txt");

    assert(obtener_cantidad_cliente(conjuntoDePedidos) == 75);
    assert(conjuntoDePedidos.enteros[0][0] == 12484697);
    assert(conjuntoDePedidos.enteros[0][1] == 4); //4 diferentes platos (AD-546, PO-751, EN-766 y BE-536)
    assert(conjuntoDePedidos.enteros[0][2] == 2); //2 platos de AD-546
    assert(conjuntoDePedidos.enteros[0][3] == 1); //1 platos de PO-751
    assert(conjuntoDePedidos.enteros[0][4] == 3); //3 platos de EN-766
    assert(conjuntoDePedidos.enteros[0][5] == 3); //3 platos de BE-536
    assert(strcmp(conjuntoDePedidos.cadenas[0][0], "LAF361") == 0);
    assert(strcmp(conjuntoDePedidos.cadenas[0][1], "AD-546") == 0);
    assert(strcmp(conjuntoDePedidos.cadenas[0][2], "PO-751") == 0);
    assert(strcmp(conjuntoDePedidos.cadenas[0][3], "EN-766") == 0);
    assert(strcmp(conjuntoDePedidos.cadenas[0][4], "BE-536") == 0);

    assert(conjuntoDePedidos.enteros[1][0] == 13731806);
    assert(conjuntoDePedidos.enteros[1][1] == 3); //3 diferentes platos (AD-764, EN-156 y BR-665)
    assert(conjuntoDePedidos.enteros[1][2] == 2); //2 platos de AD-764
    assert(conjuntoDePedidos.enteros[1][3] == 1); //1 platos de EN-156
    assert(conjuntoDePedidos.enteros[1][4] == 3); //3 platos de BR-665
    assert(strcmp(conjuntoDePedidos.cadenas[1][0], "LVW759") == 0);
    assert(strcmp(conjuntoDePedidos.cadenas[1][1], "AD-764") == 0);
    assert(strcmp(conjuntoDePedidos.cadenas[1][2], "EN-156") == 0);
    assert(strcmp(conjuntoDePedidos.cadenas[1][3], "BR-665") == 0);

    assert(conjuntoDePedidos.enteros[74][0] == 99891737);
    assert(conjuntoDePedidos.enteros[74][1] == 4); //4 diferentes platos (BE-475, PA-692, BR-745 y BE-431)
    assert(conjuntoDePedidos.enteros[74][2] == 1); //1 platos de BE-475
    assert(conjuntoDePedidos.enteros[74][3] == 3); //3 platos de PA-692
    assert(conjuntoDePedidos.enteros[74][4] == 1); //1 platos de BR-745
    assert(conjuntoDePedidos.enteros[74][5] == 2); //2 platos de BE-431
    assert(strcmp(conjuntoDePedidos.cadenas[74][0], "VSM267") == 0);
    assert(strcmp(conjuntoDePedidos.cadenas[74][1], "BE-475") == 0);
    assert(strcmp(conjuntoDePedidos.cadenas[74][2], "PA-692") == 0);
    assert(strcmp(conjuntoDePedidos.cadenas[74][3], "BR-745") == 0);
    assert(strcmp(conjuntoDePedidos.cadenas[74][4], "BE-431") == 0);

    liberar_conjunto_de_pedidos(conjuntoDePedidos);
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
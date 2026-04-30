#include "src/BibliotecaGenerica.hpp"
#include "src/FuncionesEnteros.hpp"
#include "src/FuncionesRegistros.hpp"

using namespace std;

/*
 *
 */
int main(int argc, char** argv) {
    void *pedidos1, *pedidos2, *pedidosfinal;
    crealista(pedidos1, leenum, "Data/RegistroNum1.txt");
    // crealista(nombres, leercadenas, "RegistroNum5.txt");
    imprimelista(pedidos1, imprimenum, "Reports/Repnum1.txt");
    crealista(pedidos2, leenum, "Data/RegistroNum2.txt");
    imprimelista(pedidos2, imprimenum, "Reports/Repnum2.txt");
    combinalista(pedidos1, pedidos2, pedidosfinal, cmpnum);
    imprimelista(pedidosfinal, imprimenum, "Reports/Repnumfinal.txt");
//
    crealista(pedidos1, leeregistro, "Data/Pedidos31.csv");
    imprimelista(pedidos1, imprimeregistro, "Reports/Repreg1.txt");
    crealista(pedidos2, leeregistro, "Data/Pedidos32.csv");
    imprimelista(pedidos2, imprimeregistro, "Reports/Repreg2.txt");
    combinalista(pedidos1, pedidos2, pedidosfinal, cmpregistro);
    imprimelista(pedidosfinal, imprimeregistro, "Reports/RepregFinal.txt");
    return 0;
}
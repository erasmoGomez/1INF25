/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on October 1, 2024, 4:54 PM
 */

#include "BibliotecaGenerica.hpp"
#include "FuncionesEnteros.hpp"
#include "FuncionesRegistros.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *pedidos1, *pedidos2, *pedidosfinal;
    crealista(pedidos1, leenum, "RegistroNum1.txt");
    imprimelista(pedidos1, imprimenum, "Repnum1.txt");
    crealista(pedidos2, leenum, "RegistroNum2.txt");
    imprimelista(pedidos2, imprimenum, "Repnum2.txt");
    combinalista(pedidos1, pedidos2, pedidosfinal, cmpnum);
    imprimelista(pedidosfinal, imprimenum, "Repnumfinal.txt");
//
    crealista(pedidos1, leeregistro, "Pedidos31.csv");
//    imprimelista(pedidos1, imprimeregistro, "Repreg1.txt");
//    crealista(pedidos2, leeregistro, "Pedidos32.csv");
//    imprimelista(pedidos2, imprimeregistro, "Repreg2.txt");
//    combinalista(pedidos1, pedidos2, pedidosfinal, cmpregistro);
//    imprimelista(pedidosfinal, imprimeregistro, "RepregFinal.txt");
    return 0;
}


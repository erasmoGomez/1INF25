/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on April 26, 2023, 7:18 AM
 */


#include "sobrecargas.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    struct Estructura_ClienteRegistrado clientes[5];
    struct Estructura_ClienteRegistrado cliente_nuevo;
    ifstream arch_cliente;
    AperturaDeUnArchivoDeTextosParaLeer(arch_cliente, "Clientes.txt");
    arch_cliente>>clientes[0];
    cout<<clientes[0].nombre<<endl;
    cout<<clientes[0].categoria<<endl;
    clientes[1].dni = 0; //Fin de clientes
    arch_cliente>>clientes[1]>>clientes[2];
    cout<<clientes[1].nombre<<endl;
    cout<<clientes[2].nombre<<endl;
    clientes[3].dni = 0;
    
    arch_cliente>>cliente_nuevo;
    //Anexar cliente
    clientes+=cliente_nuevo;
    cout<<clientes[3].nombre<<endl;
    cout<<"Fin "<<clientes[4].dni<<endl;
    return 0; 
}


//
// Created by Erasmo on 25/11/25.
//

#include "MinisterioTransporte.hpp"

MinisterioDeTransporte::MinisterioDeTransporte() {

}

void MinisterioDeTransporte::cargaDeInfracciones(const char *nom) {
    ifstream arch(nom);
    Infraccion infraccion;
    while (arch >> infraccion)
        tablaInfracciones.push_back(infraccion); // Sobrecarga = y CC
    tablaInfracciones.sort(); // Sobrecarga;
}

//[](const Infraccion &a, const Infraccion &b) {
//return a.getCodigo() < b.getCodigo();
//}


void MinisterioDeTransporte::cargaEmpresas(const char *nom) {
    ifstream arch(nom);
    Empresa e;
    while (arch >> e)
        listaEmpresas.push_back(e);
    listaEmpresas.sort();
}

void MinisterioDeTransporte::cargaVehiculos(const char *nom) {
    ifstream input(nom);
    string linea;
    int dni;
    //80310768,M982-853,Honda,Civic
    while (true) {
        input >> dni; //DNI del representante
        if (input.eof())break;
        input.get();
        Vehiculo v;
        input >> v;
        for (auto &emp: listaEmpresas)
            if (emp.getDni() == dni) {
                emp.insertar_vehiculo(v);
            }
    }
}

void MinisterioDeTransporte::cargaInfraccionesCometidas(const char *nom) {
    ifstream input(nom);
    Multa m;
    int cont=0;
    //1/12/2020,G760-721,G2022,N
    //23/07/2023,P474-593,G2060,P,22/08/2023
    while (input >> m) {

        // buscar monto en tablaInfracciones
        for (auto &inf: tablaInfracciones)
            if (inf.getCodigo() == m.getCodigo())
                m.setMulta(inf.getMulta());

        // buscar empresa por placa
        for (auto &emp: listaEmpresas) {
            emp.buscar_empresa_placa_asigna(m);
        }
    }
    // ordenar multas de cada empresa
    for (auto &emp: listaEmpresas) {
        emp.ordenar_multas();
    }
}

void MinisterioDeTransporte::eliminaInfraccionesPagadas() {
    for (auto &emp : listaEmpresas) {
        emp.eliminar_infracciones_pagadas();
    }
}

void MinisterioDeTransporte::reporteDeEmpresasConInfracciones(const char *nom) {
    ofstream output(nom);

    for (auto &emp: listaEmpresas) {
        output << "=====================================================\n";
        output << emp << endl;

        output << "VEHICULOS DE LA EMPRESA:\n";
        output << "PLACA MARCA MODELO\n";
        emp.imprimir_vehiculos(output);

        output << "-----------------------------------------------------\n";
        output << "MULTAS IMPUESTAS\n";
        emp.imprimir_multas(output);
        output << "=====================================================\n\n";
    }
}
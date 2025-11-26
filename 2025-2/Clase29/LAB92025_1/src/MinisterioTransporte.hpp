//
// Created by Erasmo on 25/11/25.
//

#ifndef LAB92025_1_MINISTERIOTRANSPORTE_HPP
#define LAB92025_1_MINISTERIOTRANSPORTE_HPP

#include "Infraccion.hpp"
#include "Empresa.hpp"

class MinisterioDeTransporte {
private:
    list<Infraccion> tablaInfracciones;
    list<Empresa> listaEmpresas;

public:
    MinisterioDeTransporte();

    void cargaDeInfracciones(const char *nom);

    void cargaEmpresas(const char *nom);

    void cargaVehiculos(const char *nom);

    void cargaInfraccionesCometidas(const char *nom);

    void eliminaInfraccionesPagadas();

    void reporteDeEmpresasConInfracciones(const char *nom);

};

#endif //LAB92025_1_MINISTERIOTRANSPORTE_HPP

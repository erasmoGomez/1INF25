//
// Created by erasmo on 5/26/26.
//

#include "Guerrero.hpp"

int Guerrero::get_n_muertes() const {
    return n_muertes;
}

void Guerrero::set_n_muertes(int n_muertes) {
    this->n_muertes = n_muertes;
}

void Guerrero::imprimir(ofstream & output) {
    // LLAMAR A LA CLASE BASE
    Personaje::imprimir(output);
    // HACER LO ESPECIFICO DE LA CLASE DERIVADA
    output<<"N_Muertes ->"<<n_muertes<<endl;
}

void Guerrero::atacar() {
    cout<<"El guerrero esta atacando!"<<endl;
}

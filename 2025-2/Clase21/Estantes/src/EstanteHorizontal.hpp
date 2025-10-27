//
// Created by Erasmo on 26/10/25.
//

#ifndef ESTANTES_ESTANTEHORIZONTAL_HPP
#define ESTANTES_ESTANTEHORIZONTAL_HPP

#include "Novela.hpp"
#include "Estante.hpp"

class EstanteHorizontal : public Estante {
private:
    Novela novelas[10];
    int cantidad_novelas;
public:
    EstanteHorizontal();

    virtual ~EstanteHorizontal();

    EstanteHorizontal(const EstanteHorizontal &);

    void leer(ifstream &input);

    int get_espacios_restantes();

    bool operator+=(const Novela &n);

    void colocar_libro(int alto_utilizado, const Novela &e);

    void mostrar(ofstream &output) const;

    void setEstadoColocado(int , bool);

    void pinta_estante(ofstream& output) const;
};

void operator<<(ofstream &output, const EstanteHorizontal &e);

#endif //ESTANTES_ESTANTEHORIZONTAL_HPP

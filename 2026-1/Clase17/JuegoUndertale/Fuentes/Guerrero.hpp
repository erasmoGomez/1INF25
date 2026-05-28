//
// Created by erasmo on 5/26/26.
//

#ifndef JUEGOUNDERTALE_GUERRERO_HPP
#define JUEGOUNDERTALE_GUERRERO_HPP
#include "Arma.hpp"
#include "Personaje.hpp"

class Guerrero : public Personaje {
public:
    int get_n_muertes() const;
    void set_n_muertes(int n_muertes);
    void imprimir(ofstream&);
    void atacar();
private:
    int n_muertes;
    Arma* armas;
};


#endif //JUEGOUNDERTALE_GUERRERO_HPP
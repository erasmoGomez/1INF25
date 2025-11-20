//
// Created by Erasmo on 19/11/25.
//

#ifndef RULETARUSA_PAGADOR_HPP
#define RULETARUSA_PAGADOR_HPP
#include "Jugador.hpp"

class Pagador : public Jugador{
private:
    double saldo;
public:
    double getSaldo() const;

    void setSaldo(double saldo);

    bool eligeDerecha() const;

public:
    void leer(ifstream& input);
    void imprimir(ofstream& output);
};


#endif //RULETARUSA_PAGADOR_HPP

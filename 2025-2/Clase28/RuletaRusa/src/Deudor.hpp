//
// Created by Erasmo on 19/11/25.
//

#ifndef RULETARUSA_DEUDOR_HPP
#define RULETARUSA_DEUDOR_HPP
#include "Jugador.hpp"

class Deudor : public Jugador{
private:
    double deuda;
public:
    double getDeuda() const;

    void setDeuda(double deuda);

public:
    void leer(ifstream& input);
    void imprimir(ofstream& output);
};


#endif //RULETARUSA_DEUDOR_HPP

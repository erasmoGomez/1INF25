//
// Created by Erasmo on 3/06/24.
//

#ifndef JUEGO_ARMA_HPP
#define JUEGO_ARMA_HPP


#include "Item.hpp"
class Arma: public Item {
public:
    Arma();
    Arma(const Arma& orig);
    virtual ~Arma();
    void SetModificador_att(int modificador_att);
    int GetModificador_att() const;
    void leer(ifstream &);
    void mostrar(ofstream &);
    void mostrar();
    int get_modificador();
private:
    int modificador_att;
};


#endif //JUEGO_ARMA_HPP

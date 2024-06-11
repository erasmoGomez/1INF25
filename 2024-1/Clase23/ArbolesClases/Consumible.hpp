//
// Created by Erasmo on 3/06/24.
//

#ifndef JUEGO_CONSUMIBLE_HPP
#define JUEGO_CONSUMIBLE_HPP


#include "Utils.hpp"
#include "Item.hpp"
using namespace std;
class Consumible: public Item {
public:
    Consumible();
    Consumible(const Consumible& orig);
    virtual ~Consumible();
    void SetModificador_hp(int modificador_hp);
    int GetModificador_hp() const;
    void leer(ifstream &);
    void mostrar(ofstream&);
    void mostrar();
    int get_modificador();
private:
    int modificador_hp;
};


#endif //JUEGO_CONSUMIBLE_HPP

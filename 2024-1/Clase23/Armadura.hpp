//
// Created by Erasmo on 3/06/24.
//

#ifndef JUEGO_ARMADURA_HPP
#define JUEGO_ARMADURA_HPP

#include "Item.hpp"
class Armadura:public Item {
public:
    Armadura();
    Armadura(const Armadura& orig);
    virtual ~Armadura();
    void SetModificador_def(int modificador_def);
    int GetModificador_def() const;
    void leer(ifstream &);
    void mostrar(ofstream &);
    void mostrar();
    int get_modificador();
private:
    int modificador_def;
};


#endif //JUEGO_ARMADURA_HPP

//
// Created by Erasmo on 3/06/24.
//

#ifndef JUEGO_MOCHILA_HPP
#define JUEGO_MOCHILA_HPP


#include "Consumible.hpp"
#include "Arma.hpp"
#include "Armadura.hpp"
#include "Utils.hpp"
using namespace std;
class Mochila {
public:

    Mochila();
    Mochila(const Mochila& orig);
    virtual ~Mochila();
    void SetN_armaduras(int n_armaduras);
    int GetN_armaduras() const;
    void SetN_armas(int n_armas);
    int GetN_armas() const;
    void SetN_consumibles(int n_consumibles);
    int GetN_consumibles() const;
    void agregar_item(ifstream &, char*);
    void equipar(const char* );
    int buscar_item(const char*);
    int buscar_consumible(const char*);
    int buscar_armadura(const char*);
    int buscar_arma(const char*);
    void mostrar(ofstream &);
    void mostrar();
    void cargar_items(ifstream &, char*);

    void asignar_memoria(char*, int);
private:
    Consumible bolsillo_consumibles[30];
    int n_consumibles;
    Arma bolsillo_armas[30];
    int n_armas;
    Armadura bolsillo_armaduras[30];
    int n_armaduras;

    Item *items[60]; // 60 ptr Item // 8bytes
    int n_items;
};



#endif //JUEGO_MOCHILA_HPP

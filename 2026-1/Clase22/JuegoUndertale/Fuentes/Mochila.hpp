//
// Created by erasmo on 5/27/26.
//

#ifndef JUEGOUNDERTALE_MOCHILA_HPP
#define JUEGOUNDERTALE_MOCHILA_HPP

#include "Utils2.hpp"

#include "Armadura.hpp"
#include "Arma.hpp"
#include "Consumible.hpp"

class Mochila {
public:
    Mochila();

    int get_cantidad_armaduras() const;

    void set_cantidad_armaduras(int cantidad_armaduras);

    int get_cantidad_armas() const;

    void set_cantidad_armas(int cantidad_armas);

    int get_cantidad_consumibles() const;

    void set_cantidad_consumibles(int cantidad_consumibles);

    void leer_item(char *tipo, ifstream & input);

    void leer_item_poli(char *tipo, ifstream & input);

    int equipar_arma(const char* nombre_item);
    int equipar_armadura(const char* nombre_item);
    int equipar_consumible(const char* nombre_item);

    int equipar(const char* nombre_item);

private:
    Armadura bolsillo_armaduras[30];
    Arma bolsillo_armas[30];
    Consumible bolsillo_consumibles[30];
    int cantidad_armaduras;
    int cantidad_armas;
    int cantidad_consumibles;

    Item* items[90];
    int cantidad_items;
};


#endif //JUEGOUNDERTALE_MOCHILA_HPP
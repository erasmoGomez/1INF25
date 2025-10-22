//
// Created by Erasmo on 9/10/25.
//

#ifndef JUEGO_MOCHILA_HPP
#define JUEGO_MOCHILA_HPP

#include "Item.hpp"
#include "Armadura.hpp"
#include "Arma.hpp"
#include "Consumible.hpp"

class Mochila {
private:
    Armadura *bolsillo_armaduras;
    Arma *bolsillo_armas;
    Consumible *bolsillo_consumibles;
    int cantidad_armaduras;
    int cantidad_armas;
    int cantidad_consumibles;
public:
    int getCantidadArmaduras() const;

    void setCantidadArmaduras(int cantidadArmaduras);

    int getCantidadArmas() const;

    void setCantidadArmas(int cantidadArmas);

    int getCantidadConsumibles() const;

    void setCantidadConsumibles(int cantidadConsumibles);

    void leer_item(ifstream& input);

    Mochila();

};


#endif //JUEGO_MOCHILA_HPP

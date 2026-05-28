//
// Created by erasmo on 5/27/26.
//

#include "Mochila.hpp"

int Mochila::get_cantidad_armaduras() const {
    return cantidad_armaduras;
}

void Mochila::set_cantidad_armaduras(int cantidad_armaduras) {
    this->cantidad_armaduras = cantidad_armaduras;
}

int Mochila::get_cantidad_armas() const {
    return cantidad_armas;
}

void Mochila::set_cantidad_armas(int cantidad_armas) {
    this->cantidad_armas = cantidad_armas;
}

int Mochila::get_cantidad_consumibles() const {
    return cantidad_consumibles;
}

void Mochila::set_cantidad_consumibles(int cantidad_consumibles) {
    this->cantidad_consumibles = cantidad_consumibles;
}

void Mochila::leer_item(char *tipo, ifstream &input) {
    /*
     * tipo : Armadura, Arma, Consumible
     */
    if (strcmp(tipo,"Weapon") == 0) {
        //Sword,A sharp and sturdy sword.,147
        Arma arma;
        arma.leer(input);
        bolsillo_armas[cantidad_armas] = arma;
        cantidad_armas++;
    }
    if (strcmp(tipo,"Armor") == 0) {
        //Sword,A sharp and sturdy sword.,147
        Armadura armadura;
        armadura.leer(input);
        bolsillo_armaduras[cantidad_armaduras] = armadura;
        cantidad_armaduras++;
    }
    if (strcmp(tipo,"Consumible") == 0) {
        //Sword,A sharp and sturdy sword.,147
        Consumible consumible;
        consumible.leer(input);
        bolsillo_consumibles[cantidad_consumibles] = consumible;
        cantidad_consumibles++;
    }
}

Mochila::Mochila() {
    cantidad_armas = 0;
    cantidad_consumibles = 0;
    cantidad_armaduras = 0;
}

//
// Created by Erasmo on 9/10/25.
//

#include "Mochila.hpp"

Mochila::Mochila() {
    cantidad_armaduras = 0;
    cantidad_armas = 0;
    cantidad_consumibles = 0;
    bolsillo_armaduras = nullptr; //implica que la reserva de memoria se hara en la lectura ; Memoria Exacta o Memoria Incrementos.
    bolsillo_armas = nullptr;
    bolsillo_consumibles = new Item[100]{}; // Ya se reserva memoria del arreglo de items;
}

int Mochila::getCantidadArmaduras() const {
    return cantidad_armaduras;
}

void Mochila::setCantidadArmaduras(int cantidadArmaduras) {
    cantidad_armaduras = cantidadArmaduras;
}

int Mochila::getCantidadArmas() const {
    return cantidad_armas;
}

void Mochila::setCantidadArmas(int cantidadArmas) {
    cantidad_armas = cantidadArmas;
}

int Mochila::getCantidadConsumibles() const {
    return cantidad_consumibles;
}

void Mochila::setCantidadConsumibles(int cantidadConsumibles) {
    cantidad_consumibles = cantidadConsumibles;
}

void Mochila::leer_item(ifstream &input) {
    //1,Sword,A sharp and sturdy sword.,147,3
    //2,Potion,A healing potion that restores health.,130,4
    //3,Leather Armor,Lightweight leather armor for protection.,173,4

    //3 opciones: bolsillo_armas, bolsillo_armaduras, bolsillo_consumibles
    char buffer_tipo[20];
    input.getline(buffer_tipo, 20, ',');

    if(!strcmp(buffer_tipo, "Weapon")){
        Arma arma;
        arma.leer(input);
        bolsillo_armas[cantidad_armas] = arma;
        cantidad_armas++;
    }

    if(!strcmp(buffer_tipo, "Consumable")){
        Consumible consumible;
        consumible.leer(input);
        bolsillo_consumibles[cantidad_consumibles] = consumible;
        cantidad_consumibles++;
    }

    if(!strcmp(buffer_tipo, "Armor")){
        Armadura armadura;
        armadura.leer(input);
        bolsillo_armaduras[cantidad_armaduras] = armadura;
        cantidad_armaduras++;
    }


}

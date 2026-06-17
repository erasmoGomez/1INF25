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
    if (strcmp(tipo, "Weapon") == 0) {
        //Sword,A sharp and sturdy sword.,147
        Arma arma;
        arma.leer(input);
        bolsillo_armas[cantidad_armas] = arma;
        cantidad_armas++;
    }
    if (strcmp(tipo, "Armor") == 0) {
        //Sword,A sharp and sturdy sword.,147
        Armadura armadura;
        armadura.leer(input);
        bolsillo_armaduras[cantidad_armaduras] = armadura;
        cantidad_armaduras++;
    }
    if (strcmp(tipo, "Consumable") == 0) {
        //Sword,A sharp and sturdy sword.,147
        Consumible consumible;
        consumible.leer(input);
        bolsillo_consumibles[cantidad_consumibles] = consumible;
        cantidad_consumibles++;
    }
}

void Mochila::leer_item_poli(char *tipo, ifstream &input) {
    if (strcmp(tipo, "Weapon") == 0) items[cantidad_items] = new Arma;
    if (strcmp(tipo, "Consumable") == 0) items[cantidad_items] = new Consumible;
    if (strcmp(tipo, "Armor") == 0) items[cantidad_items] = new Armadura;
    items[cantidad_items]->leer(input);
    cantidad_items++;
}

int Mochila::equipar_arma(const char *nombre_item) {
    for (int i = 0; i < cantidad_armas; i++) {
        char nombre[30];
        bolsillo_armas[i].get_nombre(nombre);
        if (strcmp(nombre, nombre_item) == 0) {
            //He encontrado el arma a equipar
            bolsillo_armas[i].set_equipado(true);
            return bolsillo_armas[i].get_modificador();
        }
    }
    return 0;
}

int Mochila::equipar_armadura(const char *nombre_item) {
    for (int i = 0; i < cantidad_armaduras; i++) {
        char nombre[30];
        bolsillo_armaduras[i].get_nombre(nombre);
        if (strcmp(nombre, nombre_item) == 0) {
            //He encontrado el arma a equipar
            bolsillo_armaduras[i].set_equipado(true);
            return bolsillo_armaduras[i].get_modificador();
        }
    }
    return 0;
}

int Mochila::equipar_consumible(const char *nombre_item) {
    for (int i = 0; i < cantidad_consumibles; i++) {
        char nombre[30];
        bolsillo_consumibles[i].get_nombre(nombre);
        if (strcmp(nombre, nombre_item) == 0) {
            //He encontrado el arma a equipar
            bolsillo_consumibles[i].set_equipado(true);
            return bolsillo_consumibles[i].get_modificador();
        }
    }
    return 0;
}

int Mochila::equipar(const char *nombre_item) {
    for (int i = 0; i < cantidad_items; i++) {
        char nombre[30];
        items[i]->get_nombre(nombre);
        if (strcmp(nombre, nombre_item) == 0) {
            items[i]->set_equipado(true);
            return items[i]->get_modificador();
        }
    }
    return 0;
}

Mochila::Mochila() {
    cantidad_armas = 0;
    cantidad_consumibles = 0;
    cantidad_armaduras = 0;
    cantidad_items = 0;
    for (int i = 0; i < 90; i++) {
        items[i] = nullptr;
    }
}

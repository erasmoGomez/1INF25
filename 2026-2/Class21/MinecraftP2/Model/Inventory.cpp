//
// Created by erasmo on 10/21/26.
//

#include "Inventory.hpp"

#include "Food.hpp"

Inventory::Inventory() {
    n_items = 0;
}

void Inventory::memory_allocation(char *type, int n_items) {
    if (strcmp(type, "Weapon")==0) {
        items[n_items] = new Weapon();
    }
    if (strcmp(type, "Tool")==0) {
        items[n_items] = new Tool();
    }
}

void Inventory::read(char *type, ifstream &input) {
    // reserva de memoria
    memory_allocation(type,n_items);
    items[n_items]->read(input);
    n_items++;
}

void Inventory::interact() {
    for (int i = 0; i<n_items; i++)
        items[i]->use();
}

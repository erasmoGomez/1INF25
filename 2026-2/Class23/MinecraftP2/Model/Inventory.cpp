//
// Created by erasmo on 10/21/26.
//

#include "Inventory.hpp"

#include "Food.hpp"

Inventory::Inventory() {
    n_items = 0;
}

void Inventory::memory_allocation(char *type, int n_items) {
    if (strcmp(type, "Weapon") == 0) {
        items[n_items] = new Weapon();
    }
    if (strcmp(type, "Tool") == 0) {
        items[n_items] = new Tool();
    }
    if (strcmp(type, "Food") == 0) {
        items[n_items] = new Food();
    }
}

void Inventory::read(char *type, ifstream &input) {
    // reserva de memoria
    memory_allocation(type, n_items);
    items[n_items]->read(input);
    n_items++;
}

int Inventory::interact(string name) {
    int new_hp = 0;
    for (int i = 0; i < n_items; i++) {
        if (items[i]->get_name() == name) {
            // Polymorphic call
            new_hp = items[i]->use();

            // Remove the item if depleted
            if (items[i]->is_empty()) {
                delete_item(name);
            }

            return new_hp;
        }
    }
    return new_hp;
}

void Inventory::delete_item(string name) {
    for (int i = 0; i < n_items; i++) {
        if (items[i]->get_name() == name) {
            delete items[i];

            for (int j = i; j < n_items - 1; j++) {
                items[j] = items[j + 1];
            }

            n_items--;
            items[n_items] = nullptr;

            return;
        }
    }
}

void Inventory::print( ostream &out) const {
    out << left
            << setw(30) << "Name"
            << setw(10) << "Durability"
            << endl;

    out << setfill('-') << setw(53) << "" << endl;
    out << setfill(' ');

    for (int i = 0; i < n_items; i++) {
        if (items[i] != nullptr) {
            items[i]->print(out);
        }
    }
}

int Inventory::compare_items(const void* a, const void* b) {
    Item* item1 = *(Item **) a;
    Item* item2 = *(Item**)b;

    return item1->get_name().compare(item2->get_name());
}

void Inventory::sort(){
    qsort(items, n_items, sizeof(Item*), compare_items);
}

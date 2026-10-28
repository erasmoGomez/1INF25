//
// Created by erasmo on 10/21/26.
//

#ifndef MINECRAFTP2_INVENTORY_HPP
#define MINECRAFTP2_INVENTORY_HPP

#include "Weapon.hpp"
#include "Tool.hpp"

class Inventory {
private:
    // Por separado - Herencia
    //Weapon weapons[20];
    //Tool tools[20];
    // Junto - Polimorfismo
    Item *items[40];
    int n_items;

public:
    Inventory();

    void memory_allocation(char * type, int n_items);

    void read(char *type, ifstream &input);

    void interact();
};


#endif //MINECRAFTP2_INVENTORY_HPP

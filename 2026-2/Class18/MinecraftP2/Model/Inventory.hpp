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
    Weapon weapons[20];
    Tool tools[20];
    // Junto - Polimorfismo
    Item* items[40];
};


#endif //MINECRAFTP2_INVENTORY_HPP
//
// Created by erasmo on 10/21/26.
//

#ifndef MINECRAFTP2_WEAPON_HPP
#define MINECRAFTP2_WEAPON_HPP

#include "Item.hpp"

class Weapon : public Item {
private:
    int damage;

public:
    Weapon();

    int get_damage() const;

    void set_damage(const int damage);

    void attack();

    void read(ifstream&);

    void use();
};


#endif //MINECRAFTP2_WEAPON_HPP

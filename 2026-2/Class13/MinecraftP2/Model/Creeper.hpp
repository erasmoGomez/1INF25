//
// Created by erasmo on 9/29/26.
//

#ifndef MINECRAFTP2_CREEPER_HPP
#define MINECRAFTP2_CREEPER_HPP

#include "../Utilities/Utils.hpp"

class Creeper {
public:
    int get_health() const;

    void set_health(const int health);

    int get_damage() const;

    void set_damage(const int damage);

    bool is_charged() const;

    void set_charged(const bool charged);

    //Atributos
private:
    int health;
    int damage;
    bool charged;

public:
    Creeper();

    //Metodos
    void explode();
};


#endif //MINECRAFTP2_CREEPER_HPP

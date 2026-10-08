//
// Created by erasmo on 10/7/26.
//

#ifndef MINECRAFTP2_MOB_HPP
#define MINECRAFTP2_MOB_HPP
#include "../Utilities/Utils.hpp"

class Mob {
private:
    int id;
    char *type;
    int health;
    int damage;
    int x;
    int y;
    int z;

    int elementos[20];

public:
    int get_elementos_by_index(const int index);

    int get_id() const;

    void set_id(const int id);

    void get_type(char* type) const;

    void set_type(const char * type);

    int get_health() const;

    void set_health(const int health);

    int get_damage() const;

    void set_damage(const int damage);

    int get_x() const;

    void set_x(const int x);

    int get_y() const;

    void set_y(const int y);

    int get_z() const;

    void set_z(const int z);

    void copy(const Mob & mob);

    void print(ofstream & output) const;

    Mob();

    Mob(const int id, char * const type, const int x, const int y, const int z);

    ~Mob();

    void read(ifstream &input);
};

void operator>>(ifstream &input, class Mob &m);

void operator<<(ofstream &output, const class Mob &m);


#endif //MINECRAFTP2_MOB_HPP
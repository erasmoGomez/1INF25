#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "../Utilities/Utils.hpp"

class Player{
public:
    int get_id() const;

    void set_id(const int id);

    void get_name(char* name) const;

    void set_name(const char * name);

    int get_level() const;

    void set_level(const int level);

    int get_health() const;

    void set_health(const int health);

    int get_x() const;

    void set_x(const int x);

    int get_y() const;

    void set_y(const int y);

    int get_z() const;

    void set_z(const int z);

private:
    int id;
    char *name;
    int level;
    int health;
    int x;
    int y;
    int z;
public:
    Player();
    Player(const char *name, int health, int x, int y);
    //Player(const Player &other);
    ~Player();

    void move(int dx, int dy, int dz);
    void receive_damage(int damage);
    void attack();
    void read(ifstream &in);
    void print(ostream& out) const;

    void operator=(const Player &other);
};

#endif

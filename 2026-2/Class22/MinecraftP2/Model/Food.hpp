//
// Created by erasmo on 10/21/26.
//

#ifndef MINECRAFTP2_FOOD_HPP
#define MINECRAFTP2_FOOD_HPP
#include "Item.hpp"


class Food : public Item {
public:
    int get_recover() const;

    void set_recover(const int recover);

private:
    int recover;
public:
    Food();

    Food(const string &);

    int use();

    bool is_empty() const;

    void read(ifstream&);
};


#endif //MINECRAFTP2_FOOD_HPP

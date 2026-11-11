//
// Created by erasmo on 10/21/26.
//

#ifndef MINECRAFTP2_ITEM_HPP
#define MINECRAFTP2_ITEM_HPP
#include "../Utilities/Utils.hpp"

class Item {
public:
    int get_id() const;

    void set_id(const int id);

    string get_name() const;

    void set_name(const string &name);

    string get_color() const;

    void set_color(const string &color);

    double get_durability() const;

    void set_durability(const double durability);

private:
    int id;
    string name;
    double durability;
    string description;
    int quantity;

public:
    int get_quantity() const;

    void set_quantity(const int quantity);

    Item();
    Item(const char*);
    Item(int, string, double);
    // Item(const Item&); En esta clase no es necesario ya que estamos usando string
    // Seccion Polimorfica
    virtual void read(ifstream& input);
    virtual void print(ostream&) const;

    virtual int use() = 0;

    virtual bool is_empty() const;

    virtual ~Item();
};


#endif //MINECRAFTP2_ITEM_HPP
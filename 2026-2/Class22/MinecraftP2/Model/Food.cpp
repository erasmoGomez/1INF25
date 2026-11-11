//
// Created by erasmo on 10/21/26.
//

#include "Food.hpp"

int Food::get_recover() const {
    return recover;
}

void Food::set_recover(const int recover) {
    this->recover = recover;
}

Food::Food() {
    recover = 2;
}

Food::Food(const string &name) {
    recover = 5;
    set_name(name);
}

int Food::use() {
    if (get_quantity() > 0) {
        set_quantity(get_quantity()-1);
        cout << "COMIENDO!" << " " << get_name() << endl;
        return recover;
    }
    return 0;
}

bool Food::is_empty() const {
    return get_quantity() == 0;
}

void Food::read(ifstream &input) {
    //Rotten Flesh,Can be eaten by the player with high risk of inflicting Hunger,71,5
    Item::read(input);
    //5
    input >> recover;
    input.get();
    input.get();
}

//
// Created by erasmo on 9/30/26.
//

#include "Item.hpp"

Item::Item() {
    name = nullptr;
    description = nullptr;
}

Item::~Item() {
    cout<<"Destructor Item"<<endl;
    delete name;
    delete description;
}

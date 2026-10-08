//
// Created by erasmo on 10/7/26.
//

#include "Block.hpp"

#include <iostream>

Block::Block() {
    cout<<"Constructing Block"<<endl;
    sprite = ' ';
    transitable = true;
}

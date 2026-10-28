//
// Created by erasmo on 10/21/26.
//

#include "Tool.hpp"

Tool::Tool() {
    cout << "Constructor Clase Tool" << endl;
}

void Tool::mine() {
    cout << "Mining..." << endl;
}

void Tool::read(ifstream &input) {
    Item::read(input);
    input >> mining_speed;
    input.get();
    input.get();
}

void Tool::use() {
    mine();
}

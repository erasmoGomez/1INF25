//
// Created by erasmo on 10/7/26.
//

#include "Block.hpp"

#include <iostream>

char Block::get_sprite() const {
    return sprite;
}

void Block::set_sprite(const char sprite) {
    this->sprite = sprite;
}

bool Block::is_transitable() const {
    return transitable;
}

void Block::set_transitable(const bool transitable) {
    this->transitable = transitable;
}

Block::Block() {
    //cout<<"Constructing Block"<<endl;
    sprite = ' ';
    transitable = true;
}

Block::Block(bool transitable) {
    this->transitable = transitable;
    this->sprite = this->transitable ? ' ': 'X';
}

Block::Block(const Block &orig) {
    this->sprite = orig.sprite;
    this->transitable = orig.transitable;
}

Block::~Block() {
}

void Block::display(ostream& out) const{
    out << setw(1)<<'|' <<sprite<<setw(1)<<'|';
}

void operator << (ostream& out, const class Block& b){
    b.display(out);
}
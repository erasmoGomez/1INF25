//
// Created by Erasmo on 30/09/25.
//

#include "Casilla.hpp"

Casilla::Casilla() {
    transitable = true;
    contieneheroe = false;
    sprite = ' ';
}

Casilla::Casilla(bool transitable) {
    this->transitable = transitable;
    this->sprite = this->transitable ? ' ': 'X';
}

Casilla::Casilla(const Casilla &orig) {
    this->sprite = orig.sprite;
    this->transitable = orig.transitable;
    this->contieneheroe = orig.contieneheroe;

    // *this = orig;
}

Casilla::~Casilla() {

}

char Casilla::getSprite() const {
    return sprite;
}

void Casilla::setSprite(char sprite) {
    Casilla::sprite = sprite;
}

bool Casilla::isTransitable() const {
    return transitable;
}

void Casilla::setTransitable(bool transitable) {
    Casilla::transitable = transitable;
}

bool Casilla::isContieneheroe() const {
    return contieneheroe;
}

void Casilla::setContieneheroe(bool contieneheroe) {
    Casilla::contieneheroe = contieneheroe;
}

void Casilla::mostrar_info(ostream& out) const{
    out << setw(1)<<'|' <<sprite<<setw(1)<<'|';
}

void operator << (ostream& out, const class Casilla& c){
    c.mostrar_info(out);
}

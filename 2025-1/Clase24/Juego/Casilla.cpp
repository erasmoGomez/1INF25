/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Casilla.cpp
 * Author: hecto
 * 
 * Created on May 7, 2025, 4:55 PM
 */

#include "Casilla.hpp"

Casilla::Casilla() {
    transitable = true;
    contieneHeroe = false;
    sprite = ' ';
}

Casilla::Casilla(bool transitable) {
    this->transitable = transitable;
    this->sprite = this->transitable ? ' ':'X';
}


Casilla::Casilla(const Casilla& orig) {
}

Casilla::~Casilla() {
}

void Casilla::setSprite(char sprite) {
    this->sprite = sprite;
}

char Casilla::getSprite() const {
    return sprite;
}

void Casilla::setContieneHeroe(bool contieneHeroe) {
    this->contieneHeroe = contieneHeroe;
}

bool Casilla::isContieneHeroe() const {
    return contieneHeroe;
}

void Casilla::setTransitable(bool transitable) {
    this->transitable = transitable;
}

bool Casilla::isTransitable() const {
    return transitable;
}

void Casilla::mostrar_info(ostream& out) const{
    out<< setw(1)<< '|' <<sprite<<setw(1)<<'|';
}


void operator << (ostream& out, class Casilla& c){
    c.mostrar_info(out);
}
//
// Created by erasmo on 5/27/26.
//

#include "Armadura.hpp"

void Armadura::leer(ifstream &input) {
    //Sword,A sharp and sturdy sword.,147
    Item::leer(input);
    //147
    input>>modificador_defensa;
    input.get();
}
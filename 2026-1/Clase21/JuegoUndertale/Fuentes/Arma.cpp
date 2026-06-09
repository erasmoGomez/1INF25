//
// Created by erasmo on 5/26/26.
//

#include "Arma.hpp"

void Arma::leer(ifstream &input) {
    //Sword,A sharp and sturdy sword.,147
    Item::leer(input);
    //147
    input>>modificador_ataque;
    //cout<<modificador_ataque<<endl;
}

int Arma::get_modificador() {
    return modificador_ataque;
}

//
// Created by Erasmo on 4/09/25.
//

#include "Sobrecargas.hpp"

void operator>>(ifstream &input, struct Plato &plato){
//AP-500,CHORIZOS COCKTAIL,12.90,APERITIVO
    input.getline(plato.codigo, 7, ',');
    input.getline(plato.nombre, 60, ',');
    input>>plato.precio;
    input.get();
    while(input.get()!='\n');
}
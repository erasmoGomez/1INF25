//
// Created by Erasmo on 9/10/25.
//

#include "Mochila.hpp"

Mochila::Mochila() {
    cantidad_armaduras = 0;
    cantidad_armas = 0;
    cantidad_consumibles = 0;
    bolsillo_armaduras = new Armadura[20]{};
    bolsillo_armas = new Arma[20]{};
    bolsillo_consumibles = new Consumible[20]{};
}

int Mochila::getCantidadArmaduras() const {
    return cantidad_armaduras;
}

void Mochila::setCantidadArmaduras(int cantidadArmaduras) {
    cantidad_armaduras = cantidadArmaduras;
}

int Mochila::getCantidadArmas() const {
    return cantidad_armas;
}

void Mochila::setCantidadArmas(int cantidadArmas) {
    cantidad_armas = cantidadArmas;
}

int Mochila::getCantidadConsumibles() const {
    return cantidad_consumibles;
}

void Mochila::setCantidadConsumibles(int cantidadConsumibles) {
    cantidad_consumibles = cantidadConsumibles;
}

void Mochila::leer_item(ifstream &input) {
    //1,Sword,A sharp and sturdy sword.,147,3
    //2,Potion,A healing potion that restores health.,130,4
    //3,Leather Armor,Lightweight leather armor for protection.,173,4

    //3 opciones: bolsillo_armas, bolsillo_armaduras, bolsillo_consumibles
    char buffer_tipo[20];
    input.getline(buffer_tipo, 20, ',');

    if(!strcmp(buffer_tipo, "Weapon")){
        Arma arma;
        arma.leer(input);
        bolsillo_armas[cantidad_armas] = arma;
        cantidad_armas++;
    }

    if(!strcmp(buffer_tipo, "Consumable")){
        Consumible consumible;
        consumible.leer(input);
        bolsillo_consumibles[cantidad_consumibles] = consumible;
        cantidad_consumibles++;
    }

    if(!strcmp(buffer_tipo, "Armor")){
        Armadura armadura;
        armadura.leer(input);
        bolsillo_armaduras[cantidad_armaduras] = armadura;
        cantidad_armaduras++;
    }


}

int Mochila::equipar_armadura(const char* nombre_item){
    for(int i = 0; i< cantidad_armaduras; i++){
        char nombre[30];
        bolsillo_armaduras[i].getNombre(nombre);
        if(strcmp(nombre, nombre_item)==0){
            bolsillo_armaduras[i].setEquipado(true);
            return bolsillo_armaduras[i].getValorIncrementar1();
        }
    }
    return 0;
}

int Mochila::equipar_consumible(const char* nombre_item){
    for(int i = 0; i< cantidad_consumibles; i++){
        char nombre[30];
        bolsillo_consumibles[i].getNombre(nombre);
        if(strcmp(nombre, nombre_item)==0){
            bolsillo_consumibles[i].setEquipado(true);
            return bolsillo_consumibles[i].getValorIncrementar1();
        }
    }
    return 0;
}

void Mochila::mostrar_items(ostream& output) const {
    output << "Tab Consumibles" << endl;
    for (int i = 0; i < cantidad_consumibles; i++)
        bolsillo_consumibles[i].mostrar(output);
    output << "Tab Armas" << endl;
    for (int i = 0; i < cantidad_armas; i++)
        bolsillo_armas[i].mostrar(output);
    output << "Tab Armadura" << endl;
    for (int i = 0; i < cantidad_armaduras; i++)
        bolsillo_armaduras[i].mostrar(output);
}

int Mochila::equipar_arma(const char* nombre_item){
    for(int i = 0; i< cantidad_armaduras; i++){
        char nombre[30];
        bolsillo_armas[i].getNombre(nombre);
        if(strcmp(nombre, nombre_item)==0){
            bolsillo_armas[i].setEquipado(true);
            return bolsillo_armas[i].getValorIncrementar1();
        }
    }
    return 0;
}
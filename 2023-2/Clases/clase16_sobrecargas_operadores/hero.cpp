/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "hero.hpp"
using namespace std;

Hero::Hero(){
    name = nullptr;
    posx = 0;
    posy = 0;
//    hp = 1000;
    attack = 100;
}

Hero::~Hero(){
    if(name !=nullptr) delete name;
}

void Hero::SetPosy(int posy) {
    this->posy = posy;
}

int Hero::GetPosy() const {
    return posy;
}

void Hero::SetPosx(int posx) {
    this->posx = posx;
}

int Hero::GetPosx() const {
    return posx;
}

void Hero::SetAttack(double attack) {
    this->attack = attack;
}

double Hero::GetAttack() const {
    return attack;
}

void Hero::SetHp(int hp) {
    this->hp = hp;
}

int Hero::GetHp() const {
    return hp;
}

void Hero::SetName(const char* name) {
    if(this->name != nullptr) delete this->name;
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
}

//void Hero::SetName(const char* cad) {
//    if(name != nullptr) delete name;
//    name = new char[strlen(cad)+1];
//    strcpy(name, cad);
//}

void Hero::GetName(char *cad) const {
    if(name == nullptr) cad[0] = 0;
    else strcpy(cad, name);
}

void Hero::Display(){
    char nombre[100];
    GetName(nombre);
    cout<<"Nombre del Heroe: "<<nombre<<endl;
    cout<<"Vida del Heroe: "<<GetHp()<<endl;
    cout<<"Posicion del Heroe: "<<GetPosx()<<"  "<<GetPosy()<<endl;
    cout<<"Ataque del Heroe: "<<GetAttack()<<endl;
}

//Sobrecargas dentro de la clase
void Hero::operator++(void){
    SetPosy(GetPosy()+1);
}

void Hero::operator--(void){
    SetPosy(GetPosy()-1);
}

void Hero::operator++(int){
    SetPosx(GetPosx()-1);
}

void Hero::operator--(int){
    SetPosx(GetPosx()+1);
}

//Sobrecarga fuera de la clase
void operator<<(ofstream &out, const class Hero &h){
    char nombre[100];
    h.GetName(nombre);
    out<<"Nombre del Heroe: "<<nombre<<endl;
    out<<"Vida del Heroe: "<<h.GetHp()<<endl;
    out<<"Posicion del Heroe: "<<h.GetPosx()<<"  "<<h.GetPosy()<<endl;
    out<<"Ataque del Heroe: "<<h.GetAttack()<<endl;
}

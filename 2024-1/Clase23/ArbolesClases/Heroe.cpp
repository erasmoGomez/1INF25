//
// Created by Erasmo on 8/05/24.
//
#include "Utils.hpp"
#include "Heroe.hpp"
using namespace std;
Heroe::Heroe() {
    hp = 100;
    mana = 50.0;
    nombre = nullptr;
    posx = 10;
    posy = 10;
    ataque = 100;
    vida = 100;
    defensa = 100;
}

Heroe::Heroe(const Heroe& orig){
    //Para asegurar la copia
    cout<<"copiaaaaaa"<<endl;
    nombre = nullptr;
    *this = orig;
}

void Heroe::leer(ifstream &input) {
    char extra, buffer[20];
    //Teemo,500, 25.3, 15, 15
    input.getline(buffer, 20,',');
    input>>vida>>extra;
    input>>mana>>extra;
    input>>posx>>extra;
    input>>posy;
    input.get();
    setNombre(buffer);
}

void Heroe::mostrar(ostream &output) {
    output<<"Nombre Heroe 2: "<<nombre<<endl;
    output<<"El heroe esta ubicado en la casilla : ("<< posx<<", "<<posy<<")"<<endl;
    output<<"Vida: "<<vida<<endl;
    output<<"Ataque: "<<ataque<<endl;
    output<<"Defensa: "<<defensa<<endl;
    mostrar_items();
}

void Heroe::getNombre(char *nombre) const {
    if(this->nombre== nullptr) nombre[0] = 0;
    else strcpy(nombre,this->nombre);
}

void Heroe::setNombre(const char *nombre) {
    if(this->nombre!= nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

int Heroe::getHp() const {
    return hp;
}

void Heroe::setHp(int hp) {
    Heroe::hp = hp;
}

double Heroe::getMana() const {
    return mana;
}

void Heroe::setMana(double mana) {
    Heroe::mana = mana;
}

int Heroe::getPosx() const {
    return posx;
}

void Heroe::setPosx(int posx) {
    Heroe::posx = posx;
}

int Heroe::getPosy() const {
    return posy;
}

void Heroe::setPosy(int posy) {
    Heroe::posy = posy;
}

void Heroe::setDefensa(int defensa) {
    this->defensa = defensa;
}

int Heroe::getDefensa() const {
    return defensa;
}

void Heroe::setAtaque(int ataque) {
    this->ataque = ataque;
}

int Heroe::getAtaque() const {
    return ataque;
}

void Heroe::setVida(int vida) {
    this->vida = vida;
}

int Heroe::getVida() const {
    return vida;
}

void Heroe::agregar_mochila(ifstream& input_items, char *tipo){
    //mochila.agregar_item(input_items, tipo);
    mochila.cargar_items(input_items, tipo);
}

void Heroe::move(int pasos, char dir){
    for(int i=0; i<pasos; i++){
        if(dir == 'W'){
            setPosx(posx - 1);
        }
        if(dir == 'S'){
            setPosx(posx + 1);
        }
        if(dir == 'D'){
            setPosy(posy + 1);
        }
        if(dir == 'A'){
            setPosy(posy - 1);
        }
    }
}


//HEROE -> Mochila -> CONSUMIBLE
//CONSUMIBLE -> HEROE
void Heroe::equipar(const char*tipo, const char*nombre){
    int valor_incrementar = 0;
    if(strcmp(tipo, "Consumable")==0){
        valor_incrementar = mochila.buscar_consumible(nombre);
        if(valor_incrementar!=-1)
            vida += valor_incrementar;
    }
    if(strcmp(tipo, "Weapon")==0){
        valor_incrementar = mochila.buscar_arma(nombre);
        if(valor_incrementar!=-1)
            ataque += valor_incrementar;
    }
    if(strcmp(tipo, "Armor")==0){
        valor_incrementar = mochila.buscar_armadura(nombre);
        if(valor_incrementar!=-1)
            defensa += valor_incrementar;
    }
}

void Heroe::equipar(const char*nombre, int opt){
    int valor_incrementar = 0;
    valor_incrementar = mochila.buscar_item(nombre);
    if (opt==0)
        vida += valor_incrementar;
    if (opt==1)
        ataque += valor_incrementar;
    if (opt==2)
        defensa += valor_incrementar;
}

void Heroe::mostrar(ofstream &out) {
    out<<"Nombre: "<<nombre<<endl;
    out<<"Vida: "<<vida<<endl;
    out<<"Ataque: "<<ataque<<endl;
    out<<"Defensa: "<<defensa<<endl;
    mochila.mostrar(out);
}

void Heroe::mostrar_items(){
    mochila.mostrar();
}

void Heroe::operator++(void){
    move(1, 'S');
}

void Heroe::operator--(void){
    move(1, 'A');
}

void Heroe::operator++(int){
    move(1, 'W');
}

void Heroe::operator--(int){
    move(1, 'D');
}

bool Heroe::operator >(const Heroe &h){
    char buffer_nombre[30];
    h.getNombre(buffer_nombre);
    if(strcmp(this->nombre, buffer_nombre)>0)
        return true;
    else
        return false;
}

void Heroe::operator = (const class Heroe&h){
    char name_h[30];
    this->vida = h.getVida();
    this->ataque = h.ataque;
    defensa = h.defensa;
    posx = h.posx;
    posy = h.posy;
    h.getNombre(name_h);
    this->setNombre(name_h);
}

bool Heroe::operator == (const char*nombre){
    if(strcmp(this->nombre, nombre)==0)
        return true;
    else
        return false;
}

bool Heroe::operator > (const char*nombre){
    if(strcmp(this->nombre, nombre)>0)
        return true;
    else
        return false;
}

void operator >> (ifstream& input, Heroe& h){
    h.leer(input);
}

void operator << (ostream& output, Heroe &h){
    h.mostrar(output);
}
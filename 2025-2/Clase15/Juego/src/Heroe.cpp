//
// Created by Erasmo on 24/09/25.
//

#include "Heroe.hpp"

Heroe::Heroe() {
    cout<<"Estoy en el constructor por defecto"<<endl;
    this->id = nullptr; // Totalmente obligatorio para char*
    this->nombre = nullptr; //Totalmente obligatorio para char*
    // Para los demas atributos es deci del programador.
    this->defensa = 5.5;
    this->fuerza = 10.5;
    this->hp = 100;
    this->posx = 10;
    this->posy = 10;
    // El uso del puntero THIS
    // This es puntero a la clase trabajada. es por ello que se usa -> y no el .
}

//char* Heroe::getNombre() const {
//    // YO no puedo devolver al usuario una direccion de memoria que ocupa mi clase.
//    // Esto viola el encapsulamiento de POO.
//    return this->nombre;
//}

void Heroe::getId(char * id) const {
    if(this->id == nullptr) id[0] = '\0';
    else strcpy(id, this->id); // Copia al parametro de entrada lo que hay en la clase
}

void Heroe::setId(const char *id) {
    if(this->id !=nullptr) delete this->id; //Borro lo q hay en this->id
    this->id = new char[strlen(id) +1]; //Reserva de memoria
    strcpy(this->id, id); // Copiar los datos a la clase
}

void Heroe::setNombre(const char *nombre) {
    if(this->nombre != nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre) +1];
    strcpy(this->nombre, nombre);
}

void Heroe::getNombre(char *nombre) const{
    if(this->nombre == nullptr) nombre[0] = '\0';
    else strcpy(nombre, this->nombre);
}

int Heroe::getHp() const {
    return hp;
}

void Heroe::setHp(int hp) {
    //Heroe::hp = hp;
    //hp = hp_;
    this->hp = hp;
    //El uso de puntero this para diferenciar con elementos provenientes de fuera.
}

double Heroe::getFuerza() const {
    return fuerza;
}

void Heroe::setFuerza(double fuerza) {
    Heroe::fuerza = fuerza;
}

double Heroe::getDefensa() const {
    return defensa;
}

void Heroe::setDefensa(double defensa) {
    Heroe::defensa = defensa;
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

Heroe::Heroe(const char * nombre, int hp,
             double fuerza, double defensa, int posx, int posy) {
    cout<<"Estoy en el constructor por parametros 1"<<endl;
    this->id = nullptr;
    this->nombre = nullptr;
    setId("H001");
    setNombre(nombre);
    this->hp = hp; // setHp(hp);
    this->fuerza = fuerza;
    setDefensa(defensa);
    setPosx(posx);
    setPosy(posy);
}

void Heroe::set_valores_iniciales(){
    this->id = nullptr;
    this->nombre = nullptr;
    setId("H002");
    setHp(100);
}

Heroe::Heroe(const char *nombre) {
    cout<<"Estoy en el constructor con parametros 2"<<endl;
    set_valores_iniciales();
    setNombre(nombre);
}

void Heroe::mostrar_info(ofstream &output) {
    cout<<"Estoy siendo llamado desde el main"<<endl;
    output<<"ID : "<<id<<endl;
    output<<"Nombre : "<<nombre<<endl;
    output<<"HP : "<<hp<<endl;
    output<<"FUERZA : "<<fuerza<<endl;
    output<<"DEFENSA : "<<defensa<<endl;
    output<<"POS X : "<<posx<<endl;
    output<<"POS Y : "<<posy<<endl;
    for(int i=0; i<30; i++) output.put('=');
    output<<endl;
}

void Heroe::cargar_datos(ifstream &input) {
//H002,Bran,120,12,10,0,0
    char buffer[20];
    input.getline(buffer, 20,',');
    setId(buffer);
    input.getline(buffer, 20,',');
    setNombre(buffer);
    input>>hp;
    input.get();
    input>>fuerza;
    input.get();
    input>>defensa;
    input.get();
    input>>posx;
    input.get();
    input>>posy;
    input.get();
}


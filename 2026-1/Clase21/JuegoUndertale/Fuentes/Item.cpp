//
// Created by erasmo on 5/27/26.
//

#include "Item.hpp"

bool Item::is_equipado() const {
    return equipado;
}

void Item::set_equipado(bool equipado) {
    this->equipado = equipado;
}

Item::Item() {
    nombre = nullptr;
    descripcion = nullptr;
    equipado = false;
}

void Item::set_nombre(const char *nombre) {
    if (this->nombre != nullptr) delete[] this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

void Item::get_nombre(char *nombre) const {
    if (this->nombre == nullptr) nombre[0] = '\0';
    else strcpy(nombre, this->nombre);
}

void Item::set_descripcion(const char *descripcion) {
    if (this->descripcion != nullptr) delete[] this->nombre;
    this->descripcion = new char[strlen(descripcion) + 1];
    strcpy(this->descripcion, descripcion);
}

void Item::leer(ifstream & input) {
    //Sword,A sharp and sturdy sword.,
    char buffer[150];
    input.getline(buffer, 150, ',');
    set_nombre(buffer);
    input.getline(buffer, 150, ',');
    set_descripcion(buffer);

}

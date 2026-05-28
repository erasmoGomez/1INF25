//
// Created by erasmo on 5/27/26.
//

#include "Item.hpp"

Item::Item() {
    nombre = nullptr;
    descripcion = nullptr;
}

void Item::set_nombre(const char *nombre) {
    if (this->nombre != nullptr) delete[] this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

void Item::set_descripcion(const char *descripcion) {
    if (this->descripcion != nullptr) delete[] this->nombre;
    this->descripcion = new char[strlen(descripcion) + 1];
    strcpy(this->descripcion, descripcion);
}

void Item::leer(ifstream & input) {
    //Sword,A sharp and sturdy sword.,
    char buffer[100];
    input.getline(buffer, 100, ',');
    set_nombre(buffer);
    input.getline(buffer, 100, ',');
    set_descripcion(buffer);

}

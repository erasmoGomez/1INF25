//
// Created by Erasmo on 9/10/25.
//

#include "Item.hpp"

Item::Item() {
    nombre = nullptr;
    this->descripcion = nullptr;
    codigo = 0;
}

int Item::getCodigo() const {
    return codigo;
}

void Item::setCodigo(int codigo) {
    Item::codigo = codigo;
}

void Item::setNombre(const char *nombre) {
    if (this->nombre != nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

void Item::getNombre(char *nombre) const {
    if (this->nombre == nullptr) nombre[0] = '\0';
    else strcpy(nombre, this->nombre);
}

void Item::setDescripcion(const char *descripcion) {
    if (this->descripcion != nullptr) delete this->descripcion;
    this->descripcion = new char[strlen(descripcion) + 1];
    strcpy(this->descripcion, descripcion);
}

void Item::getDescripcion(char *descripcion) const {
    if (this->descripcion == nullptr) descripcion[0] = '\0';
    else strcpy(descripcion, this->descripcion);
}

//int Item::getValorIncrementar() const {
//    return valor_incrementar;
//}
//
//void Item::setValorIncrementar(int valorIncrementar) {
//    valor_incrementar = valorIncrementar;
//}

Item::Item(int codigo, char *nombre, char *descripcion, int valorIncrementar) {

}

void Item::leer(ifstream &input) {
//1,Sword,A sharp and sturdy sword.,
    char buffer[60];
    input >> codigo;
    input.get();
    input.getline(buffer, 60, ',');
    setNombre(buffer);
    input.getline(buffer, 60, ',');
    setDescripcion(buffer);
}

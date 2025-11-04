//
// Created by Erasmo on 9/10/25.
//

#include "Item.hpp"

Item::Item() {
    nombre = nullptr;
    this->descripcion = nullptr;
    codigo = 0;
    equipado = false;
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

bool Item::getEquipado() const {
    return equipado;
}

void Item::setEquipado(bool equipado) {
    Item::equipado = equipado;
}

void Item::leer(ifstream &input) {
//Sword,A sharp and sturdy sword.,
    char buffer[60];
    input.getline(buffer, 60, ',');
    setNombre(buffer);
    input.getline(buffer, 60, ',');
    setDescripcion(buffer);
}

void Item::mostrar(ostream &output) const {
    output << setw(30) << left << nombre;
    output << setw(50) << left << descripcion;
}
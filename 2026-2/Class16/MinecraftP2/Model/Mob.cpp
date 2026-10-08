//
// Created by erasmo on 10/7/26.
//

#include "Mob.hpp"

int Mob::get_elementos_by_index(const int index) {
    return elementos[index];
}

int Mob::get_id() const {
    return id;
}

void Mob::set_id(const int id) {
    this->id = id;
}

void Mob::get_type(char* type) const {
    if (this->type == nullptr) type[0] = '\0';
    else strcpy(type, this->type);
}

void Mob::set_type(const char * type) {
    if (this->type!=nullptr) delete [] this->type;
    this->type = new char[strlen(type)+1];
    strcpy(this->type, type);
}

int Mob::get_health() const {
    return health;
}

void Mob::set_health(const int health) {
    this->health = health;
}

int Mob::get_damage() const {
    return damage;
}

void Mob::set_damage(const int damage) {
    this->damage = damage;
}

int Mob::get_x() const {
    return x;
}

void Mob::set_x(const int x) {
    this->x = x;
}

int Mob::get_y() const {
    return y;
}

void Mob::set_y(const int y) {
    this->y = y;
}

int Mob::get_z() const {
    return z;
}

void Mob::set_z(const int z) {
    this->z = z;
}

void Mob::copy(const Mob &other) {
    char type_buffer[20];
    other.get_type(type_buffer);
    set_type(type_buffer);
    this->id = other.id;
    this->health = other.get_health();
    this->x = other.get_x();
    this->y = other.get_y();
    this->z = other.get_z();
}

void Mob::print(ofstream &out) const {
    out << "========================================\n";
    out << "              MOB INFO               \n";
    out << "========================================\n";
    out << left << setw(12) << "Typr:" << type << '\n';
    out << left << setw(12) << "Health:" << health << '\n';
    out << left << setw(12) << "Position:"
            << "(" << x << ", " << y << ", " << z << ")\n";
    out << "========================================\n\n";
}

Mob::Mob() {
    id=0;
    health=100;
    damage=100;
    x=0;
    y=0;
    z=0;
    type=nullptr;
}

Mob::Mob(const int id, char * const type, const int x, const int y, const int z) {
    this->id = id;
    this->x = x;
    this->y = y;
    this->z = z;
    this->type = nullptr;
    this->set_type(type); // set_type(type)
}

Mob::~Mob() {
    cout<<"Destructor MOB!"<<endl;
    delete [] this->type;
}

void Mob::read(ifstream &input) {
//201,Zombie,20,4,7,4
    char buffer[20];
    input>>id;
    if (input.eof()) return;
    input.get();
    input.getline(buffer,20,',');
    set_type(buffer);
    input>>health;
    input.get();
    input>>damage;
    input.get();
    input>>x;
    input.get();
    input>>y;
    this->z = 0;
}

void operator>>(ifstream &input, class Mob &m) {
    m.read(input);
}

void operator<<(ofstream &output, const class Mob &m) {
    m.print(output);
}

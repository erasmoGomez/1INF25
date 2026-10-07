#include "Player.hpp"

int Player::get_id() const {
    return id;
}

void Player::set_id(const int id) {
    this->id = id;
}

void Player::get_name(char* name_ptr) const {
    if (this->name == nullptr) name_ptr[0] = '\0';
    else strcpy(name_ptr, this->name);
}

void Player::set_name(const char * name) {
    if (this->name!=nullptr) delete [] this->name;
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
}

int Player::get_level() const {
    return level;
}

void Player::set_level(const int level) {
    this->level = level;
}

int Player::get_health() const {
    return health;
}

void Player::set_health(const int health) {
    this->health = health;
}

int Player::get_x() const {
    return x;
}

void Player::set_x(const int x) {
    this->x = x;
}

int Player::get_y() const {
    return y;
}

void Player::set_y(const int y) {
    this->y = y;
}

int Player::get_z() const {
    return z;
}

void Player::set_z(const int z) {
    this->z = z;
}

Player::Player() {
    x = 10;
    y = 10;
    z = 10;
    health = 100;
    name = nullptr;
    level = 0;
}

Player::Player(const char *name,
               int health,
               int x,
               int y) {
    this->health = health;
    this->x = x;
    this->y = y;
    this->z = 0;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    level = 0;
}

// Player::Player(const Player &other) {
//     cout << "Haciendo una copia" << endl;
//     level = other.level;
//     health = other.health;
//     x = other.x;
//     y = other.y;
//     z = other.z;
//
//     if (other.name != nullptr) {
//         name = new char[strlen(other.name) + 1];
//         strcpy(name, other.name);
//     } else {
//         name = nullptr;
//     }
// }

Player::~Player() {
    cout << "Destructor de Player" << endl;
    delete []name;
}

void Player::move(int dx, int dy, int dz) {
    x += dx;
    y += dy;
    z += dz;
}

void Player::receive_damage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
}

void Player::attack() {
}

void Player::read(ifstream &in) {
    char buffer[100];
    //103,Erasmo,20,20,20,10,0
    in >> id;
    if (in.eof()) return;
    in.get();

    in.getline(buffer, 100, ',');
    // name = new char[strlen(buffer) + 1];
    // strcpy(name, buffer);
    set_name(buffer);

    in >> level;
    in.get();

    in >> health;
    in.get();

    in >> x;
    in.get();

    in >> y;
    in.get();

    in >> z;
}

void Player::print(ostream &out) const {
    out << "========================================\n";
    out << "              PLAYER INFO               \n";
    out << "========================================\n";
    out << left << setw(12) << "Name:" << name << '\n';
    out << left << setw(12) << "Level:" << level << '\n';
    out << left << setw(12) << "Health:" << health << '\n';
    out << left << setw(12) << "Position:"
            << "(" << x << ", " << y << ", " << z << ")\n";
    out << "========================================\n\n";
}

void Player::operator=(const Player &other) {
    char name_buffer[20];
    other.get_name(name_buffer);
    set_name(name_buffer);
    this->health = other.get_health();
    this->x = other.get_x();
    this->y = other.get_y();
    this->z = other.get_z();
    this->level = other.get_level();
}

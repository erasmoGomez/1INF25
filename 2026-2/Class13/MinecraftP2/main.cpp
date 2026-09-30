#include "Model/Creeper.hpp"

int main() {
    cout << boolalpha;
    Creeper creeper1;
    creeper1.set_charged(true);
    creeper1.set_health(100);
    creeper1.set_damage(50);
    creeper1.explode();
    cout << "Health: " << creeper1.get_health() << endl;
    cout << "Damage: " << creeper1.get_damage() << endl;
    cout << "Boom? : " << creeper1.is_charged() << endl;
    cout << "Creeper KABOOM!" << endl;

    Creeper creeper2;
    creeper2.explode();
    cout << "Health: " << creeper2.get_health() << endl;
    cout << "Damage: " << creeper2.get_damage() << endl;
    cout << "Boom? : " << creeper2.is_charged() << endl;
    cout << "Creeper KABOOM!" << endl;
    return 0;
}

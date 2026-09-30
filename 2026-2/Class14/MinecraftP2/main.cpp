#include "Controller/GameController.hpp"

int main() {
    Creeper creeper1;
    creeper1.set_charged(true);
    creeper1.set_health(100);
    creeper1.set_damage(50);
    creeper1.explode();
    cout<<"Vida: "<<creeper1.get_health()<<endl;
    cout<<"Daño: "<<creeper1.get_damage()<<endl;
    cout<<"Exploto? : "<<creeper1.is_charged()<<endl;
    cout<<"Creeper EXPLOTO!"<<endl;

    Creeper creeper2;
    creeper2.explode();
    cout<<"Vida: "<<creeper2.get_health()<<endl;
    cout<<"Daño: "<<creeper2.get_damage()<<endl;
    cout<<"Exploto? : "<<creeper2.is_charged()<<endl;
    cout<<"Creeper EXPLOTO!"<<endl;
    return 0;
}
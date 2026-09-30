#include "Model/Creeper.hpp"
#include "Model/Player.hpp"

int main() {
    // Creeper creeper1;
    // creeper1.set_charged(true);
    // creeper1.set_health(100);
    // creeper1.set_damage(50);
    // creeper1.explode();
    // cout<<"Vida: "<<creeper1.get_health()<<endl;
    // cout<<"Daño: "<<creeper1.get_damage()<<endl;
    // cout<<"Exploto? : "<<creeper1.is_charged()<<endl;
    // cout<<"Creeper EXPLOTO!"<<endl;
    //
    // Creeper creeper2;
    // creeper2.explode();
    // cout<<"Vida: "<<creeper2.get_health()<<endl;
    // cout<<"Daño: "<<creeper2.get_damage()<<endl;
    // cout<<"Exploto? : "<<creeper2.is_charged()<<endl;
    // cout<<"Creeper EXPLOTO!"<<endl;

    // CONSTRUCTOR POR DEFECTO
    // Creeper c1; // llama al constructor por defecto
    // Creeper c2;
    // Creeper creepers[10];
    // Creeper *creepers_dynamic;
    // creepers_dynamic = new Creeper[10];

    // CONSTRUCTOR CON PARAMETROS
    Creeper c3(130, 50, false);
    Creeper c4(true);

    // CONSTRUCTOR COPIA
    Creeper creeper_copia(c3);

    Player player;
    return 0;
}

#include "Model/World.hpp"

int main() {
    World world;
    world.load_players("Data/players.csv");
    world.print_players("Report/players.txt");
    // Player p("Erasmo", 20, 15, 10);
    // char nombre[20]{};
    // p.get_name(nombre);
    // cout<<nombre<<endl;
    //
    // p.set_name("Suazo!");
    // p.set_name("Laura");
    return 0;
}

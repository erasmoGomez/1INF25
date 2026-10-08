#include "Model/World.hpp"
#include "Utilities/Utils.hpp"
int main() {
    World world;
    world.load_players("Data/players.csv");
    world.print_players("Report/players.txt");
    world.load_mobs("Data/mobs.csv");
    world.print_mobs("Report/mobs.txt");
    world.load_world("Data/map.csv");
    // Player p("erasmo", 10,10,10);
    // Player p2(p);
    // char buffer[20];
    // p2.get_name(buffer);
    // cout << buffer << endl;
    return 0;
}

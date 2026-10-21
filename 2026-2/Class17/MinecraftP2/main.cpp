#include "Model/World.hpp"
#include "Utilities/Utils.hpp"
int main() {
    World world;
    world.load_players("Data/players.csv");
    world.print_players("Report/players.txt");
    world.load_mobs("Data/mobs.csv");
    world.print_mobs("Report/mobs.txt");
    world.load_world("Data/world.csv");
    world.add_elements();
    world.display();
    world.play();
    return 0;
}

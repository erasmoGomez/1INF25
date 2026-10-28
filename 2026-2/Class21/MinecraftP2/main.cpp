#include "Model/World.hpp"
#include "Utilities/Utils.hpp"
#include "Model/Item.hpp"
#include "Model/Weapon.hpp"
int main() {
    World world;
    world.load_players("Data/players.csv");
    // world.print_players("Report/players.txt");
    // world.load_mobs("Data/mobs.csv");
    // world.print_mobs("Report/mobs.txt");
    // world.load_world("Data/world.csv");
    // world.add_elements();
    // world.display();
    // world.play();
    //Item item_A(100, "Espada De Diamante", 75.23);
    world.load_items("Data/inventory_erasmo.csv");
    world.interact(2);
    return 0;
}

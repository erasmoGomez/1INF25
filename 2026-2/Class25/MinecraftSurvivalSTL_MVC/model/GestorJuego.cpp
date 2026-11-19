#include "GestorJuego.hpp"
#include "DataLoader.hpp"
#include "../view/GameView.hpp"
using namespace std;

GestorJuego::GestorJuego(const string& data_dir) : data_dir(data_dir) {}
GestorJuego::~GestorJuego() = default;

void GestorJuego::load_data() {
    bool ok = true;
    ok = load_blocks(data_dir + "/blocks.csv", mining) && ok;
    ok = load_requests(data_dir + "/villagers.csv", villagers) && ok;
    ok = load_regions(data_dir + "/regions.csv", world) && ok;
    ok = load_paths(data_dir + "/paths.csv", world) && ok;
    ok = load_resources(data_dir + "/resources.csv", resources) && ok;
    if (!ok) GameView::show_message("Warning: some initial data could not be loaded.");
}
void GestorJuego::run() {
    while (true) {
        GameView::show_menu();
        int option = Utils::read_int("Select an option: ");
        if (!cin || option == 0) break;
        execute_option(option);
    }
    GameView::show_message("Goodbye, Steve!");
}
void GestorJuego::mine_block() {
    string block = Utils::read_text("Block: ");
    if (!block.empty()) { mining.push(block); ++resources[block]; }
}
void GestorJuego::remove_block() {
    string block;
    if (mining.pop(block)) GameView::show_message("Removed: " + block);
    else GameView::show_message("Stack empty.");
}
void GestorJuego::add_request() {
    VillagerRequest request;
    request.set_villager(Utils::read_text("Villager: "));
    request.set_resource(Utils::read_text("Resource: "));
    request.set_quantity(Utils::read_int("Quantity: "));
    if (request.valid())
        villagers.enqueue(request);
    else GameView::show_message("Invalid request.");
}
void GestorJuego::attend_villager() {
    VillagerRequest request;
    if (!villagers.front(request)) {
        GameView::show_message("Queue empty.");
        return;
    }
    auto it = resources.find(request.get_resource());
    if (it == resources.end() || it->second < request.get_quantity()) {
        GameView::show_message("Not enough " + request.get_resource() + ". Request remains queued.");
        return;
    }
    it->second -= request.get_quantity();
    villagers.dequeue(request);
    GameView::show_message("Served " + request.get_resource() + ".");
}
void GestorJuego::add_region() {
    string name = Utils::read_text("New region: ");
    if (name.empty()) return;
    string type = Utils::read_text("Type (Safe/Dangerous): ");
    if (type != "Safe" && type != "Dangerous") {
        GameView::show_message("Invalid region type.");
        return;
    }
    world.add_region(name, type);
}
void GestorJuego::connect_regions() {
    string origin = Utils::read_text("Origin: ");
    string destination = Utils::read_text("Destination: ");
    GameView::show_message(world.add_path(origin, destination) ?
                           "Path connected." : "Invalid path.");
}
void GestorJuego::show_world() {
    world.show_regions();
    string region = Utils::read_text("Show connections for region (blank to skip): ");
    if (!region.empty()) world.show_connections(region);
}
void GestorJuego::collect_resources() {
    string name = Utils::read_text("Resource: ");
    int quantity = Utils::read_int("Quantity: ");
    if (!name.empty() && quantity > 0) {
        resources[name] += quantity;
        GameView::show_message("Stored " + to_string(quantity) + " " + name + ".");
    } else GameView::show_message("Invalid resource or quantity.");
}
void GestorJuego::craft_sword() {
    if (resources["Diamond"] >= 2) {
        resources["Diamond"] -= 2;
        GameView::show_message("Diamond sword crafted! Remaining diamonds: " +
                               to_string(resources["Diamond"]));
    } else GameView::show_message("Not enough diamonds (need 2).");
}
void GestorJuego::execute_option(int option) {
    switch (option) {
        case 1: mine_block(); break;
        case 2: remove_block(); break;
        case 3: mining.display(); break;
        case 4: add_request(); break;
        case 5: attend_villager(); break;
        case 6: villagers.display(); break;
        case 7: add_region(); break;
        case 8: connect_regions(); break;
        case 9: show_world(); break;
        case 10: GameView::show_resources(resources); break;
        case 11: collect_resources(); break;
        case 12: craft_sword(); break;
        default: GameView::show_message("Unknown option.");
    }
}

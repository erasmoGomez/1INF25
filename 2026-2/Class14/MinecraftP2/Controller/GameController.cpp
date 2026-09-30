#include "GameController.hpp"
#include <iostream>
using namespace std;

void GameController::start() {
    view.display_welcome();
    load_game();

    int option;

    do {
        view.display_menu();
        cin >> option;
        process_option(option);
    } while (option != 5);
}

void GameController::load_game() {
    world.load_players("Data/players.txt");
    world.load_creepers("Data/creepers.txt");
    world.load_zombies("Data/zombies.txt");
}

void GameController::process_option(int option) {
    switch (option) {
        case 1:
            view.display_world(world);
            break;
        case 2:
            move_player();
            break;
        case 3:
            attack();
            break;
        case 4:
            if (world.get_player() != nullptr)
                view.display_player(*world.get_player());
            else
                view.display_message("Player has not been loaded.");
            break;
        case 5:
            view.display_message("Leaving Minecraft...");
            break;
        default:
            view.display_message("Invalid option.");
    }
}

void GameController::move_player() {
    Player *player = world.get_player();

    if (player == nullptr) {
        view.display_message("Player has not been loaded.");
        return;
    }

    int dx, dy;

    cout << "dx: ";
    cin >> dx;
    cout << "dy: ";
    cin >> dy;

    player->move(dx, dy);
}

void GameController::attack() {
    Player *player = world.get_player();

    if (player == nullptr) {
        view.display_message("Player has not been loaded.");
        return;
    }

    player->attack();
    view.display_message("Player attacks!");
}

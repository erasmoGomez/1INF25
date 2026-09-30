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

}

void GameController::process_option(int option) {
    switch (option) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
    }
}

void GameController::move_player() {
}

void GameController::attack() {
}

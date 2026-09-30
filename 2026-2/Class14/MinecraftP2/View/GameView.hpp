#ifndef GAME_VIEW_HPP
#define GAME_VIEW_HPP

#include "../Model/World.hpp"

class GameView {
public:
    void display_welcome();
    void display_menu();
    void display_world(World &world);
    void display_player(Player &player);
    void display_message(const char *message);
};

#endif

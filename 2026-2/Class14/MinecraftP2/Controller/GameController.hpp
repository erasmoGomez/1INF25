#ifndef GAME_CONTROLLER_HPP
#define GAME_CONTROLLER_HPP

#include "../Model/World.hpp"
#include "../View/GameView.hpp"

class GameController {
private:
    World world;
    GameView view;

    void load_game();
    //void process_option(int option);
    // void move_player();
    // void attack();

public:
    void start();
};

#endif

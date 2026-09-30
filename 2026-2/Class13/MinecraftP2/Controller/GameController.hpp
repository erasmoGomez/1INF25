#ifndef GAME_CONTROLLER_HPP
#define GAME_CONTROLLER_HPP
#include "../View/GameView.hpp"

class GameController {
private:
    GameView view;

    void load_game();
    void process_option(int option);
    void move_player();
    void attack();

public:
    void start();
};

#endif

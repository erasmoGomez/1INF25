#include "GameView.hpp"
#include <iostream>
using namespace std;

void GameView::display_welcome() {
    cout << "==========================" << endl;
    cout << "      MINECRAFT C++        " << endl;
    cout << "==========================" << endl;
}

void GameView::display_menu() {
    cout << endl;
    cout << "1. Show world" << endl;
    cout << "2. Move player" << endl;
    cout << "3. Attack" << endl;
    cout << "4. Show player" << endl;
    cout << "5. Exit" << endl;
    cout << "Option: ";
}


void GameView::display_message(const char *message) {
    cout << message << endl;
}

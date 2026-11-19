#pragma once
#include "../model/Utils.hpp"
#include "../model/MiningStack.hpp"
#include "../model/VillagerQueue.hpp"
class GameView {
public:
    static void show_menu();
    static void show_message(const string& message);
    static void show_resources(const map<string, int>& resources);
};

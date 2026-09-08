#include "Libraries/Controller/VideoGamesController.hpp"

int main() {
    struct Players players{};
    load_players(players, "Data/players.csv", "Data/games.csv");
    display_players(players, "Reports/players_report_multiple_registers.txt");
    calculate_stats(players);
    return 0;
}

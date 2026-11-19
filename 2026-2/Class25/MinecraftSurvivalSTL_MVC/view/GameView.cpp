#include "GameView.hpp"
using namespace std;
void GameView::show_menu() {
    cout << "\n=== MINECRAFT SURVIVAL SYSTEM ===\n"
         << " 1. Mine a block\n 2. Remove last mined block\n"
         << " 3. Show mining stack\n 4. Add villager request\n"
         << " 5. Attend villager\n 6. Show villager queue\n"
         << " 7. Add region\n 8. Connect regions\n"
         << " 9. Show world map\n10. Explore BFS\n"
         << "11. Explore DFS\n12. Show resources\n"
         << "13. Collect resources\n14. Craft diamond sword\n"
         << " 0. Exit\n";
}
void GameView::show_message(const string& message) { cout << message << '\n'; }
void GameView::show_resources(const map<string, int>& resources) {
    cout << "Resource storage:\n";
    for (auto it = resources.cbegin(); it != resources.cend(); ++it)
        cout << "  " << it->first << ": " << it->second << '\n';
}

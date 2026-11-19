#include "model/GestorJuego.hpp"
using namespace std;

int main() {
    GestorJuego juego(PROJECT_DATA_DIR);
    juego.load_data();
    juego.run();
    return 0;
}

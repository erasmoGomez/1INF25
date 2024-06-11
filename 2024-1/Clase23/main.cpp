#include "Utils.hpp"
#include "Juego.hpp"
using namespace std;
int main() {
    Juego juego;
    juego.cargar_datos();
    juego.jugar();
    return 0;
}

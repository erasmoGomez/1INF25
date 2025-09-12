#include "src/Funciones.hpp"

int main() {
    char** apodos;
    ifstream input("Data/input.txt", ios::in);
    leer_datos(input, apodos);
    return 0;
}

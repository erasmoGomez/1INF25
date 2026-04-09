#include "Librerias/AperturaArchivos.hpp"

int main() {
    ifstream input;
    open_file_read(input, "Data/datos.txt");

    int codigo = 0;
    input>>codigo;

    ofstream output;
    open_file_write(output, "Reports/reporte.txt");

    output<<codigo<<endl;
    return 0;
}
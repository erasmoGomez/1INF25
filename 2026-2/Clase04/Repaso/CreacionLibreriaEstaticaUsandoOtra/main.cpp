#include "Librerias/AperturaArchivos.hpp"
#include "Librerias/Sobrecargas.hpp"

int main() {
    ifstream input;
    open_file_read(input, "Data/datos.txt");

    Persona p;
    input>>p.edad>>p.salario;

    ofstream output;
    open_file_write(output, "Reports/reporte.txt");
    output<<"ANTES PROBAR SOBRECARGAS"<<endl;
    output<<setw(5)<<p.edad<<setw(10)<<p.salario<<endl;

    ++p;
    ++p;
    --p;

    p++;
    p--;

    output<<"LUEGO DE PROBRAR SOBRECARGAS"<<endl;
    output<<setw(5)<<p.edad<<setw(10)<<p.salario<<endl;

}
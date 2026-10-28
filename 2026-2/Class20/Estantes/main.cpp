#include "src/Biblioteca.hpp"
#include "src/Enciclopedia.hpp"

int main() {
    Biblioteca biblioteca;
    biblioteca.cargar_libros();
    biblioteca.cargar_estantes();
    biblioteca.posicionar_libros();
    // biblioteca.mostrar_datos();
    return 0;
}

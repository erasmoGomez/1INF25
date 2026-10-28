#include "Bibliotecas/Cuadrado.hpp"
#include "Bibliotecas/Figura.hpp"
#include "Bibliotecas/Triangulo.hpp"

int main() {
    Figura* figura;
    int n=5;
    Figura* figuras[10];
    figuras[0] = new Cuadrado();
    figuras[1] = new Triangulo();
    figuras[2] = new Cuadrado();
    figuras[3] = new Cuadrado();
    figuras[4] = new Triangulo();

    for (int i =0; i < n; i++) {
        figuras[i]->area(); // Esto es POLIMORFISMO
    }

    //Figura f;
    // Figura f;
    // f.leer();
    Figura* f;
    f = new Triangulo();
    f->leer();
    return 0;
}

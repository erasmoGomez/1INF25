//
// Created by Erasmo on 1/10/25.
//

#include "Circulo.hpp"
#define PI 3.141592
using namespace std;

double Circulo::area() {
    return PI * radio * radio;
}

double Circulo::perimetro() {
    return 2 * PI * radio;
}

void Circulo::mostrarResultados() {
    cout.precision(2);
    cout << fixed;
    cout << nombre << endl;
    cout << "Radio : " << setw(10) << radio << endl;
    cout << "Area : " << setw(10) << area() << endl;
    cout << "Perimetro : " << setw(10) << perimetro() << endl;

}

Circulo::Circulo() {
    radio = 10;
}

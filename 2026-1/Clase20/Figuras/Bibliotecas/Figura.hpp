//
// Created by erasmo on 6/2/26.
//

#ifndef FIGURAS_FIGURA_HPP
#define FIGURAS_FIGURA_HPP


class Figura {
public:
    // METODO VIRTUAL PURO
    // Se iguala a 0
    // No debe tener definicion en .cpp
    // Las derivadas OBLIGATORIAMENTE deben override el metodo puro.
    // Convierte a la clase en Clas Abstracta
    // es decir no se puede instanciar
    virtual void area() = 0;

    // METODO VIRTUAL
    // Debe ser virtual para q en tiempo de ejecucion, elija la clase a usar.
    // No convierte a la clase en abstracta.
    // Debe tener una definicion en la clase padre y en las hijas.
    virtual void leer();
};


#endif //FIGURAS_FIGURA_HPP

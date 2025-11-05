//
// Created by Erasmo on 4/11/25.
//

#ifndef PLANTILLAS_PERSONA_HPP
#define PLANTILLAS_PERSONA_HPP

#include "Utils.hpp"

class Persona {
public:
    Persona();

    Persona(const Persona &orig);

    virtual ~Persona();

    void operator=(const class Persona &);

    bool operator<(const class Persona &);

    void SetSueldo(double sueldo);

    double GetSueldo() const;

    void SetDni(int dni);

    int GetDni() const;

    void SetNombre(string nombre);

    string GetNombre() const;

    void leer();

    void imprimir() const;

private:
    int dni;
    string nombre;
    double sueldo;
};

void operator>>(istream &, class Persona &);

ostream &operator<<(ostream &, const class Persona &);


#endif //PLANTILLAS_PERSONA_HPP

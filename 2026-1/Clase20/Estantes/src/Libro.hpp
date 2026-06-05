//
// Created by Erasmo on 22/10/25.
//

#ifndef ESTANTES_LIBRO_HPP
#define ESTANTES_LIBRO_HPP


#include "Utils.hpp"

class Libro {
public:
    Libro(); //Defecto
    Libro(const Libro& orig); //Copia
    virtual ~Libro(); //Destructor
    void SetColocado(bool colocado);
    bool IsColocado() const;
    void SetAlto(int alto);
    int GetAlto() const;
    void SetAncho(int ancho);
    int GetAncho() const;
    void SetNombre(const char* nombre);
    void GetNombre(char*) const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char*) const;

    void leer(ifstream&);
    void mostrar(ofstream&)const;

    void operator = (const class Libro&); //Sobrecarga Del Igual

private:
    char* codigo;
    char* nombre;
    int ancho;
    int alto;
    bool colocado;
};

void operator>>(ifstream& input, Libro &);
void operator<<(ofstream& output, const Libro &);


#endif //ESTANTES_LIBRO_HPP

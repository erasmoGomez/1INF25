//
// Created by Erasmo on 22/10/25.
//

#ifndef ESTANTES_ESTANTE_HPP
#define ESTANTES_ESTANTE_HPP

#include "Espacio.hpp"
#include "Libro.hpp"

class Estante {
public:
    Estante();
    Estante(const Estante& orig);
    virtual ~Estante();
    void SetCantidad_libros(int cantidad_libros);
    int GetCantidad_libros() const;
    void SetAltura(int altura);
    int GetAltura() const;
    void SetAnchura(int anchura);
    int GetAnchura() const;
    void SetCodigo(const char*);
    void GetCodigo(char*) const;

    void leer(ifstream&);
    void mostrar(ofstream&)const;
    void imprime_linea(ofstream&, int, char) const;
    void pinta_estante(ofstream&) const;
    int get_espacios_restantes();
    void colocar_libro(int, Libro&);
    bool operator+=(Libro&);
private:
    char* codigo;
    int anchura;
    int altura;
    Libro libros[10];
    int cantidad_libros;
    Espacio *espacios;
    double peso_soportado;
    double peso_actual;
};

void operator>>(ifstream& input, Estante &);
void operator<<(ofstream& output, const Estante &);


#endif //ESTANTES_ESTANTE_HPP

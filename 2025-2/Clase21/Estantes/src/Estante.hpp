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

    Estante(const Estante &orig);

    virtual ~Estante();

    void SetCantidad_libros(int cantidad_libros);

    int GetCantidad_libros() const;

    void SetAltura(int altura);

    int GetAltura() const;

    void SetAnchura(int anchura);

    int GetAnchura() const;

    void SetCodigo(const char *);

    void GetCodigo(char *) const;

    double getPesoSoportado() const;

    void setPesoSoportado(double pesoSoportado);

    double getPesoActual() const;

    void setPesoActual(double pesoActual);

    void leer(ifstream &);

    //void mostrar(ofstream &) const;

    void imprime_linea(ofstream &, int, char) const;

    void pinta_estante(ofstream &) const;

    int get_espacios_restantes();

    void colocar_libro(int, Libro &);

    void setEspacioContenido(int i, char);

    void setEspacioPos(int i, int x, int y);

    void muestra_espacio(int i, int j, ofstream& output) const;

    bool operator+=(Libro &);


private:
    char *codigo;
    int anchura;
    int altura;
    Libro libros[10]; //Esto se crea en la compilacion
    int cantidad_libros;
    Espacio *espacios; //Esto se va a crear en tiempo de ejecucion
    double peso_soportado;
    double peso_actual;
};


void operator>>(ifstream &input, Estante &);

//void operator<<(ofstream &output, const Estante &);


#endif //ESTANTES_ESTANTE_HPP

//
// Created by Erasmo on 22/10/25.
//

#ifndef ESTANTES_BIBLIOTECA_HPP
#define ESTANTES_BIBLIOTECA_HPP


#include "Estante.hpp"
#include "Enciclopedia.hpp"
#include "Novela.hpp"

class Biblioteca {
public:
    Biblioteca(); //Por defecto
    Biblioteca(const Biblioteca& orig); //Copia
    virtual ~Biblioteca(); // Destructor
    void SetCantidad_libros(int cantidad_libros);
    int GetCantidad_libros() const;
    void SetCantidad_estantes(int cantidad_estantes);
    int GetCantidad_estantes() const;

    void cargar_libros();
    void cargar_estantes();
    void posicionar_libros();
    void mostrar_datos();
    void imprime_linea(ofstream&, int, char);

    void reserva_memoria();

private:
    Estante estantes[10];
    Libro libros[10];
    int cantidad_estantes;
    int cantidad_libros;

    Enciclopedia enciclopedias[10];
    int cantidad_total_enciclopedias;
    Novela novelas[10];
    int cantidad_total_novelas;
    int capacidad_enciclopedias;
};


#endif //ESTANTES_BIBLIOTECA_HPP

//
// Created by Erasmo on 22/10/25.
//

#ifndef ESTANTES_BIBLIOTECA_HPP
#define ESTANTES_BIBLIOTECA_HPP

#include "EstanteHorizontal.hpp"
#include "EstanteVertical.hpp"


class Biblioteca {
public:
    Biblioteca();

    Biblioteca(const Biblioteca &orig);

    virtual ~Biblioteca();

    int getCantidadEstantesVerticales() const;

    void setCantidadEstantesVerticales(int cantidadEstantesVerticales);

    int getCantidadEstantesHorizontales() const;

    void setCantidadEstantesHorizontales(int cantidadEstantesHorizontales);

    int getCantidadTotalEnciclopedias() const;

    void setCantidadTotalEnciclopedias(int cantidadTotalEnciclopedias);

    int getCantidadTotalNovelas() const;

    void setCantidadTotalNovelas(int cantidadTotalNovelas);

    void cargar_libros();

    void cargar_estantes();

    void posicionar_libros();

    void mostrar_datos();

    void imprime_linea(ofstream &, int, char);
//
private:
    EstanteVertical estantesVerticales[10];
    int cantidad_estantes_verticales;
    EstanteHorizontal estantesHorizontales[10];
    int cantidad_estantes_horizontales;
    Enciclopedia enciclopedias[10];
    int cantidad_total_enciclopedias;
    Novela novelas[10];
    int cantidad_total_novelas;
};


#endif //ESTANTES_BIBLIOTECA_HPP

//
// Created by USUARIO on 3/06/2026.
//

#ifndef LAB07_BIBLIOTECA_HERENCIA_BIBLIOTECA_HPP
#define LAB07_BIBLIOTECA_HERENCIA_BIBLIOTECA_HPP

#include "EstanteHorizontal.hpp"
#include "EstanteVertical.hpp"

class Biblioteca{
private:
    EstanteVertical estantesVerticales[MAX_VERTICALES];
    int cantidad_estantes_verticales;
    EstanteHorizontal estantesHorizontales[MAX_HORIZONTALES];
    int cantidad_estantes_horizontales;

    Enciclopedia enciclopedias[MAX_ENCICLOPEDIAS];
    int cantidad_total_enciclopedias;
    Novela novelas[MAX_NOVELAS];
    int cantidad_total_novelas;

public:
    Biblioteca();

    int get_cantidad_estantes_verticales() const;
    void set_cantidad_estantes_verticales(int cantidad_estantes_verticales);
    int get_cantidad_estantes_horizontales() const;
    void set_cantidad_estantes_horizontales(int cantidad_estantes_horizontales);
    int get_cantidad_total_enciclopedias() const;
    void set_cantidad_total_enciclopedias(int cantidad_total_enciclopedias);
    int get_cantidad_total_novelas() const;
    void set_cantidad_total_novelas(int cantidad_total_novelas);

    void agregar_novela(ifstream& in);
    void agregar_enciclopedia(ifstream& in);

    void cargar_libros(const char *arch);


    void agregar_estante_horizontal(ifstream& in);
    void agregar_estante_vertical(ifstream& in);
    void cargar_estantes(const char *arch);

    void posicionar_libros_estantes_horizontales();

    void posicionar_libros_estantes_verticales();
    void posicionar_libros();

    void inicializar();
    void imprimir_titulo_informe(ofstream& out) const;
    void mostrar_datos() const;
};


#endif //LAB07_BIBLIOTECA_HERENCIA_BIBLIOTECA_HPP

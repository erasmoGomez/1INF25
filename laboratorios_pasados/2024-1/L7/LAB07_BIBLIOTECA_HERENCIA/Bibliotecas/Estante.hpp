//
// Created by USUARIO on 3/06/2026.
//

#ifndef LAB07_BIBLIOTECA_HERENCIA_ESTANTE_HPP
#define LAB07_BIBLIOTECA_HERENCIA_ESTANTE_HPP

#include "Espacio.hpp"

class Estante{

private:
    char *codigo;
    int anchura;
    int altura;
    Espacio *espacios;
    double pesoSoportado;
    double pesoActual;
public:
    Estante();
    Estante(const class Estante& estante);

    char* get_codigo() const;
    void set_codigo(char* codigo);
    int get_anchura() const;
    void set_anchura(int anchura);
    int get_altura() const;
    void set_altura(int altura);

    double get_peso_soportado() const;
    void set_peso_soportado(double peso_soportado);
    double get_peso_actual() const;
    void set_peso_actual(double peso_actual);

    void inicializar();
    Estante& operator= (const Estante& espacio);

    void leer(ifstream &in);
    bool esta_vacio() const;
    void reservar_memoria_espacios();
    void pintar_horizontal(int i, int j, int alto_utilizado, char caracter);
    void pintar_vertical(int i, int j, int ancho_utilizado, char caracter);

    void imprimir_grafico_fisico(ofstream& out) const;

    char conseguir_contenido(int idx) const;

    virtual ~Estante();
};


#endif //LAB07_BIBLIOTECA_HERENCIA_ESTANTE_HPP
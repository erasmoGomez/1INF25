//
// Created by USUARIO on 3/06/2026.
//

#ifndef LAB07_BIBLIOTECA_HERENCIA_LIBRO_HPP
#define LAB07_BIBLIOTECA_HERENCIA_LIBRO_HPP

#include "Utils.hpp"

class Libro{


private:
    char *codigo;
    char *nombre;
    int ancho;
    int alto;
    double peso;
    bool colocado;

public:

    Libro();
    Libro(const class Libro& libro);

    //GETTERS AND SETTERS
    char* get_codigo() const;
    void set_codigo(const char* codigo);
    char* get_nombre() const;
    void set_nombre(const char* nombre);
    int get_ancho() const;
    void set_ancho(int ancho);
    int get_alto() const;
    void set_alto(int alto);
    double get_peso() const;
    void set_peso(double peso);
    bool is_colocado() const;
    void set_colocado(bool colocado);

    void inicializar();
    Libro& operator=(const class Libro& libro);

    void leer(ifstream &in);

    //DESTRUCTOR
    virtual ~Libro();
};



#endif //LAB07_BIBLIOTECA_HERENCIA_LIBRO_HPP
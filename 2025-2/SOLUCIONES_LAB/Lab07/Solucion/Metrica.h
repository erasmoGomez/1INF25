//
// Created by Daniel Sanchez on 7/11/25.
//

#ifndef SOLUCION_METRICA_H
#define SOLUCION_METRICA_H

#include <fstream>

class Metrica {
private:
    int id;
    char *descripcion;
    int fecha_calculo;
    int fecha_expiracion;
    bool estado;

public:
    Metrica();

    ~Metrica();

    Metrica &operator=(const Metrica &m);

    int get_id() const;

    void set_id(int n);

    void get_descripcion(char *buffer) const;

    void set_descripcion(const char *buffer);

    int get_fecha_calculo() const;

    void set_fecha_calculo(int n);

    int get_fecha_expiracion() const;

    void set_fecha_expiracion(int n);

    bool get_estado() const;

    void set_estado(bool e);

    void leer(std::ifstream &arch);

    std::ostream &imprimir(std::ostream &arch) const;
};


#endif //SOLUCION_METRICA_H

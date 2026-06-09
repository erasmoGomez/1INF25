//
// Created by USUARIO on 3/06/2026.
//

#ifndef LAB07_BIBLIOTECA_HERENCIA_NOVELA_HPP
#define LAB07_BIBLIOTECA_HERENCIA_NOVELA_HPP

#include "Libro.hpp"

class Novela : public Libro {

private:
    char *tipo;
    double rating;
public:
    Novela();
    Novela(const class Novela& novela);

    char* get_tipo() const;
    void set_tipo(const char* tipo);
    double get_rating() const;
    void set_rating(double rating);

    void inicializar();

    Novela& operator=(const class Novela& novela);

    void leer(ifstream &in);
    void imprimir_data_novela(ofstream& out) const;
    virtual ~Novela();
};




#endif //LAB07_BIBLIOTECA_HERENCIA_NOVELA_HPP

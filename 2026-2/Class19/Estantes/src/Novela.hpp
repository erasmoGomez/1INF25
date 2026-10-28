//
// Created by Erasmo on 22/10/25.
//

#ifndef ESTANTES_NOVELA_HPP
#define ESTANTES_NOVELA_HPP

#include "Libro.hpp"
class Novela : public Libro {
private:
    // Se define los atributos NO COMUNES
    string tipo;
    double rating;

public:
    string get_tipo() const;

    void set_tipo(const string &tipo);

    double getRating() const;

    void setRating(double rating);

    Novela();

    Novela(const Novela &orig);

    virtual ~Novela();

    void operator=(const Novela &orig);

    void leer(ifstream&);

};


#endif //ESTANTES_NOVELA_HPP

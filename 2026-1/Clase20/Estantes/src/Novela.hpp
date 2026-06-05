//
// Created by Erasmo on 22/10/25.
//

#ifndef ESTANTES_NOVELA_HPP
#define ESTANTES_NOVELA_HPP

#include "Libro.hpp"
class Novela : public Libro {
private:
    char* tipo;
    double rating;
public:
    double getRating() const;

    void setRating(double rating);

    void GetTipo(char* tipo) const;

    void SetTipo(const char* tipo);

public:
    Novela();

    Novela(const Novela &orig);

    virtual ~Novela();

    void operator=(const Novela &orig);

    void leer(ifstream&);

};


#endif //ESTANTES_NOVELA_HPP

//
// Created by Erasmo on 22/10/25.
//

#ifndef ESTANTES_NOVELA_HPP
#define ESTANTES_NOVELA_HPP

#include "Libro.hpp"
class Novela : public Libro {
private:
    char* tipo{};
public:
    double getPeso() const;

    void setPeso(double peso);

    void GetTipo(char* tipo) const;

    void SetTipo(const char* tipo);

    void leer(ifstream & input);

private:
    double peso{};
public:
    Novela();

    Novela(const Novela &orig);

    virtual ~Novela();

    void mostrar(ofstream &output) const;

    void operator=(const Novela &orig);
};
void operator<<(ofstream& output,  const Novela &);

#endif //ESTANTES_NOVELA_HPP

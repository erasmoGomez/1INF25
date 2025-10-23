//
// Created by Erasmo on 22/10/25.
//

#ifndef ESTANTES_ENCICLOPEDIA_HPP
#define ESTANTES_ENCICLOPEDIA_HPP

#include "Libro.hpp"
class Enciclopedia : public Libro {
private:
    int volumen;
public:
    int getVolumen() const;

    void setVolumen(int volumen);

    double getPeso() const;

    void setPeso(double peso);

private:
    double peso;
public:
    Enciclopedia();

    Enciclopedia(const Enciclopedia &orig);
};


#endif //ESTANTES_ENCICLOPEDIA_HPP

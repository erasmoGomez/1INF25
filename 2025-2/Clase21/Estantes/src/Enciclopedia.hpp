//
// Created by Erasmo on 22/10/25.
//

#ifndef ESTANTES_ENCICLOPEDIA_HPP
#define ESTANTES_ENCICLOPEDIA_HPP

#include "Libro.hpp"

class Enciclopedia : public Libro {
private:
    int volumen{};
    double peso{};
public:
    int getVolumen() const;

    void setVolumen(int volumen);

    double getPeso() const;

    void setPeso(double peso);

    void leer(ifstream&);

    void mostrar(ofstream &output) const;


public:
    Enciclopedia();

    Enciclopedia(const Enciclopedia &orig);

    void operator =(const Enciclopedia &orig);
};

void operator>>(ifstream &input, Enciclopedia &e);
void operator<<(ofstream& output, const Enciclopedia &e);

#endif //ESTANTES_ENCICLOPEDIA_HPP

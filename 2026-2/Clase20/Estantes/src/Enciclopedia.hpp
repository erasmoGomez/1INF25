//
// Created by Erasmo on 22/10/25.
//

#ifndef ESTANTES_ENCICLOPEDIA_HPP
#define ESTANTES_ENCICLOPEDIA_HPP

#include "Libro.hpp"
class Enciclopedia : public Libro {
private:
    // Se definen los atributos NO COMUNES
    int volumen;
    double peso;
public:
    int getVolumen() const;

    void setVolumen(int volumen);

    double getPeso() const;

    void setPeso(double peso);

    Enciclopedia();

    Enciclopedia(const Enciclopedia &orig);

    void leer(ifstream&); // ESTE METODO sobre escribe EL METODO LEER DEL PADRE
};


#endif //ESTANTES_ENCICLOPEDIA_HPP

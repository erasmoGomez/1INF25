//
// Created by USUARIO on 3/06/2026.
//

#ifndef LAB07_BIBLIOTECA_HERENCIA_ENCICLOPEDIA_HPP
#define LAB07_BIBLIOTECA_HERENCIA_ENCICLOPEDIA_HPP

#include "Libro.hpp"

class Enciclopedia : public Libro {

private:
    int volumen;
    double peso;

public:
    Enciclopedia();
    Enciclopedia(const class Enciclopedia &enc);
    //GETTERS AND SETTERS
    int get_volumen() const;
    void set_volumen(int volumen);
    double get_peso() const;
    void set_peso(double peso);

    void inicializar();
    Enciclopedia& operator=(const Enciclopedia& enc);

    void leer(ifstream &in);
    void imprimir_data_enciclopedia(ofstream& out) const;
};


#endif //LAB07_BIBLIOTECA_HERENCIA_ENCICLOPEDIA_HPP

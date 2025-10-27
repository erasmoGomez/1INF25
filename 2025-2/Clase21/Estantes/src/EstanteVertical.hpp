//
// Created by Erasmo on 26/10/25.
//

#ifndef ESTANTES_ESTANTEVERTICAL_HPP
#define ESTANTES_ESTANTEVERTICAL_HPP

#include "Enciclopedia.hpp"
#include "Estante.hpp"

class EstanteVertical : public Estante {

private:
    Enciclopedia enciclopedias[10];
    int cantidad_enciclopedias;
public:
    EstanteVertical();

    virtual ~EstanteVertical();

    EstanteVertical(const EstanteVertical &);

    void leer(ifstream &input);

    int get_espacios_restantes();

    bool operator+=(const Enciclopedia &e);

    void colocar_libro(int ancho_utilizado,  const Enciclopedia& e);

    void mostrar(ofstream &output) const;

    void setEstadoColocado(int , bool);

    void pinta_estante(ofstream &) const;
};

void operator<<(ofstream &output, const EstanteVertical &e);

#endif //ESTANTES_ESTANTEVERTICAL_HPP

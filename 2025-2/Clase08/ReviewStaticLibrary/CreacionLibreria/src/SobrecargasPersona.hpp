//
// Created by Erasmo on 3/09/25.
//

#ifndef FUENTES_SOBRECARGASPERSONA_HPP
#define FUENTES_SOBRECARGASPERSONA_HPP

#include "Utils.hpp"
#include "Persona.hpp"

ostream &operator<<(ostream &out, const struct Persona &p);

ofstream &operator<<(ofstream &out, const struct Persona &p);

ifstream &operator>>(ifstream &in, struct Persona &p);

#endif //FUENTES_SOBRECARGASPERSONA_HPP

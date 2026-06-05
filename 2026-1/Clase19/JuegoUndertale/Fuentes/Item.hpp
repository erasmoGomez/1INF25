//
// Created by erasmo on 5/27/26.
//

#ifndef JUEGOUNDERTALE_ITEM_HPP
#define JUEGOUNDERTALE_ITEM_HPP

#include "Utils2.hpp"
class Item {
private:
    char* nombre;
    char* descripcion;
    bool equipado;

public:
    bool is_equipado() const;

    void set_equipado(bool equipado);

    Item();
    //Item(char* nombre, char* descripcion);
    //Item(const Item& item);
    //virtual ~Item();
    void set_nombre(const char* nombre);
    void get_nombre(char* nombre) const;
    void set_descripcion(const char* descripcion);
    //void get_descripcion(char* descripcion) const;
    void leer(ifstream&);
};


#endif //JUEGOUNDERTALE_ITEM_HPP
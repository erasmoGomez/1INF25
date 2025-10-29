//
// Created by Erasmo on 9/10/25.
//

#ifndef JUEGO_ITEM_HPP
#define JUEGO_ITEM_HPP
#include "Utils.hpp"

class Item {
private:
    int codigo;
    char *nombre;
    char *descripcion;
    bool equipado;

public:
    Item();

    Item(int codigo, char *nombre, char *descripcion, int valorIncrementar);

    int getCodigo() const;

    void setCodigo(int codigo);

    void getNombre(char* nombre) const;

    void setNombre(const char *nombre);

    void getDescripcion(char * descripcion) const;

    void setDescripcion(const char *descripcion);

    bool getEquipado() const;

    void setEquipado(bool equipado);

//    int getValorIncrementar() const;
//
//    void setValorIncrementar(int valorIncrementar);

    virtual void leer(ifstream& input); //Método Polimorfico

    virtual void mostrar(ostream&) const; //Método Polimorfico

    virtual int get_valor() = 0; // Funcion Pura

};


#endif //JUEGO_ITEM_HPP

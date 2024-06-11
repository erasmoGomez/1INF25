//
// Created by Erasmo on 3/06/24.
//

#ifndef JUEGO_ITEM_HPP
#define JUEGO_ITEM_HPP


#include "Utils.hpp"
using namespace std;
class Item {
public:

    Item();
    Item(const Item& orig);
    virtual ~Item();
    void SetEquipadoQ(bool equipadoQ);
    bool GetEquipadoQ() const;
    void SetDescripcion(const char* );
    void GetDescripcion(char *) const;
    void SetNombre(const char* );
    void GetNombre(char *) const; //METODO GETTER
    virtual void leer(ifstream&); //metodo polimorfico
    virtual int get_modificador()=0; //METODO PURO NO DEBE TENER IMPLEMENTACION EN LA CLASE PADRE
    void mostrar(ofstream &);
    virtual void mostrar(); // Metodo polimorfico
private:
    char* nombre;
    char* descripcion;
    bool equipadoQ;
};



#endif //JUEGO_ITEM_HPP
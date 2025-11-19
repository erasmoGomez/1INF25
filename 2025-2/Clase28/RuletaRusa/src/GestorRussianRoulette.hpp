//
// Created by Erasmo on 19/11/25.
//

#ifndef RULETARUSA_GESTORRUSSIANROULETTE_HPP
#define RULETARUSA_GESTORRUSSIANROULETTE_HPP

#include "../src/BibliotecaListaCircularDoble/ListaCircularDoble.hpp"
class GestorRussianRoulette {
private:
    ListaCircularDoble ruleta;
public:
    void cargar_jugadores(const char* file_name);
    void imrprimir_jugadores(const char* file_name);
    void jugar();
};


#endif //RULETARUSA_GESTORRUSSIANROULETTE_HPP

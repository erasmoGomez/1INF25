//
// Created by Erasmo on 24/09/25.
//

#ifndef JUEGO_HEROE_HPP
#define JUEGO_HEROE_HPP

#include "Utils.hpp"
#include "Mapa.hpp"
#include "Mochila.hpp"
class Heroe {
private:
    char *id; //Excepcion para los getters y setters
    char *nombre; // Excepcion para los getters y setters
    int hp;
    double fuerza;
    double defensa;
    int posx;
    int posy;
    Mochila mochila;
public:
    //Constructores
    //Constructor por defecto. class Heroe h; Otros lo llaman, constructor sin parametros
    Heroe();

    //Constructor con parametros. class Heroe h2("Ash", 100, 50, 50, 10, 10);
    Heroe(const char *, int, double, double, int, int);

    Heroe(const char *);

    void getId(char *id) const;

    void setId(const char *id);

    void getNombre(char *nombre) const;

    void setNombre(const char *nombre);

    int getHp() const;

    void setHp(int hp);

    double getFuerza() const;

    void setFuerza(double fuerza);

    double getDefensa() const;

    void setDefensa(double defensa);

    int getPosx() const;

    void setPosx(int posx);

    int getPosy() const;

    void setPosy(int posy);

    void set_valores_iniciales();

    void cargar_datos(ifstream &input);

    void dibujar_barra(int valor, int max_valor, const char *etiqueta, ostream &output) const;

    void mostrar_heroe(ostream &output) const;

    bool mover(char mov, class Mapa &mapa);

    void leer_item(ifstream& input);

    //Sobrecargas
    void operator++();       //W ++heroe
    void operator++(int);   //S heroe++
    void operator--();     //D --heroe
    void operator--(int); //A heroe--
};

void operator<<(ofstream &, const class Heroe &);

void operator>>(ifstream &, class Heroe& h);
#endif //JUEGO_HEROE_HPP

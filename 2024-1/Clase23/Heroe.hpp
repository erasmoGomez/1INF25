//
// Created by Erasmo on 8/05/24.
//

#ifndef JUEGO_HEROE_HPP
#define JUEGO_HEROE_HPP

#include "Utils.hpp"
#include "Mochila.hpp"
using namespace std;
class Heroe{
private:
    char* nombre;
    int hp;
    double mana;
    int posx;
    int posy;
    int vida;
    int ataque;
    int defensa;
    Mochila mochila;
public:
    Heroe(const Heroe&);
    void getNombre(char *) const;

    void setNombre(const char *nombre);

    int getHp() const;

    void setHp(int hp);

    double getMana() const;

    void setMana(double mana);

    int getPosx() const;

    void setPosx(int posx);

    int getPosy() const;

    void setPosy(int posy);

    void setDefensa(int defensa);

    int getDefensa() const;

    void setAtaque(int ataque);

    int getAtaque() const;

    void setVida(int vida);

    int getVida() const;

    Heroe();

    void leer(ifstream &);

    void mostrar(ofstream &);
    void mostrar(ostream &);

    void move(int, char);

    void equipar(const char*, const char*);

    void agregar_mochila(ifstream &, char*);

    void mostrar_items();

    void equipar(const char*, int);

    void operator++(void);

    void operator++(int);

    void operator--(void);

    void operator--(int);

    bool operator >(const Heroe &);

    void operator = (const class Heroe&);
};

void operator >> (ifstream&, Heroe&);

void operator << (ostream&, Heroe&);
#endif //JUEGO_HEROE_HPP

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hero.hpp
 * Author: ASUS
 *
 * Created on April 30, 2024, 9:08 PM
 */

#ifndef HERO_HPP
#define HERO_HPP
class Heroe{
private:
    char *nombre;
    int hp;
    double mana;
    int posx;
    int posy;
public:
    Heroe(); //Constructor por defecto
    Heroe(const char*, int); //Constructor con parametros
    Heroe(const Heroe&); // Constructor Copia
    virtual ~Heroe(); //Destructor
    void crear();
    void mover(int, int, double);
    void curar(int);
    void mostrar();
    void setPosy(int posy);
    int getPosy() const;
    void setPosx(int posx);
    int getPosx() const;
    void setMana(double mana);
    double getMana() const;
    void setHp(int hp);
    int getHp() const;
    void setNombre(const char*);
    void getNombre(char*) const;
};
#endif /* HERO_HPP */


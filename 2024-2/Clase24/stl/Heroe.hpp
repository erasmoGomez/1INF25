/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Heroe.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on June 17, 2024, 5:00 PM
 */

#ifndef HEROE_HPP
#define HEROE_HPP
#include "utils.hpp"
using namespace std;
class Heroe {
public:
    Heroe();
    Heroe(const Heroe& orig);
    virtual ~Heroe();
    void SetAtaque(double );
    double GetAtaque() const;
    void SetNombre(const char* );
    void GetNombre(char *) const;
    void SetCodigo(int );
    int GetCodigo() const;
    void leer(ifstream &input);
    void leer2(ifstream &input);
    void mostrar() const;
    void operator = (const class Heroe&);
    bool operator <(const Heroe &h);
    void SetNombre2(string nombre2);
    string GetNombre2() const;
private:
    int codigo;
    char *nombre;
    double ataque;
    string nombre2;
};

void operator >> (ifstream& , Heroe&);
void operator<<(ostream&, const Heroe&);
#endif /* HEROE_HPP */


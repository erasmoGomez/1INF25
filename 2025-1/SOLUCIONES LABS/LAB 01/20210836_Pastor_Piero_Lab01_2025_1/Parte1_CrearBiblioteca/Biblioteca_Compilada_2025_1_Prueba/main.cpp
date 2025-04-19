/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: piero
 *
 * Created on 14 de abril de 2025, 11:20 PM
 */

#include <cstdlib>
#include "CadenaDeCaracteres.h"
#include "Sobrecargas.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ofstream arch("reporte.txt", ios::out);
    CadenaDeCaracteres hola, que, tal;
    !hola; !que; !tal;
    hola <= "zzz";
    que <= "gg";
    tal <= que;
    bool a = 0;
    cout << a << " " << tal.cadena << (tal < hola) << endl;
    cout << hola.cadena << hola.capacidad << " " << que.cadena << que.capacidad << que.longitud << endl;
    arch << que << hola << endl;
    (hola && que);
    arch << que << hola << endl;
    bool flag=(hola += que);
    arch << hola << endl;
    (hola && hola);
    arch << hola << endl;
    (hola += hola);
    arch << hola << endl;
    hola <= hola;
    arch << hola << endl;
    return 0; 
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "tablero.hpp"
#include "fa.hpp"
#include "fb.hpp"
#include "fc.hpp"

Tablero::Tablero(){
    numFichas = 0;
}

Tablero::~Tablero(){
    for(int i  = 0 ; i<numFichas; i++)
        delete ficha[i];
}

void Tablero::SetNumFichas(int numFichas) {
    this->numFichas = numFichas;
}

int Tablero::GetNumFichas() const {
    return numFichas;
}

void Tablero::leer_fichas(ifstream& arch_input){
    char id[10], tipo;
    int fil, col;
    while(1){
        arch_input>>id;
        if(arch_input.eof()) break;
        arch_input>> tipo >> fil >> col;
        set_ficha(id, tipo, fil, col);
    }
}

void Tablero::set_ficha(char * id, char tipo, int fil, int col){
    switch(tipo){
        case 'A':
            ficha[numFichas] = new Fa;
            break;
        case 'B':
            ficha[numFichas] = new Fb;
            break;
        case 'C':
            ficha[numFichas] = new Fc;
            break;
    }
    ficha[numFichas]->asigna(id, fil, col);
    numFichas++;
}

void Tablero::leer_movimiento(ifstream &arch){
    char id[10], dir;
    int cant;
    while(1){
        arch>>id;
        if(arch.eof())break;
        arch>>dir>>cant;
        mover_ficha(id, dir, cant);
    }
}

void Tablero::mover_ficha(char* id, char dir, int cant){
    char idTablero[10];
    for(int fil =0; fil<numFichas; fil++){
        ficha[fil]->GetId(idTablero);
        if(strcmp(idTablero, id) == 0)
            ficha[fil]->mover(dir, cant);
            return;
    }
}

void Tablero::imprime_datos(ofstream &arch){
    for(int fil = 0; fil<numFichas;fil++){
        ficha[fil]->imprime(arch);
    }
}
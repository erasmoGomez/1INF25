/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iomanip>
#include <fstream>
using namespace std;
#include "fa.hpp"

void Fa::imprime(ofstream &arch){
    char ident[10];
    GetId(ident);
    arch<<"TIPOA: "<<left<<setw(5)<<ident
                    <<right<<setw(5)<<GetFil()
                    <<setw(5)<<GetCol()<<endl;
}

void Fa::mover(char dir, int cant){
    switch(dir){
        case 'P':
            SetFil(GetFil()-cant);
            break;
        case 'Q':
            SetCol(GetCol()+cant);
            break;
        case 'R':
            SetFil(GetFil()+cant);
            break;
        case 'S':
            SetCol(GetCol()-cant);
            break;
    }
}
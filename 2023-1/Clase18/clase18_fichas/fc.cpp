/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iomanip>
#include <fstream>
using namespace std;
#include "fc.hpp"

void Fc::imprime(ofstream &arch){
    char ident[10];
    GetId(ident);
    arch<<"TIPOC: "<<left<<setw(5)<<ident
                    <<right<<setw(5)<<GetFil()
                    <<setw(5)<<GetCol()<<endl;
}

void Fc::mover(char dir, int cant){
    switch(dir){
        case 'P':
            SetFil(GetFil()-2);
            SetCol(GetCol()+1);
            break;
        case 'Q':
            SetFil(GetFil()+1);
            SetCol(GetCol()+2);
            break;
        case 'R':
            SetFil(GetFil()+2);
            SetCol(GetCol()-1);
            break;
        case 'S':
            SetFil(GetFil()-1);
            SetCol(GetCol()-2);
            break;
    }
}
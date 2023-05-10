/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on May 4, 2023, 11:59 PM
 */

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream input("alumnos.csv", ios::in);
    char coma, buffer[50];
    int code, percentage, escala;
    char modalidad;
    while(1){
        percentage = 0;
        modalidad = ' ';
        input>>code;
        if(input.eof())break;
        input.get();
        input.getline(buffer,50,',');
        input>>escala;
        if(input.fail()){
            input.clear();
            input>>modalidad;
            input.get();
            if (modalidad == 'S'){
                input>>percentage>>coma;
            }
            input>>escala;
        }
        else{
            modalidad = 'P';
            percentage = 100;
        }

        cout<<code<<endl;
        cout<<buffer<<endl;
        cout<<modalidad<<endl;
        cout<<percentage<<endl;
        cout<<escala<<endl;
    }
    return 0;
}


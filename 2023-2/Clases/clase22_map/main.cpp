/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on November 7, 2023, 7:40 AM
 */

#include "utils.hpp"
#include "Hero.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
//    map<string, double> map_doubles;
//    map_doubles["erasmo"] = 33.5;
//    map_doubles["coco"] = 22.5;
//    map_doubles["max"] = 11.5;
//    map_doubles["piero"] = 66.5;
//    map_doubles["delegado"] = 12.4;
//    
//    for(map<string,double>::iterator it=map_doubles.begin(); it!=map_doubles.end(); it++){
//        cout<<setw(4)<<it->first<<"  -- "<<setw(10)<<it->second<<endl;
//    }
//    map<int,double>::iterator it =map_doubles.begin();
//    for(it ; it!=map_doubles.end(); it++){
//        
//    }
    map<string, Hero>map_hero;
    class Hero h;
    char buffer[30];
    ifstream input("heroes.csv", ios::in);
    while(1){
        input>>h;
        if(input.eof()) break;
        h.GetName(buffer);
        map_hero[buffer] = h;
    }
    
    for(map<string,Hero>::iterator it=map_hero.begin();it!=map_hero.end();it++){
        cout<<"Name: "<<it->first<<"   ";
        cout<<(it->second).GetAtt()<<endl;
    }
    
    map<string,Hero>::iterator itt1;
    itt1 = map_hero.find("Sora");
    if(itt1!=map_hero.end()){
        cout<<"Encontrado: "<<itt1->first<<"   ";
        cout<<itt1->second;
    }
    else
        cout<<"No se encontro"<<endl;
    return 0;
}


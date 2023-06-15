/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "functions.hpp"
#include "pokeball.hpp"

Pokeball::Pokeball(){
    //cout<<"Constructor de Pokeball"<<endl;
    catch_ratio = 100;  
}

Pokeball::Pokeball(int id, const char* name, const char* desc, double catch_ratio) : Item(id, name, desc){
    //cout<<"Constructor de POkeball con parametros"<<endl;
    this->catch_ratio = catch_ratio;
}

void Pokeball::SetCatch_ratio(double catch_ratio) {
    this->catch_ratio = catch_ratio;
}

double Pokeball::GetCatch_ratio() const {
    return catch_ratio;
}

void Pokeball::load_pokeball(int id, const char* name, const char* desc, double catch_ratio){
    SetID(id);
    SetName(name);
    SetDescription(desc);
      
    SetCatch_ratio(catch_ratio);
    //this->catch_ratio = catch_ratio;
    //catch_ratio = catch_ratio;
}

void Pokeball::print_pokeball(){
    cout<< "************"<<endl;
    char buffer[200];
    cout<<GetID()<<endl;
    GetName(buffer);
    cout<<buffer<<endl;
    GetDescription(buffer);
    cout<<buffer<<endl;
    
    cout<<GetCatch_ratio()<<endl;
    cout<< "************"<<endl;
}
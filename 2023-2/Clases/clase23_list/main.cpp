/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on November 8, 2023, 7:04 AM
 */
#include "utils.hpp"
#include "Hero.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    list<class Hero>list_hero;
    ifstream input("heroes.csv", ios::in);
    ofstream output("heroes.txt", ios::out);
    ofstream output2("sorted_heroes.txt", ios::out);
    class Hero new_hero;
    while(true){
        input>>new_hero;
        if(input.eof())break;
        list_hero.push_back(new_hero);
    }
    for(Hero h: list_hero)
        output<<h;
    
    list_hero.sort();
    for(Hero h: list_hero)
        output2<<h;
    
    return 0;
}


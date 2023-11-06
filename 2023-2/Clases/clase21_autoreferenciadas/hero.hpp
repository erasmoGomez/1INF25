/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hero.hpp
 * Author: ASUS
 *
 * Created on October 31, 2023, 8:43 AM
 */

#ifndef HERO_HPP
#define HERO_HPP
#include "utils.hpp"
using namespace std;

class hero {
public:
    hero();
    hero(const hero& orig);
    virtual ~hero();
    void SetAtt(double att);
    double GetAtt() const;
    void SetName(const char* name);
    void GetName(char *) const;
    void SetCode(int code);
    int GetCode() const;
    void operator = (const class hero&);
    bool operator > (const class hero&);
private:
    int code;
    char *name;
    double att;
};

ifstream & operator>>(ifstream &input, class hero & h);
ofstream & operator<<(ofstream &output, class hero & h);
#endif /* HERO_HPP */


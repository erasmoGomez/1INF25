/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sobrecargas.hpp
 * Author: hecto
 *
 * Created on March 26, 2025, 5:21 PM
 */

#ifndef SOBRECARGAS_HPP
#define SOBRECARGAS_HPP
#include "utils.hpp"
#include "estructuras.hpp"

ostream& operator << (ostream&, const struct Papeleta&);
ifstream& operator >> (ifstream&, struct Papeleta&);
#endif /* SOBRECARGAS_HPP */


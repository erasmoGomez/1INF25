//
// Created by erasmo on 6/23/26.
//
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "Comentario.hpp"

string Comentario::get_canal() const {
    return canal;
}

void Comentario::set_canal(const string &canal) {
    this->canal = canal;
}

string Comentario::get_comentario() const {
    return comentario;
}

void Comentario::set_comentario(const string &comentario) {
    this->comentario = comentario;
}

void Comentario::leer(ifstream &arch) {
    getline(arch, canal, ',');
    if (arch.eof()) return;
    getline(arch, comentario);
}

void Comentario::imprimir(ofstream &arch) const {
    arch << left << setw(20) << canal << comentario << endl;
}

void operator>>(ifstream &arch, class Comentario &com) {
    com.leer(arch);
}

void operator<<(ofstream &arch, const class Comentario &com) {
    com.imprimir(arch);
}

bool Comentario::operator<(const Comentario &com) const {
    return canal < com.canal;
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Fuentes_Biblioteca_2024_1.hpp"
#include "Estructuras.hpp"

bool operator>>(ifstream &input_libro, struct Libro & libro) {
    //IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23
    char extra;
    input_libro.getline(libro.codigo, 8, ',');
    if (input_libro.eof())return false;
    input_libro.getline(libro.tiltulo, 80, ',');
    input_libro.getline(libro.autor, 60, ',');

    input_libro >> libro.stock;
    input_libro.get();
    input_libro >> libro.precio;
    input_libro.get();
    return true;
}

bool operator>>(ifstream &arch, struct Cliente &cli) {
    //54393647,Reyes Tang Edward 
    arch >> cli.dni;
    if (arch.eof()) return false;
    arch.get(); // leer la coma
    arch.getline(cli.nombre, 60, '\n');
    cli.cantDeLibros = 0;
    cli.pagoTotal = 0;
    return true;
}

bool operator>>(struct LibroSolicitado &lib, struct Libro *arrLib) {
    for (int i = 0; strcmp(arrLib[i].codigo, "FIN") != 0; i++) {
        if (strcmp(lib.codigoDelLibro, arrLib[i].codigo) == 0) {
            if (arrLib[i].stock > 0) {
                arrLib[i].stock--;
                lib.precio = arrLib[i].precio;
                lib.atendido = true;
                return true;
            } else {
                lib.atendido = false;
                return false;
            }
        }
    }
    return false;
}

bool operator<<(struct Cliente &cli, struct LibroSolicitado lib) {
    if (cli.cantDeLibros < 30) {
        cli.librosSolicitados[cli.cantDeLibros] = lib;
        cli.cantDeLibros++;
        return true;
    } else return false;
}

void operator++(struct Cliente &cli) {
    for (int i = 0; i < cli.cantDeLibros; i++)
        cli.pagoTotal += cli.librosSolicitados[i].precio;
}

void operator<<(ofstream &arch, struct Libro lib) {
    arch << left << setw(14) << lib.codigo;
    arch << setw(40) << lib.tiltulo;
    arch << setw(20) << lib.autor;
    arch << right << lib.stock;
    arch << setprecision(2) << setw(10) << lib.precio << endl;
}

void operator<<(ofstream &arch, struct Cliente cli) {
    arch << cli.dni << setw(4) << ' ' << cli.nombre << endl;
    arch << "Libros entregados:" << endl;
    arch << setw(10) << ' ' << left << setw(15) << "Pedido No." << setw(12) << "Codigo" << "Precio" << right << endl;
    for (int i = 0; i < cli.cantDeLibros; i++) {
        if (cli.librosSolicitados[i].atendido) {
            arch << setw(14) <<setfill('0')<< cli.librosSolicitados[i].numeroDePedido << setfill(' ')<<setw(10) << ' ' <<
                    left << setw(10) << cli.librosSolicitados[i].codigoDelLibro << right <<
                    setw(10) << setprecision(2) << cli.librosSolicitados[i].precio << endl;
        }
    }
    arch << "Total a pagar: " << setprecision(2) << cli.pagoTotal << endl;
    arch << "Libros no entregados por falta de stock:" << endl;
    arch << setw(10) << ' ' << left << setw(15) << "Pedido No." << setw(12) << "Codigo" << right << endl;
    for (int i = 0; i < cli.cantDeLibros; i++) {
        if (!cli.librosSolicitados[i].atendido) {
            arch << setw(14) << cli.librosSolicitados[i].numeroDePedido << setw(10) << ' ' <<
                    left << setw(10) << cli.librosSolicitados[i].codigoDelLibro << right << endl;
        }
    }
}
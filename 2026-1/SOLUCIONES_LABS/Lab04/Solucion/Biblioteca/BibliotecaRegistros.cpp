//
// Created by Daniel Sanchez on 8/05/26.
//

#include "BibliotecaRegistros.h"

#include <fstream>

int leefecha(std::ifstream &file) {
    char c;
    int year, month, day;
    file >> day >> c >> month >> c >> year >> c;
    return 10000 * year + 100 * month + day;
}

char *leestr(std::ifstream &file, char d) {
    constexpr int MAX_BUFFER = 64;
    char buffer[MAX_BUFFER]{};
    file.getline(buffer, MAX_BUFFER, d);
    char *str = new char[strlen(buffer) + 1];
    strcpy(str, buffer);
    return str;
}

int leehora(std::ifstream &file) {
    char c;
    int hour, min;
    file >> hour >> c >> min >> c;
    return 60 * hour + min;
}

void *leeregistro(std::ifstream &file) {
    char c;
    int cod;
    file >> cod;
    if (file.eof()) return nullptr;
    file >> c;
    int fecha = leefecha(file);
    char *motivo = leestr(file, ',');
    int hora = leehora(file);
    char *estado = leestr(file, ',');
    char *nombre = leestr(file, ',');
    char *raza = leestr(file, ',');
    char *color = leestr(file, ',');
    char *especie = leestr(file, '\n');

    void **registro = new void *[REGISTRO_COUNT]{};
    registro[CODIGO] = new int(cod);
    registro[FECHA] = new int(fecha);
    registro[MOTIVO] = motivo;
    registro[HORA] = new int(hora);
    registro[ESTADO] = estado;
    registro[NOMBRE] = nombre;
    registro[RAZA] = raza;
    registro[COLOR] = color;
    registro[ESPECIE] = especie;
    return registro;
}

int fecha_hora(int fecha, int hora) {
    return fecha * 10000 + hora;
}

int comparareg(const void *a, const void *b) {
    void **a_ptr = (void **) a;
    void **b_ptr = (void **) b;
    return verificareg(*a_ptr, *b_ptr);
}

int verificareg(const void *a, const void *b) {
    void **a_reg = (void **) a;
    void **b_reg = (void **) b;
    int a_fecha_hora = fecha_hora(*(int *) a_reg[FECHA], *(int *) a_reg[HORA]);
    int b_fecha_hora = fecha_hora(*(int *) b_reg[FECHA], *(int *) b_reg[HORA]);
    return a_fecha_hora - b_fecha_hora;
}

void imprime_fecha(std::ostream &file, int fecha) {
    int year = fecha / 10000;
    int month = (fecha % 10000) / 100;
    int day = fecha % 100;
    file << std::right << std::setfill('0') << year << "/";
    file << std::setw(2) << month << "/";
    file << std::setw(2) << day << std::setfill(' ');
    file << "  ";
}

void imprime_hora(std::ostream &file, int hora) {
    int hour = hora / 60;
    int minute = hora % 60;
    file << std::right << std::setfill('0') << std::setw(2) << hour << ":";
    file << std::setw(2) << minute << std::setfill(' ');
    file << "   ";
}

void imprimeregistro(std::ostream &file, void *data) {
    void **registro = (void **) data;
    imprime_fecha(file, *(int *) registro[FECHA]);
    imprime_hora(file, *(int *) registro[HORA]);
    file << std::left << std::setw(6) << *(int *) registro[CODIGO];
    file << std::left << std::setw(16) << (char *) registro[NOMBRE];
    file << std::left << std::setw(24) << (char *) registro[RAZA];
    file << std::left << std::setw(16) << (char *) registro[COLOR];
    file << std::endl;
}

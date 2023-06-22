/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "medicamento.hpp"
using namespace std;

Medicamento::Medicamento() {
    nombre = nullptr;
}

Medicamento::~Medicamento() {
    if (nombre != nullptr)delete nombre;
}

void Medicamento::SetTotal(double total) {
    this->total = total;
}

double Medicamento::GetTotal() const {
    return total;
}

void Medicamento::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Medicamento::GetFecha() const {
    return fecha;
}

void Medicamento::SetPrecio(double precio) {
    this->precio = precio;
}

double Medicamento::GetPrecio() const {
    return precio;
}

void Medicamento::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Medicamento::GetCantidad() const {
    return cantidad;
}

void Medicamento::SetNombre(const char* cad) {
    if (nombre != nullptr) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre, cad);
}

void Medicamento::GetNombre(char* cad) const {
    if (nombre == nullptr) cad[0] = '\0';
    else strcpy(cad, nombre);
}

void Medicamento::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Medicamento::GetCodigo() const {
    return codigo;
}

void Medicamento::lee_medicamento(int codMedicamento, int auxI, char* auxC)
{
    // Apertura de archivo para lectura
    const char* nombreArch = "medicamentos.csv";
    ifstream archMedicamentos(nombreArch, ios::in);
    if (!archMedicamentos)
    {
        cout << "ERROR: " << nombreArch << endl;
        exit(1);
    }
    
    // Definicion de variables
    int codigo;
    char nombreMedicamento[200];
    double precio;
    
    // Lectura
    while (1)
    {
        archMedicamentos >> codigo;
        if (archMedicamentos.eof()) return;
        archMedicamentos.get(); // lee coma
        archMedicamentos.getline(nombreMedicamento, 200, ',');
        archMedicamentos >> precio;
        
        if (codigo == codMedicamento)
        {
            // Asignacion
            /*
                int codigo; //
                char* nombre; // 
                int cantidad;
                double precio; // 
                int fecha;
                double total;
             */
            SetCodigo(codMedicamento);
            SetNombre(nombreMedicamento);
            SetPrecio(precio);
            return;
        }
    }
}

void Medicamento::imprime_medicamento(ofstream& arch) {
    int dia, mes, anho;
    separa_fecha(fecha, dia, mes, anho);
    arch << setfill('0') << anho << '/' << setw(2) << mes << '/' << setw(2) << dia << setfill(' ')
            << setw(14) << codigo << setw(13) << " " << left << setw(62)
            << nombre << right << setw(2) << cantidad << setw(14) << " "
            << setw(5) << precio << setw(11) << " " << setw(6) << total << setw(9) << " ";
}

void Medicamento::separa_fecha(int fecha, int& dia, int&mes, int& anho) {
    dia = fecha % 100;
    fecha = fecha / 100;
    mes = fecha % 100;
    fecha = fecha / 100;
    anho = fecha;
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "sinreceta.hpp"
#include <iomanip>
#include <cstring>
using namespace std;

SinReceta::SinReceta() 
{
    dni = 0;
    nombreP = nullptr;
}

SinReceta::SinReceta(const SinReceta& orig) {
}

SinReceta::~SinReceta() {
}

void SinReceta::SetNombreP(char* nombre) 
{
    if (nombreP != nullptr) delete[] nombreP;
    nombreP = new char[strlen(nombre) + 1];
    strcpy(nombreP, nombre);
}

void SinReceta::GetNombreP(char* nombre) 
{
    if (nombreP == nullptr)
    {
        nombre[0] = 0;
        return;
    }
    
    strcpy(nombre, nombreP);
}

void SinReceta::SetDni(int dni) {
    this->dni = dni;
}

int SinReceta::GetDni() const {
    return dni;
}

void SinReceta::lee_medicamento(int codMedicamento, int dni, char* nombrePaciente)
{
    Medicamento::lee_medicamento(codMedicamento, dni, nombrePaciente);
    SetDni(dni);
    SetNombreP(nombrePaciente);
}

void SinReceta::imprime_medicamento(ofstream& archReporte)
{
    Medicamento::imprime_medicamento(archReporte);
    archReporte << setw(8) << dni << setw(12) << " " << nombreP << endl;
}
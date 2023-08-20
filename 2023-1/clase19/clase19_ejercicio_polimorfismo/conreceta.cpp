/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "conreceta.hpp"
#include <cstring>
#include <iomanip>
using namespace std;

ConReceta::ConReceta() 
{
    codmed = 0;
    especialidad = nullptr;
}

ConReceta::ConReceta(const ConReceta& orig) {
}

ConReceta::~ConReceta() 
{
    if (this->especialidad != nullptr) delete[] this->especialidad;
}

void ConReceta::SetEspecialidad(char* especialidad) 
{
    if (this->especialidad != nullptr) delete[] this->especialidad;
    this->especialidad = new char[strlen(especialidad) + 1];
    strcpy(this->especialidad, especialidad);
}

void ConReceta::GetEspecialidad(char* especialidad)
{
    if (this->especialidad == nullptr)
    {
        especialidad[0] = 0;
        return;
    }
    
    strcpy(especialidad, this->especialidad);
}

void ConReceta::SetCodMed(int codMed) {
    this->codmed = codMed;
}

int ConReceta::GetCodMed() const {
    return codmed;
}

void ConReceta::lee_medicamento(int codMedicamento, int codMedico, char* especialidadMedico)
{
    Medicamento::lee_medicamento(codMedicamento, codMedico, especialidadMedico);
    SetCodMed(codMedico);
    SetEspecialidad(especialidadMedico);
}

void ConReceta::imprime_medicamento(ofstream& archReporte)
{
    Medicamento::imprime_medicamento(archReporte);
    archReporte << setw(8) << codmed << setw(12) << " " << especialidad << endl;
}
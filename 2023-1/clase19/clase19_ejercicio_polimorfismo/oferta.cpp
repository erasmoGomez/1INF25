/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "oferta.hpp"

Oferta::Oferta() {
    poferta = nullptr;
}

Oferta::Oferta(const Oferta& orig) {
}

Oferta::~Oferta() {
    if (this->poferta != nullptr) delete poferta;
}

void Oferta::SetPoferta(Medicamento* poferta) {
    this->poferta = poferta;
}

Medicamento* Oferta::GetPoferta() const {
    return poferta;
}

void Oferta::operator=(class Medicamento*pt) {
    poferta = pt;
}

bool Oferta::operator!=(Medicamento*pt) {
    return poferta != pt;
}

void Oferta::obtener_especialidad_medico(int codMedico, char* especialidadMedico){
    const char* nombreArch = "medicos.csv";
    ifstream archMedicos(nombreArch, ios::in);
    if (!archMedicos)
    {
        cout << "ERROR: No se puede abrir el archivo " << nombreArch << endl;
        exit(1);
    }
    
    // Definicion de variables
    int codigoMedico;
    char nombreMedico[200];
    char espMedico[200];
    
    // Recorre archivo medicos en busca del codMedico
    while (1)
    {
        archMedicos >> codigoMedico;
        if (archMedicos.eof())
        {
            especialidadMedico[0] = 0;
            return;
        }
        archMedicos.get(); // lee coma
        archMedicos.getline(nombreMedico, 200, ',');
        archMedicos.getline(espMedico, 200, '\n');
        
        if (codMedico == codigoMedico)
        {
            strcpy(especialidadMedico, espMedico);
            return;
        }
    }
}

void Oferta::asigna_medicamento(ifstream &archRecetas) {
    // Definicion de variables
    int codMedicamento;
    int cantMedicamento;
    int dia, mes, anho;
    int fecha;
    char aux;
    int codMedico;
    int dniPaciente;
    char nombrePaciente[200];
    //Medicamento* pMedicamento;

    archRecetas >> codMedicamento;
    if (archRecetas.eof()) return;
    archRecetas >> aux >> cantMedicamento >> aux >> dia >> aux >> mes >> aux >> anho >> aux >> codMedico >> aux >> dniPaciente >> aux;
    archRecetas.getline(nombrePaciente, 200, '\n');

    fecha = (anho * 10000) + (mes * 100) + dia;

    // Medicamento con receta
    if (codMedicamento / 10000 % 2 == 0) {
        poferta = new class ConReceta;
        char especialidadMedico[200];
        obtener_especialidad_medico(codMedico, especialidadMedico);
        poferta->lee_medicamento(codMedicamento, codMedico, especialidadMedico);
    } else {
        poferta = new class SinReceta;
        poferta->lee_medicamento(codMedicamento, dniPaciente, nombrePaciente);
    }

    poferta->SetFecha(fecha);
    poferta->SetCantidad(cantMedicamento);
}

void Oferta::imprime_medicamento(ofstream& arch) {
    poferta->imprime_medicamento(arch); //Usamos POLIMORFISMO
}
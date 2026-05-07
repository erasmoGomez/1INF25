//
// Created by Daniel Sanchez on 6/05/26.
//

#ifndef SOLUCION_HOSPITAL_H
#define SOLUCION_HOSPITAL_H

enum PACIENTE_FIELD {
    PACIENTE_ID = 0,
    PACIENTE_NAME,
    PACIENTE_AGE,
    PACIENTE_GENDER,
    PACIENTE_VISITS,
    PACIENTE_COST,
    PACIENTE_COUNT
};

enum VISIT_FIELD {
    VISIT_DATE = 0,
    VISIT_TIME,
    VISIT_COST,
    VISIT_COUNT
};

void cargarPacientes(const char *arch_name, void *&pacientes);

void generarReporte(const char *arch_name, void *pacientes);

void cargarVisitas(const char *arch_name, void *pacientes);

#endif //SOLUCION_HOSPITAL_H

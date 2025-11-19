//
// Created by cueva on 2/09/2025.
//

#ifndef SOBRECARGACURSOS_ESTRUCTURAS_H
#define SOBRECARGACURSOS_ESTRUCTURAS_H

    struct Alumnos {
        int codigo;
        char *nombre;
        char tipo;
    };

    struct Cursos {
        char *codigo;
        char *nombre;
        double creditos;
        char *docente;
        struct Alumnos presencial[50];
        struct Alumnos semipresencial[50];
        struct Alumnos vvirtual[50];
        int numpresencial;
        int numsemipresencial;
        int numvirtual;
        char *tipofinal;
    };


#endif //SOBRECARGACURSOS_ESTRUCTURAS_H
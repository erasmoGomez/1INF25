#include "MetodoPorIncrementos.h"

void cargarDatos(const char* nombreArch, char***& datos, int*& creditos,
            char****& alumnos, double**& informacion_economica){
    ifstream arch(nombreArch, ios::in);
    if(!arch.is_open()){
        cout << "Error en archivo " << nombreArch;
        exit(1);
    }
    
    char nombreCurso[100], codCurso[10], **infoCurso, aux;
    int nCursos = 0, capCursos = 0, credito;
    double *infoEconomicaCurso;
    
    datos = nullptr;
    creditos = nullptr;
    alumnos = nullptr;
    informacion_economica = nullptr;
    
    while(true){
        arch.getline(codCurso, 10, ',');
        if(arch.eof())
            break;
        arch.getline(nombreCurso, 100, ',');
        arch >> credito >> aux;
        cout << codCurso << endl << nombreCurso << endl << endl;
        if(nCursos == capCursos)
            incrementarEspacios(datos, creditos, alumnos, informacion_economica,
                nCursos, capCursos);
        creditos[nCursos-1] = credito;
        creditos[nCursos] = 0;
        infoCurso = new char*[2];
        asignarCadena(infoCurso[0], codCurso);
        asignarCadena(infoCurso[1], nombreCurso);
        datos[nCursos-1] = infoCurso;
        datos[nCursos] = nullptr;
        procesarAlumnosEnCurso(arch, alumnos[nCursos-1], creditos[nCursos-1],
                infoEconomicaCurso);
        informacion_economica[nCursos-1] = infoEconomicaCurso;
        informacion_economica[nCursos] = nullptr;
        alumnos[nCursos] = nullptr;
        nCursos++;
    }
}

void pruebaCursos(const char* nombreArch, char*** datos, int* creditos,
            char**** alumnos, double** informacion_economica){
    ofstream arch(nombreArch, ios::out);
    if(!arch.is_open()){
        cout << "Error en archivo " << nombreArch;
        exit(1);
    }
    arch.precision(2);
    arch << "PRUEBA DE CURSOS" << endl << endl;
    for(int i=0; datos[i] != nullptr; i++){
        imprimirLinea(arch, '=', 90);
        arch << "(" << right << setw(2) << setfill('0') << (i+1) << ") " << left <<
                datos[i][1] << " [" << datos[i][0] << " -> " << creditos[0] <<
                " créditos]" << endl;
        imprimirLinea(arch, '-', 90);
        arch << "Alumnos:" << endl;
        for(int j=0; alumnos[i][j] != nullptr; j++){
            arch << "(" << right << setw(2) << setfill('0') << (j+1) << ") " << left <<
                    alumnos[i][j][1] << " [Código: " << alumnos[i][j][0] << "]" << endl;
        }
        imprimirLinea(arch, '-', 90);
        arch << "Número de alumnos: " << (int) informacion_economica[i][0] << endl;
        arch << "Total recaudado: " << fixed << informacion_economica[i][1] << endl;

    }
}

void reporteDeAlumnosPorCurso(const char* nombreArch, char*** datos,
        int* creditos, char**** alumnos, double** informacion_economica){
    ofstream arch(nombreArch, ios::out);
    char **infoCurso, ***infoAlumnos;
    double pagoTotalCurso, pagoTotalCiclo = 0;
    if(!arch.is_open()){
        cout << "Error en archivo " << nombreArch;
        exit(1);
    }
    arch.precision(2);
    arch << right << setw(59) << "CURSOS EN EL CICLO 2023-1" << endl;
    imprimirLinea(arch, '=', 90);
    arch << setw(62) << "RELACIÓN DE ALUMNOS POR CURSO" << left << endl;
    for(int i=0; datos[i] != nullptr; i++){
        pagoTotalCurso = 0;
        imprimirLinea(arch, '=', 90);
        arch << left << setw(10) << "CÓDIGO" << setw(60) << "Nombre" << setw(13) <<
                "Créditos:" << creditos[i] << endl;
        infoCurso = datos[i];
        arch << setw(9) << infoCurso[0] << setw(60) << infoCurso[1] << endl;
        imprimirLinea(arch, '-', 90);
        arch << "RELACIÓN DE ALUMNOS MATRICULADOS:" << endl;
        imprimirLinea(arch, '-', 90);
        arch << setw(12) << " " << setw(10) << "CODIGO" << setw(50) << "Nombre" <<
                "Pago total" << endl;
        imprimirLinea(arch, '-', 90);
        imprimirDetalleAlumnosCurso(arch, alumnos[i], creditos[i], pagoTotalCurso);
        infoAlumnos = alumnos[i];
        
    }
    arch << right << setw(25) << "TOTAL RECAUDADO 2023-1:" << setw(57) <<
            fixed << pagoTotalCiclo;
    
}

void incrementarEspacios(char***& datos, int*& creditos, char****& alumnos,
        double**& informacion_economica, int& nCursos, int& capacidad){
    char*** auxDatos, ****auxAlumnos;
    double** auxEconomica;
    int* auxCreditos;
    
    capacidad += INCREMENTO;
    if(datos == nullptr){
        datos = new char**[capacidad];
        creditos = new int[capacidad];
        alumnos = new char***[capacidad];
        informacion_economica = new double*[capacidad];
        datos[0] = nullptr;
        creditos[0] = 0;
        alumnos[0] = nullptr;
        informacion_economica[0] = nullptr;
        nCursos++;
    }else{
        auxDatos = new char**[capacidad];
        auxAlumnos = new char***[capacidad];
        auxEconomica = new double*[capacidad];
        auxCreditos = new int[capacidad];
        for(int i=0; i<nCursos; i++){
            auxDatos[i] = datos[i];
            auxAlumnos[i] = alumnos[i];
            auxEconomica[i] = informacion_economica[i];
            auxCreditos[i] = creditos[i];
        }
        delete datos;
        delete alumnos;
        delete informacion_economica;
        delete creditos;
        datos = auxDatos;
        alumnos = auxAlumnos;
        informacion_economica = auxEconomica;
        creditos = auxCreditos;
    }
}

void procesarAlumnosEnCurso(ifstream& arch, char***& infoAlumnos, int creditaje,
        double*& infoEconomica){
    int capacidad = 0, nAlumnos = 0, escala;
    char **auxInfoAlumnos, nombreAlumno[100], codEscala[11];
    infoEconomica = new double[2];
    infoEconomica[0] = 0;
    infoEconomica[1] = 0;
    while(true){
        arch.getline(nombreAlumno, 100, ',');
        arch.get(codEscala, 11);
        if(nAlumnos == capacidad){
            incrementarPunteroCaracterTriple(infoAlumnos, nAlumnos, capacidad);
        }
        auxInfoAlumnos = new char*[2];
        asignarCadena(auxInfoAlumnos[0], codEscala);
        asignarCadena(auxInfoAlumnos[1], nombreAlumno);
        infoAlumnos[nAlumnos-1] = auxInfoAlumnos;
        infoAlumnos[nAlumnos] = nullptr;
        escala = (codEscala[9]) - 48;
        infoEconomica[1] += creditaje * obtenerPrecioPorEscala(escala);
        nAlumnos++;
        if(arch.get() == '\n')
            break;
    }
    infoEconomica[0] = nAlumnos-1;
}

void incrementarPunteroCaracterTriple(char***& lista, int& nAlumnos, int& capacidad){
    char*** auxLista;
    
    capacidad += INCREMENTO;
    if(lista == nullptr){
        lista = new char**[capacidad];
        lista[0] = nullptr;
        nAlumnos++;
    }else{
        auxLista = new char**[capacidad];
        for(int i=0; i<nAlumnos; i++)
            auxLista[i] = lista[i];
        delete lista;
        lista = auxLista;
    }
}

void asignarCadena(char*& copia, char* original){
    copia = new char[strlen(original)+1];
    strcpy(copia, original);
}

void imprimirDetalleAlumnosCurso(ofstream& arch, char ***infoAlumno,
            int creditos, double& pagoTotalCiclo){
    double pagoTotalCurso = 0;
    for(int i=0; infoAlumno[i] != nullptr; i++)
        imprimirAlumnoYAcumularTotalCurso(arch, i, infoAlumno[i], creditos, 
                pagoTotalCurso);
    imprimirLinea(arch, '-', 90);
    arch << right << setw(28) << "TOTAL:" << setw(54) << pagoTotalCurso << endl;
    imprimirLinea(arch, '=', 90);
    arch << endl;
    pagoTotalCiclo += pagoTotalCurso;
}

void imprimirAlumnoYAcumularTotalCurso(ofstream& arch, int indice, 
        char** detalleAlumno, int creditos, double& pagoTotalCurso){
    char *codAlumno;
    double pagoUnitario;
    int escala;
    codAlumno = detalleAlumno[0];
    escala = (codAlumno[9]) - 48;
    codAlumno[8] = '\0';
    pagoUnitario = creditos * obtenerPrecioPorEscala(escala);
    arch << right << setw(4) << (indice+1) << setw(7) << " " << left <<
            setw(11) << codAlumno << setw(50) << detalleAlumno[1] << 
            setw(10) << right << fixed << pagoUnitario << endl;
    pagoTotalCurso += pagoUnitario;
}

double obtenerPrecioPorEscala(int escala){
    return (escala == 1 ? PRECIOESCALA1 : 
            escala == 2 ? PRECIOESCALA2 : escala == 3 ? PRECIOESCALA3 :
            escala == 4 ? PRECIOESCALA4 : PRECIOESCALA5);
}

void imprimirLinea(ofstream& arch, char caracter, int repeticiones){
    for(int i=0; i<repeticiones; i++)
        arch << caracter;
    arch << endl;
}
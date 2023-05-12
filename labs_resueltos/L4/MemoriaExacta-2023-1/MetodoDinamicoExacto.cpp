/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "MetodoDinamicoExacto.h"

void lecturaAlumnos(const char *nombreArchivo, int*& alumno_Codigo,
        char**& alumno_Nombre, char*& alumno_Modalidad, int*& alumno_Porcentaje,
        int*& alumno_Escala){
    ifstream archEntrada(nombreArchivo, ios::in);
    int buffCodigo[100], buffEscala[100];
    int buffPorcentaje[100], nDatos = 0;
    char *buffModalidad, *buffNombre[100];
    
    if(!archEntrada.is_open()){
        cout << "Error al abrir archivo " << nombreArchivo;
        exit(1);
    }
    
    procesarArchivoAlumnos(archEntrada, buffCodigo, buffPorcentaje, buffEscala, 
            buffModalidad, buffNombre, nDatos);
    
    // Formación de arreglos exactos
    memoriaExactaEntera(alumno_Codigo, buffCodigo, nDatos);
    memoriaExactaEntera(alumno_Porcentaje, buffPorcentaje, nDatos);
    memoriaExactaEntera(alumno_Escala, buffEscala, nDatos);
    memoriaExactaCadena(alumno_Modalidad, buffModalidad, nDatos);
    memoriaExactaArregloCadena(alumno_Nombre, buffNombre, nDatos);
}

void pruebaLecturaAlumnos(const char *nombreReporte, int* alumno_Codigo,
        char** alumno_Nombre, char* alumno_Modalidad, int* alumno_Porcentaje,
        int* alumno_Escala){
    ofstream archReporte(nombreReporte, ios::out);
    if(!archReporte.is_open()){
        cout << "Error al abrir archivo " << nombreReporte;
        exit(1);
    }
    archReporte.precision(2);
    archReporte << "REPORTE DE ALUMNOS" << endl << endl;
    for(int i=0; alumno_Nombre[i] != 0; i++){
        archReporte << "(" << setw(2) << setfill('0') << right << (i+1) << ") "
                << alumno_Nombre[i] << endl << "     Código: " << fixed
                << alumno_Codigo[i] << endl << "     Escala: " 
                << alumno_Escala[i] << endl << "     Modalidad: ";
        if(alumno_Modalidad[i] == 'P')
            archReporte << "Presencial" << endl;
        else if(alumno_Modalidad[i] == 'V')
            archReporte << "Virtual" << endl;
        else
            archReporte << "Semipresencial con pago de " <<
                    alumno_Porcentaje[i] << "%" << endl;
    }
}

void lecturaCursos(const char *nombreArchivo, int* alumno_Codigo, 
        int* alumno_Escala, char**& curso_Nombre, double*& curso_Credito,
        int**& curso_Alumnos){
    ifstream archEntrada(nombreArchivo, ios::in);
    int nDatos, *buffAlumnos[100];
    double buffCreditos[100];
    char *buffNombre[100];
    
    if(!archEntrada.is_open()){
        cout << "Error al abrir archivo " << nombreArchivo;
        exit(1);
    }
    
    procesarArchivoCursos(archEntrada, buffNombre, buffCreditos, buffAlumnos,
            alumno_Codigo, alumno_Escala, nDatos);
    
    // Formación de arreglos exactos
    memoriaExactaArregloCadena(curso_Nombre, buffNombre, nDatos);
    memoriaExactaPuntoFlotante(curso_Credito, buffCreditos, nDatos);
    memoriaExactaArregloAlumnos(curso_Alumnos, buffAlumnos, nDatos);
    
}

void pruebaDeLecturaCursos(const char *nombreReporte, char** curso_Nombre,
        double* curso_Credito, int** curso_Alumnos){
    ofstream archReporte(nombreReporte, ios::out);
    if(!archReporte.is_open()){
        cout << "Error al abrir archivo " << nombreReporte;
        exit(1);
    }
    archReporte.precision(2);
    archReporte << "REPORTE DE CURSOS" << endl << endl;
    for(int i=0; curso_Nombre[i] != nullptr; i++){ 
        archReporte << "(" << setw(2) << setfill('0') << right << (i+1) << ") "
                << curso_Nombre[i] << " (" << fixed << curso_Credito[i] << 
                " créditos)" << endl;
        archReporte << "Matriculados:" << endl;
        for(int j=0; j<curso_Alumnos[i][2*j] != 0; j++)
            archReporte << curso_Alumnos[i][2*j] << " (Escala " << 
                    curso_Alumnos[i][2*j+1] << ")" << endl;
        archReporte << endl;
    }
}

void reporteDeRecaudacionPorModalidad(const char* nombreReporte, 
        int* alumno_Codigo, char* alumno_Modalidad, int* alumno_Porcentaje,
        char** alumno_Nombre, char** curso_Nombre, double* curso_Credito,
        int** curso_Alumnos){
    ofstream archReporte(nombreReporte, ios::out);
    
    int indiceAlumno, escala;
    double *pagoXEscalas, creditaje, subTotalAlumno[3] = {0}, totalXModalidad[3] = {0};
     
    if(!archReporte.is_open()){
        cout << "Error al abrir archivo " << nombreReporte;
        exit(1);
    }
    leerEscalas(pagoXEscalas);
    imprimirCabeceraGeneral(archReporte);
    for(int i=0; curso_Alumnos[i] != nullptr; i++){
        imprimirCabeceraCurso(archReporte, i, curso_Nombre[i], curso_Credito[i]);
        creditaje = curso_Credito[i];
        for(int j=0; curso_Alumnos[i][2*j] != 0; j++){
            archReporte << right << setw(2) << setfill('0') << (j+1);
            archReporte << setfill(' ') << left << ")  " << setw(7);
            archReporte << curso_Alumnos[i][2*j];
            
            indiceAlumno = buscarIndiceAlumno(curso_Alumnos[i][2*j], 
                    alumno_Codigo);
            escala = curso_Alumnos[i][2*j+1];
            imprimirYActualizarDetalleAlumno(archReporte, indiceAlumno, 
                    alumno_Nombre, alumno_Modalidad, alumno_Porcentaje,
                    pagoXEscalas, escala, creditaje, subTotalAlumno);
        }
        imprimirResumenCurso(archReporte, subTotalAlumno, totalXModalidad);
    }
    imprimirResumenGeneral(archReporte, totalXModalidad);
}

void procesarArchivoAlumnos(ifstream& arch, int* codigos, int* porcentajes,
        int* escalas, char*& modalidades, char** nombres, int& nDatos){
    int codAlumno, escala, porcentaje;
    char modalidad, *nombreAlumno;
    modalidades = new char[101];
    nDatos = 0;
    while(true){
        arch >> codAlumno;
        if(arch.eof())
            break;
        // Lectura de demás campos
        procesarDemasDatosDeAlumno(arch, nombreAlumno, escala, modalidad, porcentaje);
        // Asignación a arreglos
        codigos[nDatos] = codAlumno;
        porcentajes[nDatos] = porcentaje;
        escalas[nDatos] = escala;
        modalidades[nDatos] = modalidad;
        nombres[nDatos] = nombreAlumno;
        nDatos++;
    }
}

void procesarArchivoCursos(ifstream& archEntrada, char** buffNombre,
        double* buffCreditos, int** buffAlumnos, int* alumno_Codigo,
        int* alumno_Escala, int& nDatos){
    int codAlumno, escala, indiceAlumno;
    double creditaje;
    char aux, nombreCurso[100];

    nDatos = 0;
    while(true){
        archEntrada >> codAlumno;
        if(archEntrada.eof())
            break;
        // Búsqueda del índice del alumno en el arreglo de códigos.
        indiceAlumno = buscarIndiceAlumno(codAlumno, alumno_Codigo);
        escala = alumno_Escala[indiceAlumno];
        // Lectura de demás campos
        archEntrada >> aux;
        archEntrada.getline(nombreCurso, 100, ',');
        archEntrada >> creditaje;
        // El presente módulo discierne si se trata de un curso existente o nuevo.
        procesarCurso(nombreCurso, creditaje, codAlumno, escala, nDatos, 
                buffNombre, buffCreditos, buffAlumnos);
    }
}


// Estos módulos realizan la reserva de memoria exacta.
void memoriaExactaEntera(int*& exacto, int* buffer, int nDatos){
    exacto = new int[nDatos+1];
    for(int i=0; i<nDatos; i++)
        exacto[i] = buffer[i];
    exacto[nDatos] = 0;
    delete buffer;
}

void memoriaExactaPuntoFlotante(double*& exacto, double* buffer, int nDatos){
    exacto = new double[nDatos+1];
    for(int i=0; i<nDatos; i++)
        exacto[i] = buffer[i];
    exacto[nDatos] = 0;
    delete buffer;
}

void memoriaExactaCadena(char*& exacto, char* buffer, int nDatos){
    exacto = new char[nDatos+1];
    for(int i=0; i<nDatos; i++)
        exacto[i] = buffer[i];
    exacto[nDatos] = '\0';
    delete buffer;
}

void memoriaExactaArregloCadena(char**& exacto, char** buffer, int nDatos){
    exacto = new char*[nDatos+1];
    for(int i=0; i<nDatos; i++)
        exacto[i] = buffer[i];
    exacto[nDatos] = nullptr;
    delete buffer;
}

void memoriaExactaArregloAlumnos(int**& exacto, int** buffer, int nDatos){
    int *auxCursoXAlumno;
    exacto = new int*[nDatos+1];
    
    for(int i=0; i<nDatos; i++){
        int nDatosAlumnos;
        // Recorrer el arreglo del curso hasta encontrar el 0.
        for(nDatosAlumnos=0; buffer[i][nDatosAlumnos] != 0;
                nDatosAlumnos=nDatosAlumnos+2);
        // Tratar el arreglo resultante para asignarlo mediante memoria exacta.
        memoriaExactaEntera(auxCursoXAlumno, buffer[i], nDatosAlumnos);
        exacto[i] = auxCursoXAlumno;
    }
    
    exacto[nDatos] = nullptr; 
}

void procesarDemasDatosDeAlumno(ifstream& arch, char*& nombre, int& escala, 
        char& modalidad, int& porcentaje){
    char aux, nombreTemp[100];
    arch >> aux;
    arch.getline(nombreTemp, 100, ',');
    nombre = new char[strlen(nombreTemp) + 1];
    strcpy(nombre, nombreTemp);
    arch >> escala;
    if(arch.fail()){
        arch.clear();
        arch >> modalidad >> aux;
        if(modalidad == 'S')
            arch >> porcentaje >> aux;
        else
            porcentaje = 0;
        arch >> escala;
    } else
        modalidad = 'P';
}

void procesarCurso(char* nombre, double creditaje, int codAlumno,
        int escalaAlumno, int& nCursos, char** buffNombre,
        double* buffCreditos, int** buffAlumnos){
    int indiceCurso = cursoEstaRegistrado(nombre, buffNombre, nCursos);
    if(indiceCurso == -1){ // No está, hay que crearlo
        buffNombre[nCursos] = new char[strlen(nombre) + 1];
        strcpy(buffNombre[nCursos], nombre);
        buffCreditos[nCursos] = creditaje;
        buffAlumnos[nCursos] = new int[100];
        buffAlumnos[nCursos][0] = codAlumno;
        buffAlumnos[nCursos][1] = escalaAlumno;
        buffAlumnos[nCursos][2] = 0;
        nCursos++;
    }else{ // Está, agregar a arreglo ya existente
        int indiceAInsertar;
        for(indiceAInsertar=0;
            buffAlumnos[indiceCurso][indiceAInsertar] != 0;
            indiceAInsertar=indiceAInsertar+2);
        buffAlumnos[indiceCurso][indiceAInsertar] = codAlumno;
        buffAlumnos[indiceCurso][indiceAInsertar+1] = escalaAlumno;
        buffAlumnos[indiceCurso][indiceAInsertar+2] = 0;
    }
}

void imprimirCabeceraGeneral(ofstream& archReporte){
    archReporte << right << setw(71) << "ENTIDAD EDUCATIVA LP1" << endl;
    archReporte << setw(69) << "LISTADOS DE CLASE" << left << endl;
    imprimirLinea(archReporte, '=', 120, true);
    archReporte.precision(2);
}

void imprimirCabeceraCurso(ofstream& archReporte, int contador,
        char* nombreCurso, int creditaje){
    archReporte << right << setfill('0') << setw(2) << (contador+1);
    archReporte << setfill(' ') << ") ";
    imprimirNombre(archReporte, nombreCurso, true);
    archReporte << setw(15) << "Créditos: " << left;
    archReporte << fixed << creditaje << endl;
    imprimirLinea(archReporte, '-', 120, true);
    archReporte << "ALUMNOS Matriculados" << endl;
    imprimirLinea(archReporte, '-', 120, true);
    archReporte << right << setw(90) << "PAGOS" << endl;
    archReporte << left << "   " << setw(11) << "CÓDIGO" << setw(50);
    archReporte << "NOMBRE" << setw(10) << "ESCALA" << setw(15);
    archReporte << "PRESENCIAL" << setw(20) << "SEMIPRESENCIAL";
    archReporte << setw(15) << "VIRTUAL" << endl;
    imprimirLinea(archReporte, '-', 120, true);
}

void imprimirYActualizarDetalleAlumno(ofstream& archReporte, int indiceAlumno,
        char** nombres, char* modalidades, int* porcentajes, 
        double* pagoXEscalas, int escala, double creditaje,
        double* subTotalAlumno){
    char modalidad;
    int espaciadoPrecio;
    double pagoUnitario;
    
    imprimirNombre(archReporte, nombres[indiceAlumno], false);
    modalidad = modalidades[indiceAlumno];
    pagoUnitario = pagoXEscalas[escala-1]*creditaje;
    if(modalidad == 'P'){
        subTotalAlumno[IND_PRESENCIAL] += pagoUnitario;
        espaciadoPrecio = 16;
    }else if(modalidad == 'V'){
        pagoUnitario *= 0.45;
        subTotalAlumno[IND_VIRTUAL] += pagoUnitario;
        espaciadoPrecio = 48;
    }else{
        pagoUnitario *= porcentajes[indiceAlumno] / 100.00;
        subTotalAlumno[IND_SEMI] += pagoUnitario;
        espaciadoPrecio = 35;
    }
    archReporte << escala << fixed << right << setw(espaciadoPrecio) <<
        pagoUnitario << endl;
}

void imprimirResumenCurso(ofstream& archReporte, double* subTotales,
        double* totales){
    imprimirLinea(archReporte, '=', 120, true);
    archReporte << left << "RECAUDACIÓN POR MODALIDAD DE ESTUDIO" << right <<
            setw(47) << subTotales[IND_PRESENCIAL] <<
            setw(19) << subTotales[IND_SEMI] <<
            setw(13) << subTotales[IND_VIRTUAL] << left << endl;
    imprimirLinea(archReporte, '-', 120, true);
    archReporte << "TOTAL RECAUDADO: " << right <<
            setw(98) << subTotales[IND_PRESENCIAL] + subTotales[IND_SEMI] +
                totales[IND_VIRTUAL] << left << endl;
    imprimirLinea(archReporte, '=', 120, true);
    for(int j=0; j<3; j++){
        totales[j] += subTotales[j];
        subTotales[j] = 0;
    }
}

void imprimirResumenGeneral(ofstream& archReporte, double* totales){
    archReporte << "RECAUDACIÓN TOTAL POR MODALIDAD DE ESTUDIO: " << right <<
                setw(39) << totales[IND_PRESENCIAL] <<
                setw(19) << totales[IND_SEMI] <<
                setw(13) << totales[IND_VIRTUAL] << left << endl;
    imprimirLinea(archReporte, '-', 120, true);
    archReporte << "TOTAL GENERAL RECAUDADO: " << right <<
                setw(90) << totales[IND_PRESENCIAL] + totales[IND_SEMI] +
                    totales[IND_VIRTUAL] << left << endl;
    imprimirLinea(archReporte, '=', 120, true);
}

int buscarIndiceAlumno(int alumnoBuscado, int* alumno_Codigo){
    for(int i=0; alumno_Codigo[i] != 0; i++){
        if(alumno_Codigo[i] == alumnoBuscado)
            return i;
    }
}

int cursoEstaRegistrado(char* nombreCurso, char **buffNombre, int nCursos){
    for(int i=0; i<nCursos; i++){
        if(strcmp(nombreCurso, buffNombre[i]) == 0)
            return i;
    }
    return -1;
}

void leerEscalas(double*& escalas){
    ifstream archEscalas("escalas.csv", ios::out);
    char aux;
    int numEscala;
    if(!archEscalas.is_open()){
        cout << "Error al abrir archivo escalas.csv";
        exit(1);
    }
    escalas = new double[5];
    while(true){
        archEscalas >> aux >> numEscala;
        if(archEscalas.eof())
            break;
        archEscalas >> aux >> escalas[numEscala-1];
    }
}

void imprimirNombre(ofstream& arch, char *nombre, bool capitalizar){
    int nCaracteres = imprimirCapitalizacion(arch, nombre, capitalizar);
    for(int i=nCaracteres; i<54; i++)
        arch << ' ';
}

// Devuelve la cantidad de caracteres de la cadena
int imprimirCapitalizacion(ofstream& archivo, char* nombre, bool capitalizar){
    int i;
    for(i=0; nombre[i] != '\0'; i++){
        if(nombre[i] == '_')
            archivo << ' ';
        else if(capitalizar and nombre[i] >= 'a' and nombre[i] <= 'z')
            archivo << (char)(nombre[i] - 32);
        else if(!capitalizar and nombre[i] >= 'A' and nombre[i] <= 'Z' and not
                // Para no descapitalizar las primeras letras de las palabras
                (i==0 or (i>0 and nombre[i-1] == ' ' or nombre[i-1] == '_')))
            archivo << (char)(nombre[i] + 32);
        else
            archivo << nombre[i];
    }
    return i;
}

void imprimirLinea(ofstream& archivo, char caracter, double repeticiones,
        bool cambioLinea){
    for(int i=0; i<repeticiones; i++) archivo << caracter;
    if(cambioLinea)
        archivo << endl;
}
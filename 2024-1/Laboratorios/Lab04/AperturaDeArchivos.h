#ifndef APERTURADEARCHIVOS_H
#define APERTURADEARCHIVOS_H
#include <fstream>
using namespace std;
void AperturaDeUnArchivoDeTextosParaLeer(ifstream &archivo, const char *nombreDelArchivo);
void AperturaDeUnArchivoDeTextosParaEscribir(ofstream &archivo, const char *nombreDelArchivo);
#endif /* APERTURADEARCHIVOS_H */

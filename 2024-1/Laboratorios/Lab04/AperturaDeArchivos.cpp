/*
  Mac OS X ARM (64-bit):

	To compile into a static library:
		clang++ -std=c++17 -c AperturaDeArchivos.cpp -o AperturaDeArchivos.o
		ar rcs libAperturaDeArchivos.a AperturaDeArchivos.o
*/

#include "AperturaDeArchivos.h"

#include <iostream>
#include <fstream>

using namespace std;

void AperturaDeUnArchivoDeTextosParaLeer(ifstream &arch, const char *name)
{
	arch.open(name, ifstream::in);
	if (not arch.is_open())
	{
		cerr << "[ERROR] AperturaDeUnArchivoDeTextosParaLeer: no se puede abrir el archivo " << name << "." << endl;
		exit(1);
	}
}
void AperturaDeUnArchivoDeTextosParaEscribir(ofstream &arch, const char *name)
{
	arch.open(name, ofstream::out);
	if (not arch.is_open())
	{
		cerr << "[ERROR] AperturaDeUnArchivoDeTextosParaEscribir: no se puede abrir el archivo " << name << "." << endl;
		exit(1);
	}
}
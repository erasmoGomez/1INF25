#include "MuestraPunteroGenerico.h"

#include "AperturaDeArchivos.h"

#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

void muestraclientes(void *clientes)
{
	ofstream arch;
	AperturaDeUnArchivoDeTextosParaEscribir(arch, "ReporteClientes.txt");
	void **clientes_arr = (void **)clientes;
	for (int i = 0; clientes_arr[i] != nullptr; i += 1)
	{
		void **cliente = (void **)clientes_arr[i];
		int *dni = (int *)cliente[0];
		char *nombre = (char *)cliente[1];
		arch << "DNI: " << *dni << endl;
		arch << "Nombre: " << nombre << endl;
		arch << endl;
	}
}

void muestrareservas(void *reserva)
{
	ofstream arch;
	AperturaDeUnArchivoDeTextosParaEscribir(arch, "ReporteReserva.txt");
	void **reserva_arr = (void **)reserva;
	for (int i = 0; reserva_arr[i] != nullptr; i += 1)
	{
		void **libro = (void **)reserva_arr[i];
		char *codigo = (char *)libro[0];
		char *nombre_libro = (char *)libro[1];
		char *autor = (char *)libro[2];
		void **pedidos = (void **)libro[3];
		int *stock = (int *)libro[4];
		arch << "Libro: " << codigo << endl;
		arch << "Nombre: " << nombre_libro << endl;
		arch << "Autor: " << autor << endl;
		arch << "Stock: " << *stock << endl;
		for (int j = 0; j < *stock; j += 1)
		{
			void **pedido = (void **)pedidos[j];
			// `pedido` debe ser nullptr segun enunciado
			if (pedido != nullptr)
			{
				cerr << "[Warning] muestrareservas: el pedido[" << j << "] del libro " << codigo << " debe estar inicializado con nullptr." << endl;
			}
		}
		arch << endl;
	}
}

void reportefinal(void *reserva)
{
	ofstream arch;
	AperturaDeUnArchivoDeTextosParaEscribir(arch, "ReporteFinal.txt");

	arch << "Reporte de Libros reservados" << endl;
	arch << "==============================" << endl;
	void **reserva_arr = (void **)reserva;
	for (int i = 0; reserva_arr[i] != nullptr; i += 1)
	{
		void **libro = (void **)reserva_arr[i];
		char *codigo = (char *)libro[0];
		char *nombre_libro = (char *)libro[1];
		char *autor = (char *)libro[2];
		void **pedidos = (void **)libro[3];
		int *stock = (int *)libro[4];

		arch << "Libro: " << codigo << endl;
		arch << "Nombre: " << nombre_libro << endl;
		arch << "Autor: " << autor << endl;
		// arch << "Stock:" << *stock << endl;
		arch << left << setw(10) << "DNI" << setw(60) << "Nombre del solicitante" << endl;
		arch << "----------------------------------------" << endl;
		for (int j = 0; j < *stock; j += 1)
		{
			void **pedido = (void **)pedidos[j];
			if (pedido != nullptr)
			{
				int *dni = (int *)pedido[0];
				char *nombre_cliente = (char *)pedido[1];
				arch << left << setw(10) << *dni << setw(60) << nombre_cliente << endl;
			}
		}
		arch << endl;
	}
}

#include "PunterosGenericos.h"

#include "AperturaDeArchivos.h"

#include <iostream>
#include <fstream>

#include <cstring>

using namespace std;

char *read_string(ifstream &arch, char delim)
{
	constexpr int MAX_BUF_SIZE = 100;
	char buf[MAX_BUF_SIZE];
	arch.getline(buf, MAX_BUF_SIZE, delim);
	char *str = new char[strlen(buf) + 1];
	strcpy(str, buf);
	return str;
}

void cargaclientes(void *&clientes)
{
	ifstream arch;
	AperturaDeUnArchivoDeTextosParaLeer(arch, "Clientes.csv");

	int n_clientes = 0;
	void *clientes_buf[60];
	while (true)
	{
		char c;
		int *dni = new int;
		arch >> *dni;
		if (arch.eof())
			break;
		arch >> c;
		char *nombre = read_string(arch, '\n');
		void **cliente = new void *[2];
		cliente[0] = (void *)dni;
		cliente[1] = (void *)nombre;
		clientes_buf[n_clientes] = cliente;
		n_clientes += 1;
	}

	void **clientes_arr = new void *[n_clientes + 1];
	for (int i = 0; i < n_clientes; i += 1)
	{
		clientes_arr[i] = clientes_buf[i];
	}
	clientes_arr[n_clientes] = nullptr;

	clientes = clientes_arr;
}

void creareserva(void *&reserva)
{
	ifstream arch;
	AperturaDeUnArchivoDeTextosParaLeer(arch, "Libros.csv");

	int n_libros = 0;
	void *reserva_buf[300];
	while (true)
	{
		char c;
		double precio;
		char *codigo = read_string(arch, ',');
		if (arch.eof())
			break;
		char *nombre_libro = read_string(arch, ',');
		char *autor = read_string(arch, ',');
		int *stock = new int;
		arch >> *stock >> c >> precio;
		arch.get();

		void **libro = new void *[5];
		libro[0] = (void *)codigo;
		libro[1] = (void *)nombre_libro;
		libro[2] = (void *)autor;
		libro[3] = (void *)(new void *[*stock] {});
		libro[4] = (void *)stock;

		reserva_buf[n_libros] = libro;
		n_libros += 1;
	}

	void **reserva_arr = new void *[n_libros + 1];
	for (int i = 0; i < n_libros; i += 1)
	{
		reserva_arr[i] = reserva_buf[i];
	}
	reserva_arr[n_libros] = nullptr;

	reserva = reserva_arr;
}

void **buscar_cliente(void *clientes, int dni)
{
	void **clientes_arr = (void **)clientes;
	if (clientes_arr == nullptr)
		return nullptr;
	for (int i = 0; clientes_arr[i] != nullptr; i += 1)
	{
		void **cliente = (void **)clientes_arr[i];
		int *dni_cliente = (int *)cliente[0];
		if (*dni_cliente == dni)
			return cliente;
	}
	return nullptr;
}

void **buscar_libro(void *reserva, char *codigo)
{
	void **reserva_arr = (void **)reserva;
	if (reserva_arr == nullptr)
		return nullptr;
	for (int i = 0; reserva_arr[i] != nullptr; i += 1)
	{
		void **libro = (void **)reserva_arr[i];
		char *codigo_libro = (char *)libro[0];
		if (strcmp(codigo_libro, codigo) == 0)
			return libro;
	}
	return nullptr;
}

void cargareserva(void *clientes, void *reserva)
{
	ifstream arch;
	AperturaDeUnArchivoDeTextosParaLeer(arch, "Pedidos2.csv");
	while (true)
	{
		char c;
		int dni;
		char codigo[8];
		arch >> dni;
		if (arch.eof())
			break;
		arch >> c;
		arch >> codigo;
		arch.get();

		void **cliente = buscar_cliente(clientes, dni);
		if (cliente == nullptr)
		{
			cerr << "[ERROR] cargareserva: no se encontro el cliente con dni " << dni << "." << endl;
			exit(1);
		}

		void **libro = buscar_libro(reserva, codigo);
		if (libro == nullptr)
		{
			cerr << "[ERROR] cargareserva: no se encontro el libro con codigo " << codigo << "." << endl;
			exit(1);
		}

		// Buscar un pedido que este libre en el arreglo de pedidos
		int *stock = (int *)libro[4];
		void **pedidos = (void **)libro[3];
		int n_pedidos = 0;
		for (; n_pedidos < *stock; n_pedidos += 1)
		{
			if (pedidos[n_pedidos] == nullptr)
			{
				break;
			}
		}
		if (n_pedidos == *stock)
		{
			cerr << "[WARNING] cargareserva: no hay mas stock para el pedido (" << codigo << ", " << dni << ")." << endl;
			continue;
		}

		// Crear un nuevo puntero para el DNI del cliente
		int *pedido_dni = new int;
		*pedido_dni = dni;

		// Crear un nuevo puntero para el nombre del cliente
		char *cliente_nombre = (char *)cliente[1];
		char *pedido_nombre = new char[strlen(cliente_nombre) + 1];
		strcpy(pedido_nombre, cliente_nombre);

		// Crear un pedido nuevo
		void **pedido = new void *[2];
		pedido[0] = (void *)pedido_dni;
		pedido[1] = (void *)pedido_nombre;

		// Guardar el pedido nuevo en el arreglo de pedidos
		pedidos[n_pedidos] = pedido;
	}
}
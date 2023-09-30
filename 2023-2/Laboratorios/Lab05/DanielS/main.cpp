
#include <iostream>
#include <fstream>

/*------------------------------------------------------------------------------
	Pila herramientas
------------------------------------------------------------------------------*/

void inicializarPila(void *&pila)
{
	double *peso_camion = new double;
	*peso_camion = 0.0;

	void **cabeza = new void *[2];
	cabeza[0] = nullptr;
	cabeza[1] = (void *)peso_camion;

	pila = (void *)cabeza;
}

void push(void *pila, void *dato)
{
	void **ultimo_nodo = (void **)pila;
	while (true)
	{
		if (ultimo_nodo[0] == nullptr)
		{
			break;
		}
		ultimo_nodo = (void **)ultimo_nodo[0];
	}

	void **nuevo_nodo = new void *[2];
	nuevo_nodo[0] = nullptr;
	nuevo_nodo[1] = dato;

	ultimo_nodo[0] = (void *)nuevo_nodo;
}

double *obtenerPesoDelCamionPtr(void *pila)
{
	void **cabeza = (void **)pila;
	double *peso_camion_ptr = (double *)cabeza[1];
	return peso_camion_ptr;
}

double obtenerPesoDelCamion(void *pila)
{
	return *obtenerPesoDelCamionPtr(pila);
}

void actualizarPesoDelCamion(void *pila, double peso_pedido)
{
	double *peso_camion_ptr = obtenerPesoDelCamionPtr(pila);
	*peso_camion_ptr += peso_pedido;
}

/*------------------------------------------------------------------------------
	cargacamiones()
------------------------------------------------------------------------------*/

void cargacamiones(void *&flota, int num_camiones, double peso_maximo, void *(leePedido)(std::ifstream &arch),
				   double(calculaPeso)(void *pedido), const char *nombre_arch)
{
	std::ifstream arch(nombre_arch, std::ios::in);
	if (not arch.is_open())
	{
		std::cerr << "Error: No se pudo abrir el archivo " << nombre_arch << "." << std::endl;
		exit(1);
	}

	void **flota_arr = new void *[num_camiones];
	for (int i = 0; i < num_camiones; i += 1)
	{
		inicializarPila(flota_arr[i]);
	}

	int n_camion = 0;
	while (true)
	{
		void *dato = leePedido(arch);
		if (dato == nullptr)
		{
			break;
		}

		double peso_camion = obtenerPesoDelCamion(flota_arr[n_camion]);
		double peso_pedido = calculaPeso(dato);

		if ((peso_camion + peso_pedido) > peso_maximo)
		{
			n_camion += 1;
			if (n_camion >= num_camiones)
			{
				break;
			}
		}
		push(flota_arr[n_camion], dato);
		actualizarPesoDelCamion(flota_arr[n_camion], peso_pedido);
	}

	flota = (void *)flota_arr;
}

/*------------------------------------------------------------------------------
	muestracamiones()
------------------------------------------------------------------------------*/

void muestracamiones(void *flota, int num_camiones, void(imprime)(std::ofstream &arch, void *dato), const char *nombre_arch)
{
	std::ofstream arch(nombre_arch, std::ios::out);
	if (not arch.is_open())
	{
		std::cerr << "Error: No se pudo abrir el archivo " << nombre_arch << "." << std::endl;
		exit(1);
	}

	arch.precision(2);

	void **flota_arr = (void **)flota;
	for (int i = 0; i < num_camiones; i += 1)
	{
		void *pila = flota_arr[i];
		arch << std::left << "Camion " << ((i <= 9) ? "0" : "") << i + 1
			 << std::setw(5) << ":"
			 << std::setw(10) << std::left << "Peso: "
			 << std::setw(10) << std::right << std::fixed << obtenerPesoDelCamion(pila) << std::endl;

		void **ultimo_nodo = (void **)((void **)pila)[0];
		while (true)
		{
			imprime(arch, ultimo_nodo[1]);
			if (ultimo_nodo[0] == nullptr)
			{
				break;
			}
			ultimo_nodo = (void **)ultimo_nodo[0];
		}
		arch << std::endl;
	}
}

/*------------------------------------------------------------------------------
	Pregunta 1
------------------------------------------------------------------------------*/

void *leenumero(std::ifstream &arch)
{
	double *peso = new double;
	arch >> *peso;
	if (arch.eof())
	{
		return nullptr;
	}
	arch >> std::ws;
	return (void *)peso;
}

double calculanumero(void *dato)
{
	double *peso = (double *)dato;
	return *peso;
}

void imprimenumero(std::ofstream &arch, void *dato)
{
	double peso = calculanumero(dato);
	arch << std::fixed << peso << std::endl;
}

int cmpnumero(const void *pila1_ptr, const void *pila2_ptr)
{
	void **pila1 = (void **)pila1_ptr;
	void **pila2 = (void **)pila2_ptr;

	double peso_camion1 = obtenerPesoDelCamion(*pila1);
	double peso_camion2 = obtenerPesoDelCamion(*pila2);
	return peso_camion2 - peso_camion1;
}

/*------------------------------------------------------------------------------
	Pregunta 2
------------------------------------------------------------------------------*/

void *leeregistro(std::ifstream &arch)
{
	char *codigo = new char[8];
	char comma;
	int *dni = new int;
	int *cantidad = new int;
	double *peso = new double;

	arch.getline(codigo, 8, ',');
	if (arch.eof())
	{
		return nullptr;
	}

	arch >> *dni >> comma >> *cantidad >> comma >> *peso >> std::ws;

	void **registro = new void *[4];
	registro[0] = (void *)codigo;
	registro[1] = (void *)dni;
	registro[2] = (void *)cantidad;
	registro[3] = (void *)peso;
	return (void *)registro;
}

double calcularegistro(void *dato)
{
	void **registro = (void **)dato;
	// int *cantidad = (int *)registro[2];
	double *peso = (double *)registro[3];
	// return *peso * *cantidad;
	return *peso;
}

void imprimeregistro(std::ofstream &arch, void *dato)
{
	void **registro = (void **)dato;
	char *codigo = (char *)registro[0];
	// int *dni = (int *)registro[1];
	int *cantidad = (int *)registro[2];
	double *peso = (double *)registro[3];
	arch << std::setw(14) << " "
		 << std::left << std::setw(15) << codigo
		 << std::right << std::setw(5) << *cantidad
		 << std::right << std::setw(10) << std::fixed << *peso
		 << std::endl;
}

/*------------------------------------------------------------------------------
	main
------------------------------------------------------------------------------*/

int main(int argc, char *argv[])
{
	int numcamiones;
	double pesomaximo;
	void *flota;

	numcamiones = 5;
	pesomaximo = 10;
	cargacamiones(flota, numcamiones, pesomaximo, leenumero, calculanumero, "numeros.txt");
	qsort(flota, numcamiones, sizeof(void *), cmpnumero);
	muestracamiones(flota, numcamiones, imprimenumero, "reportenum.txt");

	numcamiones = 100;
	pesomaximo = 400;
	cargacamiones(flota, numcamiones, pesomaximo, leeregistro, calcularegistro, "pedidos3.csv");
	qsort(flota, numcamiones, sizeof(void *), cmpnumero);
	muestracamiones(flota, numcamiones, imprimeregistro, "reporteregistro.txt");

	return 0;
}
#include "PunterosGenericos.h"

#include "MuestraPunteroGenerico.h"

int main(int argc, char *argv[])
{
	void *clientes, *reserva;

	cargaclientes(clientes);
	muestraclientes(clientes);

	creareserva(reserva);
	muestrareservas(reserva);

	cargareserva(clientes, reserva);
	reportefinal(reserva);
}
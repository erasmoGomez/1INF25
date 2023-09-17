/*	Mac OS X ARM (64-bit)

	To compile:
		clang++ -std=c++17 -stdlib=libc++ -g -fsanitize=address ./main.cpp -o ./main

	To check memory leaks:
		leaks -atExit --list -- ./main > ./leaks.txt
*/

#include <fstream>	// for ifstream, ofstream
#include <iostream> // for cout, endl
#include <cstring>	// for strlen, strcpy

char *leerProductoCodigo(std::ifstream &in)
{
	char buffer[10];
	in.get(buffer, 8);
	if (in.eof())
	{
		return nullptr;
	}
	char *codigo = new char[strlen(buffer) + 1];
	strcpy(codigo, buffer);
	char comma;
	in >> comma;
	return codigo;
}

char *leerProductoDescripcion(std::ifstream &in)
{
	constexpr int MAX_STR_SIZE = 100;
	char buffer[MAX_STR_SIZE];
	in.getline(buffer, MAX_STR_SIZE, ',');
	char *descripcion = new char[strlen(buffer) + 1];
	strcpy(descripcion, buffer);
	return descripcion;
}

double leerProductoPrecio(std::ifstream &in)
{
	double precio;
	char comma;
	in >> precio >> comma;
	return precio;
}

int leerProductoStock(std::ifstream &in)
{
	int stock;
	in >> stock >> std::ws;
	return stock;
}

char **crearProducto(char *codigo, char *descripcion)
{
	char **producto = new char *[2];
	producto[0] = codigo;
	producto[1] = descripcion;
	return producto;
}

void lecturaDeProductos(const char *filename, char ***&productos, int *&stock, double *&precios)
{
	constexpr int MAX_BUFFER_SIZE = 300;

	std::ifstream in(filename, std::ios::in);
	if (not in.is_open())
	{
		std::cerr << "Error en la apertura del archivo: " << filename << std::endl;
		exit(1);
	}

	int buffer_size = 0;
	char **buffer_productos[MAX_BUFFER_SIZE];
	double buffer_precios[MAX_BUFFER_SIZE];
	int buffer_stock[MAX_BUFFER_SIZE];

	while (true)
	{
		char *codigo = leerProductoCodigo(in);
		if (codigo == nullptr)
		{
			break;
		}

		char *descripcion = leerProductoDescripcion(in);
		double precio = leerProductoPrecio(in);
		int stock = leerProductoStock(in);

		buffer_productos[buffer_size] = crearProducto(codigo, descripcion);
		buffer_precios[buffer_size] = precio;
		buffer_stock[buffer_size] = stock;

		buffer_size += 1;
	}

	productos = new char **[buffer_size + 1];
	precios = new double[buffer_size + 1];
	stock = new int[buffer_size + 1];
	for (int i = 0; i < buffer_size; i += 1)
	{
		productos[i] = buffer_productos[i];
		precios[i] = buffer_precios[i];
		stock[i] = buffer_stock[i];
	}
	productos[buffer_size] = nullptr;
	precios[buffer_size] = -1.0f;
	stock[buffer_size] = -1;
}

void printDelimiter(std::ofstream &out, char c, int repeat)
{
	for (int i = 0; i < repeat; i += 1)
	{
		out << c;
	}
	out << std::endl;
}

void pruebaDeLecturaDeProductos(const char *filename, char ***productos, int *stock, double *precios)
{
	std::ofstream out(filename, std::ios::out);
	if (not out.is_open())
	{
		std::cerr << "Error en la apertura del archivo: " << filename << std::endl;
		exit(1);
	}

	constexpr int codigo_w = 15;
	constexpr int descripcion_w = 60;
	constexpr int stock_w = 5;
	constexpr int precio_w = 15;
	constexpr int total_w = codigo_w + descripcion_w + stock_w + precio_w;

	out << std::left
		<< std::setw(codigo_w) << "CODIGO"
		<< std::setw(descripcion_w) << "DESCRIPCION"
		<< std::right
		<< std::setw(stock_w) << "STOCK"
		<< std::setw(precio_w) << "PRECIO"
		<< std::endl;

	printDelimiter(out, '=', total_w);

	for (int i = 0; stock[i] >= 0; i += 1)
	{
		char **producto = productos[i];
		out << std::setw(codigo_w) << std::left << producto[0];
		out << std::setw(descripcion_w) << std::left << producto[1];
		out << std::setw(stock_w) << std::right << stock[i];
		out << std::setw(precio_w) << std::right << std::setprecision(2) << std::fixed << precios[i];
		out << std::endl;
	}
}

int leerPedidoDNI(std::ifstream &in)
{
	int dni;
	char comma;
	in >> dni >> comma;
	return dni;
}

int leerPedidoCantidad(std::ifstream &in)
{
	int cantidad;
	char comma;
	in >> cantidad >> comma;
	return cantidad;
}

int leerPedidoFecha(std::ifstream &in)
{
	char delim;
	int day, month, year;
	in >> day >> delim;
	in >> month >> delim;
	in >> year >> std::ws;
	return year * 10000 + month * 100 + day;
}

int posicionEnBuffer(int *buffer, int n, int x)
{
	for (int i = 0; i < n; i += 1)
	{
		if (buffer[i] == x)
		{
			return i;
		}
	}
	return -1;
}

int *crearDNICantidad(int dni, int cantidad)
{
	int *dni_cantidad_ptr = new int[2];
	dni_cantidad_ptr[0] = dni;
	dni_cantidad_ptr[1] = cantidad;
	return dni_cantidad_ptr;
}

void agregarPedido(int fecha_pos, int *buffer_fechas_ocurrencias, char ***buffer_codigos, int ***buffer_dni_cantidad, char *codigo, int dni, int cantidad)
{
	char **codigos_ptr = buffer_codigos[fecha_pos];
	int **dni_cantidades_ptr = buffer_dni_cantidad[fecha_pos];

	codigos_ptr[buffer_fechas_ocurrencias[fecha_pos]] = codigo;
	dni_cantidades_ptr[buffer_fechas_ocurrencias[fecha_pos]] = crearDNICantidad(dni, cantidad);
	buffer_fechas_ocurrencias[fecha_pos] += 1;
}

void lecturaDePedidos(const char *filename, int *&fechaPedidos, char ***&codigoPedidos, int ***&dniCantPedidos)
{
	constexpr int MAX_BUFFER_SIZE = 300;

	std::ifstream in(filename, std::ios::in);
	if (not in.is_open())
	{
		std::cerr << "Error en la apertura del archivo: " << filename << std::endl;
		exit(1);
	}

	int buffer_size = 0;
	int buffer_fechas[MAX_BUFFER_SIZE]{};
	int buffer_fechas_ocurrencias[MAX_BUFFER_SIZE]{};
	char **buffer_codigos[MAX_BUFFER_SIZE]{};
	int **buffer_dni_cantidad[MAX_BUFFER_SIZE]{};

	while (true)
	{
		char *codigo = leerProductoCodigo(in);
		if (codigo == nullptr)
		{
			break;
		}
		int dni = leerPedidoDNI(in);
		int cantidad = leerPedidoCantidad(in);
		int fecha = leerPedidoFecha(in);

		int fecha_pos = posicionEnBuffer(buffer_fechas, buffer_size, fecha);
		if (fecha_pos < 0)
		{
			buffer_fechas[buffer_size] = fecha;
			buffer_fechas_ocurrencias[buffer_size] = 0;

			buffer_codigos[buffer_size] = new char *[MAX_BUFFER_SIZE];
			buffer_dni_cantidad[buffer_size] = new int *[MAX_BUFFER_SIZE];

			fecha_pos = buffer_size;
			buffer_size += 1;
		}

		agregarPedido(fecha_pos, buffer_fechas_ocurrencias, buffer_codigos, buffer_dni_cantidad, codigo, dni, cantidad);
	}

	fechaPedidos = new int[buffer_size + 1];
	codigoPedidos = new char **[buffer_size + 1];
	dniCantPedidos = new int **[buffer_size + 1];
	for (int i = 0; i < buffer_size; i += 1)
	{
		fechaPedidos[i] = buffer_fechas[i];

		int ocurrencias = buffer_fechas_ocurrencias[i];
		codigoPedidos[i] = new char *[ocurrencias + 1];
		dniCantPedidos[i] = new int *[ocurrencias + 1];
		char **codigos_por_fecha = buffer_codigos[i];
		int **dni_cantidad_por_fecha = buffer_dni_cantidad[i];
		for (int j = 0; j < ocurrencias; j += 1)
		{
			codigoPedidos[i][j] = codigos_por_fecha[j];
			dniCantPedidos[i][j] = dni_cantidad_por_fecha[j];
		}
		codigoPedidos[i][ocurrencias] = nullptr;
		dniCantPedidos[i][ocurrencias] = nullptr;
		delete[] buffer_codigos[i];
		delete[] buffer_dni_cantidad[i];
	}
	fechaPedidos[buffer_size] = -1;
}

void imprimirFecha(std::ofstream &out, int fecha)
{
	int day = fecha % 100;
	int month = (fecha / 100) % 100;
	int year = fecha / 10000;
	out << ((day < 10) ? "0" : "") << day << '/' << ((month < 10) ? "0" : "") << month << '/' << year;
}

void pruebaDeLecturaDePedidos(const char *filename, int *fechaPedidos, char ***codigoPedidos, int ***dniCantPedidos)
{
	std::ofstream out(filename, std::ios::out);
	if (not out.is_open())
	{
		std::cerr << "Error en la apertura del archivo: " << filename << std::endl;
		exit(1);
	}

	constexpr int fecha_w = 15;
	constexpr int codigo_w = 15;
	constexpr int dni_w = 10;
	constexpr int cantidad_w = 10;
	constexpr int total_w = fecha_w + codigo_w + dni_w + cantidad_w;

	out << std::left
		<< std::setw(fecha_w) << "FECHA"
		<< std::left
		<< std::setw(codigo_w) << "CODIGO"
		<< std::right
		<< std::setw(dni_w) << "DNI"
		<< std::setw(cantidad_w) << "CANTIDAD"
		<< std::endl;

	printDelimiter(out, '=', total_w);

	for (int i = 0; fechaPedidos[i] >= 0; i += 1)
	{
		out << std::setw(fecha_w) << std::left << fechaPedidos[i];
		char **codigos = codigoPedidos[i];
		int **dniCantidades = dniCantPedidos[i];
		for (int j = 0; codigos[j] != nullptr; j += 1)
		{
			if (j != 0)
			{
				out << std::setw(fecha_w) << std::left << " ";
			}
			out << std::setw(codigo_w) << std::left << codigos[j];
			int *dniCantidad = dniCantidades[j];
			out << std::setw(dni_w) << std::right << dniCantidad[0];
			out << std::setw(cantidad_w) << std::right << dniCantidad[1];
			out << std::endl;
		}
	}
}

int buscarIndiceDeProducto(char ***productos, char *codigo)
{
	int i = 0;
	char **producto;
	while (true)
	{
		producto = productos[i];
		if (producto == nullptr)
		{
			return -1;
		}
		if (strcmp(producto[0], codigo) == 0)
		{
			break;
		}
		i += 1;
	}
	return i;
}

void reporteDeEnvioDePedidos(const char *filename, char ***productos, int *stock, double *precios, int *fechaPedidos, char ***codigoPedidos, int ***dniCantPedidos)
{
	std::ofstream out(filename, std::ios::out);
	if (not out.is_open())
	{
		std::cerr << "Error en la apertura del archivo: " << filename << std::endl;
		exit(1);
	}

	constexpr int dni_w = 20;
	constexpr int codigo_w = 9;
	constexpr int descripcion_w = 60;
	constexpr int cantidad_w = 10;
	constexpr int precio_w = 13;
	constexpr int total_ingresos_w = 20;
	constexpr int total_w = dni_w + codigo_w + descripcion_w + cantidad_w + precio_w + total_ingresos_w;

	for (int i = 0; fechaPedidos[i] > 0; i += 1)
	{
		printDelimiter(out, '=', total_w);

		out << "FECHA:  ";
		int fecha = fechaPedidos[i];
		imprimirFecha(out, fecha);
		out << std::endl;

		printDelimiter(out, '=', total_w);

		out << std::setw(dni_w) << std::left << "No.  DNI";
		out << std::setw(codigo_w + descripcion_w) << std::left << "     Producto";
		out << std::setw(cantidad_w) << std::right << "Cantidad";
		out << std::setw(precio_w) << std::right << "Precio";
		out << std::setw(total_ingresos_w) << std::right << "Total de ingresos";
		out << std::endl;

		printDelimiter(out, '-', total_w);

		char **codigos_por_fecha = codigoPedidos[i];
		int **dni_cantidades_por_fecha = dniCantPedidos[i];
		double total_ingresado = 0.0;
		double total_perdido = 0.0;
		for (int j = 0; dni_cantidades_por_fecha[j] != nullptr; j += 1)
		{
			// e.g "  1)  50375303      "
			int *dni_cantidad = dni_cantidades_por_fecha[j];
			int dni = dni_cantidad[0];
			out << std::left << " " << ((j <= 8) ? " " : "") << j + 1 << ")  " << std::setw(dni_w - 6) << dni;

			// e.g. "JXD-139  Terma Evolucion Soltu                                       "
			char *codigo = codigos_por_fecha[j];
			int producto_index = buscarIndiceDeProducto(productos, codigo);
			char *descripcion = productos[producto_index][1];
			out << std::setw(codigo_w) << std::left << codigo;
			out << std::setw(descripcion_w) << std::left << descripcion;

			// e.g. "      6   "
			int cantidad = dni_cantidad[1];
			out << std::setw(cantidad_w - 3) << std::right << cantidad << "   ";

			// e.g. "         375.09"
			double precio = precios[j];
			out << std::setw(precio_w) << std::right << precio;

			double total_de_ingresos = cantidad * precio;
			if (stock[producto_index] >= cantidad)
			{
				stock[producto_index] -= cantidad;
				total_ingresado += total_de_ingresos;
				out << std::setw(total_ingresos_w) << std::right << total_de_ingresos;
			}
			else
			{
				total_perdido += total_de_ingresos;
				out << std::setw(total_ingresos_w) << std::right << "SIN STOCK";
			}

			out << std::endl;
		}
		printDelimiter(out, '-', total_w);
		out << std::setw(total_w - 15) << std::left << "Total ingresado:"
			<< std::setw(15) << std::right << total_ingresado << std::endl;
		out << std::setw(total_w - 15) << std::left << "Total perdido por falta de stock:"
			<< std::setw(15) << std::right << total_perdido << std::endl;
	}
}

int main(int argc, char *argv[])
{
	char ***productos, ***codigoPedidos;
	int *stock, *fechaPedidos, ***dniCantPedidos;
	double *precios;

	lecturaDeProductos("./Productos.csv", productos, stock, precios);
	pruebaDeLecturaDeProductos("./ReporteDeProductos.txt", productos, stock, precios);

	lecturaDePedidos("./Pedidos.csv", fechaPedidos, codigoPedidos, dniCantPedidos);
	pruebaDeLecturaDePedidos("./ReporteDePedidos.txt", fechaPedidos, codigoPedidos, dniCantPedidos);

	reporteDeEnvioDePedidos("./ReporteDeEntregaDePedidos.txt", productos, stock, precios, fechaPedidos, codigoPedidos, dniCantPedidos);
	pruebaDeLecturaDeProductos("./ReporteDeProductosFinal.txt", productos, stock, precios);

	for (int i = 0; productos[i] != nullptr; i += 1)
	{
		char **producto = productos[i];
		char *codigo = producto[0];
		char *descripcion = producto[1];
		delete[] codigo;
		delete[] descripcion;
		delete[] producto;
	}
	delete[] productos;

	delete[] precios;
	delete[] stock;

	for (int i = 0; fechaPedidos[i] > 0; i += 1)
	{
		char **codigos_por_fecha = codigoPedidos[i];
		int **dni_cantidades = dniCantPedidos[i];
		for (int j = 0; codigos_por_fecha[j] != nullptr; j += 1)
		{
			char *codigo = codigos_por_fecha[j];
			int *dni_cantidad = dni_cantidades[j];
			delete[] codigo;
			delete[] dni_cantidad;
		}
		delete[] codigos_por_fecha;
		delete[] dni_cantidades;
	}
	delete[] codigoPedidos;
	delete[] dniCantPedidos;
	delete[] fechaPedidos;

	return 0;
}

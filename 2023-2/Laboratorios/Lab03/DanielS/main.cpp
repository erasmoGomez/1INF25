/*	Mac OS X ARM (64-bit)

	To compile:
		clang++ -std=c++17 -stdlib=libc++ -g -fsanitize=address ./main.cpp -o ./main

	To check memory leaks:
		leaks -atExit --list -- ./main > ./leaks.txt
*/

#include <fstream>	// for ifstream, ofstream
#include <iostream> // for cout, endl
#include <cstring>	// for strlen, strcpy

constexpr int MEM_INIT_SIZE = 5;
constexpr int MAX_STR_SIZE = 100;
constexpr int MEM_INCR = 5;

//------------------------------------------------------------------------------
// Utilities
//------------------------------------------------------------------------------

void imprimirDelimitador(std::ofstream &out, char c, int repeat)
{
	for (int i = 0; i < repeat; i += 1)
	{
		out << c;
	}
	out << std::endl;
}

//------------------------------------------------------------------------------
// lecturaDeProductos
//------------------------------------------------------------------------------

char *crearString(char *buffer)
{
	char *str = new char[strlen(buffer) + 1];
	strcpy(str, buffer);
	return str;
}

char *leerProductoCodigo(std::ifstream &in)
{
	char buffer[8];
	in.get(buffer, 8);
	if (in.eof())
	{
		return nullptr;
	}
	char comma;
	in >> comma;
	return crearString(buffer);
}

char *leerProductoDescripcion(std::ifstream &in)
{
	char buffer[MAX_STR_SIZE];
	in.getline(buffer, MAX_STR_SIZE, ',');
	return crearString(buffer);
}

int inicializarProductos(char ***&productos, int *&stock, double *&precios)
{
	productos = new char **[MEM_INIT_SIZE];
	stock = new int[MEM_INIT_SIZE];
	precios = new double[MEM_INIT_SIZE];

	productos[0] = nullptr;
	return MEM_INIT_SIZE;
}

void reubicarProductos(int &n_productos_max, int n_productos, char ***&productos, int *&stocks, double *&precios)
{
	n_productos_max += MEM_INCR;

	char ***productos_tmp = new char **[n_productos_max + 1];
	int *stocks_tmp = new int[n_productos_max];
	double *precios_tmp = new double[n_productos_max];
	for (int i = 0; i < n_productos; i += 1)
	{
		productos_tmp[i] = productos[i];
		stocks_tmp[i] = stocks[i];
		precios_tmp[i] = precios[i];
	}
	productos_tmp[n_productos] = nullptr;
	delete[] productos;
	delete[] stocks;
	delete[] precios;

	productos = productos_tmp;
	stocks = stocks_tmp;
	precios = precios_tmp;
}

void agregarProducto(int &n_productos_max, int &n_productos, char ***&productos, int *&stocks, double *&precios,
					 char *codigo, char *descripcion, double precio, int stock)
{
	/*
		Queremos que `n_productos` siempre sea 1 menos que `n_productos_max` ya
		que queremos setear: `productos[n_productos + 1] = nullptr;`
	*/
	if (n_productos_max - 1 == n_productos)
	{
		reubicarProductos(n_productos_max, n_productos, productos, stocks, precios);
	}

	// codigo + descripcion
	char **producto = new char *[2];
	producto[0] = codigo;
	producto[1] = descripcion;
	productos[n_productos] = producto;
	productos[n_productos + 1] = nullptr;

	// stock
	stocks[n_productos] = stock;

	// precio
	precios[n_productos] = precio;

	n_productos += 1;
}

void lecturaDeProductos(const char *filename, char ***&productos, int *&stocks, double *&precios)
{
	std::ifstream in(filename, std::ios::in);
	if (not in.is_open())
	{
		std::cerr << "Error en la apertura del archivo: " << filename << std::endl;
		exit(1);
	}
	char comma;

	int n_productos_max = inicializarProductos(productos, stocks, precios);
	int n_productos = 0;
	while (true)
	{
		char *codigo = leerProductoCodigo(in);
		if (codigo == nullptr)
		{
			break;
		}
		char *descripcion = leerProductoDescripcion(in);

		// precio
		double precio;
		in >> precio >> comma;

		// stock
		int stock;
		in >> stock >> std::ws;

		agregarProducto(n_productos_max, n_productos, productos, stocks, precios,
						codigo, descripcion, precio, stock);
	}
}

//------------------------------------------------------------------------------
// pruebaDeLecturaDeProductos
//------------------------------------------------------------------------------

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

	imprimirDelimitador(out, '=', total_w);

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

//------------------------------------------------------------------------------
// lecturaDePedidos
//------------------------------------------------------------------------------

int leerPedidoFecha(std::ifstream &in)
{
	char delim;
	int day, month, year;
	in >> day >> delim;
	in >> month >> delim;
	in >> year >> std::ws;
	return year * 10000 + month * 100 + day;
}

int posicionEnArreglo(int *buffer, int n, int x)
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

int inicializarPedidos(int *&n_pedidos_max_por_fecha, int *&n_pedidos_por_fecha, int *&fechaPedidos,
					   char ***&codigoPedidos, int ***&dniCantPedidos)
{
	n_pedidos_max_por_fecha = new int[MEM_INIT_SIZE]{};
	n_pedidos_por_fecha = new int[MEM_INIT_SIZE]{};

	fechaPedidos = new int[MEM_INIT_SIZE]{};
	codigoPedidos = new char **[MEM_INIT_SIZE];
	dniCantPedidos = new int **[MEM_INIT_SIZE];

	fechaPedidos[0] = -1;
	return MEM_INIT_SIZE;
}

void reubicarPedidos(int &n_fechas_max, int n_fechas, int *&fechaPedidos, int *&n_pedidos_max_por_fecha,
					 int *&n_pedidos_por_fecha, char ***&codigoPedidos, int ***&dniCantPedidos)
{
	n_fechas_max += MEM_INCR;

	int *fechaPedidos_tmp = new int[n_fechas_max + 1];
	char ***codigoPedidos_tmp = new char **[n_fechas_max];
	int ***dniCantPedidos_tmp = new int **[n_fechas_max];

	int *n_pedidos_max_por_fecha_tmp = new int[n_fechas_max];
	int *n_pedidos_por_fecha_tmp = new int[n_fechas_max];

	for (int i = 0; i < n_fechas; i += 1)
	{
		fechaPedidos_tmp[i] = fechaPedidos[i];
		codigoPedidos_tmp[i] = codigoPedidos[i];
		dniCantPedidos_tmp[i] = dniCantPedidos[i];

		n_pedidos_max_por_fecha_tmp[i] = n_pedidos_max_por_fecha[i];
		n_pedidos_por_fecha_tmp[i] = n_pedidos_por_fecha[i];
	}
	fechaPedidos_tmp[n_fechas] = -1;
	delete[] fechaPedidos;
	delete[] codigoPedidos;
	delete[] dniCantPedidos;

	delete[] n_pedidos_por_fecha;
	delete[] n_pedidos_max_por_fecha;

	fechaPedidos = fechaPedidos_tmp;
	codigoPedidos = codigoPedidos_tmp;
	dniCantPedidos = dniCantPedidos_tmp;

	n_pedidos_max_por_fecha = n_pedidos_max_por_fecha_tmp;
	n_pedidos_por_fecha = n_pedidos_por_fecha_tmp;
}

int agregarFecha(int *fechaPedidos, int &n_fechas, int fecha,
				 int *n_pedidos_max_por_fecha, int *n_pedidos_por_fecha, char ***codigoPedidos, int ***dniCantPedidos)
{
	/*
		Las fechas deben ser insertadas de forma ordenada.
		Para esto se sigue el siguiente algoritmo:
			1) Asumir que `fechaPedidos` está ya ordenado y tiene `n_fechas` elementos.
			2) Asumir que `fecha` no está en el arreglo `fechaPedidos` (esto se verificó antes).
			3) Empezando por la última posición, `n_fechas - 1`, recorrer el arreglo `fechaPedidos` de derecha
			   a izquierda comparando los elementos de este con `fecha`
			4) Si `fecha` es mayor que cualquiera de estas fechas, hemos encontrado la posición en la debemos introducir
			   esta fecha: `pos_fecha`.
			5) Mover todos los elementos del arreglo `fechaPedidos` un elemento hacia la derecha, a partir del elemento
			   `pos_fecha` (ojo, hacer esto de derecha a izquierda para evitar perder data). Al mismo tiempo, se debe
			   mover los arreglos `codigoPedidos` y `dniCantPedidos`
	*/

	// Ubicar la posición en la cual debemos introducir `fecha`
	int pos_fecha;
	for (pos_fecha = n_fechas; pos_fecha > 0; pos_fecha -= 1)
	{
		if (fecha > fechaPedidos[pos_fecha - 1])
		{
			break;
		}
	}

	// Moves todas las fechas (y codigos y dni/cantidades) a partir del elemento `pos_fecha + 1` hacia la derecha
	for (int j = n_fechas; j > pos_fecha; j -= 1)
	{
		fechaPedidos[j] = fechaPedidos[j - 1];

		codigoPedidos[j] = codigoPedidos[j - 1];
		dniCantPedidos[j] = dniCantPedidos[j - 1];

		n_pedidos_max_por_fecha[j] = n_pedidos_max_por_fecha[j - 1];
		n_pedidos_por_fecha[j] = n_pedidos_por_fecha[j - 1];
	}

	// Introducir la fecha en su posición
	fechaPedidos[pos_fecha] = fecha;

	fechaPedidos[n_fechas + 1] = -1;

	n_fechas += 1;
	return pos_fecha;
}

int inicializarPedidosPorFecha(char **&codigos_por_fecha, int **&dni_cantidades_por_fecha)
{
	int n_pedidos_max = MEM_INIT_SIZE;

	codigos_por_fecha = new char *[n_pedidos_max];
	dni_cantidades_por_fecha = new int *[n_pedidos_max];

	codigos_por_fecha[0] = nullptr;

	return n_pedidos_max;
}

void reubicarPedidosPorFecha(int &n_pedidos_max, int &n_pedidos, char **&codigos_por_fecha, int **&dni_cantidades_por_fecha)
{
	n_pedidos_max += MEM_INCR;

	char **codigos_por_fecha_tmp = new char *[n_pedidos_max + 1];
	int **dni_cantidades_por_fecha_tmp = new int *[n_pedidos_max];

	for (int i = 0; i < n_pedidos; i += 1)
	{
		codigos_por_fecha_tmp[i] = codigos_por_fecha[i];
		dni_cantidades_por_fecha_tmp[i] = dni_cantidades_por_fecha[i];
	}
	codigos_por_fecha_tmp[n_pedidos] = nullptr;
	delete[] codigos_por_fecha;
	delete[] dni_cantidades_por_fecha;

	codigos_por_fecha = codigos_por_fecha_tmp;
	dni_cantidades_por_fecha = dni_cantidades_por_fecha_tmp;
}

void agregarPedido(int &n_pedidos_max, int &n_pedidos, char **&codigos_por_fecha,
				   int **&dni_cantidades_por_fecha, char *codigo, int dni, int cantidad)
{
	if (n_pedidos_max - 1 == n_pedidos)
	{
		reubicarPedidosPorFecha(n_pedidos_max, n_pedidos, codigos_por_fecha, dni_cantidades_por_fecha);
	}

	codigos_por_fecha[n_pedidos] = codigo;
	codigos_por_fecha[n_pedidos + 1] = nullptr;

	int *dni_cantidad = new int[2];
	dni_cantidad[0] = dni;
	dni_cantidad[1] = cantidad;
	dni_cantidades_por_fecha[n_pedidos] = dni_cantidad;

	n_pedidos += 1;
}

void lecturaDePedidos(const char *filename, int *&fechaPedidos, char ***&codigoPedidos, int ***&dniCantPedidos)
{
	std::ifstream in(filename, std::ios::in);
	if (not in.is_open())
	{
		std::cerr << "Error en la apertura del archivo: " << filename << std::endl;
		exit(1);
	}
	char comma;

	int *n_pedidos_por_fecha;
	int *n_pedidos_max_por_fecha;
	int n_fechas_max = inicializarPedidos(n_pedidos_max_por_fecha, n_pedidos_por_fecha, fechaPedidos,
										  codigoPedidos, dniCantPedidos);
	int n_fechas = 0;
	while (true)
	{
		char *codigo = leerProductoCodigo(in);
		if (codigo == nullptr)
		{
			break;
		}

		// DNI
		int dni;
		in >> dni >> comma;

		// cantidad
		int cantidad;
		in >> cantidad >> comma;

		// fecha
		int fecha = leerPedidoFecha(in);

		int pos_fecha = posicionEnArreglo(fechaPedidos, n_fechas, fecha);
		if (pos_fecha < 0)
		{
			if (n_fechas_max - 1 == n_fechas)
			{
				reubicarPedidos(n_fechas_max, n_fechas, fechaPedidos, n_pedidos_max_por_fecha,
								n_pedidos_por_fecha, codigoPedidos, dniCantPedidos);
			}
			pos_fecha = agregarFecha(fechaPedidos, n_fechas, fecha,
									 n_pedidos_max_por_fecha, n_pedidos_por_fecha, codigoPedidos, dniCantPedidos);

			n_pedidos_max_por_fecha[pos_fecha] = inicializarPedidosPorFecha(codigoPedidos[pos_fecha], dniCantPedidos[pos_fecha]);
			n_pedidos_por_fecha[pos_fecha] = 0;
		}
		agregarPedido(n_pedidos_max_por_fecha[pos_fecha], n_pedidos_por_fecha[pos_fecha], codigoPedidos[pos_fecha],
					  dniCantPedidos[pos_fecha], codigo, dni, cantidad);
	}

	delete[] n_pedidos_por_fecha;
	delete[] n_pedidos_max_por_fecha;
}

//------------------------------------------------------------------------------
// pruebaDeLecturaDePedidos
//------------------------------------------------------------------------------

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

	imprimirDelimitador(out, '=', total_w);

	for (int i = 0; fechaPedidos[i] > 0; i += 1)
	{
		out << std::setw(fecha_w) << std::left << fechaPedidos[i];
		char **codigos_por_fecha = codigoPedidos[i];
		int **dni_cantidades_por_fecha = dniCantPedidos[i];
		for (int j = 0; codigos_por_fecha[j] != nullptr; j += 1)
		{
			if (j != 0)
			{
				out << std::setw(fecha_w) << std::left << " ";
			}
			out << std::setw(codigo_w) << std::left << codigos_por_fecha[j];
			int *dni_cantidad = dni_cantidades_por_fecha[j];
			out << std::setw(dni_w) << std::right << dni_cantidad[0];
			out << std::setw(cantidad_w) << std::right << dni_cantidad[1];
			out << std::endl;
		}
		imprimirDelimitador(out, '-', total_w);
	}
}

int buscarIndiceDeProducto(char ***productos, char *codigo)
{
	char **producto;
	for (int i = 0; productos[i] != nullptr; i += 1)
	{
		producto = productos[i];
		if (strcmp(producto[0], codigo) == 0)
		{
			return i;
		}
	}
	return -1;
}

//------------------------------------------------------------------------------
// reporteDeEnvioDePedidos
//------------------------------------------------------------------------------

void reporteDeEnvioDePedidos(const char *filename, char ***productos, int *stock, double *precios,
							 int *fechaPedidos, char ***codigoPedidos, int ***dniCantPedidos)
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

	double total_ingresos_periodo = 0.0;
	double total_perdidas_periodo = 0.0;
	for (int i = 0; fechaPedidos[i] > 0; i += 1)
	{
		imprimirDelimitador(out, '=', total_w);

		out << "FECHA:  ";
		int fecha = fechaPedidos[i];
		imprimirFecha(out, fecha);
		out << std::endl;

		imprimirDelimitador(out, '=', total_w);

		out << std::setw(dni_w) << std::left << "No.  DNI";
		out << std::setw(codigo_w + descripcion_w) << std::left << "     Producto";
		out << std::setw(cantidad_w) << std::right << "Cantidad";
		out << std::setw(precio_w) << std::right << "Precio";
		out << std::setw(total_ingresos_w) << std::right << "Total de ingresos";
		out << std::endl;

		imprimirDelimitador(out, '-', total_w);

		char **codigos_por_fecha = codigoPedidos[i];
		int **dni_cantidades_por_fecha = dniCantPedidos[i];
		double total_ingresado = 0.0;
		double total_perdido = 0.0;
		for (int j = 0; codigos_por_fecha[j] != nullptr; j += 1)
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
			double precio = precios[producto_index];
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
		imprimirDelimitador(out, '-', total_w);
		out << std::setw(total_w - 15) << std::left << "Total ingresado:"
			<< std::setw(15) << std::right << total_ingresado << std::endl;
		out << std::setw(total_w - 15) << std::left << "Total perdido por falta de stock:"
			<< std::setw(15) << std::right << total_perdido << std::endl;

		total_ingresos_periodo += total_ingresado;
		total_perdidas_periodo += total_perdido;
	}

	imprimirDelimitador(out, '=', total_w);
	out << "Resumen de ingresos:" << std::endl;
	out << "Total de ingresos en el periodo: " << std::setprecision(2) << std::fixed << total_ingresos_periodo << std::endl;
	out << "Total perdido por falta de stock: " << std::setprecision(2) << std::fixed << total_perdidas_periodo << std::endl;
}

//------------------------------------------------------------------------------
// cleanup
//------------------------------------------------------------------------------

void cleanup(char ***productos, double *precios, int *stock,
			 int *fechaPedidos, char ***codigoPedidos, int ***dniCantPedidos)
{
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
}

//------------------------------------------------------------------------------
// main
//------------------------------------------------------------------------------

int main(int argc, char *argv[])
{
	char ***productos, ***codigoPedidos;
	int *stock, *fechaPedidos, ***dniCantPedidos;
	double *precios;

	lecturaDeProductos("Productos.csv", productos, stock, precios);
	pruebaDeLecturaDeProductos("ReporteDeProductos.txt", productos, stock, precios);

	lecturaDePedidos("Pedidos.csv", fechaPedidos, codigoPedidos, dniCantPedidos);
	pruebaDeLecturaDePedidos("ReporteDePedidos.txt", fechaPedidos, codigoPedidos, dniCantPedidos);

	reporteDeEnvioDePedidos("ReporteDeEntregaDePedidos.txt", productos, stock, precios,
							fechaPedidos, codigoPedidos, dniCantPedidos);
	pruebaDeLecturaDeProductos("ReporteDeProductosFinal.txt", productos, stock, precios);

	cleanup(productos, precios, stock,
			fechaPedidos, codigoPedidos, dniCantPedidos);
	return 0;
}

#include <cstring>
#include <fstream>
#include <iostream>

const int CODIGO_LEN = 8;

/*==============================================================================
	Pedido
==============================================================================*/

class Pedido
{
public:
	Pedido()
	{
		codigo = nullptr;
		dni_cliente = -1;
		precio_producto = 0.0;
	}

	void get_codigo(char *str)
	{
		if (this->codigo == nullptr)
		{
			str = nullptr;
		}
		else
		{
			strcpy(str, this->codigo);
		}
	}

	int get_dni_cliente() const
	{
		return this->dni_cliente;
	}

	double get_precio_producto() const
	{
		return this->precio_producto;
	}

	void set_precio_producto(double precio_producto)
	{
		this->precio_producto = precio_producto;
	}

	void set_codigo(char *str)
	{
		if (this->codigo != nullptr)
		{
			delete this->codigo;
		}
		this->codigo = new char[strlen(str) + 1];
		strcpy(this->codigo, str);
	}

	void set_dni_cliente(int dni_cliente)
	{
		this->dni_cliente = dni_cliente;
	}

private:
	char *codigo;
	int dni_cliente;
	double precio_producto;
};

bool operator>>(std::ifstream &arch, class Pedido &pedido)
{
	int dni_cliente;
	char codigo[CODIGO_LEN];
	arch.getline(codigo, CODIGO_LEN, ',');
	if (arch.eof())
	{
		return false;
	}
	arch >> dni_cliente >> std::ws;

	pedido.set_codigo(codigo);
	pedido.set_dni_cliente(dni_cliente);

	return true;
}

/*==============================================================================
	ProductoEntregado
==============================================================================*/

class ProductoEntregado
{
public:
	ProductoEntregado()
	{
		codigo = nullptr;
		precio = 0.0;
	}

	void get_codigo(char *str)
	{
		if (this->codigo == nullptr)
		{
			str = nullptr;
			return;
		}
		strcpy(str, this->codigo);
	}

	void set_codigo(char *str)
	{
		if (this->codigo != nullptr)
		{
			delete this->codigo;
		}
		this->codigo = new char[strlen(str) + 1];
		strcpy(this->codigo, str);
	}

	void set_precio(double precio)
	{
		this->precio = precio;
	}

private:
	char *codigo;
	double precio;
};

/*==============================================================================
	Cliente
==============================================================================*/

const int MAX_PRODUCTOS_ENTREGADOS = 50;
const int CLIENTE_MAX_NOMBRE_SIZE = 40;

class Cliente
{
public:
	Cliente()
	{
		nombre = nullptr;
		telefono = -1;
		cantidad_productos_entregados = 0;
		monto_total = 0.0;
	}

	int get_dni() const
	{
		return this->dni;
	}

	void set_dni(int dni)
	{
		this->dni = dni;
	}

	void get_nombre(char *str)
	{
		if (this->nombre == nullptr)
		{
			str = nullptr;
			return;
		}
		strcpy(str, this->nombre);
	}

	void set_nombre(char *str)
	{
		if (this->nombre != nullptr)
		{
			delete this->nombre;
		}
		this->nombre = new char[strlen(str) + 1];
		strcpy(this->nombre, str);
	}

	int get_telefono() const
	{
		return this->telefono;
	}

	void set_telefono(int telefono)
	{
		this->telefono = telefono;
	}

	double get_monto_total() const
	{
		return this->monto_total;
	}

	int get_cantidad_productos_entregados() const
	{
		return this->cantidad_productos_entregados;
	}

	class ProductoEntregado &get_producto_entregado(int i)
	{
		return this->productos_entregados[i];
	}

	void operator+=(class Pedido &pedido)
	{
		char codigo[CODIGO_LEN];
		pedido.get_codigo(codigo);

		class ProductoEntregado &producto_entregado = this->get_producto_entregado(this->cantidad_productos_entregados);
		producto_entregado.set_codigo(codigo);

		double precio = pedido.get_precio_producto();
		producto_entregado.set_precio(precio);

		this->monto_total += precio;
		this->cantidad_productos_entregados += 1;
	}

private:
	int dni;
	char *nombre;
	int telefono;
	class ProductoEntregado productos_entregados[MAX_PRODUCTOS_ENTREGADOS]{};
	int cantidad_productos_entregados;
	double monto_total;
};

bool operator>>(std::ifstream &arch, class Cliente &cliente)
{
	int dni, telefono;
	char nombre[CLIENTE_MAX_NOMBRE_SIZE];
	char c;
	arch >> dni;
	if (arch.eof())
	{
		return false;
	}
	arch >> c;
	arch.getline(nombre, CLIENTE_MAX_NOMBRE_SIZE, ',');
	arch >> telefono >> std::ws;

	cliente.set_dni(dni);
	cliente.set_nombre(nombre);
	cliente.set_telefono(telefono);

	return true;
}

void operator<<(std::ofstream &arch, class Cliente &cliente)
{
	char nombre[CLIENTE_MAX_NOMBRE_SIZE];
	cliente.get_nombre(nombre);

	arch << std::right << std::setw(10) << cliente.get_dni();
	arch << ' ';
	arch << std::left << std::setw(CLIENTE_MAX_NOMBRE_SIZE) << nombre;
	arch << ' ';
	arch << std::right << std::setw(10) << cliente.get_telefono();
	arch << ' ';
	arch << std::right << std::setw(15) << cliente.get_monto_total();
	arch << std::endl;
	arch << std::left << std::setw(20) << "Productos entregados: ";
	if (cliente.get_cantidad_productos_entregados() == 0)
	{
		arch << "NO SE LE ENTREGARON PRODUCTOS" << std::endl;
		return;
	}
	char codigo[CODIGO_LEN];
	for (int i = 0; i < cliente.get_cantidad_productos_entregados(); i += 1)
	{
		cliente.get_producto_entregado(i).get_codigo(codigo);
		arch << std::right << std::setw(10) << codigo;
		arch << ' ';
	}
	arch << std::endl;
}

/*==============================================================================
	Producto
==============================================================================*/

const int MAX_CLIENTES_SERVIDOS = 50;
const int PRODUCTO_MAX_DESCRIPCION_SIZE = 60;

class Producto
{
public:
	Producto()
	{
		codigo = nullptr;
		descripcion = nullptr;
		precio = 0.0;
		stock = 0;
		cantidad_clientes_servidos = 0;
		cantidad_clientes_no_servidos = 0;
	}

	void get_codigo(char *str)
	{
		if (this->codigo == nullptr)
		{
			str = nullptr;
		}
		else
		{
			strcpy(str, this->codigo);
		}
	}

	void set_codigo(char *str)
	{
		if (this->codigo != nullptr)
		{
			delete this->codigo;
		}
		this->codigo = new char[strlen(str) + 1];
		strcpy(this->codigo, str);
	}

	void get_descripcion(char *str)
	{
		if (this->descripcion == nullptr)
		{
			str = nullptr;
		}
		else
		{
			strcpy(str, this->descripcion);
		}
	}

	void set_descripcion(char *str)
	{
		if (this->descripcion != nullptr)
		{
			delete this->descripcion;
		}
		this->descripcion = new char[strlen(str) + 1];
		strcpy(this->descripcion, str);
	}

	double get_precio() const
	{
		return this->precio;
	}

	void set_precio(double precio)
	{
		this->precio = precio;
	}

	int get_stock() const
	{
		return this->stock;
	}

	void set_stock(int stock)
	{
		this->stock = stock;
	}

	int get_cantidad_clientes_servidos() const
	{
		return this->cantidad_clientes_servidos;
	}

	int get_cantidad_clientes_no_servidos() const
	{
		return this->cantidad_clientes_no_servidos;
	}

	int get_clientes_servidos(int i) const
	{
		return this->clientes_servidos[i];
	}

	int get_clientes_no_servidos(int i) const
	{
		return this->clientes_no_servidos[i];
	}

	bool operator+=(class Pedido &pedido)
	{
		pedido.set_precio_producto(this->precio);
		int dni = pedido.get_dni_cliente();
		if (this->stock > 0)
		{
			this->clientes_servidos[this->cantidad_clientes_servidos] = dni;
			this->cantidad_clientes_servidos += 1;
			this->stock -= 1;
			return true;
		}
		else
		{
			this->clientes_no_servidos[this->cantidad_clientes_no_servidos] = dni;
			this->cantidad_clientes_no_servidos += 1;
			return false;
		}
	}

private:
	char *codigo;
	char *descripcion;
	double precio;
	int stock;
	int clientes_servidos[MAX_CLIENTES_SERVIDOS]{};
	int clientes_no_servidos[MAX_CLIENTES_SERVIDOS]{};
	int cantidad_clientes_servidos;
	int cantidad_clientes_no_servidos;
};

bool operator>>(std::ifstream &arch, class Producto &producto)
{
	double precio;
	int stock;
	char codigo[CODIGO_LEN];
	char descripcion[PRODUCTO_MAX_DESCRIPCION_SIZE];
	char c;

	arch.getline(codigo, CODIGO_LEN, ',');
	if (arch.eof())
	{
		return false;
	}
	arch.getline(descripcion, PRODUCTO_MAX_DESCRIPCION_SIZE, ',');
	arch >> precio >> c >> stock >> std::ws;

	producto.set_codigo(codigo);
	producto.set_descripcion(descripcion);
	producto.set_precio(precio);
	producto.set_stock(stock);

	return true;
}

bool operator<<(std::ofstream &arch, class Producto &producto)
{
	char codigo[CODIGO_LEN];
	producto.get_codigo(codigo);

	char descripcion[PRODUCTO_MAX_DESCRIPCION_SIZE];
	producto.get_descripcion(descripcion);

	arch << std::left << std::setw(15) << codigo;
	arch << std::left << std::setw(PRODUCTO_MAX_DESCRIPCION_SIZE) << descripcion;
	arch << std::right << std::setw(7) << producto.get_precio();
	arch << std::right << std::setw(7) << producto.get_stock() << std::endl;
	arch << std::endl;
	arch << std::left << std::setw(20) << "Clientes atendidos: ";
	if (producto.get_cantidad_clientes_servidos() == 0)
	{
		arch << std::right << "NO SE ATENDIERON PRODUCTOS" << std::endl;
	}
	else
	{
		for (int i = 0; i < producto.get_cantidad_clientes_servidos(); i += 1)
		{
			arch << std::right << std::setw(10) << producto.get_clientes_servidos(i);
		}
		arch << std::endl;
	}
	arch << std::right << std::setw(20) << "Clientes no atendidos: ";
	if (producto.get_cantidad_clientes_no_servidos() == 0)
	{
		arch << std::right << "NO HAY CLIENTES SIN ATENDER" << std::endl;
	}
	else
	{
		for (int i = 0; i < producto.get_cantidad_clientes_no_servidos(); i += 1)
		{
			arch << std::right << std::setw(10) << producto.get_clientes_no_servidos(i);
		}
		arch << std::endl;
	}
	return true;
}

/*==============================================================================
	Almacen
==============================================================================*/

const int ALMACEN_MAX_CLIENTES = 200;
const int ALMACEN_MAX_PRODUCTOS = 200;

class Almacen
{
public:
	Almacen()
	{
		cantidad_clientes = 0;
		cantidad_productos = 0;
	}

	int busca_producto(char *codigo)
	{
		char codigo_prod[CODIGO_LEN];
		for (int i = 0; i < this->cantidad_productos; i += 1)
		{
			class Producto producto = this->arreglo_productos[i];
			producto.get_codigo(codigo_prod);
			if (!strcmp(codigo, codigo_prod))
			{
				return i;
			}
		}
		return -1;
	}

	int busca_cliente(int dni)
	{
		for (int i = 0; i < this->cantidad_productos; i += 1)
		{
			class Cliente cliente = this->arreglo_clientes[i];
			if (dni == cliente.get_dni())
			{
				return i;
			}
		}
		return -1;
	}

	void cargar_clientes()
	{
		std::ifstream arch("Clientes.csv", std::ios::in);
		if (not arch.is_open())
		{
			std::cerr << "Error: No se pudo abrir el archivo Clientes.csv." << std::endl;
			exit(1);
		}

		while (true)
		{
			if (not(arch >> this->arreglo_clientes[this->cantidad_clientes]))
			{
				break;
			}
			this->cantidad_clientes += 1;
		}
	}

	void cargar_productos()
	{
		std::ifstream arch("Productos.csv", std::ios::in);
		if (not arch.is_open())
		{
			std::cerr << "Error: No se pudo abrir el archivo Productos.csv." << std::endl;
			exit(1);
		}

		while (true)
		{
			if (not(arch >> this->arreglo_productos[this->cantidad_productos]))
			{
				break;
			}
			this->cantidad_productos += 1;
		}
	}

	void cargar_pedidos()
	{
		std::ifstream arch("Pedidos.csv", std::ios::in);
		if (not arch.is_open())
		{
			std::cerr << "Error: No se pudo abrir el archivo Pedidos.csv." << std::endl;
			exit(1);
		}

		while (true)
		{
			class Pedido pedido = Pedido{};
			if (not(arch >> pedido))
			{
				break;
			}
			char codigo[CODIGO_LEN];
			pedido.get_codigo(codigo);

			int prod_i = busca_producto(codigo);
			this->arreglo_productos[prod_i] += pedido;

			int cli_i = busca_cliente(pedido.get_dni_cliente());
			this->arreglo_clientes[cli_i] += pedido;
		}
	}

	void print_header(std::ofstream &arch, int size, char ch)
	{
		for (int i = 0; i < size; i += 1)
		{
			arch << ch;
		}
		arch << std::endl;
	}

	void reporte_productos(std::ofstream &arch)
	{
		const int LINE_SIZE = 90;

		arch << std::setw(50) << "REPORTE PRODUCTOS" << std::endl;

		this->print_header(arch, LINE_SIZE, '=');
		arch << std::left << std::setw(15) << "CODIGO"
			 << std::setw(PRODUCTO_MAX_DESCRIPCION_SIZE) << "DESCRIPCION"
			 << std::right << std::setw(7) << "PRECIO"
			 << std::right << std::setw(7) << "STOCK"
			 << std::endl;
		this->print_header(arch, LINE_SIZE, '=');
		for (int i = 0; i < this->cantidad_productos; i += 1)
		{
			arch << this->arreglo_productos[i];
			this->print_header(arch, LINE_SIZE, '-');
		}
	}

	void reporte_clientes(std::ofstream &arch)
	{
		const int LINE_SIZE = 120;

		arch << std::setw(50) << "REPORTE CLIENTES" << std::endl;

		this->print_header(arch, LINE_SIZE, '=');
		arch << std::right << std::setw(10) << "DNI";
		arch << ' ';
		arch << std::left << std::setw(CLIENTE_MAX_NOMBRE_SIZE) << "NOMBRE";
		arch << ' ';
		arch << std::right << std::setw(10) << "TELEFONO";
		arch << ' ';
		arch << std::right << std::setw(15) << "MONTO TOTAL";
		arch << std::endl;
		this->print_header(arch, LINE_SIZE, '=');
		for (int i = 0; i < this->cantidad_clientes; i += 1)
		{
			arch << this->arreglo_clientes[i];
			this->print_header(arch, LINE_SIZE, '-');
		}
	}

	void mostrar_datos()
	{
		std::ofstream arch("Reporte.txt", std::ios::out);
		if (not arch.is_open())
		{
			std::cerr << "Error: No se pudo abrir el archivo Reporte.txt." << std::endl;
			exit(1);
		}

		this->reporte_productos(arch);
		arch << std::endl;
		this->reporte_clientes(arch);
		arch << std::endl;
	}

private:
	class Cliente arreglo_clientes[ALMACEN_MAX_CLIENTES]{};
	int cantidad_clientes;
	class Producto arreglo_productos[ALMACEN_MAX_PRODUCTOS]{};
	int cantidad_productos;
};

/*==============================================================================
	main
==============================================================================*/

int main(int argc, char *argv[])
{
	class Almacen almacen;

	almacen.cargar_clientes();
	almacen.cargar_productos();
	almacen.cargar_pedidos();
	almacen.mostrar_datos();
	return 0;
}

#include "Libraries/Controller/Sales.hpp"

int main(int argc, char **argv) {
    char ***sales = nullptr;
    char ****sales_details_text = nullptr;
    int ***sales_details_values = nullptr;

    load_sales("DataFiles/Ventas.csv", sales);
    print_report("ReportFiles/ReporteVentas.csv", sales,
                 sales_details_text, sales_details_values);

    load_sales_details("DataFiles/DetalleVentas.csv", sales,
                       sales_details_text, sales_details_values);
    print_report("ReportFiles/ReporteVentasConDetalles.csv", sales,
                 sales_details_text, sales_details_values);

    load_product_details("DataFiles/Productos.csv", sales,
                         sales_details_text, sales_details_values);
    print_report("ReportFiles/ReporteVentasConDetallesProductos.csv", sales,
                 sales_details_text, sales_details_values);

    return 0;
}

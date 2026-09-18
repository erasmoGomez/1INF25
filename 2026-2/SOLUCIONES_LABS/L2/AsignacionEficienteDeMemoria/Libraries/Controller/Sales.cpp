//
// Created by erasmo on 9/17/26.
//
#include "Sales.hpp"

void load_sales(const char *filename, char ***&sales) {
    char **buffer_sales[MAX_SALES]{};
    int num_data = 0;
    ifstream input_file; open_file_read(input_file, filename);

    while (true) {
        buffer_sales[num_data] = read_sale(input_file);
        if (input_file.eof()) break;
        num_data++;
    }

    sales = new char **[num_data + 1]{};
    for (int i = 0; i < num_data; i++) {
        sales[i] = buffer_sales[i];
    }
}

char **read_sale(ifstream &input_file) {
    char *sale_code = read_str(input_file, ',');
    if (input_file.eof()) return nullptr;

    char **sale = new char *[4];
    sale[SALE_CODE] = sale_code;
    sale[CLIENT_CODE] = read_str(input_file, ',');
    sale[SALE_DATE] = read_str(input_file, ',');
    sale[CHANNEL] = read_str(input_file);

    return sale;
}

void process_sale_detail(ifstream &input_file, int position,
                         char ****sales_details_text,
                         int ***sales_details_values,
                         int *num_data, int *capacity) {
    if (num_data[position] == capacity[position]) {
        increase_capacity(sales_details_text[position],
                          sales_details_values[position],
                          num_data[position], capacity[position]);
    }

    add_detail(input_file, sales_details_text[position],
               sales_details_values[position], num_data[position]);
}

void load_sales_details(const char *filename, char ***sales,
                        char ****&sales_details_text,
                        int ***&sales_details_values) {
    ifstream input_file; open_file_read(input_file, filename);

    int num_sales = 0, num_data[150]{}, capacity[150]{};
    char sale_code[7];

    while (sales[num_sales]) num_sales++;

    //Reserva a primer Nivel
    sales_details_text = new char ***[num_sales + 1]{};
    sales_details_values = new int **[num_sales + 1]{};

    while (true) {
        input_file.getline(sale_code, 7, ',');
        if (input_file.eof()) break;

        int position = search_sale(sale_code, sales);
        if (position != NOT_FOUND) {
            process_sale_detail(input_file, position,
                                sales_details_text, sales_details_values,
                                num_data, capacity);
        }
    }
}

int search_sale(const char *sale_code, char ***sales) {
    for (int i = 0; sales[i]; i++) {
        if (are_equal(sale_code, sales[i])) return i;
    }
    return NOT_FOUND;
}

bool are_equal(const char *sale_code, char **sale) {
    return strcmp(sale_code, sale[SALE_CODE]) == 0;
}

void increase_capacity(char ***&sales_details_text,
                       int **&sales_details_values,
                       int &num_data, int &capacity) {
    capacity += INCREMENT;

    if (sales_details_text == nullptr) {
        sales_details_text = new char **[capacity]{};
        sales_details_values = new int *[capacity]{};
        num_data = 1;
    } else {
        char ***aux_text = new char **[capacity]{};
        int **aux_values = new int *[capacity]{};

        for (int i = 0; i < num_data; i++) {
            aux_text[i] = sales_details_text[i];
            aux_values[i] = sales_details_values[i];
        }

        delete[] sales_details_text;
        delete[] sales_details_values;
        sales_details_text = aux_text;
        sales_details_values = aux_values;
    }
}

void add_detail(ifstream &input_file, char ***sales_details_text,
                int **sales_details_values, int &num_data) {
    char **sale_detail_text = new char *[4]{};
    int *sale_detail_values = new int[5]{};
    //V00045,P0050,PAQ20,20,1,13%
    sale_detail_text[0] = read_str(input_file, ',');
    sale_detail_text[1] = read_str(input_file, ',');

    sale_detail_values[0] = read_int(input_file, true);
    sale_detail_values[1] = read_int(input_file, true);
    sale_detail_values[2] = read_int(input_file, true);
    input_file.get(); //r
    input_file.get(); //n

    sales_details_text[num_data - 1] = sale_detail_text;
    sales_details_values[num_data - 1] = sale_detail_values;
    num_data++;
}

void load_product_details(const char *filename, char ***sales,
                          char ****sales_details_text,
                          int ***sales_details_values) {
    ifstream input_file; open_file_read(input_file, filename);

    //P0001,Avena Pacifico Tipo 17,ABARROTES,22,25
    while (true) {
        char *product_code = read_str(input_file, ',');
        if (input_file.eof()) break;

        char *description = read_str(input_file, ',');
        char *category = read_str(input_file, ',');
        int unit_cost = read_int(input_file, true);
        int unit_price = read_int(input_file, false);
        input_file.get();//r
        input_file.get();//n

        for (int i = 0; sales[i]; i++) {
            complete_sale(sales_details_text[i], sales_details_values[i],
                          product_code, description, category,
                          unit_cost, unit_price);
        }
    }
}

void complete_sale(char ***sales_details_text,
                   int **sales_details_values,
                   const char *product_code, char *description, char *category,
                   int unit_cost, int unit_price) {
    for (int i = 0; sales_details_text[i]; i++) {
        verify_and_assign(sales_details_text[i], sales_details_values[i],
                          product_code, description, category,
                          unit_cost, unit_price);
    }
}

void verify_and_assign(char **sale_detail_text,
                       int *sale_detail_values,
                       const char *product_code, char *description, char *category,
                       int unit_cost, int unit_price) {
    if (strcmp(product_code, sale_detail_text[0]) == 0) {
        sale_detail_text[2] = description;
        sale_detail_text[3] = category;
        sale_detail_values[3] = unit_cost;
        sale_detail_values[4] = unit_price;
    }
}

void calculate_totals(double &total_cost, double &total_price,
                      double &total_profit, int **sales_details_values) {
    for (int i = 0; sales_details_values[i]; i++) {
        total_cost += calculate_cost(sales_details_values[i]);
        total_price += calculate_price(sales_details_values[i]);
    }
}

double calculate_cost(const int *sale_detail_values) {
    return sale_detail_values[3];
}

double calculate_price(const int *sale_detail_values) {
    return sale_detail_values[4];
}

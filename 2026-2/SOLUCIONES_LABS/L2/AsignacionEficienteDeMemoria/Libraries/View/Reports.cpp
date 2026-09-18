//
// Created by erasmo on 9/17/26.
//
#include "../Controller/Sales.hpp"
#include "Reports.hpp"


void print_headers(ofstream &output, const char **headers) {
    int column_width = REPORT_WIDTH / N_COLUMNS;

    for (int i = 0; i < N_COLUMNS; i++)
        output << setw(column_width) << left << headers[i];

    output << endl;
}

void print_totals(ofstream &output_file, const double total_cost, const double total_price) {
    output_file.precision(2);
    output_file << fixed;
    output_file << "=================" << endl;
    output_file << "Total Cost:   " << setw(10) << total_cost << endl;
    output_file << "Total Price:  " << setw(10) << total_price << endl;
    output_file << "Total Profit: " << setw(10)
            << total_price - total_cost << endl;
    output_file << "=================" << endl;
}

void print_report(const char *filename, char ***sales,
                  char ****sales_details_text,
                  int ***sales_details_values) {
    ofstream output_file;
    open_file_write(output_file, filename);
    const char *headers[4] = {"SALE CODE", "CLIENT CODE", "SALE DATE", "SALE CHANNEL"};
    output_file << left << setw(3) << "";
    print_headers(output_file, headers);

    for (int i = 0; sales[i]; i++) {
        output_file << left << i + 1 << ") ";
        print_sale(output_file, sales[i]);

        if (sales_details_text != nullptr) {
            print_sale_details(output_file, sales_details_text[i],
                               sales_details_values[i]);

            double total_cost = 0.0, total_price = 0.0, total_profit = 0.0;

            calculate_totals(total_cost, total_price, total_profit,
                             sales_details_values[i]);

            print_totals(output_file, total_cost, total_price);
        }
    }
}

void print_sale(ofstream &output_file, char **sale) {
    int column_width = REPORT_WIDTH / N_COLUMNS;
    output_file << left
            << setw(column_width) << sale[SALE_CODE]
            << setw(column_width) << sale[CLIENT_CODE]
            << setw(column_width) << sale[SALE_DATE]
            << setw(column_width) << sale[CHANNEL]
            << endl;
}

void print_sale_details(ofstream &output_file, char ***sales_details_text,
                        int **sales_details_values) {
    output_file << "PURCHASED PRODUCTS" << endl;
    output_file << left << setw(9) << "CODE"
            << setw(30) << "DESCRIPTION"
            << setw(14) << "PRESENTATION"
            << setw(11) << "CATEGORY"
            << setw(13) << "UNITS/PRES"
            << setw(10) << "QUANTITY"
            << setw(13) << "UNIT COST"
            << setw(15) << "UNIT PRICE"
            << "DISCOUNT" << endl;

    for (int i = 0; sales_details_text[i]; i++) {
        print_detail(output_file, sales_details_text[i],
                     sales_details_values[i]);
    }
}

void print_detail(ofstream &output_file,
                  char **sale_detail_text,
                  const int *sale_detail_values) {
    output_file << left << setw(9) << sale_detail_text[0];

    if (sale_detail_text[2] != nullptr)
        output_file << setw(33) << sale_detail_text[2];
    else
        output_file << setw(33) << ' ';

    output_file << setw(14) << sale_detail_text[0];

    if (sale_detail_text[3] != nullptr)
        output_file << setw(11) << sale_detail_text[3];
    else
        output_file << setw(11) << ' ';

    output_file << right << setw(5) << sale_detail_values[0]
            << setw(10) << sale_detail_values[1];

    if (sale_detail_values[3] != 0)
        output_file << setw(13) << sale_detail_values[3]
                << setw(13) << sale_detail_values[4];
    else
        output_file << setw(13) << ' ' << setw(13) << ' ';

    output_file << setw(13) << sale_detail_values[2] << '%' << endl;
}

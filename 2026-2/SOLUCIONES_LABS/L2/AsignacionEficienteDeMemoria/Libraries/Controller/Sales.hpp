//
// Created by erasmo on 9/17/26.
//

#ifndef ASIGNACIONEFICIENTEDEMEMORIA_SALES_HPP
#define ASIGNACIONEFICIENTEDEMEMORIA_SALES_HPP
#include "../View/Reports.hpp"

void load_sales(const char *filename, char ***&sales);

char **read_sale(ifstream &input_file);

void load_sales_details(const char *filename, char ***sales,
                        char ****&sales_details_text,
                        int ***&sales_details_values);

int search_sale(const char *sale_code, char ***sales);

bool are_equal(const char *sale_code, char **sale);

void increase_capacity(char ***&sales_details_text,
                       int **&sales_details_values,
                       int &num_data, int &capacity);

void add_detail(ifstream &input_file, char ***sales_details_text,
                int **sales_details_values, int &num_data);

void load_product_details(const char *filename, char ***sales,
                          char ****sales_details_text,
                          int ***sales_details_values);

void complete_sale(char ***sales_details_text,
                   int **sales_details_values,
                   const char *product_code, char *description, char *category,
                   int unit_cost, int unit_price);

void verify_and_assign(char **sale_detail_text,
                       int *sale_detail_values,
                       const char *product_code, char *description, char *category,
                       int unit_cost, int unit_price);

void calculate_totals(double &total_cost, double &total_price,
                      double &total_profit, int **sales_details_values);

double calculate_cost(const int *sale_detail_values);

double calculate_price(const int *sale_detail_values);
#endif //ASIGNACIONEFICIENTEDEMEMORIA_SALES_HPP

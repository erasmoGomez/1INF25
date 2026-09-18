//
// Created by erasmo on 9/17/26.
//

#ifndef ASIGNACIONEFICIENTEDEMEMORIA_REPORTS_HPP
#define ASIGNACIONEFICIENTEDEMEMORIA_REPORTS_HPP
#include "../Utilities/AuxiliaryFunctions.hpp"
void print_report(const char *filename, char ***sales,
                  char ****sales_details_text,
                  int ***sales_details_values);
void print_sale(ofstream &output_file, char **sale);
void print_sale_details(ofstream &output_file, char ***sales_details_text,
                        int **sales_details_values);
void print_detail(ofstream &output_file, char **sale_detail_text,
                  const int *sale_detail_values);
#endif //ASIGNACIONEFICIENTEDEMEMORIA_REPORTS_HPP
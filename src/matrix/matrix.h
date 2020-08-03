#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <stdlib.h>
#include <vector>
#include "matrix_line.h"
#include "matrix_item.h"

namespace matrix
{
    class Matrix
    {
    public:
        const std::string tab = "\t\t\t\t\t\t";
        Matrix();
        ~Matrix();
        void set_target_to_after_end();
        bool equality_between_matrices(Matrix *matrix);
        void sum_of_two_matrix(Matrix *matrix);
        void difference_between_matrices(Matrix *matrix);
        Matrix *multiply_by_constant(const int constant);
        Matrix *multiply_by_matrix(Matrix *matrix);
        Matrix *transposed_matrix();
        bool is_inverse(Matrix *matrix);
        bool is_matrix_n(int n = 1);
        bool is_symmetric_matrix();
        bool is_anti_symmetric_matrix();
        Matrix(int linesQuantity, int columnsQuantity);
        void add_line(matrix::MatrixLine *line);
        int get_lines_quantity();
        int get_columns_quantity();
        int get_current_targed_line();
        void set_current_targed_line(int value);
        int get_current_targed_column();
        void set_current_targed_column(int value);
        bool is_square_matrix();
        matrix::MatrixItem *get_item(int line, int column);
        void set_item(int line, int column, int value);
        void add_item_matrix(const int data);
        void print_matrix(bool skipOption = false);
        bool is_in_last_position();
        void set_to_equal_to(Matrix *matchMatrix);
        void set_matrix();

    private:
        std::vector<matrix::MatrixLine *> *lines;
        int linesQuantity;
        int columnsQuantity;
        int currentTargedLine;
        int currentTargedColumn;
    };

} // namespace matrix

#endif
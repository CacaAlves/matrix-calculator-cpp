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

        Matrix();
        Matrix(int linesQuantity, int columnsQuantity);
        ~Matrix();
        void add_line(matrix::MatrixLine *line);
        int get_lines_quantity();
        int get_columns_quantity();
        int get_current_targed_line();
        void set_current_targed_line(int value);
        int get_current_targed_column();
        void set_current_targed_column(int value);
        bool is_square_matrix();
        matrix::MatrixItem *get_item(int line, int column);
        void add_item_matrix(const int data);
        void print_matrix();
        bool is_in_last_position();
    private:
        std::vector<matrix::MatrixLine *> *lines;
        int linesQuantity;
        int columnsQuantity;
        int currentTargedLine;
        int currentTargedColumn;
    };

} // namespace matrix

#endif
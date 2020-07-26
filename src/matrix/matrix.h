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
        std::vector<MatrixLine *> lines;
        int currentLine;
        int currentColumn;

        Matrix();
        Matrix(int linesQuantity, int columnsQuantity);
        ~Matrix();
        int get_lines_quantity();
        int get_columns_quantity();
        bool is_square_matrix();
        MatrixItem *get_item(int line, int column);
        void print_matrix();
    private:
        int linesQuantity;
        int columnsQuantity;
    };

} // namespace matrix

#endif
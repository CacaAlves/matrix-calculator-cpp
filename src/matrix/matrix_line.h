#ifndef MATRIX_LINE
#define MATRIX_LINE

#include <iostream>
#include <vector>
#include "matrix_item.h"

namespace matrix
{

    class MatrixLine
    {
    public:


        MatrixLine();
        ~MatrixLine();
        void add_element(int value);
        void set_element(int value, int index);
        matrix::MatrixItem *get_element(int index);
        int get_columns_quantity();
        
    private:
        std::vector<matrix::MatrixItem *> *line;
    };

} // namespace matrix

#endif

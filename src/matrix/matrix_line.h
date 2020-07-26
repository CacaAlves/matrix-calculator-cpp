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

        std::vector<MatrixItem *> line;

        MatrixLine();
        ~MatrixLine();
        void add_element(int value);
        void set_element(int value, int index);
        MatrixItem *get_element(int index);
        
    private:
    };

} // namespace matrix

#endif

#ifndef MATRIX_ITEM
#define MATRIX_ITEM

#include <iostream>

namespace matrix
{
    class MatrixItem
    {
        public:
            MatrixItem();
            MatrixItem(int data);
            ~MatrixItem();
            void set_data(int data);
            int get_data();
        private:
            int data;
    };
}

#endif
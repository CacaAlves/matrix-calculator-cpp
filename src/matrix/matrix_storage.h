#ifndef MATRIX_STORAGE
#define MATRIX_STORAGE

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <list>
#include "matrix.h"

namespace matrix
{

    struct MatrixStorage
    {
    public:
        std::list<int> *items;
        MatrixStorage();
        ~MatrixStorage();
        void set_matrix_storage(matrix::Matrix *matrixToStore);
        void set_file_name(std::string fileName);
        bool store_in_hard_disk();
        matrix::Matrix *read_from_hard_disk();
        void delete_from_hard_disk();

    private:
        std::string fileName;
        int linesQuantity;
        int columnsQuantity;
    };

} // namespace matrix
#endif
#ifndef MATRIX_STORAGE
#define MATRIX_STORAGE

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <list>
#include "matrix.h"

namespace matrix
{

    class MatrixStorage
    {
    public:
        std::list<int> *items;
        MatrixStorage();
        ~MatrixStorage();
        void set_matrix_storage(matrix::Matrix *matrixToStore);
        void set_file_name(std::string fileName);
        bool store_in_hard_disk();
        static matrix::Matrix *read_from_hard_disk(std::string fileName);
        static void delete_from_hard_disk(std::string fileName);

    private:
        std::string fileName;
        int linesQuantity;
        int columnsQuantity;
    };

} // namespace matrix
#endif
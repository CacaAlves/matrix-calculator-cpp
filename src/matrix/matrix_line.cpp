#include "matrix_line.h"

matrix::MatrixLine::MatrixLine()
{
    (this->line) = new std::vector<matrix::MatrixItem *>();
}

matrix::MatrixLine::~MatrixLine()
{
    for (matrix::MatrixItem *item : *(this->line))
    {
        delete item;
    }
    delete (this->line);
    std::cout << "Line destructed\n";
}

void matrix::MatrixLine::add_element(int value)
{
    matrix::MatrixItem *item = new matrix::MatrixItem(value);
    (this->line)->push_back(item);
}

void matrix::MatrixLine::set_element(int value, int index)
{
    if (index < (this->line)->size())
    {
        matrix::MatrixItem *item = new matrix::MatrixItem(value);
        (*this->line)[index] = item;
    }
    else
    {
        std::cout << "Trying to insert in a invalid position\n";
    }
}

matrix::MatrixItem *matrix::MatrixLine::get_element(int index)
{
    return (*this->line)[index];
}

int matrix::MatrixLine::get_columns_quantity()
{
    return (this->line)->size();
}
#include "matrix_line.h"

matrix::MatrixLine::MatrixLine() {}

matrix::MatrixLine::~MatrixLine()
{
    for (MatrixItem *item : this->line)
    {
        delete item;
    }
    std::cout << "Line destructed\n";
}

void matrix::MatrixLine::add_element(int value)
{
    MatrixItem *item = new MatrixItem(value);
    (this->line).push_back(item);
}

void matrix::MatrixLine::set_element(int value, int index)
{
    if (index < this->line.size())
    {
        MatrixItem *item = new MatrixItem(value);
        (this->line)[index] = item;
    }
    else
    {
        std::cout << "Trying to insert in a invalid position\n";
    }
}

matrix::MatrixItem *matrix::MatrixLine::get_element(int index)
{
    return (this->line)[index];
}

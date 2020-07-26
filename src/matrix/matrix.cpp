#include "matrix.h"

matrix::Matrix::Matrix()
{
    this->currentLine = 0;
    this->currentColumn = 0;
}

matrix::Matrix::Matrix(int linesQuantity, int columnsQuantity)
{
    this->linesQuantity = linesQuantity;
    this->columnsQuantity = columnsQuantity;

    this->currentLine = 0;
    this->currentColumn = 0;
}

matrix::Matrix::~Matrix()
{
    for (MatrixLine *line : this->lines)
    {
        delete line;
    }
    std::cout << "Matrix destructed\n";
}

int matrix::Matrix::get_lines_quantity()
{
    return this->linesQuantity;
}

int matrix::Matrix::get_columns_quantity()
{
    return this->columnsQuantity;
}

bool matrix::Matrix::is_square_matrix()
{
    return (this->linesQuantity == this->columnsQuantity);
}

matrix::MatrixItem *matrix::Matrix::get_item(int line, int column)
{
    matrix::MatrixLine *matrixLine = (this->lines)[line];
    matrix::MatrixItem *item = (matrixLine->line)[column];

    return item;
}

void matrix::Matrix::print_matrix()
{
    for (int i = 1; i <= this->linesQuantity; i++)
    {
        for (int j = 1; j <= this->columnsQuantity; i++)
        {
            if ((i == this->currentLine && j == this->currentColumn) || )
            {
                std::cout << " * ";
            }
            else if ((i > this->currentLine) || (i == this->currentLine && j > this->currentColumn))
            {
                std::cout << "   ";
            }
            else
            {
                matrix::MatrixItem *item = this->get_item(i, j);
                std::cout << " " <<std::to_string(item->get_data()) << " ";
            }
        }

        std::cout << std::endl;
    }
}
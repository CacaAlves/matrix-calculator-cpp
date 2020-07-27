#include "matrix.h"

matrix::Matrix::Matrix()
{
    this->currentTargedLine = 0;
    this->currentTargedColumn = 0;

    this->lines = new std::vector<matrix::MatrixLine *>();
}

matrix::Matrix::Matrix(int linesQuantity, int columnsQuantity)
{
    this->linesQuantity = linesQuantity;
    this->columnsQuantity = columnsQuantity;

    this->currentTargedLine = 0;
    this->currentTargedColumn = 0;

    this->lines = new std::vector<matrix::MatrixLine *>();
}

matrix::Matrix::~Matrix()
{
    for (matrix::MatrixLine *line : (*this->lines))
    {
        delete line;
    }

    delete (this->lines);

    std::cout << "Matrix destructed\n";
}

void matrix::Matrix::add_line(matrix::MatrixLine *line)
{
    (this->lines)->push_back(line);
}

int matrix::Matrix::get_lines_quantity()
{
    return this->linesQuantity;
}

int matrix::Matrix::get_columns_quantity()
{
    return this->columnsQuantity;
}

int matrix::Matrix::get_current_targed_line()
{
    return (this->currentTargedLine);
}

void matrix::Matrix::set_current_targed_line(int value)
{
    this->currentTargedLine = value;
}

int matrix::Matrix::get_current_targed_column()
{
    return (this->currentTargedColumn);
}

void matrix::Matrix::set_current_targed_column(int value)
{
    this->currentTargedColumn = value;
}

bool matrix::Matrix::is_square_matrix()
{
    return (this->linesQuantity == this->columnsQuantity);
}

matrix::MatrixItem *matrix::Matrix::get_item(int line, int column)
{
    matrix::MatrixLine *matrixLine = (*this->lines)[line];
    matrix::MatrixItem *item = matrixLine->get_element(column);

    return item;
}

void matrix::Matrix::add_item_matrix(const int data)
{
    matrix::MatrixLine *line = (*this->lines)[this->currentTargedLine];
    line->set_element(data, this->currentTargedColumn);
}

void matrix::Matrix::print_matrix()
{
    for (int i = 0; i < this->linesQuantity; i++)
    {
        for (int j = 0; j < this->columnsQuantity; j++)
        {
            if ((i == this->currentTargedLine && j == this->currentTargedColumn))
            {
                std::cout << " * ";
            }
            else if ((i > this->currentTargedLine) || (i == this->currentTargedLine && j > this->currentTargedColumn))
            {
                std::cout << "   ";
            }
            else
            {
                matrix::MatrixItem *item = this->get_item(i, j);
                std::cout << " " << std::to_string(item->get_data()) << " ";
            }
        }

        std::cout << std::endl;
    }
}

bool matrix::Matrix::is_in_last_position()
{
    bool isLastPosition = (
        ((this->currentTargedLine) ==  (this->linesQuantity -1 ))
        &&
        ((this->currentTargedColumn) == (this->columnsQuantity - 1))
    );
}
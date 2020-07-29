#include "matrix.h"

matrix::Matrix::Matrix()
{
    this->currentTargedLine = 0;
    this->currentTargedColumn = 0;

    this->lines = new std::vector<matrix::MatrixLine *>();
}

bool matrix::Matrix::equality_between_matrices(matrix::Matrix *matrix)
{
    if (!(this->get_lines_quantity() == matrix->get_lines_quantity() &&
          this->get_columns_quantity() == matrix->get_columns_quantity()))
    {
        return false;
    }

    bool areEquals = true;

    for (int line = 0; line < this->get_lines_quantity(); line++)
    {
        for (int column = 0; column < this->get_columns_quantity(); column++)
        {
            const bool equalsValuesInPosition =
                (this->get_item(line, column)->get_data()) ==
                (matrix->get_item(line, column)->get_data());

            if (!equalsValuesInPosition)
            {
                areEquals = false;
                break;
            }
        }

        if (!areEquals)
        {
            break;
        }
    }

    return areEquals;
}

void matrix::Matrix::sum_of_two_matrix(matrix::Matrix *matrixToSum)
{
    if (!(this->get_lines_quantity() == matrixToSum->get_lines_quantity() &&
          this->get_columns_quantity() == matrixToSum->get_columns_quantity()))
    {
        return;
    }

    for (int line = 0; line < this->get_lines_quantity(); line++)
    {
        for (int column = 0; column < this->get_columns_quantity(); column++)
        {
            const int currentPositionData = (this->get_item(line, column)->get_data());
            const int currentPositionDataMatrixToSum = (matrixToSum->get_item(line, column)->get_data());

            matrix::MatrixItem *currentPosition = (this->get_item(line, column));

            currentPosition->set_data(currentPositionData + currentPositionDataMatrixToSum);
        }
    }
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

void matrix::Matrix::print_matrix(bool skipOption)
{
    std::cout << std::endl;

    for (int i = 0; i < this->linesQuantity; i++)
    {
        for (int j = 0; j < this->columnsQuantity; j++)
        {
            if ((i == this->currentTargedLine && j == this->currentTargedColumn))
            {
                if (j == 0)
                {
                    std::cout << matrix::Matrix::tab;
                }
                std::cout << " * ";
            }
            else if ((i > this->currentTargedLine) || (i == this->currentTargedLine && j > this->currentTargedColumn))
            {
                if (j == 0)
                {
                    std::cout << matrix::Matrix::tab;
                }
                std::cout << "   ";
            }
            else
            {
                if (j == 0)
                {
                    std::cout << matrix::Matrix::tab;
                }
                int data = (this->get_item(i, j)->get_data());
                if (data < 0)
                {
                    std::cout << "  " << std::to_string(data) << "   ";
                }
                else
                {
                    std::cout << "   " << std::to_string(data) << "   ";
                }
            }
        }

        std::cout << std::endl;
    }

    if (skipOption)
    {
        int exit = 1;
        std::cout << std::endl
                  << matrix::Matrix::tab << "Input 0 to stop printing\n";
        while (exit != 0)
        {
            std::cout << matrix::Matrix::tab;
            std::cin >> exit;
        }
    }
}

bool matrix::Matrix::is_in_last_position()
{
    bool isLastPosition = (((this->currentTargedLine) == (this->linesQuantity - 1)) &&
                           ((this->currentTargedColumn) == (this->columnsQuantity - 1)));
}
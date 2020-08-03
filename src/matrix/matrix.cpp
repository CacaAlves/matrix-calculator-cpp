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

    this->set_matrix();
}

matrix::Matrix::~Matrix()
{
    for (matrix::MatrixLine *line : (*this->lines))
    {
        delete line;
    }

    delete (this->lines);
}

void matrix::Matrix::set_target_to_after_end()
{
    this->set_current_targed_line(
        (this->get_lines_quantity()));
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

void matrix::Matrix::difference_between_matrices(matrix::Matrix *matrixToSum)
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

            currentPosition->set_data(currentPositionData - currentPositionDataMatrixToSum);
        }
    }
}

matrix::Matrix *matrix::Matrix::multiply_by_constant(const int constant)
{
    matrix::Matrix *multipliedMatrix = new matrix::Matrix(this->get_lines_quantity(), this->get_columns_quantity());
    multipliedMatrix->set_to_equal_to(this);

    for (int line = 0; line < multipliedMatrix->get_lines_quantity(); line++)
    {
        for (int column = 0; column < multipliedMatrix->get_columns_quantity(); column++)
        {
            matrix::MatrixItem *item = multipliedMatrix->get_item(line, column);
            int currentData = item->get_data();
            item->set_data(currentData * constant);
        }
    }

    return multipliedMatrix;
}

matrix::Matrix *matrix::Matrix::multiply_by_matrix(matrix::Matrix *matrixToMultiply)
{
    if (this->columnsQuantity != matrixToMultiply->get_lines_quantity())
    {
        return NULL;
    }

    matrix::Matrix *multiplicationMatrix = new matrix::Matrix(this->linesQuantity, matrixToMultiply->get_columns_quantity());
    multiplicationMatrix->set_target_to_after_end();

    for (int matrixLine = 0; matrixLine < this->get_lines_quantity(); matrixLine++)
    {

        for (int matrixToMultiplyColumn = 0; matrixToMultiplyColumn < matrixToMultiply->get_columns_quantity(); matrixToMultiplyColumn++)
        {
            int sum = 0;
            for (int matrixToMultiplyLine = 0; matrixToMultiplyLine < matrixToMultiply->get_lines_quantity(); matrixToMultiplyLine++)
            {
                const int matrixPositionData = (this->get_item(matrixLine, matrixToMultiplyLine)->get_data());
                const int matrixToMultiplyPositionData = (matrixToMultiply->get_item(matrixToMultiplyLine, matrixToMultiplyColumn)->get_data());

                sum += (matrixPositionData * matrixToMultiplyPositionData);
            }

            multiplicationMatrix->get_item(matrixLine, matrixToMultiplyColumn)->set_data(sum);
        }
    }

    return multiplicationMatrix;
}

bool matrix::Matrix::is_inverse(Matrix *matrix)
{
    matrix::Matrix *multiplicationMatrix = this->multiply_by_matrix(matrix);
    bool isInverse;

    if (multiplicationMatrix != NULL)
    {
        isInverse = multiplicationMatrix->is_matrix_n();
    }
    else
    {
        isInverse = false;
    }

    return isInverse;
}

matrix::Matrix *matrix::Matrix::transposed_matrix()
{
    matrix::Matrix *transposedMatrix = new matrix::Matrix(
        this->columnsQuantity, this->linesQuantity);

    for (int line = 0; line < transposedMatrix->get_lines_quantity(); line++)
    {
        for (int column = 0; column < transposedMatrix->get_columns_quantity(); column++)
        {
            const int value = this->get_item(column, line)->get_data();
            transposedMatrix->set_item(line, column, value);
        }
    }

    return transposedMatrix;
}

bool matrix::Matrix::is_matrix_n(int n)
{
    if (this->linesQuantity != this->columnsQuantity)
    {
        return false;
    }

    bool isMatrixN;

    for (int line = 0; line < this->get_lines_quantity(); line++)
    {
        for (int column = 0; column < this->get_columns_quantity(); column++)
        {
            bool isMatrixMainDiagonal = (line == column);
            const int value = (this->get_item(line, column))->get_data();

            if (isMatrixMainDiagonal)
            {
                isMatrixN = (value == n);
            }
            else
            {
                isMatrixN = (value == 0);
            }

            if (!isMatrixN)
            {
                break;
            }
        }

        if (!isMatrixN)
        {
            break;
        }
    }

    return isMatrixN;
}

bool matrix::Matrix::is_symmetric_matrix()
{
    matrix::Matrix *transposedMatrix = this->transposed_matrix();

    const bool isSymmetricMatrix = this->equality_between_matrices(transposedMatrix);

    delete transposedMatrix;

    return isSymmetricMatrix;
}

bool matrix::Matrix::is_anti_symmetric_matrix()
{
    matrix::Matrix *transposedMatrix = this->transposed_matrix();
    matrix::Matrix *negativeMatrix = this->multiply_by_constant(-1);

    const bool isAntiSymmetricMatrix = transposedMatrix->equality_between_matrices(negativeMatrix);

    delete transposedMatrix;
    delete negativeMatrix;

    return isAntiSymmetricMatrix;
}

bool matrix::Matrix::is_lower_triangular_matrix()
{
    bool isLTM = true;

    for (int i = 0; i < this->get_lines_quantity(); i++)
    {
        for (int j = 0; j < this->get_columns_quantity(); j++)
        {
            const int value = this->get_item(i, j)->get_data();

            if (i < j && value != 0)
            {
                isLTM = false;
                break;
            }
        }

        if (!isLTM)
        {
            break;
        }
    }

    return isLTM;
}

bool matrix::Matrix::is_upper_triangular_matrix()
{
    bool isUTM = true;

    for (int i = 0; i < this->get_lines_quantity(); i++)
    {
        for (int j = 0; j < this->get_columns_quantity(); j++)
        {
            const int value = this->get_item(i, j)->get_data();

            if (i > j && value != 0)
            {
                isUTM = false;
                break;
            }
        }

        if (!isUTM)
        {
            break;
        }
    }

    return isUTM;
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

void matrix::Matrix::set_item(int line, int column, int value)
{
    matrix::MatrixItem *item = this->get_item(line, column);
    item->set_data(value);
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
                std::cout << "       *";
            }
            else if ((i < this->currentTargedLine) || (i == this->currentTargedLine && j <= this->currentTargedColumn))
            /* elements that were not target yet will not be printed */
            {

                if (j == 0)
                {
                    std::cout << matrix::Matrix::tab;
                }

                int data = (this->get_item(i, j)->get_data());
                const std::string space = " ";
                std::string spaces = "";

                int decrement = 8;

                for (int k = 0; k < decrement - (std::to_string(data)).size(); k++)
                {
                    spaces += space;
                }

                std::cout << spaces << std::to_string(data);
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

void matrix::Matrix::set_to_equal_to(matrix::Matrix *matchMatrix)
{
    if (!(this->get_lines_quantity() == matchMatrix->get_lines_quantity() &&
          this->get_columns_quantity() == matchMatrix->get_columns_quantity()))
    {
        return;
    }

    for (int line = 0; line < this->get_lines_quantity(); line++)
    {
        for (int column = 0; column < this->get_columns_quantity(); column++)
        {
            const int data = (matchMatrix)->get_item(line, column)->get_data();
            matrix::MatrixItem *item = (this->get_item(line, column));
            item->set_data(data);
        }
    }
}

void matrix::Matrix::set_matrix()
{
    for (int i = 0; i < this->get_lines_quantity(); i++)
    {
        matrix::MatrixLine *tempLine = new matrix::MatrixLine();
        this->add_line(tempLine);

        for (int j = 0; j < this->get_columns_quantity(); j++)
        {
            tempLine->add_element(0);
        }
    }
}
#include "menu_operations.h"

void main_utils::MenuOperations::print_receive_menu_operations()
{
    std::cout << std::endl
              << (this->utils)->tab << "Menu operations\n\n";
    std::cout << (this->utils)->tab << "Enter a number:\n";
    std::cout << (this->utils)->tab << "1 - equality between matrices.\n";
    std::cout << (this->utils)->tab << "2 - sum two (or more) matrices.\n";
    std::cout << (this->utils)->tab << "3 - subtraction between two (or more) matrices.\n";
    std::cout << (this->utils)->tab << "4 - multiply a matrix by a constant.\n";
    std::cout << (this->utils)->tab << "5 - multiply a matrix by a matrix.\n";
    std::cout << (this->utils)->tab << "6 - is inverse.\n";
    std::cout << (this->utils)->tab << "7 - transposed matrix.\n";
    std::cout << (this->utils)->tab << "8 - is matrix 0.\n";
    std::cout << (this->utils)->tab << "9 - is matrix 1.\n";
    std::cout << (this->utils)->tab << "10 - is matrix n.\n";
    std::cout << (this->utils)->tab << "11 - is symmetric matrix.\n";
    std::cout << (this->utils)->tab << "12 - is anti-symmetric matrix.\n";
    std::cout << (this->utils)->tab << "13 - is lower triangular matrix.\n";
    std::cout << (this->utils)->tab << "14 - is upper triangular matrix.\n";
    std::cout << (this->utils)->tab << "0 - cancel.\n";

    std::cout << std::endl
              << (this->utils)->tab;
    this->menuOperations = ((this->utils)->filtered_input());

    std::cout << std::endl;
}

bool main_utils::MenuOperations::is_menu_operations_a_valid_number()
{
    bool isAValidNumber;

    switch (this->menuOperations)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 0:
        isAValidNumber = true;
        break;
    default:
        isAValidNumber = false;
        break;
    }

    return isAValidNumber;
}

main_utils::ActionResponse *main_utils::MenuOperations::manage_operations()
{
    do
    {
        this->print_receive_menu_operations();
        system("clear");
    } while (!(this->is_menu_operations_a_valid_number()));

    ActionResponse *response = perform_action_menu_operations();
    return response;
}

main_utils::ActionResponse *main_utils::MenuOperations::perform_action_menu_operations()
{
    main_utils::ActionResponse *response = new main_utils::ActionResponse;

    switch (this->menuOperations)
    {
    case 0:
    {
        std::string responseMessage = "";
        response->set_action_response(responseMessage, true);
        break;
    }
    case 1:
    {
        std::string responseMessage = this->equality_between_matrices();
        response->set_action_response(responseMessage, true);
        break;
    }
    case 2:
    {
        std::string responseMessage = this->sum_of_matrices();
        response->set_action_response(responseMessage, true);
        break;
    }
    case 3:
    {
        std::string responseMessage = this->difference_between_matrices();
        response->set_action_response(responseMessage, true);
        break;
    }
    case 4:
    {
        std::string responseMessage = this->multiply_matrix_by_constant();
        response->set_action_response(responseMessage, true);
        break;
    }
    case 5:
    {
        std::string responseMessage = this->multiply_matrix_by_matrix();
        response->set_action_response(responseMessage, true);
        break;
    }
    case 6:
    {
        std::string responseMessage = this->is_inverse_matrix();
        response->set_action_response(responseMessage, true);
        break;
    }
    case 7:
    {
        std::string responseMessage = this->transposed_matrix();
        response->set_action_response(responseMessage, true);
        break;
    }
    case 8:
    {
        std::string responseMessage = this->is_matrix_n(0);
        response->set_action_response(responseMessage, true);
        break;
    }
    case 9:
    {
        std::string responseMessage = this->is_matrix_n(1);
        response->set_action_response(responseMessage, true);
        break;
    }
    case 10:
    {
        std::string responseMessage = this->is_matrix_n();
        response->set_action_response(responseMessage, true);
        break;
    }
    case 11:
    {
        std::string responseMessage = this->is_symmetric_matrix();
        response->set_action_response(responseMessage, true);
        break;
    }
    case 12:
    {
        std::string responseMessage = this->is_anti_symmetric_matrix();
        response->set_action_response(responseMessage, true);
        break;
    }
    case 13:
    {
        std::string responseMessage = this->is_lower_triangular_matrix_matrix();
        response->set_action_response(responseMessage, true);
        break;
    }
    case 14:
    {
        std::string responseMessage = this->is_upper_triangular_matrix_matrix();
        response->set_action_response(responseMessage, true);
        break;
    }
    default:
        break;
    }

    return response;
}

std::string main_utils::MenuOperations::equality_between_matrices()
{
    std::string strToReturn;
    bool equality;

    std::string matrix1Name;
    std::string matrix2Name;

    std::cout << (this->utils)->tab << "Input a matrix name: ";
    std::cin >> matrix1Name;

    std::cout << (this->utils)->tab << "Input a second matrix name to be compared: ";
    std::cin >> matrix2Name;

    matrix::Matrix *matrix1 = (this->utils)->find_matrix_in_matrices(matrix1Name);
    matrix::Matrix *matrix2 = (this->utils)->find_matrix_in_matrices(matrix2Name);

    if (matrix1 == NULL || matrix2 == NULL)
    {
        equality = false;
        strToReturn = (this->utils)->tab + "One or both of the matrices are not in the list of variables\n";
    }
    else
    {
        equality = matrix1->equality_between_matrices(matrix2);
    }

    if (equality)
    {
        strToReturn = (this->utils)->tab + "The matrix " + matrix1Name + " and the matrix " +
                      matrix2Name + " are equals\n";
    }
    else if (strToReturn.size() == 0)
    {
        strToReturn = (this->utils)->tab + "The matrix " + matrix1Name + " and the matrix " +
                      matrix2Name + " are NOT equals\n";
    }

    return strToReturn;
}

std::string main_utils::MenuOperations::sum_of_matrices()
{
    std::string strToReturn;
    bool ableToSum = true;

    std::string matrixName;
    std::vector<matrix::Matrix *> matricesToSum;
    int linesQuantity;
    int columnsQuantity;

    while (matrixName != "0" && ableToSum)
    {
        std::cout << (this->utils)->tab << "Input a matrix name to sum (input 0 to stop inputting): ";
        std::cin >> matrixName;

        if (matrixName != "0")
        {

            matrix::Matrix *matrix = (this->utils)->find_matrix_in_matrices(matrixName);

            if (matrix == NULL)
            {
                strToReturn = (this->utils)->tab + "One of the matrices in the input does not exist\n";
                ableToSum = false;
            }
            else
            {
                matricesToSum.push_back(matrix);
                ableToSum = true;
            }
        }
    }

    if (ableToSum)
    {
        bool allSameSize = true;

        linesQuantity = -1;
        columnsQuantity = -1;

        for (matrix::Matrix *temp : matricesToSum)
        {
            if (linesQuantity == -1 && columnsQuantity == -1) //first loop
            {
                linesQuantity = temp->get_lines_quantity();
                columnsQuantity = temp->get_columns_quantity();
            }
            else
            {
                allSameSize = (linesQuantity == temp->get_lines_quantity() && columnsQuantity == temp->get_columns_quantity());
            }

            if (!allSameSize)
            {
                ableToSum = false;
                break;
            }
        }
    }

    if (ableToSum)
    {
        matrix::Matrix *sumMatrix = new matrix::Matrix(linesQuantity, columnsQuantity);

        for (matrix::Matrix *temp : matricesToSum)
        {
            sumMatrix->sum_of_two_matrix(temp);
        }

        std::string sumMatrixName = (this->utils)->insert_matrix(sumMatrix);
        strToReturn = (this->utils)->tab + "The new matrix was stored in the constant: " + sumMatrixName + "\n";

        sumMatrix->set_target_to_after_end();
    }
    else if (!ableToSum && strToReturn.size() == 0)
    {
        strToReturn = (this->utils)->tab + "Something went wrong: Unable to sum\n";
    }

    matricesToSum.clear();
    return strToReturn;
}

std::string main_utils::MenuOperations::difference_between_matrices()
{
    std::string strToReturn;
    bool ableToSubtract = true;

    std::string matrixName;
    std::vector<matrix::Matrix *> matricesToSubtract;
    int linesQuantity;
    int columnsQuantity;

    while (matrixName != "0" && ableToSubtract)
    {
        std::cout << (this->utils)->tab << "Input a matrix name to subtract (input 0 to stop inputting): ";
        std::cin >> matrixName;

        if (matrixName != "0")
        {

            matrix::Matrix *matrix = (this->utils)->find_matrix_in_matrices(matrixName);

            if (matrix == NULL)
            {
                strToReturn = (this->utils)->tab + "One of the matrices in the input does not exist\n";
                ableToSubtract = false;
            }
            else
            {
                matricesToSubtract.push_back(matrix);
                ableToSubtract = true;
            }
        }
    }

    if (ableToSubtract)
    {
        bool allSameSize = true;

        linesQuantity = -1;
        columnsQuantity = -1;

        for (matrix::Matrix *temp : matricesToSubtract)
        {
            if (linesQuantity == -1 && columnsQuantity == -1) //first loop
            {
                linesQuantity = temp->get_lines_quantity();
                columnsQuantity = temp->get_columns_quantity();
            }
            else
            {
                allSameSize = (linesQuantity == temp->get_lines_quantity() && columnsQuantity == temp->get_columns_quantity());
            }

            if (!allSameSize)
            {
                ableToSubtract = false;
                break;
            }
        }
    }

    if (ableToSubtract)
    {
        matrix::Matrix *differenceMatrix = NULL;

        for (matrix::Matrix *temp : matricesToSubtract)
        {
            if (differenceMatrix == NULL)
            {
                differenceMatrix = new matrix::Matrix(temp->get_lines_quantity(), temp->get_columns_quantity());

                differenceMatrix->set_to_equal_to(temp);
            }
            else
            {
                differenceMatrix->difference_between_matrices(temp);
            }
        }

        std::string differenceMatrixName = (this->utils)->insert_matrix(differenceMatrix);
        strToReturn = (this->utils)->tab + "The new matrix was stored in the constant: " + differenceMatrixName + "\n";

        differenceMatrix->set_target_to_after_end();
    }
    else if (!ableToSubtract && strToReturn.size() == 0)
    {
        strToReturn = (this->utils)->tab + "Something went wrong: Unable to subtract\n";
    }

    matricesToSubtract.clear();
    return strToReturn;
}

std::string main_utils::MenuOperations::multiply_matrix_by_constant()
{
    std::string strToReturn;

    std::string matrixName;
    int constant;

    std::cout << (this->utils)->tab << "Input a matrix name: ";
    std::cin >> matrixName;

    std::cout << (this->utils)->tab << "Input a constant to multiply: ";
    constant = (this->utils)->filtered_input(1); //1 will be returned when input is NaN

    if (constant == 1)
    {
        strToReturn = (this->utils)->tab + "Did not multiplied.\n";
        return strToReturn;
    }

    matrix::Matrix *matrix = (this->utils)->find_matrix_in_matrices(matrixName);
    matrix::Matrix *multipliedMatrix = NULL;

    if (matrix == NULL)
    {
        strToReturn = (this->utils)->tab + "The matrix of the input does not exist\n";
    }
    else
    {
        matrix::Matrix *multipliedMatrix = matrix->multiply_by_constant(constant);

        std::string multipliedMatrixName = (this->utils)->insert_matrix(multipliedMatrix);
        strToReturn = (this->utils)->tab + "The multiplied matrix was stored in the constant: " + multipliedMatrixName + "\n";

        multipliedMatrix->set_target_to_after_end();
    }

    return strToReturn;
}

std::string main_utils::MenuOperations::multiply_matrix_by_matrix()
{
    std::string strToReturn;
    bool multiplication;

    std::string matrix1Name;
    std::string matrix2Name;

    std::cout << (this->utils)->tab << "Input a matrix name: ";
    std::cin >> matrix1Name;

    std::cout << (this->utils)->tab << "Input a second matrix name to multiply: ";
    std::cin >> matrix2Name;

    matrix::Matrix *matrix1 = (this->utils)->find_matrix_in_matrices(matrix1Name);
    matrix::Matrix *matrix2 = (this->utils)->find_matrix_in_matrices(matrix2Name);

    matrix::Matrix *multiplicationMatrix = NULL;

    if (matrix1 == NULL || matrix2 == NULL)
    {
        multiplication = false;
        strToReturn = (this->utils)->tab + "One or both of the matrices are not in the list of variables\n";
    }
    else if (matrix1->get_columns_quantity() != matrix2->get_lines_quantity())
    {
        multiplication = false;
        strToReturn = (this->utils)->tab + "The first matrix has a number of columns different from the second matrix number of lines\n";
    }
    else
    {
        multiplicationMatrix = matrix1->multiply_by_matrix(matrix2);
        multiplication = true;
    }

    if (multiplication)
    {
        std::string matrixName = (this->utils)->insert_matrix(multiplicationMatrix);
        strToReturn = (this->utils)->tab + "The new matrix was stored in the constant: " + matrixName + "\n";
    }
    else if (strToReturn.size() == 0)
    {
        strToReturn = (this->utils)->tab + "Something went wrong in the multiplication\n";
    }

    return strToReturn;
}

std::string main_utils::MenuOperations::is_inverse_matrix()
{
    std::string strToReturn;
    bool isInverse;

    std::string matrix1Name;
    std::string matrix2Name;

    std::cout << (this->utils)->tab << "Input a matrix name: ";
    std::cin >> matrix1Name;

    std::cout << (this->utils)->tab << "Input a second matrix name to verify if it is previous's inverse: ";
    std::cin >> matrix2Name;

    matrix::Matrix *matrix1 = (this->utils)->find_matrix_in_matrices(matrix1Name);
    matrix::Matrix *matrix2 = (this->utils)->find_matrix_in_matrices(matrix2Name);

    if (matrix1 == NULL || matrix2 == NULL)
    {
        isInverse = false;
        strToReturn = (this->utils)->tab + "One or both of the matrices are not in the list of variables\n";
    }
    else
    {
        isInverse = matrix1->is_inverse(matrix2);
    }

    if (isInverse)
    {
        strToReturn = (this->utils)->tab + "The matrix " + matrix2Name + " is inverse of matrix " + matrix1Name + "\n";
    }
    else if (strToReturn.size() == 0)
    {
        strToReturn = (this->utils)->tab + "The matrix " + matrix2Name + " is NOT inverse of matrix " + matrix1Name + "\n";
    }

    return strToReturn;
}

std::string main_utils::MenuOperations::transposed_matrix()
{
    std::string strToReturn;

    std::string matrixName;

    std::cout << (this->utils)->tab << "Input a matrix name to receive its transposed: ";
    std::cin >> matrixName;

    matrix::Matrix *matrix = (this->utils)->find_matrix_in_matrices(matrixName);

    if (matrix == NULL)
    {
        strToReturn = (this->utils)->tab + "The matrix of the input does not exist\n";
    }
    else
    {
        matrix::Matrix *transposedMatrix = matrix->transposed_matrix();

        std::string transposedMatrixName = (this->utils)->insert_matrix(transposedMatrix);
        strToReturn = (this->utils)->tab + "The transposed matrix was stored in the constant: " + transposedMatrixName + "\n";

        transposedMatrix->set_target_to_after_end();
    }

    return strToReturn;
}

std::string main_utils::MenuOperations::is_matrix_n(int n)
{
    std::string strToReturn;

    std::string matrixName;

    if (n == -1)
    {
        std::cout << (this->utils)->tab << "Input a number: ";
        n = this->utils->filtered_input();
    }

    std::cout << (this->utils)->tab << "Input a matrix name to verify if it's matrix " + std::to_string(n) + ": ";
    std::cin >> matrixName;

    matrix::Matrix *matrix = (this->utils)->find_matrix_in_matrices(matrixName);

    if (matrix == NULL)
    {
        strToReturn = (this->utils)->tab + "The matrix of the input does not exist\n";
    }
    else
    {
        bool isMatrixN;
        isMatrixN = matrix->is_matrix_n(n);

        if (isMatrixN)
        {
            strToReturn = (this->utils)->tab + "The matrix " + matrixName + " is matrix " + std::to_string(n) + "\n";
        }
        else
        {
            strToReturn = (this->utils)->tab + "The matrix " + matrixName + " is NOT matrix " + std::to_string(n) + "\n";
        }
    }

    return strToReturn;
}
std::string main_utils::MenuOperations::is_symmetric_matrix()
{
    std::string strToReturn;

    std::string matrixName;

    std::cout << (this->utils)->tab << "Input a matrix name to verify if it's a symmetric matrix: ";
    std::cin >> matrixName;

    matrix::Matrix *matrix = (this->utils)->find_matrix_in_matrices(matrixName);

    if (matrix == NULL)
    {
        strToReturn = (this->utils)->tab + "The matrix of the input does not exist\n";
    }
    else
    {
        bool isSymmetricMatrix;
        isSymmetricMatrix = matrix->is_symmetric_matrix();

        if (isSymmetricMatrix)
        {
            strToReturn = (this->utils)->tab + "The matrix " + matrixName + " is a symmetric matrix\n";
        }
        else
        {
            strToReturn = (this->utils)->tab + "The matrix " + matrixName + " is NOT a symmetric matrix\n";
        }
    }

    return strToReturn;
}

std::string main_utils::MenuOperations::is_anti_symmetric_matrix()
{
    std::string strToReturn;

    std::string matrixName;

    std::cout << (this->utils)->tab << "Input a matrix name to verify if it's an anti-symmetric matrix: ";
    std::cin >> matrixName;

    matrix::Matrix *matrix = (this->utils)->find_matrix_in_matrices(matrixName);

    if (matrix == NULL)
    {
        strToReturn = (this->utils)->tab + "The matrix of the input does not exist\n";
    }
    else
    {
        bool isAntiSymmetricMatrix;
        isAntiSymmetricMatrix = matrix->is_anti_symmetric_matrix();

        if (isAntiSymmetricMatrix)
        {
            strToReturn = (this->utils)->tab + "The matrix " + matrixName + " is an anti-symmetric matrix\n";
        }
        else
        {
            strToReturn = (this->utils)->tab + "The matrix " + matrixName + " is NOT an anti-symmetric matrix\n";
        }
    }

    return strToReturn;
}

std::string main_utils::MenuOperations::is_lower_triangular_matrix_matrix()
{
    std::string strToReturn;

    std::string matrixName;

    std::cout << (this->utils)->tab << "Input a matrix name to verify if it's a lower triangular matrix: ";
    std::cin >> matrixName;

    matrix::Matrix *matrix = (this->utils)->find_matrix_in_matrices(matrixName);

    if (matrix == NULL)
    {
        strToReturn = (this->utils)->tab + "The matrix of the input does not exist\n";
    }
    else
    {
        bool isLowerTriangularMatrix;
        isLowerTriangularMatrix = matrix->is_lower_triangular_matrix();

        if (isLowerTriangularMatrix)
        {
            strToReturn = (this->utils)->tab + "The matrix " + matrixName + " is a lower triangular matrix\n";
        }
        else
        {
            strToReturn = (this->utils)->tab + "The matrix " + matrixName + " is NOT a lower triangular matrix\n";
        }
    }

    return strToReturn;
}

std::string main_utils::MenuOperations::is_upper_triangular_matrix_matrix()
{
    std::string strToReturn;

    std::string matrixName;

    std::cout << (this->utils)->tab << "Input a matrix name to verify if it's an upper triangular matrix: ";
    std::cin >> matrixName;

    matrix::Matrix *matrix = (this->utils)->find_matrix_in_matrices(matrixName);

    if (matrix == NULL)
    {
        strToReturn = (this->utils)->tab + "The matrix of the input does not exist\n";
    }
    else
    {
        bool isUpperTriangularMatrix;
        isUpperTriangularMatrix = matrix->is_upper_triangular_matrix();

        if (isUpperTriangularMatrix)
        {
            strToReturn = (this->utils)->tab + "The matrix " + matrixName + " is an upper triangular matrix\n";
        }
        else
        {
            strToReturn = (this->utils)->tab + "The matrix " + matrixName + " is NOT an upper triangular matrix\n";
        }
    }

    return strToReturn;
}

void main_utils::MenuOperations::set_main_utils(main_utils::MainUtils *utils)
{
    this->utils = utils;
}
#include "menu_operations.h"

void main_utils::MenuOperations::print_receive_menu_operations()
{
    std::cout << std::endl
              << (this->utils)->tab << "Menu operations\n\n";
    std::cout << (this->utils)->tab << "Enter a number:\n";
    std::cout << (this->utils)->tab << "1 - equality between matrices.\n";
    std::cout << (this->utils)->tab << "2 - sum two matrices.\n";
    std::cout << (this->utils)->tab << "3 - subtraction between two matrices.\n";
    std::cout << (this->utils)->tab << "4 - multiply a matrix by a constant.\n";
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
        matrix::Matrix *sumMatrix = (this->utils)->get_matrix_zero(linesQuantity, columnsQuantity);

        for (matrix::Matrix *temp : matricesToSum)
        {
            sumMatrix->sum_of_two_matrix(temp);
        }

        std::string sumMatrixName = (this->utils)->insert_matrix(sumMatrix);
        strToReturn = (this->utils)->tab + "The new matrix was stored in the constant: " + sumMatrixName + "\n";

        sumMatrix->set_current_targed_line(sumMatrix->get_lines_quantity()); //setting the target to after the last element
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
                differenceMatrix = (this->utils)->get_matrix_zero(temp->get_lines_quantity(), temp->get_columns_quantity());

                differenceMatrix->set_to_equal_to(temp);
            }
            else
            {
                differenceMatrix->difference_between_matrices(temp);
            }
        }

        std::string differenceMatrixName = (this->utils)->insert_matrix(differenceMatrix);
        strToReturn = (this->utils)->tab + "The new matrix was stored in the constant: " + differenceMatrixName + "\n";

        differenceMatrix->set_current_targed_line(differenceMatrix->get_lines_quantity()); //setting the target to after the last element
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

    std::cout << (this->utils)->tab << "Input a matrix name to sum: ";
    std::cin >> matrixName;

    std::cout << (this->utils)->tab << "Input a constant to multiply: ";
    constant = (this->utils)->filtered_input(1); //1 will be returned when input is NaN

    if (constant == 1)
    {
        strToReturn = (this->utils)->tab + "Did not multiplied.\n";
        return strToReturn;
    }

    matrix::Matrix *matrix = (this->utils)->find_matrix_in_matrices(matrixName);
    matrix::Matrix *mutipliedMatrix = NULL;

    if (matrix == NULL)
    {
        strToReturn = (this->utils)->tab + "The matrix of the input does not exist\n";
    }
    else
    {
        int linesQuantity = matrix->get_lines_quantity();
        int columnsQuantity = matrix->get_columns_quantity();

        mutipliedMatrix = (this->utils)->get_matrix_zero(linesQuantity, columnsQuantity);
        mutipliedMatrix->set_to_equal_to(matrix);

        for (int line = 0; line < mutipliedMatrix->get_lines_quantity(); line++)
        {
            for (int column = 0; column < mutipliedMatrix->get_columns_quantity(); column++)
            {
                matrix::MatrixItem *item = mutipliedMatrix->get_item(line, column);
                int currentData = item->get_data();
                item->set_data(currentData * constant);
            }
        }

        std::string multipliedMatrixName = (this->utils)->insert_matrix(mutipliedMatrix);
        strToReturn = (this->utils)->tab + "The multiplied matrix was stored in the constant: " + multipliedMatrixName + "\n";

        mutipliedMatrix->set_current_targed_line(mutipliedMatrix->get_lines_quantity()); //setting the target to after the last element
    }

    return strToReturn;
}

void main_utils::MenuOperations::set_main_utils(main_utils::MainUtils *utils)
{
    this->utils = utils;
}
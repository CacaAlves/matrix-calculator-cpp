#include "menu_determinant.h"

void main_utils::MenuDeterminant::print_receive_menu_determinant()
{
    std::cout << std::endl
              << (this->utils)->tab << "Menu operations\n\n";
    std::cout << (this->utils)->tab << "Enter a number:\n";
    std::cout << (this->utils)->tab << "1 - calculate determinant of a matrix.\n";
    std::cout << (this->utils)->tab << "0 - cancel.\n";

    std::cout << std::endl
              << (this->utils)->tab;
    this->menuDeterminant = ((this->utils)->filtered_input());

    std::cout << std::endl;
}

bool main_utils::MenuDeterminant::is_menu_determinant_a_valid_number()
{
    bool isAValidNumber;

    switch (this->menuDeterminant)
    {
    case 1:
    case 0:
        isAValidNumber = true;
        break;
    default:
        isAValidNumber = false;
        break;
    }

    return isAValidNumber;
}

main_utils::ActionResponse *main_utils::MenuDeterminant::manage_determinant()
{
    do
    {
        this->print_receive_menu_determinant();
        system("clear");
    } while (!(this->is_menu_determinant_a_valid_number()));

    ActionResponse *response = perform_action_menu_determinant();
    return response;
}

main_utils::ActionResponse *main_utils::MenuDeterminant::perform_action_menu_determinant()
{
    main_utils::ActionResponse *response = new main_utils::ActionResponse;

    switch (this->menuDeterminant)
    {
    case 0:
    {
        std::string responseMessage = "";
        response->set_action_response(responseMessage, true);
        break;
    }
    case 1:
    {
        std::string responseMessage = this->calculate_determinant();
        response->set_action_response(responseMessage, true);
        break;
    }
    default:
        break;
    }

    return response;
}

std::string main_utils::MenuDeterminant::calculate_determinant()
{
    std::string strToReturn;
    bool ableToCalculateDeterminant;

    std::string matrixName;
    matrix::Determinant *determinant;

    std::cout << (this->utils)->tab << "Input a matrix name: ";
    std::cin >> matrixName;

    matrix::Matrix *matrix = (this->utils)->find_matrix_in_matrices(matrixName);

    if (matrix == NULL)
    {
        ableToCalculateDeterminant = false;
        strToReturn = (this->utils)->tab + "One or both of the matrices are not in the list of variables\n";
    }
    else
    {
        determinant = matrix->calculate_determinant();

        if (determinant == NULL)
        {
            strToReturn = (this->utils)->tab + "The matrix " + matrixName + " is not square matrix\n";
            ableToCalculateDeterminant = false;
        }
        else
        {
            std::string determinantStr = std::to_string(determinant->value);
            strToReturn = (this->utils)->tab + "The determinant of matrix " + 
                        matrixName + " is: " + determinantStr + "\n";

            delete determinant;

            ableToCalculateDeterminant = true;
        }
    }

    if (!ableToCalculateDeterminant && strToReturn.size() == 0)
    {
        strToReturn = (this->utils)->tab + "Something went wrong!\n ";
    }

    return strToReturn;
}

void main_utils::MenuDeterminant::set_main_utils(main_utils::MainUtils *utils)
{
    this->utils = utils;
}
#include "menu_main.h"

main_utils::MenuMain::MenuMain()
{
    (this->menuHardDisk) = new main_utils::MenuHardDisk();
    (this->menuOperations) = new main_utils::MenuOperations();
    (this->menuDeterminant) = new main_utils::MenuDeterminant();
}

main_utils::MenuMain::~MenuMain()
{
    delete (this->menuHardDisk);
    delete (this->menuOperations);
    delete (this->menuDeterminant);
}

void main_utils::MenuMain::set_main_utils(main_utils::MainUtils *utils)
{
    this->utils = utils;
    (this->menuHardDisk)->set_main_utils(utils);
    (this->menuOperations)->set_main_utils(utils);
    (this->menuDeterminant)->set_main_utils(utils);
}

void main_utils::MenuMain::welcome_message()
{
    std::cout << (this->utils)->tab << " ---------------- Welcome to the Matrix Calculator! ---------------- \n";
}

bool main_utils::MenuMain::is_menu_a_valid_number()
{
    bool isAValidNumber;

    switch (this->menu)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        isAValidNumber = true;
        break;
    default:
        isAValidNumber = false;
        break;
    }

    return isAValidNumber;
}

void main_utils::MenuMain::print_receive_menu()
{
    std::cout
        << (this->utils)->tab << "Menu\n\n";
    std::cout << (this->utils)->tab << "Enter a number:\n";
    std::cout << (this->utils)->tab << "1 - enter a matrix.\n";
    std::cout << (this->utils)->tab << "2 - print a matrix.\n";
    std::cout << (this->utils)->tab << "3 - print all matrices.\n";
    std::cout << (this->utils)->tab << "4 - operations between matrices.\n";
    std::cout << (this->utils)->tab << "5 - operations with determinant.\n";
    std::cout << (this->utils)->tab << "6 - delete a matrix (from variables).\n";
    std::cout << (this->utils)->tab << "7 - store / read / delete from Hard Disk.\n";
    std::cout << (this->utils)->tab << "8 - hints.\n";
    std::cout << (this->utils)->tab << "0 - exit program.\n";

    std::cout << std::endl
              << (this->utils)->tab;
    this->menu = ((this->utils)->filtered_input());

    std::cout << std::endl;
}

main_utils::ActionResponse *main_utils::MenuMain::perform_action_menu()
{
    main_utils::ActionResponse *response;

    switch (this->menu)
    {
    case 0:
    {
        response = new main_utils::ActionResponse;
        response->set_action_response("", false); /* Returning if the program needs to continue running */
        break;
    }
    case 1:
    {
        response = new main_utils::ActionResponse;
        std::string newMatrixName = this->receive_matrix();
        std::string responseMessage = "\n" + (this->utils)->tab + "The new matrix was stored in the constant: " + newMatrixName + "\n";
        response->set_action_response(responseMessage, true);

        break;
    }
    case 2:
    {
        response = new main_utils::ActionResponse;
        std::string responseMessage = this->print_matrix();
        response->set_action_response(responseMessage, true);

        break;
    }
    case 3:
    {
        response = new main_utils::ActionResponse;
        std::string responseMessage = this->print_all_matrices();
        response->set_action_response(responseMessage, true);
        break;
    }
    case 4:
    {
        response = ((this->menuOperations)->manage_operations());
        break;
    }
    case 5:
    {
        response = ((this->menuDeterminant)->manage_determinant());
        break;
    }
    case 6:
    {
        response = new main_utils::ActionResponse;
        std::string responseMessage = (this->utils)->delete_matrix_from_matrices();
        response->set_action_response(responseMessage, true);
        break;
    }
    case 7:
    {
        response = (this->menuHardDisk)->manage_hard_disk();
        break;
    }
    case 8:
    {
        response = new main_utils::ActionResponse;
        this->print_hints();
        std::string responseMessage = "";
        response->set_action_response(responseMessage, true);
        break;
    }
    default:
        response = new main_utils::ActionResponse;
        std::string responseMessage = (this->utils)->tab + "Enter a valid input\n";
        response->set_action_response(responseMessage, true);
        break;
    }

    return response;
}

void main_utils::MenuMain::print_hints()
{
    std::cout << std::endl
              << "\tHint 1: if you are inserting data in a matrix and would like to insert in the previous data, input \"bs\" (short for backspace).\n";

    std::cout << std::endl
              << "\tHint 2: if you are no longer using a matrix, delete it (either in list of variables or Hard Disk), you will be using less memory and (in list of variables case) will be less matrix names to keep in mind.\n";

    int exit = 1;
    std::cout << std::endl
              << (this->utils)->tab << "Input 0 to stop printing\n";
    while (exit != 0)
    {
        std::cout << (this->utils)->tab;
        exit = (this->utils)->filtered_input();
    }
}

std::string main_utils::MenuMain::receive_matrix()
{

    int lines = 1, columns = 1;

    std::cout << (this->utils)->tab << "Input the number of lines and then the number columns of the new matrix.\n";

    do
    {
        if (lines <= 0 || columns <= 0)
        {
            std::cout << (this->utils)->tab << "Input a positive and greater than 0 number.\n";
        }

        std::cout << (this->utils)->tab;
        lines = (this->utils)->filtered_input();

        std::cout << (this->utils)->tab;
        columns = (this->utils)->filtered_input();

        system("clear");

    } while (lines <= 0 || columns <= 0);

    matrix::Matrix *newMatrix = new matrix::Matrix(lines, columns);

    bool insertionOccurring = true;
    while (insertionOccurring)
    {
        system("clear");
        newMatrix->print_matrix();

        std::string input;

        std::cout << (this->utils)->tab;
        std::cin >> input;

        const std::string backspace = "bs";
        if (input == backspace)
        {
            newMatrix->set_current_targed_column(newMatrix->get_current_targed_column() - 1);
            if (newMatrix->get_current_targed_line() != 0 && newMatrix->get_current_targed_column() < 0)
            {
                newMatrix->set_current_targed_line(newMatrix->get_current_targed_line() - 1);
                newMatrix->set_current_targed_column(newMatrix->get_columns_quantity() - 1);
            }

            if (newMatrix->get_current_targed_column() < 0)
            {
                newMatrix->set_current_targed_column(0);
            }
        }
        else
        {
            int integerInput = (this->utils)->str_to_number(input);
            newMatrix->add_item_matrix(integerInput);

            if (newMatrix->is_in_last_position())
            {
                insertionOccurring = false;
                newMatrix->set_target_to_after_end();
            }
            else
            {
                newMatrix->set_current_targed_column(newMatrix->get_current_targed_column() + 1);
                if (newMatrix->get_current_targed_column() > (newMatrix->get_columns_quantity() - 1))
                {
                    newMatrix->set_current_targed_column(0);
                    newMatrix->set_current_targed_line(newMatrix->get_current_targed_line() + 1);
                }
            }
        }
    }

    std::string newMatrixName = (this->utils)->insert_matrix(newMatrix);

    return newMatrixName;
}

std::string main_utils::MenuMain::print_matrix()
{
    std::string responseMessage;

    std::string matrixName;
    std::cout << (this->utils)->tab << "Insert a matrix name of the matrix to be printed.\n";
    std::cout << (this->utils)->tab;
    std::cin >> matrixName;

    matrix::Matrix *matrix = (this->utils)->find_matrix_in_matrices(matrixName);
    if (matrix != NULL)
    {
        const int linesQuantity = matrix->get_lines_quantity();
        const int columnsQuantity = matrix->get_columns_quantity();

        std::cout << (this->utils)->tab << "number of lines: " << std::to_string(linesQuantity)
                  << ", number of columns: " << std::to_string(columnsQuantity) << std::endl;
        matrix->print_matrix(true);
        responseMessage = "";
    }
    else
    {
        responseMessage = "\n" + (this->utils)->tab + "There is not a matrix with this name\n";
    }

    return responseMessage;
}

std::string main_utils::MenuMain::print_all_matrices()
{
    std::string responseMessage;

    if (((this->utils)->matrices)->empty())
    {
        responseMessage = (this->utils)->tab + "There is no matrices to print\n";
    }
    else
    {
        responseMessage = "";
        std::string tempMatrixName = (this->utils)->get_first_matrix_in_matrices();
        matrix::Matrix *tempMatrix = (this->utils)->find_matrix_in_matrices(tempMatrixName);

        while (tempMatrix != NULL)
        {
            bool isLastMatrix = (tempMatrixName == (this->utils)->get_greater_matrix_in_matrices());

            const int linesQuantity = tempMatrix->get_lines_quantity();
            const int columnsQuantity = tempMatrix->get_columns_quantity();
            std::cout << (this->utils)->tab << "Matrix: " << tempMatrixName << std::endl
                      << (this->utils)->tab << "number of lines: " << std::to_string(linesQuantity)
                      << ", number of columns: " << std::to_string(columnsQuantity) << std::endl;
            tempMatrix->print_matrix(isLastMatrix);

            tempMatrixName = (this->utils)->get_next_matrix_in_matrices(tempMatrixName);
            tempMatrix = (this->utils)->find_matrix_in_matrices(tempMatrixName);

            std::cout << std::endl;
        }
    }

    return responseMessage;
}
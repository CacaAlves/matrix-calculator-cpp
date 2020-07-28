#include "main_utils.h"

void main_utils::ActionResponse::set_action_response(std::string message, bool running)
{
    this->message = message;
    this->running = running;
}

main_utils::MainUtils::MainUtils() {}

void main_utils::MainUtils::welcome_message()
{
    std::cout << main_utils::MainUtils::tab << " ---------------- Welcome to the Matrix Calculator! ---------------- \n";
}

bool main_utils::MainUtils::is_menu_a_valid_number()
{
    bool isAValidNumber;

    switch (this->menu)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 9:
    case 10:
        isAValidNumber = true;
        break;
    default:
        isAValidNumber = false;
        break;
    }

    return isAValidNumber;
}

void main_utils::MainUtils::print_receive_menu()
{
    std::cout << std::endl
              << main_utils::MainUtils::tab << "Menu\n\n";
    std::cout << main_utils::MainUtils::tab << "Enter a number.\n";
    std::cout << main_utils::MainUtils::tab << "1 - enter a matrix.\n";
    std::cout << main_utils::MainUtils::tab << "2 - print matrix.\n";
    std::cout << main_utils::MainUtils::tab << "3 - store a matrix in the hard disk.\n";
    std::cout << main_utils::MainUtils::tab << "4 - read a matrix from the hard disk.\n";
    std::cout << main_utils::MainUtils::tab << "9 - delete matrix.\n";
    std::cout << main_utils::MainUtils::tab << "10 - delete matrix from storage.\n";
    std::cout << main_utils::MainUtils::tab << "11 - hints.\n";
    std::cout << main_utils::MainUtils::tab << "0 - exit program.\n";
    // std::cout << "Menu\n";
    // std::cout << "Menu\n";
    std::cout << std::endl
              << main_utils::MainUtils::tab;
    std::cin >> this->menu;

    std::cout << std::endl;
}

void main_utils::MainUtils::clear_matrices()
{
    (this->matrices).clear();
}

void main_utils::MainUtils::delete_matrix(std::string name)
{
    (this->matrices).erase(name);
}

main_utils::ActionResponse *main_utils::MainUtils::perform_action_menu()
{
    main_utils::ActionResponse *response = new main_utils::ActionResponse;

    switch (this->menu)
    {
    case 0:
    {
        response->set_action_response("", false); /* Returning if the program needs to continue running */
        break;
    }
    case 1:
    {
        std::string newMatrixName = this->receive_matrix();
        std::string responseMessage = "\n" + main_utils::MainUtils::tab + "The new matrix was stored in the variable: " + newMatrixName + "\n";
        response->set_action_response(responseMessage, true);

        break;
    }
    case 2:
    {
        std::string responseMessage = this->print_matrix();
        response->set_action_response(responseMessage, true);

        break;
    }
    case 3:
    {
        std::string responseMessage = this->store_matrix_hard_disk();
        response->set_action_response(responseMessage, true);
        break;
    }
    case 4:
    {
        this->read_matrix_hard_disk();
        std::string responseMessage = "";
        response->set_action_response(responseMessage, true);
        break;
    }
    case 9:
    {
        // this->delete_matrix_from_matrices();
        std::string responseMessage = "";
        response->set_action_response(responseMessage, true);
        break;
    }
    case 10:
    {
        // this->delete_matrix_from_storage();
        std::string responseMessage = "";
        response->set_action_response(responseMessage, true);
        break;
    }
    case 11:
    {
        this->print_hints();
        std::string responseMessage = "";
        response->set_action_response(responseMessage, true);
        break;
    }
    default:
        break;
    }

    return response;
}

long long int main_utils::MainUtils::str_to_number(const std::string str)
{
    long long int number = 0;
    bool isNegative = (str.at(0) == '-');

    int strLength = str.length();
    long long unsigned int decimalPlace = 1;
    const int stopFlag = (isNegative ? 0 : -1);
    for (int i = strLength - 1; i != stopFlag; i--)
    {
        int digit = (str.at(i) - '0');
        number += (digit * decimalPlace);
        decimalPlace *= 10;
    }

    if (isNegative)
    {
        number *= -1;
    }

    return number;
}

std::string main_utils::MainUtils::insert_matrix(matrix::Matrix *matrix)
{
    std::string name = "m";

    if ((this->matrices).empty())
    {
        name += "1";
    }
    else
    {
        std::string lastPairName = (--(this->matrices).end())->first;
        lastPairName.at(0) = '0';
        int lastPairNameNumber = str_to_number(lastPairName);
        int newPairNameNumber = lastPairNameNumber + 1;

        name += std::to_string(newPairNameNumber);
    }

    (this->matrices).insert({name, matrix});

    return name;
}

matrix::Matrix *main_utils::MainUtils::find_matrix_in_matrices(std::string name)
{
    std::map<std::string, matrix::Matrix *>::iterator it;
    it = (this->matrices).find(name);
    if (it != (this->matrices).end())
    {
        matrix::Matrix *item = it->second;
        return item;
    }
    else
    {
        return NULL;
    }
}

std::string main_utils::MainUtils::receive_matrix()
{
    system("clear");

    std::cout << main_utils::MainUtils::tab << "Input the number of lines and then the number columns of the new matrix.\n";

    int lines, columns;
    std::cout << main_utils::MainUtils::tab;
    std::cin >> lines;
    std::cout << main_utils::MainUtils::tab;
    std::cin >> columns;

    matrix::Matrix *newMatrix = new matrix::Matrix(lines, columns);
    for (int i = 0; i < newMatrix->get_lines_quantity(); i++)
    {
        matrix::MatrixLine *tempLine = new matrix::MatrixLine();
        newMatrix->add_line(tempLine);

        for (int j = 0; j < newMatrix->get_columns_quantity(); j++)
        {
            tempLine->add_element(0);
        }
    }

    bool insertionOccurring = true;
    while (insertionOccurring)
    {
        system("clear");
        newMatrix->print_matrix();

        std::string input;

        std::cout << main_utils::MainUtils::tab;
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
            int integerInput = this->str_to_number(input);
            newMatrix->add_item_matrix(integerInput);

            if (newMatrix->is_in_last_position())
            {
                insertionOccurring = false;
                newMatrix->set_current_targed_line(newMatrix->get_current_targed_line() + 1);
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

    std::string newMatrixName = this->insert_matrix(newMatrix);

    return newMatrixName;
}

std::string main_utils::MainUtils::print_matrix()
{
    std::string responseMessage;

    std::string matrixName;
    std::cout << main_utils::MainUtils::tab << "Insert a matrix name of the matrix to be printed.\n";
    std::cout << main_utils::MainUtils::tab;
    std::cin >> matrixName;

    matrix::Matrix *matrix = this->find_matrix_in_matrices(matrixName);
    if (matrix != NULL)
    {
        matrix->print_matrix(true);
        responseMessage = "";
    }
    else
    {
        responseMessage = "\n" + main_utils::MainUtils::tab + "There is not a matrix with this name\n";
    }

    return responseMessage;
}

void main_utils::MainUtils::print_hints()
{
    std::cout << std::endl
              << "\tHint 1: if you are inserting data in a matrix and would like to insert in the previous data, input \"bs\" (short for backspace).\n";

    int exit = 1;
    std::cout << std::endl
              << main_utils::MainUtils::tab << "Input 0 to stop printing\n";
    while (exit != 0)
    {
        std::cout << main_utils::MainUtils::tab;
        std::cin >> exit;
    }
}

std::string main_utils::MainUtils::store_matrix_hard_disk()
{
    bool ableToStore;
    std::string strToReturn;

    std::string matrixName;

    std::cout << main_utils::MainUtils::tab << "Input a variable name to store: ";

    std::cin >> matrixName;

    std::cout << std::endl;

    matrix::Matrix *matrix;
    matrix = find_matrix_in_matrices(matrixName);

    if (matrix == NULL)
    {
        ableToStore = false;
    }
    else
    {
        std::string fileName;
        std::cout << main_utils::MainUtils::tab << "Input the name of the matrix in the hard disk: ";
        std::cin >> fileName;

        matrix::MatrixStorage *matrixInStorageFormat = new matrix::MatrixStorage;

        matrixInStorageFormat->set_matrix_storage(matrix);
        matrixInStorageFormat->set_file_name(fileName);

        ableToStore = matrixInStorageFormat->store_in_hard_disk();

        delete matrixInStorageFormat;
    }

    if (ableToStore)
    {
        strToReturn = main_utils::MainUtils::tab + "Stored succefully.";
    }
    else
    {
        strToReturn = main_utils::MainUtils::tab + "Error storing.";
    }

    return strToReturn;
}

bool main_utils::MainUtils::read_matrix_hard_disk()
{
    bool ableToRead;

    return ableToRead;
}

bool main_utils::MainUtils::delete_matrix_from_matrices()
{
}

bool main_utils::MainUtils::delete_matrix_from_storage()
{
}

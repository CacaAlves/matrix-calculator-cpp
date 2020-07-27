#include "main_utils.h"

main_utils::MainUtils::MainUtils() {}

void main_utils::MainUtils::welcome_message()
{
    system("clear");
    std::cout << " ---------------- Welcome to the Matrix Calculator! ---------------- \n";
}

bool main_utils::MainUtils::is_menu_a_valid_number()
{
    bool isAValidNumber;

    switch (this->menu)
    {
    case 0:
    case 1:
    case 2:
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
    system("clear");
    std::cout << "Menu\n Enter a number\n";
    std::cout << " 1 - enter a matrix\n";
    std::cout << " 2 - print matrix\n";
    std::cout << " 0 - exit program\n";
    // std::cout << "Menu\n";
    // std::cout << "Menu\n";
    std::cin >> this->menu;
}

int main_utils::MainUtils::get_menu()
{
    return this->menu;
}

void main_utils::MainUtils::clear_matrices()
{
    (this->matrices).clear();
}

void main_utils::MainUtils::delete_matrix(std::string name)
{
    (this->matrices).erase(name);
}

bool main_utils::MainUtils::perform_action_menu()
{
    switch (this->menu)
    {
    case 0:
        return false; /* Returning if the program needs to continue running */
        break;
    case 1:
        this->receive_matrix();
        return true;
        break;
    case 2:
        this->print_matrix();
        return true;
        break;
    case 3:
        /* nothing yet */
        break;
    default:
        break;
    }
}

long long int main_utils::MainUtils::str_to_number(const std::string &str)
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
    std::string name = "M";
    if ((this->matrices).empty())
    {
        name += "1";
    }
    else
    {
        auto lastPair = (this->matrices).end()--;
        std::string lastPairName = lastPair->first;
        lastPairName.at(0) = '0';
        int lastPairNameNumber = str_to_number(lastPairName);
        int newPairNameNumber = lastPairNameNumber++;

        name += std::to_string(newPairNameNumber);
    }

    (this->matrices).insert({name, matrix});

    return name;
}

matrix::Matrix *main_utils::MainUtils::find(std::string name)
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

void main_utils::MainUtils::receive_matrix()
{
    system("clear");

    std::cout << "Input the number of lines and then the number columns of the new matrix.\n";
    int lines, columns;
    std::cin >> lines >> columns;

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

        std::cin >> input;

        const int backspace = 8;
        if (((int)input.at(0)) == backspace)
        {
            newMatrix->set_current_targed_column(newMatrix->get_current_targed_column() - 1);
            if (newMatrix->get_current_targed_line() != 0 && newMatrix->get_current_targed_column() < 0)
            {
                newMatrix->set_current_targed_line(newMatrix->get_current_targed_line() - 1);
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
            }
            else
            {
                newMatrix->set_current_targed_column(newMatrix->get_current_targed_column() + 1);
                if (newMatrix->get_current_targed_column() + 1 > (newMatrix->get_lines_quantity()))
                {
                    newMatrix->set_current_targed_column(0);
                    newMatrix->set_current_targed_line(newMatrix->get_current_targed_line() + 1);
                }
            }
            
        }
    }

    std::string newMatrixName = this->insert_matrix(newMatrix);

    system("clear");

    std::cout << "Matrix saved in the variable: " << newMatrixName << std::endl;
}

void main_utils::MainUtils::print_matrix()
{
    system("clear");

    std::string matrixName;
    std::cout << "Insert a matrix name of the matrix to be printed.\n";
    std::cin >> matrixName;

    matrix::Matrix *matrix = this->find(matrixName);
    if (matrix != NULL)
    {
        matrix->print_matrix();
    }
    else
    {
        std::cout << "There is not a matrix with this name\n";
    }
}

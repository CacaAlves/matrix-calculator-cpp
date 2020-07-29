#include "main_utils.h"

void main_utils::ActionResponse::set_action_response(std::string message, bool running)
{
    this->message = message;
    this->running = running;
}

main_utils::MainUtils::MainUtils()
{
    (this->matrices) = new std::map<std::string, matrix::Matrix *>();
}

bool main_utils::MainUtils::is_a_digit(char c)
{
    bool isDigit;

    switch (c)
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        isDigit = true;
        break;
    default:
        isDigit = false;
        break;
    }

    return isDigit;
}

int main_utils::MainUtils::filtered_input()
{
    std::string input;
    std::string filteredInput = "";
    int inputToReturn = 0;
    bool isANumber = true;

    std::cin >> input;

    for (int i = 0; i < input.size(); i++)
    {
        if (i == 0 && input.at(0) == '-')
        {
            if (input.size() > 1)
            {
                filteredInput += input.at(0);
            }
            else
            {
                isANumber = false;
                break;
            }
        }
        else
        {

            if (this->is_a_digit(input.at(i)))
            {
                filteredInput += input.at(i);
            }
            else
            {
                isANumber = false;
                break;
            }
        }
    }

    inputToReturn = (isANumber ? (this->str_to_number(filteredInput)) : -1);

    return inputToReturn;
}

void main_utils::MainUtils::clear_matrices()
{
    (this->matrices)->clear();
}

void main_utils::MainUtils::delete_matrix(std::string name)
{
    (this->matrices)->erase(name);
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

    if ((this->matrices)->empty())
    {
        name += "1";
    }
    else
    {
        std::string lastPairName = (--(this->matrices)->end())->first;
        lastPairName.at(0) = '0';
        int lastPairNameNumber = str_to_number(lastPairName);
        int newPairNameNumber = lastPairNameNumber + 1;

        name += std::to_string(newPairNameNumber);
    }

    (this->matrices)->insert({name, matrix});

    return name;
}

matrix::Matrix *main_utils::MainUtils::find_matrix_in_matrices(std::string name)
{
    std::map<std::string, matrix::Matrix *>::iterator it;
    it = (this->matrices)->find(name);
    if (it != (this->matrices)->end())
    {
        matrix::Matrix *item = it->second;
        return item;
    }
    else
    {
        return NULL;
    }
}

matrix::Matrix *main_utils::MainUtils::get_matrix_zero(int lines, int columns)
{
    matrix::Matrix *matrixZero = new matrix::Matrix(lines, columns);

    for (int i = 0; i < matrixZero->get_lines_quantity(); i++)
    {
        matrix::MatrixLine *tempLine = new matrix::MatrixLine();
        matrixZero->add_line(tempLine);

        for (int j = 0; j < matrixZero->get_columns_quantity(); j++)
        {
            tempLine->add_element(0);
        }
    }

    return matrixZero;
}

std::string main_utils::MainUtils::receive_matrix()
{

    int lines = 0, columns = 0;

    std::cout << this->tab << "Input the number of lines and then the number columns of the new matrix.\n";

    do
    {
        if (lines < 0 || columns < 0)
        {
            std::cout << this->tab << "Input a positive number.\n";
        }

        std::cout << this->tab;
        lines = this->filtered_input();

        std::cout << this->tab;
        columns = this->filtered_input();

        system("clear");

    } while (lines < 0 || columns < 0);

    matrix::Matrix *newMatrix = this->get_matrix_zero(lines, columns);

    bool insertionOccurring = true;
    while (insertionOccurring)
    {
        system("clear");
        newMatrix->print_matrix();

        std::string input;

        std::cout << this->tab;
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
    std::cout << this->tab << "Insert a matrix name of the matrix to be printed.\n";
    std::cout << this->tab;
    std::cin >> matrixName;

    matrix::Matrix *matrix = this->find_matrix_in_matrices(matrixName);
    if (matrix != NULL)
    {
        matrix->print_matrix(true);
        responseMessage = "";
    }
    else
    {
        responseMessage = "\n" + this->tab + "There is not a matrix with this name\n";
    }

    return responseMessage;
}

std::string main_utils::MainUtils::print_all_matrices()
{
    std::string responseMessage;

    if (this->matrices->empty())
    {
        responseMessage = this->tab + "There is no matrices to print\n";
    }
    else
    {
        responseMessage = "";
        for (auto it = (this->matrices)->begin(); it != (this->matrices)->end(); it++)
        {
            std::cout << this->tab << "Matrix " << it->first << ": \n";

            matrix::Matrix *matrix = it->second;
            bool isLastOne = ((++it) == (this->matrices)->end());
            it--;

            matrix->print_matrix(isLastOne);

            std::cout << std::endl;
        }
    }

    return responseMessage;
}

std::string main_utils::MainUtils::delete_matrix_from_matrices()
{
    std::string strToReturn;

    std::string matrixName = "";

    while (matrixName != "0")
    {
        std::cout << this->tab << "Input a matrix name to delete from list of variables (input \"0\" to stop inputting): ";

        std::cin >> matrixName;

        this->delete_matrix(matrixName);
    }

    strToReturn = this->tab + "Deleted, if any.\n";
    return strToReturn;
}

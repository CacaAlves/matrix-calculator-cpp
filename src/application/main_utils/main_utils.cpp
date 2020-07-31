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

int main_utils::MainUtils::filtered_input(int returnWhenNaN)
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

    inputToReturn = (isANumber ? (this->str_to_number(filteredInput)) : returnWhenNaN);

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
        std::string matrixName = (this->get_greater_matrix_in_matrices());
        matrix::Matrix *matrix = this->find_matrix_in_matrices(matrixName);

        std::string lastPairName = this->get_greater_matrix_in_matrices();
        std::string numberStrFormat = lastPairName.substr(1);

        int lastPairNameNumber = this->str_to_number(numberStrFormat);
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

std::string main_utils::MainUtils::get_greater_matrix_in_matrices()
{
    std::string greaterName = "";

    if (!(this->matrices)->empty())
    {
        for (auto it = (this->matrices)->begin(); it != (this->matrices)->end(); it++)
        {
            if (greaterName.size() == 0)
            {
                greaterName = it->first;
            }
            else
            {
                int greaterNumber = this->str_to_number(
                    (greaterName).substr(1));

                std::string matrixName = it->first;
                int matrixNumber = str_to_number(
                    (it->first).substr(1));

                if (matrixNumber > greaterNumber)
                {
                    greaterName = matrixName;
                }
            }
        }
    }

    return greaterName;
}

std::string main_utils::MainUtils::get_first_matrix_in_matrices()
{
    std::string strToReturn = "";
    if (!(this->matrices)->empty())
    {
        strToReturn = "m1";
    }

    return strToReturn;
}

std::string main_utils::MainUtils::get_next_to(std::string currentMatrixName)
{
    int currentNumber = this->str_to_number(
        (currentMatrixName).substr(1));
    std::string nextName = "";

    if (!(this->matrices)->empty())
    {
        for (auto it = (this->matrices)->begin(); it != (this->matrices)->end(); it++)
        {
            std::string matrixName = it->first;
            int matrixNumber = str_to_number(
                (it->first).substr(1));

            if (matrixNumber - 1 == currentNumber)
            {
                nextName = matrixName;
                break;
            }
        }
    }

    return nextName;
}

#include "main_utils.h"

void main_utils::ActionResponse::set_action_response(std::string message, bool running)
{
    this->message = message;
    this->running = running;
}

main_utils::MainUtils::MainUtils() {}

void main_utils::MainUtils::welcome_message()
{
    std::cout << this->tab << " ---------------- Welcome to the Matrix Calculator! ---------------- \n";
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
    case 5:
    case 6:
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
    std::cout
        << this->tab << "Menu\n\n";
    std::cout << this->tab << "Enter a number:\n";
    std::cout << this->tab << "1 - enter a matrix.\n";
    std::cout << this->tab << "2 - print a matrix.\n";
    std::cout << this->tab << "3 - operations between matrices.\n";
    std::cout << this->tab << "4 - delete a matrix (from variables).\n";
    std::cout << this->tab << "5 - store / read / delete from Hard Disk.\n";
    std::cout << this->tab << "6 - hints.\n";
    std::cout << this->tab << "0 - exit program.\n";

    std::cout << std::endl
              << this->tab;
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
        std::string responseMessage = "\n" + this->tab + "The new matrix was stored in the constant: " + newMatrixName + "\n";
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
        response = (this->manage_operations());
        break;
    }
    case 4:
    {
        response = new main_utils::ActionResponse;
        std::string responseMessage = this->delete_matrix_from_matrices();
        response->set_action_response(responseMessage, true);
        break;
    }
    case 5:
    {
        response = this->manage_hard_disk();
        break;
    }
    case 6:
    {
        response = new main_utils::ActionResponse;
        this->print_hints();
        std::string responseMessage = "";
        response->set_action_response(responseMessage, true);
        break;
    }
    default:
        response = new main_utils::ActionResponse;
        std::string responseMessage = this->tab + "Input a valid input\n";
        response->set_action_response(responseMessage, true);
        break;
    }

    return response;
}

void main_utils::MainUtils::print_receive_menu_hard_disk()
{
    std::cout << std::endl
              << this->tab << "Menu storage\n\n";
    std::cout << this->tab << "Enter a number:\n";
    std::cout << this->tab << "1 - store a matrix in the storage.\n";
    std::cout << this->tab << "2 - read a matrix from the storage.\n";
    std::cout << this->tab << "3 - delete matrix from the storage.\n";
    std::cout << this->tab << "0 - cancel.\n";

    std::cout << std::endl
              << this->tab;
    std::cin >> this->menuHardDisk;

    std::cout << std::endl;
}

bool main_utils::MainUtils::is_menu_hard_disk_a_valid_number()
{
    bool isAValidNumber;

    switch (this->menuHardDisk)
    {
    case 1:
    case 2:
    case 3:
    case 0:
        isAValidNumber = true;
        break;
    default:
        isAValidNumber = false;
        break;
    }

    return isAValidNumber;
}

main_utils::ActionResponse *main_utils::MainUtils::manage_hard_disk()
{
    do
    {
        this->print_receive_menu_hard_disk();

    } while (!(this->is_menu_hard_disk_a_valid_number()));

    system("clear");

    ActionResponse *response = perform_action_menu_hard_disk();
    return response;
}

main_utils::ActionResponse *main_utils::MainUtils::perform_action_menu_hard_disk()
{
    main_utils::ActionResponse *response = new main_utils::ActionResponse;

    switch (this->menuHardDisk)
    {
    case 0:
    {
        std::string responseMessage = "";
        response->set_action_response(responseMessage, true);
        break;
    }
    case 1:
    {
        std::string responseMessage = this->store_matrix_hard_disk();
        response->set_action_response(responseMessage, true);
        break;
    }
    case 2:
    {
        std::string responseMessage = this->read_matrix_hard_disk();
        response->set_action_response(responseMessage, true);
        break;
    }
    case 3:
    {
        std::string responseMessage = this->delete_matrix_hard_disk();
        response->set_action_response(responseMessage, true);
        break;
    }
    default:
        break;
    }

    return response;
}

void main_utils::MainUtils::print_receive_menu_operations()
{
    std::cout << std::endl
              << this->tab << "Menu operations\n\n";
    std::cout << this->tab << "Enter a number:\n";
    std::cout << this->tab << "1 - equality between matrices.\n";
    std::cout << this->tab << "2 - sum two matrices.\n";
    std::cout << this->tab << "3 - subtraction between two matrices.\n";
    std::cout << this->tab << "4 - multiply a matrice by a constant.\n";
    std::cout << this->tab << "0 - cancel.\n";

    std::cout << std::endl
              << this->tab;
    std::cin >> this->menuOperations;

    std::cout << std::endl;
}

bool main_utils::MainUtils::is_menu_operations_a_valid_number()
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

main_utils::ActionResponse *main_utils::MainUtils::manage_operations()
{
    do
    {
        this->print_receive_menu_operations();

    } while (!(this->is_menu_operations_a_valid_number()));

    system("clear");

    ActionResponse *response = perform_action_menu_operations();
    return response;
}

main_utils::ActionResponse *main_utils::MainUtils::perform_action_menu_operations()
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
        std::string responseMessage = this->delete_matrix_hard_disk();
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
    std::cout << this->tab << "Input the number of lines and then the number columns of the new matrix.\n";

    int lines, columns;
    std::cout << this->tab;
    std::cin >> lines;
    std::cout << this->tab;
    std::cin >> columns;

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

void main_utils::MainUtils::print_hints()
{
    std::cout << std::endl
              << "\tHint 1: if you are inserting data in a matrix and would like to insert in the previous data, input \"bs\" (short for backspace).\n";

    int exit = 1;
    std::cout << std::endl
              << this->tab << "Input 0 to stop printing\n";
    while (exit != 0)
    {
        std::cout << this->tab;
        std::cin >> exit;
    }
}

std::string main_utils::MainUtils::store_matrix_hard_disk()
{
    bool ableToStore;
    std::string strToReturn;

    std::string matrixName;

    std::cout << this->tab << "Input a matrix name to store: ";

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
        std::cout << this->tab << "Input the name of the matrix in the storage: ";
        std::cin >> fileName;

        matrix::MatrixStorage *matrixInStorageFormat = new matrix::MatrixStorage();

        matrixInStorageFormat->set_matrix_storage(matrix);
        matrixInStorageFormat->set_file_name(fileName);

        ableToStore = matrixInStorageFormat->store_in_hard_disk();

        delete matrixInStorageFormat;
    }

    if (ableToStore)
    {
        strToReturn = this->tab + "Stored succefully.";
    }
    else
    {
        strToReturn = this->tab + "Error storing: there is no matrix with that name on list of matrices.\n";
    }

    return strToReturn;
}

std::string main_utils::MainUtils::read_matrix_hard_disk()
{
    bool ableToRead;
    std::string strToReturn;

    std::string matrixName;

    std::cout << this->tab << "Input a matrix name to read: ";

    std::cin >> matrixName;

    matrix::Matrix *readMatrix = matrix::MatrixStorage::read_from_hard_disk(matrixName);

    ableToRead = !(readMatrix == NULL);

    if (ableToRead)
    {
        std::string readMatrixNamethis = this->insert_matrix(readMatrix);
        strToReturn = this->tab + "The new matrix was stored in the constant: " + readMatrixNamethis + "\n";
    }
    else
    {
        strToReturn = this->tab + "Error reading: there is no matrix with that name on Hard Disk.\n";
    }

    return strToReturn;
}

std::string main_utils::MainUtils::delete_matrix_hard_disk()
{
    std::string strToReturn;

    std::string matrixName;

    std::cout << this->tab << "Input a matrix name to delete from Hard Disk: ";

    std::cin >> matrixName;

    matrix::MatrixStorage::delete_from_hard_disk(matrixName);

    strToReturn = this->tab + "Deleted, if any.\n";
    return strToReturn;
}

std::string main_utils::MainUtils::delete_matrix_from_matrices()
{
    std::string strToReturn;

    std::string matrixName;

    std::cout << this->tab << "Input a matrix name to delete from list of variables: ";

    std::cin >> matrixName;

    this->delete_matrix(matrixName);

    strToReturn = this->tab + "Deleted, if any.\n";
    return strToReturn;
}

std::string main_utils::MainUtils::equality_between_matrices()
{
    std::string strToReturn;
    bool equality;

    std::string matrix1Name;
    std::string matrix2Name;

    std::cout << this->tab << "Input a matrix name: ";
    std::cin >> matrix1Name;

    std::cout << this->tab << "Input a second matrix name to be compared: ";
    std::cin >> matrix2Name;

    matrix::Matrix *matrix1 = this->find_matrix_in_matrices(matrix1Name);
    matrix::Matrix *matrix2 = this->find_matrix_in_matrices(matrix2Name);

    if (matrix1 == NULL || matrix2 == NULL)
    {
        equality = false;
        strToReturn = this->tab + "One or both of the matrices are not in the list of variables\n";
    }
    else
    {
        equality = matrix1->equality_between_matrices(matrix2);
    }

    if (equality)
    {
        strToReturn = this->tab + "The matrix " + matrix1Name + " and the matrix " +
                      matrix2Name + " are equals\n";
    }
    else if (strToReturn.size() == 0)
    {
        strToReturn = this->tab + "The matrix " + matrix1Name + " and the matrix " +
                      matrix2Name + " are NOT equals\n";
    }

    return strToReturn;
}

std::string main_utils::MainUtils::sum_of_matrices()
{
    std::string strToReturn;
    bool ableToSum = true;

    std::string matrixName;
    std::vector<matrix::Matrix *> matricesToSum;
    int linesQuantity;
    int columnsQuantity;

    while (matrixName != "0" && ableToSum)
    {
        std::cout << this->tab << "Input a matrix name to sum (input 0 to stop): ";
        std::cin >> matrixName;

        if (matrixName != "0")
        {

            matrix::Matrix *matrix = find_matrix_in_matrices(matrixName);

            if (matrix == NULL)
            {
                strToReturn = this->tab + "One of the matrices in the input does not exist\n";
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
                ableToSum = (linesQuantity == temp->get_lines_quantity() && columnsQuantity == temp->get_columns_quantity());
            }

            if (!ableToSum)
            {
                break;
            }
        }
    }

    if (ableToSum)
    {
        matrix::Matrix *sumMatrix = get_matrix_zero(linesQuantity, columnsQuantity);

        for (matrix::Matrix *temp : matricesToSum)
        {
            sumMatrix->sum_of_two_matrix(temp);
        }

        std::string sumMatrixName = this->insert_matrix(sumMatrix);
        strToReturn = this->tab + "The new matrix was stored in the constant: " + sumMatrixName + "\n";

        sumMatrix->set_current_targed_line(sumMatrix->get_lines_quantity()); //setting the target to after the last element
    }
    else if (!ableToSum && strToReturn.size() == 0)
    {
        strToReturn = this->tab + "Something went wrong: Unable to sum\n";
    }

    matricesToSum.clear();
    return strToReturn;
}
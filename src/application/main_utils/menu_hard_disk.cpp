#include "menu_hard_disk.h"

void main_utils::MenuHardDisk::print_receive_menu_hard_disk()
{
    std::cout << std::endl
              << (this->utils)->tab << "Menu storage\n\n";
    std::cout << (this->utils)->tab << "Enter a number:\n";
    std::cout << (this->utils)->tab << "1 - store a matrix in the storage.\n";
    std::cout << (this->utils)->tab << "2 - read a matrix from the storage.\n";
    std::cout << (this->utils)->tab << "3 - delete matrix from the storage.\n";
    std::cout << (this->utils)->tab << "0 - cancel.\n";

    std::cout << std::endl
              << (this->utils)->tab;
    this->menuHardDisk = (this->utils)->filtered_input();

    std::cout << std::endl;
}

bool main_utils::MenuHardDisk::is_menu_hard_disk_a_valid_number()
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

main_utils::ActionResponse *main_utils::MenuHardDisk::manage_hard_disk()
{
    do
    {
        this->print_receive_menu_hard_disk();
        system("clear");
    } while (!(this->is_menu_hard_disk_a_valid_number()));

    ActionResponse *response = perform_action_menu_hard_disk();
    return response;
}

main_utils::ActionResponse *main_utils::MenuHardDisk::perform_action_menu_hard_disk()
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

std::string main_utils::MenuHardDisk::store_matrix_hard_disk()
{
    bool ableToStore;
    std::string strToReturn;

    std::string matrixName;

    std::cout << (this->utils)->tab << "Input a matrix name to store: ";

    std::cin >> matrixName;

    std::cout << std::endl;

    matrix::Matrix *matrix;
    matrix = (this->utils)->find_matrix_in_matrices(matrixName);

    if (matrix == NULL)
    {
        ableToStore = false;
    }
    else
    {
        std::string fileName;
        std::cout << (this->utils)->tab << "Input the name of the matrix in the storage: ";
        std::cin >> fileName;

        matrix::MatrixStorage *matrixInStorageFormat = new matrix::MatrixStorage();

        matrixInStorageFormat->set_matrix_storage(matrix);
        matrixInStorageFormat->set_file_name(fileName);

        ableToStore = matrixInStorageFormat->store_in_hard_disk();

        delete matrixInStorageFormat;
    }

    if (ableToStore)
    {
        strToReturn = (this->utils)->tab + "Stored succefully.";
    }
    else
    {
        strToReturn = (this->utils)->tab + "Error storing: there is no matrix with that name on list of matrices.\n";
    }

    return strToReturn;
}

std::string main_utils::MenuHardDisk::read_matrix_hard_disk()
{
    bool ableToRead;
    std::string strToReturn;

    std::string matrixName;

    std::cout << (this->utils)->tab << "Input a matrix name to read: ";

    std::cin >> matrixName;

    matrix::Matrix *readMatrix = matrix::MatrixStorage::read_from_hard_disk(matrixName);

    ableToRead = !(readMatrix == NULL);

    if (ableToRead)
    {
        std::string readMatrixNamethis = (this->utils)->insert_matrix(readMatrix);
        strToReturn = (this->utils)->tab + "The new matrix was stored in the constant: " + readMatrixNamethis + "\n";
    }
    else
    {
        strToReturn = (this->utils)->tab + "Error reading: there is no matrix with that name on Hard Disk.\n";
    }

    return strToReturn;
}

std::string main_utils::MenuHardDisk::delete_matrix_hard_disk()
{
    std::string strToReturn;

    std::string matrixName;

    std::cout << (this->utils)->tab << "Input a matrix name to delete from Hard Disk: ";

    std::cin >> matrixName;

    matrix::MatrixStorage::delete_from_hard_disk(matrixName);

    strToReturn = (this->utils)->tab + "Deleted, if any.\n";
    return strToReturn;
}

void main_utils::MenuHardDisk::set_main_utils(main_utils::MainUtils *utils)
{
    this->utils = utils;
}
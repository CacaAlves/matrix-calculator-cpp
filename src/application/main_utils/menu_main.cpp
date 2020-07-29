#include "menu_main.h"

main_utils::MenuMain::MenuMain()
{
    (this->menuHardDisk) = new main_utils::MenuHardDisk();
    (this->MenuOperations) = new main_utils::MenuOperations();
}

main_utils::MenuMain::~MenuMain()
{
    delete (this->menuHardDisk);
    delete (this->MenuOperations);
}

void main_utils::MenuMain::set_main_utils(main_utils::MainUtils *utils)
{
    this->utils = utils;
    (this->menuHardDisk)->set_main_utils(utils);
    (this->MenuOperations)->set_main_utils(utils);
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
    std::cout << (this->utils)->tab << "5 - delete a matrix (from variables).\n";
    std::cout << (this->utils)->tab << "6 - store / read / delete from Hard Disk.\n";
    std::cout << (this->utils)->tab << "7 - hints.\n";
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
        std::string newMatrixName = (this->utils)->receive_matrix();
        std::string responseMessage = "\n" + (this->utils)->tab + "The new matrix was stored in the constant: " + newMatrixName + "\n";
        response->set_action_response(responseMessage, true);

        break;
    }
    case 2:
    {
        response = new main_utils::ActionResponse;
        std::string responseMessage = (this->utils)->print_matrix();
        response->set_action_response(responseMessage, true);

        break;
    }
    case 3:
    {
        response = new main_utils::ActionResponse;
        std::string responseMessage = (this->utils)->print_all_matrices();
        response->set_action_response(responseMessage, true);
        break;
    }
    case 4:
    {
        response = ((this->MenuOperations)->manage_operations());
        break;
    }
    case 5:
    {
        response = new main_utils::ActionResponse;
        std::string responseMessage = (this->utils)->delete_matrix_from_matrices();
        response->set_action_response(responseMessage, true);
        break;
    }
    case 6:
    {
        response = (this->menuHardDisk)->manage_hard_disk();
        break;
    }
    case 7:
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

    int exit = 1;
    std::cout << std::endl
              << (this->utils)->tab << "Input 0 to stop printing\n";
    while (exit != 0)
    {
        std::cout << (this->utils)->tab;
        exit = (this->utils)->filtered_input();
    }
}
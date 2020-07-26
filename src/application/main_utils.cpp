#include "main_utils.h"

main_utils::MainUtils::MainUtils()
{

}

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
    case 1:
    case 2:
    case -1:
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
    std::cout << "-1 - exit program\n";
    // std::cout << "Menu\n";
    // std::cout << "Menu\n";
    std::cin >> this->menu;
}

int main_utils::MainUtils::get_menu()
{
    return this->menu;
}
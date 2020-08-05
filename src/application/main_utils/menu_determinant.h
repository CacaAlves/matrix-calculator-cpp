#ifndef MENU_DETERMINANT
#define MENU_DETERMINANT

#include <iostream>
#include "main_utils.h"
#include "./../../matrix/matrix.h"

namespace main_utils
{
    class MenuDeterminant
    {
    public:
        ActionResponse *manage_determinant();
        void set_main_utils(main_utils::MainUtils *utils);

    private:
        int menuDeterminant;
        main_utils::MainUtils *utils;
        void print_receive_menu_determinant();
        bool is_menu_determinant_a_valid_number();
        ActionResponse *perform_action_menu_determinant();
        std::string calculate_determinant();
    };
} // namespace main_utils

#endif
#ifndef MENU_MAIN
#define MENU_MAIN

#include <iostream>
#include <vector>
#include "main_utils.h"
#include "menu_hard_disk.h"
#include "menu_operations.h"
#include "menu_determinant.h"

namespace main_utils
{
    class MenuMain
    {
    public:
        int menu;
        MenuMain();
        ~MenuMain();
        void set_main_utils(main_utils::MainUtils *utils);
        void welcome_message();
        void print_receive_menu();
        bool is_menu_a_valid_number();
        ActionResponse *perform_action_menu();
    private:
        main_utils::MenuHardDisk *menuHardDisk;
        main_utils::MenuOperations *menuOperations;
        main_utils::MenuDeterminant *menuDeterminant;
        main_utils::MainUtils *utils;
        std::string receive_matrix();
        std::string print_matrix();
        std::string print_all_matrices();
        void print_hints();
    };
} // namespace main_utils

#endif
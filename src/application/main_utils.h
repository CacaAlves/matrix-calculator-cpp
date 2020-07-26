#ifndef MAIN_UTILS
#define MAIN_UTILS

#include <iostream>
#include <stdlib.h>

namespace main_utils
{

    class MainUtils
    {
    public:
        MainUtils();
        void welcome_message();
        bool is_menu_a_valid_number();
        void print_receive_menu();
        int get_menu();

    private:
        int menu;
    };
} // namespace main

#endif
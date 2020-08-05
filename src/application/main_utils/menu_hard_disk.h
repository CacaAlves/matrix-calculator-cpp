#ifndef MENU_HARD_DISK
#define MENU_HARD_DISK

#include <iostream>
#include "main_utils.h"

namespace main_utils
{
    class MenuHardDisk
    {
    public:
        ActionResponse *manage_hard_disk();
        void set_main_utils(main_utils::MainUtils *utils);
    private:
        int menuHardDisk;
        main_utils::MainUtils *utils;
        void print_receive_menu_hard_disk();
        bool is_menu_hard_disk_a_valid_number();
        ActionResponse *perform_action_menu_hard_disk();
        std::string store_matrix_hard_disk();
        std::string read_matrix_hard_disk();
        std::string delete_matrix_hard_disk();
    };
} // namespace main_utils

#endif
#include <iostream>
#include "main_utils.h"

int main(int argc, char const *argv[])
{
    main_utils::MainUtils *utils = new main_utils::MainUtils();
    utils->welcome_message();

    bool running = true;

    while (running)
    {
        do
        {
            utils->print_receive_menu();
        }
        while (!(utils->is_menu_a_valid_number()));

        switch (utils->get_menu())
        {
        case -1:
            running = false;
            break;
        
        default:
            break;
        }
    }


    return 1;
}

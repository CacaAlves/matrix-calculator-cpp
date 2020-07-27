#include <iostream>
#include "main_utils.h"

int main(int argc, char const *argv[])
{
    main_utils::MainUtils utils;
    utils.welcome_message();

    bool running = true;

    while (running)
    {
        do
        {
            utils.print_receive_menu();
        } while (!(utils.is_menu_a_valid_number()));

        running = utils.perform_action_menu();
    }

    return 1;
}

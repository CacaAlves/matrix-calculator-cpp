#include <iostream>
#include "./main_utils/main_utils.h"
#include "./main_utils/menu_main.h"

int main(int argc, char const *argv[])
{
    main_utils::MainUtils *utils = new main_utils::MainUtils();
    main_utils::MenuMain *menuMain = new main_utils::MenuMain();
    menuMain->set_main_utils(utils);

    bool running = true;
    bool firstRunningLoop = true;
    main_utils::ActionResponse *response = NULL;

    while (running)
    {
        if (firstRunningLoop)
        {
            system("clear");
            menuMain->welcome_message();

            firstRunningLoop = false;
        }
        do
        {
            menuMain->print_receive_menu();
            system("clear");
        } while (!(menuMain->is_menu_a_valid_number()));

        response = menuMain->perform_action_menu();
        system("clear");

        std::cout << response->message;
        std::cout << std::endl;
        running = response->running;

        delete response;
        response = NULL;
    }

    return 1;
}

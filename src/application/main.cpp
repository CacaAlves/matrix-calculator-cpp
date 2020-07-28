#include <iostream>
#include "main_utils.h"

int main(int argc, char const *argv[])
{
    main_utils::MainUtils utils;

    bool running = true;
    bool firstRunningLoop = true;
    main_utils::ActionResponse *response = NULL;

    while (running)
    {
        if (firstRunningLoop)
        {
            system("clear");
            utils.welcome_message();

            firstRunningLoop = false;
        }
        do
        {
            utils.print_receive_menu();
        } while (!(utils.is_menu_a_valid_number()));

        system("clear");
        response = utils.perform_action_menu();
        system("clear");

        std::cout << response->message;
        std::cout << std::endl;
        running = response->running;

        delete response;
        response = NULL;
    }

    return 1;
}

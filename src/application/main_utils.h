#ifndef MAIN_UTILS
#define MAIN_UTILS


#include <iostream>
#include <stdlib.h>
#include <map>
#include "./../matrix/matrix.h"
#include "./../matrix/matrix_line.h"
#include "./../matrix/matrix_item.h"
#include "./../matrix/matrix_storage.h"

namespace main_utils
{
    struct ActionResponse
    {
    public:
        std::string message;
        bool running;
        void set_action_response(std::string message, bool running);
    };

    class MainUtils
    {
    public:
        const std::string tab = "\t\t\t\t\t\t";
        MainUtils();
        void welcome_message();
        bool is_menu_a_valid_number();
        void print_receive_menu();
        ActionResponse *perform_action_menu();
        int get_menu();

    private:
        std::map<std::string, matrix::Matrix *> matrices;
        void clear_matrices();
        void delete_matrix(std::string name);
        int menu;
        long long int str_to_number(const std::string str);
        std::string insert_matrix(matrix::Matrix *matrix);
        matrix::Matrix *find_matrix_in_matrices(std::string name);
        std::string receive_matrix();
        std::string print_matrix();
        void print_hints();
        std::string store_matrix_hard_disk();
        bool read_matrix_hard_disk();
        bool delete_matrix_from_matrices();
        bool delete_matrix_from_storage();
    };
} // namespace main_utils

#endif
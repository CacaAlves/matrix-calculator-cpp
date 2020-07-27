#ifndef MAIN_UTILS
#define MAIN_UTILS

#include <iostream>
#include <stdlib.h>
#include <map>
#include "./../matrix/matrix.h"
#include "./../matrix/matrix_line.h"
#include "./../matrix/matrix_item.h"

namespace main_utils
{

    class MainUtils
    {
    public:

        MainUtils();
        void welcome_message();
        bool is_menu_a_valid_number();
        void print_receive_menu();
        bool perform_action_menu();
        int get_menu();
    private:
        std::map<std::string, matrix::Matrix *> matrices;
        void clear_matrices();
        void delete_matrix(std::string name);
        int menu;
        long long int str_to_number(const std::string &str);
        std::string insert_matrix(matrix::Matrix *matrix);
        matrix::Matrix *find(std::string name);
        void receive_matrix();
        void print_matrix();
    };
} // namespace main

#endif
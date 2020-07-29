#ifndef MAIN_UTILS
#define MAIN_UTILS

#include <iostream>
#include <stdlib.h>
#include <map>
#include <vector>
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
        int filtered_menu_input();
        void clear_matrices();
        void delete_matrix(std::string name);
        int menu;
        int menuHardDisk;
        int menuOperations;
        long long int str_to_number(const std::string str);
        std::string insert_matrix(matrix::Matrix *matrix);
        matrix::Matrix *find_matrix_in_matrices(std::string name);
        matrix::Matrix *get_matrix_zero(int lines, int columns);
        std::string receive_matrix();
        std::string print_matrix();
        std::string print_all_matrices();
        void print_hints();
        std::string store_matrix_hard_disk();
        std::string read_matrix_hard_disk();
        std::string delete_matrix_hard_disk();
        std::string delete_matrix_from_matrices();
        ActionResponse *manage_hard_disk();
        void print_receive_menu_hard_disk();
        bool is_menu_hard_disk_a_valid_number();
        ActionResponse *perform_action_menu_hard_disk();
        ActionResponse *manage_operations();
        void print_receive_menu_operations();
        bool is_menu_operations_a_valid_number();
        ActionResponse *perform_action_menu_operations();
        std::string equality_between_matrices();
        std::string sum_of_matrices();
    };
} // namespace main_utils

#endif
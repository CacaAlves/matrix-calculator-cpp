#ifndef MENU_OPERATIONS
#define MENU_OPERATIONS

#include <iostream>
#include <vector>
#include "main_utils.h"

namespace main_utils
{
    class MenuOperations
    {
    public:
        ActionResponse *manage_operations();
        void set_main_utils(main_utils::MainUtils *utils);

    private:
        int menuOperations;
        main_utils::MainUtils *utils;
        void print_receive_menu_operations();
        bool is_menu_operations_a_valid_number();
        ActionResponse *perform_action_menu_operations();
        std::string equality_between_matrices();
        std::string sum_of_matrices();
        std::string difference_between_matrices();
        std::string multiply_matrix_by_constant();
        std::string multiply_matrix_by_matrix();
        std::string is_inverse_matrix();
        std::string transposed_matrix();
        std::string is_matrix_n(int n = -1);
        std::string is_symmetric_matrix();
        std::string is_anti_symmetric_matrix();
        std::string is_lower_triangular_matrix_matrix();
        std::string is_upper_triangular_matrix_matrix();
        std::string matrix_power();
    };
} // namespace main_utils

#endif
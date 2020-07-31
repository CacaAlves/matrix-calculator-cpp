#ifndef MAIN_UTILS
#define MAIN_UTILS

#include <iostream>
#include <stdlib.h>
#include <map>
#include "./../../matrix/matrix.h"
#include "./../../matrix/matrix_line.h"
#include "./../../matrix/matrix_item.h"
#include "./../../matrix/matrix_storage.h"

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
        std::string tab = "\t\t\t\t\t\t";
        MainUtils();
        int filtered_input(int returnWhenNaN = -1);
        std::string insert_matrix(matrix::Matrix *matrix);
        matrix::Matrix *find_matrix_in_matrices(std::string name);
        std::string delete_matrix_from_matrices();
        std::map<std::string, matrix::Matrix *> *matrices;
        long long int str_to_number(const std::string str);
        std::string get_greater_matrix_in_matrices();
        std::string get_first_matrix_in_matrices();
        std::string get_next_to(std::string currentMatrixName);

    private:
        void clear_matrices();
        void delete_matrix(std::string name);
        bool is_a_digit(char c);
    };
} // namespace main_utils

#endif
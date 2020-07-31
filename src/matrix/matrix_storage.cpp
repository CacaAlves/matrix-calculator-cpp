#include "matrix_storage.h"

matrix::MatrixStorage::MatrixStorage()
{
    this->items = new std::list<int>();
}

matrix::MatrixStorage::~MatrixStorage()
{
    (this->items)->clear();
}

void matrix::MatrixStorage::set_matrix_storage(matrix::Matrix *matrixToStore)
{
    this->linesQuantity = matrixToStore->get_lines_quantity();
    this->columnsQuantity = matrixToStore->get_columns_quantity();

    for (int line = 0; line < this->linesQuantity; line++)
    {
        for (int column = 0; column < this->columnsQuantity; column++)
        {
            (this->items)->push_back(matrixToStore->get_item(line, column)->get_data());
        }
    }
}

void matrix::MatrixStorage::set_file_name(std::string fileName)
{
    this->fileName = fileName;
}

bool matrix::MatrixStorage::store_in_hard_disk()
{
    bool ableToStore;

    std::string fileName = "./files/" + this->fileName + ".txt";
    std::string deleteFileScript = "rm " + fileName;
    const char *script1 = deleteFileScript.c_str();
    system(script1);
    std::string createFileScript = "touch " + fileName;
    const char *script2 = deleteFileScript.c_str();
    system(script2);

    std::ofstream file(fileName, std::ios_base::app);

    if (file.is_open())
    {

        file << this->linesQuantity << " " << this->columnsQuantity << std::endl;

        for (int line = 0; line < this->linesQuantity; line++)
        {
            for (int column = 0; column < this->columnsQuantity; column++)
            {
                file << (this->items)->front() << " ";

                (this->items)->pop_front();
            }

            file << std::endl;
        }

        ableToStore = true;
    }
    else
    {
        ableToStore = false;
    }

    file.close();

    return ableToStore;
}

matrix::Matrix *matrix::MatrixStorage::read_from_hard_disk(std::string fileName)
{
    std::string path = "./files/" + fileName + ".txt";
    FILE *file = fopen(path.c_str(), "r");

    matrix::Matrix *matrix = NULL;

    if (file != NULL)
    {
        int linesQuantity, columnsQuantity;
        fscanf(file, "%d %d", &linesQuantity, &columnsQuantity);

        matrix = new matrix::Matrix(linesQuantity, columnsQuantity);



        for (int i = 0; i < matrix->get_lines_quantity(); i++)
        {
            for (int j = 0; j < matrix->get_columns_quantity(); j++)
            {
                int element;
                fscanf(file, "%d", &element);
                matrix->set_item(i, j, element);

            }
        }

        matrix->set_target_to_after_end();
        fclose(file);
    }

    return matrix;
}

void matrix::MatrixStorage::delete_from_hard_disk(std::string fileName)
{
    std::string path = "./files/" + fileName + ".txt";

    std::string deleteFileScript = "rm " + path;
    const char *script1 = deleteFileScript.c_str();
    system(script1);
}

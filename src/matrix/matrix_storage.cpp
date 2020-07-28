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

void matrix::MatrixStorage::delete_from_hard_disk()
{
}

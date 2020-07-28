#include "matrix_item.h"

matrix::MatrixItem::MatrixItem() {}

matrix::MatrixItem::MatrixItem(int data)
{
    this->data = data;
}

matrix::MatrixItem::~MatrixItem() {}

void matrix::MatrixItem::set_data(int data)
{
    this->data = data;
}

int matrix::MatrixItem::get_data()
{
    return this->data;
}

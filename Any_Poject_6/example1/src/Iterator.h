#pragma once
#include "Cell.h"
class Iterator
{
public:
    Cell* _current_iter;
    Cell** _matrix;
    int row_size;
    int col_size;
    int iterable = 0;

    explicit Iterator(Cell* t_ptr) { _current_iter = t_ptr; row_size = col_size = 0; }
    explicit Iterator(Cell* t_ptr, int row, int col, Cell** _matrix);
    Iterator& operator++();
    Iterator& operator--();
    Cell* operator->();
    Cell operator* ();
    bool operator !=(Iterator&& t_iter);
};


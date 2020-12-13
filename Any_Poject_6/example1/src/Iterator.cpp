#include "Iterator.h"

Iterator& Iterator::operator++() {
    if (_current_iter == &_matrix[iterable][col_size - 1]) {
        iterable++;
        _current_iter = &_matrix[iterable][0];
    }
    else {
        _current_iter++;
    }

    return *this;
}

Cell* Iterator::operator->() {
    return _current_iter;
}

Cell Iterator::operator*() {
    return *_current_iter;
}

Iterator::Iterator(Cell* t_ptr, int row, int col, Cell** _matrix) {
    _current_iter = t_ptr;
    row_size = row;
    col_size = col;
    this->_matrix = _matrix;
}

bool Iterator::operator!=(Iterator&& t_iter) {
    return _current_iter != t_iter._current_iter;
}

Iterator& Iterator::operator--() {
    if (_current_iter == &_matrix[iterable][0]) {
        iterable--;
        _current_iter = &_matrix[iterable][col_size - 1];
    }
    else {
        _current_iter--;
    }
    return *this;
}

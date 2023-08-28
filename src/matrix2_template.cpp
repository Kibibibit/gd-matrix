#include "matrix2_template.h"
#include <vector>

using namespace godot;


template <class T>
void Matrix2Template<T>::_init(T empty_value, int width, int height) {
    this->size = Vector2i(width, height);
    for (int i = 0; i < width*height; i++) {
        this->data->push_back(empty_value);
    }
}

template <class T>
Matrix2Template<T>::Matrix2Template() {
    this->data = new std::vector<T>();
    this->size = Vector2i(0,0);
}

template <class T>
Matrix2Template<T>::~Matrix2Template() {
    delete this->data;
}


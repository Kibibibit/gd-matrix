#include "matrix2_template.h"
#include <vector>
#include <stdexcept>
#include <string>

template <class T>
Matrix2Template<T>::Matrix2Template(T empty_value, int width, int height)
{
    this->data = new std::vector<T>();
    this->width = width;
    this->height = height;
    this->empty_value = empty_value;
    for (int i = 0; i < width * height; i++)
    {
        this->data->push_back(empty_value);
    }
}

template <class T>
Matrix2Template<T>::~Matrix2Template()
{
    delete this->data;
}

template <class T>
int Matrix2Template<T>::get_index(int x, int y)
{
    if (this->contains_index(x, y))
    {
        return x + (this->width * y);
    } else {
        throw std::out_of_range("("+std::to_string(x)+","+std::to_string(y)+") is invalid for matrix of size ("+std::to_string(this->width)+","+std::to_string(this->height)+")");
    }
}

template <class T>
int Matrix2Template<T>::get_width()
{
    return this->width;
}

template <class T>
int Matrix2Template<T>::get_height()
{
    return this->height;
}

template <class T>
void Matrix2Template<T>::set_width(int width)
{
    this->resize(width, this->height);
}

template <class T>
void Matrix2Template<T>::set_height(int height)
{
    this->resize(this->width, height);
}

template <class T>
void Matrix2Template<T>::resize(int width, int height) {
    std::vector<T> new_data = std::vector<T>();

    new_data.resize(width*height);

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {

            if (contains_point(x,y)) {
                new_data[x+(width*y)] = at(x,y);
            } else {
                new_data[x+(width*y)] = empty_value;
            }
        }
    }

    for (int i = 0; i < new_data.size(); i++) {
        if (i < this->data.size()) {
            this->data->at(i) = new_data.at(i);
        } else {
            this->data->push_back(new_data.at(i));
        }
    }

    while (this->data->size() > width*height) {
        this->data->pop_back();
    }


    this->width = width;
    this->height = height;
}


template <class T>
T Matrix2Template<T>::at(int x, int y)
{
    return this->data->at(get_index(x, y));
}

template <class T>
bool Matrix2Template<T>::contains_point(int x, int y) {
    return x >= 0 && y >= 0 && x < this->width && y < this->height;
}
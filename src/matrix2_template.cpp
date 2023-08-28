#include "matrix2_template.h"
#include <vector>


template <class T>
Matrix2Template<T>::Matrix2Template(T empty_value, int width, int height)
{
    this->data = new std::vector<T>();
    this->width = width;
    this->height = height;
    this->empty_value = empty_value;
    for (int i = 0; i < width * height; i++)
    {
        this->data->push_back(this->empty_value);
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
    return x + (this->width * y);
    // if (this->contains_index(x, y))
    // {
        
    // }
    // else
    // {
    //     //throw std::out_of_range("(" + std::to_string(x) + "," + std::to_string(y) + ") is invalid for matrix of size (" + std::to_string(this->width) + "," + std::to_string(this->height) + ")");
    //     throw std::out_of_range("Bad index for matrix!");
    // }
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
void Matrix2Template<T>::set_width(int new_width)
{
    this->resize(new_width, this->height);
}

template <class T>
void Matrix2Template<T>::set_height(int new_height)
{
    this->resize(this->width, new_height);
}

template <class T>
void Matrix2Template<T>::resize(int new_width, int new_height)
{
    std::vector<T> new_data = std::vector<T>();

    for (int i = 0; i < new_width*new_height; i++) {
        new_data.push_back(empty_value);
    }

    for (int x = 0; x < new_width; x++)
    {
        for (int y = 0; y < new_height; y++)
        {

            if (contains_point(x, y))
            {
                new_data.at(x + (new_width * y)) = this->get_at(x, y);
            }
        }
    }
    for (int i = 0; i < (int) new_data.size(); i++)
    {
        if (i < (int) this->data->size())
        {
            this->data->at(i) = new_data.at(i);
        }
        else
        {
            // Only triggers if we're making the matrix bigger
            this->data->push_back(new_data.at(i));
        }
    }

    // Only triggers if we're making the matrix smaller
    while (this->data->size() > new_data.size())
    {
        this->data->pop_back();
    }

    this->width = new_width;
    this->height = new_height;
}

template <class T>
T Matrix2Template<T>::get_at(int x, int y)
{
    return this->data->at(get_index(x, y));
}

template <class T>
void Matrix2Template<T>::set_at(T value, int x, int y)
{
    this->data->at(get_index(x, y)) = value;
}

template <class T>
bool Matrix2Template<T>::contains_point(int x, int y)
{
    return x >= 0 && y >= 0 && x < this->width && y < this->height;
}


template class Matrix2Template<int>;
template class Matrix2Template<float>;
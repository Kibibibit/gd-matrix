#ifndef _GDMATRIX_MATRIX2_TEMPLATE_H
#define _GDMATRIX_MATRIX2_TEMPLATE_H

#include <vector>

template <class T>
class Matrix2Template
{

private:
    std::vector<T> * data;
    T empty_value;
    int width;
    int height;
    int get_index(int x, int y);

public:
    Matrix2Template(T empty_value, int width, int height);
    ~Matrix2Template();
    int get_width();
    int get_height();
    void set_width(int width);
    void set_height(int height);
    T get_at(int x, int y);
    void set_at(T value, int x, int y);
    void resize(int width, int height);
    bool contains_point(int x, int y);
};

#endif
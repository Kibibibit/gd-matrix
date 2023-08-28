#include "matrix2i.h"


using namespace godot;

Matrix2i::Matrix2i() {
    this->data = new Matrix2Template<int>(0,0,0);
}

Matrix2i::~Matrix2i() {
    delete this->data;
}

void Matrix2i::_bind_methods() {

}

void Matrix2i::_init(int width, int height) {
    this->data->resize(width, height);
}


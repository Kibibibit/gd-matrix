#include "matrix2i.h"
#include "matrix2_template.h"


using namespace godot;

Matrix2i::Matrix2i() {
    this->data = new Matrix2Template<int>(0,0,0);
}

Matrix2i::~Matrix2i() {
    delete this->data;
}

void Matrix2i::resize(int width, int height) {
    this->data->resize(width, height);
}


int Matrix2i::get_at(int x, int y) {
    return this->data->get_at(x,y);
}

int Matrix2i::get_at_v(Vector2i vector) {
    return this->data->get_at(vector.x, vector.y);
}

void Matrix2i::set_at(int value, int x, int y) {
    this->data->set_at(value, x, y);
}

void Matrix2i::set_at_v(int value, Vector2i vector) {
    set_at(value, vector.x, vector.y);
}

void Matrix2i::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_at", "x", "y"), &Matrix2i::get_at);
    ClassDB::bind_method(D_METHOD("get_at_v", "vector"), &Matrix2i::get_at_v);
    ClassDB::bind_method(D_METHOD("set_at", "value", "x", "y"), &Matrix2i::set_at);
    ClassDB::bind_method(D_METHOD("set_at_v", "value", "vector"), &Matrix2i::set_at_v);
    ClassDB::bind_method(D_METHOD("resize", "width", "height"), &Matrix2i::resize);
}

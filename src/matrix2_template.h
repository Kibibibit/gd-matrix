#ifndef _GDMATRIX_MATRIX2_TEMPLATE_H
#define _GDMATRIX_MATRIX2_TEMPLATE_H


#include <godot_cpp/classes/ref_counted.hpp>
#include <vector>

// redo this as a normal class and then have matrix2 and matrix2i call it like a wrapper

namespace godot {

    template <class T>
    class Matrix2Template : public RefCounted {
        GDCLASS(Matrix2Template<T>, RefCounted)

        private:
            std::vector<T> data;
            Vector2i size;
        protected:
            static void _bind_methods();
            static void _init(T empty_value, int width, int height);
        public:
            Matrix2Template();
            ~Matrix2Template();

    };

}

#endif
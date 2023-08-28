#ifndef _GDMATRIX_MATRIX2I_H
#define _GDMATRIX_MATRIX2I_H


#include <godot_cpp/classes/ref_counted.hpp>
#include "matrix2_template.h"

namespace godot {

    class Matrix2i: public RefCounted {
        
        GDCLASS(Matrix2i, RefCounted)

        private:
            Matrix2Template<int> * data;
        protected:
            static void _bind_methods();
            void _init(int width, int height);
        public:
            Matrix2i();
            ~Matrix2i();

    };

}

#endif
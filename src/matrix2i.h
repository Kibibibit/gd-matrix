#ifndef _GDMATRIX_MATRIX2I_H
#define _GDMATRIX_MATRIX2I_H


#include "matrix2_template.h"

namespace godot {

    class Matrix2i: Matrix2Template<int> {
        
        GDCLASS(Matrix2i, Matrix2Template<int>)

        private:
        protected:
            static void _bind_methods();
            static void _init(int width, int height);

    };

}

#endif
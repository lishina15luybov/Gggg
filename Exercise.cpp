#include "Exercise.h"

namespace miit::algebra
{
    Exercise::Exercise(int rows, int cols, Generator& generator)
        : matrix{rows, cols}
    {
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                matrix(i, j) = generator.generate();
    }

    Exercise::Exercise(const Matrix<int>& matrix) : matrix{matrix} {}

    const Matrix<int>& Exercise::getMatrix() const { return matrix; }

    std::string Exercise::toString() const { return matrix.toString(); }
}

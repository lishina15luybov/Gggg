#include "Exercise.h"

namespace miit::algebra
{
    Exercise::Exercise(const std::size_t rows, const std::size_t cols, const Generator& generator)
        : matrix{rows, cols}
    {
        matrix.fill(generator);
    }

    Exercise::Exercise(const Matrix<int>& matrix) : matrix{matrix} {}

    const Matrix<int>& Exercise::getMatrix() const { return matrix; }

    std::string Exercise::toString() const { return matrix.toString(); }
}

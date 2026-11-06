#include "Exercise.h"

namespace miit::algebra
{
    Exercise::Exercise(const std::size_t rows, const std::size_t cols, const Generator& generator)
        : matrix{rows, cols}
    {
        Generator& nonConstGen = const_cast<Generator&>(generator);
        for (std::size_t i = 0; i < rows; ++i)
            for (std::size_t j = 0; j < cols; ++j)
                matrix[i][j] = nonConstGen.generate();
    }

    Exercise::Exercise(const Matrix<int>& matrix) : matrix{matrix} {}

    const Matrix<int>& Exercise::getMatrix() const { return matrix; }

    std::string Exercise::toString() const { return matrix.toString(); }
}

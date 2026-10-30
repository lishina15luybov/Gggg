#include "Exercise.h"

namespace miit::algebra
{
    Exercise::Exercise(const int rows, const int cols, const Generator& generator)
        : matrix{rows, cols}
    {
        Generator& nonConstGen = const_cast<Generator&>(generator);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                matrix[i][j] = nonConstGen.generate(); 
    }

    Exercise::Exercise(const Matrix<int>& matrix) : matrix{matrix} {}

    const Matrix<int>& Exercise::getMatrix() const { return matrix; }

    std::string Exercise::toString() const { return matrix.toString(); }
}

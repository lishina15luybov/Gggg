#include "Task1.h"
#include <cstdlib>

namespace miit::algebra
{
    Task1::Task1(const std::size_t rows, const std::size_t cols, const Generator& generator)
        : Exercise(rows, cols, generator) {}

    Task1::Task1(const Matrix<int>& matrix) : Exercise(matrix) {}

    void Task1::solve()
    {
        std::size_t rows = matrix.getRows();
        std::size_t cols = matrix.getCols();
        if (rows == 0 || cols == 0) return;

        for (std::size_t j = 0; j < cols; ++j)
        {
            std::size_t minRow = 0;
            int minAbs = std::abs(matrix[0][j]);
            for (std::size_t i = 1; i < rows; ++i)
            {
                int curAbs = std::abs(matrix[i][j]);
                if (curAbs < minAbs)
                {
                    minAbs = curAbs;
                    minRow = i;
                }
            }
            matrix[minRow][j] = 0;
        }
    }
}

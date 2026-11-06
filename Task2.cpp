#include "Task2.h"

namespace miit::algebra
{
    Task2::Task2(const std::size_t rows, const std::size_t cols, const Generator& generator)
        : Exercise(rows, cols, generator) {}

    Task2::Task2(const Matrix<int>& matrix) : Exercise(matrix) {}

    void Task2::solve()
    {
        std::size_t rows = matrix.getRows();
        std::size_t cols = matrix.getCols();
        if (rows == 0 || cols == 0) return;

        for (std::size_t j = cols; j > 0; --j)
        {
            std::size_t index = j - 1;
            if (matrix[0][index] > matrix[rows - 1][index])
            {
                matrix.removeColumn(index);
            }
        }
    }
}

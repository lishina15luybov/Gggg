#include "Task2.h"

namespace miit::algebra
{
    Task2::Task2(int rows, int cols, Generator& generator)
        : Exercise(rows, cols, generator) {}

    Task2::Task2(const Matrix<int>& matrix) : Exercise(matrix) {}

    void Task2::solve()
    {
        int rows = matrix.getRows();
        int cols = matrix.getCols();
        if (rows == 0 || cols == 0) return;

        // Идём с конца, чтобы удаление не сбивало индексацию
        for (int j = cols - 1; j >= 0; --j)
        {
            if (matrix(0, j) > matrix(rows - 1, j))
            {
                matrix.removeColumn(j);
            }
        }
    }
}

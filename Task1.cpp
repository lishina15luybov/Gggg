#include "Task1.h"
#include <cstdlib>

namespace miit::algebra
{
    Task1::Task1(int rows, int cols, Generator& generator)
        : Exercise(rows, cols, generator) {}

    Task1::Task1(const Matrix<int>& matrix) : Exercise(matrix) {}

    void Task1::solve()
    {
        int rows = matrix.getRows();
        int cols = matrix.getCols();
        if (rows == 0 || cols == 0) return;

        for (int j = 0; j < cols; ++j)
        {
            int minRow = 0;
            int minAbs = std::abs(matrix(0, j));
            for (int i = 1; i < rows; ++i)
            {
                int curAbs = std::abs(matrix(i, j));
                if (curAbs < minAbs)
                {
                    minAbs = curAbs;
                    minRow = i;
                }
            }
            matrix(minRow, j) = 0;
        }
    }
}

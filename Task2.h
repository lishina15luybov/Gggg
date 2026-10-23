#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    /**
     * @brief Задача 2: удалить все столбцы, в которых первый элемент
     *        больше последнего.
     */
    class Task2 : public Exercise
    {
    public:
        Task2(int rows, int cols, Generator& generator);
        explicit Task2(const Matrix<int>& matrix);

        void solve() override;
    };
}

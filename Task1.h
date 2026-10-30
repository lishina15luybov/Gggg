#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    /**
     * @brief Задача 1: заменить минимальный по модулю элемент каждого
     *        столбца нулем.
     */
    class Task1 : public Exercise
    {
    public:
        Task1(const int rows, const int cols, const Generator& generator);
        explicit Task1(const Matrix<int>& matrix);

        void solve() override;
    };
}

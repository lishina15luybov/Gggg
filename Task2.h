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
        /**
         * @brief Конструктор с размерами и генератором.
         * @param rows Количество строк.
         * @param cols Количество столбцов.
         * @param generator Генератор значений.
         */
        Task2(const std::size_t rows, const std::size_t cols, const Generator& generator);

        /**
         * @brief Конструктор с готовой матрицей.
         * @param matrix Готовая матрица.
         */
        explicit Task2(const Matrix<int>& matrix);

        /**
         * @brief Решить задачу.
         */
        void solve() override;
    };
}

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
        /**
         * @brief Конструктор с размерами и генератором.
         * @param rows Количество строк.
         * @param cols Количество столбцов.
         * @param generator Генератор значений.
         */
        Task1(const std::size_t rows, const std::size_t cols, const Generator& generator);

        /**
         * @brief Конструктор с готовой матрицей.
         * @param matrix Готовая матрица.
         */
        explicit Task1(const Matrix<int>& matrix);

        /**
         * @brief Решить задачу.
         */
        void solve() override;
    };
}

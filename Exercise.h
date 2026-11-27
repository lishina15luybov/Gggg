#pragma once
#include "Matrix.h"
#include "Generator.h"
#include <cstddef>

namespace miit::algebra
{
    /**
     * @brief Базовый класс упражнения над матрицей.
     */
    class Exercise
    {
    protected:
        Matrix<int> matrix;

    public:
        /**
         * @brief Конструктор с размерами и генератором.
         * @param rows Количество строк.
         * @param cols Количество столбцов.
         * @param generator Генератор значений.
         */
        Exercise(const std::size_t rows, const std::size_t cols, const Generator& generator);

        /**
         * @brief Конструктор с готовой матрицей.
         * @param matrix Готовая матрица.
         */
        explicit Exercise(const Matrix<int>& matrix);

        /**
         * @brief Виртуальный деструктор.
         */
        virtual ~Exercise() = default;

        /**
         * @brief Чисто виртуальный метод решения задачи.
         */
        virtual void solve() = 0;

        /**
         * @brief Получить матрицу.
         * @return Константная ссылка на матрицу.
         */
        const Matrix<int>& getMatrix() const;

        /**
         * @brief Строковое представление матрицы.
         * @return Строка с матрицей.
         */
        std::string toString() const;
    };
}

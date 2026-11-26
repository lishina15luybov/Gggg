#pragma once
#include "Matrix.h"
#include "Generator.h"
#include <cstddef>

namespace miit::algebra
{
    /**
     * @brief Базовый абстрактный класс упражнения над матрицей.
     */
    class Exercise
    {
    protected:
        /**
         * @brief Матрица для выполнения операций.
         */
        Matrix<int> matrix;

    public:
        /**
         * @brief Конструктор с инициализацией матрицы через генератор.
         * @param rows Количество строк матрицы.
         * @param cols Количество столбцов матрицы.
         * @param generator Ссылка на генератор значений.
         */
        Exercise(const std::size_t rows, const std::size_t cols, Generator& generator);

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
         * @brief Получить текущую матрицу.
         * @return Константная ссылка на матрицу.
         */
        const Matrix<int>& getMatrix() const;

        /**
         * @brief Получить строковое представление матрицы.
         * @return Строка с элементами матрицы.
         */
        std::string toString() const;
    };
}

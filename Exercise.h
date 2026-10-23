#pragma once
#include "Matrix.h"
#include "Generator.h"
#include <memory>

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
         */
        Exercise(int rows, int cols, Generator& generator);

        /**
         * @brief Конструктор с готовой матрицей.
         */
        explicit Exercise(const Matrix<int>& matrix);

        virtual ~Exercise() = default;

        /**
         * @brief Чисто виртуальный метод решения задачи.
         */
        virtual void solve() = 0;

        /**
         * @brief Получить матрицу.
         */
        const Matrix<int>& getMatrix() const;

        /**
         * @brief Строковое представление.
         */
        std::string toString() const;
    };
}

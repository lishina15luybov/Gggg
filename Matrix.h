#pragma once
#include <vector>
#include <string>
#include <cstddef>
#include "Generator.h"

namespace miit::algebra
{
    /**
     * @brief Шаблонный класс двумерной матрицы.
     */
    template <typename T>
    class Matrix
    {
    private:
        /**
         * @brief Двумерный массив (вектор векторов) для хранения данных.
         */
        std::vector<std::vector<T>> data;

        /**
         * @brief Количество строк в матрице.
         */
        std::size_t rows;

        /**
         * @brief Количество столбцов в матрице.
         */
        std::size_t cols;

    public:
        Matrix();
        Matrix(const std::size_t rows, const std::size_t cols);
        Matrix(const Matrix& other);
        Matrix(Matrix&& other) noexcept;
        virtual ~Matrix();

        Matrix& operator=(const Matrix& other);
        Matrix& operator=(Matrix&& other) noexcept;

        std::size_t getRows() const;
        std::size_t getCols() const;

        /**
         * @brief Заполнить матрицу заданным значением.
         * @param value Значение для заполнения.
         */
        virtual void fill(const T& value);

        /**
         * @brief Изменить размер и заполнить матрицу заданным значением.
         * @param newRows Новое количество строк.
         * @param newCols Новое количество столбцов.
         * @param value Значение для заполнения.
         */
        virtual void fill(const std::size_t newRows, const std::size_t newCols, const T& value);

        /**
         * @brief Заполнить матрицу значениями с помощью генератора.
         * @param generator Константная ссылка на генератор.
         */
        virtual void fill(const Generator& generator);

        const std::vector<T>& operator[](const std::size_t index) const;
        std::vector<T>& operator[](const std::size_t index);

        Matrix& operator<<(const int shift);
        Matrix& operator>>(const int shift);

        std::string toString() const;

        void removeColumn(const std::size_t colIndex);
        void removeRow(const std::size_t rowIndex);
        virtual void resize(const std::size_t newRows, const std::size_t newCols);
    };
}

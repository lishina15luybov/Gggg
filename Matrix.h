#pragma once
#include <vector>
#include <string>
#include <cstddef>

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
        ~Matrix();

        Matrix& operator=(const Matrix& other);
        Matrix& operator=(Matrix&& other) noexcept;

        std::size_t getRows() const;
        std::size_t getCols() const;

        /**
         * @brief Заполнить матрицу заданным значением.
         * @param value Значение для заполнения.
         */
        void fill(const T& value); 

        const std::vector<T>& operator[](const std::size_t index) const;
        std::vector<T>& operator[](const std::size_t index);

        Matrix& operator<<(const int shift);
        Matrix& operator>>(const int shift);

        std::string toString() const;

        void removeColumn(const std::size_t colIndex);
        void removeRow(const std::size_t rowIndex);
        void resize(const std::size_t newRows, const std::size_t newCols);
    };
}

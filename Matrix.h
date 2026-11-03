#pragma once
#include <vector>
#include <string>
#include <iostream>

namespace miit::algebra
{
    /**
     * @brief Шаблонный класс двумерной матрицы.
     */
    template <typename T>
    class Matrix
    {
    private:
        std::vector<std::vector<T>> data;
        int rows;
        int cols;

    public:
        Matrix();
        Matrix(const int rows, const int cols);
        Matrix(const Matrix& other);
        Matrix(Matrix&& other) noexcept;
        ~Matrix();

        Matrix& operator=(const Matrix& other);
        Matrix& operator=(Matrix&& other) noexcept;

        int getRows() const;
        int getCols() const;

        const std::vector<T>& operator[](const int index) const;
        std::vector<T>& operator[](const int index);

        /**
         * @brief Сдвиг влево (циклический сдвиг строк).
         */
        Matrix& operator<<(const int shift);

        /**
         * @brief Сдвиг вправо (циклический сдвиг строк).
         */
        Matrix& operator>>(const int shift); // ИСПРАВЛЕНО: добавлен const

        std::string toString() const;

        void removeColumn(const int colIndex);
        void removeRow(const int rowIndex);
        void resize(const int newRows, const int newCols);
    };
}

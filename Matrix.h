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
        /**
         * @brief Конструктор по умолчанию.
         */
        Matrix();

        /**
         * @brief Конструктор с размерами, заполняет нулями.
         * @param rows Количество строк.
         * @param cols Количество столбцов.
         */
        Matrix(int rows, int cols);

        /**
         * @brief Конструктор копирования.
         */
        Matrix(const Matrix& other);

        /**
         * @brief Конструктор перемещения.
         */
        Matrix(Matrix&& other) noexcept;

        /**
         * @brief Деструктор.
         */
        ~Matrix();

        /**
         * @brief Оператор присваивания копированием.
         */
        Matrix& operator=(const Matrix& other);

        /**
         * @brief Оператор присваивания перемещением.
         */
        Matrix& operator=(Matrix&& other) noexcept;

        /**
         * @brief Получить количество строк.
         */
        int getRows() const;

        /**
         * @brief Получить количество столбцов.
         */
        int getCols() const;

        /**
         * @brief Доступ к элементу по индексам (const).
         */
        const T& operator[](int index) const;

        /**
         * @brief Доступ к строке по индексу (для изменения).
         */
        std::vector<T>& operator[](int index);

        /**
         * @brief Сдвиг влево (циклический сдвиг строк).
         */
        Matrix& operator<<(int shift);

        /**
         * @brief Сдвиг вправо (циклический сдвиг строк).
         */
        Matrix& operator>>(int shift);

        /**
         * @brief Разыменование элемента по паре индексов.
         */
        T& operator()(int row, int col);
        const T& operator()(int row, int col) const;

        /**
         * @brief Преобразование в строку.
         */
        std::string toString() const;

        /**
         * @brief Удалить столбец по индексу.
         */
        void removeColumn(int colIndex);

        /**
         * @brief Удалить строку по индексу.
         */
        void removeRow(int rowIndex);

        /**
         * @brief Изменить размеры (сохраняя данные).
         */
        void resize(int newRows, int newCols);
    };
}

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
        /**
         * @brief Конструктор по умолчанию.
         */
        Matrix();

        /**
         * @brief Конструктор с размерами, заполняет нулями.
         * @param rows Количество строк.
         * @param cols Количество столбцов.
         */
        Matrix(const std::size_t rows, const std::size_t cols);

        /**
         * @brief Конструктор копирования.
         * @param other Другая матрица.
         */
        Matrix(const Matrix& other);

        /**
         * @brief Конструктор перемещения.
         * @param other Другая матрица.
         */
        Matrix(Matrix&& other) noexcept;

        /**
         * @brief Деструктор.
         */
        ~Matrix();

        /**
         * @brief Оператор присваивания копированием.
         * @param other Другая матрица.
         * @return Ссылка на текущую матрицу.
         */
        Matrix& operator=(const Matrix& other);

        /**
         * @brief Оператор присваивания перемещением.
         * @param other Другая матрица.
         * @return Ссылка на текущую матрицу.
         */
        Matrix& operator=(Matrix&& other) noexcept;

        /**
         * @brief Получить количество строк.
         * @return Количество строк.
         */
        std::size_t getRows() const;

        /**
         * @brief Получить количество столбцов.
         * @return Количество столбцов.
         */
        std::size_t getCols() const;

        /**
         * @brief Доступ к элементу по индексам (const).
         * @param index Индекс строки.
         * @return Константная ссылка на строку.
         */
        const std::vector<T>& operator[](const std::size_t index) const;

        /**
         * @brief Доступ к строке по индексу (для изменения).
         * @param index Индекс строки.
         * @return Ссылка на строку.
         */
        std::vector<T>& operator[](const std::size_t index);

        /**
         * @brief Сдвиг влево (циклический сдвиг строк).
         * @param shift Величина сдвига.
         * @return Ссылка на текущую матрицу.
         */
        Matrix& operator<<(const int shift);

        /**
         * @brief Сдвиг вправо (циклический сдвиг строк).
         * @param shift Величина сдвига.
         * @return Ссылка на текущую матрицу.
         */
        Matrix& operator>>(const int shift);

        /**
         * @brief Преобразование в строку.
         * @return Строковое представление матрицы.
         */
        std::string toString() const;

        /**
         * @brief Удалить столбец по индексу.
         * @param colIndex Индекс столбца.
         */
        void removeColumn(const std::size_t colIndex);

        /**
         * @brief Удалить строку по индексу.
         * @param rowIndex Индекс строки.
         */
        void removeRow(const std::size_t rowIndex);

        /**
         * @brief Изменить размеры (сохраняя данные).
         * @param newRows Новое количество строк.
         * @param newCols Новое количество столбцов.
         */
        void resize(const std::size_t newRows, const std::size_t newCols);
    };
}

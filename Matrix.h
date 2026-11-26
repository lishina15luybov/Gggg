#pragma once
#include <vector>
#include <string>
#include <cstddef>

namespace miit::algebra
{
    /**
     * @brief Шаблонный класс двумерной матрицы.
     * @tparam T Тип элементов матрицы.
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
         * @brief Конструктор по умолчанию. Создает пустую матрицу.
         */
        Matrix();

        /**
         * @brief Конструктор с заданными размерами.
         * @param rows Количество строк.
         * @param cols Количество столбцов.
         */
        Matrix(const std::size_t rows, const std::size_t cols);

        /**
         * @brief Конструктор копирования.
         * @param other Матрица для копирования.
         */
        Matrix(const Matrix& other);

        /**
         * @brief Конструктор перемещения.
         * @param other Матрица для перемещения.
         */
        Matrix(Matrix&& other) noexcept;

        /**
         * @brief Виртуальный деструктор.
         */
        virtual ~Matrix();

        /**
         * @brief Оператор присваивания копированием.
         * @param other Матрица для копирования.
         * @return Ссылка на текущую матрицу.
         */
        Matrix& operator=(const Matrix& other);

        /**
         * @brief Оператор присваивания перемещением.
         * @param other Матрица для перемещения.
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
         * @brief Доступ к строке матрицы (только чтение).
         * @param index Индекс строки.
         * @return Константная ссылка на строку (вектор).
         */
        const std::vector<T>& operator[](const std::size_t index) const;

        /**
         * @brief Доступ к строке матрицы (чтение и запись).
         * @param index Индекс строки.
         * @return Ссылка на строку (вектор).
         */
        std::vector<T>& operator[](const std::size_t index);

        /**
         * @brief Циклический сдвиг строк матрицы вверх.
         * @param shift Величина сдвига.
         * @return Ссылка на измененную матрицу.
         */
        Matrix& operator<<(const int shift);

        /**
         * @brief Циклический сдвиг строк матрицы вниз.
         * @param shift Величина сдвига.
         * @return Ссылка на измененную матрицу.
         */
        Matrix& operator>>(const int shift);

        /**
         * @brief Получить строковое представление матрицы.
         * @return Строка, содержащая элементы матрицы.
         */
        std::string toString() const;

        /**
         * @brief Удалить столбец по индексу.
         * @param colIndex Индекс удаляемого столбца.
         */
        void removeColumn(const std::size_t colIndex);

        /**
         * @brief Удалить строку по индексу.
         * @param rowIndex Индекс удаляемой строки.
         */
        void removeRow(const std::size_t rowIndex);

        /**
         * @brief Изменить размер матрицы.
         * @param newRows Новое количество строк.
         * @param newCols Новое количество столбцов.
         */
        virtual void resize(const std::size_t newRows, const std::size_t newCols);
    };
}

#pragma once
#include <vector>
#include <string>
#include <cstddef>
#include "Generator.h"

namespace miit::algebra
{
    /**
     * @brief Шаблонный класс двумерной матрицы.
     * @tparam T Тип хранимых элементов.
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
         * @brief Конструктор по умолчанию. Создаёт пустую матрицу.
         */
        Matrix();

        /**
         * @brief Конструктор матрицы заданного размера.
         * @param rows Количество строк.
         * @param cols Количество столбцов.
         */
        Matrix(const std::size_t rows, const std::size_t cols);

        /**
         * @brief Конструктор копирования.
         * @param other Копируемая матрица.
         */
        Matrix(const Matrix& other);

        /**
         * @brief Конструктор перемещения.
         * @param other Перемещаемая матрица.
         */
        Matrix(Matrix&& other) noexcept;

        /**
         * @brief Виртуальный деструктор.
         */
        virtual ~Matrix();

        /**
         * @brief Оператор копирующего присваивания.
         * @param other Присваиваемая матрица.
         * @return Ссылка на текущий объект.
         */
        Matrix& operator=(const Matrix& other);

        /**
         * @brief Оператор перемещающего присваивания.
         * @param other Присваиваемая матрица.
         * @return Ссылка на текущий объект.
         */
        Matrix& operator=(Matrix&& other) noexcept;

        /**
         * @brief Получить количество строк.
         * @return Количество строк в матрице.
         */
        std::size_t getRows() const;

        /**
         * @brief Получить количество столбцов.
         * @return Количество столбцов в матрице.
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
         * @brief Заполнить матрицу значениями с помощью генератора.
         * @param generator Константная ссылка на генератор.
         */
        virtual void fill(const Generator& generator);

        /**
         * @brief Доступ к строке матрицы (константная версия).
         * @param index Индекс строки.
         * @return Константная ссылка на вектор значений строки.
         */
        const std::vector<T>& operator[](const std::size_t index) const;

        /**
         * @brief Доступ к строке матрицы (неконстантная версия).
         * @param index Индекс строки.
         * @return Ссылка на вектор значений строки.
         */
        std::vector<T>& operator[](const std::size_t index);

        /**
         * @brief Циклический сдвиг элементов матрицы влево.
         * @param shift Количество позиций сдвига.
         * @return Ссылка на текущий объект.
         */
        Matrix& operator<<(const int shift);

        /**
         * @brief Циклический сдвиг элементов матрицы вправо.
         * @param shift Количество позиций сдвига.
         * @return Ссылка на текущий объект.
         */
        Matrix& operator>>(const int shift);

        /**
         * @brief Получить строковое представление матрицы.
         * @return Строка с элементами матрицы.
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

#include "Matrix.h"
#include <sstream>
#include <algorithm>

namespace miit::algebra
{
    template <typename T>
    Matrix<T>::Matrix() : rows{0}, cols{0} {}

    template <typename T>
    Matrix<T>::Matrix(const std::size_t rows, const std::size_t cols)
    {
        fill(rows, cols, T{});
    }

    template <typename T>
    Matrix<T>::Matrix(const Matrix& other) : data{other.data}, rows{other.rows}, cols{other.cols} {}

    template <typename T>
    Matrix<T>::Matrix(Matrix&& other) noexcept : data{std::move(other.data)}, rows{other.rows}, cols{other.cols}
    {
        other.rows = 0;
        other.cols = 0;
    }

    template <typename T>
    Matrix<T>::~Matrix() = default;

    template <typename T>
    Matrix<T>& Matrix<T>::operator=(const Matrix& other)
    {
        if (this != &other)
        {
            data = other.data;
            rows = other.rows;
            cols = other.cols;
        }
        return *this;
    }

    template <typename T>
    Matrix<T>& Matrix<T>::operator=(Matrix&& other) noexcept
    {
        if (this != &other)
        {
            data = std::move(other.data);
            rows = other.rows;
            cols = other.cols;
            other.rows = 0;
            other.cols = 0;
        }
        return *this;
    }

    template <typename T>
    std::size_t Matrix<T>::getRows() const { return rows; }

    template <typename T>
    std::size_t Matrix<T>::getCols() const { return cols; }

    template <typename T>
    void Matrix<T>::fill(const T& value)
    {
        for (auto& row : data)
        {
            std::fill(row.begin(), row.end(), value);
        }
    }
    template <typename T>
    void Matrix<T>::fill(const std::size_t newRows, const std::size_t newCols, const T& value)
    {
        rows = newRows;
        cols = newCols;
        data.assign(rows, std::vector<T>(cols, value));
    }

    template <typename T>
    const std::vector<T>& Matrix<T>::operator[](const std::size_t index) const { return data.at(index); }

    template <typename T>
    std::vector<T>& Matrix<T>::operator[](const std::size_t index) { return data.at(index); }

    template <typename T>
    Matrix<T>& Matrix<T>::operator<<(const int shift)
    {
        if (rows == 0) return *this;
        int s = ((shift % static_cast<int>(rows)) + static_cast<int>(rows)) % static_cast<int>(rows);
        for (int k = 0; k < s; ++k)
        {
            std::vector<T> first = data.front();
            data.erase(data.begin());
            data.push_back(first);
        }
        return *this;
    }

    template <typename T>
    Matrix<T>& Matrix<T>::operator>>(const int shift)
    {
        if (rows == 0) return *this;
        int s = ((shift % static_cast<int>(rows)) + static_cast<int>(rows)) % static_cast<int>(rows);
        for (int k = 0; k < s; ++k)
        {
            std::vector<T> last = data.back();
            data.pop_back();
            data.insert(data.begin(), last);
        }
        return *this;
    }

    template <typename T>
    std::string Matrix<T>::toString() const
    {
        std::ostringstream oss;
        for (std::size_t i = 0; i < rows; ++i)
        {
            for (std::size_t j = 0; j < cols; ++j)
            {
                oss << data[i][j];
                if (j + 1 < cols) oss << " ";
            }
            oss << "\n";
        }
        return oss.str();
    }

    template <typename T>
    void Matrix<T>::removeColumn(const std::size_t colIndex)
    {
        if (colIndex >= cols) return;
        for (auto& row : data)
            row.erase(row.begin() + colIndex);
        --cols;
    }

    template <typename T>
    void Matrix<T>::removeRow(const std::size_t rowIndex)
    {
        if (rowIndex >= rows) return;
        data.erase(data.begin() + rowIndex);
        --rows;
    }

    template <typename T>
    void Matrix<T>::resize(const std::size_t newRows, const std::size_t newCols)
    {
        std::vector<std::vector<T>> newData(newRows, std::vector<T>(newCols, T{}));
        std::size_t r = std::min(rows, newRows);
        std::size_t c = std::min(cols, newCols);
        for (std::size_t i = 0; i < r; ++i)
            for (std::size_t j = 0; j < c; ++j)
                newData[i][j] = data[i][j];
        data = std::move(newData);
        rows = newRows;
        cols = newCols;
    }

    template class Matrix<int>;
    template class Matrix<double>;
}

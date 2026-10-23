#include "Matrix.h"
#include <sstream>
#include <stdexcept>

namespace miit::algebra
{
    template <typename T>
    Matrix<T>::Matrix() : rows{0}, cols{0} {}

    template <typename T>
    Matrix<T>::Matrix(int rows, int cols)
        : rows{rows}, cols{cols}
    {
        if (rows < 0 || cols < 0)
        {
            throw std::invalid_argument("Размеры матрицы не могут быть отрицательными");
        }
        data.assign(rows, std::vector<T>(cols, T{}));
    }

    template <typename T>
    Matrix<T>::Matrix(const Matrix& other)
        : data{other.data}, rows{other.rows}, cols{other.cols} {}

    template <typename T>
    Matrix<T>::Matrix(Matrix&& other) noexcept
        : data{std::move(other.data)}, rows{other.rows}, cols{other.cols}
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
    int Matrix<T>::getRows() const { return rows; }

    template <typename T>
    int Matrix<T>::getCols() const { return cols; }

    template <typename T>
    const std::vector<T>& Matrix<T>::operator[](int index) const
    {
        return data.at(index);
    }

    template <typename T>
    std::vector<T>& Matrix<T>::operator[](int index)
    {
        return data.at(index);
    }

    template <typename T>
    T& Matrix<T>::operator()(int row, int col)
    {
        return data.at(row).at(col);
    }

    template <typename T>
    const T& Matrix<T>::operator()(int row, int col) const
    {
        return data.at(row).at(col);
    }

    template <typename T>
    Matrix<T>& Matrix<T>::operator<<(int shift)
    {
        if (rows == 0) return *this;
        int s = ((shift % rows) + rows) % rows;
        for (int k = 0; k < s; ++k)
        {
            std::vector<T> first = data.front();
            data.erase(data.begin());
            data.push_back(first);
        }
        return *this;
    }

    template <typename T>
    Matrix<T>& Matrix<T>::operator>>(int shift)
    {
        if (rows == 0) return *this;
        int s = ((shift % rows) + rows) % rows;
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
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                oss << data[i][j];
                if (j + 1 < cols) oss << " ";
            }
            oss << "\n";
        }
        return oss.str();
    }

    template <typename T>
    void Matrix<T>::removeColumn(int colIndex)
    {
        if (colIndex < 0 || colIndex >= cols) return;
        for (auto& row : data)
        {
            row.erase(row.begin() + colIndex);
        }
        --cols;
    }

    template <typename T>
    void Matrix<T>::removeRow(int rowIndex)
    {
        if (rowIndex < 0 || rowIndex >= rows) return;
        data.erase(data.begin() + rowIndex);
        --rows;
    }

    template <typename T>
    void Matrix<T>::resize(int newRows, int newCols)
    {
        std::vector<std::vector<T>> newData(newRows, std::vector<T>(newCols, T{}));
        int r = std::min(rows, newRows);
        int c = std::min(cols, newCols);
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                newData[i][j] = data[i][j];
        data = std::move(newData);
        rows = newRows;
        cols = newCols;
    }
    template class Matrix<int>;
    template class Matrix<double>;
}

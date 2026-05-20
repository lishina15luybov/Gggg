#pragma once

#include "Point.h"
#include <string>
#include <memory>
#include <vector>

namespace VectorLib {

/**
 * @brief Абстрактный базовый класс Вектор
 * @details Предоставляет интерфейс для работы с векторами
 */
class Vector {
protected:
    Point m_start;  ///< Начальная точка вектора
    Point m_end;    ///< Конечная точка вектора

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Vector();

    /**
     * @brief Конструктор с двумя точками
     * @param start начальная точка
     * @param end конечная точка
     */
    Vector(const Point& start, const Point& end);

    /**
     * @brief Виртуальный деструктор
     */
    virtual ~Vector();

    /**
     * @brief Получить начальную точку
     * @return начальная точка
     */
    Point getStart() const;

    /**
     * @brief Получить конечную точку
     * @return конечная точка
     */
    Point getEnd() const;

    /**
     * @brief Получить координаты вектора
     * @return разность конечной и начальной точек
     */
    Point getCoordinates() const;

    /**
     * @brief Вычисление евклидовой нормы (длины вектора)
     * @return длина вектора
     */
    virtual double length() const;

    /**
     * @brief Статический метод нахождения угла между двумя векторами
     * @param v1 первый вектор
     * @param v2 второй вектор
     * @return угол в радианах
     */
    static double angleBetween(const Vector& v1, const Vector& v2);

    /**
     * @brief Метод сериализации в строку
     * @return строковое представление вектора
     */
    virtual std::string toString() const;

    /**
     * @brief Статический метод чтения из стандартного потока ввода
     * @param is входной поток
     * @return прочитанный вектор
     */
    static Vector readFromStream(std::istream& is);

    /**
     * @brief Оператор сдвига влево
     * @param os выходной поток
     * @param v выводимый вектор
     * @return ссылка на поток
     */
    friend std::ostream& operator<<(std::ostream& os, const Vector& v);
};

/**
 * @brief Класс Вектор на плоскости
 * @details Конкретная реализация вектора на плоскости
 */
class Vector2D : public Vector {
public:
    /**
     * @brief Конструктор по умолчанию
     */
    Vector2D();

    /**
     * @brief Конструктор через две точки
     * @param start начальная точка
     * @param end конечная точка
     */
    Vector2D(const Point& start, const Point& end);

    /**
     * @brief Конструктор через пары чисел
     * @param x1 абсцисса начала
     * @param y1 ордината начала
     * @param x2 абсцисса конца
     * @param y2 ордината конца
     */
    Vector2D(const double x1, const double y1, const double x2, const double y2);

    /**
     * @brief Оператор сравнения "равно"
     * @param other другой вектор
     * @return true если векторы равны
     */
    bool operator==(const Vector2D& other) const;

    /**
     * @brief Оператор сравнения "не равно"
     * @param other другой вектор
     * @return true если векторы не равны
     */
    bool operator!=(const Vector2D& other) const;

    /**
     * @brief Оператор сложения векторов
     * @param other другой вектор
     * @return новый вектор-сумма
     */
    Vector2D operator+(const Vector2D& other) const;

    /**
     * @brief Оператор вычитания векторов
     * @param other другой вектор
     * @return новый вектор-разность
     */
    Vector2D operator-(const Vector2D& other) const;

    /**
     * @brief Оператор умножения на скаляр
     * @param scalar множитель
     * @return новый вектор, умноженный на скаляр
     */
    Vector2D operator*(const double scalar) const;

    /**
     * @brief Оператор сдвига влево
     * @param os выходной поток
     * @param v выводимый вектор
     * @return ссылка на поток
     */
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v);

    /**
     * @brief Статический метод чтения из потока
     * @param is входной поток
     * @return прочитанный вектор
     */
    static Vector2D readFromStream(std::istream& is);

    /**
     * @brief Статический метод сериализации в строку
     * @param v вектор
     * @return строковое представление
     */
    static std::string toString(const Vector2D& v);
};

} // namespace VectorLib

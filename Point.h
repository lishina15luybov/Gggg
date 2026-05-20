#pragma once

#include <iostream>
#include <string>

namespace VectorLib {

/**
 * @brief Класс Точка на плоскости
 * @details Представляет точку с координатами (x, y)
 */
class Point {
private:
    double m_x;  ///< Абсцисса точки
    double m_y;  ///< Ордината точки

public:
    /**
     * @brief Конструктор по умолчанию
     * @details Создает точку с координатами (0, 0)
     */
    Point();

    /**
     * @brief Конструктор с координатами
     * @param x абсцисса
     * @param y ордината
     */
    Point(const double x, const double y);

    /**
     * @brief Получить абсциссу
     * @return значение x
     */
    double getX() const;

    /**
     * @brief Получить ординату
     * @return значение y
     */
    double getY() const;

    /**
     * @brief Установить абсциссу
     * @param x новое значение x
     */
    void setX(const double x);

    /**
     * @brief Установить ординату
     * @param y новое значение y
     */
    void setY(const double y);

    /**
     * @brief Сериализация в строку
     * @return строка вида "(x; y)"
     */
    std::string toString() const;

    /**
     * @brief Оператор сравнения "равно"
     * @param other другая точка
     * @return true если координаты совпадают
     */
    bool operator==(const Point& other) const;

    /**
     * @brief Оператор сравнения "не равно"
     * @param other другая точка
     * @return true если координаты не совпадают
     */
    bool operator!=(const Point& other) const;

    /**
     * @brief Оператор сложения точки с числом
     * @param scalar число
     * @return новая точка с координатами (x + scalar, y + scalar)
     */
    Point operator+(const double scalar) const;

    /**
     * @brief Оператор вычитания числа из точки
     * @param scalar число
     * @return новая точка с координатами (x - scalar, y - scalar)
     */
    Point operator-(const double scalar) const;

    /**
     * @brief Оператор сложения двух точек
     * @param other другая точка
     * @return новая точка с координатами (x1 + x2, y1 + y2)
     */
    Point operator+(const Point& other) const;

    /**
     * @brief Оператор вычитания двух точек
     * @param other другая точка
     * @return новая точка с координатами (x1 - x2, y1 - y2)
     */
    Point operator-(const Point& other) const;

    /**
     * @brief Оператор сдвига влево (вывод в поток)
     * @param os выходной поток
     * @param point выводимая точка
     * @return ссылка на поток
     */
    friend std::ostream& operator<<(std::ostream& os, const Point& point);

    /**
     * @brief Оператор сдвига вправо (ввод из потока)
     * @param is входной поток
     * @param point считываемая точка
     * @return ссылка на поток
     */
    friend std::istream& operator>>(std::istream& is, Point& point);
};

} // namespace VectorLib

#pragma once

/**
 * @brief Класс Точка
 */
class Point
{
private:
    /**
     * @brief Координата X
     */
    double x;
    /**
     * @brief Координата Y
     */
    double y;
    /**
     * @brief Координата Z
     */
    double z;

public:
    /**
     * @brief Конструктор точки
     */
    Point(double x = 0, double y = 0, double z = 0);

    /**
     * @brief Получение координаты X
     */
    double getX() const;

    /**
     * @brief Получение координаты Y
     */
    double getY() const;

    /**
     * @brief Получение координаты Z
     */
    double getZ() const;

    /**
     * @brief Проверка на равенство оператора
     */
    bool operator==(const Point& p) const;

    /**
     * @brief Проверка на неравенство оператора
     */
    bool operator!=(const Point& p) const;
};

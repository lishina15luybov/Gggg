#pragma once

#include "point.h"

/**
 * @brief Класс треугольник (задаёт плоскость)
 */
class Triangle
{
private:
    /**
     * @brief Первая вершина
     */
    Point p1;
    /**
     * @brief Вторая вершина
     */
    Point p2;
    /**
     * @brief Третья вершина
     */
    Point p3;

public:
    /**
     * @brief Конструктор
     * @param p1 - первая точка
     * @param p2 - вторая точка
     * @param p3 - третья точка
     */
    Triangle(const Point& p1, const Point& p2, const Point& p3);

    /**
     * @brief Проверка принадлежности точки плоскости
     * @param p - проверяемая точка
     * @return true - если точка принадлежит плоскости
     */
    bool isPointOnPlane(const Point& p) const;

    /**
     * @brief Расстояние от точки до плоскости
     * @param p - точка
     * @return расстояние
     */
    double distanceToPlane(const Point& p) const;
};

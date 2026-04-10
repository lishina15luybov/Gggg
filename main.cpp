#include <iostream>
#include "triangle.h"
#include "point.h"

/**
 * @brief Считывает значение, введенное с клавиатуры
 * @param report - строка информации
 * @return считанное значение
 */
double getValue(std::string report = "");

/**
 * @brief Вводит точку с клавиатуры
 * @param pointName - название точки для вывода в приглашении
 * @return введенная точка
 */
Point getPoint(std::string pointName);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
    std::cout << "=== Ввод трех точек плоскости ===" << std::endl;
    
    Point p1 = getPoint("1");
    Point p2 = getPoint("2");
    Point p3 = getPoint("3");
    
    Triangle myTriangle(p1, p2, p3);
    
    std::cout << "\n=== Ввод четвертой точки ===" << std::endl;
    
    Point p4 = getPoint("4");
    
    if (myTriangle.isPointOnPlane(p4))
    {
        std::cout << "\nТочка принадлежит заданной плоскости" << std::endl;
    }
    else
    {
        std::cout << "\nТочка НЕ принадлежит заданной плоскости" << std::endl;
    }
    
    double dist = myTriangle.distanceToPlane(p4);
    std::cout << "Расстояние от точки до плоскости: " << dist << std::endl;
    
    return 0;
}

double getValue(std::string report)
{
    std::cout << report;
    double value = 0;
    std::cin >> value;
    
    if (std::cin.fail())
    {
        std::cout << "Ошибка, введено неверное значение!\n";
        exit(1);
    }
    
    return value;
}

Point getPoint(std::string pointName)
{
    std::cout << "\n--- Ввод " << pointName << "-й точки ---" << std::endl;
    double x = getValue("Введите x: ");
    double y = getValue("Введите y: ");
    double z = getValue("Введите z: ");
    
    return Point(x, y, z);
}

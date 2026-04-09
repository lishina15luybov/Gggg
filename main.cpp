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
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
    std::cout << "=== Ввод трех точек плоскости ===" << std::endl;
    
    double x1 = getValue("Введите x1: ");
    double y1 = getValue("Введите y1: ");
    double z1 = getValue("Введите z1: ");
    
    double x2 = getValue("Введите x2: ");
    double y2 = getValue("Введите y2: ");
    double z2 = getValue("Введите z2: ");
    
    double x3 = getValue("Введите x3: ");
    double y3 = getValue("Введите y3: ");
    double z3 = getValue("Введите z3: ");
    
    Point p1(x1, y1, z1);
    Point p2(x2, y2, z2);
    Point p3(x3, y3, z3);
    
    Triangle myTriangle(p1, p2, p3);
    
    std::cout << "\n=== Ввод четвертой точки ===" << std::endl;
    
    double x4 = getValue("Введите x4: ");
    double y4 = getValue("Введите y4: ");
    double z4 = getValue("Введите z4: ");
    
    Point p4(x4, y4, z4);
    
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

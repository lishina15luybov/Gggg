#include <iostream>
#include <cmath>
#include "triangle.h"

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3)
{
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
    
    if (p1 == p2 || p2 == p3 || p1 == p3)
    {
        std::cout << "Ошибка: Точки совпадают!" << std::endl;
        exit(1);
    }
    
    // Проверка на вырожденность треугольника (проверка нормали)
    double ux = p2.getX() - p1.getX();
    double uy = p2.getY() - p1.getY();
    double uz = p2.getZ() - p1.getZ();
    
    double vx = p3.getX() - p1.getX();
    double vy = p3.getY() - p1.getY();
    double vz = p3.getZ() - p1.getZ();
    
    double nx = uy * vz - uz * vy;
    double ny = uz * vx - ux * vz;
    double nz = ux * vy - uy * vx;
    
    double len = sqrt(nx * nx + ny * ny + nz * nz);
    
    if (len < 1e-9)
    {
        std::cout << "Ошибка: Треугольник вырожден (точки лежат на одной прямой)!" << std::endl;
        exit(1);
    }
}

bool Triangle::isPointOnPlane(const Point& p) const
{
    double ux = p2.getX() - p1.getX();
    double uy = p2.getY() - p1.getY();
    double uz = p2.getZ() - p1.getZ();
    
    double vx = p3.getX() - p1.getX();
    double vy = p3.getY() - p1.getY();
    double vz = p3.getZ() - p1.getZ();
    
    double nx = uy * vz - uz * vy;
    double ny = uz * vx - ux * vz;
    double nz = ux * vy - uy * vx;
    
    double dx = p.getX() - p1.getX();
    double dy = p.getY() - p1.getY();
    double dz = p.getZ() - p1.getZ();
    
    double value = nx * dx + ny * dy + nz * dz;
    
    if (value > -1e-9 && value < 1e-9)
    {
        return true;
    }
    else
    {
        return false;
    }
}

double Triangle::distanceToPlane(const Point& p) const
{
    double ux = p2.getX() - p1.getX();
    double uy = p2.getY() - p1.getY();
    double uz = p2.getZ() - p1.getZ();
    
    double vx = p3.getX() - p1.getX();
    double vy = p3.getY() - p1.getY();
    double vz = p3.getZ() - p1.getZ();
    
    double nx = uy * vz - uz * vy;
    double ny = uz * vx - ux * vz;
    double nz = ux * vy - uy * vx;
    
    double len = sqrt(nx * nx + ny * ny + nz * nz);
    
    if (len < 1e-9)
    {
        return 0.0;
    }
    
    nx = nx / len;
    ny = ny / len;
    nz = nz / len;
    
    double dx = p.getX() - p1.getX();
    double dy = p.getY() - p1.getY();
    double dz = p.getZ() - p1.getZ();
    
    double distance = nx * dx + ny * dy + nz * dz;
    
    if (distance < 0)
    {
        distance = -distance;
    }
    
    return distance;
}

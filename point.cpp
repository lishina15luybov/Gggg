#include "point.h"
#include <cmath>
#include <limits>

Point::Point(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

double Point::getX() const
{
    return this->x;
}

double Point::getY() const
{
    return this->y;
}

double Point::getZ() const
{
    return this->z;
}

bool Point::operator==(const Point& p) const
{
    return (std::abs(this->x - p.x) < std::numeric_limits<double>::epsilon() && 
            std::abs(this->y - p.y) < std::numeric_limits<double>::epsilon() &&
            std::abs(this->z - p.z) < std::numeric_limits<double>::epsilon());
}

bool Point::operator!=(const Point& p) const
{
    return !(*this == p);
}

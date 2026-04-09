#include "point.h"

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
    if (this->x == p.x && this->y == p.y && this->z == p.z)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Point::operator!=(const Point& p) const
{
    if (this->x != p.x || this->y != p.y || this->z != p.z)
    {
        return true;
    }
    else
    {
        return false;
    }
}

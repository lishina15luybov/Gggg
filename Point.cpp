#include "Point.h"
#include <sstream>
#include <cmath>

namespace VectorLib {

Point::Point() : m_x(0.0), m_y(0.0) {}

Point::Point(double x, double y) : m_x(x), m_y(y) {}

double Point::getX() const {
    return m_x;
}

double Point::getY() const {
    return m_y;
}

void Point::setX(double x) {
    m_x = x;
}

void Point::setY(double y) {
    m_y = y;
}

std::string Point::toString() const {
    std::stringstream ss;
    ss << "(" << m_x << "; " << m_y << ")";
    return ss.str();
}

bool Point::operator==(const Point& other) const {
    const double eps = 1e-9;
    return std::fabs(m_x - other.m_x) < eps && std::fabs(m_y - other.m_y) < eps;
}

bool Point::operator!=(const Point& other) const {
    return !(*this == other);
}

Point Point::operator+(double scalar) const {
    return Point(m_x + scalar, m_y + scalar);
}

Point Point::operator-(double scalar) const {
    return Point(m_x - scalar, m_y - scalar);
}

Point Point::operator+(const Point& other) const {
    return Point(m_x + other.m_x, m_y + other.m_y);
}

Point Point::operator-(const Point& other) const {
    return Point(m_x - other.m_x, m_y - other.m_y);
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << point.toString();
    return os;
}

std::istream& operator>>(std::istream& is, Point& point) {
    double x, y;
    is >> x >> y;
    point = Point(x, y);
    return is;
}

} // namespace VectorLib

#include "Point.h"

namespace VectorLib {

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

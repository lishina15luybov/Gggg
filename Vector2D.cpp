#include "Vector2D.h"
#include <sstream>
#include <cmath>
#include <limits>

namespace VectorLib {

// ==================== Реализация Vector ====================

Vector::Vector() : m_start(0, 0), m_end(0, 0) {}

Vector::Vector(const Point& start, const Point& end) : m_start(start), m_end(end) {}

Vector::~Vector() {}

Point Vector::getStart() const {
    return m_start;
}

Point Vector::getEnd() const {
    return m_end;
}

Point Vector::getCoordinates() const {
    return m_end - m_start;
}

double Vector::length() const {
    Point coords = getCoordinates();
    return std::sqrt(coords.getX() * coords.getX() + coords.getY() * coords.getY());
}

double Vector::angleBetween(const Vector& v1, const Vector& v2) {
    Point coords1 = v1.getCoordinates();
    Point coords2 = v2.getCoordinates();

    double dot = coords1.getX() * coords2.getX() + coords1.getY() * coords2.getY();
    double len1 = v1.length();
    double len2 = v2.length();

    const double eps = std::numeric_limits<double>::epsilon();
    if (len1 < eps || len2 < eps) {
        return 0.0;
    }

    double cosAngle = dot / (len1 * len2);
    if (cosAngle > 1.0) cosAngle = 1.0;
    if (cosAngle < -1.0) cosAngle = -1.0;

    return std::acos(cosAngle);
}

std::string Vector::toString() const {
    std::stringstream ss;
    ss << "Vector[" << m_start << " -> " << m_end << "], length = " << length();
    return ss.str();
}

Vector Vector::readFromStream(std::istream& is) {
    Point start, end;
    is >> start >> end;
    return Vector(start, end);
}

std::ostream& operator<<(std::ostream& os, const Vector& v) {
    os << v.toString();
    return os;
}

// ==================== Реализация Vector2D ====================

Vector2D::Vector2D() : Vector() {}

Vector2D::Vector2D(const Point& start, const Point& end) : Vector(start, end) {}

Vector2D::Vector2D(const double x1, const double y1, const double x2, const double y2)
    : Vector(Point(x1, y1), Point(x2, y2)) {}

bool Vector2D::operator==(const Vector2D& other) const {
    return getCoordinates() == other.getCoordinates();
}

bool Vector2D::operator!=(const Vector2D& other) const {
    return !(*this == other);
}

Vector2D Vector2D::operator+(const Vector2D& other) const {
    Point coords1 = getCoordinates();
    Point coords2 = other.getCoordinates();
    Point newCoords = coords1 + coords2;
    return Vector2D(Point(0, 0), newCoords);
}

Vector2D Vector2D::operator-(const Vector2D& other) const {
    Point coords1 = getCoordinates();
    Point coords2 = other.getCoordinates();
    Point newCoords = coords1 - coords2;
    return Vector2D(Point(0, 0), newCoords);
}

Vector2D Vector2D::operator*(const double scalar) const {
    Point coords = getCoordinates();
    return Vector2D(Point(0, 0), Point(coords.getX() * scalar, coords.getY() * scalar));
}

std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
    os << v.toString();
    return os;
}

Vector2D Vector2D::readFromStream(std::istream& is) {
    Point start, end;
    is >> start >> end;
    return Vector2D(start, end);
}

std::string Vector2D::toString(const Vector2D& v) {
    return v.toString();
}

} // namespace VectorLib

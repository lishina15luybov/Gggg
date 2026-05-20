#include "Vector2D.h"

namespace VectorLib {

double Vector::angleBetween(const Vector& v1, const Vector& v2) {
    Point coords1 = v1.getCoordinates();
    Point coords2 = v2.getCoordinates();

    double dot = coords1.getX() * coords2.getX() + coords1.getY() * coords2.getY();
    double len1 = v1.length();
    double len2 = v2.length();

    if (len1 < 1e-9 || len2 < 1e-9) {
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

Vector2D Vector2D::operator*(double scalar) const {
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

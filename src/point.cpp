#include "point.hpp"


namespace GJK {
  Point Point::operator-(const Point &other) const {
    return Point(x - other.x, y - other.y, z - other.z);
  }

  Point Point::operator-() const { return Point(-x, -y, -z); }

  Point Point::operator/(double scalar) const {
    return Point(x / scalar, y / scalar, z / scalar);
  };

  Point Point::operator+(const Point &other) const {
    return Point(x + other.x, y + other.y, z + other.z);
  }

  void Point::operator+=(const Point &other) {
    this->x += other.x;
    this->y += other.y;
    this->z += other.y;
  }

  void Point::operator/=(const double value) {
    this->x /= value;
    this->y /= value;
    this->z /= value;
  }

  double Point::dot_product(const Point &other) const {
    return x * other.x + y * other.y + z * other.z;
  };

  Point Point::normalize() const {
    double l2_norm = sqrt(x * x + y * y + z * z);
    if (l2_norm < kEPS) return Point(0, 0, 0);
    return *this / l2_norm;
  }

  Point Point::cross_product(const Point &other) const {
    return Point(this->y * other.z - this->z * other.z,
                 this->x * other.z - this->z * other.x,
                 this->x * other.y - this->y * other.x);
  }
}
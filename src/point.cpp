#include "point.hpp"

#include <cmath>  // abs, sqrt

namespace Geometry {
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

  bool Point::operator==(const Point &other) const {
    return std::abs(x - other.x) <= kEPS && std::abs(y - other.y) <= kEPS &&
           std::abs(z - other.z) <= kEPS;
  }

  bool Point::operator!=(const Point &other) const { return !(*this == other); }

  void Point::operator+=(const Point &other) {
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
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
    double l2_norm = std::sqrt(x * x + y * y + z * z);
    if (l2_norm < kEPS) return kOrigin;
    return *this / l2_norm;
  }

  Point Point::cross_product(const Point &other) const {
    return Point(this->y * other.z - this->z * other.y,
                 this->z * other.x - this->x * other.z,
                 this->x * other.y - this->y * other.x);
  }
  }  // namespace Geometry
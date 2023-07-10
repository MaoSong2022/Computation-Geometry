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

Point Point::operator*(double scalar) const {
  return Point(x * scalar, y * scalar, z * scalar);
}

bool Point::operator==(const Point &other) const {
  return std::abs(x - other.x) <= kEPS && std::abs(y - other.y) <= kEPS &&
         std::abs(z - other.z) <= kEPS;
}

bool Point::operator!=(const Point &other) const { return !(*this == other); }

Point &Point::operator+=(const Point &other) {
  this->x += other.x;
  this->y += other.y;
  this->z += other.z;
  return *this;
}

Point &Point::operator*=(double scalar) {
  this->x *= scalar;
  this->y *= scalar;
  this->z *= scalar;
  return *this;
}

Point &Point::operator/=(const double value) {
  this->x /= value;
  this->y /= value;
  this->z /= value;
  return *this;
}

double Point::dot_product(const Point &other) const {
  return x * other.x + y * other.y + z * other.z;
};

double Point::distance_to(const Point &other) const {
  return std::sqrt((x - other.x) * (x - other.x) +
                   (y - other.y) * (y - other.y) +
                   (z - other.z) * (z - other.z));
}

double Point::length() const { return std::sqrt(x * x + y * y + z * z); }

Point Point::normalize() const {
  const double length = this->length();
  if (length < kEPS) return kOrigin;
  return *this / length;
}

Point Point::cross_product(const Point &other) const {
  return Point(this->y * other.z - this->z * other.y,
               this->z * other.x - this->x * other.z,
               this->x * other.y - this->y * other.x);
}

Point operator*(double scalar, const Point &point) { return point * scalar; }

}  // namespace Geometry
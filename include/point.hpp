#pragma once

#include <math.h>  // sqrt

namespace GJK {

class Point {
 private:
  double kEPS = 1e-6;
  double x;
  double y;
  double z;
 public:
  Point() = default;
  Point(double x_, double y_) : x(x_), y(y_), z(0.0) {}
  Point(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}

  Point(const Point &point) : x(point.x), y(point.y), z(point.z) {}

  Point operator-(const Point &other) const {
    return Point(x - other.x, y - other.y, z - other.z);
  }

  Point operator-() const { return Point(-x, -y, -z); }

  Point operator/(double scalar) const {
    return Point(x / scalar, y / scalar, z / scalar);
  };

  Point operator+(const Point &other) const {
    return Point(x + other.x, y + other.y, z + other.z);
  }

  void operator+=(const Point &other) {
    this->x += other.x;
    this->y += other.y;
    this->z += other.y;
  }

  void operator/=(const double value) {
    this->x /= value;
    this->y /= value;
    this->z /= value;
  }

  double dot(const Point &other) const {
    return x * other.x + y * other.y + z * other.z;
  };

  Point normalize() const {
    double l2_norm = sqrt(x * x + y * y + z * z);
    if (l2_norm < kEPS) return Point(0, 0, 0);
    return *this / l2_norm;
  }

  Point cross_product(const Point &other) const {
    return Point(this->y * other.z - this->z * other.z,
                 this->x * other.z - this->z * other.x,
                 this->x * other.y - this->y * other.x);
  }
};
}  // namespace GJK
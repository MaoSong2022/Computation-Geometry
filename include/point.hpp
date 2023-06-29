#pragma once

#include <math.h>  // sqrt

namespace GJK {

struct Point {
  static constexpr double kEPS = 1e-6;
  double x;
  double y;
  double z;

  Point() = default;
  Point(double x_, double y_) : x(x_), y(y_), z(0.0) {}
  Point(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}

  Point(const Point &point) : x(point.x), y(point.y), z(point.z) {}

  Point operator-(const Point &other) const;

  Point operator-() const;

  Point operator/(double scalar) const;

  Point operator+(const Point &other) const;

  void operator+=(const Point &other);

  void operator/=(const double value);

  double dot_product(const Point &other) const;

  Point normalize() const;

  Point cross_product(const Point &other) const;
};
}  // namespace GJK
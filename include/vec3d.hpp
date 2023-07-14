#pragma once

namespace Geometry {

struct Vec3d {
  static constexpr double kEPS = 1e-6;
  double x;
  double y;
  double z;

  Vec3d() = default;
  Vec3d(double x_, double y_) : x(x_), y(y_), z(0.0) {}
  Vec3d(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}

  Vec3d(const Vec3d &point) : x(point.x), y(point.y), z(point.z) {}

  Vec3d operator-(const Vec3d &other) const;

  Vec3d operator-() const;

  Vec3d operator/(double scalar) const;

  Vec3d operator+(const Vec3d &other) const;
  Vec3d operator*(double scalar) const;

  bool operator==(const Vec3d &other) const;

  Vec3d &operator*=(double scalar);
  bool operator!=(const Vec3d &other) const;
  Vec3d &operator+=(const Vec3d &other);

  Vec3d &operator/=(const double value);

  double dot_product(const Vec3d &other) const;

  double distance_to(const Vec3d &other) const;

  /**
   * @brief Calculates the distance from a point to a straight line determined
   * by two points.
   *
   * @param a A point on the line.
   * @param b Another point on the line.
   * @return The distance between the point and the line.
   */
  double distance_to_Line(const Vec3d &a, const Vec3d &b) const;

  double length() const;

  Vec3d normalize() const;

  Vec3d cross_product(const Vec3d &other) const;
};

Vec3d operator*(double scalar, const Vec3d &other);

const Vec3d kOrigin = Vec3d(0.0, 0.0, 0.0);
}  // namespace Geometry
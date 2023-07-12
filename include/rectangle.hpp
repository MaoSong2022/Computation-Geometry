#pragma once

#include "polygon.hpp"

namespace Geometry {
class Rectangle : public Polygon {
 public:
  Rectangle() = default;
  explicit Rectangle(const Vec3d& point1, const Vec3d& point2)
      : Polygon(std::vector<Vec3d>{point1, point2, Vec3d(point1.x, point2.y),
                                   Vec3d(point2.x, point1.y)}) {}
  Rectangle(const std::vector<Vec3d>& vertices) : Polygon(vertices) {}
  ~Rectangle() {}

  double left_bound() const;
  double right_bound() const;
  double lower_bound() const;
  double upper_bound() const;

  bool intersects(const Rectangle&) const;
};
}  // namespace Geometry
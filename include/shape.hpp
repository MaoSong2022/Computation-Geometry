#pragma once

#include <vector>

#include "vec3d.hpp"

namespace Geometry {
class Shape {
 protected:
  Vec3d center_;
  std::vector<Vec3d> vertices_;

 public:
  Shape() = default;
  Shape(const std::vector<Vec3d> &vertices, const Vec3d &center)
      : vertices_(vertices), center_(center) {}
  virtual ~Shape() {}

  const Vec3d &center() const { return center_; }
  const std::vector<Vec3d> &vertices() const { return vertices_; }

  /**
   * @brief compute the furthest point along a direction
   *
   * @param d direction
   * @return Point
   */
  virtual Vec3d support(const Vec3d &d) const = 0;
};
}  // namespace Geometry
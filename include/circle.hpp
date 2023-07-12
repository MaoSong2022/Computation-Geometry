#pragma once

#include "shape.hpp"

namespace Geometry {
class Circle : public Shape {
 private:
  double radius_;

 public:
  Circle(const Vec3d& center, double radius)
      : Shape({}, center), radius_(radius) {}

  Vec3d support(const Vec3d& d) const override;
};
}  // namespace Geometry
#pragma once

#include "shape.hpp"

namespace Geometry {
// Circle class inherits from Shape class
class Circle : public Shape {
 private:
  double radius_;  // private member variable for radius

 public:
  /**
   * Constructor for Circle class
   * @param center The center point of the circle
   * @param radius The radius of the circle
   */
  Circle(const Vec3d& center, double radius)
      : Shape({}, center), radius_(radius) {}

  /**
   * Get the radius of the circle
   * @return The radius of the circle
   */
  double radius() const { return radius_; }

  /**
   * Calculate the support point of the circle in a given direction
   * @param d The direction vector
   * @return The support point of the circle in the given direction
   */
  Vec3d support(const Vec3d& d) const override;
};

}  // namespace Geometry
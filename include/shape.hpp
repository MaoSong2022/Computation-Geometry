#pragma once

#include <vector>

#include "point.hpp"

namespace GJK {
class Shape {
 protected:
  Point center_;
  std::vector<Point> vertices_;

 public:
  Shape() = default;
  Shape(const std::vector<Point> &vertices, const Point &center)
      : vertices_(vertices), center_(center) {}
  virtual ~Shape() {}

  const Point &center() const { return center_; }
  
  /**
   * @brief compute the furthest point along a direction
   * 
   * @param d direction
   * @return Point 
   */
  virtual Point support(const Point &d) const = 0;
};
}  // namespace GJK
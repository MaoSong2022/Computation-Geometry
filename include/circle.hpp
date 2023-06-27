#pragma once

#include "shape.hpp"

namespace GJK {
class Circle : public Shape {
 private:
  double radius_;

 public:
  Circle(const Point& center, double radius)
      : Shape({}, center), radius_(radius) {}

  Point support(const Point& d) const override;
};
}  // namespace GJK
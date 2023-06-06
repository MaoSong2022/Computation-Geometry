#pragma once

#include "shape.hpp"

namespace GJK {
class Polygon : public Shape {
 private:
  /* data */
 public:
  Polygon() = default;
  Polygon(const std::vector<Point>& vertices) : Shape(vertices, Point()){};
  ~Polygon(){}

  Point support(const Point& d) const override;
};
}  // namespace GJK
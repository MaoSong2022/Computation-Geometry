#pragma once

#include "shape.hpp"

namespace Geometry {
class LineSegment : public Shape {
 public:
  LineSegment() = delete;
  explicit LineSegment(const Point& point1, const Point& point2)
      : endpoint1_(point1), endpoint2_(point2) {
    center_ = (endpoint1_ + endpoint2_) / 2.0;
  }

  LineSegment(const std::vector<Point>& vertices)
      : Shape(vertices, Point()),
        endpoint1_(vertices[0]),
        endpoint2_(vertices[1]) {
    center_ = (endpoint1_ + endpoint2_) / 2.0;
  }
  ~LineSegment() {}

  Point support(const Point& d) const override;

  /**
   * @brief if a point is on the line segment.
   *
   * @param point A Point object representing the point to check.
   *
   * @return A boolean value indicating whether the point is on the line
   * segment.
   *
   * @see Point
   */
  bool contains(const Point& point) const;

 private:
  Point endpoint1_;
  Point endpoint2_;
};
}  // namespace Geometry
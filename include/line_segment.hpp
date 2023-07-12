#pragma once

#include "shape.hpp"

namespace Geometry {
class LineSegment : public Shape {
 public:
  LineSegment() = default;
  explicit LineSegment(const Vec3d& point1, const Vec3d& point2)
      : endpoint1_(point1), endpoint2_(point2) {
    center_ = (endpoint1_ + endpoint2_) / 2.0;
  }

  LineSegment(const std::vector<Vec3d>& vertices)
      : Shape(vertices, Vec3d()),
        endpoint1_(vertices[0]),
        endpoint2_(vertices[1]) {
    center_ = (endpoint1_ + endpoint2_) / 2.0;
  }
  ~LineSegment() {}

  Vec3d support(const Vec3d& d) const override;

  /**
   * @brief Checks if a given point lies on the line segment.
   *
   * @param point The point to check.
   * @return True if the point lies on the line segment, false otherwise.
   */
  bool contains(const Vec3d& point) const;

  /**
   * @brief Computes the distance between a given point and the line segment.
   *
   * @param point The point to compute the distance from.
   * @return The distance between the point and the line segment.
   */
  double distance_to(const Vec3d& point) const;

  bool intersects(const LineSegment& other) const;

 private:
  Vec3d endpoint1_;
  Vec3d endpoint2_;
};
}  // namespace Geometry
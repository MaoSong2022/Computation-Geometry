#pragma once

#include "shape.hpp"

namespace Geometry {
class LineSegment : public Shape {
 public:
  LineSegment() = default;

  /**
   * @brief Constructs a LineSegment object with two endpoints.
   *
   * @param point1 The first endpoint.
   * @param point2 The second endpoint.
   */
  explicit LineSegment(const Vec3d& point1, const Vec3d& point2)
      : endpoint1_(point1), endpoint2_(point2) {
    center_ = (endpoint1_ + endpoint2_) / 2.0;
  }

  /**
   * @brief Constructs a LineSegment object from a vector of vertices.
   *
   * @param vertices The vector of vertices (should contain at least 2
   * vertices).
   */
  LineSegment(const std::vector<Vec3d>& vertices)
      : Shape(vertices, Vec3d()),
        endpoint1_(vertices[0]),
        endpoint2_(vertices[1]) {
    center_ = (endpoint1_ + endpoint2_) / 2.0;
  }

  ~LineSegment() override = default;

  /**
   * @brief Returns the first endpoint of the line segment.
   *
   * @return The first endpoint.
   */
  const Vec3d& endpoint1() const { return endpoint1_; }

  /**
   * @brief Returns the second endpoint of the line segment.
   *
   * @return The second endpoint.
   */
  const Vec3d& endpoint2() const { return endpoint2_; }

  /**
   * @brief Computes the support point of the line segment in the given
   * direction.
   *
   * @param d The direction vector.
   * @return The support point.
   */
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

  /**
   * @brief Checks if this line segment intersects with another line segment.
   *
   * @param other The other line segment.
   * @return True if the two line segments intersect, false otherwise.
   */
  bool intersects(const LineSegment& other) const;

  /**
   * @brief Returns the direction vector of the line segment.
   *
   * @return The direction vector.
   */
  Vec3d direction() const { return endpoint1_ - endpoint2_; }

 private:
  Vec3d endpoint1_;  // The first endpoint of the line segment.
  Vec3d endpoint2_;  // The second endpoint of the line segment.
};

}  // namespace Geometry
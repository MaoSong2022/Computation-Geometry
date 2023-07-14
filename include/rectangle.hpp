#pragma once

#include "polygon.hpp"
#include "circle.hpp"

namespace Geometry {
class Rectangle : public Polygon {
 public:
  Rectangle() = default;
  Rectangle(const std::vector<Vec3d>& vertices) : Polygon(vertices) {}
  ~Rectangle() {}

  double left_bound() const;
  double right_bound() const;
  double front_bound() const;
  double back_bound() const;
  double lower_bound() const;
  double upper_bound() const;

  bool AABBIntersects(const Rectangle &) const;

  bool intersects(const Rectangle&) const;

  bool contains(const Vec3d &) const;

  bool contains(const Rectangle &) const;

  bool contains(const Circle &) const;
};

/**
 * @brief Computes the cuboid (axis-aligned bounding box) that
 *        contains two diagonal points.
 *
 * Given two diagonal points of a cuboid, this function computes
 * the minimum axis-aligned bounding box (AABB) that contains
 * both points. The resulting cuboid is a rectangle with six faces,
 * defined by eight vertices.
 *
 * @param point1 The first diagonal point of the cuboid.
 * @param point2 The second diagonal point of the cuboid.
 *
 * @return A Rectangle object that represents the cuboid.
 */
Rectangle AABBFromDiagonalPoints(const Vec3d &point1, const Vec3d &point2);

}  // namespace Geometry
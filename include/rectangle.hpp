#pragma once

#include "circle.hpp"
#include "polygon.hpp"

namespace Geometry {
class Rectangle : public Polygon {
 public:
  Rectangle() = default;
  Rectangle(const std::vector<Vec3d>& vertices) : Polygon(vertices) {}
  ~Rectangle() override = default;

  /**
   * @brief Get the left bound of the rectangle.
   * @return The left bound of the rectangle.
   */
  double left_bound() const;

  /**
   * @brief Get the right bound of the rectangle.
   * @return The right bound of the rectangle.
   */
  double right_bound() const;

  /**
   * @brief Get the front bound of the rectangle.
   * @return The front bound of the rectangle.
   */
  double front_bound() const;

  /**
   * @brief Get the back bound of the rectangle.
   * @return The back bound of the rectangle.
   */
  double back_bound() const;

  /**
   * @brief Get the lower bound of the rectangle.
   * @return The lower bound of the rectangle.
   */
  double lower_bound() const;

  /**
   * @brief Get the upper bound of the rectangle.
   * @return The upper bound of the rectangle.
   */
  double upper_bound() const;

  /**
   * @brief Check if the rectangle axis-aligned bounding box (AABB)
   *        intersects with another rectangle's AABB.
   * @param other The other rectangle.
   * @return True if the AABBs intersect, false otherwise.
   */
  bool AABBIntersects(const Rectangle& other) const;

  /**
   * @brief Check if the rectangle intersects with another rectangle.
   * @param other The other rectangle.
   * @return True if the rectangles intersect, false otherwise.
   */
  bool intersects(const Rectangle& other) const;

  /**
   * @brief Check if the rectangle contains a point.
   * @param point The point to check.
   * @return True if the rectangle contains the point, false otherwise.
   */
  bool contains(const Vec3d& point) const;

  /**
   * @brief Check if the rectangle contains another rectangle.
   * @param other The other rectangle.
   * @return True if the rectangle contains the other rectangle, false
   * otherwise.
   */
  bool contains(const Rectangle& other) const;

  /**
   * @brief Check if the rectangle contains a circle.
   * @param circle The circle.
   * @return True if the rectangle contains the circle, false otherwise.
   */
  bool contains(const Circle& circle) const;
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
 * @return A Rectangle object that represents the cuboid.
 */
Rectangle AABBFromDiagonalPoints(const Vec3d& point1, const Vec3d& point2);

}  // namespace Geometry
#pragma once

#include "line_segment.hpp"
#include "shape.hpp"

namespace Geometry {
class Polygon : public Shape {
 public:
  Polygon() = default;
  Polygon(const std::vector<Vec3d>& vertices) : Shape(vertices, Vec3d()) {
    for (const auto& vertex : vertices_) {
      center_ += vertex;
    }
    center_ /= (1.0 * vertices.size());
  }
  ~Polygon() {}

  /**
   * @brief check if two polygons are equal
   *
   * @details Two polygons are equal if they contain the same vertices
   *
   * @return True if two polygons are equal, false otherwise
   */
  bool operator==(const Polygon&) const;

  bool operator!=(const Polygon&) const;

  Vec3d support(const Vec3d& d) const override;

  /**
   * @brief  if a point is contained within the polygon.
   *
   * @details This function tests if a point is contained within a polygon by
   * counting the number of times a horizontal ray from the point intersects
   * with the polygon edges. If the number of intersections is odd, then the
   * point is contained within the polygon.
   *
   * @param point The point to check for containment.
   *
   * @return True if the point is contained within the polygon, false otherwise.
   */
  bool contains(const Vec3d& point) const;

  /**
   * @brief  if a line segment is contained within the polygon.
   *
   * @param line_segment The line segment to check for containment.
   *
   * @return True if the line segment is contained within the polygon, false
   * otherwise.
   */
  bool contains(const LineSegment& line_segment) const;
};
}  // namespace Geometry
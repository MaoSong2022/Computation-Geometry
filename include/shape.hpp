#pragma once

#include <vector>

#include "vec3d.hpp"

namespace Geometry {
class Shape {
 protected:
  Vec3d center_;                 ///< The center point of the shape
  std::vector<Vec3d> vertices_;  ///< The vertices of the shape

 public:
  /**
   * @brief Default constructor for Shape
   */
  Shape() = default;

  /**
   * @brief Constructor for Shape
   * @param vertices The vertices of the shape
   * @param center The center point of the shape
   */
  Shape(const std::vector<Vec3d> &vertices, const Vec3d &center)
      : vertices_(vertices), center_(center) {}

  /**
   * @brief Virtual destructor for Shape
   */
  virtual ~Shape() = default;

  /**
   * @brief Get the center point of the shape
   * @return The center point
   */
  const Vec3d &center() const { return center_; }

  /**
   * @brief Get the vertices of the shape
   * @return The vertices
   */
  const std::vector<Vec3d> &vertices() const { return vertices_; }

  /**
   * @brief Get the vertices of the shape
   * @return The vertices
   */
  std::vector<Vec3d> &vertices() { return vertices_; }

  /**
   * @brief Compute the furthest point along a direction
   * @param d The direction
   * @return The furthest point
   */
  virtual Vec3d support(const Vec3d &d) const = 0;
};

}  // namespace Geometry
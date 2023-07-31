#pragma once

#include <iostream>

namespace Geometry {
struct Vec3d {
  static constexpr double kEPS = 1e-6;
  double x;
  double y;
  double z;

  Vec3d() = default;

  /**
   * @brief Constructs a 3D vector with given x and y coordinates.
   *
   * @param x_ The x coordinate.
   * @param y_ The y coordinate.
   */
  Vec3d(double x_, double y_) : x(x_), y(y_), z(0.0) {}

  /**
   * @brief Constructs a 3D vector with given x, y, and z coordinates.
   *
   * @param x_ The x coordinate.
   * @param y_ The y coordinate.
   * @param z_ The z coordinate.
   */
  Vec3d(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}

  /**
   * @brief Constructs a 3D vector by copying another vector.
   *
   * @param point The vector to copy.
   */
  Vec3d(const Vec3d &point) : x(point.x), y(point.y), z(point.z) {}

  /**
   * @brief Subtracts another vector from this vector.
   *
   * @param other The vector to subtract.
   * @return The resulting vector.
   */
  Vec3d operator-(const Vec3d &other) const;

  /**
   * @brief Negates this vector.
   *
   * @return The negated vector.
   */
  Vec3d operator-() const;

  /**
   * @brief Divides this vector by a scalar value.
   *
   * @param scalar The scalar value to divide by.
   * @return The resulting vector.
   */
  Vec3d operator/(double scalar) const;

  /**
   * @brief Adds another vector to this vector.
   *
   * @param other The vector to add.
   * @return The resulting vector.
   */
  Vec3d operator+(const Vec3d &other) const;

  /**
   * @brief Multiplies this vector by a scalar value.
   *
   * @param scalar The scalar value to multiply by.
   * @return The resulting vector.
   */
  Vec3d operator*(double scalar) const;

  /**
   * @brief Checks if this vector is equal to another vector.
   *
   * @param other The vector to compare with.
   * @return true if the vectors are equal; false otherwise.
   */
  bool operator==(const Vec3d &other) const;

  /**
   * @brief Multiplies this vector by a scalar value and updates this vector.
   *
   * @param scalar The scalar value to multiply by.
   * @return A reference to this vector.
   */
  Vec3d &operator*=(double scalar);

  /**
   * @brief Checks if this vector is not equal to another vector.
   *
   * @param other The vector to compare with.
   * @return true if the vectors are not equal; false otherwise.
   */
  bool operator!=(const Vec3d &other) const;

  /**
   * @brief Adds another vector to this vector and updates this vector.
   *
   * @param other The vector to add.
   * @return A reference to this vector.
   */
  Vec3d &operator+=(const Vec3d &other);

  /**
   * @brief Divides this vector by a scalar value and updates this vector.
   *
   * @param value The scalar value to divide by.
   * @return A reference to this vector.
   */
  Vec3d &operator/=(const double value);

  /**
   * @brief Checks if this vector is less than another vector.
   *
   * @param other The vector to compare with.
   * @return true if this vector is less than the other vector; false otherwise.
   */
  bool operator<(const Vec3d &other) const;

  /**
   * @brief Calculates the dot product of this vector with another vector.
   *
   * @param other The vector to calculate the dot product with.
   * @return The dot product.
   */
  double dot_product(const Vec3d &other) const;

  /**
   * @brief Calculates the Euclidean distance between this vector and another
   * vector.
   *
   * @param other The vector to calculate the distance to.
   * @return The Euclidean distance.
   */
  double distance_to(const Vec3d &other) const;

  /**
   * @brief Calculates the distance from a point to a straight line determined
   * by two points.
   *
   * @param a A point on the line.
   * @param b Another point on the line.
   * @return The distance between the point and the line.
   */
  double distance_to_Line(const Vec3d &a, const Vec3d &b) const;

  /**
   * @brief Calculates the length of this vector.
   *
   * @return The length of the vector.
   */
  double length() const;

  /**
   * @brief Normalizes this vector.
   *
   * @return The normalized vector.
   */
  Vec3d normalize() const;

  /**
   * @brief Calculates the cross product of this vector with another vector.
   *
   * @param other The vector to calculate the cross product with.
   * @return The cross product.
   */
  Vec3d cross_product(const Vec3d &other) const;

  /**
   * @brief Computes the cross product of two vectors in 2 dimensional.
   *
   * @param other The other vector to compute the cross product with.
   * @return The scalar value of the 2D cross product of the two vectors.
   */
  double cross_product_2d(const Vec3d &other) const;
};

/**
 * @brief Multiplies a vector by a scalar value.
 *
 * @param scalar The scalar value to multiply by.
 * @param other The vector to multiply.
 * @return The resulting vector.
 */
Vec3d operator*(double scalar, const Vec3d &other);

/**
 * @brief Swaps the values of two 3D vectors in place.
 *
 * @param lhs The first vector to swap.
 * @param rhs The second vector to swap.
 */
void swap(Vec3d &lhs, Vec3d &rhs);

/**
 * @brief Prints the coordinates of a 3D vector to an output stream.
 *
 * @param os The output stream.
 * @param point The vector to print.
 * @return The output stream.
 */
std::ostream &operator<<(std::ostream &os, const Vec3d &point);

/**
 * @brief The origin point in 3D space.
 */
const Vec3d kOrigin = Vec3d(0.0, 0.0, 0.0);

}  // namespace Geometry
#pragma once

#include "shape.hpp"

namespace Geometry {
/*
 * @brief Determine if two convex shapes intersect.
 * @param a Pointer to the first shape.
 * @param b Pointer to the second shape.
 * @return True if the two shapes intersect, false otherwise.
 */
bool GJK_algorithm(const Shape *a, const Shape *b);

/*
 * @brief Calculate the support point of two shapes in a given direction.
 * @param a Pointer to the first shape.
 * @param b Pointer to the second shape.
 * @param d The direction vector.
 * @return The support point in the given direction.
 */
Vec3d support(const Shape *a, const Shape *b, const Vec3d &d);

/*
 * @brief Calculate the triple product of three vectors.
 * @param a The first vector.
 * @param b The second vector.
 * @param c The third vector.
 * @return The result of the triple product.
 */
Vec3d triple_product(const Vec3d &a, const Vec3d &b, const Vec3d &c);

/*
 * @brief Check if two vectors are pointing in the same direction.
 * @param d1 The first vector.
 * @param d2 The second vector.
 * @return True if the two vectors are pointing in the same direction, false
 * otherwise.
 */
bool is_same_direction(const Vec3d &d1, const Vec3d &d2);

/*
 * @brief Handle the line case in the GJK algorithm.
 * @param simplex The simplex used in the algorithm.
 * @param d A reference to a vector. It will be set to a perpendicular vector
 * from the face closest to the origin.
 * @return True if the line case is handled successfully, false otherwise.
 */
bool line_case(std::vector<Vec3d> &simplex, Vec3d &d);

/*
 * @brief Check if the origin (0,0,0) is contained within the simplex.
 * @param simplex A vector of points representing the vertices of the simplex.
 * @param d A reference to a vector. It will be set to a perpendicular vector
 * from the face closest to the origin.
 * @return True if the origin is contained within the simplex, false otherwise.
 */
bool contains_origin(std::vector<Vec3d> &simplex, Vec3d &d);
}  // namespace Geometry
#pragma once

#include "shape.hpp"

namespace Geometry {
/*
 * @brief determine if two convex shapes intersect
 * @return true if two shapes intersect.
 */
bool GJK_algorithm(Shape *a, Shape *b);

Vec3d support(Shape *a, Shape *b, const Vec3d &d);

Vec3d triple_product(const Vec3d &a, const Vec3d &b, const Vec3d &c);

bool is_same_direction(const Vec3d &d1, const Vec3d &d2);

bool line_case(std::vector<Vec3d> &simplex, Vec3d &d);

/**
 * @brief Checks if the origin (0,0,0) is contained within the simplex.
 * @param simplex A vector of Points representing the vertices of the
 * simplex.
 * @param d A reference to a Point. d will be set to a perpendicular vector
 * from the face closest to the origin.
 * @return True if the origin is contained within the simplex, false
 * otherwise.
 */
bool contains_origin(std::vector<Vec3d> &simplex, Vec3d &d);
}  // namespace Geometry
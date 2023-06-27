#pragma once

#include "shape.hpp"

namespace GJK {
/*
 * @brief determine if two convex shapes intersect
 * @return true if two shapes intersect.
 */
bool algorithm(Shape *a, Shape *b);

Point support(Shape *a, Shape *b, const Point &d);

Point triple_product(const Point &a, const Point &b, const Point c);

/*
 * @brief Checks if the origin (0,0,0) is contained within the simplex.
 * @param simplex A vector of Points representing the vertices of the simplex.
 * @param d A reference to a Point. d will be set to a perpendicular vector from
 * the face closest to the origin.
 * @return True if the origin is contained within the simplex, false otherwise.
 */
bool contains_origin(std::vector<Point> &simplex, Point &d);
}  // namespace GJK
#pragma once

#include "shape.hpp"

namespace Geometry {
/*
 * @brief determine if two convex shapes intersect
 * @return true if two shapes intersect.
 */
bool GJK_algorithm(Shape *a, Shape *b);

Point support(Shape *a, Shape *b, const Point &d);

Point triple_product(const Point &a, const Point &b, const Point &c);

bool is_same_direction(const Point &d1, const Point &d2);

/**
 * @brief if a point Q is on the line segment defined by points P1 and P2.
 *
 * @param P1 A Point object representing one end of the line segment.
 * @param P2 A Point object representing the other end of the line segment.
 * @param Q A Point object representing the point to check.
 *
 * @return A boolean value indicating whether Q is on the line segment P1-P2.
 *
 * @see Point
 */
bool in_line_segment(const Point &P1, const Point &P2, const Point &Q);

bool line_case(std::vector<Point> &simplex, Point &d);

/**
 * @brief Checks if the origin (0,0,0) is contained within the simplex.
 * @param simplex A vector of Points representing the vertices of the
 * simplex.
 * @param d A reference to a Point. d will be set to a perpendicular vector
 * from the face closest to the origin.
 * @return True if the origin is contained within the simplex, false
 * otherwise.
 */
bool contains_origin(std::vector<Point> &simplex, Point &d);
}  // namespace Geometry
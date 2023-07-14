#pragma once

#include "shape.hpp"

namespace Geometry {
/**
 * @brief Checks if two shapes are in collision using the Separating Axis
 * Theorem (SAT).
 *
 * @param a Pointer to the first shape.
 * @param b Pointer to the second shape.
 *
 * @return True if the shapes are in collision, false otherwise.
 */
bool SAT_algorithm(const Shape *a, const Shape *b);
}  // namespace Geometry
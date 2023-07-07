#include <iostream>

#include "GJK.hpp"
#include "polygon.hpp"

int main(int argc, char const *argv[]) {
  std::vector<Geometry::Point> vertices1{Geometry::Point(4.0, 11.0),
                                         Geometry::Point(5.0, 5.0),
                                         Geometry::Point(9.0, 9.0)};
  std::vector<Geometry::Point> vertices2{Geometry::Point(7.0, 9.0),
                                         Geometry::Point(13.0, 11.0),
                                         Geometry::Point(11.0, 6.0)};
  std::vector<Geometry::Point> vertices3{
      Geometry::Point(2.0, 4.0), Geometry::Point(6.0, 5.0),
      Geometry::Point(11.0, 4.0), Geometry::Point(8.0, -1.0)};
  Geometry::Shape *triangle1 = new Geometry::Polygon(vertices1);
  Geometry::Shape *triangle2 = new Geometry::Polygon(vertices2);
  Geometry::Shape *polygon1 = new Geometry::Polygon(vertices3);
  if (Geometry::GJK_algorithm(triangle1, triangle2)) {
    std::cout << "In collision" << std::endl;
  } else {
    std::cout << "No collision" << std::endl;
  }
  if (Geometry::GJK_algorithm(triangle1, polygon1)) {
    std::cout << "In collision" << std::endl;
  } else {
    std::cout << "No collision" << std::endl;
  }
  return 0;
}

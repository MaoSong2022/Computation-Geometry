#include <iostream>

#include "GJK.hpp"
#include "polygon.hpp"

int main(int argc, char const *argv[]) {
  std::vector<Geometry::Vec3d> vertices1{Geometry::Vec3d(4.0, 11.0),
                                         Geometry::Vec3d(5.0, 5.0),
                                         Geometry::Vec3d(9.0, 9.0)};
  std::vector<Geometry::Vec3d> vertices2{Geometry::Vec3d(7.0, 9.0),
                                         Geometry::Vec3d(13.0, 11.0),
                                         Geometry::Vec3d(11.0, 6.0)};
  std::vector<Geometry::Vec3d> vertices3{
      Geometry::Vec3d(2.0, 4.0), Geometry::Vec3d(6.0, 5.0),
      Geometry::Vec3d(11.0, 4.0), Geometry::Vec3d(8.0, -1.0)};
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

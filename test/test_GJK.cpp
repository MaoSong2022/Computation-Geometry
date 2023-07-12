
#include <gtest/gtest.h>

#include <vector>

#include "GJK.hpp"
#include "polygon.hpp"
#include "vec3d.hpp"

class GJKTestSuite : public ::testing::Test {
 protected:
  void SetUp() override {
    std::vector<Geometry::Vec3d> vertices1{Geometry::Vec3d(4.0, 11.0),
                                           Geometry::Vec3d(5.0, 5.0),
                                           Geometry::Vec3d(9.0, 9.0)};
    std::vector<Geometry::Vec3d> vertices2{
        Geometry::Vec3d(2.0, 4.0), Geometry::Vec3d(6.0, 5.0),
        Geometry::Vec3d(11.0, 4.0), Geometry::Vec3d(8.0, -1.0)};
    triangle1 = new Geometry::Polygon(vertices1);
    triangle2 = new Geometry::Polygon(vertices2);
  }

  void TearDown() override {
    delete triangle1;
    delete triangle2;
  }

  Geometry::Shape *triangle1;
  Geometry::Shape *triangle2;
  const double kEPS = 1e-3;
};

TEST_F(GJKTestSuite, TripleProduct) {
  Geometry::Vec3d result = Geometry::triple_product(
      triangle1->vertices()[1] - triangle1->vertices()[0],
      triangle1->vertices()[0] - Geometry::Vec3d(0, 0, 0),
      triangle1->vertices()[1] - triangle1->vertices()[0]);
  ASSERT_NEAR(result.x, 210, kEPS);
  ASSERT_NEAR(result.y, 35, kEPS);
  ASSERT_NEAR(result.z, 0, kEPS);
}

TEST_F(GJKTestSuite, CollisionFree) {
  ASSERT_FALSE(Geometry::GJK_algorithm(triangle1, triangle2));
}

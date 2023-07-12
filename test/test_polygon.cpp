#include <gtest/gtest.h>

#include "polygon.hpp"
#include "vec3d.hpp"

class PolygonTestSuite : public ::testing::Test {
 protected:
  void SetUp() override {
    std::vector<Geometry::Vec3d> vertices1{Geometry::Vec3d(4.0, 11.0),
                                           Geometry::Vec3d(5.0, 5.0),
                                           Geometry::Vec3d(9.0, 9.0)};
    triangle1 = new Geometry::Polygon(vertices1);
  }

  void TearDown() override { delete triangle1; }

  Geometry::Shape *triangle1;
  const double kEPS = 1e-3;
};

TEST_F(PolygonTestSuite, center) {
  ASSERT_NEAR(triangle1->center().x, 6.0, kEPS);
  ASSERT_NEAR(triangle1->center().y, 25.0 / 3, kEPS);
  ASSERT_NEAR(triangle1->center().z, 0.0, kEPS);
}

TEST_F(PolygonTestSuite, support) {
  Geometry::Vec3d direction = Geometry::Vec3d(1, 1);
  Geometry::Vec3d d = triangle1->support(direction);
  ASSERT_NEAR(d.x, 9.0, kEPS);
  ASSERT_NEAR(d.y, 9.0, kEPS);
  ASSERT_NEAR(d.z, 0.0, kEPS);
}
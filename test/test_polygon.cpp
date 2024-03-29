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

  Geometry::Polygon *triangle1;
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

TEST_F(PolygonTestSuite, contains) {
  Geometry::Vec3d point1 = Geometry::Vec3d(4, 8);
  Geometry::Vec3d point2 = Geometry::Vec3d(8.2, 8);
  Geometry::Vec3d point3 = Geometry::Vec3d(6, 9);
  Geometry::Vec3d point4 = Geometry::Vec3d(8.18, 9.18);
  ASSERT_TRUE(triangle1->contains(point3));
  ASSERT_TRUE(triangle1->contains(point4));
  ASSERT_FALSE(triangle1->contains(point1));
  ASSERT_FALSE(triangle1->contains(point2));
}

TEST_F(PolygonTestSuite, equal) {
  ASSERT_TRUE((*triangle1) ==
              (Geometry::Polygon(std::vector<Geometry::Vec3d>{
                  Geometry::Vec3d(4.0, 11.0), Geometry::Vec3d(9.0, 9.0),
                  Geometry::Vec3d(5.0, 5.0)})));
  ASSERT_TRUE((*triangle1) ==
              (Geometry::Polygon(std::vector<Geometry::Vec3d>{
                  Geometry::Vec3d(9.0, 9.0), Geometry::Vec3d(5.0, 5.0),
                  Geometry::Vec3d(4.0, 11.0)})));
  ASSERT_FALSE((*triangle1) ==
               (Geometry::Polygon(std::vector<Geometry::Vec3d>{
                   Geometry::Vec3d(9.0, 9.0), Geometry::Vec3d(5.0, 5.0),
                   Geometry::Vec3d(4.0, 11.0), Geometry::Vec3d(5.0, 11.0)})));
  ASSERT_FALSE((*triangle1) ==
               (Geometry::Polygon(std::vector<Geometry::Vec3d>{
                   Geometry::Vec3d(9.0, 9.0), Geometry::Vec3d(5.0, 5.0),
                   Geometry::Vec3d(4.0, 11.1)})));
}

TEST_F(PolygonTestSuite, contains_line_segment) {
  Geometry::LineSegment line_segment1 =
      Geometry::LineSegment(Geometry::Vec3d(4, 4), Geometry::Vec3d(8, 4));
  Geometry::LineSegment line_segment2 =
      Geometry::LineSegment(Geometry::Vec3d(5, 10), Geometry::Vec3d(6, 7));
  Geometry::LineSegment line_segment3 =
      Geometry::LineSegment(Geometry::Vec3d(6, 9), Geometry::Vec3d(8, 11));
  ASSERT_TRUE(triangle1->contains(line_segment2));
  ASSERT_FALSE(triangle1->contains(line_segment3));
  ASSERT_FALSE(triangle1->contains(line_segment1));
}

TEST_F(PolygonTestSuite, from_vertices) {
  std::vector<Geometry::Vec3d> points1{
      Geometry::Vec3d(4.0, 11.0), Geometry::Vec3d(5.0, 5.0),
      Geometry::Vec3d(9.0, 9.0),  Geometry::Vec3d(5, 9),
      Geometry::Vec3d(7, 9),      Geometry::Vec3d(6, 7)};
  ASSERT_TRUE(Geometry::Polygon::from_vertices(points1) == (*triangle1));

  points1.push_back(Geometry::Vec3d(4.0, 11.0));
  ASSERT_TRUE(Geometry::Polygon::from_vertices(points1) == (*triangle1));

  points1.push_back(Geometry::Vec3d(7.0, 7.0));
  ASSERT_TRUE(Geometry::Polygon::from_vertices(points1) == (*triangle1));

  points1.push_back(Geometry::Vec3d(10.0, 10.0));
  ASSERT_FALSE(Geometry::Polygon::from_vertices(points1) == (*triangle1));
}
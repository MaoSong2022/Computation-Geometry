#include <gtest/gtest.h>

#include "line_segment.hpp"

class LineSegmentTestSuite : public ::testing::Test {
 protected:
  void SetUp() override {
    endpoint1 = Geometry::Vec3d(4.0, 11.0);
    endpoint2 = Geometry::Vec3d(5.0, 5.0);
    line_segment = Geometry::LineSegment(endpoint1, endpoint2);
  }

  void TearDown() override {}

  Geometry::LineSegment line_segment;
  Geometry::Vec3d endpoint1;
  Geometry::Vec3d endpoint2;
  const double kEPS = 1e-3;
};

TEST_F(LineSegmentTestSuite, center) {
  ASSERT_NEAR(line_segment.center().x, 4.5, kEPS);
  ASSERT_NEAR(line_segment.center().y, 8.0, kEPS);
  ASSERT_NEAR(line_segment.center().z, 0.0, kEPS);
}

TEST_F(LineSegmentTestSuite, Support) {
  Geometry::Vec3d direction1 = Geometry::Vec3d(1.0, 1.0);
  auto support1 = line_segment.support(direction1);
  ASSERT_NEAR(support1.x, 4.0, kEPS);
  ASSERT_NEAR(support1.y, 11.0, kEPS);
  ASSERT_NEAR(support1.z, 0.0, kEPS);

  Geometry::Vec3d direction2 = Geometry::Vec3d(1, -1.0);
  auto support2 = line_segment.support(direction2);
  ASSERT_NEAR(support2.x, 5.0, kEPS);
  ASSERT_NEAR(support2.y, 5.0, kEPS);
  ASSERT_NEAR(support2.z, 0.0, kEPS);
}

TEST_F(LineSegmentTestSuite, contains) {
  Geometry::Vec3d direction = line_segment.direction();
  ASSERT_NEAR(direction.x, -1.0, kEPS);
  ASSERT_NEAR(direction.y, 6.0, kEPS);
  ASSERT_NEAR(direction.z, 0.0, kEPS);
}

TEST_F(LineSegmentTestSuite, direction) {
  ASSERT_TRUE(line_segment.contains(endpoint1));
  ASSERT_TRUE(line_segment.contains(endpoint2));
  ASSERT_TRUE(line_segment.contains(Geometry::Vec3d(4.5, 8.0)));
  ASSERT_FALSE(line_segment.contains(Geometry::kOrigin));
  ASSERT_FALSE(line_segment.contains(Geometry::Vec3d(4, 7.0)));
  ASSERT_FALSE(line_segment.contains(Geometry::Vec3d(4, 10.0)));
}

TEST_F(LineSegmentTestSuite, distance_to) {
  ASSERT_NEAR(line_segment.distance_to(endpoint1), 0.0, kEPS);
  ASSERT_NEAR(line_segment.distance_to(endpoint2), 0.0, kEPS);
  ASSERT_NEAR(line_segment.distance_to(Geometry::Vec3d(4.5, 8.0)), 0.0, kEPS);

  ASSERT_NEAR(line_segment.distance_to(Geometry::kOrigin), 7.07106781, kEPS);
  ASSERT_NEAR(line_segment.distance_to(Geometry::Vec3d(3.0, 7.0)), 1.643989873,
              kEPS);
}

TEST_F(LineSegmentTestSuite, intersects) {
  Geometry::LineSegment line_segment1 = Geometry::LineSegment(
      Geometry::Vec3d(4.0, 6.0), Geometry::Vec3d(7.0, 11.0));
  ASSERT_TRUE(line_segment.intersects(line_segment1));

  Geometry::LineSegment line_segment2 = Geometry::LineSegment(
      Geometry::Vec3d(5.0, 8.0), Geometry::Vec3d(6.0, 2.0));
  ASSERT_FALSE(line_segment.intersects(line_segment2));
}
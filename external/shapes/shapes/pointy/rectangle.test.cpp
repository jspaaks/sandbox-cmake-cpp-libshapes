#include "gtest/gtest.h"
#include <shapes/pointy/rectangle.cpp>

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(RectangleTests, calcArea) {
    shapes::Rectangle rectangle(2.0, 3.0);
    double actual = rectangle.calcArea();
    double expected = 6.00;
    ASSERT_EQ(actual, expected);
}

TEST(RectangleTests, accessWidthMember) {
    shapes::Rectangle rectangle(1.23, 4.56);
    double actual = rectangle.width;
    double expected = 1.23;
    ASSERT_EQ(actual, expected);
}

TEST(RectangleTests, accessHeightMember) {
    shapes::Rectangle rectangle(1.23, 4.56);
    double actual = rectangle.height;
    double expected = 4.56;
    ASSERT_EQ(actual, expected);
}

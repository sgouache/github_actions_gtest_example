#include <gtest/gtest.h>
#include "github_actions_gtest_example.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(HelloTest, CallHello) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", githubActionsGtestExample::sayHello().c_str());
}

TEST(HelloTest, CallAdd) {
  // Expect addition to be correct.
  EXPECT_EQ(2, githubActionsGtestExample::add(1, 1));
}
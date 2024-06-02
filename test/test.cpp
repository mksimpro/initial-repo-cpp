#include <gtest/gtest.h>
#include "../StrongType.hpp"

namespace {
template <typename T>
using Meter = StrongType<T, struct MeterTag, Comparable, Addable>;
}

TEST(StrongTypeTests, SucceedAddMeters)
{
    const auto res = Meter<int>(10) + Meter<int>(20);
    EXPECT_EQ(Meter<int>(30).get(), res.get());
}

TEST(StrongTypeTests, SucceedAddAndCompareMeters)
{
    const auto res = Meter<int>(10) + Meter<int>(20);
    EXPECT_EQ(Meter<int>(30), res);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

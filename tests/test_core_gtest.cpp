#include <gtest/gtest.h>

#include "core.h"
#include <vector>

TEST(CoreTests, MinMax)
{
    const std::vector<int> a{ 5, -2, 10, 3 };
    const auto mm = CalcMinMax(a);
    EXPECT_EQ(mm.first, -2);
    EXPECT_EQ(mm.second, 10);
}

TEST(CoreTests, Average)
{
    const std::vector<int> a{ 2, 4, 6 };
    const double avg = CalcAverage(a);
    EXPECT_NEAR(avg, 4.0, 1e-9);
}

TEST(CoreTests, Replace)
{
    const std::vector<int> a{ 1, 9, 5, 9, 1 };
    const auto mm = CalcMinMax(a);
    const double avg = CalcAverage(a);
    const auto r = ReplaceMinMax(a, mm.first, mm.second, avg);
    EXPECT_EQ((r), (std::vector<int>{5, 5, 5, 5, 5}));
}

TEST(CoreTests, AllEqual)
{
    const std::vector<int> a{ 7, 7, 7 };
    const auto mm = CalcMinMax(a);
    const double avg = CalcAverage(a);
    const auto r = ReplaceMinMax(a, mm.first, mm.second, avg);
    EXPECT_EQ(r, a);
}

TEST(CoreTests, SingleElement)
{
    const std::vector<int> a{ 42 };
    const auto mm = CalcMinMax(a);
    const double avg = CalcAverage(a);
    const auto r = ReplaceMinMax(a, mm.first, mm.second, avg);
    EXPECT_EQ(r, a);
}

TEST(CoreTests, NegativeNumbers)
{
    const std::vector<int> a{ -5, 0, -1, -5 };
    const auto mm = CalcMinMax(a);
    EXPECT_EQ(mm.first, -5);
    EXPECT_EQ(mm.second, 0);

    const double avg = CalcAverage(a);
    EXPECT_NEAR(avg, -2.75, 1e-9);
}

TEST(CoreTests, EmptyArrayThrows_MinMax)
{
    const std::vector<int> a;
    EXPECT_THROW(CalcMinMax(a), std::invalid_argument);
}

TEST(CoreTests, EmptyArrayThrows_Average)
{
    const std::vector<int> a;
    EXPECT_THROW(CalcAverage(a), std::invalid_argument);
}
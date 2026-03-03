#include "core.h"
#include <cmath>
#include <iostream>
#include <vector>

static int g_failed = 0;

#define EXPECT_TRUE(cond) \
    do { \
        if (!(cond)) { \
            std::cout << "FAILED: " #cond \
                      << " at " << __FILE__ << ":" << __LINE__ << "\n"; \
            ++g_failed; \
        } \
    } while (0)

#define EXPECT_EQ(a,b) EXPECT_TRUE((a) == (b))
#define EXPECT_NEAR(a,b,eps) EXPECT_TRUE(std::fabs((a)-(b)) <= (eps))

static void TestMinMax() {
    const std::vector<int> a{ 5, -2, 10, 3 };
    const auto mm = CalcMinMax(a);
    EXPECT_EQ(mm.first, -2);
    EXPECT_EQ(mm.second, 10);
}

static void TestAverage() {
    const std::vector<int> a{ 2, 4, 6 };
    const double avg = CalcAverage(a);
    EXPECT_NEAR(avg, 4.0, 1e-9);
}

static void TestReplace() {
    const std::vector<int> a{ 1, 9, 5, 9, 1 };
    const auto mm = CalcMinMax(a);
    const double avg = CalcAverage(a);
    const auto r = ReplaceMinMax(a, mm.first, mm.second, avg);
    EXPECT_TRUE((r == std::vector<int>{5, 5, 5, 5, 5}));
}

static void TestAllEqual() {
    const std::vector<int> a{ 7, 7, 7 };
    const auto mm = CalcMinMax(a);
    const double avg = CalcAverage(a);
    const auto r = ReplaceMinMax(a, mm.first, mm.second, avg);
    EXPECT_TRUE((r == a));
}

static void TestSingleElement() {
    const std::vector<int> a{ 42 };
    const auto mm = CalcMinMax(a);
    const double avg = CalcAverage(a);
    const auto r = ReplaceMinMax(a, mm.first, mm.second, avg);
    EXPECT_TRUE((r == a));
}

static void TestNegativeNumbers() {
    const std::vector<int> a{ -5, 0, -1, -5 };
    const auto mm = CalcMinMax(a);
    EXPECT_EQ(mm.first, -5);
    EXPECT_EQ(mm.second, 0);

    const double avg = CalcAverage(a);
    EXPECT_NEAR(avg, -2.75, 1e-9);
}

int main() {
    TestMinMax();
    TestAverage();
    TestReplace();
    TestAllEqual();
    TestSingleElement();
    TestNegativeNumbers();

    if (g_failed == 0) {
        std::cout << "ALL TESTS PASSED\n";
        return 0;
    }
    std::cout << g_failed << " TEST(S) FAILED\n";
    return 1;
}
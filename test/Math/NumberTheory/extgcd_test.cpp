#include "../../../algorithm/Math/NumberTheory/extgcd.hpp"

#include <gtest/gtest.h>

#include <cmath>
#include <cstdint>
#include <limits>
#include <numeric>
#include <random>

class ExtgcdTest : public ::testing::Test {
protected:
    std::mt19937_64 rng;

    void SetUp() override {
        std::random_device seed;
        rng.seed(seed());
    }
};

TEST_F(ExtgcdTest, Positive) {
    using type = std::int32_t;
    auto min = std::numeric_limits<type>::min();
    auto max = std::numeric_limits<type>::max();
    std::uniform_int_distribution<type> dist(min, max);

    for(int i = 0; i < 100; ++i) {
        auto a = dist(rng);
        auto b = dist(rng);

        auto [x, y, g] = algorithm::extgcd(a, b);

        EXPECT_TRUE(g >= 0);
        EXPECT_EQ(std::gcd(a, b), g);

        EXPECT_TRUE(std::abs(x) <= std::abs(b) / g);
        EXPECT_TRUE(std::abs(y) <= std::abs(a) / g);
        EXPECT_EQ((std::int64_t)a * x + (std::int64_t)b * y, g);
    }
}

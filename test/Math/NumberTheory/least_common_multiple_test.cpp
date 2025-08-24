#include "../../../algorithm/Math/NumberTheory/least_common_multiple.hpp"

#include <gtest/gtest.h>

#include <cstdint>
#include <limits>
#include <numeric>
#include <random>
#include <type_traits>

class LcmTest : public ::testing::Test {
protected:
    std::mt19937_64 rng;

    void SetUp() override {
        std::random_device seed;
        rng.seed(seed());
    }
};

TEST_F(LcmTest, TwoArguments) {
    using type = std::int32_t;
    auto min = std::numeric_limits<type>::min();
    auto max = std::numeric_limits<type>::max();
    std::uniform_int_distribution<type> dist(min, max);

    for(int i = 0; i < 100; ++i) {
        auto a = dist(rng);
        auto b = dist(rng);

        auto expected = std::lcm(a, b);
        auto actual = algorithm::lcm(a, b);

        EXPECT_TRUE((std::is_same_v<std::int32_t, decltype(actual)>));
        EXPECT_TRUE((std::is_same_v<decltype(expected), decltype(actual)>));
        EXPECT_EQ(expected, actual);
    }
}

TEST_F(LcmTest, ThreeArguments) {
    using type_a = std::int32_t;
    auto min_a = std::numeric_limits<type_a>::min();
    auto max_a = std::numeric_limits<type_a>::max();
    std::uniform_int_distribution<type_a> dist_a(min_a, max_a);

    using type_b = std::uint32_t;
    auto min_b = std::numeric_limits<type_b>::min();
    auto max_b = std::numeric_limits<type_b>::max();
    std::uniform_int_distribution<type_b> dist_b(min_b, max_b);

    using type_c = std::int64_t;
    auto min_c = std::numeric_limits<type_c>::min();
    auto max_c = std::numeric_limits<type_c>::max();
    std::uniform_int_distribution<type_c> dist_c(min_c, max_c);

    for(int i = 0; i < 100; ++i) {
        auto a = dist_a(rng);
        auto b = dist_b(rng);
        auto c = dist_c(rng);

        auto expected = std::lcm(a, std::lcm(b, c));
        auto actual = algorithm::lcm(a, b, c);

        EXPECT_TRUE((std::is_same_v<std::int64_t, decltype(actual)>));
        EXPECT_TRUE((std::is_same_v<decltype(expected), decltype(actual)>));
        EXPECT_EQ(expected, actual);
    }
}

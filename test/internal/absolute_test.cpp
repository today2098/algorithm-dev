#include "../../algorithm/internal/absolute.hpp"

#include <gtest/gtest.h>

#include <cstdint>
#include <limits>
#include <tuple>
#include <vector>

TEST(AbsTest, CornerCase) {
    using type = std::int32_t;
    using res = std::int32_t;

    auto min = std::numeric_limits<type>::min();  // -2^31 = -2'147'483'648.
    EXPECT_EQ(min, algorithm::internal::abs<res>(min));
}

TEST(AbsTest, Unsigned) {
    using type = std::uint32_t;
    using res = std::uint64_t;

    using tuple = std::tuple<type, res>;  // tuple of (arg, expected).
    std::vector<tuple> table(
        {{10, 10}});

    for(const auto &[arg, expected] : table) {
        auto actual = algorithm::internal::abs<res>(arg);

        EXPECT_TRUE((std::is_same_v<res, decltype(actual)>));
        EXPECT_EQ(expected, actual);
    }
}

TEST(AbsTest, Signed) {
    using type = std::int32_t;
    using res = std::uint64_t;

    using tuple = std::tuple<type, res>;  // tuple of (arg, expected).
    std::vector<tuple> table(
        {{10, 10},
         {-10, 10},
         {std::numeric_limits<type>::min(), 1ULL << 31}});

    for(const auto &[arg, expected] : table) {
        auto actual = algorithm::internal::abs<res>(arg);

        EXPECT_TRUE((std::is_same_v<res, decltype(actual)>));
        EXPECT_EQ(expected, actual);
    }
}

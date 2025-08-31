#include "../../../algorithm/Math/ModularArithmetic/mod_inv.hpp"

#include <gtest/gtest.h>

#include <cstdint>
#include <numeric>
#include <random>

TEST(ModInvTest, Base) {
    std::random_device seed;
    std::mt19937_64 engine(seed());

    std::uniform_int_distribution<std::uint32_t> dist_mod(1);
    auto mod = dist_mod(engine);
    assert(mod >= 1);

    std::uniform_int_distribution<std::uint32_t> dist_a(0, mod - 1);
    auto a = dist_a(engine);
    assert(a < mod);

    auto [x, g] = algorithm::internal::mod_inv(a, mod);
    if(a == 0) {
        EXPECT_EQ(g, mod);
        EXPECT_EQ(x, 0);
    } else {
        EXPECT_EQ(g, std::gcd(a, mod));
        EXPECT_TRUE(x < mod / g);
        EXPECT_EQ((std::uint64_t)a * x % mod, g);
    }
}

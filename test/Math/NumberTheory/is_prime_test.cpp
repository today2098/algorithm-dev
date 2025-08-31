#include "../../../algorithm/Math/NumberTheory/is_prime.hpp"

#include <gtest/gtest.h>

#include <chrono>
#include <cstdint>
#include <future>

TEST(IsPrimeTest, Basic) {
    std::uint64_t n = 18'446'744'073'709'551'557ULL;  // the largest prime representable by std::uint64_t.
    auto fut = std::async(std::launch::async, [&] {
        return algorithm::is_prime(n);
    });

    auto status = fut.wait_for(std::chrono::seconds(15));
    ASSERT_NE(status, std::future_status::timeout);
    EXPECT_TRUE(fut.get());
}

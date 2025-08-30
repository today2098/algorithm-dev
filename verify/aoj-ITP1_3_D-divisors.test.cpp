#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D"

#include <algorithm>
#include <cstdint>
#include <iostream>

#include "../algorithm/Math/NumberTheory/divisors.hpp"

int main() {
    std::uint32_t a, b, c;
    std::cin >> a >> b >> c;

    auto divs = algorithm::divisors(c);
    auto ans = std::count_if(divs.cbegin(), divs.cend(), [&](std::uint32_t d) -> bool {
        return a <= d and d <= b;
    });

    std::cout << ans << std::endl;
}

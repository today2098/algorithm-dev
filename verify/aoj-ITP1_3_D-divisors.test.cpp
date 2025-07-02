#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D"

#include <algorithm>
#include <iostream>

#include "../algorithm/Math/NumberTheory/divisors.hpp"

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    const auto &&divs = algorithm::divisors(c);
    auto left = std::lower_bound(divs.cbegin(), divs.cend(), a);
    auto right = std::upper_bound(divs.cbegin(), divs.cend(), b);

    auto ans = right - left;
    std::cout << ans << std::endl;
}

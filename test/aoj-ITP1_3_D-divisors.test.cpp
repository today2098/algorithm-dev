#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D"

#include <algorithm>
#include <iostream>

#include "../lib/Math/NumberTheory/divisors.hpp"

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    const auto &&divs = algorithm::divisors(c);

    auto ans = std::upper_bound(divs.begin(), divs.end(), b) - std::lower_bound(divs.begin(), divs.end(), a);
    std::cout << ans << std::endl;
}

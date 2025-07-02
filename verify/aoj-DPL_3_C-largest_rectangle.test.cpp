#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/3/DPL_3_C"

#include <algorithm>
#include <iostream>
#include <vector>

#include "../algorithm/Others/largest_rectangle.hpp"

int main() {
    int n;
    std::cin >> n;

    std::vector<int> h(n);
    for(auto &in : h) std::cin >> in;

    auto &&ranges = algorithm::largest_rectangle(h);

    long long ans = 0;
    for(int i = 0; i < n; ++i) {
        const auto &[l, r] = ranges[i];
        long long tmp = (long long)h[i] * (r - l);
        ans = std::max(ans, tmp);
    }

    std::cout << ans << std::endl;
}

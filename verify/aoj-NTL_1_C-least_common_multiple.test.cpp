#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C"

#include <cstdint>
#include <iostream>

#include "../algorithm/Math/NumberTheory/least_common_multiple.hpp"

int main() {
    int n;
    std::cin >> n;

    uint32_t ans = 1;
    for(int i = 0; i < n; ++i) {
        uint32_t a;
        std::cin >> a;

        ans = algorithm::ilcm(ans, a);
    }

    std::cout << ans << std::endl;
}

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B"

#include <iostream>
#include <vector>

#include "../lib/Others/binary_search.hpp"

int main() {
    int n;
    std::cin >> n;

    std::vector<int> s(n);
    for(auto &elem : s) std::cin >> elem;

    int q;
    std::cin >> q;

    int ans = 0;
    while(q--) {
        int t;
        std::cin >> t;

        auto l = algorithm::bisearch(-1, n, [&](int idx) -> bool {
            return s[idx] < t;
        });
        auto r = algorithm::bisearch(-1, n, [&](int idx) -> bool {
            return s[idx] <= t;
        });

        if(r - l > 0) ans++;
    }

    std::cout << ans << std::endl;
}

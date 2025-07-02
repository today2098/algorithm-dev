#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B"

#include <iostream>
#include <vector>

#include "../algorithm/Others/binary_search.hpp"

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

        auto itr = algorithm::bisearch(0, n, [&](int i) -> bool {
            return s[i] < t;
        });

        if(itr < n and s[itr] == t) ++ans;
    }

    std::cout << ans << std::endl;
}

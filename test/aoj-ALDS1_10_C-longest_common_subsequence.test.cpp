#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/10/ALDS1_10_C"

#include <iostream>
#include <string>

#include "../lib/String/longest_common_subsequence.hpp"

int main() {
    int q;
    std::cin >> q;

    while(q--) {
        std::string x, y;
        std::cin >> x >> y;

        auto ans = algorithm::lcs(x, y).size();
        std::cout << ans << "\n";
    }
}

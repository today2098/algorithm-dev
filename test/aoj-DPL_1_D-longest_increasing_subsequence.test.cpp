#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_D"

#include <iostream>
#include <vector>

#include "../lib/Others/longest_increasing_subsequence.hpp"

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(auto &in : a) std::cin >> in;

    auto ans = algorithm::lis2(a).back();
    std::cout << ans << std::endl;
}

#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"

#include <algorithm>
#include <iostream>
#include <vector>

#include "../algorithm/Others/longest_increasing_subsequence.hpp"

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(auto &in : a) std::cin >> in;

    auto &&dp = algorithm::lis(a);
    auto itr = std::max_element(dp.begin(), dp.end()) - dp.begin();

    std::vector<int> ans;
    ans.push_back(itr);
    for(int i = itr - 1; i >= 0; --i) {
        if(dp[i] == dp[ans.back()] - 1) ans.push_back(i);
    }
    std::reverse(ans.begin(), ans.end());

    std::cout << ans.size() << "\n";
    for(auto elem : ans) std::cout << elem << " ";
    std::cout << std::endl;
}

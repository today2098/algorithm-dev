#ifndef ALGORITHM_LONGEST_INCREASING_SUBSEQUENCE_HPP
#define ALGORITHM_LONGEST_INCREASING_SUBSEQUENCE_HPP 1

/**
 * @brief Longest Increasing Subsequence（最長増加部分列）
 * @docs docs/Others/longest_increasing_subsequence.md
 */

#include <algorithm>
#include <functional>
#include <vector>

namespace algorithm {

// 最長増加部分列 (LIS: Longest Increasing Subsequence) の長さを求める．O(N*logN).
template <typename Type, class Compare = std::function<bool(const Type &, const Type &)> >
std::vector<int> lis(const std::vector<Type> &v, Compare comp = [](const Type &a, const Type &b) -> bool { return a < b; }) {
    const int n = v.size();
    std::vector<int> res(n, 0);  // res[i]:=(v[i]を最後の要素とする最長増加部分列の長さ).
    std::vector<Type> dp;        // dp[k]:=(長さkの増加部分列のうち，その最後の要素の最小値).
    for(int i = 0; i < n; ++i) {
        auto itr = std::lower_bound(dp.begin(), dp.end(), v[i], comp);
        res[i] = itr - dp.begin() + 1;
        if(itr == dp.end()) dp.push_back(v[i]);
        else *itr = v[i];
    }
    return res;
}

// 最長増加部分列 (LIS: Longest Increasing Subsequence) の長さを求める．O(N*logN).
template <typename Type, class Compare = std::function<bool(const Type &, const Type &)> >
std::vector<int> lis2(const std::vector<Type> &v, Compare comp = [](const Type &a, const Type &b) -> bool { return a < b; }) {
    const int n = v.size();
    std::vector<int> res(n + 1, 0);  // res[i]:=(v[:i]における最長増加部分列の長さ).
    std::vector<Type> dp;            // dp[k]:=(長さkの増加部分列のうち，その最後の要素の最小値).
    for(int i = 0; i < n; ++i) {
        auto itr = std::lower_bound(dp.begin(), dp.end(), v[i], comp);
        if(itr == dp.end()) dp.push_back(v[i]);
        else *itr = v[i];
        res[i + 1] = dp.size();
    }
    return res;
}

}  // namespace algorithm

#endif

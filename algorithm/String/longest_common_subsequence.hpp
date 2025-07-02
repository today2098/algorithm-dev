#ifndef ALGORITHM_LONGEST_COMMON_SUBSEQUENCE_HPP
#define ALGORITHM_LONGEST_COMMON_SUBSEQUENCE_HPP 1

/**
 * @brief Longest Common Subsequence（最長共通部分列）
 * @docs docs/String/longest_common_subsequence.md
 */

#include <algorithm>
#include <vector>

namespace algorithm {

// 2つの配列に対して，最長共通部分列 (LCS: Longest Common Subsequence) を求める．
// 引数はSTLのシーケンスコンテナであること．O(|S|*|T|).
template <class Sequence>
Sequence lcs(const Sequence &s, const Sequence &t) {
    const int n = s.size(), m = t.size();
    // dp[i][j]:=(s[:i]とt[:j]のLCSの長さ).
    std::vector<std::vector<int> > dp(n + 1, std::vector<int>(m + 1, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            dp[i + 1][j + 1] = (s[i] == t[j] ? dp[i][j] + 1 : std::max(dp[i][j + 1], dp[i + 1][j]));
        }
    }
    Sequence sub(dp[n][m], 0);  // sub[]:=(配列s, tのLCS).
    int i = n - 1, j = m - 1, k = dp[n][m] - 1;
    while(k >= 0) {
        if(s[i] == t[j]) {
            sub[k] = s[i];
            i--, j--, k--;
        } else if(dp[i + 1][j + 1] == dp[i][j + 1]) {
            i--;
        } else {
            j--;
        }
    }
    return sub;
}

}  // namespace algorithm

#endif

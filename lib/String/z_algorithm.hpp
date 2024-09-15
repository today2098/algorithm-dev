#ifndef ALGORITHM_Z_ALGORITHM_HPP
#define ALGORITHM_Z_ALGORITHM_HPP 1

/**
 * @brief Z algorithm（最長共通接頭辞）
 * @docs docs/String/z_algorithm.md
 */

#include <vector>

namespace algorithm {

// 最長共通接頭辞 (LCP: Longest Common Prefix) の長さを求める．
// 引数はSTLのシーケンスコンテナであること．O(|S|).
template <class Sequence>
std::vector<int> z_algorithm(const Sequence &s) {
    const int n = s.size();
    std::vector<int> z(n + 1, 0);  // z[i]:=(sとs[i:]のLCPの長さ).
    z[0] = n;
    int i = 1, j = 0;
    while(i < n) {
        while(i + j < n and s[j] == s[i + j]) j++;
        z[i] = j;
        if(j == 0) {
            i++;
            continue;
        }
        int k = 1;
        while(i + k < n and k + z[k] < j) {
            z[i + k] = z[k];
            k++;
        }
        i += k, j -= k;
    }
    return z;
}

}  // namespace algorithm

#endif

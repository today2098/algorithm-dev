#ifndef ALGORITHM_COMPRESS_HPP
#define ALGORITHM_COMPRESS_HPP 1

/**
 * @brief 座標圧縮
 * @docs docs/Others/compress.md
 */

#include <algorithm>
#include <vector>

namespace algorithm {

// 座標圧縮．O(N*logN).
template <typename Type>
std::vector<Type> compress(std::vector<Type> &v) {
    std::vector<Type> key = v;
    std::sort(key.begin(), key.end());
    key.erase(std::unique(key.begin(), key.end()), key.end());
    for(auto &elem : v) elem = std::lower_bound(key.begin(), key.end(), elem) - key.begin();
    return key;
}

}  // namespace algorithm

#endif

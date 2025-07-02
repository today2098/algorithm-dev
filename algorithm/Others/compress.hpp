#ifndef ALGORITHM_COMPRESS_HPP
#define ALGORITHM_COMPRESS_HPP 1

#include <algorithm>
#include <vector>

namespace algorithm {

// 座標圧縮．O(N log N).
template <typename Type>
std::vector<Type> compress(std::vector<Type> &v) {
    std::vector<Type> key(v);
    std::sort(key.begin(), key.end());
    key.erase(std::unique(key.begin(), key.end()), key.end());
    key.shrink_to_fit();
    for(auto &elem : v) elem = std::lower_bound(key.cbegin(), key.cend(), elem) - key.cbegin();
    return key;
}

}  // namespace algorithm

#endif

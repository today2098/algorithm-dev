#ifndef ALGORITHM_COMPRESS_HPP
#define ALGORITHM_COMPRESS_HPP 1

#include <algorithm>
#include <ranges>
#include <vector>

namespace algorithm {

// 座標圧縮．O(N*logN).
template <std::ranges::random_access_range R>
auto compress(R &&r) {
    std::vector key(std::ranges::cbegin(r), std::ranges::cend(r));
    std::sort(key.begin(), key.end());
    key.erase(std::unique(key.begin(), key.end()), key.end());
    key.shrink_to_fit();
    for(auto &elem : r) elem = std::lower_bound(key.cbegin(), key.cend(), elem) - key.begin();
    return key;
}

}  // namespace algorithm

#endif

#ifndef ALGORITHM_GRID_HPP
#define ALGORITHM_GRID_HPP 1

/**
 * @brief グリッド問題に関するユーティリティライブラリ
 * @docs docs/Utils/grid.md
 */

#include <cassert>
#include <utility>
#include <vector>

namespace algorithm {

constexpr std::pair<int, int> dydx4[] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
constexpr std::pair<int, int> dydx8[] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

auto is_inner = [](int h, int w, int y, int x) -> bool {
    return (0 <= y and y < h and 0 <= x and x < w);
};

}  // namespace algorithm

#endif

#ifndef ALGORITHM_GRID_HPP
#define ALGORITHM_GRID_HPP 1

#include <utility>
#include <vector>

namespace algorithm {

namespace grid {

constexpr std::pair<int, int> dydx4[] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
constexpr std::pair<int, int> dydx8[] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

auto is_inner = [](int h, int w, int y, int x) -> bool {
    return (0 <= y and y < h and 0 <= x and x < w);
};

// 2次元配列を反時計回りに90度回転させる．
template <class Sequence>
std::vector<Sequence> rotate90(const std::vector<Sequence> &vv) {
    if(vv.empty()) return std::vector<Sequence>();
    const int h = vv.size(), w = vv[0].size();
    std::vector<Sequence> res(w, Sequence(h, 0));
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) res[w - 1 - j][i] = vv[i][j];
    }
    return res;
}

// 2次元配列を180度回転させる．
template <class Sequence>
std::vector<Sequence> rotate180(const std::vector<Sequence> &vv) {
    if(vv.empty()) return std::vector<Sequence>();
    const int h = vv.size(), w = vv[0].size();
    std::vector<Sequence> res(h, Sequence(w, 0));
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) res[h - 1 - i][w - 1 - j] = vv[i][j];
    }
    return res;
}

// 2次元配列を反時計回りに270度（時計回りに90度）回転させる．
template <class Sequence>
std::vector<Sequence> rotate270(const std::vector<Sequence> &vv) {
    if(vv.empty()) return std::vector<Sequence>();
    const int h = vv.size(), w = vv[0].size();
    std::vector<Sequence> res(w, Sequence(h, 0));
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) res[j][h - 1 - i] = vv[i][j];
    }
    return res;
}

}  // namespace grid

}  // namespace algorithm

#endif

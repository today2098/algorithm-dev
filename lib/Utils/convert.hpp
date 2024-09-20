#ifndef ALGORITHM_CONVERT_HPP
#define ALGORITHM_CONVERT_HPP 1

/**
 * @brief 値の変換
 * @docs docs/Utils/convert.md
 */

#include <cassert>
#include <vector>

namespace algorithm {

template <typename Type>
bool chmin(Type &a, const Type &b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

template <typename Type>
bool chmax(Type &a, const Type &b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

// 2次元配列を反時計回りに90度回転させる．
template <class Sequence>
std::vector<Sequence> rotate90(const std::vector<Sequence> &vv) {
    const int h = vv.size();
    if(h == 0) return std::vector<Sequence>();
    const int w = vv[0].size();
    std::vector<Sequence> res(w, Sequence(h, 0));
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) res[w - 1 - j][i] = vv[i][j];
    }
    return res;
}

// 2次元配列を180度回転させる．
template <class Sequence>
std::vector<Sequence> rotate180(const std::vector<Sequence> &vv) {
    const int h = vv.size();
    if(h == 0) return std::vector<Sequence>();
    const int w = vv[0].size();
    std::vector<Sequence> res(h, Sequence(w, 0));
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) res[h - 1 - i][w - 1 - j] = vv[i][j];
    }
    return res;
}

// 2次元配列を反時計回りに270度（時計回りに90度）回転させる．
template <class Sequence>
std::vector<Sequence> rotate270(const std::vector<Sequence> &vv) {
    const int h = vv.size();
    if(h == 0) return std::vector<Sequence>();
    const int w = vv[0].size();
    std::vector<Sequence> res(w, Sequence(h, 0));
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) res[j][h - 1 - i] = vv[i][j];
    }
    return res;
}

}  // namespace algorithm

#endif

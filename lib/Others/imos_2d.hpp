#ifndef ALGORITHM_IMOS_2D_HPP
#define ALGORITHM_IMOS_2D_HPP 1

/**
 * @brief 二次元いもす法
 * @docs docs/Others/imos_2d.md
 */

#include <algorithm>
#include <cassert>
#include <vector>

namespace algorithm {

// 二次元いもす法．
template <typename T>
class Imos2D {
    int m_h, m_w;
    std::vector<std::vector<T> > m_dat;  // 0-based index.

public:
    Imos2D() : Imos2D(0, 0) {}
    explicit Imos2D(size_t h, size_t w) : m_h(h), m_w(w), m_dat(h + 1, std::vector<T>(w + 1, 0)) {}

    int height() const { return m_h; }
    int width() const { return m_w; }
    void add(int ly, int lx, int ry, int rx, T a) {
        assert(0 <= ly and ly <= ry and ry <= height());
        assert(0 <= lx and lx <= rx and rx <= width());
        m_dat[ly][lx] += a;
        m_dat[ly][rx] -= a;
        m_dat[ry][lx] -= a;
        m_dat[ry][rx] += a;
    }
    void build() {
        for(int i = 0; i < height(); ++i) {
            for(int j = 0; j < width(); ++j) m_dat[i][j + 1] += m_dat[i][j];
        }
        for(int i = 0; i < height(); ++i) {
            for(int j = 0; j < width(); ++j) m_dat[i + 1][j] += m_dat[i][j];
        }
    }
    T get(int y, int x) const {
        assert(0 <= y and y < height());
        assert(0 <= x and x < width());
        return m_dat[y][x];
    }
    void reset() {
        for(std::vector<T> &v : m_dat) std::fill(v.begin(), v.end(), 0);
    }
};

}  // namespace algorithm

#endif

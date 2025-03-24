#ifndef ALGORITHM_BINARY_INDEXED_TREE_2D_HPP
#define ALGORITHM_BINARY_INDEXED_TREE_2D_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>

namespace algorithm {

// 二次元BIT．
template <typename T>
class BIT2D {
public:
    using value_type = T;

private:
    int m_h, m_w;
    std::vector<std::vector<value_type>> m_tree;

    static constexpr int lsb(int bit) { return bit & -bit; }
    void build() {
        for(int i = 1, h = height(); i <= h; ++i) {
            int ni = i + lsb(i);
            for(int j = 1, w = width(); j <= w; ++j) {
                int nj = j + lsb(j);
                if(ni <= h) m_tree[ni - 1][j - 1] += m_tree[i - 1][j - 1];
                if(nj <= w) {
                    m_tree[i - 1][nj - 1] += m_tree[i - 1][j - 1];
                    if(ni <= h) m_tree[ni - 1][nj - 1] -= m_tree[i - 1][j - 1];
                }
            }
        }
    }

public:
    // constructor. O(H*W).
    BIT2D() : BIT2D(0, 0) {}
    explicit BIT2D(int h, int w) : BIT2D(h, w, value_type()) {}
    explicit BIT2D(int h, int w, const value_type &a) : m_h(h), m_w(w), m_tree(h, std::vector<value_type>(w, a)) {
        assert(h >= 0 and w >= 0);
        if(a != value_type()) build();
    }

    int height() const { return m_h; }
    int width() const { return m_w; }
    // (y,x)にある要素にaを加算する．O((logH)*logW).
    void add(int y, int x, const value_type &a) {
        assert(0 <= y and y < height());
        assert(0 <= x and x < width());
        for(int i = y + 1, h = height(); i <= h; i += lsb(i)) {
            for(int j = x + 1, w = width(); j <= w; j += lsb(j)) m_tree[i - 1][j - 1] += a;
        }
    }
    // [0,y)かつ[0,x)の範囲にある要素の総和を求める．O((logH)*logW).
    value_type sum(int y, int x) const {
        assert(0 <= y and y <= height());
        assert(0 <= x and x <= width());
        value_type res = 0;
        for(int i = y; i >= 1; i -= lsb(i)) {
            for(int j = x; j >= 1; j -= lsb(j)) res += m_tree[i - 1][j - 1];
        }
        return res;
    }
    // [y,yy)かつ[x,xx)の範囲にある要素の総和を求める．O((logH)*logW).
    value_type sum(int y, int x, int yy, int xx) const {
        assert(0 <= y and y <= yy and yy <= height());
        assert(0 <= x and x <= xx and xx <= width());
        return sum(yy, xx) - sum(yy, x) - sum(y, xx) + sum(y, x);
    }
    void reset() {
        for(auto &v : m_tree) std::fill(v.begin(), v.end(), value_type());
    }
};

}  // namespace algorithm

#endif

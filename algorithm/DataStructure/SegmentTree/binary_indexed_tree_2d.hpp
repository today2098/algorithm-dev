#ifndef ALGORITHM_BINARY_INDEXED_TREE_2D_HPP
#define ALGORITHM_BINARY_INDEXED_TREE_2D_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>

#include "../../Math/Algebra/algebra.hpp"

namespace algorithm {

template <class AbelianGroup>
class BIT2D {
public:
    using group_type = AbelianGroup;
    using value_type = typename group_type::value_type;

private:
    int m_h, m_w;
    std::vector<std::vector<group_type>> m_tree;

    static constexpr int lsb(int bit) { return bit & -bit; }
    group_type sum_internal(int y, int x) const {
        group_type &&res = group_type::one();
        for(int i = y; i >= 1; i -= lsb(i)) {
            for(int j = x; j >= 1; j -= lsb(j)) res = res * m_tree[i - 1][j - 1];
        }
        return res;
    }
    void build() {
        for(int i = 1; i <= m_h; ++i) {
            int ni = i + lsb(i);
            for(int j = 1; j <= m_w; ++j) {
                int nj = j + lsb(j);
                if(ni <= m_h) m_tree[ni - 1][j - 1] = m_tree[ni - 1][j - 1] * m_tree[i - 1][j - 1];
                if(nj <= m_w) {
                    m_tree[i - 1][nj - 1] = m_tree[i - 1][nj - 1] * m_tree[i - 1][j - 1];
                    if(ni <= m_h) m_tree[ni - 1][nj - 1] = m_tree[ni - 1][nj - 1] * m_tree[i - 1][j - 1].inv();
                }
            }
        }
    }

public:
    // constructor. O(H*W).
    BIT2D() : BIT2D(0, 0) {}
    explicit BIT2D(int h, int w) : m_h(h), m_w(w), m_tree(h, std::vector<group_type>(w, group_type::one())) {
        assert(h >= 0 and w >= 0);
    }
    explicit BIT2D(int h, int w, const value_type &a) : BIT2D(h, w, group_type(a)) {}
    explicit BIT2D(int h, int w, const group_type &a) : m_h(h), m_w(w), m_tree(h, std::vector<group_type>(w, a)) {
        assert(h >= 0 and w >= 0);
        build();
    }

    int height() const { return m_h; }
    int width() const { return m_w; }
    // (y,x)にある要素をaとの積の結果に置き換える．O((log H)*log W).
    void add(int y, int x, const value_type &a) { add(y, x, group_type(a)); }
    void add(int y, int x, const group_type &a) {
        assert(0 <= y and y < height());
        assert(0 <= x and x < width());
        for(int i = y + 1; i <= m_h; i += lsb(i)) {
            for(int j = x + 1; j <= m_w; j += lsb(j)) m_tree[i - 1][j - 1] = m_tree[i - 1][j - 1] * a;
        }
    }
    // [0,y)かつ[0,x)の範囲にある要素の総積を求める．O((log H)*log W).
    value_type sum(int y, int x) const {
        assert(0 <= y and y <= height());
        assert(0 <= x and x <= width());
        return sum_internal(y, x).value();
    }
    // [y,yy)かつ[x,xx)の範囲にある要素の総積を求める．O((log H)*log W).
    value_type sum(int y, int x, int yy, int xx) const {
        assert(0 <= y and y <= yy and yy <= height());
        assert(0 <= x and x <= xx and xx <= width());
        return (sum_internal(yy, xx) * sum_internal(yy, x).inv() * sum_internal(y, xx).inv() * sum_internal(y, x)).value();
    }
    // 全要素の総積を求める．O((log H)*log W).
    value_type sum_all() const { return sum_internal(m_h, m_w).value(); }
    void reset() {
        for(auto &v : m_tree) std::fill(v.begin(), v.end(), group_type::one());
    }
};

namespace binary_indexed_tree_2d {

template <typename S>
using range_sum_binary_indexed_tree_2d = BIT2D<algebra::group::addition<S>>;

}  // namespace binary_indexed_tree_2d

}  // namespace algorithm

#endif

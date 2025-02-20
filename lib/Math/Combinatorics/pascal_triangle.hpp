#ifndef ALGORITHM_PASCAL_TRIANGLE_HPP
#define ALGORITHM_PASCAL_TRIANGLE_HPP 1

#include <cassert>
#include <vector>

namespace algorithm {

template <typename T = long long>
class PascalTriangle {
    static std::vector<std::vector<T> > s_c;  // s_c[n][k]:=(C(n,n-k) and C(n,k)).

    PascalTriangle() = default;
    ~PascalTriangle() = default;

public:
    // 組合せ．
    static T nCk(int n, int k) {
        assert(n >= 0);
        assert(k >= 0);
        if(k > n) return 0;
        resize(n + 1);
        return (n - k < k ? s_c[n][n - k] : s_c[n][k]);
    }
    // 重複組合せ．
    static T nHk(int n, int k) {
        assert(n >= 1);
        assert(k >= 0);
        return nCk(k + n - 1, k);
    }
    static void resize(int sz) {
        const int now = s_c.size();
        s_c.resize(sz);
        for(int n = now; n < sz; ++n) {
            const int len = (n + 2) / 2;
            s_c[n].resize(len);
            s_c[n][0] = 1;
            for(int k = 1; k < len; ++k) s_c[n][k] = s_c[n - 1][k - 1] + (n - 1 - k < k ? s_c[n - 1][n - 1 - k] : s_c[n - 1][k]);
        }
    }
    static void clear() { s_c.clear(); }
};

template <typename T>
std::vector<std::vector<T> > PascalTriangle<T>::s_c;

}  // namespace algorithm

#endif

#ifndef ALGORITHM_DIVISORS_HPP
#define ALGORITHM_DIVISORS_HPP 1

#include <algorithm>
#include <cassert>
#include <concepts>
#include <map>
#include <vector>

namespace algorithm {

// 約数列挙．O(√N).
template <std::integral Type>
std::vector<Type> divisors(Type n) {
    assert(n >= 1);
    std::vector<Type> res;  // res[]:=(自然数nの約数のリスト).
    for(unsigned long long p = 1, m = n; p * p <= m; ++p) {
        if(m % p == 0) {
            res.push_back(p);
            auto q = m / p;
            if(q != p) res.push_back(q);
        }
    }
    res.shrink_to_fit();
    std::sort(res.begin(), res.end());
    return res;
}

// 高速約数列挙．
template <std::integral Type>
std::vector<Type> divisors(const std::map<Type, int> &pf) {
    std::vector<Type> res({1});
    for(const auto &[p, cnt] : pf) {
        assert(p >= 1 and cnt >= 0);
        const int sz = res.size();
        Type b = 1;
        for(int i = 0; i < cnt; ++i) {
            b *= p;
            for(int j = 0; j < sz; ++j) res.push_back(res[j] * b);
        }
    }
    res.shrink_to_fit();
    std::sort(res.begin(), res.end());
    return res;
}

}  // namespace algorithm

#endif

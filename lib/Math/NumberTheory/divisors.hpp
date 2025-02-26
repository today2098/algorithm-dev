#ifndef ALGORITHM_DIVISORS_HPP
#define ALGORITHM_DIVISORS_HPP 1

#include <algorithm>
#include <cassert>
#include <map>
#include <vector>

namespace algorithm {

// 約数列挙．O(√N).
template <typename Type>
std::vector<Type> divisors(Type n) {
    assert(n >= 1);
    std::vector<Type> res;  // res[]:=(自然数nの約数の集合).
    for(Type p = 1; p * p <= n; ++p) {
        if(n % p == 0) {
            res.push_back(p);
            Type q = n / p;
            if(q != p) res.push_back(q);
        }
    }
    std::sort(res.begin(), res.end());
    return res;
}

// 高速約数列挙．
template <typename Type>
std::vector<Type> divisors(const std::map<Type, int> &pf) {
    std::vector<Type> res({1});
    for(const auto &[p, cnt] : pf) {
        const int sz = res.size();
        Type b = 1;
        for(int i = 0; i < cnt; ++i) {
            b *= p;
            for(int j = 0; j < sz; ++j) res.push_back(res[j] * b);
        }
    }
    std::sort(res.begin(), res.end());
    return res;
}

}  // namespace algorithm

#endif

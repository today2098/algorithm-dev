#ifndef ALGORITHM_MY_TEMPLATE_HPP
#define ALGORITHM_MY_TEMPLATE_HPP 1

#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, l, r) for(int i = (int)(l); i < (int)(r); ++i)
#define RREP(i, n) for(int i = (int)(n); i-- > 0;)
#define RFOR(i, r, l) for(int i = (int)(r); i-- > (int)(l);)
#define ALL(v) std::begin(v), std::end(v)
using llong = long long;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int, int>;
using namespace std;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr double EPS = 1e-10;
constexpr int MOD = 998'244'353;
constexpr int MOD2 = 1e9 + 7;

template <typename Type>
inline std::istream &operator>>(std::istream &is, std::vector<Type> &v) {
    for(auto &elem : v) is >> elem;
    return is;
}

template <typename Type>
inline std::ostream &operator<<(std::ostream &os, const std::vector<Type> &v) {
    for(auto iter = v.cbegin(); iter != v.cend(); ++iter) os << (iter == v.cbegin() ? "" : " ") << *iter;
    return os;
}

#endif

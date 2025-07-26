#ifndef ALGORITHM_MY_TEMPLATE_HPP
#define ALGORITHM_MY_TEMPLATE_HPP 1

#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define RREP(i, n) for(int i = (int)(n); i-- > 0;)
#define FOR(i, l, r) for(int i = (int)(l); i < (int)(r); ++i)
#define RFOR(i, l, r) for(int i = (int)(r); i-- > (int)(l);)
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

template <typename C, typename Tr, typename R, typename T = std::ranges::range_value_t<R>>
    requires std::ranges::output_range<R, T>
inline auto &operator>>(std::basic_istream<C, Tr> &is, R &r) {
    for(auto &elem : r) is >> elem;
    return is;
}

template <typename C, typename Tr, std::ranges::input_range R>
    requires(!std::convertible_to<R, const char *>)
inline auto &operator<<(std::basic_ostream<C, Tr> &os, const R &r) {
    if(std::ranges::empty(r)) return os;
    auto iter = std::ranges::cbegin(r);
    const auto end = std::ranges::cend(r);
    os << *iter++;
    while(iter != end) os << " " << *iter++;
    return os;
}

#endif

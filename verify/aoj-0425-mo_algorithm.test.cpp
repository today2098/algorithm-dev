#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/sources/PCK/Final/0425"

#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

#include "../algorithm/Others/mo_algorithm.hpp"

int main() {
    int n;
    int k;
    int q;
    std::cin >> n >> k >> q;

    std::vector<std::pair<int, int> > vp(k);
    for(auto &[a, b] : vp) {
        std::cin >> a >> b;
        a--, b--;
    }

    std::vector<std::pair<int, int> > queries(q);
    algorithm::Mo mo(k, q);
    for(int i = 0; i < q; ++i) {
        int type;
        int s, t;
        int x;
        std::cin >> type >> s >> t >> x;
        s--, x--;

        queries[i] = std::pair<int, int>(type, x);
        mo.insert(s, t);
    }

    std::vector<int> ans(q);
    std::vector<int> alpha(n), inv(n);
    std::iota(alpha.begin(), alpha.end(), 0);
    std::iota(inv.begin(), inv.end(), 0);
    auto swap_l = [&](int itr) -> void {
        const auto &[a, b] = vp[itr];
        std::swap(alpha[inv[a]], alpha[inv[b]]);
        std::swap(inv[a], inv[b]);
    };
    auto swap_r = [&](int itr) -> void {
        const auto &[a, b] = vp[itr];
        std::swap(inv[alpha[a]], inv[alpha[b]]);
        std::swap(alpha[a], alpha[b]);
    };
    auto solve = [&](int idx) -> void {
        const auto &[type, x] = queries[idx];
        ans[idx] = (type == 1 ? alpha[x] + 1 : inv[x] + 1);
    };
    mo.execute(swap_l, swap_l, swap_r, swap_r, solve);

    for(auto elem : ans) std::cout << elem << "\n";
}

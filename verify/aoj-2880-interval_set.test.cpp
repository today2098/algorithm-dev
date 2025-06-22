#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2880"

#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

#include "../lib/Others/interval_set.hpp"

int main() {
    int n;
    int m;
    int q;
    std::cin >> n >> m >> q;

    std::vector<std::tuple<int, int, int>> vt(m);
    for(auto &[d, a, b] : vt) std::cin >> d >> a >> b;
    std::sort(vt.begin(), vt.end());

    std::vector<std::tuple<int, int, int, int>> query(q);
    for(int i = 0; i < q; ++i) {
        auto &[e, s, t, idx] = query[i];
        std::cin >> e >> s >> t;
        idx = i;
    }
    std::sort(query.begin(), query.end());

    std::vector<bool> ans(q);
    algorithm::interval_set::IntervalSet<int> st;
    int next = 0;
    for(const auto &[e, s, t, idx] : query) {
        while(next < m) {
            const auto &[d, a, b] = vt[next];
            if(e <= d) break;
            st.insert(a, b);
            ++next;
        }

        ans[idx] = (s >= t or st.contains(s, t) == 2);
    }

    for(auto elem : ans) std::cout << (elem ? "Yes" : "No") << "\n";
}

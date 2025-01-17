#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2880"

#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

#include "../lib/Others/interval_set.hpp"
#include "../lib/Utils/debug.hpp"

int main() {
    int n;
    int m;
    int q;
    std::cin >> n >> m >> q;

    std::vector<std::tuple<int, int, int> > vt(m);
    for(auto &[d, a, b] : vt) std::cin >> d >> a >> b;
    std::sort(vt.begin(), vt.end());
    debug(vt);

    std::vector<std::tuple<int, int, int, int> > query(q);
    for(int i = 0; i < q; ++i) {
        auto &[e, s, t, idx] = query[i];
        std::cin >> e >> s >> t;
        idx = i;
    }
    std::sort(query.begin(), query.end());
    debug(query);

    std::vector<bool> ans(q);
    algorithm::IntervalSet<int> st;
    int i = 0;
    for(const auto &[e, s, t, idx] : query) {
        while(i < m) {
            const auto &[d, a, b] = vt[i];
            if(e <= d) break;
            st.insert(a, b);
            debug(d, a, b, st);
            i++;
        }

        ans[idx] = (s >= t or st.contains(s, t) == 2);
        debug(e, s, t, st, idx, ans[idx]);
    }

    for(auto elem : ans) std::cout << (elem ? "Yes" : "No") << "\n";
}

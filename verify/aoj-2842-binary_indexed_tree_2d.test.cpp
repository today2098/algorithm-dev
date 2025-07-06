#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2842"

#include <iostream>
#include <queue>
#include <tuple>

#include "../algorithm/DataStructure/SegmentTree/binary_indexed_tree_2d.hpp"

int main() {
    int y, x;
    int t;
    int q;
    std::cin >> y >> x >> t >> q;

    algorithm::binary_indexed_tree_2d::range_sum_binary_indexed_tree_2d<int> raw(y, x), baked(y, x);
    std::queue<std::tuple<int, int, int>> que;
    while(q--) {
        int time;
        int c;
        std::cin >> time >> c;

        while(!que.empty()) {
            auto [end, y, x] = que.front();
            if(time < end) break;
            que.pop();

            raw.add(y, x, -1);
            baked.add(y, x, 1);
        }

        if(c == 0) {
            int y, x;
            std::cin >> y >> x;
            y--, x--;

            raw.add(y, x, 1);
            que.emplace(time + t, y, x);
        } else if(c == 1) {
            int y, x;
            std::cin >> y >> x;
            y--, x--;

            if(baked.sum(y, x, y + 1, x + 1) >= 1) baked.add(y, x, -1);
        } else {
            int y, x, yy, xx;
            std::cin >> y >> x >> yy >> xx;
            y--, x--;

            auto &&a = baked.sum(y, x, yy, xx);
            auto &&b = raw.sum(y, x, yy, xx);
            std::cout << a << " " << b << "\n";
        }
    }
}

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include <iostream>

#include "../algorithm/DataStructure/SegmentTree/binary_indexed_tree.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    algorithm::RangeSumBIT<int> bit(n);

    while(q--) {
        int com;
        std::cin >> com;

        if(com == 0) {
            int x;
            int y;
            std::cin >> x >> y;
            --x;

            bit.add(x, y);
        } else {
            int x, y;
            std::cin >> x >> y;
            --x;

            auto ans = bit.sum(x, y);
            std::cout << ans << "\n";
        }
    }
}

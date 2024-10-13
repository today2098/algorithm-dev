#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include <iostream>

#include "../lib/DataStructure/Others/binary_trie.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    algorithm::BinaryTrie<20> trie;
    while(q--) {
        int com;
        std::cin >> com;

        if(com == 0) {
            int x;
            int y;
            std::cin >> x >> y;

            trie.insert(x, y);
        } else {
            int x, y;
            std::cin >> x >> y;

            auto ans = trie.upper_bound(y) - trie.lower_bound(x);
            std::cout << ans << "\n";
        }
    }
}
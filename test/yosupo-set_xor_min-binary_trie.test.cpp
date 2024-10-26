#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include <iostream>

#include "../lib/DataStructure/Others/binary_trie.hpp"

int main() {
    int q;
    std::cin >> q;

    algorithm::BinaryTrie<30> trie;
    while(q--) {
        int t;
        unsigned int x;
        std::cin >> t >> x;

        if(t == 0) {
            if(!trie.exists(x)) trie.insert(x);
        } else if(t == 1) {
            if(trie.exists(x)) trie.erase(x, 1);
        } else {
            trie.xor_all(x);
            auto ans = trie.min_element().to_ulong();
            trie.xor_all(x);

            std::cout << ans << "\n";
        }
    }
}
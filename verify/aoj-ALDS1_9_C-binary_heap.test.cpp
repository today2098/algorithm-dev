#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/9/ALDS1_9_C"

#include <iostream>
#include <string>

#include "../lib/DataStructure/Others/binary_heap.hpp"

int main() {
    using Type = int;
    auto comp = [](Type a, Type b) -> bool { return a < b; };
    algorithm::BinaryHeap<Type, comp> heap;

    while(true) {
        std::string op;
        std::cin >> op;

        if(op == "insert") {
            Type k;
            std::cin >> k;

            heap.push(k);
        } else if(op == "extract") {
            auto &&ans = heap.pop();
            std::cout << ans << "\n";
        } else {
            break;
        }
    }
}

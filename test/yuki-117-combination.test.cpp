#define PROBLEM "https://yukicoder.me/problems/no/117"

#include <iostream>

#include "../lib/Math/Combinatorics/combination.hpp"

int main() {
    int t;
    scanf("%d\n", &t);

    algorithm::Combination1000000007::reserve(1e6 + 1);
    while(t--) {
        char c;
        int n, k;
        scanf("%c(%d,%d)\n", &c, &n, &k);

        if(c == 'C') std::cout << algorithm::Combination1000000007::nCk(n, k);
        else if(c == 'P') std::cout << algorithm::Combination1000000007::nPk(n, k);
        else std::cout << algorithm::Combination1000000007::nHk(n, k);
        std::cout << "\n";
    }
}

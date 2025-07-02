#define PROBLEM "https://yukicoder.me/problems/no/117"

#include <iostream>

#include "../algorithm/Math/Combinatorics/combination.hpp"

int main() {
    int t;
    scanf("%d\n", &t);

    algorithm::Combination1000000007 comb(2e6);
    while(t--) {
        char c;
        int n, k;
        scanf("%c(%d,%d)\n", &c, &n, &k);

        long long ans;
        if(c == 'C') ans = comb.nCk(n, k);
        else if(c == 'P') ans = comb.nPk(n, k);
        else ans = comb.nHk(n, k);
        std::cout << ans << "\n";
    }
}

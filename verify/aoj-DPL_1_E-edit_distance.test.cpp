#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_E"

#include <iostream>
#include <string>

#include "../lib/String/edit_distance.hpp"

int main() {
    std::string s, t;
    std::cin >> s >> t;

    auto ans = algorithm::edit_distance(s, t);
    std::cout << ans << std::endl;
}

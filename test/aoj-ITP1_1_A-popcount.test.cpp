#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include <cassert>
#include <iostream>
#include <limits>
#include <random>

#include "../lib/Others/popcount.hpp"
#include "../lib/Utils/debug.hpp"

constexpr int naive_popcount(uint64_t bit) {
    int res = 0;
    while(bit) {
        res++;
        bit &= bit - 1;
    }
    return res;
}

int main() {
    static_assert(algorithm::popcount32(std::numeric_limits<uint32_t>::max()) == 32);
    static_assert(algorithm::popcount64(std::numeric_limits<uint64_t>::max()) == 64);

    constexpr int cnt = 10000;
    std::random_device seed;
    std::mt19937_64 rng(seed());

    std::uniform_int_distribution<uint32_t> uniform_type(std::numeric_limits<uint32_t>::min(),
                                                         std::numeric_limits<uint32_t>::max());
    for(int i = 0; i < cnt; ++i) {
        uint32_t &&arg = uniform_type(rng);
        auto &&target = algorithm::popcount32(arg);
        auto &&want = naive_popcount(arg);
        debug(i, arg, target, want);

        assert(target == want);
    }

    std::uniform_int_distribution<uint64_t> uniform_type2(std::numeric_limits<uint64_t>::min(),
                                                          std::numeric_limits<uint64_t>::max());
    for(int i = 0; i < cnt; ++i) {
        uint64_t &&arg = uniform_type2(rng);
        auto &&target = algorithm::popcount64(arg);
        auto &&want = naive_popcount(arg);
        debug(i, arg, target, want);

        assert(target == want);
    }

    std::cout << "Hello World" << std::endl;
}

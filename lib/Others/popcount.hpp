#ifndef ALGORITHM_POPCOUNT_HPP
#define ALGORITHM_POPCOUNT_HPP 1

/**
 * @brief Population Count (popcount)
 * @docs docs/Others/popcount.md
 */

#include <cstdint>

namespace algorithm {

constexpr int popcount32(uint32_t n) {
    constexpr uint32_t masks[5] = {0x55555555U, 0x33333333U, 0x0f0f0f0fU, 0x00ff00ffU, 0x0000ffffU};
    for(int i = 0; i < 5; ++i) n = (n & masks[i]) + ((n >> (1 << i)) & masks[i]);
    return n;
}

constexpr int popcount64(uint64_t n) {
    constexpr uint64_t masks[6] = {0x5555555555555555ULL, 0x3333333333333333ULL, 0x0f0f0f0f0f0f0f0fULL,
                                   0x00ff00ff00ff00ffULL, 0x0000ffff0000ffffULL, 0x00000000ffffffffULL};
    for(int i = 0; i < 6; ++i) n = (n & masks[i]) + ((n >> (1 << i)) & masks[i]);
    return n;
}

}  // namespace algorithm

#endif

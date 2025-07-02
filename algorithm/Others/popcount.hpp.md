---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-ITP1_1_A-popcount.test.cpp
    title: verify/aoj-ITP1_1_A-popcount.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Others/popcount.hpp\"\n\n\n\n#include <cstdint>\n\
    \nnamespace algorithm {\n\nconstexpr int popcount32(uint32_t bit) {\n    bit -=\
    \ (bit >> 1) & 0x5555'5555U;\n    bit = (bit & 0x3333'3333U) + ((bit >> 2) & 0x3333'3333U);\n\
    \    bit = (bit + (bit >> 4)) & 0x0f0f'0f0fU;\n    bit += bit >> 8;\n    bit +=\
    \ bit >> 16;\n    return bit & 0x0000'003fU;\n}\n\nconstexpr int popcount64(uint64_t\
    \ bit) {\n    bit -= (bit >> 1) & 0x5555'5555'5555'5555ULL;\n    bit = (bit &\
    \ 0x3333'3333'3333'3333ULL) + ((bit >> 2) & 0x3333'3333'3333'3333ULL);\n    bit\
    \ = (bit + (bit >> 4)) & 0x0f0f'0f0f'0f0f'0f0fULL;\n    bit += bit >> 8;\n   \
    \ bit += bit >> 16;\n    bit += bit >> 32;\n    return bit & 0x0000'0000'0000'007fULL;\n\
    }\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_POPCOUNT_HPP\n#define ALGORITHM_POPCOUNT_HPP 1\n\n#include\
    \ <cstdint>\n\nnamespace algorithm {\n\nconstexpr int popcount32(uint32_t bit)\
    \ {\n    bit -= (bit >> 1) & 0x5555'5555U;\n    bit = (bit & 0x3333'3333U) + ((bit\
    \ >> 2) & 0x3333'3333U);\n    bit = (bit + (bit >> 4)) & 0x0f0f'0f0fU;\n    bit\
    \ += bit >> 8;\n    bit += bit >> 16;\n    return bit & 0x0000'003fU;\n}\n\nconstexpr\
    \ int popcount64(uint64_t bit) {\n    bit -= (bit >> 1) & 0x5555'5555'5555'5555ULL;\n\
    \    bit = (bit & 0x3333'3333'3333'3333ULL) + ((bit >> 2) & 0x3333'3333'3333'3333ULL);\n\
    \    bit = (bit + (bit >> 4)) & 0x0f0f'0f0f'0f0f'0f0fULL;\n    bit += bit >> 8;\n\
    \    bit += bit >> 16;\n    bit += bit >> 32;\n    return bit & 0x0000'0000'0000'007fULL;\n\
    }\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Others/popcount.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-ITP1_1_A-popcount.test.cpp
documentation_of: algorithm/Others/popcount.hpp
layout: document
redirect_from:
- /library/algorithm/Others/popcount.hpp
- /library/algorithm/Others/popcount.hpp.html
title: algorithm/Others/popcount.hpp
---

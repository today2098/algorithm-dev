---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/Utils/grid.md
    document_title: "\u30B0\u30EA\u30C3\u30C9\u554F\u984C\u306B\u95A2\u3059\u308B\u30E6\
      \u30FC\u30C6\u30A3\u30EA\u30C6\u30A3\u30E9\u30A4\u30D6\u30E9\u30EA"
    links: []
  bundledCode: "#line 1 \"lib/Utils/grid.hpp\"\n\n\n\n/**\n * @brief \u30B0\u30EA\u30C3\
    \u30C9\u554F\u984C\u306B\u95A2\u3059\u308B\u30E6\u30FC\u30C6\u30A3\u30EA\u30C6\
    \u30A3\u30E9\u30A4\u30D6\u30E9\u30EA\n * @docs docs/Utils/grid.md\n */\n\n#include\
    \ <cassert>\n#include <utility>\n#include <vector>\n\nnamespace algorithm {\n\n\
    constexpr std::pair<int, int> dydx4[] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};\n\
    constexpr std::pair<int, int> dydx8[] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},\
    \ {0, 1}, {1, -1}, {1, 0}, {1, 1}};\n\nauto is_inner = [](int h, int w, int y,\
    \ int x) -> bool {\n    return (0 <= y and y < h and 0 <= x and x < w);\n};\n\n\
    }  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_GRID_HPP\n#define ALGORITHM_GRID_HPP 1\n\n/**\n * @brief\
    \ \u30B0\u30EA\u30C3\u30C9\u554F\u984C\u306B\u95A2\u3059\u308B\u30E6\u30FC\u30C6\
    \u30A3\u30EA\u30C6\u30A3\u30E9\u30A4\u30D6\u30E9\u30EA\n * @docs docs/Utils/grid.md\n\
    \ */\n\n#include <cassert>\n#include <utility>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\nconstexpr std::pair<int, int> dydx4[] = {{-1, 0}, {0, -1}, {0,\
    \ 1}, {1, 0}};\nconstexpr std::pair<int, int> dydx8[] = {{-1, -1}, {-1, 0}, {-1,\
    \ 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};\n\nauto is_inner = [](int h,\
    \ int w, int y, int x) -> bool {\n    return (0 <= y and y < h and 0 <= x and\
    \ x < w);\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Utils/grid.hpp
  requiredBy: []
  timestamp: '2025-01-04 00:08:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/Utils/grid.hpp
layout: document
redirect_from:
- /library/lib/Utils/grid.hpp
- /library/lib/Utils/grid.hpp.html
title: "\u30B0\u30EA\u30C3\u30C9\u554F\u984C\u306B\u95A2\u3059\u308B\u30E6\u30FC\u30C6\
  \u30A3\u30EA\u30C6\u30A3\u30E9\u30A4\u30D6\u30E9\u30EA"
---

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo-zalgorithm-z_algorithm.test.cpp
    title: verify/yosupo-zalgorithm-z_algorithm.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/String/z_algorithm.md
    document_title: "Z algorithm\uFF08\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E\uFF09"
    links: []
  bundledCode: "#line 1 \"lib/String/z_algorithm.hpp\"\n\n\n\n/**\n * @brief Z algorithm\uFF08\
    \u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E\uFF09\n * @docs docs/String/z_algorithm.md\n\
    \ */\n\n#include <vector>\n\nnamespace algorithm {\n\n// \u6700\u9577\u5171\u901A\
    \u63A5\u982D\u8F9E (LCP: Longest Common Prefix) \u306E\u9577\u3055\u3092\u6C42\
    \u3081\u308B\uFF0E\n// \u5F15\u6570\u306FSTL\u306E\u30B7\u30FC\u30B1\u30F3\u30B9\
    \u30B3\u30F3\u30C6\u30CA\u3067\u3042\u308B\u3053\u3068\uFF0EO(|S|).\ntemplate\
    \ <class Sequence>\nstd::vector<int> z_algorithm(const Sequence &s) {\n    const\
    \ int n = s.size();\n    std::vector<int> z(n);  // z[i]:=(s\u3068s[i:]\u306E\
    LCP\u306E\u9577\u3055).\n    z[0] = n;\n    int i = 1, j = 0;\n    while(i < n)\
    \ {\n        while(i + j < n and s[j] == s[i + j]) j++;\n        z[i] = j;\n \
    \       if(j == 0) {\n            i++;\n            continue;\n        }\n   \
    \     int k = 1;\n        while(i + k < n and k + z[k] < j) {\n            z[i\
    \ + k] = z[k];\n            k++;\n        }\n        i += k, j -= k;\n    }\n\
    \    return z;\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_Z_ALGORITHM_HPP\n#define ALGORITHM_Z_ALGORITHM_HPP 1\n\n\
    /**\n * @brief Z algorithm\uFF08\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E\uFF09\
    \n * @docs docs/String/z_algorithm.md\n */\n\n#include <vector>\n\nnamespace algorithm\
    \ {\n\n// \u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E (LCP: Longest Common Prefix)\
    \ \u306E\u9577\u3055\u3092\u6C42\u3081\u308B\uFF0E\n// \u5F15\u6570\u306FSTL\u306E\
    \u30B7\u30FC\u30B1\u30F3\u30B9\u30B3\u30F3\u30C6\u30CA\u3067\u3042\u308B\u3053\
    \u3068\uFF0EO(|S|).\ntemplate <class Sequence>\nstd::vector<int> z_algorithm(const\
    \ Sequence &s) {\n    const int n = s.size();\n    std::vector<int> z(n);  //\
    \ z[i]:=(s\u3068s[i:]\u306ELCP\u306E\u9577\u3055).\n    z[0] = n;\n    int i =\
    \ 1, j = 0;\n    while(i < n) {\n        while(i + j < n and s[j] == s[i + j])\
    \ j++;\n        z[i] = j;\n        if(j == 0) {\n            i++;\n          \
    \  continue;\n        }\n        int k = 1;\n        while(i + k < n and k + z[k]\
    \ < j) {\n            z[i + k] = z[k];\n            k++;\n        }\n        i\
    \ += k, j -= k;\n    }\n    return z;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/String/z_algorithm.hpp
  requiredBy: []
  timestamp: '2024-09-16 02:32:32+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo-zalgorithm-z_algorithm.test.cpp
documentation_of: lib/String/z_algorithm.hpp
layout: document
redirect_from:
- /library/lib/String/z_algorithm.hpp
- /library/lib/String/z_algorithm.hpp.html
title: "Z algorithm\uFF08\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E\uFF09"
---
## 概要

配列 $S$ に対して，$S$ と各 $i$ における $S[i:]$ の最長共通接頭辞 (LCP: Longest Common Prefix) の長さを求める．

アルゴリズムの計算量は $\mathcal{O}(\lvert S \rvert)$ となる．


## 参考文献

1. Pro_ktmr. "【図解】線形時間の文字列アルゴリズム「Z algorithm」をイラストとアニメーションでかみ砕く". Qiita. <https://qiita.com/Pro_ktmr/items/16904c9570aa0953bf05>.
1. snuke. "文字列の頭良い感じの線形アルゴリズムたち3". HatenaBlog. <https://snuke.hatenablog.com/entry/2014/12/03/214243>.

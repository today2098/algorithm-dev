---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/Math/Convolution/number_theoretic_transform.hpp
    title: "Number Theoretic Transform\uFF08\u6570\u8AD6\u5909\u63DB\uFF09"
  - icon: ':warning:'
    path: lib/Math/ModularArithmetic/dynamic_modint.hpp
    title: "\u52D5\u7684Modint\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: lib/Math/ModularArithmetic/modint.hpp
    title: "Modint\u69CB\u9020\u4F53"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-convolution_mod-number_theoretic_transform.test.cpp
    title: test/yosupo-convolution_mod-number_theoretic_transform.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-convolution_mod-number_theoretic_transform.test.cpp
    title: test/yosupo-convolution_mod-number_theoretic_transform.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
    title: test/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Math/ModularArithmetic/modint_base.md
    document_title: "Modint\u69CB\u9020\u4F53\u306E\u57FA\u5E95\u30AF\u30E9\u30B9"
    links: []
  bundledCode: "#line 1 \"lib/Math/ModularArithmetic/modint_base.hpp\"\n\n\n\n/**\n\
    \ * @brief Modint\u69CB\u9020\u4F53\u306E\u57FA\u5E95\u30AF\u30E9\u30B9\n * @docs\
    \ docs/Math/ModularArithmetic/modint_base.md\n */\n\n#include <type_traits>\n\n\
    namespace algorithm {\n\nclass ModintBase {};\n\ntemplate <class T>\nusing is_modint\
    \ = std::is_base_of<ModintBase, T>;\n\ntemplate <class T>\ninline constexpr bool\
    \ is_modint_v = is_modint<T>::value;\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_MODINT_BASE_HPP\n#define ALGORITHM_MODINT_BASE_HPP 1\n\n\
    /**\n * @brief Modint\u69CB\u9020\u4F53\u306E\u57FA\u5E95\u30AF\u30E9\u30B9\n\
    \ * @docs docs/Math/ModularArithmetic/modint_base.md\n */\n\n#include <type_traits>\n\
    \nnamespace algorithm {\n\nclass ModintBase {};\n\ntemplate <class T>\nusing is_modint\
    \ = std::is_base_of<ModintBase, T>;\n\ntemplate <class T>\ninline constexpr bool\
    \ is_modint_v = is_modint<T>::value;\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Math/ModularArithmetic/modint_base.hpp
  requiredBy:
  - lib/Math/Convolution/number_theoretic_transform.hpp
  - lib/Math/ModularArithmetic/modint.hpp
  - lib/Math/ModularArithmetic/dynamic_modint.hpp
  timestamp: '2024-09-06 22:39:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
  - test/yosupo-convolution_mod-number_theoretic_transform.test.cpp
  - test/yosupo-convolution_mod-number_theoretic_transform.test.cpp
documentation_of: lib/Math/ModularArithmetic/modint_base.hpp
layout: document
redirect_from:
- /library/lib/Math/ModularArithmetic/modint_base.hpp
- /library/lib/Math/ModularArithmetic/modint_base.hpp.html
title: "Modint\u69CB\u9020\u4F53\u306E\u57FA\u5E95\u30AF\u30E9\u30B9"
---

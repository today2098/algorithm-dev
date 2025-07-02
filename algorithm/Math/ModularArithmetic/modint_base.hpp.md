---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: algorithm/Math/Convolution/number_theoretic_transform.hpp
    title: "Number Theoretic Transform\uFF08\u6570\u8AD6\u5909\u63DB\uFF09"
  - icon: ':warning:'
    path: algorithm/Math/ModularArithmetic/dynamic_modint.hpp
    title: algorithm/Math/ModularArithmetic/dynamic_modint.hpp
  - icon: ':x:'
    path: algorithm/Math/ModularArithmetic/modint.hpp
    title: algorithm/Math/ModularArithmetic/modint.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp
    title: verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp
  - icon: ':x:'
    path: verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp
    title: verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp
  - icon: ':x:'
    path: verify/yosupo-point_set_range_composite-segment_tree.test.cpp
    title: verify/yosupo-point_set_range_composite-segment_tree.test.cpp
  - icon: ':x:'
    path: verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
    title: verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: '#line 1 "algorithm/Math/ModularArithmetic/modint_base.hpp"




    #include <type_traits>


    namespace algorithm {


    class ModintBase {};


    template <class T>

    using is_modint = std::is_base_of<ModintBase, T>;


    template <class T>

    inline constexpr bool is_modint_v = is_modint<T>::value;


    }  // namespace algorithm



    '
  code: '#ifndef ALGORITHM_MODINT_BASE_HPP

    #define ALGORITHM_MODINT_BASE_HPP 1


    #include <type_traits>


    namespace algorithm {


    class ModintBase {};


    template <class T>

    using is_modint = std::is_base_of<ModintBase, T>;


    template <class T>

    inline constexpr bool is_modint_v = is_modint<T>::value;


    }  // namespace algorithm


    #endif

    '
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Math/ModularArithmetic/modint_base.hpp
  requiredBy:
  - algorithm/Math/ModularArithmetic/modint.hpp
  - algorithm/Math/ModularArithmetic/dynamic_modint.hpp
  - algorithm/Math/Convolution/number_theoretic_transform.hpp
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp
  - verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp
  - verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
  - verify/yosupo-point_set_range_composite-segment_tree.test.cpp
documentation_of: algorithm/Math/ModularArithmetic/modint_base.hpp
layout: document
redirect_from:
- /library/algorithm/Math/ModularArithmetic/modint_base.hpp
- /library/algorithm/Math/ModularArithmetic/modint_base.hpp.html
title: algorithm/Math/ModularArithmetic/modint_base.hpp
---

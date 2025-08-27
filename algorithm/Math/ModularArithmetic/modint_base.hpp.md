---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/Convolution/number_theoretic_transform.hpp
    title: "Number Theoretic Transform\uFF08\u6570\u8AD6\u5909\u63DB\uFF09"
  - icon: ':warning:'
    path: algorithm/Math/ModularArithmetic/dynamic_modint.hpp
    title: "\u52D5\u7684Modint\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/modint.hpp
    title: "Modint\u69CB\u9020\u4F53"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp
    title: verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp
    title: verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-point_set_range_composite-segment_tree.test.cpp
    title: verify/yosupo-point_set_range_composite-segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
    title: verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 1 "algorithm/Math/ModularArithmetic/modint_base.hpp"




    #include <type_traits>


    namespace algorithm {


    class ModintBase {};


    template <typename T>

    struct is_modint : std::is_base_of<ModintBase, std::remove_cv_t<std::remove_reference_t<T>>>
    {};


    template <typename T>

    inline constexpr bool is_modint_v = is_modint<T>::value;


    }  // namespace algorithm



    '
  code: '#ifndef ALGORITHM_MODINT_BASE_HPP

    #define ALGORITHM_MODINT_BASE_HPP 1


    #include <type_traits>


    namespace algorithm {


    class ModintBase {};


    template <typename T>

    struct is_modint : std::is_base_of<ModintBase, std::remove_cv_t<std::remove_reference_t<T>>>
    {};


    template <typename T>

    inline constexpr bool is_modint_v = is_modint<T>::value;


    }  // namespace algorithm


    #endif

    '
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Math/ModularArithmetic/modint_base.hpp
  requiredBy:
  - algorithm/Math/Convolution/number_theoretic_transform.hpp
  - algorithm/Math/ModularArithmetic/dynamic_modint.hpp
  - algorithm/Math/ModularArithmetic/modint.hpp
  timestamp: '2025-08-10 09:02:12+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
  - verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp
  - verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp
  - verify/yosupo-point_set_range_composite-segment_tree.test.cpp
documentation_of: algorithm/Math/ModularArithmetic/modint_base.hpp
layout: document
title: "Modint\u69CB\u9020\u4F53\u306E\u57FA\u5E95\u30AF\u30E9\u30B9"
---

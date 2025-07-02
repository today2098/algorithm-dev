---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 1 "algorithm/Utils/table.hpp"




    #include <vector>


    namespace algorithm {


    template <typename Type>

    std::vector<Type> table(std::size_t n, const Type &val) { return std::vector<Type>(n,
    val); }


    template <typename... Args>

    auto table(std::size_t n, const Args &...args) { return std::vector(n, table(args...));
    }


    }  // namespace algorithm



    '
  code: '#ifndef ALGORITHM_TABLE_HPP

    #define ALGORITHM_TABLE_HPP 1


    #include <vector>


    namespace algorithm {


    template <typename Type>

    std::vector<Type> table(std::size_t n, const Type &val) { return std::vector<Type>(n,
    val); }


    template <typename... Args>

    auto table(std::size_t n, const Args &...args) { return std::vector(n, table(args...));
    }


    }  // namespace algorithm


    #endif

    '
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Utils/table.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/Utils/table.hpp
layout: document
redirect_from:
- /library/algorithm/Utils/table.hpp
- /library/algorithm/Utils/table.hpp.html
title: algorithm/Utils/table.hpp
---

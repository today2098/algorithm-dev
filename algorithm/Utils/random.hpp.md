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
  bundledCode: "#line 1 \"algorithm/Utils/random.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <concepts>\n#include <iterator>\n#include <limits>\n\
    #include <random>\n\nnamespace algorithm {\n\nclass Random {\npublic:\n    using\
    \ seed_type = std::uint_fast64_t;\n    using engine_type = std::mt19937_64;\n\
    \    using size_type = std::size_t;\n\nprivate:\n    seed_type m_seed;\n    engine_type\
    \ m_engine;\n\npublic:\n    Random() : Random(std::random_device()()) {}\n   \
    \ explicit Random(seed_type seed) : m_seed(seed), m_engine(seed) {}\n\n    seed_type\
    \ seed() const { return m_seed; }\n    engine_type &engine() { return m_engine;\
    \ }\n    auto next() { return m_engine(); }\n\n    template <std::integral Type>\n\
    \    Type uniform(Type min = std::numeric_limits<Type>::min(), Type max = std::numeric_limits<Type>::max())\
    \ {\n        std::uniform_int_distribution<Type> dist(min, max);\n        return\
    \ dist(m_engine);\n    }\n    template <std::floating_point Type>\n    Type uniform(Type\
    \ min = std::numeric_limits<Type>::min(), Type max = std::numeric_limits<Type>::max())\
    \ {\n        std::uniform_real_distribution<Type> dist(min, max);\n        return\
    \ dist(m_engine);\n    }\n    bool bernoulli(double p = 0.5) {\n        assert(0.0\
    \ <= p and p <= 1.0);\n        std::bernoulli_distribution dist(p);\n        return\
    \ dist(m_engine);\n    }\n    size_type binomial(size_type t, double p = 0.5)\
    \ {\n        assert(0.0 <= p and p <= 1.0);\n        std::binomial_distribution<size_type>\
    \ dist(t, p);\n        return dist(m_engine);\n    }\n    double normal(double\
    \ mean = 0.0, double stddev = 1.0) {\n        assert(stddev > 0.0);\n        std::normal_distribution<double>\
    \ dist(mean, stddev);\n        return dist(m_engine);\n    }\n    double lognormal(double\
    \ mean = 0.0, double stddev = 1.0) {\n        assert(stddev > 0.0);\n        std::lognormal_distribution<double>\
    \ dist(mean, stddev);\n        return dist(m_engine);\n    }\n\n    template <std::random_access_iterator\
    \ Iter>\n    void shuffle(Iter first, Iter last) { std::shuffle(first, last, m_engine);\
    \ }\n    template <std::input_iterator Iter, class Container>\n    auto sample(Iter\
    \ first, Iter last, size_type n, Container &c) { return std::sample(first, last,\
    \ std::back_inserter(c), n, m_engine); }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_RANDOM_HPP\n#define ALGORITHM_RANDOM_HPP 1\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <concepts>\n#include <iterator>\n\
    #include <limits>\n#include <random>\n\nnamespace algorithm {\n\nclass Random\
    \ {\npublic:\n    using seed_type = std::uint_fast64_t;\n    using engine_type\
    \ = std::mt19937_64;\n    using size_type = std::size_t;\n\nprivate:\n    seed_type\
    \ m_seed;\n    engine_type m_engine;\n\npublic:\n    Random() : Random(std::random_device()())\
    \ {}\n    explicit Random(seed_type seed) : m_seed(seed), m_engine(seed) {}\n\n\
    \    seed_type seed() const { return m_seed; }\n    engine_type &engine() { return\
    \ m_engine; }\n    auto next() { return m_engine(); }\n\n    template <std::integral\
    \ Type>\n    Type uniform(Type min = std::numeric_limits<Type>::min(), Type max\
    \ = std::numeric_limits<Type>::max()) {\n        std::uniform_int_distribution<Type>\
    \ dist(min, max);\n        return dist(m_engine);\n    }\n    template <std::floating_point\
    \ Type>\n    Type uniform(Type min = std::numeric_limits<Type>::min(), Type max\
    \ = std::numeric_limits<Type>::max()) {\n        std::uniform_real_distribution<Type>\
    \ dist(min, max);\n        return dist(m_engine);\n    }\n    bool bernoulli(double\
    \ p = 0.5) {\n        assert(0.0 <= p and p <= 1.0);\n        std::bernoulli_distribution\
    \ dist(p);\n        return dist(m_engine);\n    }\n    size_type binomial(size_type\
    \ t, double p = 0.5) {\n        assert(0.0 <= p and p <= 1.0);\n        std::binomial_distribution<size_type>\
    \ dist(t, p);\n        return dist(m_engine);\n    }\n    double normal(double\
    \ mean = 0.0, double stddev = 1.0) {\n        assert(stddev > 0.0);\n        std::normal_distribution<double>\
    \ dist(mean, stddev);\n        return dist(m_engine);\n    }\n    double lognormal(double\
    \ mean = 0.0, double stddev = 1.0) {\n        assert(stddev > 0.0);\n        std::lognormal_distribution<double>\
    \ dist(mean, stddev);\n        return dist(m_engine);\n    }\n\n    template <std::random_access_iterator\
    \ Iter>\n    void shuffle(Iter first, Iter last) { std::shuffle(first, last, m_engine);\
    \ }\n    template <std::input_iterator Iter, class Container>\n    auto sample(Iter\
    \ first, Iter last, size_type n, Container &c) { return std::sample(first, last,\
    \ std::back_inserter(c), n, m_engine); }\n};\n\n}  // namespace algorithm\n\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Utils/random.hpp
  requiredBy: []
  timestamp: '2025-08-11 05:59:14+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/Utils/random.hpp
layout: document
redirect_from:
- /library/algorithm/Utils/random.hpp
- /library/algorithm/Utils/random.hpp.html
title: algorithm/Utils/random.hpp
---

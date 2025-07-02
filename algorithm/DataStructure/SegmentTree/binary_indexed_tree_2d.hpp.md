---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algorithm/Math/Algebra/algebra.hpp
    title: algorithm/Math/Algebra/algebra.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-2842-binary_indexed_tree_2d.test.cpp
    title: verify/aoj-2842-binary_indexed_tree_2d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/DataStructure/SegmentTree/binary_indexed_tree_2d.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\n#line 1\
    \ \"algorithm/Math/Algebra/algebra.hpp\"\n\n\n\n#line 5 \"algorithm/Math/Algebra/algebra.hpp\"\
    \n#include <iostream>\n#include <limits>\n#include <numeric>\n#include <type_traits>\n\
    #include <utility>\n\nnamespace algorithm {\n\nnamespace algebra {\n\ntemplate\
    \ <typename S>\nclass Set {\npublic:\n    using value_type = S;\n\nprotected:\n\
    \    value_type val;\n\npublic:\n    constexpr Set() : val() {}\n    constexpr\
    \ Set(const value_type &val) : val(val) {}\n    constexpr Set(value_type &&val)\
    \ : val(std::move(val)) {}\n\n    friend constexpr bool operator==(const Set &lhs,\
    \ const Set &rhs) { return lhs.val == rhs.val; }\n    friend std::istream &operator>>(std::istream\
    \ &is, Set &rhs) { return is >> rhs.val; }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Set &rhs) { return os << rhs.val; }\n\n    constexpr value_type value()\
    \ const { return val; }\n};\n\ntemplate <typename S, auto op>\nclass Semigroup\
    \ : public Set<S> {\n    static_assert(std::is_invocable_r<S, decltype(op), S,\
    \ S>::value);\n\n    using base_type = Set<S>;\n\npublic:\n    using value_type\
    \ = typename base_type::value_type;\n\n    constexpr Semigroup() : base_type()\
    \ {}\n    constexpr Semigroup(const value_type &val) : base_type(val) {}\n   \
    \ constexpr Semigroup(value_type &&val) : base_type(std::move(val)) {}\n\n   \
    \ friend constexpr Semigroup operator*(const Semigroup &lhs, const Semigroup &rhs)\
    \ { return Semigroup(op(lhs.val, rhs.val)); }\n\n    static constexpr auto get_op()\
    \ { return op; }\n};\n\ntemplate <typename S, auto op, auto e>\nclass Monoid :\
    \ public Semigroup<S, op> {\n    static_assert(std::is_invocable_r<S, decltype(e)>::value);\n\
    \n    using base_type = Semigroup<S, op>;\n\npublic:\n    using value_type = typename\
    \ base_type::value_type;\n\n    constexpr Monoid() : base_type() {}\n    constexpr\
    \ Monoid(const value_type &val) : base_type(val) {}\n    constexpr Monoid(value_type\
    \ &&val) : base_type(std::move(val)) {}\n\n    friend constexpr Monoid operator*(const\
    \ Monoid &lhs, const Monoid &rhs) { return Monoid(op(lhs.val, rhs.val)); }\n\n\
    \    static constexpr auto get_e() { return e; }\n    static constexpr Monoid\
    \ one() { return Monoid(e()); }  // return identity element.\n};\n\ntemplate <typename\
    \ S, auto op, auto e, auto inverse>\nclass Group : public Monoid<S, op, e> {\n\
    \    static_assert(std::is_invocable_r<S, decltype(inverse), S>::value);\n\n \
    \   using base_type = Monoid<S, op, e>;\n\npublic:\n    using value_type = typename\
    \ base_type::value_type;\n\n    constexpr Group() : base_type() {}\n    constexpr\
    \ Group(const value_type &val) : base_type(val) {}\n    constexpr Group(value_type\
    \ &&val) : base_type(std::move(val)) {}\n\n    friend constexpr Group operator*(const\
    \ Group &lhs, const Group &rhs) { return Group(op(lhs.val, rhs.val)); }\n\n  \
    \  static constexpr auto get_inverse() { return inverse; }\n    static constexpr\
    \ Group one() { return Group(e()); }                // return identity element.\n\
    \    constexpr Group inv() const { return Group(inverse(this->val)); }  // return\
    \ inverse element.\n};\n\ntemplate <typename F, auto compose, auto id, typename\
    \ X, auto mapping>\nclass OperatorMonoid : public Monoid<F, compose, id> {\n \
    \   static_assert(std::is_invocable_r<X, decltype(mapping), F, X>::value);\n\n\
    \    using base_type = Monoid<F, compose, id>;\n\npublic:\n    using value_type\
    \ = typename base_type::value_type;\n    using acted_value_type = X;\n\n    constexpr\
    \ OperatorMonoid() : base_type() {}\n    constexpr OperatorMonoid(const value_type\
    \ &val) : base_type(val) {}\n    constexpr OperatorMonoid(value_type &&val) :\
    \ base_type(std::move(val)) {}\n\n    friend constexpr OperatorMonoid operator*(const\
    \ OperatorMonoid &lhs, const OperatorMonoid &rhs) { return OperatorMonoid(compose(lhs.val,\
    \ rhs.val)); }\n\n    static constexpr auto get_mapping() { return mapping; }\n\
    \    static constexpr OperatorMonoid one() { return OperatorMonoid(id()); }  //\
    \ return identity mapping.\n    constexpr acted_value_type act(const acted_value_type\
    \ &x) const { return mapping(this->val, x); }\n    template <class S>\n    constexpr\
    \ S act(const S &x) const {\n        static_assert(std::is_base_of<Set<acted_value_type>,\
    \ S>::value);\n        return S(mapping(this->val, x.value()));\n    }\n};\n\n\
    namespace element {\n\ntemplate <typename S>\nconstexpr auto zero = []() -> S\
    \ { return S(); };\n\ntemplate <typename S>\nconstexpr auto one = []() -> S {\
    \ return 1; };\n\ntemplate <typename S>\nconstexpr auto min = []() -> S { return\
    \ std::numeric_limits<S>::min(); };\n\ntemplate <typename S>\nconstexpr auto max\
    \ = []() -> S { return std::numeric_limits<S>::max(); };\n\ntemplate <typename\
    \ S>\nconstexpr auto one_below_max = []() -> S { return std::numeric_limits<S>::max()\
    \ - 1; };\n\ntemplate <typename S>\nconstexpr auto lowest = []() -> S { return\
    \ std::numeric_limits<S>::lowest(); };\n\ntemplate <typename S>\nconstexpr auto\
    \ one_above_lowest = []() -> S { return std::numeric_limits<S>::lowest() + 1;\
    \ };\n\n}  // namespace element\n\nnamespace uoperator {\n\ntemplate <typename\
    \ S>\nconstexpr auto identity = [](const S &val) -> S { return val; };\n\ntemplate\
    \ <typename S>\nconstexpr auto negate = [](const S &val) -> S { return -val; };\n\
    \n}  // namespace uoperator\n\nnamespace boperator {\n\ntemplate <typename T,\
    \ typename S = T>\nconstexpr auto plus = [](const T &lhs, const S &rhs) -> S {\
    \ return lhs + rhs; };\n\ntemplate <typename T, typename S = T>\nconstexpr auto\
    \ mul = [](const T &lhs, const S &rhs) -> S { return lhs * rhs; };\n\ntemplate\
    \ <typename T, typename S = T>\nconstexpr auto bit_and = [](const T &lhs, const\
    \ S &rhs) -> S { return lhs & rhs; };\n\ntemplate <typename T, typename S = T>\n\
    constexpr auto bit_or = [](const T &lhs, const S &rhs) -> S { return lhs | rhs;\
    \ };\n\ntemplate <typename T, typename S = T>\nconstexpr auto bit_xor = [](const\
    \ T &lhs, const S &rhs) -> S { return lhs ^ rhs; };\n\ntemplate <typename T, typename\
    \ S = T>\nconstexpr auto min = [](const T &lhs, const S &rhs) -> S { return std::min<S>(lhs,\
    \ rhs); };\n\ntemplate <typename T, typename S = T>\nconstexpr auto max = [](const\
    \ T &lhs, const S &rhs) -> S { return std::max<S>(lhs, rhs); };\n\ntemplate <typename\
    \ T, typename S = T>\nconstexpr auto gcd = [](const T &lhs, const S &rhs) -> S\
    \ { return std::gcd(lhs, rhs); };\n\ntemplate <typename T, typename S = T>\nconstexpr\
    \ auto lcm = [](const T &lhs, const S &rhs) -> S { return std::lcm(lhs, rhs);\
    \ };\n\ntemplate <typename F, auto id, typename X = F>\nconstexpr auto assign_if_not_id\
    \ = [](const F &lhs, const X &rhs) -> X {\n    static_assert(std::is_invocable_r<F,\
    \ decltype(id)>::value);\n    return (lhs == id() ? rhs : lhs);\n};\n\n}  // namespace\
    \ boperator\n\nnamespace monoid {\n\ntemplate <typename S>\nusing minimum = Monoid<S,\
    \ boperator::min<S>, element::max<S>>;\n\ntemplate <typename S>\nusing minimum_safe\
    \ = Monoid<S, boperator::min<S>, element::one_below_max<S>>;\n\ntemplate <typename\
    \ S>\nusing maximum = Monoid<S, boperator::max<S>, element::lowest<S>>;\n\ntemplate\
    \ <typename S>\nusing maximum_safe = Monoid<S, boperator::max<S>, element::one_above_lowest<S>>;\n\
    \ntemplate <typename S>\nusing addition = Monoid<S, boperator::plus<S>, element::zero<S>>;\n\
    \ntemplate <typename S>\nusing multiplication = Monoid<S, boperator::mul<S>, element::one<S>>;\n\
    \ntemplate <typename S>\nusing bit_xor = Monoid<S, boperator::bit_xor<S>, element::zero<S>>;\n\
    \n}  // namespace monoid\n\nnamespace group {\n\ntemplate <typename S>\nusing\
    \ addition = Group<S, boperator::plus<S>, element::zero<S>, uoperator::negate<S>>;\n\
    \ntemplate <typename S>\nusing bit_xor = Group<S, boperator::bit_xor<S>, element::zero<S>,\
    \ uoperator::identity<S>>;\n\n}  // namespace group\n\nnamespace operator_monoid\
    \ {\n\ntemplate <typename F, typename X = F>\nusing assign_for_minimum = OperatorMonoid<\n\
    \    F, boperator::assign_if_not_id<F, element::max<F>>, element::max<F>,\n  \
    \  X, boperator::assign_if_not_id<F, element::max<F>, X>>;\n\ntemplate <typename\
    \ F, typename X = F>\nusing assign_for_maximum = OperatorMonoid<\n    F, boperator::assign_if_not_id<F,\
    \ element::lowest<F>>, element::lowest<F>,\n    X, boperator::assign_if_not_id<F,\
    \ element::lowest<F>, X>>;\n\ntemplate <typename F, typename X = F>\nusing addition\
    \ = OperatorMonoid<F, boperator::plus<F>, element::zero<F>, X, boperator::plus<F,\
    \ X>>;\n\n}  // namespace operator_monoid\n\n}  // namespace algebra\n\n}  //\
    \ namespace algorithm\n\n\n#line 9 \"algorithm/DataStructure/SegmentTree/binary_indexed_tree_2d.hpp\"\
    \n\nnamespace algorithm {\n\nnamespace binary_indexed_tree_2d {\n\ntemplate <class\
    \ AbelianGroup>\nclass BIT2D {\npublic:\n    using group_type = AbelianGroup;\n\
    \    using value_type = group_type::value_type;\n\nprivate:\n    int m_h, m_w;\n\
    \    std::vector<std::vector<group_type>> m_tree;\n\n    static constexpr int\
    \ lsb(int bit) { return bit & -bit; }\n    group_type sum_internal(int y, int\
    \ x) const {\n        group_type &&res = group_type::one();\n        for(int i\
    \ = y; i >= 1; i -= lsb(i)) {\n            for(int j = x; j >= 1; j -= lsb(j))\
    \ res = res * m_tree[i - 1][j - 1];\n        }\n        return res;\n    }\n \
    \   void build() {\n        for(int i = 1; i <= m_h; ++i) {\n            int ni\
    \ = i + lsb(i);\n            for(int j = 1; j <= m_w; ++j) {\n               \
    \ int nj = j + lsb(j);\n                if(ni <= m_h) m_tree[ni - 1][j - 1] =\
    \ m_tree[ni - 1][j - 1] * m_tree[i - 1][j - 1];\n                if(nj <= m_w)\
    \ {\n                    m_tree[i - 1][nj - 1] = m_tree[i - 1][nj - 1] * m_tree[i\
    \ - 1][j - 1];\n                    if(ni <= m_h) m_tree[ni - 1][nj - 1] = m_tree[ni\
    \ - 1][nj - 1] * m_tree[i - 1][j - 1].inv();\n                }\n            }\n\
    \        }\n    }\n\npublic:\n    // constructor. O(H*W).\n    BIT2D() : BIT2D(0,\
    \ 0) {}\n    explicit BIT2D(int h, int w) : m_h(h), m_w(w), m_tree(h, std::vector<group_type>(w,\
    \ group_type::one())) {\n        assert(h >= 0 and w >= 0);\n    }\n    explicit\
    \ BIT2D(int h, int w, const value_type &a) : BIT2D(h, w, group_type(a)) {}\n \
    \   explicit BIT2D(int h, int w, const group_type &a) : m_h(h), m_w(w), m_tree(h,\
    \ std::vector<group_type>(w, a)) {\n        assert(h >= 0 and w >= 0);\n     \
    \   build();\n    }\n\n    int height() const { return m_h; }\n    int width()\
    \ const { return m_w; }\n    // (y,x)\u306B\u3042\u308B\u8981\u7D20\u3092a\u3068\
    \u306E\u7A4D\u306E\u7D50\u679C\u306B\u7F6E\u304D\u63DB\u3048\u308B\uFF0EO((log\
    \ H) log W).\n    void add(int y, int x, const value_type &a) { add(y, x, group_type(a));\
    \ }\n    void add(int y, int x, const group_type &a) {\n        assert(0 <= y\
    \ and y < height());\n        assert(0 <= x and x < width());\n        for(int\
    \ i = y + 1; i <= m_h; i += lsb(i)) {\n            for(int j = x + 1; j <= m_w;\
    \ j += lsb(j)) m_tree[i - 1][j - 1] = m_tree[i - 1][j - 1] * a;\n        }\n \
    \   }\n    // [0,y)\u304B\u3064[0,x)\u306E\u7BC4\u56F2\u306B\u3042\u308B\u8981\
    \u7D20\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\u308B\uFF0EO((log H) log W).\n    value_type\
    \ sum(int y, int x) const {\n        assert(0 <= y and y <= height());\n     \
    \   assert(0 <= x and x <= width());\n        return sum_internal(y, x).value();\n\
    \    }\n    // [y,yy)\u304B\u3064[x,xx)\u306E\u7BC4\u56F2\u306B\u3042\u308B\u8981\
    \u7D20\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\u308B\uFF0EO((log H) log W).\n    value_type\
    \ sum(int y, int x, int yy, int xx) const {\n        assert(0 <= y and y <= yy\
    \ and yy <= height());\n        assert(0 <= x and x <= xx and xx <= width());\n\
    \        return (sum_internal(yy, xx) * sum_internal(yy, x).inv() * sum_internal(y,\
    \ xx).inv() * sum_internal(y, x)).value();\n    }\n    // \u5168\u8981\u7D20\u306E\
    \u7DCF\u7A4D\u3092\u6C42\u3081\u308B\uFF0EO((log H) log W).\n    value_type sum_all()\
    \ const { return sum_internal(m_h, m_w).value(); }\n    void reset() {\n     \
    \   for(auto &v : m_tree) std::fill(v.begin(), v.end(), group_type::one());\n\
    \    }\n};\n\ntemplate <typename S>\nusing range_sum_binary_indexed_tree_2d =\
    \ BIT2D<algebra::group::addition<S>>;\n\n}  // namespace binary_indexed_tree_2d\n\
    \n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_BINARY_INDEXED_TREE_2D_HPP\n#define ALGORITHM_BINARY_INDEXED_TREE_2D_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\n#include\
    \ \"../../Math/Algebra/algebra.hpp\"\n\nnamespace algorithm {\n\nnamespace binary_indexed_tree_2d\
    \ {\n\ntemplate <class AbelianGroup>\nclass BIT2D {\npublic:\n    using group_type\
    \ = AbelianGroup;\n    using value_type = group_type::value_type;\n\nprivate:\n\
    \    int m_h, m_w;\n    std::vector<std::vector<group_type>> m_tree;\n\n    static\
    \ constexpr int lsb(int bit) { return bit & -bit; }\n    group_type sum_internal(int\
    \ y, int x) const {\n        group_type &&res = group_type::one();\n        for(int\
    \ i = y; i >= 1; i -= lsb(i)) {\n            for(int j = x; j >= 1; j -= lsb(j))\
    \ res = res * m_tree[i - 1][j - 1];\n        }\n        return res;\n    }\n \
    \   void build() {\n        for(int i = 1; i <= m_h; ++i) {\n            int ni\
    \ = i + lsb(i);\n            for(int j = 1; j <= m_w; ++j) {\n               \
    \ int nj = j + lsb(j);\n                if(ni <= m_h) m_tree[ni - 1][j - 1] =\
    \ m_tree[ni - 1][j - 1] * m_tree[i - 1][j - 1];\n                if(nj <= m_w)\
    \ {\n                    m_tree[i - 1][nj - 1] = m_tree[i - 1][nj - 1] * m_tree[i\
    \ - 1][j - 1];\n                    if(ni <= m_h) m_tree[ni - 1][nj - 1] = m_tree[ni\
    \ - 1][nj - 1] * m_tree[i - 1][j - 1].inv();\n                }\n            }\n\
    \        }\n    }\n\npublic:\n    // constructor. O(H*W).\n    BIT2D() : BIT2D(0,\
    \ 0) {}\n    explicit BIT2D(int h, int w) : m_h(h), m_w(w), m_tree(h, std::vector<group_type>(w,\
    \ group_type::one())) {\n        assert(h >= 0 and w >= 0);\n    }\n    explicit\
    \ BIT2D(int h, int w, const value_type &a) : BIT2D(h, w, group_type(a)) {}\n \
    \   explicit BIT2D(int h, int w, const group_type &a) : m_h(h), m_w(w), m_tree(h,\
    \ std::vector<group_type>(w, a)) {\n        assert(h >= 0 and w >= 0);\n     \
    \   build();\n    }\n\n    int height() const { return m_h; }\n    int width()\
    \ const { return m_w; }\n    // (y,x)\u306B\u3042\u308B\u8981\u7D20\u3092a\u3068\
    \u306E\u7A4D\u306E\u7D50\u679C\u306B\u7F6E\u304D\u63DB\u3048\u308B\uFF0EO((log\
    \ H) log W).\n    void add(int y, int x, const value_type &a) { add(y, x, group_type(a));\
    \ }\n    void add(int y, int x, const group_type &a) {\n        assert(0 <= y\
    \ and y < height());\n        assert(0 <= x and x < width());\n        for(int\
    \ i = y + 1; i <= m_h; i += lsb(i)) {\n            for(int j = x + 1; j <= m_w;\
    \ j += lsb(j)) m_tree[i - 1][j - 1] = m_tree[i - 1][j - 1] * a;\n        }\n \
    \   }\n    // [0,y)\u304B\u3064[0,x)\u306E\u7BC4\u56F2\u306B\u3042\u308B\u8981\
    \u7D20\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\u308B\uFF0EO((log H) log W).\n    value_type\
    \ sum(int y, int x) const {\n        assert(0 <= y and y <= height());\n     \
    \   assert(0 <= x and x <= width());\n        return sum_internal(y, x).value();\n\
    \    }\n    // [y,yy)\u304B\u3064[x,xx)\u306E\u7BC4\u56F2\u306B\u3042\u308B\u8981\
    \u7D20\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\u308B\uFF0EO((log H) log W).\n    value_type\
    \ sum(int y, int x, int yy, int xx) const {\n        assert(0 <= y and y <= yy\
    \ and yy <= height());\n        assert(0 <= x and x <= xx and xx <= width());\n\
    \        return (sum_internal(yy, xx) * sum_internal(yy, x).inv() * sum_internal(y,\
    \ xx).inv() * sum_internal(y, x)).value();\n    }\n    // \u5168\u8981\u7D20\u306E\
    \u7DCF\u7A4D\u3092\u6C42\u3081\u308B\uFF0EO((log H) log W).\n    value_type sum_all()\
    \ const { return sum_internal(m_h, m_w).value(); }\n    void reset() {\n     \
    \   for(auto &v : m_tree) std::fill(v.begin(), v.end(), group_type::one());\n\
    \    }\n};\n\ntemplate <typename S>\nusing range_sum_binary_indexed_tree_2d =\
    \ BIT2D<algebra::group::addition<S>>;\n\n}  // namespace binary_indexed_tree_2d\n\
    \n}  // namespace algorithm\n\n#endif\n"
  dependsOn:
  - algorithm/Math/Algebra/algebra.hpp
  isVerificationFile: false
  path: algorithm/DataStructure/SegmentTree/binary_indexed_tree_2d.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-2842-binary_indexed_tree_2d.test.cpp
documentation_of: algorithm/DataStructure/SegmentTree/binary_indexed_tree_2d.hpp
layout: document
redirect_from:
- /library/algorithm/DataStructure/SegmentTree/binary_indexed_tree_2d.hpp
- /library/algorithm/DataStructure/SegmentTree/binary_indexed_tree_2d.hpp.html
title: algorithm/DataStructure/SegmentTree/binary_indexed_tree_2d.hpp
---

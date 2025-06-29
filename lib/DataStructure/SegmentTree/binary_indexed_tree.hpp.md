---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Math/Algebra/algebra.hpp
    title: "Algebraic Structure\uFF08\u4EE3\u6570\u7684\u69CB\u9020\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DSL_2_B-binary_indexed_tree.test.cpp
    title: verify/aoj-DSL_2_B-binary_indexed_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-point_add_range_sum-binary_indexed_tree.test.cpp
    title: verify/yosupo-point_add_range_sum-binary_indexed_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp
    title: verify/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-vertex_add_subtree_sum-heavy_light_decomposition.test.cpp
    title: verify/yosupo-vertex_add_subtree_sum-heavy_light_decomposition.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/DataStructure/SegmentTree/binary_indexed_tree.hpp\"\n\
    \n\n\n#include <algorithm>\n#include <cassert>\n#include <initializer_list>\n\
    #include <iterator>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\
    \n#line 1 \"lib/Math/Algebra/algebra.hpp\"\n\n\n\n#line 5 \"lib/Math/Algebra/algebra.hpp\"\
    \n#include <iostream>\n#include <limits>\n#include <numeric>\n#line 10 \"lib/Math/Algebra/algebra.hpp\"\
    \n\nnamespace algorithm {\n\nnamespace algebra {\n\ntemplate <typename S>\nclass\
    \ Set {\npublic:\n    using value_type = S;\n\nprotected:\n    value_type val;\n\
    \npublic:\n    constexpr Set() : val() {}\n    constexpr Set(const value_type\
    \ &val) : val(val) {}\n    constexpr Set(value_type &&val) : val(std::move(val))\
    \ {}\n\n    friend constexpr bool operator==(const Set &lhs, const Set &rhs) {\
    \ return lhs.val == rhs.val; }\n    friend std::istream &operator>>(std::istream\
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
    \ namespace algorithm\n\n\n#line 13 \"lib/DataStructure/SegmentTree/binary_indexed_tree.hpp\"\
    \n\nnamespace algorithm {\n\nnamespace binary_indexed_tree {\n\ntemplate <class\
    \ AbelianGroup>\nclass BIT {\npublic:\n    using group_type = AbelianGroup;\n\
    \    using value_type = group_type::value_type;\n\nprivate:\n    int m_sz;  //\
    \ m_sz:=(\u8981\u7D20\u6570).\n    std::vector<group_type> m_tree;\n\n    static\
    \ constexpr int lsb(int bit) { return bit & -bit; }\n    group_type sum_internal(int\
    \ r) const {\n        group_type &&res = group_type::one();\n        for(; r >=\
    \ 1; r -= lsb(r)) res = res * m_tree[r - 1];\n        return res;\n    }\n   \
    \ void build() {\n        for(int i = 1; i < m_sz; ++i) {\n            int j =\
    \ i + lsb(i);\n            if(j <= m_sz) m_tree[j - 1] = m_tree[j - 1] * m_tree[i\
    \ - 1];\n        }\n    }\n\npublic:\n    // constructor. O(N).\n    BIT() : m_sz(0)\
    \ {};\n    explicit BIT(int n) : m_sz(n), m_tree(n, group_type::one()) {\n   \
    \     assert(n >= 0);\n    }\n    explicit BIT(int n, const value_type &a) : BIT(n,\
    \ group_type(a)) {}\n    explicit BIT(int n, const group_type &a) : m_sz(n), m_tree(n,\
    \ a) {\n        assert(n >= 0);\n        build();\n    }\n    template <std::input_iterator\
    \ InputIter>\n    explicit BIT(InputIter first, InputIter last) : m_tree(first,\
    \ last) {\n        m_sz = m_tree.size();\n        build();\n    }\n    template\
    \ <typename T>\n    explicit BIT(std::initializer_list<T> il) : BIT(il.begin(),\
    \ il.end()) {}\n    explicit BIT(const std::vector<group_type> &v) : m_sz(v.size()),\
    \ m_tree(v) {\n        build();\n    }\n    explicit BIT(std::vector<group_type>\
    \ &&v) : m_tree(std::move(v)) {\n        m_sz = m_tree.size();\n        build();\n\
    \    }\n\n    // \u8981\u7D20\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int\
    \ size() const { return m_sz; }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\
    a\u3068\u306E\u7A4D\u306E\u7D50\u679C\u306B\u7F6E\u304D\u63DB\u3048\u308B\uFF0E\
    O(log N).\n    void add(int k, const value_type &a) { add(k, group_type(a)); }\n\
    \    void add(int k, const group_type &a) {\n        assert(0 <= k and k < size());\n\
    \        for(int i = k + 1; i <= m_sz; i += lsb(i)) m_tree[i - 1] = m_tree[i -\
    \ 1] * a;\n    }\n    // \u533A\u9593[0,r)\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\
    \u3092\u6C42\u3081\u308B\uFF0EO(log N).\n    value_type sum(int r) const {\n \
    \       assert(0 <= r and r <= size());\n        return sum_internal(r).value();\n\
    \    }\n    // \u533A\u9593[l,r)\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u6C42\
    \u3081\u308B\uFF0EO(log N).\n    value_type sum(int l, int r) const {\n      \
    \  assert(0 <= l and l <= r and r <= size());\n        return (sum_internal(r)\
    \ * sum_internal(l).inv()).value();\n    }\n    // \u5168\u8981\u7D20\u306E\u7DCF\
    \u7A4D\u3092\u6C42\u3081\u308B\uFF0EO(log N).\n    value_type sum_all() const\
    \ { return sum_internal(m_sz).value(); }\n    // pred(sum(r))==true \u3068\u306A\
    \u308B\u533A\u9593\u306E\u6700\u53F3\u4F4D\u5024r\u3092\u4E8C\u5206\u63A2\u7D22\
    \u3059\u308B\uFF0E\n    // \u305F\u3060\u3057\uFF0C\u533A\u9593[0,n)\u306E\u8981\
    \u7D20\u306Fpred(S)\u306B\u3088\u3063\u3066\u533A\u5206\u5316\u3055\u308C\u3066\
    \u3044\u308B\u3053\u3068\uFF0E\u307E\u305F\uFF0Cpred(e)==true \u3067\u3042\u308B\
    \u3053\u3068\uFF0EO(log N).\n    template <bool (*pred)(value_type)>\n    int\
    \ most_right() const {\n        return most_right([](const value_type &x) -> bool\
    \ { return pred(x); });\n    }\n    template <typename Pred>\n    int most_right(Pred\
    \ pred) const {\n        static_assert(std::is_invocable_r<bool, Pred, value_type>::value);\n\
    \        assert(pred(group_type::one().value()));\n        int r = 0;\n      \
    \  group_type &&val = group_type::one();\n        for(int i = 1; i <= m_sz and\
    \ pred(m_tree[i - 1].value()); i <<= 1) r = i, val = m_tree[i - 1];\n        for(int\
    \ len = r >> 1; len > 0; len >>= 1) {\n            if(r + len <= m_sz and pred((val\
    \ * m_tree[r + len - 1]).value())) {\n                r += len;\n            \
    \    val = val * m_tree[r - 1];\n            }\n        }\n        return r;\n\
    \    }\n    void reset() { std::fill(m_tree.begin(), m_tree.end(), group_type::one());\
    \ }\n};\n\ntemplate <typename S>\nusing range_sum_binary_indexed_tree = BIT<algebra::group::addition<S>>;\n\
    \ntemplate <typename S>\nusing range_xor_binary_indexed_tree = BIT<algebra::group::bit_xor<S>>;\n\
    \n}  // namespace binary_indexed_tree\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_BINARY_INDEXED_TREE_HPP\n#define ALGORITHM_BINARY_INDEXED_TREE_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <initializer_list>\n\
    #include <iterator>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\
    \n#include \"../../Math/Algebra/algebra.hpp\"\n\nnamespace algorithm {\n\nnamespace\
    \ binary_indexed_tree {\n\ntemplate <class AbelianGroup>\nclass BIT {\npublic:\n\
    \    using group_type = AbelianGroup;\n    using value_type = group_type::value_type;\n\
    \nprivate:\n    int m_sz;  // m_sz:=(\u8981\u7D20\u6570).\n    std::vector<group_type>\
    \ m_tree;\n\n    static constexpr int lsb(int bit) { return bit & -bit; }\n  \
    \  group_type sum_internal(int r) const {\n        group_type &&res = group_type::one();\n\
    \        for(; r >= 1; r -= lsb(r)) res = res * m_tree[r - 1];\n        return\
    \ res;\n    }\n    void build() {\n        for(int i = 1; i < m_sz; ++i) {\n \
    \           int j = i + lsb(i);\n            if(j <= m_sz) m_tree[j - 1] = m_tree[j\
    \ - 1] * m_tree[i - 1];\n        }\n    }\n\npublic:\n    // constructor. O(N).\n\
    \    BIT() : m_sz(0) {};\n    explicit BIT(int n) : m_sz(n), m_tree(n, group_type::one())\
    \ {\n        assert(n >= 0);\n    }\n    explicit BIT(int n, const value_type\
    \ &a) : BIT(n, group_type(a)) {}\n    explicit BIT(int n, const group_type &a)\
    \ : m_sz(n), m_tree(n, a) {\n        assert(n >= 0);\n        build();\n    }\n\
    \    template <std::input_iterator InputIter>\n    explicit BIT(InputIter first,\
    \ InputIter last) : m_tree(first, last) {\n        m_sz = m_tree.size();\n   \
    \     build();\n    }\n    template <typename T>\n    explicit BIT(std::initializer_list<T>\
    \ il) : BIT(il.begin(), il.end()) {}\n    explicit BIT(const std::vector<group_type>\
    \ &v) : m_sz(v.size()), m_tree(v) {\n        build();\n    }\n    explicit BIT(std::vector<group_type>\
    \ &&v) : m_tree(std::move(v)) {\n        m_sz = m_tree.size();\n        build();\n\
    \    }\n\n    // \u8981\u7D20\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int\
    \ size() const { return m_sz; }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\
    a\u3068\u306E\u7A4D\u306E\u7D50\u679C\u306B\u7F6E\u304D\u63DB\u3048\u308B\uFF0E\
    O(log N).\n    void add(int k, const value_type &a) { add(k, group_type(a)); }\n\
    \    void add(int k, const group_type &a) {\n        assert(0 <= k and k < size());\n\
    \        for(int i = k + 1; i <= m_sz; i += lsb(i)) m_tree[i - 1] = m_tree[i -\
    \ 1] * a;\n    }\n    // \u533A\u9593[0,r)\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\
    \u3092\u6C42\u3081\u308B\uFF0EO(log N).\n    value_type sum(int r) const {\n \
    \       assert(0 <= r and r <= size());\n        return sum_internal(r).value();\n\
    \    }\n    // \u533A\u9593[l,r)\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u6C42\
    \u3081\u308B\uFF0EO(log N).\n    value_type sum(int l, int r) const {\n      \
    \  assert(0 <= l and l <= r and r <= size());\n        return (sum_internal(r)\
    \ * sum_internal(l).inv()).value();\n    }\n    // \u5168\u8981\u7D20\u306E\u7DCF\
    \u7A4D\u3092\u6C42\u3081\u308B\uFF0EO(log N).\n    value_type sum_all() const\
    \ { return sum_internal(m_sz).value(); }\n    // pred(sum(r))==true \u3068\u306A\
    \u308B\u533A\u9593\u306E\u6700\u53F3\u4F4D\u5024r\u3092\u4E8C\u5206\u63A2\u7D22\
    \u3059\u308B\uFF0E\n    // \u305F\u3060\u3057\uFF0C\u533A\u9593[0,n)\u306E\u8981\
    \u7D20\u306Fpred(S)\u306B\u3088\u3063\u3066\u533A\u5206\u5316\u3055\u308C\u3066\
    \u3044\u308B\u3053\u3068\uFF0E\u307E\u305F\uFF0Cpred(e)==true \u3067\u3042\u308B\
    \u3053\u3068\uFF0EO(log N).\n    template <bool (*pred)(value_type)>\n    int\
    \ most_right() const {\n        return most_right([](const value_type &x) -> bool\
    \ { return pred(x); });\n    }\n    template <typename Pred>\n    int most_right(Pred\
    \ pred) const {\n        static_assert(std::is_invocable_r<bool, Pred, value_type>::value);\n\
    \        assert(pred(group_type::one().value()));\n        int r = 0;\n      \
    \  group_type &&val = group_type::one();\n        for(int i = 1; i <= m_sz and\
    \ pred(m_tree[i - 1].value()); i <<= 1) r = i, val = m_tree[i - 1];\n        for(int\
    \ len = r >> 1; len > 0; len >>= 1) {\n            if(r + len <= m_sz and pred((val\
    \ * m_tree[r + len - 1]).value())) {\n                r += len;\n            \
    \    val = val * m_tree[r - 1];\n            }\n        }\n        return r;\n\
    \    }\n    void reset() { std::fill(m_tree.begin(), m_tree.end(), group_type::one());\
    \ }\n};\n\ntemplate <typename S>\nusing range_sum_binary_indexed_tree = BIT<algebra::group::addition<S>>;\n\
    \ntemplate <typename S>\nusing range_xor_binary_indexed_tree = BIT<algebra::group::bit_xor<S>>;\n\
    \n}  // namespace binary_indexed_tree\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn:
  - lib/Math/Algebra/algebra.hpp
  isVerificationFile: false
  path: lib/DataStructure/SegmentTree/binary_indexed_tree.hpp
  requiredBy: []
  timestamp: '2025-06-14 20:16:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp
  - verify/aoj-DSL_2_B-binary_indexed_tree.test.cpp
  - verify/yosupo-vertex_add_subtree_sum-heavy_light_decomposition.test.cpp
  - verify/yosupo-point_add_range_sum-binary_indexed_tree.test.cpp
documentation_of: lib/DataStructure/SegmentTree/binary_indexed_tree.hpp
layout: document
title: Binary Indexed Tree
---


## 概要

「Binary Indexed Tree (BIT)」とは，1994年に Peter Fenwick により提案された木構造をしたデータ構造．
別名「Fenwick Tree（フェニック木）」．

あるアーベル群 $(S, *: S \times S \rightarrow S, e \in S)$ において，長さ $N$ の数列 $\lbrace a_0, a_1, \ldots, a_{N-1} \rbrace$ に対する次のクエリ処理を $\mathcal{O}(\log N)$ で行う．

- **一点更新** $\operatorname{add}(i,x)$：要素 $a_i$ を $a_i * x$ に更新する
- **区間取得** $\operatorname{sum}(r)$：区間 $[0,r)$ の要素の総積を求める

任意の区間 $[l,r)$ の要素の総積を知りたい場合は，$\operatorname{sum}(r)-\operatorname{sum}(l)$ から求められる．

ここで「アーベル群 (abelian group)」とは，次の性質を満たす組 $(S, *：S \times S \rightarrow S, e \in S)$ による代数的構造のことをいう（交換法則を有する群である）．

1. 結合法則：$a \ast (b \ast c) = (a \ast b) \ast c \quad (\forall a, \forall b, \forall c \in S)$
1. 単位元の存在：$e \ast a = a \ast e = a \quad (\exists e, \forall a \in S)$
1. **逆元の存在**：$a \ast a^{-1} = a^{-1} \ast a = e \quad (\exists e, \forall a, \exists a^{-1} \in S)$
1. **交換法則**：$a \ast b = b \ast a \quad (\forall a, \forall b \in S)$

必要なメモリサイズは対象の配列サイズと同じであり，Segment tree より軽い（Segment tree は2倍程度）．


## 説明

### algorithm::binary_indexed_tree::BIT<AbelianGroup>

|テンプレート引数|説明|
|---|---|
|`AbelianGroup`|アーベル群の型．`algorithm::algebra::Group` を想定している．|

|コンストラクタ|説明|計算量|
|---|---|---|
|`BIT()`|デフォルトコンストラクタ．サイズゼロの `BIT` オブジェクトを構築する．|-|
|`BIT(n)`|コンストラクタ．`n` 個の単位元 `Group::one()` で初期化された要素をもつ `BIT` オブジェクトを構築する．|$\Theta(N)$|
|`BIT(n,a)`|コンストラクタ．`n` 個の `a` で初期化された要素をもつ `BIT` オブジェクトを構築する．|$\Theta(N)$|
|`BIT(first,last)`|コンストラクタ．イテレータ範囲 `[first,last)` の要素を用いて `BIT` オブジェクトを構築する．|$\Theta(N)$|
|`BIT(il)`|初期化子リスト `il` を受け取るコンストラクタ．`BIT(il.begin(),il.end())` と等価．|$\Theta(N)$|

|メンバ関数|説明|計算量|
|---|---|---|
|`x=size()`|要素数 `x` を取得する．|$\mathcal{O}(1)$|
|`add(k,a)`|`k` 番目の要素を `a` との積の結果に置き換える．|$\mathcal{O}(\log N)$|
|`x=sum(r)`|区間 `[0,r)` の要素の総積 `x` を求める．|$\mathcal{O}(\log N)$|
|`x=sum(l,r)`|区間 `[l,r)` の要素の総積 `x` を求める．|$\mathcal{O}(\log N)$|
|`x=sum_all()`|全要素の総積 `x` を求める．|$\mathcal{O}(\log N)$|
|`r=most_right(pred)`|`pred(sum(r))==true` となる区間の最右位置 `r` を二分探索する．ただし，区間 $[0,n)$ の要素は1項述語 `pred` によって区分化されていること．また，`pred(Monoid::one())==true` であること．|$\mathcal{O}(\log N)$|
|`reset()`|全要素を単位元 `Monoid::one()` で初期化する．|$\Theta(N)$|


## 参考

1. "フェニック木". Wikipedia. <https://ja.wikipedia.org/wiki/フェニック木>.
1. "アーベル群". Wikipedia. <https://ja.wikipedia.org/wiki/アーベル群>.
1. ngtkana. "データ構造 Fenwick tree (binary indexed tree, BIT) にどっぷりと入門し、その美しき構造に心を洗われたい方のための紹介記事です！". Qiita. <https://qiita.com/ngtkana/items/7d50ff180a4e5c294cb7>.
1. sysdev. "AtCoder Library を読んでアルゴリズムを勉強：フェニック木（BIT）". Qiita. <https://qiita.com/sysdev/items/30aa7d5e9ac4ea871bd3>.
1. "Binary Indexed Tree（Fenwick Tree）". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/binary_indexed_tree>.


## 問題

- "B - Fenwick Tree". AtCoder Library Practice Contest. AtCoder. <https://atcoder.jp/contests/practice2/tasks/practice2_b>.

---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/DataStructure/SegmentTree/lazy_segment_tree.hpp
    title: "Lazy Segment Tree\uFF08\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\
      \u30C8\u6728\uFF09"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/Algebra/algebra.hpp
    title: "Algebraic Structure\uFF08\u4EE3\u6570\u7684\u69CB\u9020\uFF09"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/mod_inv.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u9006\u6570\uFF08\u4E57\u6CD5\u9006\u5143\uFF09"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/modint.hpp
    title: "Modint\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/modint_base.hpp
    title: "Modint\u69CB\u9020\u4F53\u306E\u57FA\u5E95\u30AF\u30E9\u30B9"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/modulo.hpp
    title: algorithm/Math/ModularArithmetic/modulo.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    \n#include <iostream>\n#include <vector>\n\n#line 1 \"algorithm/DataStructure/SegmentTree/lazy_segment_tree.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <initializer_list>\n\
    #line 8 \"algorithm/DataStructure/SegmentTree/lazy_segment_tree.hpp\"\n#include\
    \ <iterator>\n#include <ranges>\n#include <type_traits>\n#include <utility>\n\
    #line 13 \"algorithm/DataStructure/SegmentTree/lazy_segment_tree.hpp\"\n\n#line\
    \ 1 \"algorithm/Math/Algebra/algebra.hpp\"\n\n\n\n#line 6 \"algorithm/Math/Algebra/algebra.hpp\"\
    \n#include <limits>\n#include <numeric>\n#line 10 \"algorithm/Math/Algebra/algebra.hpp\"\
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
    \ S>::value);\n\npublic:\n    using base_type = Set<S>;\n    using value_type\
    \ = typename base_type::value_type;\n\n    constexpr Semigroup() : base_type()\
    \ {}\n    constexpr Semigroup(const value_type &val) : base_type(val) {}\n   \
    \ constexpr Semigroup(value_type &&val) : base_type(std::move(val)) {}\n\n   \
    \ friend constexpr Semigroup operator*(const Semigroup &lhs, const Semigroup &rhs)\
    \ { return Semigroup(op(lhs.val, rhs.val)); }\n\n    static constexpr auto get_op()\
    \ { return op; }\n};\n\ntemplate <typename S, auto op, auto e>\nclass Monoid :\
    \ public Semigroup<S, op> {\n    static_assert(std::is_invocable_r<S, decltype(e)>::value);\n\
    \npublic:\n    using base_type = Semigroup<S, op>;\n    using value_type = typename\
    \ base_type::value_type;\n\n    constexpr Monoid() : base_type() {}\n    constexpr\
    \ Monoid(const value_type &val) : base_type(val) {}\n    constexpr Monoid(value_type\
    \ &&val) : base_type(std::move(val)) {}\n\n    friend constexpr Monoid operator*(const\
    \ Monoid &lhs, const Monoid &rhs) { return Monoid(op(lhs.val, rhs.val)); }\n\n\
    \    static constexpr auto get_e() { return e; }\n    static constexpr Monoid\
    \ one() { return Monoid(e()); }  // return identity element.\n};\n\ntemplate <typename\
    \ S, auto op, auto e, auto inverse>\nclass Group : public Monoid<S, op, e> {\n\
    \    static_assert(std::is_invocable_r<S, decltype(inverse), S>::value);\n\npublic:\n\
    \    using base_type = Monoid<S, op, e>;\n    using value_type = typename base_type::value_type;\n\
    \n    constexpr Group() : base_type() {}\n    constexpr Group(const value_type\
    \ &val) : base_type(val) {}\n    constexpr Group(value_type &&val) : base_type(std::move(val))\
    \ {}\n\n    friend constexpr Group operator*(const Group &lhs, const Group &rhs)\
    \ { return Group(op(lhs.val, rhs.val)); }\n\n    static constexpr auto get_inverse()\
    \ { return inverse; }\n    static constexpr Group one() { return Group(e()); }\
    \                     // return identity element.\n    constexpr Group inv() const\
    \ { return Group(inverse(base_type::val)); }  // return inverse element.\n};\n\
    \ntemplate <typename F, auto compose, auto id, typename X, auto mapping>\nclass\
    \ OperatorMonoid : public Monoid<F, compose, id> {\n    static_assert(std::is_invocable_r<X,\
    \ decltype(mapping), F, X>::value);\n\npublic:\n    using base_type = Monoid<F,\
    \ compose, id>;\n    using value_type = typename base_type::value_type;\n    using\
    \ acted_type = X;\n\n    constexpr OperatorMonoid() : base_type() {}\n    constexpr\
    \ OperatorMonoid(const value_type &val) : base_type(val) {}\n    constexpr OperatorMonoid(value_type\
    \ &&val) : base_type(std::move(val)) {}\n\n    friend constexpr OperatorMonoid\
    \ operator*(const OperatorMonoid &lhs, const OperatorMonoid &rhs) { return OperatorMonoid(compose(lhs.val,\
    \ rhs.val)); }\n\n    static constexpr auto get_mapping() { return mapping; }\n\
    \    static constexpr OperatorMonoid one() { return OperatorMonoid(id()); }  //\
    \ return identity mapping.\n    constexpr acted_type act(const acted_type &x)\
    \ const { return mapping(base_type::val, x); }\n    template <class S>\n    constexpr\
    \ S act(const S &x) const {\n        static_assert(std::is_base_of<Set<acted_type>,\
    \ S>::value);\n        return S(mapping(base_type::val, x.value()));\n    }\n\
    };\n\nnamespace element {\n\ntemplate <typename S>\nconstexpr auto zero = []()\
    \ -> S { return S(); };\n\ntemplate <typename S>\nconstexpr auto one = []() ->\
    \ S { return 1; };\n\ntemplate <typename S>\nconstexpr auto min = []() -> S {\
    \ return std::numeric_limits<S>::min(); };\n\ntemplate <typename S>\nconstexpr\
    \ auto max = []() -> S { return std::numeric_limits<S>::max(); };\n\ntemplate\
    \ <typename S>\nconstexpr auto one_below_max = []() -> S { return std::numeric_limits<S>::max()\
    \ - 1; };\n\ntemplate <typename S>\nconstexpr auto lowest = []() -> S { return\
    \ std::numeric_limits<S>::lowest(); };\n\ntemplate <typename S>\nconstexpr auto\
    \ one_above_lowest = []() -> S { return std::numeric_limits<S>::lowest() + 1;\
    \ };\n\n}  // namespace element\n\nnamespace unary_operator {\n\ntemplate <typename\
    \ S>\nconstexpr auto identity = [](const S &val) -> S { return val; };\n\ntemplate\
    \ <typename S>\nconstexpr auto negate = [](const S &val) -> S { return -val; };\n\
    \n}  // namespace unary_operator\n\nnamespace binary_operator {\n\ntemplate <typename\
    \ T, typename S = T>\nconstexpr auto plus = [](const T &lhs, const S &rhs) ->\
    \ S { return lhs + rhs; };\n\ntemplate <typename T, typename S = T>\nconstexpr\
    \ auto mul = [](const T &lhs, const S &rhs) -> S { return lhs * rhs; };\n\ntemplate\
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
    \ binary_operator\n\nnamespace monoid {\n\ntemplate <typename S>\nusing minimum\
    \ = Monoid<S, binary_operator::min<S>, element::max<S>>;\n\ntemplate <typename\
    \ S>\nusing minimum_safe = Monoid<S, binary_operator::min<S>, element::one_below_max<S>>;\n\
    \ntemplate <typename S>\nusing maximum = Monoid<S, binary_operator::max<S>, element::lowest<S>>;\n\
    \ntemplate <typename S>\nusing maximum_safe = Monoid<S, binary_operator::max<S>,\
    \ element::one_above_lowest<S>>;\n\ntemplate <typename S>\nusing addition = Monoid<S,\
    \ binary_operator::plus<S>, element::zero<S>>;\n\ntemplate <typename S>\nusing\
    \ multiplication = Monoid<S, binary_operator::mul<S>, element::one<S>>;\n\ntemplate\
    \ <typename S>\nusing bit_xor = Monoid<S, binary_operator::bit_xor<S>, element::zero<S>>;\n\
    \n}  // namespace monoid\n\nnamespace group {\n\ntemplate <typename S>\nusing\
    \ addition = Group<S, binary_operator::plus<S>, element::zero<S>, unary_operator::negate<S>>;\n\
    \ntemplate <typename S>\nusing bit_xor = Group<S, binary_operator::bit_xor<S>,\
    \ element::zero<S>, unary_operator::identity<S>>;\n\n}  // namespace group\n\n\
    namespace operator_monoid {\n\ntemplate <typename F, typename X = F>\nusing assign_for_minimum\
    \ = OperatorMonoid<\n    F, binary_operator::assign_if_not_id<F, element::max<F>>,\
    \ element::max<F>,\n    X, binary_operator::assign_if_not_id<F, element::max<F>,\
    \ X>>;\n\ntemplate <typename F, typename X = F>\nusing assign_for_maximum = OperatorMonoid<\n\
    \    F, binary_operator::assign_if_not_id<F, element::lowest<F>>, element::lowest<F>,\n\
    \    X, binary_operator::assign_if_not_id<F, element::lowest<F>, X>>;\n\ntemplate\
    \ <typename F, typename X = F>\nusing addition = OperatorMonoid<\n    F, binary_operator::plus<F>,\
    \ element::zero<F>,\n    X, binary_operator::plus<F, X>>;\n\n}  // namespace operator_monoid\n\
    \n}  // namespace algebra\n\n}  // namespace algorithm\n\n\n#line 15 \"algorithm/DataStructure/SegmentTree/lazy_segment_tree.hpp\"\
    \n\nnamespace algorithm {\n\ntemplate <class ActedMonoid, class OperatorMonoid>\n\
    class LazySegmentTreeBase {\npublic:\n    using acted_monoid_type = ActedMonoid;\n\
    \    using operator_monoid_type = OperatorMonoid;\n    using acted_value_type\
    \ = typename acted_monoid_type::value_type;\n    using operator_value_type = typename\
    \ operator_monoid_type::value_type;\n\nprivate:\n    int m_sz;               \
    \                   // m_sz:=(\u8981\u7D20\u6570).\n    int m_n;             \
    \                      // m_n:=(\u5B8C\u5168\u4E8C\u5206\u6728\u306E\u8449\u6570\
    ).\n    int m_depth;                               // m_depth:=(\u5B8C\u5168\u4E8C\
    \u5206\u6728\u306E\u6DF1\u3055).\n    std::vector<acted_monoid_type> m_tree; \
    \    // m_tree(2n)[]:=(\u5B8C\u5168\u4E8C\u5206\u6728). 1-based index.\n    std::vector<operator_monoid_type>\
    \ m_lazy;  // m_lazy(n)[k]:=(m_tree[k]\u306E\u5B50 (m_tree[2k], m_tree[2k+1])\
    \ \u306B\u5BFE\u3059\u308B\u9045\u5EF6\u8A55\u4FA1).\n\n    void apply_with_lazy(int\
    \ k, const operator_monoid_type &f) {\n        m_tree[k] = f.act(m_tree[k]);\n\
    \        if(k < m_n) m_lazy[k] = f * m_lazy[k];\n    }\n    void push(int k) {\n\
    \        apply_with_lazy(k << 1, m_lazy[k]);\n        apply_with_lazy(k << 1 |\
    \ 1, m_lazy[k]);\n        m_lazy[k] = operator_monoid_type::one();\n    }\n  \
    \  void update(int k) { m_tree[k] = m_tree[k << 1] * m_tree[k << 1 | 1]; }\n \
    \   void build() {\n        for(int i = 1; i <= m_depth; ++i) {\n            int\
    \ l = m_n >> i, r = (m_n + m_sz - 1) >> i;\n            for(int j = r; j >= l;\
    \ --j) update(j);\n        }\n    }\n\npublic:\n    // constructor. O(N).\n  \
    \  LazySegmentTreeBase() : LazySegmentTreeBase(0) {}\n    explicit LazySegmentTreeBase(int\
    \ n) : m_sz(n), m_n(1), m_depth(0) {\n        assert(n >= 0);\n        while(m_n\
    \ < m_sz) m_n <<= 1, ++m_depth;\n        m_tree.assign(2 * m_n, acted_monoid_type::one());\n\
    \        m_lazy.assign(m_n, operator_monoid_type::one());\n    }\n    explicit\
    \ LazySegmentTreeBase(int n, const acted_monoid_type &a) : LazySegmentTreeBase(n)\
    \ {\n        std::fill_n(m_tree.begin() + m_n, n, a);\n        build();\n    }\n\
    \    template <std::input_iterator InputIter>\n    explicit LazySegmentTreeBase(InputIter\
    \ first, InputIter last) : m_n(1), m_depth(0), m_tree(first, last) {\n       \
    \ m_sz = m_tree.size();\n        while(m_n < m_sz) m_n <<= 1, ++m_depth;\n   \
    \     m_tree.reserve(2 * m_n);\n        m_tree.insert(m_tree.begin(), m_n, acted_monoid_type::one());\n\
    \        m_tree.resize(2 * m_n, acted_monoid_type::one());\n        m_lazy.resize(m_n,\
    \ operator_monoid_type::one());\n        build();\n    }\n    template <std::ranges::input_range\
    \ R>\n    explicit LazySegmentTreeBase(R &&r) : LazySegmentTreeBase(std::ranges::begin(r),\
    \ std::ranges::end(r)) {}\n    template <typename T>\n    explicit LazySegmentTreeBase(std::initializer_list<T>\
    \ il) : LazySegmentTreeBase(il.begin(), il.end()) {}\n\n    // \u8981\u7D20\u6570\
    \u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int size() const { return m_sz; }\n\
    \    // k\u756A\u76EE\u306E\u8981\u7D20\u3092a\u306B\u7F6E\u304D\u63DB\u3048\u308B\
    \uFF0EO(log N).\n    void set(int k, const acted_monoid_type &a) {\n        assert(0\
    \ <= k and k < size());\n        k += m_n;\n        for(int i = m_depth; i >=\
    \ 1; --i) push(k >> i);\n        m_tree[k] = a;\n        for(int i = 1; i <= m_depth;\
    \ ++i) update(k >> i);\n    }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\u4F5C\
    \u7528\u7D20f\u3092\u7528\u3044\u3066\u66F4\u65B0\u3059\u308B\uFF0EO(log N).\n\
    \    void apply(int k, const operator_monoid_type &f) {\n        assert(0 <= k\
    \ and k < size());\n        k += m_n;\n        for(int i = m_depth; i >= 1; --i)\
    \ push(k >> i);\n        m_tree[k] = f.act(m_tree[k]);\n        for(int i = 1;\
    \ i <= m_depth; ++i) update(k >> i);\n    }\n    // \u533A\u9593[l,r)\u306E\u8981\
    \u7D20\u3092\u4F5C\u7528\u7D20f\u3092\u7528\u3044\u3066\u66F4\u65B0\u3059\u308B\
    \uFF0EO(log N).\n    void apply(int l, int r, const operator_monoid_type &f) {\n\
    \        assert(0 <= l and l <= r and r <= size());\n        if(l == r) return;\n\
    \        l += m_n, r += m_n;\n        for(int i = m_depth; i >= 1; --i) {\n  \
    \          if((l >> i) << i != l) push(l >> i);\n            if((r >> i) << i\
    \ != r) push((r - 1) >> i);\n        }\n        for(int ll = l, rr = r; ll < rr;\
    \ ll >>= 1, rr >>= 1) {\n            if(ll & 1) apply_with_lazy(ll++, f);\n  \
    \          if(rr & 1) apply_with_lazy(--rr, f);\n        }\n        for(int i\
    \ = 1; i <= m_depth; ++i) {\n            if((l >> i) << i != l) update(l >> i);\n\
    \            if((r >> i) << i != r) update((r - 1) >> i);\n        }\n    }\n\
    \    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\u6C42\u3081\u308B\uFF0EO(log N).\n\
    \    acted_monoid_type prod(int k) {\n        assert(0 <= k and k < size());\n\
    \        k += m_n;\n        for(int i = m_depth; i >= 1; --i) push(k >> i);\n\
    \        return m_tree[k];\n    }\n    // \u533A\u9593[l,r)\u306E\u8981\u7D20\u306E\
    \u7DCF\u7A4D\u3092\u6C42\u3081\u308B\uFF0EO(log N).\n    acted_monoid_type prod(int\
    \ l, int r) {\n        assert(0 <= l and l <= r and r <= size());\n        if(l\
    \ == r) return acted_monoid_type::one();\n        l += m_n, r += m_n;\n      \
    \  for(int i = m_depth; i >= 1; --i) {\n            if((l >> i) << i != l) push(l\
    \ >> i);\n            if((r >> i) << i != r) push((r - 1) >> i);\n        }\n\
    \        acted_monoid_type val_l = acted_monoid_type::one(), val_r = acted_monoid_type::one();\n\
    \        for(; l < r; l >>= 1, r >>= 1) {\n            if(l & 1) val_l = val_l\
    \ * m_tree[l++];\n            if(r & 1) val_r = m_tree[--r] * val_r;\n       \
    \ }\n        return val_l * val_r;\n    }\n    // \u533A\u9593\u5168\u4F53\u306E\
    \u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(1).\n    acted_monoid_type\
    \ prod_all() const { return m_tree[1]; }\n    // pred(prod(l,r))==true \u3068\u306A\
    \u308B\u533A\u9593\u306E\u6700\u53F3\u4F4D\u5024r\u3092\u4E8C\u5206\u63A2\u7D22\
    \u3059\u308B\uFF0E\n    // \u305F\u3060\u3057\uFF0C\u533A\u9593[l,n)\u306E\u8981\
    \u7D20\u306Fpred(S)\u306B\u3088\u3063\u3066\u533A\u5206\u5316\u3055\u308C\u3066\
    \u3044\u308B\u3053\u3068\uFF0E\u307E\u305F\uFF0Cpred(e)==true \u3067\u3042\u308B\
    \u3053\u3068\uFF0EO(log N).\n    template <class Pred>\n    int most_right(int\
    \ l, Pred pred) const {\n        static_assert(std::is_invocable_r<bool, Pred,\
    \ acted_monoid_type>::value);\n        assert(0 <= l and l <= size());\n     \
    \   assert(pred(acted_monoid_type::one()));\n        if(l == m_sz) return m_sz;\n\
    \        l += m_n;\n        for(int i = m_depth; i >= 1; --i) push(l >> i);\n\
    \        acted_monoid_type val = acted_monoid_type::one();\n        do {\n   \
    \         while(!(l & 1)) l >>= 1;\n            acted_monoid_type tmp = val *\
    \ m_tree[l];\n            if(!pred(tmp)) {\n                while(l < m_n) {\n\
    \                    push(l);\n                    l <<= 1;\n                \
    \    tmp = val * m_tree[l];\n                    if(pred(tmp)) val = tmp, ++l;\n\
    \                }\n                return l - m_n;\n            }\n         \
    \   val = tmp, ++l;\n        } while((l & -l) != l);\n        return m_sz;\n \
    \   }\n    // pred(prod(l,r))==true \u3068\u306A\u308B\u533A\u9593\u306E\u6700\
    \u5DE6\u4F4D\u5024l\u3092\u4E8C\u5206\u63A2\u7D22\u3059\u308B\uFF0E\n    // \u305F\
    \u3060\u3057\uFF0C\u533A\u9593[0,r)\u306E\u8981\u7D20\u306Fpred(S)\u306B\u3088\
    \u3063\u3066\u533A\u5206\u5316\u3055\u308C\u3066\u3044\u308B\u3053\u3068\uFF0E\
    \u307E\u305F\uFF0Cpred(e)==true \u3067\u3042\u308B\u3053\u3068\uFF0EO(log N).\n\
    \    template <class Pred>\n    int most_left(int r, Pred pred) const {\n    \
    \    static_assert(std::is_invocable_r<bool, Pred, acted_monoid_type>::value);\n\
    \        assert(0 <= r and r <= size());\n        assert(pred(acted_monoid_type::one()));\n\
    \        if(r == 0) return 0;\n        r += m_n;\n        for(int i = m_depth;\
    \ i >= 1; --i) push((r - 1) >> i);\n        acted_monoid_type val = acted_monoid_type::one();\n\
    \        do {\n            --r;\n            while(r > 1 and (r & 1)) r >>= 1;\n\
    \            acted_monoid_type tmp = m_tree[r] * val;\n            if(!pred(tmp))\
    \ {\n                while(r < m_n) {\n                    push(r);\n        \
    \            r = r << 1 | 1;\n                    tmp = m_tree[r] * val;\n   \
    \                 if(pred(tmp)) val = tmp, --r;\n                }\n         \
    \       return r - m_n + 1;\n            }\n            val = tmp;\n        }\
    \ while((r & -r) != r);\n        return 0;\n    }\n    void reset() {\n      \
    \  std::fill(m_tree.begin() + 1, m_tree.end(), acted_monoid_type::one());\n  \
    \      std::fill(m_lazy.begin() + 1, m_lazy.end(), operator_monoid_type::one());\n\
    \    }\n\n    friend std::ostream &operator<<(std::ostream &os, const LazySegmentTreeBase\
    \ &rhs) {\n        os << \"{\\n  [\\n\";\n        for(int i = 0; i <= rhs.m_depth;\
    \ ++i) {\n            int l = 1 << i, r = 2 << i;\n            for(int j = l;\
    \ j < r; ++j) os << (j == l ? \"    [\" : \" \") << rhs.m_tree[j];\n         \
    \   os << \"]\\n\";\n        }\n        os << \"  ],\\n  [\\n\";\n        for(int\
    \ i = 0; i < rhs.m_depth; ++i) {\n            int l = 1 << i, r = 2 << i;\n  \
    \          for(int j = l; j < r; ++j) os << (j == l ? \"    [\" : \" \") << rhs.m_lazy[j];\n\
    \            os << \"]\\n\";\n        }\n        return os << \"  ]\\n}\";\n \
    \   }\n};\n\ntemplate <typename S, typename F, class ActedMonoid, class OperatorMonoid>\n\
    class LazySegmentTree : public LazySegmentTreeBase<ActedMonoid, OperatorMonoid>\
    \ {\npublic:\n    using base_type = LazySegmentTreeBase<ActedMonoid, OperatorMonoid>;\n\
    \    using typename base_type::acted_monoid_type;\n    using typename base_type::operator_monoid_type;\n\
    \    using acted_value_type = S;\n    using operator_value_type = F;\n\n    //\
    \ constructor. O(N).\n    LazySegmentTree() : base_type() {}\n    explicit LazySegmentTree(int\
    \ n) : base_type(n) {}\n    explicit LazySegmentTree(int n, const acted_value_type\
    \ &a) : base_type(n, a) {}\n    template <std::input_iterator InputIter>\n   \
    \ explicit LazySegmentTree(InputIter first, InputIter last) : base_type(first,\
    \ last) {}\n    template <std::ranges::input_range R>\n    explicit LazySegmentTree(R\
    \ &&r) : base_type(std::forward<R>(r)) {}\n    template <typename T>\n    explicit\
    \ LazySegmentTree(std::initializer_list<T> il) : base_type(std::move(il)) {}\n\
    \n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092a\u306B\u7F6E\u304D\u63DB\u3048\u308B\
    \uFF0EO(log N).\n    void set(int k, const acted_value_type &a) { base_type::set(k,\
    \ a); }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\u4F5C\u7528\u7D20f\u3092\
    \u7528\u3044\u3066\u66F4\u65B0\u3059\u308B\uFF0EO(log N).\n    void apply(int\
    \ k, const operator_value_type &f) { base_type::apply(k, f); }\n    // \u533A\u9593\
    [l,r)\u306E\u8981\u7D20\u3092\u4F5C\u7528\u7D20f\u3092\u7528\u3044\u3066\u66F4\
    \u65B0\u3059\u308B\uFF0EO(log N).\n    void apply(int l, int r, const operator_value_type\
    \ &f) { base_type::apply(l, r, f); }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\
    \u6C42\u3081\u308B\uFF0EO(log N).\n    acted_value_type prod(int k) { return base_type::prod(k).value();\
    \ }\n    // \u533A\u9593[l,r)\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\
    \u308B\uFF0EO(log N).\n    acted_value_type prod(int l, int r) { return base_type::prod(l,\
    \ r).value(); }\n    // \u533A\u9593\u5168\u4F53\u306E\u8981\u7D20\u306E\u7DCF\
    \u7A4D\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(1).\n    acted_value_type prod_all()\
    \ const { return base_type::prod_all().value(); }\n    // pred(prod(l,r))==true\
    \ \u3068\u306A\u308B\u533A\u9593\u306E\u6700\u53F3\u4F4D\u5024r\u3092\u4E8C\u5206\
    \u63A2\u7D22\u3059\u308B\uFF0E\n    // \u305F\u3060\u3057\uFF0C\u533A\u9593[l,n)\u306E\
    \u8981\u7D20\u306Fpred(S)\u306B\u3088\u3063\u3066\u533A\u5206\u5316\u3055\u308C\
    \u3066\u3044\u308B\u3053\u3068\uFF0E\u307E\u305F\uFF0Cpred(e)==true \u3067\u3042\
    \u308B\u3053\u3068\uFF0EO(log N).\n    template <typename Pred>\n    int most_right(int\
    \ l, Pred pred) const {\n        static_assert(std::is_invocable_r<bool, Pred,\
    \ acted_value_type>::value);\n        return base_type::most_right(l, [&](const\
    \ acted_monoid_type &x) -> bool { return pred(x.value()); });\n    }\n    // pred(prod(l,r))==true\
    \ \u3068\u306A\u308B\u533A\u9593\u306E\u6700\u5DE6\u4F4D\u5024l\u3092\u4E8C\u5206\
    \u63A2\u7D22\u3059\u308B\uFF0E\n    // \u305F\u3060\u3057\uFF0C\u533A\u9593[0,r)\u306E\
    \u8981\u7D20\u306Fpred(S)\u306B\u3088\u3063\u3066\u533A\u5206\u5316\u3055\u308C\
    \u3066\u3044\u308B\u3053\u3068\uFF0E\u307E\u305F\uFF0Cpred(e)==true \u3067\u3042\
    \u308B\u3053\u3068\uFF0EO(log N).\n    template <typename Pred>\n    int most_left(int\
    \ r, Pred pred) const {\n        static_assert(std::is_invocable_r<bool, Pred,\
    \ acted_value_type>::value);\n        return base_type::most_left(r, [&](const\
    \ acted_monoid_type &x) -> bool { return pred(x.value()); });\n    }\n};\n\ntemplate\
    \ <typename T>\nstruct LengthAwareType {\n    using value_type = T;\n\n    value_type\
    \ val;\n    int len;\n\n    constexpr LengthAwareType() : val(value_type()), len(0)\
    \ {}\n    constexpr LengthAwareType(const value_type &val) : val(val), len(1)\
    \ {}\n    constexpr LengthAwareType(const value_type &val, int len) : val(val),\
    \ len(len) {}\n\n    friend constexpr LengthAwareType operator+(const LengthAwareType\
    \ &lhs, const LengthAwareType &rhs) { return {lhs.val + rhs.val, lhs.len + rhs.len};\
    \ }\n    friend std::ostream &operator<<(std::ostream &os, const LengthAwareType\
    \ &rhs) { return os << \"{\" << rhs.val << \", \" << rhs.len << \"}\"; }\n};\n\
    \ntemplate <typename T, typename S, typename F, class ActedMonoid, class OperatorMonoid>\n\
    class LengthAwareLazySegmentTree : public LazySegmentTree<S, F, ActedMonoid, OperatorMonoid>\
    \ {\npublic:\n    using base_type = LazySegmentTree<S, F, ActedMonoid, OperatorMonoid>;\n\
    \    using typename base_type::acted_monoid_type;\n    using typename base_type::acted_value_type;\n\
    \    using typename base_type::operator_monoid_type;\n    using typename base_type::operator_value_type;\n\
    \    using value_type = T;\n\n    // constructor. O(N).\n    LengthAwareLazySegmentTree()\
    \ : base_type() {}\n    explicit LengthAwareLazySegmentTree(int n) : base_type(n,\
    \ value_type()) {}\n    explicit LengthAwareLazySegmentTree(int n, const value_type\
    \ &a) : base_type(n, a) {}\n    template <std::input_iterator InputIter>\n   \
    \ explicit LengthAwareLazySegmentTree(InputIter first, InputIter last) : LengthAwareLazySegmentTree(std::ranges::subrange(first,\
    \ last)) {}\n    template <std::ranges::input_range R>\n    explicit LengthAwareLazySegmentTree(R\
    \ &&r) : base_type(std::ranges::transform_view(r, [](const auto &x) -> acted_value_type\
    \ { return static_cast<acted_value_type>(x); })) {}\n    template <typename U>\n\
    \    explicit LengthAwareLazySegmentTree(std::initializer_list<U> il) : LengthAwareLazySegmentTree(il.begin(),\
    \ il.end()) {}\n\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092a\u306B\u7F6E\u304D\
    \u63DB\u3048\u308B\uFF0EO(log N).\n    void set(int k, const value_type &a) {\
    \ base_type::set(k, a); }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\u6C42\u3081\
    \u308B\uFF0EO(log N).\n    value_type prod(int k) { return base_type::prod(k).val;\
    \ }\n    // \u533A\u9593[l,r)\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\
    \u308B\uFF0EO(log N).s\n    value_type prod(int l, int r) { return base_type::prod(l,\
    \ r).val; }\n    // \u533A\u9593\u5168\u4F53\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\
    \u3092\u53D6\u5F97\u3059\u308B\uFF0EO(1).\n    value_type prod_all() const { return\
    \ base_type::prod_all().val; }\n    // pred(prod(l,r))==true \u3068\u306A\u308B\
    \u533A\u9593\u306E\u6700\u53F3\u4F4D\u5024r\u3092\u4E8C\u5206\u63A2\u7D22\u3059\
    \u308B\uFF0E\n    // \u305F\u3060\u3057\uFF0C\u533A\u9593[l,n)\u306E\u8981\u7D20\
    \u306Fpred(S)\u306B\u3088\u3063\u3066\u533A\u5206\u5316\u3055\u308C\u3066\u3044\
    \u308B\u3053\u3068\uFF0E\u307E\u305F\uFF0Cpred(e)==true \u3067\u3042\u308B\u3053\
    \u3068\uFF0EO(log N).\n    template <typename Pred>\n    int most_right(int l,\
    \ Pred pred) const {\n        static_assert(std::is_invocable_r<bool, Pred, value_type>::value);\n\
    \        return base_type::most_right(l, [&](const acted_value_type &x) -> bool\
    \ { return pred(x.val); });\n    }\n    // pred(prod(l,r))==true \u3068\u306A\u308B\
    \u533A\u9593\u306E\u6700\u5DE6\u4F4D\u5024l\u3092\u4E8C\u5206\u63A2\u7D22\u3059\
    \u308B\uFF0E\n    // \u305F\u3060\u3057\uFF0C\u533A\u9593[0,r)\u306E\u8981\u7D20\
    \u306Fpred(S)\u306B\u3088\u3063\u3066\u533A\u5206\u5316\u3055\u308C\u3066\u3044\
    \u308B\u3053\u3068\uFF0E\u307E\u305F\uFF0Cpred(e)==true \u3067\u3042\u308B\u3053\
    \u3068\uFF0EO(log N).\n    template <typename Pred>\n    int most_left(int r,\
    \ Pred pred) const {\n        static_assert(std::is_invocable_r<bool, Pred, value_type>::value);\n\
    \        return base_type::most_left(r, [&](const acted_value_type &x) -> bool\
    \ { return pred(x.val); });\n    }\n};\n\nnamespace lazy_segment_tree {\n\nnamespace\
    \ detail {\n\nnamespace range_sum_range_update {\n\ntemplate <typename T>\nusing\
    \ S = LengthAwareType<T>;\n\ntemplate <typename T>\nconstexpr auto e = algebra::element::zero<S<T>>;\n\
    \ntemplate <typename T>\nconstexpr auto op = algebra::binary_operator::plus<S<T>>;\n\
    \ntemplate <typename T>\nusing acted_monoid = algebra::Monoid<S<T>, op<T>, e<T>>;\n\
    \ntemplate <typename F>\nconstexpr auto id = algebra::element::max<F>;\n\ntemplate\
    \ <typename F>\nconstexpr auto compose = algebra::binary_operator::assign_if_not_id<F,\
    \ id<F>>;\n\ntemplate <typename F, typename T = F>\nconstexpr auto mapping = [](const\
    \ F &f, const S<T> &x) -> S<T> { return {(f == id<F>() ? x.val : f * x.len), x.len};\
    \ };\n\ntemplate <typename F, typename T = F>\nusing operator_monoid = algebra::OperatorMonoid<F,\
    \ compose<F>, id<F>, S<T>, mapping<F, T>>;\n\n}  // namespace range_sum_range_update\n\
    \nnamespace range_sum_range_add {\n\ntemplate <typename T>\nusing S = range_sum_range_update::S<T>;\n\
    \ntemplate <typename T>\nconstexpr auto e = range_sum_range_update::e<T>;\n\n\
    template <typename T>\nconstexpr auto op = range_sum_range_update::op<T>;\n\n\
    template <typename T>\nusing acted_monoid = range_sum_range_update::acted_monoid<T>;\n\
    \ntemplate <typename F>\nconstexpr auto id = algebra::element::zero<F>;\n\ntemplate\
    \ <typename F>\nconstexpr auto compose = algebra::binary_operator::plus<F>;\n\n\
    template <typename F, typename T = F>\nconstexpr auto mapping = [](const F &f,\
    \ const S<T> &x) -> S<T> { return {x.val + f * x.len, x.len}; };\n\ntemplate <typename\
    \ F, typename T = F>\nusing operator_monoid = algebra::OperatorMonoid<F, compose<F>,\
    \ id<F>, S<T>, mapping<F, T>>;\n\n}  // namespace range_sum_range_add\n\nnamespace\
    \ range_sum_range_affine {\n\ntemplate <typename T>\nusing S = range_sum_range_update::S<T>;\n\
    \ntemplate <typename T>\nconstexpr auto e = range_sum_range_update::e<T>;\n\n\
    template <typename T>\nconstexpr auto op = range_sum_range_update::op<T>;\n\n\
    template <typename T>\nusing acted_monoid = range_sum_range_update::acted_monoid<T>;\n\
    \ntemplate <typename U>\nstruct F {\n    U a;\n    U b;\n\n    constexpr F() :\
    \ F(U(), U()) {}\n    constexpr F(const U &a, const U &b) : a(a), b(b) {}\n\n\
    \    friend constexpr F operator*(const F &lhs, const F &rhs) { return {lhs.a\
    \ * rhs.a, lhs.a * rhs.b + lhs.b}; }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const F &rhs) { return os << \"{\" << rhs.a << \", \" << rhs.b << \"}\"\
    ; }\n};\n\ntemplate <typename U>\nconstexpr auto id = []() -> F<U> { return {1,\
    \ 0}; };\n\ntemplate <typename U>\nconstexpr auto compose = algebra::binary_operator::mul<F<U>>;\n\
    \ntemplate <typename U, typename T = U>\nconstexpr auto mapping = [](const F<U>\
    \ &f, const S<T> &x) -> S<T> { return {f.a * x.val + f.b * x.len, x.len}; };\n\
    \ntemplate <typename U, typename T = U>\nusing operator_monoid = algebra::OperatorMonoid<F<U>,\
    \ compose<U>, id<U>, S<T>, mapping<U, T>>;\n\n}  // namespace range_sum_range_affine\n\
    \n}  // namespace detail\n\n}  // namespace lazy_segment_tree\n\nusing namespace\
    \ lazy_segment_tree;\n\ntemplate <typename S, typename F = S>\nusing RangeMinimumRangeUpdateLazySegmentTree\
    \ = LazySegmentTree<S, F, algebra::monoid::minimum_safe<S>, algebra::operator_monoid::assign_for_minimum<F,\
    \ S>>;\n\ntemplate <typename S, typename F = S>\nusing RangeMinimumRangeAddLazySegmentTree\
    \ = LazySegmentTree<S, F, algebra::monoid::minimum<S>, algebra::operator_monoid::addition<F,\
    \ S>>;\n\ntemplate <typename S, typename F = S>\nusing RangeMaximumRangeUpdateLazySegmentTree\
    \ = LazySegmentTree<S, F, algebra::monoid::maximum_safe<S>, algebra::operator_monoid::assign_for_maximum<F,\
    \ S>>;\n\ntemplate <typename S, typename F = S>\nusing RangeMaximumRangeAddLazySegmentTree\
    \ = LazySegmentTree<S, F, algebra::monoid::maximum<S>, algebra::operator_monoid::addition<F,\
    \ S>>;\n\ntemplate <typename T, typename F = T>\nusing RangeSumRangeUpdateLazySegmentTree\
    \ = LengthAwareLazySegmentTree<T, detail::range_sum_range_update::S<T>, F, detail::range_sum_range_update::acted_monoid<T>,\
    \ detail::range_sum_range_update::operator_monoid<F, T>>;\n\ntemplate <typename\
    \ T, typename F = T>\nusing RangeSumRangeAddLazySegmentTree = LengthAwareLazySegmentTree<T,\
    \ detail::range_sum_range_add::S<T>, F, detail::range_sum_range_add::acted_monoid<T>,\
    \ detail::range_sum_range_add::operator_monoid<F, T>>;\n\ntemplate <typename T,\
    \ typename U = T>\nusing RangeSumRangeAffineLazySegmentTree = LengthAwareLazySegmentTree<T,\
    \ detail::range_sum_range_affine::S<T>, detail::range_sum_range_affine::F<U>,\
    \ detail::range_sum_range_affine::acted_monoid<T>, detail::range_sum_range_affine::operator_monoid<U,\
    \ T>>;\n\n}  // namespace algorithm\n\n\n#line 1 \"algorithm/Math/ModularArithmetic/modint.hpp\"\
    \n\n\n\n#line 5 \"algorithm/Math/ModularArithmetic/modint.hpp\"\n#include <concepts>\n\
    #include <cstdint>\n#include <functional>\n#line 9 \"algorithm/Math/ModularArithmetic/modint.hpp\"\
    \n\n#line 1 \"algorithm/Math/ModularArithmetic/mod_inv.hpp\"\n\n\n\n#line 8 \"\
    algorithm/Math/ModularArithmetic/mod_inv.hpp\"\n\n#line 1 \"algorithm/Math/ModularArithmetic/modulo.hpp\"\
    \n\n\n\n#line 6 \"algorithm/Math/ModularArithmetic/modulo.hpp\"\n\nnamespace algorithm\
    \ {\n\nnamespace internal {\n\n// return x mod m.\ntemplate <std::unsigned_integral\
    \ Type>\nconstexpr std::uint32_t modulo(Type x, std::uint32_t mod) { return x\
    \ % mod; }\n\n// return x mod m.\ntemplate <std::unsigned_integral Type>\nconstexpr\
    \ std::uint32_t modulo(Type x, std::int32_t mod) { return modulo(x, static_cast<std::uint32_t>(mod));\
    \ }\n\n// return x mod m.\ntemplate <std::signed_integral Type>\nconstexpr std::uint32_t\
    \ modulo(Type x, std::uint32_t mod) {\n    x %= static_cast<std::int64_t>(mod);\n\
    \    if(x < 0) x += static_cast<std::int64_t>(mod);\n    return x;\n}\n\n// return\
    \ x mod m.\ntemplate <std::signed_integral Type>\nconstexpr std::uint32_t modulo(Type\
    \ x, std::int32_t mod) {\n    x %= mod;\n    if(x < 0) x += mod;\n    return x;\n\
    }\n\n}  // namespace internal\n\n}  // namespace algorithm\n\n\n#line 10 \"algorithm/Math/ModularArithmetic/mod_inv.hpp\"\
    \n\nnamespace algorithm {\n\nnamespace internal {\n\n// return pair of (x, g)\
    \ s.t. g=gcd(a,m), ax=g (mod m), 0<=x<m/g.\nconstexpr std::pair<std::uint32_t,\
    \ std::uint32_t> mod_inv(std::uint32_t a, std::uint32_t m) {\n    if(a == 0) return\
    \ {0, m};\n    std::uint32_t s = m, t = a;\n    std::uint32_t u = m, v = 1;\n\
    \    while(true) {\n        std::uint32_t q = s / t;\n        s -= t * q, u -=\
    \ v * q;\n        if(s == 0) return {v, t};\n        q = t / s;\n        t -=\
    \ s * q, v += (m - u) * q;\n        if(t == 0) return {u, s};\n    }\n}\n\n} \
    \ // namespace internal\n\n// \u30E2\u30B8\u30E5\u30E9\u9006\u6570\uFF08\u4E57\
    \u6CD5\u9006\u5143\uFF09\uFF0E\n// a^-1 mod m \u3092\u6C42\u3081\u308B\uFF0E\u89E3\
    \u304C\u5B58\u5728\u3059\u308B\u5FC5\u8981\u5341\u5206\u6761\u4EF6\u306F\uFF0C\
    a\u3068m\u304C\u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\u3053\u3068\uFF0EO(log\
    \ a).\ntemplate <std::integral Type>\nconstexpr std::int64_t mod_inv(Type a, std::int32_t\
    \ m) {\n    assert(m >= 1);\n    auto [x, g] = internal::mod_inv(::algorithm::internal::modulo(a,\
    \ m), m);\n    assert(g == 1);\n    return x;\n}\n\n}  // namespace algorithm\n\
    \n\n#line 1 \"algorithm/Math/ModularArithmetic/mod_pow.hpp\"\n\n\n\n#line 7 \"\
    algorithm/Math/ModularArithmetic/mod_pow.hpp\"\n\n#line 10 \"algorithm/Math/ModularArithmetic/mod_pow.hpp\"\
    \n\nnamespace algorithm {\n\nnamespace internal {\n\n// return n^k mod m.\nconstexpr\
    \ std::uint32_t mod_pow(std::uint64_t n, unsigned long long k, std::uint32_t mod)\
    \ {\n    std::uint64_t res = 1;\n    for(; k > 0; k >>= 1) {\n        if(k & 1ULL)\
    \ res = res * n % mod;\n        n = n * n % mod;\n    }\n    return res;\n}\n\n\
    }  // namespace internal\n\n// \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08\
    mod\u4ED8\u304D\uFF09\uFF0EO(log k).\ntemplate <std::integral Type>\nconstexpr\
    \ std::int64_t mod_pow(Type n, long long k, std::int32_t mod) {\n    assert(mod\
    \ >= 1);\n    auto r = ::algorithm::internal::modulo(n, mod);\n    if(k < 0) {\n\
    \        auto [x, g] = ::algorithm::internal::mod_inv(r, mod);\n        assert(g\
    \ == 1);\n        r = x, k = -k;\n    }\n    return internal::mod_pow(r, k, mod);\n\
    }\n\n}  // namespace algorithm\n\n\n#line 1 \"algorithm/Math/ModularArithmetic/modint_base.hpp\"\
    \n\n\n\n#line 5 \"algorithm/Math/ModularArithmetic/modint_base.hpp\"\n\nnamespace\
    \ algorithm {\n\nclass ModintBase {};\n\ntemplate <typename T>\nusing is_modint\
    \ = std::is_base_of<ModintBase, T>;\n\ntemplate <typename T>\ninline constexpr\
    \ bool is_modint_v = is_modint<T>::value;\n\ntemplate <typename T>\nconcept modint\
    \ = is_modint_v<T>;\n\n}  // namespace algorithm\n\n\n#line 14 \"algorithm/Math/ModularArithmetic/modint.hpp\"\
    \n\nnamespace algorithm {\n\ntemplate <std::int32_t mod>\nclass Modint : public\
    \ ModintBase {\n    static_assert(mod >= 1);\n\n    std::uint32_t val;\n\n   \
    \ static constexpr std::uint32_t umod() { return mod; }\n\npublic:\n    constexpr\
    \ Modint() : val(0) {}\n    template <std::integral Type>\n    constexpr Modint(Type\
    \ val) : val(::algorithm::internal::modulo(val, mod)) {}\n\n    constexpr Modint\
    \ operator+() const { return Modint(*this); }\n    constexpr Modint operator-()\
    \ const {\n        if(val == 0) Modint();\n        return raw(umod() - val);\n\
    \    }\n    constexpr Modint &operator++() {\n        ++val;\n        if(val ==\
    \ umod()) val = 0;\n        return *this;\n    }\n    constexpr Modint &operator--()\
    \ {\n        if(val == 0) val = umod();\n        --val;\n        return *this;\n\
    \    }\n    constexpr Modint operator++(int) {\n        Modint res = *this;\n\
    \        ++(*this);\n        return res;\n    }\n    constexpr Modint operator--(int)\
    \ {\n        Modint res = *this;\n        --(*this);\n        return res;\n  \
    \  }\n    constexpr Modint &operator+=(const Modint &rhs) {\n        if(rhs.val\
    \ >= umod() - val) val -= umod();\n        val += rhs.val;\n        return *this;\n\
    \    }\n    constexpr Modint &operator-=(const Modint &rhs) {\n        if(rhs.val\
    \ > val) val += umod();\n        val -= rhs.val;\n        return *this;\n    }\n\
    \    constexpr Modint &operator*=(const Modint &rhs) {\n        val = static_cast<std::uint64_t>(val)\
    \ * rhs.val % umod();\n        return *this;\n    }\n    constexpr Modint &operator/=(const\
    \ Modint &rhs) { return *this *= rhs.inv(); }\n\n    friend constexpr bool operator==(const\
    \ Modint &lhs, const Modint &rhs) { return lhs.val == rhs.val; }\n    friend constexpr\
    \ Modint operator+(const Modint &lhs, const Modint &rhs) { return Modint(lhs)\
    \ += rhs; }\n    friend constexpr Modint operator-(const Modint &lhs, const Modint\
    \ &rhs) { return Modint(lhs) -= rhs; }\n    friend constexpr Modint operator*(const\
    \ Modint &lhs, const Modint &rhs) { return Modint(lhs) *= rhs; }\n    friend constexpr\
    \ Modint operator/(const Modint &lhs, const Modint &rhs) { return Modint(lhs)\
    \ /= rhs; }\n    friend std::istream &operator>>(std::istream &is, Modint &rhs)\
    \ {\n        std::int64_t val;\n        is >> val;\n        rhs.val = ::algorithm::internal::modulo(val,\
    \ mod);\n        return is;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Modint &rhs) { return os << rhs.val; }\n\n    static constexpr std::int32_t\
    \ modulus() { return mod; }\n    static constexpr Modint raw(std::uint32_t val)\
    \ {\n        Modint res;\n        res.val = val;\n        return res;\n    }\n\
    \n    constexpr std::int64_t value() const { return val; }\n    constexpr Modint\
    \ inv() const {\n        auto [x, g] = ::algorithm::internal::mod_inv(val, umod());\n\
    \        assert(g == 1);\n        return raw(x);\n    }\n    constexpr Modint\
    \ pow(long long k) const {\n        if(k < 0) return raw(::algorithm::internal::mod_pow(val,\
    \ -k, umod())).inv();\n        return raw(::algorithm::internal::mod_pow(val,\
    \ k, umod()));\n    }\n\n    friend constexpr Modint mod_inv(const Modint &a)\
    \ { return a.inv(); }\n    friend constexpr Modint mod_pow(const Modint &a, long\
    \ long k) { return a.pow(k); }\n};\n\nusing mint998244353 = Modint<998'244'353>;\n\
    using mint1000000007 = Modint<1'000'000'007>;\n\n}  // namespace algorithm\n\n\
    template <std::int32_t mod>\nstruct std::hash<algorithm::Modint<mod>> {\n    std::size_t\
    \ operator()(const algorithm::Modint<mod> &ob) const { return ob.value(); }\n\
    };\n\n\n#line 8 \"verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    std::vector<int>\
    \ a(n);\n    for(auto &elem : a) std::cin >> elem;\n\n    algorithm::RangeSumRangeAffineLazySegmentTree<algorithm::mint998244353>\
    \ segtree(a);\n\n    while(q--) {\n        int type;\n        int l, r;\n    \
    \    std::cin >> type >> l >> r;\n\n        if(type == 0) {\n            int b,\
    \ c;\n            std::cin >> b >> c;\n\n            segtree.apply(l, r, {b, c});\n\
    \        } else {\n            auto ans = segtree.prod(l, r);\n            std::cout\
    \ << ans << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../algorithm/DataStructure/SegmentTree/lazy_segment_tree.hpp\"\
    \n#include \"../algorithm/Math/ModularArithmetic/modint.hpp\"\n\nint main() {\n\
    \    int n;\n    int q;\n    std::cin >> n >> q;\n\n    std::vector<int> a(n);\n\
    \    for(auto &elem : a) std::cin >> elem;\n\n    algorithm::RangeSumRangeAffineLazySegmentTree<algorithm::mint998244353>\
    \ segtree(a);\n\n    while(q--) {\n        int type;\n        int l, r;\n    \
    \    std::cin >> type >> l >> r;\n\n        if(type == 0) {\n            int b,\
    \ c;\n            std::cin >> b >> c;\n\n            segtree.apply(l, r, {b, c});\n\
    \        } else {\n            auto ans = segtree.prod(l, r);\n            std::cout\
    \ << ans << \"\\n\";\n        }\n    }\n}\n"
  dependsOn:
  - algorithm/DataStructure/SegmentTree/lazy_segment_tree.hpp
  - algorithm/Math/Algebra/algebra.hpp
  - algorithm/Math/ModularArithmetic/modint.hpp
  - algorithm/Math/ModularArithmetic/mod_inv.hpp
  - algorithm/Math/ModularArithmetic/modulo.hpp
  - algorithm/Math/ModularArithmetic/mod_pow.hpp
  - algorithm/Math/ModularArithmetic/modint_base.hpp
  isVerificationFile: true
  path: verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2025-08-31 12:36:13+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
- /verify/verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp.html
title: verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
---

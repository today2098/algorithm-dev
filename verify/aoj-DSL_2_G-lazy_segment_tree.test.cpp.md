---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/DataStructure/SegmentTree/lazy_segment_tree.hpp
    title: "Lazy Segment Tree\uFF08\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\
      \u30C8\u6728\uFF09"
  - icon: ':heavy_check_mark:'
    path: lib/Math/Algebra/algebra.hpp
    title: "Algebraic Structure\uFF08\u4EE3\u6570\u7684\u69CB\u9020\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
  bundledCode: "#line 1 \"verify/aoj-DSL_2_G-lazy_segment_tree.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\"\
    \n\n#include <iostream>\n\n#line 1 \"lib/DataStructure/SegmentTree/lazy_segment_tree.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <initializer_list>\n\
    #line 8 \"lib/DataStructure/SegmentTree/lazy_segment_tree.hpp\"\n#include <iterator>\n\
    #include <type_traits>\n#include <vector>\n\n#line 1 \"lib/Math/Algebra/algebra.hpp\"\
    \n\n\n\n#line 6 \"lib/Math/Algebra/algebra.hpp\"\n#include <limits>\n#include\
    \ <numeric>\n#line 9 \"lib/Math/Algebra/algebra.hpp\"\n#include <utility>\n\n\
    namespace algorithm {\n\nnamespace algebra {\n\ntemplate <typename S>\nclass Set\
    \ {\npublic:\n    using value_type = S;\n\nprotected:\n    value_type val;\n\n\
    public:\n    constexpr Set() : val() {}\n    constexpr Set(const value_type &val)\
    \ : val(val) {}\n    constexpr Set(value_type &&val) : val(std::move(val)) {}\n\
    \n    friend constexpr bool operator==(const Set &lhs, const Set &rhs) { return\
    \ lhs.val == rhs.val; }\n    friend std::istream &operator>>(std::istream &is,\
    \ Set &rhs) { return is >> rhs.val; }\n    friend std::ostream &operator<<(std::ostream\
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
    \ namespace algorithm\n\n\n#line 13 \"lib/DataStructure/SegmentTree/lazy_segment_tree.hpp\"\
    \n\nnamespace algorithm {\n\nnamespace lazy_segment_tree {\n\ntemplate <class\
    \ ActedMonoid, class OperatorMonoid>\nclass LazySegmentTree {\npublic:\n    using\
    \ acted_monoid_type = ActedMonoid;\n    using operator_monoid_type = OperatorMonoid;\n\
    \    using acted_value_type = acted_monoid_type::value_type;\n    using operator_value_type\
    \ = operator_monoid_type::value_type;\n\nprivate:\n    int m_sz;             \
    \                     // m_sz:=(\u8981\u7D20\u6570).\n    int m_n;           \
    \                        // m_n:=(\u5B8C\u5168\u4E8C\u5206\u6728\u306E\u8449\u6570\
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
    \  LazySegmentTree() : LazySegmentTree(0) {}\n    explicit LazySegmentTree(int\
    \ n) : m_sz(n), m_n(1), m_depth(0) {\n        assert(n >= 0);\n        while(m_n\
    \ < m_sz) m_n <<= 1, ++m_depth;\n        m_tree.assign(2 * m_n, acted_monoid_type::one());\n\
    \        m_lazy.assign(m_n, operator_monoid_type::one());\n    }\n    explicit\
    \ LazySegmentTree(int n, const acted_value_type &a) : LazySegmentTree(n, acted_monoid_type(a))\
    \ {}\n    explicit LazySegmentTree(int n, const acted_monoid_type &a) : LazySegmentTree(n)\
    \ {\n        std::fill_n(m_tree.begin() + m_n, n, a);\n        build();\n    }\n\
    \    template <std::input_iterator InputIter>\n    explicit LazySegmentTree(InputIter\
    \ first, InputIter last) : m_n(1), m_depth(0), m_tree(first, last) {\n       \
    \ m_sz = m_tree.size();\n        while(m_n < m_sz) m_n <<= 1, ++m_depth;\n   \
    \     m_tree.reserve(2 * m_n);\n        m_tree.insert(m_tree.begin(), m_n, acted_monoid_type::one());\n\
    \        m_tree.resize(2 * m_n, acted_monoid_type::one());\n        m_lazy.resize(m_n,\
    \ operator_monoid_type::one());\n        build();\n    }\n    template <typename\
    \ T>\n    explicit LazySegmentTree(std::initializer_list<T> il) : LazySegmentTree(il.begin(),\
    \ il.end()) {}\n\n    // \u8981\u7D20\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\
    \n    int size() const { return m_sz; }\n    // k\u756A\u76EE\u306E\u8981\u7D20\
    \u3092a\u306B\u7F6E\u304D\u63DB\u3048\u308B\uFF0EO(log N).\n    void set(int k,\
    \ const acted_value_type &a) { set(k, acted_monoid_type(a)); }\n    void set(int\
    \ k, const acted_monoid_type &a) {\n        assert(0 <= k and k < size());\n \
    \       k += m_n;\n        for(int i = m_depth; i >= 1; --i) push(k >> i);\n \
    \       m_tree[k] = a;\n        for(int i = 1; i <= m_depth; ++i) update(k >>\
    \ i);\n    }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\u4F5C\u7528\u7D20f\u3092\
    \u7528\u3044\u3066\u66F4\u65B0\u3059\u308B\uFF0EO(log N).\n    void apply(int\
    \ k, const operator_value_type &f) { apply(k, operator_monoid_type(f)); }\n  \
    \  void apply(int k, const operator_monoid_type &f) {\n        assert(0 <= k and\
    \ k < size());\n        k += m_n;\n        for(int i = m_depth; i >= 1; --i) push(k\
    \ >> i);\n        m_tree[k] = f.act(m_tree[k]);\n        for(int i = 1; i <= m_depth;\
    \ ++i) update(k >> i);\n    }\n    // \u533A\u9593[l,r)\u306E\u8981\u7D20\u3092\
    \u4F5C\u7528\u7D20f\u3092\u7528\u3044\u3066\u66F4\u65B0\u3059\u308B\uFF0EO(log\
    \ N).\n    void apply(int l, int r, const operator_value_type &f) { apply(l, r,\
    \ operator_monoid_type(f)); }\n    void apply(int l, int r, const operator_monoid_type\
    \ &f) {\n        assert(0 <= l and l <= r and r <= size());\n        if(l == r)\
    \ return;\n        l += m_n, r += m_n;\n        for(int i = m_depth; i >= 1; --i)\
    \ {\n            if((l >> i) << i != l) push(l >> i);\n            if((r >> i)\
    \ << i != r) push((r - 1) >> i);\n        }\n        for(int ll = l, rr = r; ll\
    \ < rr; ll >>= 1, rr >>= 1) {\n            if(ll & 1) apply_with_lazy(ll++, f);\n\
    \            if(rr & 1) apply_with_lazy(--rr, f);\n        }\n        for(int\
    \ i = 1; i <= m_depth; ++i) {\n            if((l >> i) << i != l) update(l >>\
    \ i);\n            if((r >> i) << i != r) update((r - 1) >> i);\n        }\n \
    \   }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\u6C42\u3081\u308B\uFF0EO(log\
    \ N).\n    acted_value_type prod(int k) {\n        assert(0 <= k and k < size());\n\
    \        k += m_n;\n        for(int i = m_depth; i >= 1; --i) push(k >> i);\n\
    \        return m_tree[k].value();\n    }\n    // \u533A\u9593[l,r)\u306E\u8981\
    \u7D20\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\u308B\uFF0EO(log N).\n    acted_value_type\
    \ prod(int l, int r) {\n        assert(0 <= l and l <= r and r <= size());\n \
    \       if(l == r) return acted_monoid_type::one().value();\n        l += m_n,\
    \ r += m_n;\n        for(int i = m_depth; i >= 1; --i) {\n            if((l >>\
    \ i) << i != l) push(l >> i);\n            if((r >> i) << i != r) push((r - 1)\
    \ >> i);\n        }\n        acted_monoid_type &&val_l = acted_monoid_type::one(),\
    \ &&val_r = acted_monoid_type::one();\n        for(; l < r; l >>= 1, r >>= 1)\
    \ {\n            if(l & 1) val_l = val_l * m_tree[l++];\n            if(r & 1)\
    \ val_r = m_tree[--r] * val_r;\n        }\n        return (val_l * val_r).value();\n\
    \    }\n    // \u533A\u9593\u5168\u4F53\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\
    \u53D6\u5F97\u3059\u308B\uFF0EO(1).\n    acted_value_type prod_all() const { return\
    \ m_tree[1].value(); }\n    // pred(prod(l,r))==true \u3068\u306A\u308B\u533A\u9593\
    \u306E\u6700\u53F3\u4F4D\u5024r\u3092\u4E8C\u5206\u63A2\u7D22\u3059\u308B\uFF0E\
    \n    // \u305F\u3060\u3057\uFF0C\u533A\u9593[l,n)\u306E\u8981\u7D20\u306Fpred(S)\u306B\
    \u3088\u3063\u3066\u533A\u5206\u5316\u3055\u308C\u3066\u3044\u308B\u3053\u3068\
    \uFF0E\u307E\u305F\uFF0Cpred(e)==true \u3067\u3042\u308B\u3053\u3068\uFF0EO(log\
    \ N).\n    template <bool (*pred)(acted_value_type)>\n    int most_right(int l)\
    \ const {\n        return most_right(l, [](const acted_value_type &x) -> bool\
    \ { return pred(x); });\n    }\n    template <class Pred>\n    int most_right(int\
    \ l, Pred pred) const {\n        static_assert(std::is_invocable_r<bool, Pred,\
    \ acted_value_type>::value);\n        assert(0 <= l and l <= size());\n      \
    \  assert(pred(acted_monoid_type::one().value()));\n        if(l == m_sz) return\
    \ m_sz;\n        l += m_n;\n        for(int i = m_depth; i >= 1; --i) push(l >>\
    \ i);\n        acted_monoid_type &&val = acted_monoid_type::one();\n        do\
    \ {\n            while(!(l & 1)) l >>= 1;\n            acted_monoid_type &&tmp\
    \ = val * m_tree[l];\n            if(!pred(tmp.value())) {\n                while(l\
    \ < m_n) {\n                    push(l);\n                    l <<= 1;\n     \
    \               tmp = val * m_tree[l];\n                    if(pred(tmp.value()))\
    \ val = tmp, ++l;\n                }\n                return l - m_n;\n      \
    \      }\n            val = tmp, ++l;\n        } while((l & -l) != l);\n     \
    \   return m_sz;\n    }\n    // pred(prod(l,r))==true \u3068\u306A\u308B\u533A\
    \u9593\u306E\u6700\u5DE6\u4F4D\u5024l\u3092\u4E8C\u5206\u63A2\u7D22\u3059\u308B\
    \uFF0E\n    // \u305F\u3060\u3057\uFF0C\u533A\u9593[0,r)\u306E\u8981\u7D20\u306F\
    pred(S)\u306B\u3088\u3063\u3066\u533A\u5206\u5316\u3055\u308C\u3066\u3044\u308B\
    \u3053\u3068\uFF0E\u307E\u305F\uFF0Cpred(e)==true \u3067\u3042\u308B\u3053\u3068\
    \uFF0EO(log N).\n    template <bool (*pred)(acted_value_type)>\n    int most_left(int\
    \ r) const {\n        return most_left(r, [](const acted_value_type &x) -> bool\
    \ { return pred(x); });\n    }\n    template <class Pred>\n    int most_left(int\
    \ r, Pred pred) const {\n        static_assert(std::is_invocable_r<bool, Pred,\
    \ acted_value_type>::value);\n        assert(0 <= r and r <= size());\n      \
    \  assert(pred(acted_monoid_type::one().value()));\n        if(r == 0) return\
    \ 0;\n        r += m_n;\n        for(int i = m_depth; i >= 1; --i) push((r - 1)\
    \ >> i);\n        acted_monoid_type &&val = acted_monoid_type::one();\n      \
    \  do {\n            --r;\n            while(r > 1 and (r & 1)) r >>= 1;\n   \
    \         acted_monoid_type &&tmp = m_tree[r] * val;\n            if(!pred(tmp.value()))\
    \ {\n                while(r < m_n) {\n                    push(r);\n        \
    \            r = r << 1 | 1;\n                    tmp = m_tree[r] * val;\n   \
    \                 if(pred(tmp.value())) val = tmp, --r;\n                }\n \
    \               return r - m_n + 1;\n            }\n            val = tmp;\n \
    \       } while((r & -r) != r);\n        return 0;\n    }\n    void reset() {\n\
    \        std::fill(m_tree.begin() + 1, m_tree.end(), acted_monoid_type::one());\n\
    \        std::fill(m_lazy.begin() + 1, m_lazy.end(), operator_monoid_type::one());\n\
    \    }\n\n    friend std::ostream &operator<<(std::ostream &os, const LazySegmentTree\
    \ &rhs) {\n        os << \"{\\n  [\\n\";\n        for(int i = 0; i <= rhs.m_depth;\
    \ ++i) {\n            int l = 1 << i, r = 2 << i;\n            for(int j = l;\
    \ j < r; ++j) os << (j == l ? \"    [\" : \" \") << rhs.m_tree[j].value();\n \
    \           os << \"]\\n\";\n        }\n        os << \"  ],\\n  [\\n\";\n   \
    \     for(int i = 0; i < rhs.m_depth; ++i) {\n            int l = 1 << i, r =\
    \ 2 << i;\n            for(int j = l; j < r; ++j) os << (j == l ? \"    [\" :\
    \ \" \") << rhs.m_lazy[j].value();\n            os << \"]\\n\";\n        }\n \
    \       return os << \"  ]\\n}\";\n    }\n};\n\nnamespace internal {\n\nnamespace\
    \ range_sum_range_update {\n\ntemplate <typename T>\nstruct S {\n    T val;\n\
    \    int size;\n\n    constexpr S() : S(T(), 0) {}\n    constexpr S(const T &val)\
    \ : S(val, 1) {}\n    constexpr S(const T &val, int size) : val(val), size(size)\
    \ {}\n\n    friend constexpr S operator+(const S &lhs, const S &rhs) { return\
    \ {lhs.val + rhs.val, lhs.size + rhs.size}; }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const S &rhs) { return os << \"{\" << rhs.val << \", \" << rhs.size <<\
    \ \"}\"; }\n};\n\ntemplate <typename T>\nusing acted_monoid = algebra::Monoid<S<T>,\
    \ algebra::boperator::plus<S<T>>, algebra::element::zero<S<T>>>;\n\ntemplate <typename\
    \ F>\nconstexpr auto id = algebra::element::max<F>;\n\ntemplate <typename F>\n\
    constexpr auto compose = algebra::boperator::assign_if_not_id<F, id<F>>;\n\ntemplate\
    \ <typename F, typename T = F>\nconstexpr auto mapping = [](const F &f, const\
    \ S<T> &x) -> S<T> {\n    static_assert(std::is_invocable_r<F, decltype(id<F>)>::value);\n\
    \    return {(f == id<F>() ? x.val : f * x.size), x.size};\n};\n\ntemplate <typename\
    \ F, typename T = F>\nusing operator_monoid = algebra::OperatorMonoid<F, compose<F>,\
    \ id<F>, S<T>, mapping<F, T>>;\n\n}  // namespace range_sum_range_update\n\nnamespace\
    \ range_sum_range_add {\n\ntemplate <typename T>\nusing S = range_sum_range_update::S<T>;\n\
    \ntemplate <typename T>\nusing acted_monoid = range_sum_range_update::acted_monoid<T>;\n\
    \ntemplate <typename F>\nconstexpr auto id = algebra::element::zero<F>;\n\ntemplate\
    \ <typename F>\nconstexpr auto compose = algebra::boperator::plus<F>;\n\ntemplate\
    \ <typename F, typename T = F>\nconstexpr auto mapping = [](const F &f, const\
    \ S<T> &x) -> S<T> { return {x.val + f * x.size, x.size}; };\n\ntemplate <typename\
    \ F, typename T = F>\nusing operator_monoid = algebra::OperatorMonoid<F, compose<F>,\
    \ id<F>, S<T>, mapping<F, T>>;\n\n}  // namespace range_sum_range_add\n\nnamespace\
    \ range_sum_range_affine {\n\ntemplate <typename T>\nusing S = range_sum_range_update::S<T>;\n\
    \ntemplate <typename T>\nusing acted_monoid = range_sum_range_update::acted_monoid<T>;\n\
    \ntemplate <typename U>\nstruct F {\n    U a;\n    U b;\n\n    constexpr F() :\
    \ F(U(), U()) {}\n    constexpr F(const U &a, const U &b) : a(a), b(b) {}\n\n\
    \    friend constexpr F operator*(const F &lhs, const F &rhs) { return {lhs.a\
    \ * rhs.a, lhs.a * rhs.b + lhs.b}; }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const F &rhs) { return os << \"{\" << rhs.a << \", \" << rhs.b << \"}\"\
    ; }\n};\n\ntemplate <typename U>\nconstexpr auto id = []() -> F<U> { return {1,\
    \ 0}; };\n\ntemplate <typename U>\nconstexpr auto compose = algebra::boperator::mul<F<U>>;\n\
    \ntemplate <typename U, typename T = U>\nconstexpr auto mapping = [](const F<U>\
    \ &f, const S<T> &x) -> S<T> { return {f.a * x.val + f.b * x.size, x.size}; };\n\
    \ntemplate <typename U, typename T = U>\nusing operator_monoid = algebra::OperatorMonoid<F<U>,\
    \ compose<U>, id<U>, S<T>, mapping<U, T>>;\n\n}  // namespace range_sum_range_affine\n\
    \n}  // namespace internal\n\ntemplate <typename S, typename F = S>\nusing range_minimum_range_update_lazy_segment_tree\
    \ = LazySegmentTree<algebra::monoid::minimum_safe<S>, algebra::operator_monoid::assign_for_minimum<F,\
    \ S>>;\n\ntemplate <typename S, typename F = S>\nusing range_minimum_range_add_lazy_segment_tree\
    \ = LazySegmentTree<algebra::monoid::minimum<S>, algebra::operator_monoid::addition<F,\
    \ S>>;\n\ntemplate <typename S, typename F = S>\nusing range_maximum_range_update_lazy_segment_tree\
    \ = LazySegmentTree<algebra::monoid::maximum_safe<S>, algebra::operator_monoid::assign_for_maximum<F,\
    \ S>>;\n\ntemplate <typename S, typename F = S>\nusing range_maximum_range_add_lazy_segment_tree\
    \ = LazySegmentTree<algebra::monoid::maximum<S>, algebra::operator_monoid::addition<F,\
    \ S>>;\n\ntemplate <typename T, typename F = T>\nusing range_sum_range_update_lazy_segment_tree\
    \ = LazySegmentTree<internal::range_sum_range_update::acted_monoid<T>, internal::range_sum_range_update::operator_monoid<F,\
    \ T>>;\n\ntemplate <typename T, typename F = T>\nusing range_sum_range_add_lazy_segment_tree\
    \ = LazySegmentTree<internal::range_sum_range_add::acted_monoid<T>, internal::range_sum_range_add::operator_monoid<F,\
    \ T>>;\n\ntemplate <typename T, typename U = T>\nusing range_sum_range_affine_lazy_segment_tree\
    \ = LazySegmentTree<internal::range_sum_range_affine::acted_monoid<T>, internal::range_sum_range_affine::operator_monoid<U,\
    \ T>>;\n\n}  // namespace lazy_segment_tree\n\n}  // namespace algorithm\n\n\n\
    #line 6 \"verify/aoj-DSL_2_G-lazy_segment_tree.test.cpp\"\n\nint main() {\n  \
    \  int n;\n    int q;\n    std::cin >> n >> q;\n\n    algorithm::lazy_segment_tree::range_sum_range_add_lazy_segment_tree<long\
    \ long> segtree(n, {0, 1});\n\n    while(q--) {\n        int type;\n        std::cin\
    \ >> type;\n\n        if(type == 0) {\n            int s, t;\n            long\
    \ long x;\n            std::cin >> s >> t >> x;\n            --s;\n\n        \
    \    segtree.apply(s, t, x);\n        } else {\n            int s, t;\n      \
    \      std::cin >> s >> t;\n            --s;\n\n            auto &&ans = segtree.prod(s,\
    \ t).val;\n            std::cout << ans << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\"\
    \n\n#include <iostream>\n\n#include \"../lib/DataStructure/SegmentTree/lazy_segment_tree.hpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    algorithm::lazy_segment_tree::range_sum_range_add_lazy_segment_tree<long\
    \ long> segtree(n, {0, 1});\n\n    while(q--) {\n        int type;\n        std::cin\
    \ >> type;\n\n        if(type == 0) {\n            int s, t;\n            long\
    \ long x;\n            std::cin >> s >> t >> x;\n            --s;\n\n        \
    \    segtree.apply(s, t, x);\n        } else {\n            int s, t;\n      \
    \      std::cin >> s >> t;\n            --s;\n\n            auto &&ans = segtree.prod(s,\
    \ t).val;\n            std::cout << ans << \"\\n\";\n        }\n    }\n}\n"
  dependsOn:
  - lib/DataStructure/SegmentTree/lazy_segment_tree.hpp
  - lib/Math/Algebra/algebra.hpp
  isVerificationFile: true
  path: verify/aoj-DSL_2_G-lazy_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2025-06-14 20:38:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-DSL_2_G-lazy_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-DSL_2_G-lazy_segment_tree.test.cpp
- /verify/verify/aoj-DSL_2_G-lazy_segment_tree.test.cpp.html
title: verify/aoj-DSL_2_G-lazy_segment_tree.test.cpp
---

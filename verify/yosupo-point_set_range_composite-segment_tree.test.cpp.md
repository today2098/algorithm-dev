---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/DataStructure/SegmentTree/segment_tree.hpp
    title: Segment Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"verify/yosupo-point_set_range_composite-segment_tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <iostream>\n\n#line 1 \"algorithm/DataStructure/SegmentTree/segment_tree.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <initializer_list>\n\
    #line 8 \"algorithm/DataStructure/SegmentTree/segment_tree.hpp\"\n#include <iterator>\n\
    #include <ranges>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\
    \n#line 1 \"algorithm/Math/Algebra/algebra.hpp\"\n\n\n\n#line 6 \"algorithm/Math/Algebra/algebra.hpp\"\
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
    \n}  // namespace algebra\n\n}  // namespace algorithm\n\n\n#line 15 \"algorithm/DataStructure/SegmentTree/segment_tree.hpp\"\
    \n\nnamespace algorithm {\n\ntemplate <class Monoid>\nclass SegmentTreeBase {\n\
    public:\n    using monoid_type = Monoid;\n\nprivate:\n    int m_sz;          \
    \               // m_sz:=(\u8981\u7D20\u6570).\n    int m_n;                 \
    \         // m_n:=(\u5B8C\u5168\u4E8C\u5206\u6728\u306E\u8449\u6570).\n    std::vector<monoid_type>\
    \ m_tree;  // m_tree(2n)[]:=(\u5B8C\u5168\u4E8C\u5206\u6728). 1-based index.\n\
    \n    void update(int k) { m_tree[k] = m_tree[k << 1] * m_tree[k << 1 | 1]; }\n\
    \    void build() {\n        for(int l = m_n >> 1, r = (m_n + m_sz - 1) >> 1;\
    \ l >= 1; l >>= 1, r >>= 1) {\n            for(int i = r; i >= l; --i) update(i);\n\
    \        }\n    }\n\npublic:\n    // constructor. O(N).\n    SegmentTreeBase()\
    \ : SegmentTreeBase(0) {};\n    explicit SegmentTreeBase(int n) : m_sz(n), m_n(1)\
    \ {\n        assert(n >= 0);\n        while(m_n < m_sz) m_n <<= 1;\n        m_tree.assign(2\
    \ * m_n, monoid_type::one());\n    }\n    explicit SegmentTreeBase(int n, const\
    \ monoid_type &a) : SegmentTreeBase(n) {\n        std::fill_n(m_tree.begin() +\
    \ m_n, n, a);\n        build();\n    }\n    template <std::input_iterator InputIter>\n\
    \    explicit SegmentTreeBase(InputIter first, InputIter last) : m_n(1), m_tree(first,\
    \ last) {\n        m_sz = m_tree.size();\n        while(m_n < m_sz) m_n <<= 1;\n\
    \        m_tree.reserve(2 * m_n);\n        m_tree.insert(m_tree.begin(), m_n,\
    \ monoid_type::one());\n        m_tree.resize(2 * m_n, monoid_type::one());\n\
    \        build();\n    }\n    template <std::ranges::input_range R>\n    explicit\
    \ SegmentTreeBase(R &&r) : SegmentTreeBase(std::ranges::begin(r), std::ranges::end(r))\
    \ {}\n    template <typename T>\n    explicit SegmentTreeBase(std::initializer_list<T>\
    \ il) : SegmentTreeBase(il.begin(), il.end()) {}\n\n    // \u8981\u7D20\u6570\u3092\
    \u53D6\u5F97\u3059\u308B\uFF0E\n    int size() const { return m_sz; }\n    //\
    \ k\u756A\u76EE\u306E\u8981\u7D20\u3092a\u306B\u7F6E\u304D\u63DB\u3048\u308B\uFF0E\
    O(log N).\n    void set(int k, const monoid_type &a) {\n        assert(0 <= k\
    \ and k < size());\n        k += m_n;\n        m_tree[k] = a;\n        while(k\
    \ >>= 1) update(k);\n    }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\
    \u5F97\u3059\u308B\uFF0EO(1).\n    monoid_type prod(int k) const {\n        assert(0\
    \ <= k and k < size());\n        return m_tree[k + m_n];\n    }\n    // \u533A\
    \u9593[l,r)\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\u308B\uFF0E\
    O(log N).\n    monoid_type prod(int l, int r) const {\n        assert(0 <= l and\
    \ l <= r and r <= size());\n        monoid_type val_l = monoid_type::one(), val_r\
    \ = monoid_type::one();\n        for(l += m_n, r += m_n; l < r; l >>= 1, r >>=\
    \ 1) {\n            if(l & 1) val_l = val_l * m_tree[l++];\n            if(r &\
    \ 1) val_r = m_tree[--r] * val_r;\n        }\n        return val_l * val_r;\n\
    \    }\n    // \u533A\u9593\u5168\u4F53\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\
    \u53D6\u5F97\u3059\u308B\uFF0EO(1).\n    monoid_type prod_all() const { return\
    \ m_tree[1]; }\n    // pred(prod(l,r))==true \u3068\u306A\u308B\u533A\u9593\u306E\
    \u6700\u53F3\u4F4D\u5024r\u3092\u4E8C\u5206\u63A2\u7D22\u3059\u308B\uFF0E\n  \
    \  // \u305F\u3060\u3057\uFF0C\u533A\u9593[l,n)\u306E\u8981\u7D20\u306Fpred(S)\u306B\
    \u3088\u3063\u3066\u533A\u5206\u5316\u3055\u308C\u3066\u3044\u308B\u3053\u3068\
    \uFF0E\u307E\u305F\uFF0Cpred(e)==true \u3067\u3042\u308B\u3053\u3068\uFF0EO(log\
    \ N).\n    template <typename Pred>\n    int most_right(int l, Pred pred) const\
    \ {\n        static_assert(std::is_invocable_r<bool, Pred, monoid_type>::value);\n\
    \        assert(0 <= l and l <= size());\n        assert(pred(monoid_type::one()));\n\
    \        if(l == m_sz) return m_sz;\n        l += m_n;\n        monoid_type val\
    \ = monoid_type::one();\n        do {\n            while(!(l & 1)) l >>= 1;\n\
    \            monoid_type tmp = val * m_tree[l];\n            if(!pred(tmp)) {\n\
    \                while(l < m_n) {\n                    l <<= 1;\n            \
    \        tmp = val * m_tree[l];\n                    if(pred(tmp)) val = tmp,\
    \ ++l;\n                }\n                return l - m_n;\n            }\n  \
    \          val = tmp, ++l;\n        } while((l & -l) != l);\n        return m_sz;\n\
    \    }\n    // pred(prod(l,r))==true \u3068\u306A\u308B\u533A\u9593\u306E\u6700\
    \u5DE6\u4F4D\u5024l\u3092\u4E8C\u5206\u63A2\u7D22\u3059\u308B\uFF0E\n    // \u305F\
    \u3060\u3057\uFF0C\u533A\u9593[0,r)\u306E\u8981\u7D20\u306Fpred(S)\u306B\u3088\
    \u3063\u3066\u533A\u5206\u5316\u3055\u308C\u3066\u3044\u308B\u3053\u3068\uFF0E\
    \u307E\u305F\uFF0Cpred(e)==true \u3067\u3042\u308B\u3053\u3068\uFF0EO(log N).\n\
    \    template <typename Pred>\n    int most_left(int r, Pred pred) const {\n \
    \       static_assert(std::is_invocable_r<bool, Pred, monoid_type>::value);\n\
    \        assert(0 <= r and r <= size());\n        assert(pred(monoid_type::one()));\n\
    \        if(r == 0) return 0;\n        r += m_n;\n        monoid_type val = monoid_type::one();\n\
    \        do {\n            --r;\n            while(r > 1 and (r & 1)) r >>= 1;\n\
    \            monoid_type tmp = m_tree[r] * val;\n            if(!pred(tmp)) {\n\
    \                while(r < m_n) {\n                    r = r << 1 | 1;\n     \
    \               tmp = m_tree[r] * val;\n                    if(pred(tmp)) val\
    \ = tmp, --r;\n                }\n                return r + 1 - m_n;\n      \
    \      }\n            val = tmp;\n        } while((r & -r) != r);\n        return\
    \ 0;\n    }\n    void reset() { std::fill(m_tree.begin() + 1, m_tree.begin() +\
    \ m_n + m_sz, monoid_type::one()); }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const SegmentTreeBase &rhs) {\n        os << \"[\\n\";\n        for(int\
    \ l = 1, r = 2; r <= 2 * rhs.m_n; l <<= 1, r <<= 1) {\n            for(int i =\
    \ l; i < r; ++i) os << (i == l ? \"  [\" : \" \") << rhs.m_tree[i];\n        \
    \    os << \"]\\n\";\n        }\n        return os << \"]\";\n    }\n};\n\ntemplate\
    \ <typename S, class Monoid>\nclass SegmentTree : public SegmentTreeBase<Monoid>\
    \ {\npublic:\n    using base_type = SegmentTreeBase<Monoid>;\n    using typename\
    \ base_type::monoid_type;\n    using value_type = S;\n\n    // constructor. O(N).\n\
    \    SegmentTree() : base_type() {};\n    explicit SegmentTree(int n) : base_type(n)\
    \ {}\n    explicit SegmentTree(int n, const value_type &a) : base_type(n, a) {}\n\
    \    template <std::input_iterator InputIter>\n    explicit SegmentTree(InputIter\
    \ first, InputIter last) : base_type(first, last) {}\n    template <std::ranges::input_range\
    \ R>\n    explicit SegmentTree(R &&r) : base_type(std::forward<R>(r)) {}\n   \
    \ template <typename T>\n    explicit SegmentTree(std::initializer_list<T> il)\
    \ : base_type(std::move(il)) {}\n\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\
    a\u306B\u7F6E\u304D\u63DB\u3048\u308B\uFF0EO(log N).\n    void set(int k, const\
    \ value_type &a) { base_type::set(k, a); }\n    // k\u756A\u76EE\u306E\u8981\u7D20\
    \u3092\u53D6\u5F97\u3059\u308B\uFF0EO(1).\n    value_type prod(int k) const {\
    \ return base_type::prod(k).value(); }\n    // \u533A\u9593[l,r)\u306E\u8981\u7D20\
    \u306E\u7DCF\u7A4D\u3092\u6C42\u3081\u308B\uFF0EO(log N).\n    value_type prod(int\
    \ l, int r) const { return base_type::prod(l, r).value(); }\n    // \u533A\u9593\
    \u5168\u4F53\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u53D6\u5F97\u3059\u308B\
    \uFF0EO(1).\n    value_type prod_all() const { return base_type::prod_all().value();\
    \ }\n    // pred(prod(l,r))==true \u3068\u306A\u308B\u533A\u9593\u306E\u6700\u53F3\
    \u4F4D\u5024r\u3092\u4E8C\u5206\u63A2\u7D22\u3059\u308B\uFF0E\n    // \u305F\u3060\
    \u3057\uFF0C\u533A\u9593[l,n)\u306E\u8981\u7D20\u306Fpred(S)\u306B\u3088\u3063\
    \u3066\u533A\u5206\u5316\u3055\u308C\u3066\u3044\u308B\u3053\u3068\uFF0E\u307E\
    \u305F\uFF0Cpred(e)==true \u3067\u3042\u308B\u3053\u3068\uFF0EO(log N).\n    template\
    \ <typename Pred>\n    int most_right(int l, Pred pred) const {\n        static_assert(std::is_invocable_r<bool,\
    \ Pred, value_type>::value);\n        return base_type::most_right(l, [&](const\
    \ monoid_type &x) -> bool { return pred(x.value()); });\n    }\n    // pred(prod(l,r))==true\
    \ \u3068\u306A\u308B\u533A\u9593\u306E\u6700\u5DE6\u4F4D\u5024l\u3092\u4E8C\u5206\
    \u63A2\u7D22\u3059\u308B\uFF0E\n    // \u305F\u3060\u3057\uFF0C\u533A\u9593[0,r)\u306E\
    \u8981\u7D20\u306Fpred(S)\u306B\u3088\u3063\u3066\u533A\u5206\u5316\u3055\u308C\
    \u3066\u3044\u308B\u3053\u3068\uFF0E\u307E\u305F\uFF0Cpred(e)==true \u3067\u3042\
    \u308B\u3053\u3068\uFF0EO(log N).\n    template <typename Pred>\n    int most_left(int\
    \ r, Pred pred) const {\n        static_assert(std::is_invocable_r<bool, Pred,\
    \ value_type>::value);\n        return base_type::most_left(r, [&](const monoid_type\
    \ &x) -> bool { return pred(x.value()); });\n    }\n};\n\ntemplate <typename S>\n\
    using RangeMinimumSegmentTree = SegmentTree<S, algebra::monoid::minimum<S>>;\n\
    \ntemplate <typename S>\nusing RangeMaximumSegmentTree = SegmentTree<S, algebra::monoid::maximum<S>>;\n\
    \ntemplate <typename S>\nusing RangeSumSegmentTree = SegmentTree<S, algebra::monoid::addition<S>>;\n\
    \ntemplate <typename S>\nusing RangeProductSegmentTree = SegmentTree<S, algebra::monoid::multiplication<S>>;\n\
    \n}  // namespace algorithm\n\n\n#line 1 \"algorithm/Math/ModularArithmetic/modint.hpp\"\
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
    };\n\n\n#line 7 \"verify/yosupo-point_set_range_composite-segment_tree.test.cpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    using\
    \ S = struct {\n        algorithm::mint998244353 a;\n        algorithm::mint998244353\
    \ b;\n    };\n    auto mapping = [](const S &f, algorithm::mint998244353 x) ->\
    \ algorithm::mint998244353 {\n        return f.a * x + f.b;\n    };\n\n    std::vector<S>\
    \ v(n);\n    for(auto &elem : v) std::cin >> elem.a >> elem.b;\n\n    constexpr\
    \ auto op = [](const S &lhs, const S &rhs) -> S { return {lhs.a * rhs.a, lhs.b\
    \ * rhs.a + rhs.b}; };\n    constexpr auto e = []() -> S { return {1, 0}; };\n\
    \    using monoid_type = algorithm::algebra::Monoid<S, op, e>;\n    algorithm::SegmentTree<S,\
    \ monoid_type> segtree(v);\n\n    while(q--) {\n        int t;\n        std::cin\
    \ >> t;\n\n        if(t == 0) {\n            int p;\n            algorithm::mint998244353\
    \ c, d;\n            std::cin >> p >> c >> d;\n\n            segtree.set(p, {c,\
    \ d});\n        } else {\n            int l, r;\n            int x;\n        \
    \    std::cin >> l >> r >> x;\n\n            auto f = segtree.prod(l, r);\n  \
    \          auto ans = mapping(f, x);\n            std::cout << ans << \"\\n\"\
    ;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <iostream>\n\n#include \"../algorithm/DataStructure/SegmentTree/segment_tree.hpp\"\
    \n#include \"../algorithm/Math/ModularArithmetic/modint.hpp\"\n\nint main() {\n\
    \    int n;\n    int q;\n    std::cin >> n >> q;\n\n    using S = struct {\n \
    \       algorithm::mint998244353 a;\n        algorithm::mint998244353 b;\n   \
    \ };\n    auto mapping = [](const S &f, algorithm::mint998244353 x) -> algorithm::mint998244353\
    \ {\n        return f.a * x + f.b;\n    };\n\n    std::vector<S> v(n);\n    for(auto\
    \ &elem : v) std::cin >> elem.a >> elem.b;\n\n    constexpr auto op = [](const\
    \ S &lhs, const S &rhs) -> S { return {lhs.a * rhs.a, lhs.b * rhs.a + rhs.b};\
    \ };\n    constexpr auto e = []() -> S { return {1, 0}; };\n    using monoid_type\
    \ = algorithm::algebra::Monoid<S, op, e>;\n    algorithm::SegmentTree<S, monoid_type>\
    \ segtree(v);\n\n    while(q--) {\n        int t;\n        std::cin >> t;\n\n\
    \        if(t == 0) {\n            int p;\n            algorithm::mint998244353\
    \ c, d;\n            std::cin >> p >> c >> d;\n\n            segtree.set(p, {c,\
    \ d});\n        } else {\n            int l, r;\n            int x;\n        \
    \    std::cin >> l >> r >> x;\n\n            auto f = segtree.prod(l, r);\n  \
    \          auto ans = mapping(f, x);\n            std::cout << ans << \"\\n\"\
    ;\n        }\n    }\n}\n"
  dependsOn:
  - algorithm/DataStructure/SegmentTree/segment_tree.hpp
  - algorithm/Math/Algebra/algebra.hpp
  - algorithm/Math/ModularArithmetic/modint.hpp
  - algorithm/Math/ModularArithmetic/mod_inv.hpp
  - algorithm/Math/ModularArithmetic/modulo.hpp
  - algorithm/Math/ModularArithmetic/mod_pow.hpp
  - algorithm/Math/ModularArithmetic/modint_base.hpp
  isVerificationFile: true
  path: verify/yosupo-point_set_range_composite-segment_tree.test.cpp
  requiredBy: []
  timestamp: '2025-08-31 12:36:13+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo-point_set_range_composite-segment_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-point_set_range_composite-segment_tree.test.cpp
- /verify/verify/yosupo-point_set_range_composite-segment_tree.test.cpp.html
title: verify/yosupo-point_set_range_composite-segment_tree.test.cpp
---

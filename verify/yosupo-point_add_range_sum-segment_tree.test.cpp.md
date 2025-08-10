---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/DataStructure/SegmentTree/segment_tree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/Algebra/algebra.hpp
    title: "Algebraic Structure\uFF08\u4EE3\u6570\u7684\u69CB\u9020\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"verify/yosupo-point_add_range_sum-segment_tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #include <iostream>\n#include <vector>\n\n#line 1 \"algorithm/DataStructure/SegmentTree/segment_tree.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <initializer_list>\n\
    #line 8 \"algorithm/DataStructure/SegmentTree/segment_tree.hpp\"\n#include <iterator>\n\
    #include <ranges>\n#include <type_traits>\n#include <utility>\n#line 13 \"algorithm/DataStructure/SegmentTree/segment_tree.hpp\"\
    \n\n#line 1 \"algorithm/Math/Algebra/algebra.hpp\"\n\n\n\n#line 6 \"algorithm/Math/Algebra/algebra.hpp\"\
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
    \ {\npublic:\n    using base_type = SegmentTreeBase<Monoid>;\n    using value_type\
    \ = S;\n    using typename base_type::monoid_type;\n\n    // constructor. O(N).\n\
    \    SegmentTree() : base_type() {};\n    explicit SegmentTree(int n) : base_type(n)\
    \ {}\n    explicit SegmentTree(int n, const value_type &a) : base_type(n, a) {}\n\
    \    template <std::input_iterator InputIter>\n    explicit SegmentTree(InputIter\
    \ first, InputIter last) : base_type(first, last) {}\n    template <std::ranges::input_range\
    \ R>\n    explicit SegmentTree(R &&r) : base_type(std::forward<R>(r)) {}\n   \
    \ template <typename T>\n    explicit SegmentTree(std::initializer_list<T> il)\
    \ : SegmentTree(std::move(il)) {}\n\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\
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
    \n}  // namespace algorithm\n\n\n#line 7 \"verify/yosupo-point_add_range_sum-segment_tree.test.cpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    std::vector<long\
    \ long> a(n);\n    for(auto &elem : a) std::cin >> elem;\n\n    algorithm::RangeSumSegmentTree<long\
    \ long> segtree(a);\n\n    while(q--) {\n        int t;\n        std::cin >> t;\n\
    \n        if(t == 0) {\n            int p;\n            long long x;\n       \
    \     std::cin >> p >> x;\n\n            auto now = segtree.prod(p);\n       \
    \     segtree.set(p, now + x);\n        } else {\n            int l, r;\n    \
    \        std::cin >> l >> r;\n\n            auto ans = segtree.prod(l, r);\n \
    \           std::cout << ans << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <iostream>\n#include <vector>\n\n#include \"../algorithm/DataStructure/SegmentTree/segment_tree.hpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    std::vector<long\
    \ long> a(n);\n    for(auto &elem : a) std::cin >> elem;\n\n    algorithm::RangeSumSegmentTree<long\
    \ long> segtree(a);\n\n    while(q--) {\n        int t;\n        std::cin >> t;\n\
    \n        if(t == 0) {\n            int p;\n            long long x;\n       \
    \     std::cin >> p >> x;\n\n            auto now = segtree.prod(p);\n       \
    \     segtree.set(p, now + x);\n        } else {\n            int l, r;\n    \
    \        std::cin >> l >> r;\n\n            auto ans = segtree.prod(l, r);\n \
    \           std::cout << ans << \"\\n\";\n        }\n    }\n}\n"
  dependsOn:
  - algorithm/DataStructure/SegmentTree/segment_tree.hpp
  - algorithm/Math/Algebra/algebra.hpp
  isVerificationFile: true
  path: verify/yosupo-point_add_range_sum-segment_tree.test.cpp
  requiredBy: []
  timestamp: '2025-08-10 07:13:29+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo-point_add_range_sum-segment_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-point_add_range_sum-segment_tree.test.cpp
- /verify/verify/yosupo-point_add_range_sum-segment_tree.test.cpp.html
title: verify/yosupo-point_add_range_sum-segment_tree.test.cpp
---

---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algorithm/DataStructure/SegmentTree/binary_indexed_tree.hpp
    title: algorithm/DataStructure/SegmentTree/binary_indexed_tree.hpp
  - icon: ':x:'
    path: algorithm/Graph/Tree/heavy_light_decomposition.hpp
    title: algorithm/Graph/Tree/heavy_light_decomposition.hpp
  - icon: ':question:'
    path: algorithm/Math/Algebra/algebra.hpp
    title: algorithm/Math/Algebra/algebra.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"verify/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\n\
    #include <iostream>\n#include <utility>\n#include <vector>\n\n#line 1 \"algorithm/DataStructure/SegmentTree/binary_indexed_tree.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <initializer_list>\n\
    #include <iterator>\n#include <type_traits>\n#line 11 \"algorithm/DataStructure/SegmentTree/binary_indexed_tree.hpp\"\
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
    \ namespace algorithm\n\n\n#line 13 \"algorithm/DataStructure/SegmentTree/binary_indexed_tree.hpp\"\
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
    \n}  // namespace binary_indexed_tree\n\n}  // namespace algorithm\n\n\n#line\
    \ 1 \"algorithm/Graph/Tree/heavy_light_decomposition.hpp\"\n\n\n\n#line 8 \"algorithm/Graph/Tree/heavy_light_decomposition.hpp\"\
    \n\nnamespace algorithm {\n\n// Heavy-Light Decomposition\uFF08HL\u5206\u89E3\uFF0C\
    \u91CD\u8EFD\u5206\u89E3\uFF09.\nclass HLD {\n    int m_vn;                  \
    \         // m_vn:=(\u30CE\u30FC\u30C9\u6570).\n    std::vector<std::vector<int>>\
    \ m_g;  // m_g[v][]:=(\u30CE\u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\
    ). \u30B0\u30E9\u30D5\u306F\u68EE\u3067\u3042\u308B\u3053\u3068\uFF0E\n    std::vector<int>\
    \ m_par, m_head;     // m_par[v]:=(\u30CE\u30FC\u30C9v\u306E\u89AA\u756A\u53F7\
    ), m_head[v]:=(\u30CE\u30FC\u30C9v\u3092\u542B\u3080heavy path\u306E\u7AEF\u70B9\
    ).\n    std::vector<int> m_sub;             // m_sub[v]:=(\u30CE\u30FC\u30C9v\u3092\
    \u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u30B5\u30A4\u30BA).\n    std::vector<int>\
    \ m_ord;             // m_ord[v]:=(\u30CE\u30FC\u30C9v\u306E\u884C\u304D\u304B\
    \u3051\u9806\u5E8F).\n    bool m_is_built;\n\n    bool is_built() const { return\
    \ m_is_built; }\n\npublic:\n    // constructor. O(|V|).\n    HLD() : HLD(0) {}\n\
    \    explicit HLD(int vn) : m_vn(vn), m_g(vn), m_par(vn, -1), m_head(vn, -1),\
    \ m_sub(vn, 1), m_ord(vn, -1), m_is_built(false) {\n        assert(vn >= 0);\n\
    \    }\n\n    // \u30CE\u30FC\u30C9\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n\
    \    int order() const { return m_vn; }\n    // \u7121\u5411\u8FBA\u3092\u5F35\
    \u308B\uFF0E\n    void add_edge(int u, int v) {\n        assert(0 <= u and u <\
    \ order());\n        assert(0 <= v and v < order());\n        m_g[u].push_back(v);\n\
    \        m_g[v].push_back(u);\n    }\n    // \u6728\u3092HL\u5206\u89E3\u3059\u308B\
    \uFF0EO(|V|).\n    void build() {\n        auto dfs = [&](auto self, int u, int\
    \ p) -> int {\n            assert(m_par[u] == -1);  // \u30B0\u30E9\u30D5\u306B\
    \u9589\u8DEF\u306F\u306A\u3044\u3053\u3068\uFF0E\n            m_par[u] = p, m_sub[u]\
    \ = 1;\n            if(m_g[u].size() > 1 and m_g[u][0] == p) std::swap(m_g[u][0],\
    \ m_g[u].back());\n            for(auto &v : m_g[u]) {\n                if(v ==\
    \ p) continue;\n                m_sub[u] += self(self, v, u);\n              \
    \  if(m_sub[v] > m_sub[m_g[u][0]]) std::swap(m_g[u][0], v);  // m_g[u][0]\u306B\
    heavy child\u3092\u683C\u7D0D\u3059\u308B\uFF0E\n            }\n            return\
    \ m_sub[u];\n        };\n        int next = 0;\n        auto dfs2 = [&](auto self,\
    \ int u, int p) -> void {\n            m_ord[u] = next++;\n            for(auto\
    \ v : m_g[u]) {\n                if(v == p) continue;\n                m_head[v]\
    \ = (v == m_g[u][0] ? m_head[u] : v);\n                self(self, v, u);\n   \
    \         }\n        };\n        std::fill(m_par.begin(), m_par.end(), -1);\n\
    \        for(int v = 0, end = order(); v < end; ++v) {\n            if(m_par[v]\
    \ != -1) continue;\n            dfs(dfs, v, -1);\n            m_head[v] = v;\n\
    \            dfs2(dfs2, v, -1);\n        }\n        m_is_built = true;\n    }\n\
    \    // \u30CE\u30FC\u30C9v\u306E\u884C\u304D\u304C\u3051\u9806\u5E8F\u306B\u304A\
    \u3051\u308B\u756A\u53F7\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int vertex_index(int\
    \ v) const {\n        assert(0 <= v and v < order());\n        return m_ord[v];\n\
    \    }\n    const auto &vertex_index() const { return m_ord; }\n    // \u30D1\u30B9\
    u-v\u306B\u304A\u3051\u308B\u9802\u70B9\u5C5E\u6027\u306E\u30AF\u30A8\u30EA\u306B\
    \u5BFE\u5FDC\u3059\u308B\u7BC4\u56F2\u3092\u6C42\u3081\u308B\uFF0EO(log|V|).\n\
    \    std::vector<std::pair<int, int>> vertex_query_ranges(int u, int v) const\
    \ {\n        assert(0 <= u and u < order());\n        assert(0 <= v and v < order());\n\
    \        assert(is_built());\n        std::vector<std::pair<int, int>> res;\n\
    \        do {\n            if(m_ord[u] > m_ord[v]) std::swap(u, v);\n        \
    \    if(m_head[u] == m_head[v]) {\n                res.emplace_back(m_ord[u],\
    \ m_ord[v] + 1);\n                return res;\n            }\n            res.emplace_back(m_ord[m_head[v]],\
    \ m_ord[v] + 1);\n            v = m_par[m_head[v]];\n        } while(v != -1);\n\
    \        return {};  // \u975E\u9023\u7D50\u306E\u5834\u5408\uFF0E\n    }\n  \
    \  // \u30CE\u30FC\u30C9v\u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306B\
    \u304A\u3051\u308B\u9802\u70B9\u5C5E\u6027\u306E\u30AF\u30A8\u30EA\u306B\u5BFE\
    \u5FDC\u3059\u308B\u7BC4\u56F2\u3092\u6C42\u3081\u308B\uFF0EO(1).\n    std::pair<int,\
    \ int> vertex_query_range_of_subtree(int v) const {\n        assert(0 <= v and\
    \ v < order());\n        assert(is_built());\n        return {m_ord[v], m_ord[v]\
    \ + m_sub[v]};\n    }\n    // \u6728\u4E0A\u306E\u30CE\u30FC\u30C9u\u3068v\u306E\
    \u6700\u8FD1\u5171\u901A\u7956\u5148\u3092\u6C42\u3081\u308B\uFF0EO(log|V|).\n\
    \    int lca(int u, int v) const {\n        assert(0 <= u and u < order());\n\
    \        assert(0 <= v and v < order());\n        assert(is_built());\n      \
    \  do {\n            if(m_ord[u] > m_ord[v]) std::swap(u, v);\n            if(m_head[u]\
    \ == m_head[v]) return u;\n            v = m_par[m_head[v]];\n        } while(v\
    \ != -1);\n        return -1;  // \u975E\u9023\u7D50\u306E\u5834\u5408\uFF0E\n\
    \    }\n};\n\n}  // namespace algorithm\n\n\n#line 9 \"verify/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    std::vector<int>\
    \ a(n);\n    for(auto &elem : a) std::cin >> elem;\n\n    algorithm::HLD hld(n);\n\
    \    for(int i = 0; i < n - 1; ++i) {\n        int u, v;\n        std::cin >>\
    \ u >> v;\n\n        hld.add_edge(u, v);\n    }\n    hld.build();\n\n    using\
    \ binary_indexed_tree = algorithm::binary_indexed_tree::range_sum_binary_indexed_tree<long\
    \ long>;\n    using group = binary_indexed_tree::group_type;\n\n    std::vector<group>\
    \ b(n);\n    for(int i = 0; i < n; ++i) b[hld.vertex_index()[i]] = a[i];\n\n \
    \   binary_indexed_tree bit(std::move(b));\n\n    while(q--) {\n        int t;\n\
    \        std::cin >> t;\n\n        if(t == 0) {\n            int p;\n        \
    \    int x;\n            std::cin >> p >> x;\n\n            bit.add(hld.vertex_index(p),\
    \ x);\n        } else {\n            int u, v;\n            std::cin >> u >> v;\n\
    \n            long long ans = 0;\n            auto &&ranges = hld.vertex_query_ranges(u,\
    \ v);\n            for(const auto &[l, r] : ranges) ans += bit.sum(l, r);\n\n\
    \            std::cout << ans << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include <iostream>\n#include <utility>\n#include <vector>\n\n#include \"../algorithm/DataStructure/SegmentTree/binary_indexed_tree.hpp\"\
    \n#include \"../algorithm/Graph/Tree/heavy_light_decomposition.hpp\"\n\nint main()\
    \ {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    std::vector<int> a(n);\n\
    \    for(auto &elem : a) std::cin >> elem;\n\n    algorithm::HLD hld(n);\n   \
    \ for(int i = 0; i < n - 1; ++i) {\n        int u, v;\n        std::cin >> u >>\
    \ v;\n\n        hld.add_edge(u, v);\n    }\n    hld.build();\n\n    using binary_indexed_tree\
    \ = algorithm::binary_indexed_tree::range_sum_binary_indexed_tree<long long>;\n\
    \    using group = binary_indexed_tree::group_type;\n\n    std::vector<group>\
    \ b(n);\n    for(int i = 0; i < n; ++i) b[hld.vertex_index()[i]] = a[i];\n\n \
    \   binary_indexed_tree bit(std::move(b));\n\n    while(q--) {\n        int t;\n\
    \        std::cin >> t;\n\n        if(t == 0) {\n            int p;\n        \
    \    int x;\n            std::cin >> p >> x;\n\n            bit.add(hld.vertex_index(p),\
    \ x);\n        } else {\n            int u, v;\n            std::cin >> u >> v;\n\
    \n            long long ans = 0;\n            auto &&ranges = hld.vertex_query_ranges(u,\
    \ v);\n            for(const auto &[l, r] : ranges) ans += bit.sum(l, r);\n\n\
    \            std::cout << ans << \"\\n\";\n        }\n    }\n}\n"
  dependsOn:
  - algorithm/DataStructure/SegmentTree/binary_indexed_tree.hpp
  - algorithm/Math/Algebra/algebra.hpp
  - algorithm/Graph/Tree/heavy_light_decomposition.hpp
  isVerificationFile: true
  path: verify/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp
- /verify/verify/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp.html
title: verify/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp
---

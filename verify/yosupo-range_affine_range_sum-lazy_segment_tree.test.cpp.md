---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/DataStructure/SegmentTree/lazy_segment_tree.hpp
    title: "Lazy Segment Tree\uFF08\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\
      \u30C8\u6728\uFF09"
  - icon: ':heavy_check_mark:'
    path: lib/Math/ModularArithmetic/modint.hpp
    title: "Modint\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: lib/Math/ModularArithmetic/modint_base.hpp
    title: "Modint\u69CB\u9020\u4F53\u306E\u57FA\u5E95\u30AF\u30E9\u30B9"
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
    \n#include <iostream>\n\n#line 1 \"lib/DataStructure/SegmentTree/lazy_segment_tree.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include\
    \ <limits>\n#include <type_traits>\n#include <vector>\n\nnamespace algorithm {\n\
    \nnamespace lazysegmenttree {\n\n// Lazy Segment Tree\uFF08\u9045\u5EF6\u8A55\u4FA1\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\uFF09.\ntemplate <class S, auto op, auto\
    \ e, class F, auto map, auto compose, auto id>\nclass LazySegmentTree {\n    static_assert(std::is_convertible_v<decltype(op),\
    \ std::function<S(S, S)>>);\n    static_assert(std::is_convertible_v<decltype(e),\
    \ std::function<S()>>);\n    static_assert(std::is_convertible_v<decltype(map),\
    \ std::function<S(F, S)>>);\n    static_assert(std::is_convertible_v<decltype(compose),\
    \ std::function<F(F, F)>>);\n    static_assert(std::is_convertible_v<decltype(id),\
    \ std::function<F()>>);\n\npublic:\n    using value_type = S;    // \u30E2\u30CE\
    \u30A4\u30C9\u306E\u578B\uFF0E\n    using mapping_type = F;  // \u5199\u50CF\u306E\
    \u578B\uFF0E\n\nprivate:\n    int m_sz;                          // m_sz:=(\u8981\
    \u7D20\u6570).\n    int m_n;                           // m_n:=(\u5B8C\u5168\u4E8C\
    \u5206\u6728\u306E\u8449\u6570).\n    int m_depth;                       // m_depth:=(\u5B8C\
    \u5168\u4E8C\u5206\u6728\u306E\u6DF1\u3055).\n    std::vector<value_type> m_tree;\
    \    // m_tree(2n)[]:=(\u5B8C\u5168\u4E8C\u5206\u6728). 1-based index.\n    std::vector<mapping_type>\
    \ m_lazy;  // m_lazy(n)[k]:=(m_tree[k]\u306E\u5B50 (m_tree[2k], m_tree[2k+1])\
    \ \u306B\u5BFE\u3059\u308B\u9045\u5EF6\u8A55\u4FA1).\n\n    void apply_with_lazy(int\
    \ k, const mapping_type &f) {\n        m_tree[k] = map(f, m_tree[k]);\n      \
    \  if(k < m_n) m_lazy[k] = compose(f, m_lazy[k]);\n    }\n    void push(int k)\
    \ {\n        apply_with_lazy(k << 1, m_lazy[k]);\n        apply_with_lazy(k <<\
    \ 1 | 1, m_lazy[k]);\n        m_lazy[k] = id();\n    }\n    void update(int k)\
    \ { m_tree[k] = op(m_tree[k << 1], m_tree[k << 1 | 1]); }\n    void build() {\n\
    \        for(int i = 1; i <= m_depth; ++i) {\n            int l = m_n >> i, r\
    \ = (m_n + m_sz - 1) >> i;\n            for(int j = r; j >= l; --j) update(j);\n\
    \        }\n    }\n\npublic:\n    // constructor. O(N).\n    LazySegmentTree()\
    \ : LazySegmentTree(0) {}\n    explicit LazySegmentTree(int n) : m_sz(n), m_n(1),\
    \ m_depth(0) {\n        assert(n >= 0);\n        while(m_n < m_sz) m_n <<= 1,\
    \ ++m_depth;\n        m_tree.assign(2 * m_n, e());\n        m_lazy.assign(m_n,\
    \ id());\n    }\n    explicit LazySegmentTree(int n, const value_type &a) : LazySegmentTree(n)\
    \ {\n        std::fill(m_tree.begin() + m_n, m_tree.begin() + m_n + m_sz, a);\n\
    \        build();\n    }\n    explicit LazySegmentTree(const std::vector<value_type>\
    \ &v) : LazySegmentTree(v.size()) {\n        std::copy(v.cbegin(), v.cend(), m_tree.begin()\
    \ + m_n);\n        build();\n    }\n\n    // \u4E8C\u9805\u6F14\u7B97\u95A2\u6570\
    \u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    static constexpr auto operation() {\
    \ return op; }\n    // \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\u3092\u53D6\
    \u5F97\u3059\u308B\uFF0E\n    static constexpr auto identity() { return e; }\n\
    \    // \u5199\u50CF\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    static constexpr\
    \ auto mapping() { return map; }\n    // \u5199\u50CF\u306E\u5408\u6210\u95A2\u6570\
    \u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    static constexpr auto composition()\
    \ { return compose; }\n    // \u6052\u7B49\u5199\u50CF\u3092\u53D6\u5F97\u3059\
    \u308B\uFF0E\n    static constexpr auto identity_mapping() { return id; }\n  \
    \  // \u8981\u7D20\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int size() const\
    \ { return m_sz; }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092a\u306B\u7F6E\u304D\
    \u63DB\u3048\u308B\uFF0EO(logN).\n    void set(int k, const value_type &a) {\n\
    \        assert(0 <= k and k < size());\n        k += m_n;\n        for(int i\
    \ = m_depth; i >= 1; --i) push(k >> i);\n        m_tree[k] = a;\n        for(int\
    \ i = 1; i <= m_depth; ++i) update(k >> i);\n    }\n    // k\u756A\u76EE\u306E\
    \u8981\u7D20\u3092\u5199\u50CFf\u3092\u7528\u3044\u3066\u66F4\u65B0\u3059\u308B\
    \uFF0EO(logN).\n    void apply(int k, const mapping_type &f) {\n        assert(0\
    \ <= k and k < size());\n        k += m_n;\n        for(int i = m_depth; i >=\
    \ 1; --i) push(k >> i);\n        m_tree[k] = map(f, m_tree[k]);\n        for(int\
    \ i = 1; i <= m_depth; ++i) update(k >> i);\n    }\n    // \u533A\u9593[l,r)\u306E\
    \u8981\u7D20\u3092\u5199\u50CFf\u3092\u7528\u3044\u3066\u66F4\u65B0\u3059\u308B\
    \uFF0EO(logN).\n    void apply(int l, int r, const mapping_type &f) {\n      \
    \  assert(0 <= l and l <= r and r <= size());\n        if(l == r) return;\n  \
    \      l += m_n, r += m_n;\n        for(int i = m_depth; i >= 1; --i) {\n    \
    \        if((l >> i) << i != l) push(l >> i);\n            if((r >> i) << i !=\
    \ r) push((r - 1) >> i);\n        }\n        for(int ll = l, rr = r; ll < rr;\
    \ ll >>= 1, rr >>= 1) {\n            if(ll & 1) apply_with_lazy(ll++, f);\n  \
    \          if(rr & 1) apply_with_lazy(--rr, f);\n        }\n        for(int i\
    \ = 1; i <= m_depth; ++i) {\n            if((l >> i) << i != l) update(l >> i);\n\
    \            if((r >> i) << i != r) update((r - 1) >> i);\n        }\n    }\n\
    \    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\u6C42\u3081\u308B\uFF0EO(logN).\n\
    \    value_type prod(int k) {\n        assert(0 <= k and k < size());\n      \
    \  k += m_n;\n        for(int i = m_depth; i >= 1; --i) push(k >> i);\n      \
    \  return m_tree[k];\n    }\n    // \u533A\u9593[l,r)\u306E\u8981\u7D20\u306E\u7DCF\
    \u7A4D v[l]\u2022v[l+1]\u2022....\u2022v[r-1] \u3092\u6C42\u3081\u308B\uFF0EO(logN).\n\
    \    value_type prod(int l, int r) {\n        assert(0 <= l and l <= r and r <=\
    \ size());\n        if(l == r) return e();\n        l += m_n, r += m_n;\n    \
    \    for(int i = m_depth; i >= 1; --i) {\n            if((l >> i) << i != l) push(l\
    \ >> i);\n            if((r >> i) << i != r) push((r - 1) >> i);\n        }\n\
    \        value_type &&val_l = e(), &&val_r = e();\n        for(; l < r; l >>=\
    \ 1, r >>= 1) {\n            if(l & 1) val_l = op(val_l, m_tree[l++]);\n     \
    \       if(r & 1) val_r = op(m_tree[--r], val_r);\n        }\n        return op(val_l,\
    \ val_r);\n    }\n    // \u533A\u9593\u5168\u4F53\u306E\u8981\u7D20\u306E\u7DCF\
    \u7A4D\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(1).\n    value_type prod_all() const\
    \ { return m_tree[1]; }\n    // eval(prod(l,-))==true \u3068\u306A\u308B\u533A\
    \u9593\u306E\u6700\u53F3\u4F4D\u5024\u3092\u4E8C\u5206\u63A2\u7D22\u3059\u308B\
    \uFF0E\n    // \u305F\u3060\u3057\uFF0C\u8981\u7D20\u5217\u306E\u533A\u9593\u7A4D\
    \u306B\u306F\u5358\u8ABF\u6027\u304C\u3042\u308A\uFF0C\u307E\u305F eval(e)==true\
    \ \u3067\u3042\u308B\u3053\u3068\uFF0EO(logN).\n    template <class Eval>\n  \
    \  int most_right(int l, Eval eval) const {\n        static_assert(std::is_convertible_v<Eval,\
    \ std::function<bool(value_type)>>);\n        assert(0 <= l and l <= size());\n\
    \        assert(eval(e()));\n        if(l == size()) return size();\n        l\
    \ += m_n;\n        for(int i = m_depth; i >= 1; --i) push(l >> i);\n        value_type\
    \ &&val = e();\n        do {\n            while(!(l & 1)) l >>= 1;\n         \
    \   value_type &&tmp = op(val, m_tree[l]);\n            if(!eval(tmp)) {\n   \
    \             while(l < m_n) {\n                    push(l);\n               \
    \     l <<= 1;\n                    tmp = op(val, m_tree[l]);\n              \
    \      if(eval(tmp)) val = tmp, ++l;\n                }\n                return\
    \ l - m_n;\n            }\n            val = tmp, ++l;\n        } while((l & -l)\
    \ != l);  // (x&-x)==x \u306E\u3068\u304D\uFF0Cx\u306F2\u306E\u968E\u4E57\u6570\
    \uFF0E\n        return size();\n    }\n    // eval(prod(-,r))==true \u3068\u306A\
    \u308B\u533A\u9593\u306E\u6700\u5DE6\u4F4D\u5024\u3092\u4E8C\u5206\u63A2\u7D22\
    \u3059\u308B\uFF0E\n    // \u305F\u3060\u3057\uFF0C\u8981\u7D20\u5217\u306E\u533A\
    \u9593\u7A4D\u306B\u306F\u5358\u8ABF\u6027\u304C\u3042\u308A\uFF0C\u307E\u305F\
    \ eval(e)==true \u3067\u3042\u308B\u3053\u3068\uFF0EO(logN).\n    template <class\
    \ Eval>\n    int most_left(int r, Eval eval) const {\n        static_assert(std::is_convertible_v<Eval,\
    \ std::function<bool(value_type)>>);\n        assert(0 <= r and r <= size());\n\
    \        assert(eval(e()));\n        if(r == 0) return 0;\n        r += m_n;\n\
    \        for(int i = m_depth; i >= 1; --i) push((r - 1) >> i);\n        value_type\
    \ &&val = e();\n        do {\n            --r;\n            while(r > 1 and r\
    \ & 1) r >>= 1;\n            value_type &&tmp = m_op(m_tree[r], val);\n      \
    \      if(!eval(tmp)) {\n                while(r < m_n) {\n                  \
    \  push(r);\n                    r = r << 1 | 1;\n                    tmp = op(m_tree[r],\
    \ val);\n                    if(eval(tmp)) val = tmp, --r;\n                }\n\
    \                return r - m_n + 1;\n            }\n            val = tmp;\n\
    \        } while((r & -r) != r);  // (x&-x)==x \u306E\u3068\u304D\uFF0Cx\u306F\
    2\u306E\u968E\u4E57\u6570\uFF0E\n        return 0;\n    }\n    void reset() {\n\
    \        std::fill(m_tree.begin() + 1, m_tree.begin() + m_n + m_sz, e());\n  \
    \      std::fill(m_lazy.begin() + 1, m_lazy.end(), id());\n    }\n};\n\ntemplate\
    \ <typename Type>\nauto range_minimum_query_and_range_update_query(int n) {\n\
    \    assert(n >= 0);\n    using S = Type;\n    using F = Type;\n    constexpr\
    \ auto e = []() -> S { return std::numeric_limits<S>::max() - 1; };\n    constexpr\
    \ auto id = []() -> F { return std::numeric_limits<F>::max(); };\n    constexpr\
    \ auto op = [](S lhs, S rhs) -> S { return std::min(lhs, rhs); };\n    constexpr\
    \ auto mapping = [id](F f, S x) -> S { return (f == id() ? x : f); };\n    constexpr\
    \ auto composition = [id](F f, F g) -> F { return (f == id() ? g : f); };\n  \
    \  return LazySegmentTree<S, op, e, F, mapping, composition, id>(n);\n}\n\ntemplate\
    \ <typename Type>\nauto range_minimum_query_and_range_update_query(const std::vector<Type>\
    \ &v) {\n    using S = Type;\n    using F = Type;\n    constexpr auto e = []()\
    \ -> S { return std::numeric_limits<S>::max() - 1; };\n    constexpr auto id =\
    \ []() -> F { return std::numeric_limits<F>::max(); };\n    constexpr auto op\
    \ = [](S lhs, S rhs) -> S { return std::min(lhs, rhs); };\n    constexpr auto\
    \ mapping = [id](F f, S x) -> F { return (f == id() ? x : f); };\n    constexpr\
    \ auto composition = [id](F f, F g) -> F { return (f == id() ? g : f); };\n  \
    \  return LazySegmentTree<S, op, e, F, mapping, composition, id>(v);\n}\n\ntemplate\
    \ <typename Type>\nauto range_minimum_query_and_range_add_query(int n) {\n   \
    \ assert(n >= 0);\n    using S = Type;\n    using F = Type;\n    constexpr auto\
    \ e = []() -> S { return std::numeric_limits<S>::max(); };\n    constexpr auto\
    \ id = []() -> F { return 0; };\n    constexpr auto op = [](S lhs, S rhs) -> S\
    \ { return std::min(lhs, rhs); };\n    constexpr auto mapping = [](F f, S x) ->\
    \ F { return x + f; };\n    constexpr auto composition = [](F f, F g) -> F { return\
    \ g + f; };\n    return LazySegmentTree<S, op, e, F, mapping, composition, id>(n);\n\
    }\n\ntemplate <typename Type>\nauto range_minimum_query_and_range_add_query(const\
    \ std::vector<Type> &v) {\n    using S = Type;\n    using F = Type;\n    constexpr\
    \ auto e = []() -> S { return std::numeric_limits<S>::max(); };\n    constexpr\
    \ auto id = []() -> F { return 0; };\n    constexpr auto op = [](S lhs, S rhs)\
    \ -> S { return std::min(lhs, rhs); };\n    constexpr auto mapping = [](F f, S\
    \ x) -> S { return x + f; };\n    constexpr auto composition = [](F f, F g) ->\
    \ F { return g + f; };\n    return LazySegmentTree<S, op, e, F, mapping, composition,\
    \ id>(v);\n}\n\ntemplate <typename Type>\nauto range_maximum_query_and_range_update_query(int\
    \ n) {\n    assert(n >= 0);\n    using S = Type;\n    using F = Type;\n    constexpr\
    \ auto e = []() -> S { return std::numeric_limits<S>::lowest() + 1; };\n    constexpr\
    \ auto id = []() -> F { return std::numeric_limits<F>::lowest(); };\n    constexpr\
    \ auto op = [](S lhs, S rhs) -> S { return std::max(lhs, rhs); };\n    constexpr\
    \ auto mapping = [id](F f, S x) -> S { return (f == id() ? x : f); };\n    constexpr\
    \ auto composition = [id](F f, F g) -> F { return (f == id() ? g : f); };\n  \
    \  return LazySegmentTree<S, op, e, F, mapping, composition, id>(n);\n}\n\ntemplate\
    \ <typename Type>\nauto range_maximum_query_and_range_update_query(const std::vector<Type>\
    \ &v) {\n    using S = Type;\n    using F = Type;\n    constexpr auto e = []()\
    \ -> S { return std::numeric_limits<S>::lowest() + 1; };\n    constexpr auto id\
    \ = []() -> F { return std::numeric_limits<F>::lowest(); };\n    constexpr auto\
    \ op = [](S lhs, S rhs) -> S { return std::max(lhs, rhs); };\n    constexpr auto\
    \ mapping = [id](F f, S x) -> S { return (f == id() ? x : f); };\n    constexpr\
    \ auto composition = [id](F f, F g) -> F { return (f == id() ? g : f); };\n  \
    \  return LazySegmentTree<S, op, e, F, mapping, composition, id>(v);\n}\n\ntemplate\
    \ <typename Type>\nauto range_maximum_query_and_range_add_query(int n) {\n   \
    \ assert(n >= 0);\n    using S = Type;\n    using F = Type;\n    constexpr auto\
    \ e = []() -> S { return std::numeric_limits<S>::lowest(); };\n    constexpr auto\
    \ id = []() -> F { return 0; };\n    constexpr auto op = [](S lhs, S rhs) -> S\
    \ { return std::max(lhs, rhs); };\n    constexpr auto mapping = [](F f, S x) ->\
    \ S { return x + f; };\n    constexpr auto composition = [](F f, F g) -> F { return\
    \ g + f; };\n    return LazySegmentTree<S, op, e, F, mapping, composition, id>(n);\n\
    }\n\ntemplate <typename Type>\nauto range_maximum_query_and_range_add_query(const\
    \ std::vector<Type> &v) {\n    using S = Type;\n    using F = Type;\n    constexpr\
    \ auto e = []() -> S { return std::numeric_limits<S>::lowest(); };\n    constexpr\
    \ auto id = []() -> F { return 0; };\n    constexpr auto op = [](S lhs, S rhs)\
    \ -> S { return std::max(lhs, rhs); };\n    constexpr auto mapping = [](F f, S\
    \ x) -> S { return x + f; };\n    constexpr auto composition = [](F f, F g) ->\
    \ F { return g + f; };\n    return LazySegmentTree<S, op, e, F, mapping, composition,\
    \ id>(v);\n}\n\ntemplate <typename Type>\nauto range_sum_query_and_range_update_query(int\
    \ n) {\n    assert(n >= 0);\n    using S = struct {\n        Type val;\n     \
    \   int size;\n    };\n    using F = Type;\n    constexpr auto e = []() -> S {\
    \ return {0, 0}; };\n    constexpr auto id = []() -> F { return std::numeric_limits<F>::max();\
    \ };\n    constexpr auto op = [](const S &lhs, const S &rhs) -> S { return {lhs.val\
    \ + rhs.val, lhs.size + rhs.size}; };\n    constexpr auto mapping = [id](F f,\
    \ const S &x) -> S { return {(f == id() ? x.val : f * x.size), x.size}; };\n \
    \   constexpr auto composition = [id](F f, F g) -> F { return (f == id() ? g :\
    \ f); };\n    return LazySegmentTree<S, op, e, F, mapping, composition, id>(n,\
    \ {0, 1});\n}\n\ntemplate <typename Type>\nauto range_sum_query_and_range_add_query(int\
    \ n) {\n    assert(n >= 0);\n    using S = struct {\n        Type val;\n     \
    \   int size;\n    };\n    using F = Type;\n    constexpr auto e = []() -> S {\
    \ return {0, 0}; };\n    constexpr auto id = []() -> F { return 0; };\n    constexpr\
    \ auto op = [](const S &lhs, const S &rhs) -> S { return {lhs.val + rhs.val, lhs.size\
    \ + rhs.size}; };\n    constexpr auto mapping = [](F f, const S &x) -> S { return\
    \ {x.val + f * x.size, x.size}; };\n    constexpr auto composition = [](F f, F\
    \ g) -> F { return g + f; };\n    return LazySegmentTree<S, op, e, F, mapping,\
    \ composition, id>(n, {0, 1});\n}\n\ntemplate <typename Type>\nauto range_sum_query_and_range_affine_query(int\
    \ n) {\n    assert(n >= 0);\n    using S = struct {\n        Type val;\n     \
    \   int size;\n    };\n    using F = struct {\n        Type a;\n        Type b;\n\
    \    };\n    constexpr auto e = []() -> S { return {0, 0}; };\n    constexpr auto\
    \ id = []() -> F { return {1, 0}; };\n    constexpr auto op = [](const S &lhs,\
    \ const S &rhs) -> S { return {lhs.val + rhs.val, lhs.size + rhs.size}; };\n \
    \   constexpr auto mapping = [](const F &f, const S &x) -> S { return {x.val *\
    \ f.a + f.b * x.size, x.size}; };\n    constexpr auto composition = [](const F\
    \ &f, const F &g) -> F { return {g.a * f.a, g.b * f.a + f.b}; };\n    return LazySegmentTree<S,\
    \ op, e, F, mapping, composition, id>(n, {0, 1});\n}\n\n}  // namespace lazysegmenttree\n\
    \n}  // namespace algorithm\n\n\n#line 1 \"lib/Math/ModularArithmetic/modint.hpp\"\
    \n\n\n\n#line 5 \"lib/Math/ModularArithmetic/modint.hpp\"\n#include <utility>\n\
    \n#line 1 \"lib/Math/ModularArithmetic/modint_base.hpp\"\n\n\n\n#line 5 \"lib/Math/ModularArithmetic/modint_base.hpp\"\
    \n\nnamespace algorithm {\n\nclass ModintBase {};\n\ntemplate <class T>\nusing\
    \ is_modint = std::is_base_of<ModintBase, T>;\n\ntemplate <class T>\ninline constexpr\
    \ bool is_modint_v = is_modint<T>::value;\n\n}  // namespace algorithm\n\n\n#line\
    \ 8 \"lib/Math/ModularArithmetic/modint.hpp\"\n\nnamespace algorithm {\n\ntemplate\
    \ <int mod>\nclass Modint : ModintBase {\n    static_assert(mod >= 1);\n\n   \
    \ long long val;\n\n    constexpr void normalize() {\n        if(val < -mod or\
    \ mod <= val) val %= mod;\n        if(val < 0) val += mod;\n    }\n\npublic:\n\
    \    constexpr Modint() : val(0) {}\n    constexpr Modint(long long val) : val(val)\
    \ {\n        normalize();\n    }\n\n    constexpr Modint operator+() const { return\
    \ Modint(*this); }\n    constexpr Modint operator-() const {\n        if(val ==\
    \ 0) Modint();\n        Modint res = *this;\n        res.val = mod - res.val;\n\
    \        return res;\n    }\n    constexpr Modint &operator++() {\n        val++;\n\
    \        if(val == mod) val = 0;\n        return *this;\n    }\n    constexpr\
    \ Modint &operator--() {\n        if(val == 0) val = mod;\n        val--;\n  \
    \      return *this;\n    }\n    constexpr Modint operator++(int) {\n        Modint\
    \ res = *this;\n        ++(*this);\n        return res;\n    }\n    constexpr\
    \ Modint operator--(int) {\n        Modint res = *this;\n        --(*this);\n\
    \        return res;\n    }\n    constexpr Modint &operator+=(const Modint &rhs)\
    \ {\n        val += rhs.val;\n        if(val >= mod) val -= mod;\n        return\
    \ *this;\n    }\n    constexpr Modint &operator-=(const Modint &rhs) {\n     \
    \   val -= rhs.val;\n        if(val < 0) val += mod;\n        return *this;\n\
    \    }\n    constexpr Modint &operator*=(const Modint &rhs) {\n        val = val\
    \ * rhs.val % mod;\n        return *this;\n    }\n    constexpr Modint &operator/=(const\
    \ Modint &rhs) { return *this *= rhs.inv(); }\n\n    friend constexpr bool operator==(const\
    \ Modint &lhs, const Modint &rhs) { return lhs.val == rhs.val; }\n    friend constexpr\
    \ Modint operator+(const Modint &lhs, const Modint &rhs) { return Modint(lhs)\
    \ += rhs; }\n    friend constexpr Modint operator-(const Modint &lhs, const Modint\
    \ &rhs) { return Modint(lhs) -= rhs; }\n    friend constexpr Modint operator*(const\
    \ Modint &lhs, const Modint &rhs) { return Modint(lhs) *= rhs; }\n    friend constexpr\
    \ Modint operator/(const Modint &lhs, const Modint &rhs) { return Modint(lhs)\
    \ /= rhs; }\n    friend std::istream &operator>>(std::istream &is, Modint &rhs)\
    \ {\n        is >> rhs.val;\n        rhs.normalize();\n        return is;\n  \
    \  }\n    friend std::ostream &operator<<(std::ostream &os, const Modint &rhs)\
    \ { return os << rhs.val; }\n\n    static constexpr int modulus() { return mod;\
    \ }\n    constexpr long long value() const { return val; }\n    constexpr Modint\
    \ inv() const {\n        long long a = mod, b = val, u = 0, v = 1;\n        while(b\
    \ != 0) {\n            long long t = a / b;\n            a -= b * t, u -= v *\
    \ t;\n            std::swap(a, b), std::swap(u, v);\n        }\n        return\
    \ Modint(u);\n    }\n    constexpr Modint pow(long long k) const {\n        if(k\
    \ < 0) return inv().pow(-k);\n        Modint res = 1, mul = *this;\n        while(k\
    \ > 0) {\n            if(k & 1LL) res *= mul;\n            mul *= mul;\n     \
    \       k >>= 1;\n        }\n        return res;\n    }\n\n    friend constexpr\
    \ Modint mod_inv(const Modint &a) { return a.inv(); }\n    friend constexpr Modint\
    \ mod_pow(const Modint &a, long long k) { return a.pow(k); }\n};\n\nusing mint998244353\
    \ = Modint<998'244'353>;\nusing mint1000000007 = Modint<1'000'000'007>;\n\n} \
    \ // namespace algorithm\n\n\n#line 7 \"verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    using\
    \ Type = algorithm::mint998244353;\n    auto &&segtree = algorithm::lazysegmenttree::range_sum_query_and_range_affine_query<Type>(n);\n\
    \    for(int i = 0; i < n; ++i) {\n        Type a;\n        std::cin >> a;\n\n\
    \        segtree.set(i, {a, 1});\n    }\n\n    while(q--) {\n        int type;\n\
    \        int l, r;\n        std::cin >> type >> l >> r;\n\n        if(type ==\
    \ 0) {\n            Type b, c;\n            std::cin >> b >> c;\n\n          \
    \  segtree.apply(l, r, {b, c});\n        } else {\n            auto &&ans = segtree.prod(l,\
    \ r).val;\n            std::cout << ans << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <iostream>\n\n#include \"../lib/DataStructure/SegmentTree/lazy_segment_tree.hpp\"\
    \n#include \"../lib/Math/ModularArithmetic/modint.hpp\"\n\nint main() {\n    int\
    \ n;\n    int q;\n    std::cin >> n >> q;\n\n    using Type = algorithm::mint998244353;\n\
    \    auto &&segtree = algorithm::lazysegmenttree::range_sum_query_and_range_affine_query<Type>(n);\n\
    \    for(int i = 0; i < n; ++i) {\n        Type a;\n        std::cin >> a;\n\n\
    \        segtree.set(i, {a, 1});\n    }\n\n    while(q--) {\n        int type;\n\
    \        int l, r;\n        std::cin >> type >> l >> r;\n\n        if(type ==\
    \ 0) {\n            Type b, c;\n            std::cin >> b >> c;\n\n          \
    \  segtree.apply(l, r, {b, c});\n        } else {\n            auto &&ans = segtree.prod(l,\
    \ r).val;\n            std::cout << ans << \"\\n\";\n        }\n    }\n}\n"
  dependsOn:
  - lib/DataStructure/SegmentTree/lazy_segment_tree.hpp
  - lib/Math/ModularArithmetic/modint.hpp
  - lib/Math/ModularArithmetic/modint_base.hpp
  isVerificationFile: true
  path: verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2025-03-27 01:07:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
- /verify/verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp.html
title: verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
---

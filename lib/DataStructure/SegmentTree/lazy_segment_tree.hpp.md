---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DSL_2_F-lazy_segment_tree.test.cpp
    title: verify/aoj-DSL_2_F-lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DSL_2_G-lazy_segment_tree.test.cpp
    title: verify/aoj-DSL_2_G-lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DSL_2_H-lazy_segment_tree.test.cpp
    title: verify/aoj-DSL_2_H-lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DSL_2_I-lazy_segment_tree.test.cpp
    title: verify/aoj-DSL_2_I-lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
    title: verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/DataStructure/SegmentTree/lazy_segment_tree.hpp\"\n\n\
    \n\n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include\
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
    \n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_LAZY_SEGMENT_TREE_HPP\n#define ALGORITHM_LAZY_SEGMENT_TREE_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include\
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
    \n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/DataStructure/SegmentTree/lazy_segment_tree.hpp
  requiredBy: []
  timestamp: '2025-03-27 01:07:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-DSL_2_G-lazy_segment_tree.test.cpp
  - verify/aoj-DSL_2_F-lazy_segment_tree.test.cpp
  - verify/aoj-DSL_2_H-lazy_segment_tree.test.cpp
  - verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
  - verify/aoj-DSL_2_I-lazy_segment_tree.test.cpp
documentation_of: lib/DataStructure/SegmentTree/lazy_segment_tree.hpp
layout: document
title: "Lazy Segment Tree\uFF08\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\
  \u6728\uFF09"
---


##  概要

通常の Segment Tree が処理するクエリは「一点更新・区間取得」であるのに対し，Lazy Segment Tree（遅延評価セグメント木）は「**区間更新**・区間取得」のクエリを処理する．

具体的には，長さ $N$ の配列 $\lbrace a_0, a_1, \ldots, a_{n-1} \rbrace$ に対して，次のクエリ処理を $\mathcal{O}(\log N)$ で行う．

- **区間更新**：区間 $[l, r)$ の要素 $a_l, a_{l+1}, \ldots, a_{r-1}$ を写像 $f$ を用いて更新 ( $x=f(x)$ )
- **区間取得**：区間 $[l, r)$ の要素の総積 $a_l \bullet a_{l+1} \bullet \cdots \bullet a_{r-1}$ を取得

本ライブラリの実装では Segment Tree と同様に抽象化を行っており，オブジェクト定義時にモノイド $(S, \bullet : S \times S \rightarrow S, e \in S)$ と，次の条件を満たす $S$ から $S$ への写像の集合 $F$ を定義する．

- $F$ は $\forall x \in S$ に対して $\operatorname{id}(x)=x$ となる恒等写像 $\operatorname{id}$ を含む
- $\forall f, \forall g \in F$ に対して $f \circ g \in F$ である（$F$ は写像の合成について閉じている）
- $\forall f \in F, \forall x, \forall y \in S$ に対して $f(x \bullet y) = f(x) \bullet f(y)$ である


## 参考文献

1. "Lazy Segtree". AC Library. AtCoder. <https://atcoder.github.io/ac-library/production/document_ja/lazysegtree.html>.
1. "作用素". Wikipedia. <https://ja.wikipedia.org/wiki/作用素>.
1. betrue12. "Atcoder LibraryのLazy Segtreeの使い方". Hatena Blog. <https://betrue12.hateblo.jp/entry/2020/09/22/194541>.
1. "遅延評価セグメント木". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/segment_tree/lazy_segment_tree>.


## 問題

- "K - Range Affine Range Sum". AtCoder Library Practice Contest. AtCoder. <https://atcoder.jp/contests/practice2/tasks/practice2_k>.
- "L - Lazy Segment Tree". AtCoder Library Practice Contest. AtCoder. <https://atcoder.jp/contests/practice2/tasks/practice2_l>.

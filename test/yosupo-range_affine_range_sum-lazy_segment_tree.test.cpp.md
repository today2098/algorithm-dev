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
  bundledCode: "#line 1 \"test/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    \n#include <iostream>\n#include <vector>\n\n#line 1 \"lib/DataStructure/SegmentTree/lazy_segment_tree.hpp\"\
    \n\n\n\n/**\n * @brief Lazy Segment Tree\uFF08\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\uFF09\n * @docs docs/DataStructure/SegmentTree/lazy_segment_tree.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <functional>\n#line\
    \ 13 \"lib/DataStructure/SegmentTree/lazy_segment_tree.hpp\"\n\nnamespace algorithm\
    \ {\n\n// Lazy Segment Tree\uFF08\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728\uFF09.\ntemplate <class S, class F>  // S:\u30E2\u30CE\u30A4\u30C9\
    \u306E\u578B, F:\u5199\u50CF\u306E\u578B.\nclass LazySegTree {\n    using Op =\
    \ std::function<S(const S &, const S &)>;\n    using Mapping = std::function<S(const\
    \ F &, const S &)>;\n    using Composition = std::function<F(const F &, const\
    \ F &)>;\n\n    Op m_op;                    // S m_op(S,S):=(\u4E8C\u9805\u6F14\
    \u7B97\u95A2\u6570). S\xD7S\u2192S.\n    Mapping m_mapping;          // S m_mapping(F\
    \ f,S x):=(\u5199\u50CF). f(x).\n    Composition m_composition;  // F m_composition(F\
    \ f,F g):=(\u5199\u50CF\u306E\u5408\u6210). f\u2218g.\n    S m_e;            \
    \          // m_e:=(\u5358\u4F4D\u5143).\n    F m_id;                     // m_id:=(\u6052\
    \u7B49\u5199\u50CF).\n    int m_sz;                   // m_sz:=(\u8981\u7D20\u6570\
    ).\n    int m_n;                    // m_n:=(\u5B8C\u5168\u4E8C\u5206\u6728\u306E\
    \u8449\u6570).\n    int m_depth;                // m_depth:=(\u5B8C\u5168\u4E8C\
    \u5206\u6728\u306E\u6DF1\u3055).\n    std::vector<S> m_tree;      // m_tree(2n)[]:=(\u5B8C\
    \u5168\u4E8C\u5206\u6728). 1-based index.\n    std::vector<F> m_lazy;      //\
    \ m_lazy(n)[k]:=(m_tree[k]\u306E\u5B50 (m_tree[2k], m_tree[2k+1]) \u306B\u5BFE\
    \u3059\u308B\u9045\u5EF6\u8A55\u4FA1).\n\n    void apply0(int k, const F &f) {\n\
    \        assert(1 <= k and k < 2 * m_n);\n        m_tree[k] = m_mapping(f, m_tree[k]);\n\
    \        if(k < m_n) m_lazy[k] = m_composition(f, m_lazy[k]);\n    }\n    void\
    \ push(int k) {\n        assert(1 <= k and k < m_n);\n        apply0(k << 1, m_lazy[k]);\n\
    \        apply0(k << 1 | 1, m_lazy[k]);\n        m_lazy[k] = identity_mapping();\n\
    \    }\n    void update(int k) {\n        assert(1 <= k and k < m_n);\n      \
    \  m_tree[k] = m_op(m_tree[k << 1], m_tree[k << 1 | 1]);\n    }\n\npublic:\n \
    \   // constructor. O(N).\n    LazySegTree() {}\n    explicit LazySegTree(const\
    \ Op &op, const Mapping &mapping, const Composition &composition, const S &e,\
    \ const F &id, size_t n)\n        : m_op(op), m_mapping(mapping), m_composition(composition),\
    \ m_e(e), m_id(id), m_sz(n), m_n(1), m_depth(0) {\n        while(m_n < size())\
    \ m_n <<= 1, m_depth++;\n        m_tree.assign(2 * m_n, identity());\n       \
    \ m_lazy.assign(m_n, identity_mapping());\n    }\n    explicit LazySegTree(const\
    \ Op &op, const Mapping &mapping, const Composition &composition, const S &e,\
    \ const F &id, const std::vector<S> &v)\n        : LazySegTree(op, mapping, composition,\
    \ e, id, v.size()) {\n        std::copy(v.begin(), v.end(), m_tree.begin() + m_n);\n\
    \        for(int i = m_n - 1; i >= 1; --i) update(i);\n    }\n\n    // \u8981\u7D20\
    \u6570\u3092\u8FD4\u3059\uFF0E\n    int size() const { return m_sz; }\n    //\
    \ \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\u3092\u8FD4\u3059\uFF0E\n \
    \   S identity() const { return m_e; }\n    // \u6052\u7B49\u5199\u50CF\u3092\u8FD4\
    \u3059\uFF0E\n    F identity_mapping() const { return m_id; }\n    // k\u756A\u76EE\
    \u306E\u8981\u7D20\u3092a\u306B\u7F6E\u304D\u63DB\u3048\u308B\uFF0EO(logN).\n\
    \    void set(int k, const S &a) {\n        assert(0 <= k and k < size());\n \
    \       k += m_n;\n        for(int i = m_depth; i >= 1; --i) push(k >> i);\n \
    \       m_tree[k] = a;\n        for(int i = 1; i <= m_depth; ++i) update(k >>\
    \ i);\n    }\n    // \u533A\u9593[l,-)\u306E\u8981\u7D20\u3092v[]\u306B\u7F6E\u304D\
    \u63DB\u3048\u308B\uFF0EO(N).\n    void set(int l, const std::vector<S> &v) {\n\
    \        assert(0 <= l and l + (int)v.size() <= size());\n        if(v.size()\
    \ == 0) return;\n        l += m_n;\n        int r = l + (int)v.size();\n     \
    \   for(int i = m_depth; i >= 1; --i) {\n            for(int j = l >> i, end =\
    \ (r - 1) >> i; j <= end; ++j) push(j);\n        }\n        std::copy(v.begin(),\
    \ v.end(), m_tree.begin() + l);\n        for(int i = 1; i <= m_depth; ++i) {\n\
    \            for(int j = l >> i, end = (r - 1) >> i; j <= end; ++j) update(j);\n\
    \        }\n    }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\u5199\u50CFf\u3092\
    \u7528\u3044\u3066\u66F4\u65B0\u3059\u308B\uFF0EO(logN).\n    void apply(int k,\
    \ const F &f) {\n        assert(0 <= k and k < size());\n        k += m_n;\n \
    \       for(int i = m_depth; i >= 1; --i) push(k >> i);\n        m_tree[k] = m_mapping(f,\
    \ m_tree[k]);\n        for(int i = 1; i <= m_depth; ++i) update(k >> i);\n   \
    \ }\n    // \u533A\u9593[l,r)\u306E\u8981\u7D20\u3092\u5199\u50CFf\u3092\u7528\
    \u3044\u3066\u66F4\u65B0\u3059\u308B\uFF0EO(logN).\n    void apply(int l, int\
    \ r, const F &f) {\n        assert(0 <= l and l <= r and r <= size());\n     \
    \   if(l == r) return;\n        l += m_n, r += m_n;\n        for(int i = m_depth;\
    \ i >= 1; --i) {\n            if((l >> i) << i != l) push(l >> i);\n         \
    \   if((r >> i) << i != r) push((r - 1) >> i);\n        }\n        for(int l2\
    \ = l, r2 = r; l2 < r2; l2 >>= 1, r2 >>= 1) {\n            if(l2 & 1) apply0(l2++,\
    \ f);\n            if(r2 & 1) apply0(--r2, f);\n        }\n        for(int i =\
    \ 1; i <= m_depth; ++i) {\n            if((l >> i) << i != l) update(l >> i);\n\
    \            if((r >> i) << i != r) update((r - 1) >> i);\n        }\n    }\n\
    \    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\u6C42\u3081\u308B\uFF0EO(logN).\n\
    \    S prod(int k) {\n        assert(0 <= k and k < size());\n        k += m_n;\n\
    \        for(int i = m_depth; i >= 1; --i) push(k >> i);\n        return m_tree[k];\n\
    \    }\n    // \u533A\u9593[l,r)\u306E\u8981\u7D20\u306E\u7DCF\u7A4D v[l]\u2022\
    v[l+1]\u2022....\u2022v[r-1] \u3092\u6C42\u3081\u308B\uFF0EO(logN).\n    S prod(int\
    \ l, int r) {\n        assert(0 <= l and l <= r and r <= size());\n        if(l\
    \ == r) return identity();\n        l += m_n, r += m_n;\n        for(int i = m_depth;\
    \ i >= 1; --i) {\n            if((l >> i) << i != l) push(l >> i);\n         \
    \   if((r >> i) << i != r) push((r - 1) >> i);\n        }\n        S val_l = identity(),\
    \ val_r = identity();\n        for(; l < r; l >>= 1, r >>= 1) {\n            if(l\
    \ & 1) val_l = m_op(val_l, m_tree[l++]);\n            if(r & 1) val_r = m_op(m_tree[--r],\
    \ val_r);\n        }\n        return m_op(val_l, val_r);\n    }\n    // \u533A\
    \u9593\u5168\u4F53\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\uFF0E\
    O(1).\n    S prod_all() const { return m_tree[1]; }\n    // jud(prod(l,-))==true\
    \ \u3068\u306A\u308B\u533A\u9593\u306E\u6700\u53F3\u4F4D\u5024\u3092\u4E8C\u5206\
    \u63A2\u7D22\u3059\u308B\uFF0E\n    // \u305F\u3060\u3057\uFF0C\u8981\u7D20\u5217\
    \u306B\u306F\u5358\u8ABF\u6027\u304C\u3042\u308A\uFF0C\u307E\u305F jud(e)==true\
    \ \u3067\u3042\u308B\u3053\u3068\uFF0EO(logN).\n    template <class Func = std::function<bool(const\
    \ S &)> >\n    int most_right(const Func &jud, int l) const {\n        assert(jud(identity())\
    \ == true);\n        assert(0 <= l and l <= size());\n        if(l == size())\
    \ return size();\n        l += m_n;\n        for(int i = m_depth; i >= 1; --i)\
    \ push(l >> i);\n        S val = identity();\n        do {\n            while(!(l\
    \ & 1)) l >>= 1;\n            S &&tmp = m_op(val, m_tree[l]);\n            if(!jud(tmp))\
    \ {\n                while(l < m_n) {\n                    push(l);\n        \
    \            l <<= 1;\n                    S &&tmp2 = m_op(val, m_tree[l]);\n\
    \                    if(jud(tmp2)) val = tmp2, l++;\n                }\n     \
    \           return l - m_n;\n            }\n            val = tmp, l++;\n    \
    \    } while((l & -l) != l);  // (x&-x)==x \u306E\u3068\u304D\uFF0Cx\u306F2\u306E\
    \u968E\u4E57\u6570\uFF0E\n        return size();\n    }\n    // jud(prod(-,r))==true\
    \ \u3068\u306A\u308B\u533A\u9593\u306E\u6700\u5DE6\u4F4D\u5024\u3092\u4E8C\u5206\
    \u63A2\u7D22\u3059\u308B\uFF0E\n    // \u305F\u3060\u3057\uFF0C\u8981\u7D20\u5217\
    \u306B\u306F\u5358\u8ABF\u6027\u304C\u3042\u308A\uFF0C\u307E\u305F jud(e)==true\
    \ \u3067\u3042\u308B\u3053\u3068\uFF0EO(logN).\n    template <class Func = std::function<bool(const\
    \ S &)> >\n    int most_left(const Func &jud, int r) const {\n        assert(jud(identity())\
    \ == true);\n        assert(0 <= r and r <= size());\n        if(r == 0) return\
    \ 0;\n        r += m_n;\n        for(int i = m_depth; i >= 1; --i) push((r - 1)\
    \ >> i);\n        S val = identity();\n        do {\n            r--;\n      \
    \      while(r > 1 and r & 1) r >>= 1;\n            S &&tmp = m_op(m_tree[r],\
    \ val);\n            if(!jud(tmp)) {\n                while(r < m_n) {\n     \
    \               push(r);\n                    r = r << 1 | 1;\n              \
    \      S &&tmp2 = m_op(m_tree[r], val);\n                    if(jud(tmp2)) val\
    \ = tmp2, r--;\n                }\n                return r - m_n + 1;\n     \
    \       }\n            val = tmp;\n        } while((r & -r) != r);  // (x&-x)==x\
    \ \u306E\u3068\u304D\uFF0Cx\u306F2\u306E\u968E\u4E57\u6570\uFF0E\n        return\
    \ 0;\n    }\n    void reset() {\n        std::fill(m_tree.begin(), m_tree.end(),\
    \ identity());\n        std::fill(m_lazy.begin(), m_lazy.end(), identity_mapping());\n\
    \    }\n};\n\n}  // namespace algorithm\n\n\n#line 1 \"lib/Math/ModularArithmetic/modint.hpp\"\
    \n\n\n\n/**\n * @brief Modint\u69CB\u9020\u4F53\n * @docs docs/Math/ModularArithmetic/modint.md\n\
    \ */\n\n#line 10 \"lib/Math/ModularArithmetic/modint.hpp\"\n#include <utility>\n\
    \n#line 1 \"lib/Math/ModularArithmetic/modint_base.hpp\"\n\n\n\n/**\n * @brief\
    \ Modint\u69CB\u9020\u4F53\u306E\u57FA\u5E95\u30AF\u30E9\u30B9\n * @docs docs/Math/ModularArithmetic/modint_base.md\n\
    \ */\n\n#include <type_traits>\n\nnamespace algorithm {\n\nclass ModintBase {};\n\
    \ntemplate <class T>\nusing is_modint = std::is_base_of<ModintBase, T>;\n\ntemplate\
    \ <class T>\ninline constexpr bool is_modint_v = is_modint<T>::value;\n\n}  //\
    \ namespace algorithm\n\n\n#line 13 \"lib/Math/ModularArithmetic/modint.hpp\"\n\
    \nnamespace algorithm {\n\ntemplate <int mod>\nclass Modint : ModintBase {\n \
    \   long long val;\n\n    constexpr void normalize() {\n        if(val < -mod\
    \ or mod <= val) val %= mod;\n        if(val < 0) val += mod;\n    }\n\npublic:\n\
    \    constexpr Modint() : Modint(0) {}\n    constexpr Modint(long long val_) :\
    \ val(val_) {\n        static_assert(mod >= 1);\n        normalize();\n    }\n\
    \n    constexpr Modint operator+() const { return Modint(*this); }\n    constexpr\
    \ Modint operator-() const { return (val == 0 ? Modint(*this) : Modint(mod - val));\
    \ }\n    constexpr Modint &operator++() {\n        val++;\n        if(val == mod)\
    \ val = 0;\n        return *this;\n    }\n    constexpr Modint &operator--() {\n\
    \        if(val == 0) val = mod;\n        val--;\n        return *this;\n    }\n\
    \    constexpr Modint operator++(int) {\n        Modint res = *this;\n       \
    \ ++(*this);\n        return res;\n    }\n    constexpr Modint operator--(int)\
    \ {\n        Modint res = *this;\n        --(*this);\n        return res;\n  \
    \  }\n    constexpr Modint &operator+=(const Modint &rhs) {\n        val += rhs.val;\n\
    \        if(val >= mod) val -= mod;\n        return *this;\n    }\n    constexpr\
    \ Modint &operator-=(const Modint &rhs) {\n        val -= rhs.val;\n        if(val\
    \ < 0) val += mod;\n        return *this;\n    }\n    constexpr Modint &operator*=(const\
    \ Modint &rhs) {\n        val = val * rhs.val % mod;\n        return *this;\n\
    \    }\n    constexpr Modint &operator/=(const Modint &rhs) { return *this *=\
    \ rhs.inv(); }\n\n    friend constexpr bool operator==(const Modint &lhs, const\
    \ Modint &rhs) { return lhs.val == rhs.val; }\n    friend constexpr bool operator!=(const\
    \ Modint &lhs, const Modint &rhs) { return lhs.val != rhs.val; }\n    friend constexpr\
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
    \ // namespace algorithm\n\n\n#line 8 \"test/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    using\
    \ S = struct {\n        algorithm::mint998244353 val;\n        int size;\n   \
    \ };\n    using F = struct {\n        algorithm::mint998244353 a;\n        algorithm::mint998244353\
    \ b;\n    };\n    constexpr S e = (S){0, 0};\n    constexpr F id = (F){1, 0};\n\
    \    auto op = [&](const S &lhs, const S &rhs) -> S { return (S){lhs.val + rhs.val,\
    \ lhs.size + rhs.size}; };\n    auto mapping = [&](const F &f, const S &x) ->\
    \ S { return (S){f.a * x.val + f.b * x.size, x.size}; };\n    auto composition\
    \ = [&](const F &f, const F &g) -> F { return (F){f.a * g.a, f.a * g.b + f.b};\
    \ };\n    algorithm::LazySegTree<S, F> segtree(op, mapping, composition, e, id,\
    \ std::vector<S>(n, (S){0, 1}));\n\n    for(int i = 0; i < n; ++i) {\n       \
    \ algorithm::mint998244353 a;\n        std::cin >> a;\n\n        segtree.set(i,\
    \ (S){a, 1});\n    }\n\n    while(q--) {\n        int type;\n        int l, r;\n\
    \        std::cin >> type >> l >> r;\n\n        if(type == 0) {\n            algorithm::mint998244353\
    \ b, c;\n            std::cin >> b >> c;\n\n            segtree.apply(l, r, (F){b,\
    \ c});\n        } else {\n            auto &&ans = segtree.prod(l, r).val;\n \
    \           std::cout << ans << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../lib/DataStructure/SegmentTree/lazy_segment_tree.hpp\"\
    \n#include \"../lib/Math/ModularArithmetic/modint.hpp\"\n\nint main() {\n    int\
    \ n;\n    int q;\n    std::cin >> n >> q;\n\n    using S = struct {\n        algorithm::mint998244353\
    \ val;\n        int size;\n    };\n    using F = struct {\n        algorithm::mint998244353\
    \ a;\n        algorithm::mint998244353 b;\n    };\n    constexpr S e = (S){0,\
    \ 0};\n    constexpr F id = (F){1, 0};\n    auto op = [&](const S &lhs, const\
    \ S &rhs) -> S { return (S){lhs.val + rhs.val, lhs.size + rhs.size}; };\n    auto\
    \ mapping = [&](const F &f, const S &x) -> S { return (S){f.a * x.val + f.b *\
    \ x.size, x.size}; };\n    auto composition = [&](const F &f, const F &g) -> F\
    \ { return (F){f.a * g.a, f.a * g.b + f.b}; };\n    algorithm::LazySegTree<S,\
    \ F> segtree(op, mapping, composition, e, id, std::vector<S>(n, (S){0, 1}));\n\
    \n    for(int i = 0; i < n; ++i) {\n        algorithm::mint998244353 a;\n    \
    \    std::cin >> a;\n\n        segtree.set(i, (S){a, 1});\n    }\n\n    while(q--)\
    \ {\n        int type;\n        int l, r;\n        std::cin >> type >> l >> r;\n\
    \n        if(type == 0) {\n            algorithm::mint998244353 b, c;\n      \
    \      std::cin >> b >> c;\n\n            segtree.apply(l, r, (F){b, c});\n  \
    \      } else {\n            auto &&ans = segtree.prod(l, r).val;\n          \
    \  std::cout << ans << \"\\n\";\n        }\n    }\n}\n"
  dependsOn:
  - lib/DataStructure/SegmentTree/lazy_segment_tree.hpp
  - lib/Math/ModularArithmetic/modint.hpp
  - lib/Math/ModularArithmetic/modint_base.hpp
  isVerificationFile: true
  path: test/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2024-09-12 01:23:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
- /verify/test/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp.html
title: test/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
---

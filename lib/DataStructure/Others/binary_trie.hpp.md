---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DSL_2_B-binary_trie.test.cpp
    title: verify/aoj-DSL_2_B-binary_trie.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-set_xor_min-binary_trie.test.cpp
    title: verify/yosupo-set_xor_min-binary_trie.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/DataStructure/Others/binary_trie.hpp\"\n\n\n\n#include\
    \ <bitset>\n#include <cassert>\n\nnamespace algorithm {\n\ntemplate <std::size_t\
    \ w = 32>\nclass BinaryTrie {\npublic:\n    using size_type = std::size_t;\n\n\
    private:\n    struct Node {\n        size_type cnt;  // cnt:=(\u81EA\u8EAB\u3092\
    \u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306B\u542B\u307E\u308C\u308B\u8981\
    \u7D20\u306E\u6570).\n        Node *ch[2];    // ch[]:=(\u5B50\u306E\u30DD\u30A4\
    \u30F3\u30BF).\n        Node() : cnt(0), ch{nullptr, nullptr} {}\n    };\n\n \
    \   Node *m_root;           // m_root:=(\u6839\u306E\u30DD\u30A4\u30F3\u30BF).\n\
    \    std::bitset<w> m_bias;  // m_bias:=(xor\u306E\u64CD\u4F5C\u5024).\n\n   \
    \ Node *find(Node *p, const std::bitset<w> &x, std::size_t itr = w) const {\n\
    \        if(!p) return nullptr;\n        if(itr == 0) return p;\n        return\
    \ find(p->ch[x[itr - 1] ^ m_bias[itr - 1]], x, itr - 1);\n    }\n    Node *add(Node\
    \ *p, size_type cnt, const std::bitset<w> &x, std::size_t itr = w) {  // top down.\n\
    \        if(!p) p = new Node();\n        p->cnt += cnt;\n        if(itr == 0)\
    \ return p;\n        bool b = x[itr - 1] ^ m_bias[itr - 1];\n        p->ch[b]\
    \ = add(p->ch[b], cnt, x, itr - 1);\n        return p;\n    }\n    Node *sub(Node\
    \ *p, size_type cnt, const std::bitset<w> &x, std::size_t itr = w) {  // bottom\
    \ up.\n        assert(p and cnt <= p->cnt);\n        if(itr > 0) {\n         \
    \   bool b = x[itr - 1] ^ m_bias[itr - 1];\n            p->ch[b] = sub(p->ch[b],\
    \ cnt, x, itr - 1);\n        }\n        if(p->cnt == cnt) {\n            delete\
    \ p;\n            return p = nullptr;\n        }\n        p->cnt -= cnt;\n   \
    \     return p;\n    }\n    std::bitset<w> get(Node *p, size_type k, std::size_t\
    \ itr = w) const {\n        assert(p);\n        if(itr == 0) return 0;\n     \
    \   bool b = m_bias[itr - 1];\n        size_type m = (p->ch[b] ? p->ch[b]->cnt\
    \ : 0);\n        if(k < m) return get(p->ch[b], k, itr - 1);\n        return get(p->ch[!b],\
    \ k - m, itr - 1).set(itr - 1);\n    }\n    size_type get_lower(Node *p, const\
    \ std::bitset<w> &x, std::size_t itr = w) const {\n        if(!p or itr == 0)\
    \ return 0;\n        size_type res = get_lower(p->ch[x[itr - 1] ^ m_bias[itr -\
    \ 1]], x, itr - 1);\n        if(x[itr - 1] and p->ch[m_bias[itr - 1]]) res +=\
    \ p->ch[m_bias[itr - 1]]->cnt;\n        return res;\n    }\n    size_type get_upper(Node\
    \ *p, const std::bitset<w> &x, std::size_t itr = w) const {\n        if(!p) return\
    \ 0;\n        if(itr == 0) return p->cnt;\n        size_type res = get_upper(p->ch[x[itr\
    \ - 1] ^ m_bias[itr - 1]], x, itr - 1);\n        if(x[itr - 1] and p->ch[m_bias[itr\
    \ - 1]]) res += p->ch[m_bias[itr - 1]]->cnt;\n        return res;\n    }\n   \
    \ Node *clear(Node *p) {\n        if(!p) return nullptr;\n        for(Node *&next\
    \ : p->ch) next = clear(next);\n        delete p;\n        return p = nullptr;\n\
    \    }\n\npublic:\n    BinaryTrie() : m_root(nullptr), m_bias(0) {}\n    ~BinaryTrie()\
    \ {\n        clear();\n    }\n\n    // \u7BA1\u7406\u3059\u308B\u975E\u8CA0\u6574\
    \u6570\u5024\u306E\u30D3\u30C3\u30C8\u9577\u3092\u53D6\u5F97\u3059\u308B\uFF0E\
    \n    static constexpr size_type word_size() { return w; }\n    // \u96C6\u5408\
    \u304C\u7A7A\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(1).\n    bool empty() const\
    \ { return !m_root; }\n    // \u96C6\u5408\u306E\u8981\u7D20\u6570\u3092\u53D6\
    \u5F97\u3059\u308B\uFF0EO(1).\n    size_type size() const { return (m_root ? m_root->cnt\
    \ : 0); }\n    // \u591A\u91CD\u96C6\u5408\u306B\u975E\u8CA0\u6574\u6570x\u304C\
    \u542B\u307E\u308C\u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(w).\n    bool contains(const\
    \ std::bitset<w> &x) const { return find(m_root, x); }\n    // \u591A\u91CD\u96C6\
    \u5408\u306B\u542B\u307E\u308C\u308B\u975E\u8CA0\u6574\u6570x\u306E\u500B\u6570\
    \u3092\u53D6\u5F97\u3059\u308B\uFF0EO(w).\n    size_type count(const std::bitset<w>\
    \ &x) const {\n        Node *p = find(m_root, x);\n        return (p ? p->cnt\
    \ : 0);\n    }\n    // \u591A\u91CD\u96C6\u5408\u306B\u975E\u8CA0\u6574\u6570\
    x\u3092\u8FFD\u52A0\u3059\u308B\uFF0EO(w).\n    void insert(const std::bitset<w>\
    \ &x, size_type cnt = 1) {\n        if(cnt == 0) return;\n        m_root = add(m_root,\
    \ cnt, x);\n    }\n    // \u591A\u91CD\u96C6\u5408\u306B\u975E\u8CA0\u6574\u6570\
    x\u3092\u524A\u9664\u3059\u308B\uFF0EO(w).\n    void erase(const std::bitset<w>\
    \ &x) { erase(x, count(x)); }\n    void erase(const std::bitset<w> &x, size_type\
    \ cnt) {\n        if(cnt == 0) return;\n        m_root = sub(m_root, cnt, x);\n\
    \    }\n    // \u591A\u91CD\u96C6\u5408\u5185\u3067k\u756A\u76EE\u306B\u5C0F\u3055\
    \u3044\u975E\u8CA0\u6574\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E0-based index.\
    \ O(w).\n    std::bitset<w> kth_element(size_type k) const {\n        assert(k\
    \ < size());\n        return get(m_root, k);\n    }\n    // \u96C6\u5408\u5185\
    \u3067\u6700\u5C0F\u306E\u975E\u8CA0\u6574\u6570\u3092\u53D6\u5F97\u3059\u308B\
    \uFF0EO(w).\n    std::bitset<w> min_element() const {\n        assert(!empty());\n\
    \        return get(m_root, 0);\n    }\n    // \u96C6\u5408\u5185\u3067\u6700\u5927\
    \u306E\u975E\u8CA0\u6574\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(w).\n    std::bitset<w>\
    \ max_element() const {\n        assert(!empty());\n        return get(m_root,\
    \ size() - 1);\n    }\n    // x\u4EE5\u4E0A\u3067\u3042\u308B\u975E\u8CA0\u6574\
    \u6570\u304C\u73FE\u308C\u308B\u5148\u982D\u306E\u4F4D\u7F6E\u3092\u53D6\u5F97\
    \u3059\u308B\uFF0EO(w).\n    size_type lower_bound(const std::bitset<w> &x) const\
    \ { return get_lower(m_root, x); }\n    // x\u3088\u308A\u5927\u304D\u3044\u975E\
    \u8CA0\u6574\u6570\u304C\u73FE\u308C\u308B\u5148\u982D\u306E\u4F4D\u7F6E\u3092\
    \u53D6\u5F97\u3059\u308B\uFF0EO(w).\n    size_type upper_bound(const std::bitset<w>\
    \ &x) const { return get_upper(m_root, x); }\n    // \u5168\u8981\u7D20\u306B\u975E\
    \u8CA0\u6574\u6570x\u3092\u7528\u3044\u3066xor\u306E\u64CD\u4F5C\u3092\u884C\u3046\
    \uFF0E\n    void xor_all(const std::bitset<w> &x) { m_bias ^= x; }\n    void clear()\
    \ { m_root = clear(m_root); }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const BinaryTrie &rhs) {\n        std::bitset<w> x(0);\n        auto dfs\
    \ = [&](auto self, Node *p, size_type itr = w) -> void {\n            if(!p) return;\n\
    \            if(itr == 0) {\n                os << \"  {\" << x;\n           \
    \     if(w <= 64) os << \" (\" << x.to_ullong() << \")\";\n                os\
    \ << \", \" << p->cnt << \"}\\n\";\n                return;\n            }\n \
    \           for(bool b : {0, 1}) {\n                x[itr - 1] = b;\n        \
    \        self(self, p->ch[b ^ rhs.m_bias[itr - 1]], itr - 1);\n            }\n\
    \        };\n        os << \"[\\n\";\n        dfs(dfs, rhs.m_root);\n        return\
    \ os << \"]\";\n    }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_BINARY_TRIE_HPP\n#define ALGORITHM_BINARY_TRIE_HPP 1\n\n\
    #include <bitset>\n#include <cassert>\n\nnamespace algorithm {\n\ntemplate <std::size_t\
    \ w = 32>\nclass BinaryTrie {\npublic:\n    using size_type = std::size_t;\n\n\
    private:\n    struct Node {\n        size_type cnt;  // cnt:=(\u81EA\u8EAB\u3092\
    \u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306B\u542B\u307E\u308C\u308B\u8981\
    \u7D20\u306E\u6570).\n        Node *ch[2];    // ch[]:=(\u5B50\u306E\u30DD\u30A4\
    \u30F3\u30BF).\n        Node() : cnt(0), ch{nullptr, nullptr} {}\n    };\n\n \
    \   Node *m_root;           // m_root:=(\u6839\u306E\u30DD\u30A4\u30F3\u30BF).\n\
    \    std::bitset<w> m_bias;  // m_bias:=(xor\u306E\u64CD\u4F5C\u5024).\n\n   \
    \ Node *find(Node *p, const std::bitset<w> &x, std::size_t itr = w) const {\n\
    \        if(!p) return nullptr;\n        if(itr == 0) return p;\n        return\
    \ find(p->ch[x[itr - 1] ^ m_bias[itr - 1]], x, itr - 1);\n    }\n    Node *add(Node\
    \ *p, size_type cnt, const std::bitset<w> &x, std::size_t itr = w) {  // top down.\n\
    \        if(!p) p = new Node();\n        p->cnt += cnt;\n        if(itr == 0)\
    \ return p;\n        bool b = x[itr - 1] ^ m_bias[itr - 1];\n        p->ch[b]\
    \ = add(p->ch[b], cnt, x, itr - 1);\n        return p;\n    }\n    Node *sub(Node\
    \ *p, size_type cnt, const std::bitset<w> &x, std::size_t itr = w) {  // bottom\
    \ up.\n        assert(p and cnt <= p->cnt);\n        if(itr > 0) {\n         \
    \   bool b = x[itr - 1] ^ m_bias[itr - 1];\n            p->ch[b] = sub(p->ch[b],\
    \ cnt, x, itr - 1);\n        }\n        if(p->cnt == cnt) {\n            delete\
    \ p;\n            return p = nullptr;\n        }\n        p->cnt -= cnt;\n   \
    \     return p;\n    }\n    std::bitset<w> get(Node *p, size_type k, std::size_t\
    \ itr = w) const {\n        assert(p);\n        if(itr == 0) return 0;\n     \
    \   bool b = m_bias[itr - 1];\n        size_type m = (p->ch[b] ? p->ch[b]->cnt\
    \ : 0);\n        if(k < m) return get(p->ch[b], k, itr - 1);\n        return get(p->ch[!b],\
    \ k - m, itr - 1).set(itr - 1);\n    }\n    size_type get_lower(Node *p, const\
    \ std::bitset<w> &x, std::size_t itr = w) const {\n        if(!p or itr == 0)\
    \ return 0;\n        size_type res = get_lower(p->ch[x[itr - 1] ^ m_bias[itr -\
    \ 1]], x, itr - 1);\n        if(x[itr - 1] and p->ch[m_bias[itr - 1]]) res +=\
    \ p->ch[m_bias[itr - 1]]->cnt;\n        return res;\n    }\n    size_type get_upper(Node\
    \ *p, const std::bitset<w> &x, std::size_t itr = w) const {\n        if(!p) return\
    \ 0;\n        if(itr == 0) return p->cnt;\n        size_type res = get_upper(p->ch[x[itr\
    \ - 1] ^ m_bias[itr - 1]], x, itr - 1);\n        if(x[itr - 1] and p->ch[m_bias[itr\
    \ - 1]]) res += p->ch[m_bias[itr - 1]]->cnt;\n        return res;\n    }\n   \
    \ Node *clear(Node *p) {\n        if(!p) return nullptr;\n        for(Node *&next\
    \ : p->ch) next = clear(next);\n        delete p;\n        return p = nullptr;\n\
    \    }\n\npublic:\n    BinaryTrie() : m_root(nullptr), m_bias(0) {}\n    ~BinaryTrie()\
    \ {\n        clear();\n    }\n\n    // \u7BA1\u7406\u3059\u308B\u975E\u8CA0\u6574\
    \u6570\u5024\u306E\u30D3\u30C3\u30C8\u9577\u3092\u53D6\u5F97\u3059\u308B\uFF0E\
    \n    static constexpr size_type word_size() { return w; }\n    // \u96C6\u5408\
    \u304C\u7A7A\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(1).\n    bool empty() const\
    \ { return !m_root; }\n    // \u96C6\u5408\u306E\u8981\u7D20\u6570\u3092\u53D6\
    \u5F97\u3059\u308B\uFF0EO(1).\n    size_type size() const { return (m_root ? m_root->cnt\
    \ : 0); }\n    // \u591A\u91CD\u96C6\u5408\u306B\u975E\u8CA0\u6574\u6570x\u304C\
    \u542B\u307E\u308C\u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(w).\n    bool contains(const\
    \ std::bitset<w> &x) const { return find(m_root, x); }\n    // \u591A\u91CD\u96C6\
    \u5408\u306B\u542B\u307E\u308C\u308B\u975E\u8CA0\u6574\u6570x\u306E\u500B\u6570\
    \u3092\u53D6\u5F97\u3059\u308B\uFF0EO(w).\n    size_type count(const std::bitset<w>\
    \ &x) const {\n        Node *p = find(m_root, x);\n        return (p ? p->cnt\
    \ : 0);\n    }\n    // \u591A\u91CD\u96C6\u5408\u306B\u975E\u8CA0\u6574\u6570\
    x\u3092\u8FFD\u52A0\u3059\u308B\uFF0EO(w).\n    void insert(const std::bitset<w>\
    \ &x, size_type cnt = 1) {\n        if(cnt == 0) return;\n        m_root = add(m_root,\
    \ cnt, x);\n    }\n    // \u591A\u91CD\u96C6\u5408\u306B\u975E\u8CA0\u6574\u6570\
    x\u3092\u524A\u9664\u3059\u308B\uFF0EO(w).\n    void erase(const std::bitset<w>\
    \ &x) { erase(x, count(x)); }\n    void erase(const std::bitset<w> &x, size_type\
    \ cnt) {\n        if(cnt == 0) return;\n        m_root = sub(m_root, cnt, x);\n\
    \    }\n    // \u591A\u91CD\u96C6\u5408\u5185\u3067k\u756A\u76EE\u306B\u5C0F\u3055\
    \u3044\u975E\u8CA0\u6574\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E0-based index.\
    \ O(w).\n    std::bitset<w> kth_element(size_type k) const {\n        assert(k\
    \ < size());\n        return get(m_root, k);\n    }\n    // \u96C6\u5408\u5185\
    \u3067\u6700\u5C0F\u306E\u975E\u8CA0\u6574\u6570\u3092\u53D6\u5F97\u3059\u308B\
    \uFF0EO(w).\n    std::bitset<w> min_element() const {\n        assert(!empty());\n\
    \        return get(m_root, 0);\n    }\n    // \u96C6\u5408\u5185\u3067\u6700\u5927\
    \u306E\u975E\u8CA0\u6574\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(w).\n    std::bitset<w>\
    \ max_element() const {\n        assert(!empty());\n        return get(m_root,\
    \ size() - 1);\n    }\n    // x\u4EE5\u4E0A\u3067\u3042\u308B\u975E\u8CA0\u6574\
    \u6570\u304C\u73FE\u308C\u308B\u5148\u982D\u306E\u4F4D\u7F6E\u3092\u53D6\u5F97\
    \u3059\u308B\uFF0EO(w).\n    size_type lower_bound(const std::bitset<w> &x) const\
    \ { return get_lower(m_root, x); }\n    // x\u3088\u308A\u5927\u304D\u3044\u975E\
    \u8CA0\u6574\u6570\u304C\u73FE\u308C\u308B\u5148\u982D\u306E\u4F4D\u7F6E\u3092\
    \u53D6\u5F97\u3059\u308B\uFF0EO(w).\n    size_type upper_bound(const std::bitset<w>\
    \ &x) const { return get_upper(m_root, x); }\n    // \u5168\u8981\u7D20\u306B\u975E\
    \u8CA0\u6574\u6570x\u3092\u7528\u3044\u3066xor\u306E\u64CD\u4F5C\u3092\u884C\u3046\
    \uFF0E\n    void xor_all(const std::bitset<w> &x) { m_bias ^= x; }\n    void clear()\
    \ { m_root = clear(m_root); }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const BinaryTrie &rhs) {\n        std::bitset<w> x(0);\n        auto dfs\
    \ = [&](auto self, Node *p, size_type itr = w) -> void {\n            if(!p) return;\n\
    \            if(itr == 0) {\n                os << \"  {\" << x;\n           \
    \     if(w <= 64) os << \" (\" << x.to_ullong() << \")\";\n                os\
    \ << \", \" << p->cnt << \"}\\n\";\n                return;\n            }\n \
    \           for(bool b : {0, 1}) {\n                x[itr - 1] = b;\n        \
    \        self(self, p->ch[b ^ rhs.m_bias[itr - 1]], itr - 1);\n            }\n\
    \        };\n        os << \"[\\n\";\n        dfs(dfs, rhs.m_root);\n        return\
    \ os << \"]\";\n    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/DataStructure/Others/binary_trie.hpp
  requiredBy: []
  timestamp: '2025-06-16 01:20:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-set_xor_min-binary_trie.test.cpp
  - verify/aoj-DSL_2_B-binary_trie.test.cpp
documentation_of: lib/DataStructure/Others/binary_trie.hpp
layout: document
title: "Binary Trie\uFF08\u4E8C\u5206\u30C8\u30E9\u30A4\u6728\uFF09"
---


## 概要

$w$ ビット非負整数を要素とする多重集合を表すデータ構造．

データ構造は $0$ と $1$ をキーとする Trie 木であり，次のクエリ処理を $\mathcal{O}(w)$ で行う．

- $\operatorname{insert}(x,c)$：多重集合 $S$ に非負整数 $x$ を $c$ 個挿入する．
- $\operatorname{erase}(x,c)$：多重集合 $S$ から非負整数 $x$ を $c$ 個削除する．
- $\operatorname{count}(x)$：多重集合 $S$ に含まれる非負整数 $x$ の個数を求める．
- $\operatorname{kth\_element}(k)$：多重集合 $S$ 内で $k$ 番目に小さい要素を取得する．

また，多重集合内の全ての非負整数に対し，任意の値で排他的論理和の操作を行うこともできる．


## 参考

1. Pat Morin. "13.1 BinaryTrie：二分トライ木". みんなのデータ構造. 堀江 慧訳. ラムダノート, 2018, pp.226-238.
1. "トライ (データ構造)". Wikipedia. <https://ja.wikipedia.org/wiki/トライ_(データ構造)>.
1. kazuma8128. "非負整数値を扱う Trie について". HatenaBlog. <https://kazuma8128.hatenablog.com/entry/2018/05/06/022654>.
1. "Trie木 (Binary Trie)". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/trie>.


## 問題

- "C - データ構造". AtCoder Regular Contest 033. AtCoder. <https://atcoder.jp/contests/arc033/tasks/arc033_3>.

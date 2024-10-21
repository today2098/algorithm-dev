---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-DSL_2_B-binary_trie.test.cpp
    title: test/aoj-DSL_2_B-binary_trie.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-set_xor_min-binary_trie.test.cpp
    title: test/yosupo-set_xor_min-binary_trie.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/DataStructure/Others/binary_trie.md
    document_title: "Binary Trie\uFF08\u975E\u8CA0\u6574\u6570\u5024\u3092\u8981\u7D20\
      \u3068\u3059\u308B\u591A\u91CD\u96C6\u5408\uFF09"
    links: []
  bundledCode: "#line 1 \"lib/DataStructure/Others/binary_trie.hpp\"\n\n\n\n/**\n\
    \ * @brief Binary Trie\uFF08\u975E\u8CA0\u6574\u6570\u5024\u3092\u8981\u7D20\u3068\
    \u3059\u308B\u591A\u91CD\u96C6\u5408\uFF09\n * @docs docs/DataStructure/Others/binary_trie.md\n\
    \ */\n\n#include <bitset>\n#include <cassert>\n#include <cstddef>\n\nnamespace\
    \ algorithm {\n\n// Binary Trie\uFF08\u975E\u8CA0\u6574\u6570\u5024\u3092\u8981\
    \u7D20\u3068\u3059\u308B\u591A\u91CD\u96C6\u5408\uFF09.\ntemplate <size_t B =\
    \ 32>  // B:\u30D3\u30C3\u30C8\u9577.\nclass BinaryTrie {\npublic:\n    using\
    \ size_type = size_t;\n\nprivate:\n    struct Node {\n        size_type cnt; \
    \ // cnt:=(\u81EA\u8EAB\u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306B\u542B\
    \u307E\u308C\u308B\u8981\u7D20\u306E\u6570).\n        Node *ch[2];    // ch[]:=(\u5B50\
    \u306E\u30DD\u30A4\u30F3\u30BF).\n        Node() : cnt(0), ch{nullptr, nullptr}\
    \ {}\n    };\n\n    Node *m_root;           // m_root:=(\u6839\u306E\u30DD\u30A4\
    \u30F3\u30BF).\n    std::bitset<B> m_bias;  // m_bias:=(xor\u306E\u64CD\u4F5C\u5024\
    ).\n\n    Node *find(const std::bitset<B> &x) const {\n        if(!m_root) return\
    \ nullptr;\n        Node *p = m_root;\n        for(int i = B - 1; i >= 0; --i)\
    \ {\n            p = p->ch[x[i] ^ m_bias[i]];\n            if(!p) return nullptr;\n\
    \        }\n        return p;\n    }\n    Node *add(Node *p, const std::bitset<B>\
    \ &x, size_type cnt, int shift = B - 1) {  // top down.\n        if(!p) p = new\
    \ Node();\n        p->cnt += cnt;\n        if(shift >= 0) {\n            bool\
    \ b = x[shift] ^ m_bias[shift];\n            p->ch[b] = add(p->ch[b], x, cnt,\
    \ shift - 1);\n        }\n        return p;\n    }\n    Node *sub(Node *p, const\
    \ std::bitset<B> &x, size_type cnt, int shift = B - 1) {  // bottom up.\n    \
    \    assert(p and p->cnt >= cnt);\n        if(shift >= 0) {\n            bool\
    \ b = x[shift] ^ m_bias[shift];\n            p->ch[b] = sub(p->ch[b], x, cnt,\
    \ shift - 1);\n        }\n        p->cnt -= cnt;\n        if(p->cnt == 0) {\n\
    \            delete p;\n            p = nullptr;\n        }\n        return p;\n\
    \    }\n    std::bitset<B> get(Node *p, size_type k, int shift = B - 1) const\
    \ {\n        assert(p);\n        if(shift < 0) return 0;\n        bool b = m_bias[shift];\n\
    \        size_type m = (p->ch[b] ? p->ch[b]->cnt : 0);\n        if(k < m) return\
    \ get(p->ch[b], k, shift - 1);\n        return get(p->ch[!b], k - m, shift - 1)\
    \ | std::bitset<B>(0).set(shift);\n    }\n    size_type get_lower(Node *p, const\
    \ std::bitset<B> &x, int shift = B - 1) const {\n        if(!p) return 0;\n  \
    \      if(shift < 0) return 0;\n        size_type res = get_lower(p->ch[x[shift]\
    \ ^ m_bias[shift]], x, shift - 1);\n        if(x[shift] and p->ch[m_bias[shift]])\
    \ res += p->ch[m_bias[shift]]->cnt;\n        return res;\n    }\n    size_type\
    \ get_upper(Node *p, const std::bitset<B> &x, int shift = B - 1) const {\n   \
    \     if(!p) return 0;\n        if(shift < 0) return p->cnt;\n        size_type\
    \ res = get_upper(p->ch[x[shift] ^ m_bias[shift]], x, shift - 1);\n        if(x[shift]\
    \ and p->ch[m_bias[shift]]) res += p->ch[m_bias[shift]]->cnt;\n        return\
    \ res;\n    }\n    Node *clear_dfs(Node *p) {\n        if(!p) return nullptr;\n\
    \        for(Node *&next : p->ch) next = clear_dfs(next);\n        delete p;\n\
    \        return p = nullptr;\n    }\n    void print_dfs(std::ostream &os, Node\
    \ *p, std::bitset<B> &x, int shift = B - 1) const {\n        if(shift < 0) {\n\
    \            os << \"  {0b\" << x;\n            if(B <= 64) os << \" (\" << x.to_ullong()\
    \ << \")\";\n            os << \", \" << p->cnt << \"}\\n\";\n            return;\n\
    \        }\n        for(bool b : {0, 1}) {\n            x[shift] = b;\n      \
    \      b ^= m_bias[shift];\n            if(p->ch[b]) print_dfs(os, p->ch[b], x,\
    \ shift - 1);\n        }\n    }\n\npublic:\n    BinaryTrie() : m_root(nullptr),\
    \ m_bias(0) {}\n    ~BinaryTrie() {\n        clear();\n    }\n\n    std::bitset<B>\
    \ operator[](size_type k) const { return kth_element(k); }\n\n    // \u7BA1\u7406\
    \u3059\u308B\u975E\u8CA0\u6574\u6570\u5024\u306E\u30D3\u30C3\u30C8\u9577\u3092\
    \u8FD4\u3059\uFF0E\n    static constexpr size_t bit_length() { return B; }\n \
    \   // \u96C6\u5408\u304C\u7A7A\u304B\u3069\u3046\u304B\u5224\u5B9A\u3059\u308B\
    \uFF0EO(1).\n    bool empty() const { return !m_root; }\n    // \u5168\u8981\u7D20\
    \u6570\u3092\u8FD4\u3059\uFF0EO(1).\n    size_type size() const { return (m_root\
    \ ? m_root->cnt : 0); }\n    // \u5024x\u306E\u8981\u7D20\u304C\u96C6\u5408\u306B\
    \u542B\u307E\u308C\u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(B).\n    bool exists(const\
    \ std::bitset<B> &x) const { return find(x); }\n    // \u5024x\u306E\u8981\u7D20\
    \u6570\u3092\u8FD4\u3059\uFF0EO(B).\n    size_type count(const std::bitset<B>\
    \ &x) const {\n        Node *p = find(x);\n        return (p ? p->cnt : 0);\n\
    \    }\n    // \u591A\u91CD\u96C6\u5408\u306B\u5024x\u306E\u8981\u7D20\u3092\u8FFD\
    \u52A0\u3059\u308B\uFF0EO(B).\n    void insert(const std::bitset<B> &x, size_type\
    \ cnt = 1) {\n        if(cnt == 0) return;\n        m_root = add(m_root, x, cnt);\n\
    \    }\n    // \u591A\u91CD\u96C6\u5408\u304B\u3089\u5024x\u306E\u8981\u7D20\u3092\
    \u524A\u9664\u3059\u308B\uFF0EO(B).\n    void erase(const std::bitset<B> &x) {\
    \ erase(x, count(x)); }\n    void erase(const std::bitset<B> &x, size_type cnt)\
    \ {\n        assert(count(x) >= cnt);\n        if(cnt == 0) return;\n        m_root\
    \ = sub(m_root, x, cnt);\n    }\n    // \u591A\u91CD\u96C6\u5408\u5185\u3067k\u756A\
    \u76EE\u306B\u5C0F\u3055\u3044\u8981\u7D20\u5024\u3092\u53D6\u5F97\u3059\u308B\
    \uFF0E0-based index. O(B).\n    std::bitset<B> kth_element(size_type k) const\
    \ {\n        assert(k < size());\n        return get(m_root, k);\n    }\n    //\
    \ \u96C6\u5408\u5185\u3067\u6700\u5C0F\u306E\u8981\u7D20\u5024\u3092\u53D6\u5F97\
    \u3059\u308B\uFF0EO(B).\n    std::bitset<B> min_element() const { return kth_element(0);\
    \ }\n    // \u96C6\u5408\u5185\u3067\u6700\u5927\u306E\u8981\u7D20\u5024\u3092\
    \u53D6\u5F97\u3059\u308B\uFF0EO(B).\n    std::bitset<B> max_element() const {\
    \ return kth_element(size() - 1); }\n    // \u5024x\u4EE5\u4E0A\u3067\u3042\u308B\
    \u8981\u7D20\u304C\u73FE\u308C\u308B\u5148\u982D\u306E\u4F4D\u7F6E\u3092\u53D6\
    \u5F97\u3059\u308B\uFF0EO(B).\n    size_type lower_bound(const std::bitset<B>\
    \ &x) const { return get_lower(m_root, x); }\n    // \u5024x\u3088\u308A\u5927\
    \u304D\u3044\u8981\u7D20\u304C\u73FE\u308C\u308B\u5148\u982D\u306E\u4F4D\u7F6E\
    \u3092\u53D6\u5F97\u3059\u308B\uFF0EO(B).\n    size_type upper_bound(const std::bitset<B>\
    \ &x) const { return get_upper(m_root, x); }\n    // xor\u306E\u64CD\u4F5C\u306B\
    \u7528\u3044\u308B\u5024\u3092\u8FD4\u3059\uFF0E\n    std::bitset<B> bias() const\
    \ { return m_bias; }\n    // \u5168\u8981\u7D20\u5024\u306Bxor\u306E\u64CD\u4F5C\
    \u3092\u884C\u3046\uFF0EO(B).\n    void xor_all(const std::bitset<B> &x) { m_bias\
    \ ^= x; }\n    // \u5168\u8981\u7D20\u3092\u524A\u9664\u3059\u308B\uFF0E\n   \
    \ void clear() { m_root = clear_dfs(m_root); }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const BinaryTrie &ob) {\n        std::bitset<B> x(0);\n        os << \"\
    [\\n\";\n        if(ob.m_root) ob.print_dfs(os, ob.m_root, x);\n        os <<\
    \ \"]\";\n        return os;\n    }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_BINARY_TRIE_HPP\n#define ALGORITHM_BINARY_TRIE_HPP 1\n\n\
    /**\n * @brief Binary Trie\uFF08\u975E\u8CA0\u6574\u6570\u5024\u3092\u8981\u7D20\
    \u3068\u3059\u308B\u591A\u91CD\u96C6\u5408\uFF09\n * @docs docs/DataStructure/Others/binary_trie.md\n\
    \ */\n\n#include <bitset>\n#include <cassert>\n#include <cstddef>\n\nnamespace\
    \ algorithm {\n\n// Binary Trie\uFF08\u975E\u8CA0\u6574\u6570\u5024\u3092\u8981\
    \u7D20\u3068\u3059\u308B\u591A\u91CD\u96C6\u5408\uFF09.\ntemplate <size_t B =\
    \ 32>  // B:\u30D3\u30C3\u30C8\u9577.\nclass BinaryTrie {\npublic:\n    using\
    \ size_type = size_t;\n\nprivate:\n    struct Node {\n        size_type cnt; \
    \ // cnt:=(\u81EA\u8EAB\u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306B\u542B\
    \u307E\u308C\u308B\u8981\u7D20\u306E\u6570).\n        Node *ch[2];    // ch[]:=(\u5B50\
    \u306E\u30DD\u30A4\u30F3\u30BF).\n        Node() : cnt(0), ch{nullptr, nullptr}\
    \ {}\n    };\n\n    Node *m_root;           // m_root:=(\u6839\u306E\u30DD\u30A4\
    \u30F3\u30BF).\n    std::bitset<B> m_bias;  // m_bias:=(xor\u306E\u64CD\u4F5C\u5024\
    ).\n\n    Node *find(const std::bitset<B> &x) const {\n        if(!m_root) return\
    \ nullptr;\n        Node *p = m_root;\n        for(int i = B - 1; i >= 0; --i)\
    \ {\n            p = p->ch[x[i] ^ m_bias[i]];\n            if(!p) return nullptr;\n\
    \        }\n        return p;\n    }\n    Node *add(Node *p, const std::bitset<B>\
    \ &x, size_type cnt, int shift = B - 1) {  // top down.\n        if(!p) p = new\
    \ Node();\n        p->cnt += cnt;\n        if(shift >= 0) {\n            bool\
    \ b = x[shift] ^ m_bias[shift];\n            p->ch[b] = add(p->ch[b], x, cnt,\
    \ shift - 1);\n        }\n        return p;\n    }\n    Node *sub(Node *p, const\
    \ std::bitset<B> &x, size_type cnt, int shift = B - 1) {  // bottom up.\n    \
    \    assert(p and p->cnt >= cnt);\n        if(shift >= 0) {\n            bool\
    \ b = x[shift] ^ m_bias[shift];\n            p->ch[b] = sub(p->ch[b], x, cnt,\
    \ shift - 1);\n        }\n        p->cnt -= cnt;\n        if(p->cnt == 0) {\n\
    \            delete p;\n            p = nullptr;\n        }\n        return p;\n\
    \    }\n    std::bitset<B> get(Node *p, size_type k, int shift = B - 1) const\
    \ {\n        assert(p);\n        if(shift < 0) return 0;\n        bool b = m_bias[shift];\n\
    \        size_type m = (p->ch[b] ? p->ch[b]->cnt : 0);\n        if(k < m) return\
    \ get(p->ch[b], k, shift - 1);\n        return get(p->ch[!b], k - m, shift - 1)\
    \ | std::bitset<B>(0).set(shift);\n    }\n    size_type get_lower(Node *p, const\
    \ std::bitset<B> &x, int shift = B - 1) const {\n        if(!p) return 0;\n  \
    \      if(shift < 0) return 0;\n        size_type res = get_lower(p->ch[x[shift]\
    \ ^ m_bias[shift]], x, shift - 1);\n        if(x[shift] and p->ch[m_bias[shift]])\
    \ res += p->ch[m_bias[shift]]->cnt;\n        return res;\n    }\n    size_type\
    \ get_upper(Node *p, const std::bitset<B> &x, int shift = B - 1) const {\n   \
    \     if(!p) return 0;\n        if(shift < 0) return p->cnt;\n        size_type\
    \ res = get_upper(p->ch[x[shift] ^ m_bias[shift]], x, shift - 1);\n        if(x[shift]\
    \ and p->ch[m_bias[shift]]) res += p->ch[m_bias[shift]]->cnt;\n        return\
    \ res;\n    }\n    Node *clear_dfs(Node *p) {\n        if(!p) return nullptr;\n\
    \        for(Node *&next : p->ch) next = clear_dfs(next);\n        delete p;\n\
    \        return p = nullptr;\n    }\n    void print_dfs(std::ostream &os, Node\
    \ *p, std::bitset<B> &x, int shift = B - 1) const {\n        if(shift < 0) {\n\
    \            os << \"  {0b\" << x;\n            if(B <= 64) os << \" (\" << x.to_ullong()\
    \ << \")\";\n            os << \", \" << p->cnt << \"}\\n\";\n            return;\n\
    \        }\n        for(bool b : {0, 1}) {\n            x[shift] = b;\n      \
    \      b ^= m_bias[shift];\n            if(p->ch[b]) print_dfs(os, p->ch[b], x,\
    \ shift - 1);\n        }\n    }\n\npublic:\n    BinaryTrie() : m_root(nullptr),\
    \ m_bias(0) {}\n    ~BinaryTrie() {\n        clear();\n    }\n\n    std::bitset<B>\
    \ operator[](size_type k) const { return kth_element(k); }\n\n    // \u7BA1\u7406\
    \u3059\u308B\u975E\u8CA0\u6574\u6570\u5024\u306E\u30D3\u30C3\u30C8\u9577\u3092\
    \u8FD4\u3059\uFF0E\n    static constexpr size_t bit_length() { return B; }\n \
    \   // \u96C6\u5408\u304C\u7A7A\u304B\u3069\u3046\u304B\u5224\u5B9A\u3059\u308B\
    \uFF0EO(1).\n    bool empty() const { return !m_root; }\n    // \u5168\u8981\u7D20\
    \u6570\u3092\u8FD4\u3059\uFF0EO(1).\n    size_type size() const { return (m_root\
    \ ? m_root->cnt : 0); }\n    // \u5024x\u306E\u8981\u7D20\u304C\u96C6\u5408\u306B\
    \u542B\u307E\u308C\u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(B).\n    bool exists(const\
    \ std::bitset<B> &x) const { return find(x); }\n    // \u5024x\u306E\u8981\u7D20\
    \u6570\u3092\u8FD4\u3059\uFF0EO(B).\n    size_type count(const std::bitset<B>\
    \ &x) const {\n        Node *p = find(x);\n        return (p ? p->cnt : 0);\n\
    \    }\n    // \u591A\u91CD\u96C6\u5408\u306B\u5024x\u306E\u8981\u7D20\u3092\u8FFD\
    \u52A0\u3059\u308B\uFF0EO(B).\n    void insert(const std::bitset<B> &x, size_type\
    \ cnt = 1) {\n        if(cnt == 0) return;\n        m_root = add(m_root, x, cnt);\n\
    \    }\n    // \u591A\u91CD\u96C6\u5408\u304B\u3089\u5024x\u306E\u8981\u7D20\u3092\
    \u524A\u9664\u3059\u308B\uFF0EO(B).\n    void erase(const std::bitset<B> &x) {\
    \ erase(x, count(x)); }\n    void erase(const std::bitset<B> &x, size_type cnt)\
    \ {\n        assert(count(x) >= cnt);\n        if(cnt == 0) return;\n        m_root\
    \ = sub(m_root, x, cnt);\n    }\n    // \u591A\u91CD\u96C6\u5408\u5185\u3067k\u756A\
    \u76EE\u306B\u5C0F\u3055\u3044\u8981\u7D20\u5024\u3092\u53D6\u5F97\u3059\u308B\
    \uFF0E0-based index. O(B).\n    std::bitset<B> kth_element(size_type k) const\
    \ {\n        assert(k < size());\n        return get(m_root, k);\n    }\n    //\
    \ \u96C6\u5408\u5185\u3067\u6700\u5C0F\u306E\u8981\u7D20\u5024\u3092\u53D6\u5F97\
    \u3059\u308B\uFF0EO(B).\n    std::bitset<B> min_element() const { return kth_element(0);\
    \ }\n    // \u96C6\u5408\u5185\u3067\u6700\u5927\u306E\u8981\u7D20\u5024\u3092\
    \u53D6\u5F97\u3059\u308B\uFF0EO(B).\n    std::bitset<B> max_element() const {\
    \ return kth_element(size() - 1); }\n    // \u5024x\u4EE5\u4E0A\u3067\u3042\u308B\
    \u8981\u7D20\u304C\u73FE\u308C\u308B\u5148\u982D\u306E\u4F4D\u7F6E\u3092\u53D6\
    \u5F97\u3059\u308B\uFF0EO(B).\n    size_type lower_bound(const std::bitset<B>\
    \ &x) const { return get_lower(m_root, x); }\n    // \u5024x\u3088\u308A\u5927\
    \u304D\u3044\u8981\u7D20\u304C\u73FE\u308C\u308B\u5148\u982D\u306E\u4F4D\u7F6E\
    \u3092\u53D6\u5F97\u3059\u308B\uFF0EO(B).\n    size_type upper_bound(const std::bitset<B>\
    \ &x) const { return get_upper(m_root, x); }\n    // xor\u306E\u64CD\u4F5C\u306B\
    \u7528\u3044\u308B\u5024\u3092\u8FD4\u3059\uFF0E\n    std::bitset<B> bias() const\
    \ { return m_bias; }\n    // \u5168\u8981\u7D20\u5024\u306Bxor\u306E\u64CD\u4F5C\
    \u3092\u884C\u3046\uFF0EO(B).\n    void xor_all(const std::bitset<B> &x) { m_bias\
    \ ^= x; }\n    // \u5168\u8981\u7D20\u3092\u524A\u9664\u3059\u308B\uFF0E\n   \
    \ void clear() { m_root = clear_dfs(m_root); }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const BinaryTrie &ob) {\n        std::bitset<B> x(0);\n        os << \"\
    [\\n\";\n        if(ob.m_root) ob.print_dfs(os, ob.m_root, x);\n        os <<\
    \ \"]\";\n        return os;\n    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/DataStructure/Others/binary_trie.hpp
  requiredBy: []
  timestamp: '2024-10-21 00:27:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-DSL_2_B-binary_trie.test.cpp
  - test/yosupo-set_xor_min-binary_trie.test.cpp
documentation_of: lib/DataStructure/Others/binary_trie.hpp
layout: document
redirect_from:
- /library/lib/DataStructure/Others/binary_trie.hpp
- /library/lib/DataStructure/Others/binary_trie.hpp.html
title: "Binary Trie\uFF08\u975E\u8CA0\u6574\u6570\u5024\u3092\u8981\u7D20\u3068\u3059\
  \u308B\u591A\u91CD\u96C6\u5408\uFF09"
---
## 概要

非負整数値を要素とする多重集合．

データ構造は $0$ と $1$ をキーとする Trie 木であり，次のクエリ処理を $\mathcal{O}(B)$ で行う（ただし，$B$ は扱う非負整数値の最大ビット長）．

- $\operatorname{insert}(x,c)$：多重集合 $S$ に非負整数 $x$ を $c$ 個挿入する．
- $\operatorname{erase}(x,c)$：多重集合 $S$ から非負整数 $x$ を $c$ 個削除する．
- $\operatorname{count}(x)$：多重集合 $S$ に含まれる非負整数 $x$ の個数を求める．
- $\operatorname{kth\_element}(k)$：多重集合 $S$ 内で $k$ 番目に小さい要素値を取得する．

また，本データ構造のキモであるが，多重集合内の全ての要素値に対し，任意の値で排他的論理和の操作を行うこともできる．
このときの計算量も $\mathcal{O}(B)$（実用上は $\mathcal{O}(1)$）となる．

- $\operatorname{xor\_all}(x)$：多重集合 $S$ に含まれる全ての要素値に対して，非負整数 $x$ で排他的論理和の操作を行う．


## 参考文献

1. "トライ (データ構造)". Wikipedia. <https://ja.wikipedia.org/wiki/トライ_(データ構造)>.
1. kazuma8128. "非負整数値を扱う Trie について". HatenaBlog. <https://kazuma8128.hatenablog.com/entry/2018/05/06/022654>.
1. "Trie木 (Binary Trie)". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/trie>.


## 例題

- "C - データ構造". AtCoder Regular Contest 033. AtCoder. <https://atcoder.jp/contests/arc033/tasks/arc033_3>.

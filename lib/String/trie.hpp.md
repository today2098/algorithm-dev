---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/String/trie.md
    document_title: "Trie\u6728"
    links: []
  bundledCode: "#line 1 \"lib/String/trie.hpp\"\n\n\n\n/**\n * @brief Trie\u6728\n\
    \ * @docs docs/String/trie.md\n */\n\n#include <algorithm>\n#include <array>\n\
    #include <cassert>\n#include <cstddef>\n#include <string>\n#include <string_view>\n\
    #include <utility>\n\nnamespace algorithm {\n\n// Trie\u6728\uFF0E\ntemplate <char\
    \ BASE = 0, size_t N = 128>\nclass Trie {\npublic:\n    using size_type = size_t;\n\
    \nprivate:\n    struct Node {\n        size_type cnt;             // cnt:=(\u81EA\
    \u8EAB\u3092\u672B\u5C3E\u3068\u3059\u308B\u8981\u7D20\u306E\u6570).\n       \
    \ size_type total;           // total:=(\u81EA\u8EAB\u3092\u6839\u3068\u3059\u308B\
    \u90E8\u5206\u6728\u306B\u542B\u307E\u308C\u308B\u8981\u7D20\u306E\u6570).\n \
    \       std::array<Node *, N> ch;  // ch[]:=(\u5B50\u306E\u30DD\u30A4\u30F3\u30BF\
    ).\n\n        Node() : cnt(0), total(0) {\n            std::fill(ch.begin(), ch.end(),\
    \ nullptr);\n        }\n\n        Node *&child(char key) { return ch.at(key -\
    \ BASE); }\n        const Node *&child(char key) const { return ch.at(key - BASE);\
    \ }\n    };\n\n    Node *m_root;  // m_root:=(\u6839\u306E\u30DD\u30A4\u30F3\u30BF\
    ).\n\n    Node *find(std::string_view sv) const {\n        if(!m_root) return\
    \ nullptr;\n        Node *p = m_root;\n        for(char c : sv) {\n          \
    \  p = p->child(c);\n            if(!p) return nullptr;\n        }\n        return\
    \ p;\n    }\n    Node *add(Node *p, std::string_view sv, int n, size_type cnt,\
    \ int i = 0) {  // top down.\n        if(!p) p = new Node();\n        if(i ==\
    \ n) {\n            p->cnt += cnt, p->total += cnt;\n            return p;\n \
    \       }\n        p->total += cnt;\n        p->child(sv[i]) = add(p->child(sv[i]),\
    \ sv, n, cnt, i + 1);\n        return p;\n    }\n    Node *sub(Node *p, std::string_view\
    \ sv, int n, size_type cnt, int i = 0) {  // bottom up.\n        assert(p and\
    \ p->total >= cnt);\n        if(i < n) p->child(sv[i]) = sub(p->child(sv[i]),\
    \ sv, n, cnt, i + 1);\n        else p->cnt -= cnt;\n        p->total -= cnt;\n\
    \        if(p->total == 0) {\n            delete p;\n            p = nullptr;\n\
    \        }\n        return p;\n    }\n    Node *erase_prefix_internal(Node *p,\
    \ std::string_view sv, int n, int i = 0) {  // bottom up.\n        if(!p) return\
    \ nullptr;\n        if(i == n) return clear_dfs(p);\n        if(!p->child(sv[i]))\
    \ return p;\n        size_type pre = p->child(sv[i])->total;\n        p->child(sv[i])\
    \ = erase_prefix_internal(p->child(sv[i]), sv, n, i + 1);\n        p->total -=\
    \ pre - (p->child(sv[i]) ? p->child(sv[i])->total : 0);\n        if(p->total ==\
    \ 0) {\n            delete p;\n            p = nullptr;\n        }\n        return\
    \ p;\n    }\n    std::pair<size_type, size_type> get_lower_and_upper(std::string_view\
    \ sv) const {\n        if(!m_root) return {0, 0};\n        size_type itr = 0;\n\
    \        Node *p = m_root;\n        for(char c : sv) {\n            itr += p->cnt;\n\
    \            for(char d = BASE; d < c; ++d) {\n                if(p->child(d))\
    \ itr += p->child(d)->total;\n            }\n            p = p->child(c);\n  \
    \          if(!p) break;\n        }\n        return {itr, itr + (p ? p->cnt :\
    \ 0)};\n    }\n    void get(Node *p, size_type k, std::string &s, int i = 0) const\
    \ {\n        assert(p);\n        if(k < p->cnt) {\n            s.resize(i);\n\
    \            return;\n        }\n        k -= p->cnt;\n        for(size_t j =\
    \ 0; j < N; ++j) {\n            if(!p->ch[j]) continue;\n            if(k < p->ch[j]->total)\
    \ {\n                get(p->ch[j], k, s, i + 1);\n                s[i] = BASE\
    \ + j;\n                return;\n            }\n            k -= p->ch[j]->total;\n\
    \        }\n        assert(false);  // not reach here.\n    }\n    Node *clear_dfs(Node\
    \ *p) {\n        if(!p) return nullptr;\n        for(Node *&next : p->ch) next\
    \ = clear_dfs(next);\n        delete p;\n        return p = nullptr;\n    }\n\n\
    public:\n    Trie() : m_root(nullptr) {}\n    ~Trie() {\n        clear();\n  \
    \  }\n\n    std::string operator[](size_type k) const { return kth_element(k);\
    \ }\n\n    // \u96C6\u5408\u304C\u7A7A\u304B\u3069\u3046\u304B\u5224\u5B9A\u3059\
    \u308B\uFF0EO(1).\n    bool empty() const { return size() == 0; }\n    // \u5168\
    \u8981\u7D20\u6570\u3092\u8FD4\u3059\uFF0EO(1).\n    size_type size() const {\
    \ return (m_root ? m_root->total : 0); }\n    // \u6587\u5B57\u5217sv\u304C\u96C6\
    \u5408\u306B\u542B\u307E\u308C\u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(|S|).\n\
    \    size_type exists(std::string_view sv) const { return count(sv) > 0; }\n \
    \   // \u63A5\u982D\u8F9E\u304Csv\u3067\u3042\u308B\u6587\u5B57\u5217\u304C\u96C6\
    \u5408\u306B\u542B\u307E\u308C\u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(|S|).\n\
    \    size_type exists_prefix(std::string_view sv) const { return count_prefix(sv)\
    \ > 0; }\n    // \u6587\u5B57\u5217sv\u306E\u8981\u7D20\u6570\u3092\u8FD4\u3059\
    \uFF0EO(|S|).\n    size_type count(std::string_view sv) const {\n        Node\
    \ *p = find(sv);\n        return (p ? p->cnt : 0);\n    }\n    // \u63A5\u982D\
    \u8F9E\u304Csv\u3067\u3042\u308B\u6587\u5B57\u5217\u306E\u8981\u7D20\u6570\u3092\
    \u8FD4\u3059\uFF0EO(|S|).\n    size_type count_prefix(std::string_view sv) const\
    \ {\n        Node *p = find(sv);\n        return (p ? p->total : 0);\n    }\n\
    \    // \u591A\u91CD\u96C6\u5408\u306B\u6587\u5B57\u5217sv\u3092\u8FFD\u52A0\u3059\
    \u308B\uFF0EO(|S|).\n    void insert(std::string_view sv, size_type cnt = 1) {\n\
    \        if(cnt == 0) return;\n        m_root = add(m_root, sv, sv.size(), cnt);\n\
    \    }\n    // \u591A\u91CD\u96C6\u5408\u304B\u3089\u6587\u5B57\u5217sv\u3092\u524A\
    \u9664\u3059\u308B\uFF0EO(|S|).\n    void erase(std::string_view sv) { erase(sv,\
    \ count(sv)); }\n    void erase(std::string_view sv, size_type cnt) {\n      \
    \  assert(count(sv) >= cnt);\n        if(cnt == 0) return;\n        m_root = sub(m_root,\
    \ sv, sv.size(), cnt);\n    }\n    // \u591A\u91CD\u96C6\u5408\u304B\u3089\u63A5\
    \u982D\u8F9E\u304Csv\u3067\u3042\u308B\u6587\u5B57\u5217\u3092\u524A\u9664\u3059\
    \u308B\uFF0EO(|S|*N).\n    void erase_prefix(std::string_view sv) { m_root = erase_prefix_internal(m_root,\
    \ sv, sv.size()); }\n    // \u8F9E\u66F8\u9806\u3067sv\u4EE5\u4E0A\u3067\u3042\
    \u308B\u6587\u5B57\u5217\u3068sv\u3088\u308A\u5927\u304D\u3044\u6587\u5B57\u5217\
    \u304C\u73FE\u308C\u308B\u5148\u982D\u306E\u4F4D\u7F6E\u3092\u53D6\u5F97\u3059\
    \u308B\uFF0EO(|S|*N).\n    std::pair<size_type, size_type> lower_and_upper_bound(std::string_view\
    \ sv) const { return get_lower_and_upper(sv); }\n    // \u591A\u91CD\u96C6\u5408\
    \u5185\u306B\u304A\u3044\u3066\u8F9E\u66F8\u9806\u3067k\u756A\u76EE\u306B\u5C0F\
    \u3055\u3044\u6587\u5B57\u5217\u3092\u53D6\u5F97\u3059\u308B\uFF0E0-based index.\
    \ O(|S|*N).\n    std::string kth_element(size_type k) const {\n        assert(k\
    \ < size());\n        std::string res;\n        get(m_root, k, res);\n       \
    \ return res;\n    }\n    // \u96C6\u5408\u5185\u306B\u304A\u3044\u3066\u8F9E\u66F8\
    \u9806\u3067\u6700\u5C0F\u306E\u6587\u5B57\u5217\u3092\u53D6\u5F97\u3059\u308B\
    \uFF0EO(|S|*N).\n    std::string min_element() const { return kth_element(0);\
    \ }\n    // \u96C6\u5408\u5185\u306B\u304A\u3044\u3066\u8F9E\u66F8\u9806\u3067\
    \u6700\u5927\u306E\u6587\u5B57\u5217\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(|S|*N).\n\
    \    std::string max_element() const { return kth_element(size() - 1); }\n   \
    \ // \u5168\u8981\u7D20\u3092\u524A\u9664\u3059\u308B\uFF0EO(|S|*N).\n    void\
    \ clear() { m_root = clear_dfs(m_root); }\n};\n\nusing DefaultTrie = Trie<'A',\
    \ 58>;\nusing DefaultTrie2 = Trie<'0', 75>;\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_TRIE_HPP\n#define ALGORITHM_TRIE_HPP 1\n\n/**\n * @brief\
    \ Trie\u6728\n * @docs docs/String/trie.md\n */\n\n#include <algorithm>\n#include\
    \ <array>\n#include <cassert>\n#include <cstddef>\n#include <string>\n#include\
    \ <string_view>\n#include <utility>\n\nnamespace algorithm {\n\n// Trie\u6728\uFF0E\
    \ntemplate <char BASE = 0, size_t N = 128>\nclass Trie {\npublic:\n    using size_type\
    \ = size_t;\n\nprivate:\n    struct Node {\n        size_type cnt;           \
    \  // cnt:=(\u81EA\u8EAB\u3092\u672B\u5C3E\u3068\u3059\u308B\u8981\u7D20\u306E\
    \u6570).\n        size_type total;           // total:=(\u81EA\u8EAB\u3092\u6839\
    \u3068\u3059\u308B\u90E8\u5206\u6728\u306B\u542B\u307E\u308C\u308B\u8981\u7D20\
    \u306E\u6570).\n        std::array<Node *, N> ch;  // ch[]:=(\u5B50\u306E\u30DD\
    \u30A4\u30F3\u30BF).\n\n        Node() : cnt(0), total(0) {\n            std::fill(ch.begin(),\
    \ ch.end(), nullptr);\n        }\n\n        Node *&child(char key) { return ch.at(key\
    \ - BASE); }\n        const Node *&child(char key) const { return ch.at(key -\
    \ BASE); }\n    };\n\n    Node *m_root;  // m_root:=(\u6839\u306E\u30DD\u30A4\u30F3\
    \u30BF).\n\n    Node *find(std::string_view sv) const {\n        if(!m_root) return\
    \ nullptr;\n        Node *p = m_root;\n        for(char c : sv) {\n          \
    \  p = p->child(c);\n            if(!p) return nullptr;\n        }\n        return\
    \ p;\n    }\n    Node *add(Node *p, std::string_view sv, int n, size_type cnt,\
    \ int i = 0) {  // top down.\n        if(!p) p = new Node();\n        if(i ==\
    \ n) {\n            p->cnt += cnt, p->total += cnt;\n            return p;\n \
    \       }\n        p->total += cnt;\n        p->child(sv[i]) = add(p->child(sv[i]),\
    \ sv, n, cnt, i + 1);\n        return p;\n    }\n    Node *sub(Node *p, std::string_view\
    \ sv, int n, size_type cnt, int i = 0) {  // bottom up.\n        assert(p and\
    \ p->total >= cnt);\n        if(i < n) p->child(sv[i]) = sub(p->child(sv[i]),\
    \ sv, n, cnt, i + 1);\n        else p->cnt -= cnt;\n        p->total -= cnt;\n\
    \        if(p->total == 0) {\n            delete p;\n            p = nullptr;\n\
    \        }\n        return p;\n    }\n    Node *erase_prefix_internal(Node *p,\
    \ std::string_view sv, int n, int i = 0) {  // bottom up.\n        if(!p) return\
    \ nullptr;\n        if(i == n) return clear_dfs(p);\n        if(!p->child(sv[i]))\
    \ return p;\n        size_type pre = p->child(sv[i])->total;\n        p->child(sv[i])\
    \ = erase_prefix_internal(p->child(sv[i]), sv, n, i + 1);\n        p->total -=\
    \ pre - (p->child(sv[i]) ? p->child(sv[i])->total : 0);\n        if(p->total ==\
    \ 0) {\n            delete p;\n            p = nullptr;\n        }\n        return\
    \ p;\n    }\n    std::pair<size_type, size_type> get_lower_and_upper(std::string_view\
    \ sv) const {\n        if(!m_root) return {0, 0};\n        size_type itr = 0;\n\
    \        Node *p = m_root;\n        for(char c : sv) {\n            itr += p->cnt;\n\
    \            for(char d = BASE; d < c; ++d) {\n                if(p->child(d))\
    \ itr += p->child(d)->total;\n            }\n            p = p->child(c);\n  \
    \          if(!p) break;\n        }\n        return {itr, itr + (p ? p->cnt :\
    \ 0)};\n    }\n    void get(Node *p, size_type k, std::string &s, int i = 0) const\
    \ {\n        assert(p);\n        if(k < p->cnt) {\n            s.resize(i);\n\
    \            return;\n        }\n        k -= p->cnt;\n        for(size_t j =\
    \ 0; j < N; ++j) {\n            if(!p->ch[j]) continue;\n            if(k < p->ch[j]->total)\
    \ {\n                get(p->ch[j], k, s, i + 1);\n                s[i] = BASE\
    \ + j;\n                return;\n            }\n            k -= p->ch[j]->total;\n\
    \        }\n        assert(false);  // not reach here.\n    }\n    Node *clear_dfs(Node\
    \ *p) {\n        if(!p) return nullptr;\n        for(Node *&next : p->ch) next\
    \ = clear_dfs(next);\n        delete p;\n        return p = nullptr;\n    }\n\n\
    public:\n    Trie() : m_root(nullptr) {}\n    ~Trie() {\n        clear();\n  \
    \  }\n\n    std::string operator[](size_type k) const { return kth_element(k);\
    \ }\n\n    // \u96C6\u5408\u304C\u7A7A\u304B\u3069\u3046\u304B\u5224\u5B9A\u3059\
    \u308B\uFF0EO(1).\n    bool empty() const { return size() == 0; }\n    // \u5168\
    \u8981\u7D20\u6570\u3092\u8FD4\u3059\uFF0EO(1).\n    size_type size() const {\
    \ return (m_root ? m_root->total : 0); }\n    // \u6587\u5B57\u5217sv\u304C\u96C6\
    \u5408\u306B\u542B\u307E\u308C\u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(|S|).\n\
    \    size_type exists(std::string_view sv) const { return count(sv) > 0; }\n \
    \   // \u63A5\u982D\u8F9E\u304Csv\u3067\u3042\u308B\u6587\u5B57\u5217\u304C\u96C6\
    \u5408\u306B\u542B\u307E\u308C\u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(|S|).\n\
    \    size_type exists_prefix(std::string_view sv) const { return count_prefix(sv)\
    \ > 0; }\n    // \u6587\u5B57\u5217sv\u306E\u8981\u7D20\u6570\u3092\u8FD4\u3059\
    \uFF0EO(|S|).\n    size_type count(std::string_view sv) const {\n        Node\
    \ *p = find(sv);\n        return (p ? p->cnt : 0);\n    }\n    // \u63A5\u982D\
    \u8F9E\u304Csv\u3067\u3042\u308B\u6587\u5B57\u5217\u306E\u8981\u7D20\u6570\u3092\
    \u8FD4\u3059\uFF0EO(|S|).\n    size_type count_prefix(std::string_view sv) const\
    \ {\n        Node *p = find(sv);\n        return (p ? p->total : 0);\n    }\n\
    \    // \u591A\u91CD\u96C6\u5408\u306B\u6587\u5B57\u5217sv\u3092\u8FFD\u52A0\u3059\
    \u308B\uFF0EO(|S|).\n    void insert(std::string_view sv, size_type cnt = 1) {\n\
    \        if(cnt == 0) return;\n        m_root = add(m_root, sv, sv.size(), cnt);\n\
    \    }\n    // \u591A\u91CD\u96C6\u5408\u304B\u3089\u6587\u5B57\u5217sv\u3092\u524A\
    \u9664\u3059\u308B\uFF0EO(|S|).\n    void erase(std::string_view sv) { erase(sv,\
    \ count(sv)); }\n    void erase(std::string_view sv, size_type cnt) {\n      \
    \  assert(count(sv) >= cnt);\n        if(cnt == 0) return;\n        m_root = sub(m_root,\
    \ sv, sv.size(), cnt);\n    }\n    // \u591A\u91CD\u96C6\u5408\u304B\u3089\u63A5\
    \u982D\u8F9E\u304Csv\u3067\u3042\u308B\u6587\u5B57\u5217\u3092\u524A\u9664\u3059\
    \u308B\uFF0EO(|S|*N).\n    void erase_prefix(std::string_view sv) { m_root = erase_prefix_internal(m_root,\
    \ sv, sv.size()); }\n    // \u8F9E\u66F8\u9806\u3067sv\u4EE5\u4E0A\u3067\u3042\
    \u308B\u6587\u5B57\u5217\u3068sv\u3088\u308A\u5927\u304D\u3044\u6587\u5B57\u5217\
    \u304C\u73FE\u308C\u308B\u5148\u982D\u306E\u4F4D\u7F6E\u3092\u53D6\u5F97\u3059\
    \u308B\uFF0EO(|S|*N).\n    std::pair<size_type, size_type> lower_and_upper_bound(std::string_view\
    \ sv) const { return get_lower_and_upper(sv); }\n    // \u591A\u91CD\u96C6\u5408\
    \u5185\u306B\u304A\u3044\u3066\u8F9E\u66F8\u9806\u3067k\u756A\u76EE\u306B\u5C0F\
    \u3055\u3044\u6587\u5B57\u5217\u3092\u53D6\u5F97\u3059\u308B\uFF0E0-based index.\
    \ O(|S|*N).\n    std::string kth_element(size_type k) const {\n        assert(k\
    \ < size());\n        std::string res;\n        get(m_root, k, res);\n       \
    \ return res;\n    }\n    // \u96C6\u5408\u5185\u306B\u304A\u3044\u3066\u8F9E\u66F8\
    \u9806\u3067\u6700\u5C0F\u306E\u6587\u5B57\u5217\u3092\u53D6\u5F97\u3059\u308B\
    \uFF0EO(|S|*N).\n    std::string min_element() const { return kth_element(0);\
    \ }\n    // \u96C6\u5408\u5185\u306B\u304A\u3044\u3066\u8F9E\u66F8\u9806\u3067\
    \u6700\u5927\u306E\u6587\u5B57\u5217\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(|S|*N).\n\
    \    std::string max_element() const { return kth_element(size() - 1); }\n   \
    \ // \u5168\u8981\u7D20\u3092\u524A\u9664\u3059\u308B\uFF0EO(|S|*N).\n    void\
    \ clear() { m_root = clear_dfs(m_root); }\n};\n\nusing DefaultTrie = Trie<'A',\
    \ 58>;\nusing DefaultTrie2 = Trie<'0', 75>;\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/String/trie.hpp
  requiredBy: []
  timestamp: '2024-10-21 00:27:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/String/trie.hpp
layout: document
redirect_from:
- /library/lib/String/trie.hpp
- /library/lib/String/trie.hpp.html
title: "Trie\u6728"
---
## 概要

文字列を要素とする多重集合を管理するデータ構造．


## 参考文献

1. "トライ (データ構造)". Wikipedia. <https://ja.wikipedia.org/wiki/トライ_(データ構造)>.
1. "すごいTrie". Qiita. <https://qiita.com/minaminao/items/caf6d8147c7e70b6ae63>.
1. "トライ木(Trie木) の解説と実装【接頭辞(prefix) を利用したデータ構造】". アルゴリズムロジック. <https://algo-logic.info/trie-tree/>.

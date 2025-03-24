---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-GRL_5_A-double_sweep.test.cpp
    title: verify/aoj-GRL_5_A-double_sweep.test.cpp
  - icon: ':x:'
    path: verify/yosupo-tree_diameter-double_sweep.test.cpp
    title: verify/yosupo-tree_diameter-double_sweep.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/Graph/Tree/double_sweep.md
    document_title: "Double Sweep\uFF08\u6728\u306E\u76F4\u5F84\uFF09"
    links: []
  bundledCode: "#line 1 \"lib/Graph/Tree/double_sweep.hpp\"\n\n\n\n/**\n * @brief\
    \ Double Sweep\uFF08\u6728\u306E\u76F4\u5F84\uFF09\n * @docs docs/Graph/Tree/double_sweep.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <queue>\n#include <utility>\n\
    #include <vector>\n\nnamespace algorithm {\n\n// \u6728\u306E\u76F4\u5F84\u3092\
    \u6C42\u3081\u308B\uFF0E\u8FD4\u308A\u5024\u306F\u76F4\u5F84\u3068\u305D\u306E\
    \u7D4C\u8DEF\uFF0EO(|V|).\nstd::pair<int, std::vector<int> > double_sweep(const\
    \ std::vector<std::vector<int> > &g, int s = 0) {\n    const int vn = g.size();\n\
    \    assert(0 <= s and s < vn);\n    int furthest_node;\n    std::vector<int>\
    \ d(vn);\n    std::vector<int> pre(vn);\n    std::queue<int> que;\n    auto bfs\
    \ = [&](int s) -> void {\n        std::fill(pre.begin(), pre.end(), -1);\n   \
    \     d[s] = 0, pre[s] = -2;\n        que.push(s);\n        while(!que.empty())\
    \ {\n            int u = que.front();\n            que.pop();\n            furthest_node\
    \ = u;\n            for(int v : g[u]) {\n                assert(0 <= v and v <\
    \ vn);\n                if(pre[v] != -1) continue;\n                d[v] = d[u]\
    \ + 1, pre[v] = u;\n                que.push(v);\n            }\n        }\n \
    \   };\n    bfs(s);\n    bfs(furthest_node);\n    std::vector<int> path({furthest_node});\n\
    \    path.reserve(d[furthest_node] + 1);\n    for(int v = furthest_node; pre[v]\
    \ != -2; v = pre[v]) path.push_back(pre[v]);\n    return {d[furthest_node], path};\
    \  // pair of (diameter, path).\n}\n\n// \u91CD\u307F\u4ED8\u304D\u6728\u306E\u76F4\
    \u5F84\u3092\u6C42\u3081\u308B\uFF0E\u8FD4\u308A\u5024\u306F\u76F4\u5F84\u3068\
    \u305D\u306E\u7D4C\u8DEF\uFF0EO(|V|).\ntemplate <typename Type>\nstd::pair<Type,\
    \ std::vector<int> > double_sweep(const std::vector<std::vector<std::pair<int,\
    \ Type> > > &g, int s = 0) {\n    const int vn = g.size();\n    assert(0 <= s\
    \ and s < vn);\n    int furthest_node;\n    std::vector<Type> d(vn);\n    std::vector<int>\
    \ pre(vn);\n    std::queue<int> que;\n    auto bfs = [&](int s) -> void {\n  \
    \      furthest_node = s;\n        std::fill(pre.begin(), pre.end(), -1);\n  \
    \      d[s] = 0, pre[s] = -2;\n        que.push(s);\n        while(!que.empty())\
    \ {\n            int u = que.front();\n            que.pop();\n            if(d[u]\
    \ > d[furthest_node]) furthest_node = u;\n            for(const auto &[v, cost]\
    \ : g[u]) {\n                assert(0 <= v and v < vn);\n                if(pre[v]\
    \ != -1) continue;\n                d[v] = d[u] + cost, pre[v] = u;\n        \
    \        que.push(v);\n            }\n        }\n    };\n    bfs(s);\n    bfs(furthest_node);\n\
    \    std::vector<int> path({furthest_node});\n    for(int v = furthest_node; pre[v]\
    \ != -2; v = pre[v]) path.push_back(pre[v]);\n    return {d[furthest_node], path};\
    \  // pair of (diameter, path).\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_DOUBLE_SWEEP_HPP\n#define ALGORITHM_DOUBLE_SWEEP_HPP 1\n\
    \n/**\n * @brief Double Sweep\uFF08\u6728\u306E\u76F4\u5F84\uFF09\n * @docs docs/Graph/Tree/double_sweep.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <queue>\n#include <utility>\n\
    #include <vector>\n\nnamespace algorithm {\n\n// \u6728\u306E\u76F4\u5F84\u3092\
    \u6C42\u3081\u308B\uFF0E\u8FD4\u308A\u5024\u306F\u76F4\u5F84\u3068\u305D\u306E\
    \u7D4C\u8DEF\uFF0EO(|V|).\nstd::pair<int, std::vector<int> > double_sweep(const\
    \ std::vector<std::vector<int> > &g, int s = 0) {\n    const int vn = g.size();\n\
    \    assert(0 <= s and s < vn);\n    int furthest_node;\n    std::vector<int>\
    \ d(vn);\n    std::vector<int> pre(vn);\n    std::queue<int> que;\n    auto bfs\
    \ = [&](int s) -> void {\n        std::fill(pre.begin(), pre.end(), -1);\n   \
    \     d[s] = 0, pre[s] = -2;\n        que.push(s);\n        while(!que.empty())\
    \ {\n            int u = que.front();\n            que.pop();\n            furthest_node\
    \ = u;\n            for(int v : g[u]) {\n                assert(0 <= v and v <\
    \ vn);\n                if(pre[v] != -1) continue;\n                d[v] = d[u]\
    \ + 1, pre[v] = u;\n                que.push(v);\n            }\n        }\n \
    \   };\n    bfs(s);\n    bfs(furthest_node);\n    std::vector<int> path({furthest_node});\n\
    \    path.reserve(d[furthest_node] + 1);\n    for(int v = furthest_node; pre[v]\
    \ != -2; v = pre[v]) path.push_back(pre[v]);\n    return {d[furthest_node], path};\
    \  // pair of (diameter, path).\n}\n\n// \u91CD\u307F\u4ED8\u304D\u6728\u306E\u76F4\
    \u5F84\u3092\u6C42\u3081\u308B\uFF0E\u8FD4\u308A\u5024\u306F\u76F4\u5F84\u3068\
    \u305D\u306E\u7D4C\u8DEF\uFF0EO(|V|).\ntemplate <typename Type>\nstd::pair<Type,\
    \ std::vector<int> > double_sweep(const std::vector<std::vector<std::pair<int,\
    \ Type> > > &g, int s = 0) {\n    const int vn = g.size();\n    assert(0 <= s\
    \ and s < vn);\n    int furthest_node;\n    std::vector<Type> d(vn);\n    std::vector<int>\
    \ pre(vn);\n    std::queue<int> que;\n    auto bfs = [&](int s) -> void {\n  \
    \      furthest_node = s;\n        std::fill(pre.begin(), pre.end(), -1);\n  \
    \      d[s] = 0, pre[s] = -2;\n        que.push(s);\n        while(!que.empty())\
    \ {\n            int u = que.front();\n            que.pop();\n            if(d[u]\
    \ > d[furthest_node]) furthest_node = u;\n            for(const auto &[v, cost]\
    \ : g[u]) {\n                assert(0 <= v and v < vn);\n                if(pre[v]\
    \ != -1) continue;\n                d[v] = d[u] + cost, pre[v] = u;\n        \
    \        que.push(v);\n            }\n        }\n    };\n    bfs(s);\n    bfs(furthest_node);\n\
    \    std::vector<int> path({furthest_node});\n    for(int v = furthest_node; pre[v]\
    \ != -2; v = pre[v]) path.push_back(pre[v]);\n    return {d[furthest_node], path};\
    \  // pair of (diameter, path).\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Graph/Tree/double_sweep.hpp
  requiredBy: []
  timestamp: '2024-09-16 18:16:16+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo-tree_diameter-double_sweep.test.cpp
  - verify/aoj-GRL_5_A-double_sweep.test.cpp
documentation_of: lib/Graph/Tree/double_sweep.hpp
layout: document
redirect_from:
- /library/lib/Graph/Tree/double_sweep.hpp
- /library/lib/Graph/Tree/double_sweep.hpp.html
title: "Double Sweep\uFF08\u6728\u306E\u76F4\u5F84\uFF09"
---
## 概要

木の直径を求めるアルゴリズム．
ここで木の直径とは，「与えられた木における単純パスの長さの最大値」をいう．
また，重みなし無向グラフに対しては，グラフの直径の下界となる．

アルゴリズムの流れは次の通り．
ただし，$\operatorname{d}(u,v)$ はノード $u, v$ 間の距離，$\operatorname{ecc}(v)$ は $\max_u \operatorname{d}(v,u)$ を表す（"ecc" は "eccentricity" の略）．

1. 与えられた木上の任意のノード $s$ を選択する．
1. BFS により，$\operatorname{d}(s,u) = \operatorname{ecc}(s)$ となるノード $u$ を探索する．
1. BFS により，$\operatorname{d}(u,v) = \operatorname{ecc}(u)$ となるノード $v$ を探索する．
1. ノード $u$ と $v$ を結ぶ単純パスが，求める木の直径となる．

計算量は，木のノード数を $\lvert V \rvert$ とすると，$\mathcal{O}(\lvert V \rvert)$ となる.


### アルゴリズムの説明

アルゴリズムのポイントは，「木上の任意のノードから最も遠くにあるノードは直径の端点になる」ということ．
アルゴリズムの正当性を背理法を用いて証明する．

ある木において，「根 $r$ から最も遠いノード $x$ は木の直径の端点にならない」と仮定する．
また，木の直径の端点を $u, v$ とおく．

(1) まず，パス $r$-$x$ が直径 $u$-$v$ と交わる場合を考える．
この交点となるノードを $h$ とおく．
ノード $h$ は直径上にあるため，$h$ から最も離れているノードは $u$ または $v$ となる．
しかし，根 $r$ から最も遠いノードは $x$ であり，$x$ は $u$ または $v$ のどちらかになるため，矛盾が生じる．

(2) 次に，パス $r$-$x$ が直径 $u$-$v$ と交わらない場合を考える．
直径上にある点を $h'$ とおく．
$\operatorname{d}(r,h') + \operatorname{d}(h',x) \geq \operatorname{d}(r,x)$ であることに注意すると，

$$
\begin{align}
&\operatorname{d}(r,x) \geq \operatorname{d}(r,h') + \max(\operatorname{d}(h',u), \operatorname{d}(h',v)) \notag\\
\Rightarrow &\operatorname{d}(h',x) \geq \max(\operatorname{d}(h',u), \operatorname{d}(h',v)) \notag
\end{align}
$$

となる．(1) と同様にノード $x$ は $u$ または $v$ のどちらかになるため，矛盾が生じる．

よって，木上の任意のノードから最も遠くにあるノードは直径の端点になることが示された．


## 参考文献

1. Clémence Magnien, Matthieu Latapy, and Michel Habib. 2009. Fast computation of empirically tight bounds for the diameter of massive graphs. ACM J. Exp. Algorithmics 13, Article 10 (2009), 9 pages. <https://doi.org/10.1145/1412228.1455266>.
1. "直径". アルゴリズムとデータ構造大全. <https://take44444.github.io/Algorithm-Book/graph/tree/diameter/main.html>.


## 問題

- "D - 高橋くんと木の直径". AtCoder Beginner Contest 019. AtCoder. <https://atcoder.jp/contests/abc019/tasks/abc019_4>.
- "C - ロミオとジュリエット". AtCoder Regular Contest 022. AtCoder. <https://atcoder.jp/contests/arc022/tasks/arc022_3>.
- "C - Removing Coins". AtCoder Grand Contest 033. AtCoder. <https://atcoder.jp/contests/agc033/tasks/agc033_c>.
- "003 - Longest Circular Road（★4）". 競プロ典型 90 問. AtCoder. <https://atcoder.jp/contests/typical90/tasks/typical90_c>.

---
title: Least Common Multiple（最小公倍数）
documentation_of: //algorithm/Math/NumberTheory/least_common_multiple.hpp
---


## 概要

2つの自然数 $a, b$ の最小公倍数 (LCM: Least Common Multiple) を求める．

次の等式が成り立つため，$a$ と $b$ の最大公約数が分かればよい．

$$
\begin{align}
&\operatorname{lcm}(a, b) \cdot \gcd(a, b) = ab \notag \\
&\Longleftrightarrow \ \operatorname{lcm}(a, b) = \frac{ab}{\gcd(a, b)}. \notag
\end{align}
$$

アルゴリズムの計算量は，最大公約数を求めるところがボトルネックとなり，$\mathcal{O}(\log(\min(a,b)))$ となる．

## 参考

1. "最小公倍数". Wikipedia. <https://ja.wikipedia.org/wiki/最小公倍数>.

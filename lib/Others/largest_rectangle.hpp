#ifndef ALGORITHM_LARGEST_RECTANGLE_HPP
#define ALGORITHM_LARGEST_RECTANGLE_HPP 1

/**
 * @brief 最大長方形問題
 * @docs docs/Others/largest_rectangle.md
 */

#include <functional>
#include <stack>
#include <utility>
#include <vector>

namespace algorithm {

// 最大長方形問題．
// 各iにおいて，comp(H[i], H[] within [l,r))==true となるiを含む最大区間[l,r)を求める．O(N).
template <typename Type, class Compare = std::function<bool(Type, Type)> >
std::vector<std::pair<int, int> > largest_rectangle(
    const std::vector<Type> &h,
    const Compare &comp = [](const Type &a, const Type &b) -> bool { return a <= b; }) {
    const int n = h.size();
    std::vector<std::pair<int, int> > res(n, {0, n});  // res[i]:=(pair of [l,r)).
    std::stack<std::pair<Type, int> > st;
    // left side.
    for(int i = 0; i < n; ++i) {
        while(!st.empty() and comp(h[i], st.top().first)) st.pop();
        if(!st.empty()) res[i].first = st.top().second + 1;
        st.push({h[i], i});
    }
    // right side.
    st = std::stack<std::pair<Type, int> >();
    for(int i = n - 1; i >= 0; --i) {
        while(!st.empty() and comp(h[i], st.top().first)) st.pop();
        if(!st.empty()) res[i].second = st.top().second;
        st.push({h[i], i});
    }
    return res;
}

}  // namespace algorithm

#endif

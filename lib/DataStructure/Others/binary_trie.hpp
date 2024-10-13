#ifndef ALGORITHM_BINARY_TRIE_HPP
#define ALGORITHM_BINARY_TRIE_HPP 1

/**
 * @brief Binary Trie（非負整数値を要素とする多重集合）
 * @docs docs/DataStructure/Others/binary_trie.md
 */

#include <bitset>
#include <cassert>
#include <cstddef>

namespace algorithm {

// Binary Trie（非負整数値を要素とする多重集合）.
template <size_t B = 32>  // B:ビット長.
class BinaryTrie {
public:
    using size_type = size_t;

private:
    struct Node {
        size_type cnt;  // cnt:=(自身を根とする部分木に含まれる要素数).
        Node *ch[2];    // ch[]:=(子のポインタ).
        Node() : cnt(0), ch{nullptr, nullptr} {}
    };

    Node *m_root;           // m_root:=(根のポインタ).
    std::bitset<B> m_bias;  // m_bias:=(xorの操作値).

    Node *find(const std::bitset<B> &x) const {
        if(!m_root) return nullptr;
        Node *p = m_root;
        for(int i = B - 1; i >= 0; --i) {
            p = p->ch[x[i] ^ m_bias[i]];
            if(!p) return nullptr;
        }
        return p;
    }
    Node *add(Node *p, const std::bitset<B> &x, size_type cnt, int shift = B - 1) {  // top down.
        if(!p) p = new Node();
        p->cnt += cnt;
        if(shift >= 0) {
            bool bit = x[shift] ^ m_bias[shift];
            p->ch[bit] = add(p->ch[bit], x, cnt, shift - 1);
        }
        return p;
    }
    Node *sub(Node *p, const std::bitset<B> &x, size_type cnt, int shift = B - 1) {  // bottom up.
        assert(p and p->cnt >= cnt);
        if(shift >= 0) {
            bool bit = x[shift] ^ m_bias[shift];
            p->ch[bit] = sub(p->ch[bit], x, cnt, shift - 1);
        }
        p->cnt -= cnt;
        if(p->cnt == 0) {
            delete p;
            p = nullptr;
        }
        return p;
    }
    std::bitset<B> get(Node *p, size_type k, int shift = B - 1) const {
        assert(p);
        if(shift < 0) return 0;
        bool bit = m_bias[shift];
        size_type m = (p->ch[bit] ? p->ch[bit]->cnt : 0);
        if(k < m) return get(p->ch[bit], k, shift - 1);
        return std::bitset<B>(0).set(shift) | get(p->ch[!bit], k - m, shift - 1);
    }
    size_type get_lower(Node *p, const std::bitset<B> &x, int shift = B - 1) const {
        if(!p) return 0;
        if(shift < 0) return 0;
        return (x[shift] and p->ch[m_bias[shift]] ? p->ch[m_bias[shift]]->cnt : 0) + get_lower(p->ch[x[shift] ^ m_bias[shift]], x, shift - 1);
    }
    size_type get_upper(Node *p, const std::bitset<B> &x, int shift = B - 1) const {
        if(!p) return 0;
        if(shift < 0) return p->cnt;
        return (x[shift] and p->ch[m_bias[shift]] ? p->ch[m_bias[shift]]->cnt : 0) + get_upper(p->ch[x[shift] ^ m_bias[shift]], x, shift - 1);
    }
    Node *clear_dfs(Node *p) {
        if(!p) return nullptr;
        for(bool bit : {0, 1}) p->ch[bit] = clear_dfs(p->ch[bit]);
        delete p;
        return p = nullptr;
    }
    void print_dfs(std::ostream &os, Node *p, std::bitset<B> &x, int shift = B - 1) const {
        if(shift < 0) {
            os << "  {0b" << x;
            if(B <= 64) os << " (" << x.to_ullong() << ")";
            os << ", " << p->cnt << "}\n";
            return;
        }
        for(bool bit : {0, 1}) {
            x[shift] = bit;
            bit ^= m_bias[shift];
            if(p->ch[bit]) print_dfs(os, p->ch[bit], x, shift - 1);
        }
    }

public:
    BinaryTrie() : m_root(nullptr), m_bias(0) {}
    ~BinaryTrie() {
        clear();
    }

    std::bitset<B> operator[](size_type k) const { return kth_element(k); }

    // 管理する非負整数値のビット長を返す．
    static constexpr size_t bit_length() { return B; }
    // 集合が空かどうか判定する．O(1).
    bool empty() const { return !m_root; }
    // 全要素数を返す．O(1).
    size_type size() const { return (m_root ? m_root->cnt : 0); }
    // 値xの要素が集合に含まれるか判定する．O(B).
    bool exists(const std::bitset<B> &x) const { return find(x); }
    // 多重集合に含まれる値xの要素数を返す．O(B).
    size_type count(const std::bitset<B> &x) const {
        Node *p = find(x);
        return (p ? p->cnt : 0);
    }
    // 多重集合に値xの要素を追加する．O(B).
    void insert(const std::bitset<B> &x, size_type cnt = 1) {
        if(cnt == 0) return;
        m_root = add(m_root, x, cnt);
    }
    // 多重集合から値xの要素を削除する．O(B).
    void erase(const std::bitset<B> &x) { erase(x, count(x)); }
    void erase(const std::bitset<B> &x, size_type cnt) {
        assert(count(x) >= cnt);
        if(cnt == 0) return;
        m_root = sub(m_root, x, cnt);
    }
    // 多重集合内でk番目に小さい要素値を取得する．0-based index. O(B).
    std::bitset<B> kth_element(size_type k) const {
        assert(k < size());
        return get(m_root, k);
    }
    // 集合内で最小の要素値を取得する．O(B).
    std::bitset<B> min_element() const { return kth_element(0); }
    // 集合内で最大の要素値を取得する．O(B).
    std::bitset<B> max_element() const { return kth_element(size() - 1); }
    // x以上である要素値が現れる先頭の位置を取得する．O(B).
    size_type lower_bound(const std::bitset<B> &x) const { return get_lower(m_root, x); }
    // xより大きい要素値が現れる先頭の位置を取得する．O(B).
    size_type upper_bound(const std::bitset<B> &x) const { return get_upper(m_root, x); }
    // xorの操作に用いる値を返す．
    std::bitset<B> bias() const { return m_bias; }
    // 全要素値にxorの操作を行う．O(B).
    void xor_all(const std::bitset<B> &x) { m_bias ^= x; }
    // 全要素を削除する．
    void clear() { m_root = clear_dfs(m_root); }

    friend std::ostream &operator<<(std::ostream &os, const BinaryTrie &ob) {
        std::bitset<B> x(0);
        os << "[\n";
        if(ob.m_root) ob.print_dfs(os, ob.m_root, x);
        os << "]";
        return os;
    }
};

}  // namespace algorithm

#endif

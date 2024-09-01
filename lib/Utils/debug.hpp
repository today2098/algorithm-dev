#ifndef ALGORITHM_DEBUG_HPP
#define ALGORITHM_DEBUG_HPP 1

/**
 * @brief デバッグ用関数形式マクロ
 * @docs docs/Utils/debug.md
 */

#include <iostream>
#include <iterator>
#include <queue>
#include <stack>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

// #define DEBUG

#ifdef DEBUG

#define debug(...) algorithm::debug::debug_internal(__LINE__, #__VA_ARGS__, __VA_ARGS__)

namespace algorithm {

namespace debug {

constexpr std::ostream &os = std::clog;

struct has_iterator_impl {
    template <class T>
    static constexpr std::true_type check(typename T::iterator *);

    template <class T>
    static constexpr std::false_type check(...);
};

template <class T>
class has_iterator : public decltype(has_iterator_impl::check<T>(nullptr)) {};

// Prototype declaration.
void print(const std::string &s);
void print(std::string_view s);
template <typename T, typename U>
void print(const std::pair<T, U> &p);
template <class T, std::size_t... Idxes>
void print_tuple(const T &t, std::index_sequence<Idxes...>);
template <typename... Ts>
void print(const std::tuple<Ts...> &t);
template <typename... Ts>
void print(const std::stack<Ts...> &st);
template <typename... Ts>
void print(const std::queue<Ts...> &que);
template <typename... Ts>
void print(const std::priority_queue<Ts...> &pque);
template <class T, typename std::enable_if_t<has_iterator<T>::value, bool> = false>
void print(const T &v);
template <typename T, typename std::enable_if_t<!has_iterator<T>::value, bool> = false>
void print(const T &elem);
template <typename T, typename... Args>
void debug_internal(int line, std::string_view context, T &&first, Args &&...args);

void print(const std::string &s) { os << s; }

void print(std::string_view s) { os << s; }

template <typename T, typename U>
void print(const std::pair<T, U> &p) {
    os << "{";
    print(p.first);
    os << ", ";
    print(p.second);
    os << "}";
}

template <class T, std::size_t... Idxes>
void print_tuple(const T &t, std::index_sequence<Idxes...>) {
    os << "{";
    ((os << (Idxes == 0 ? "" : ", "), print(std::get<Idxes>(t))), ...);
    os << "}";
}

template <typename... Ts>
void print(const std::tuple<Ts...> &t) {
    print_tuple(t, std::make_index_sequence<sizeof...(Ts)>());
}

template <typename... Ts>
void print(const std::stack<Ts...> &st) {
    std::stack<Ts...> tmp = st;
    os << "[";
    while(!tmp.empty()) {
        print(tmp.top());
        tmp.pop();
        if(!tmp.empty()) os << " ";
    }
    os << "]";
}

template <typename... Ts>
void print(const std::queue<Ts...> &que) {
    std::queue<Ts...> tmp = que;
    os << "[";
    while(!tmp.empty()) {
        print(tmp.front());
        tmp.pop();
        if(!tmp.empty()) os << " ";
    }
    os << "]";
}

template <typename... Ts>
void print(const std::priority_queue<Ts...> &pque) {
    std::priority_queue<Ts...> tmp = pque;
    os << "[";
    while(!tmp.empty()) {
        print(tmp.top());
        tmp.pop();
        if(!tmp.empty()) os << " ";
    }
    os << "]";
}

template <class T, typename std::enable_if_t<has_iterator<T>::value, bool> >
void print(const T &v) {
    os << "[";
    for(auto itr = std::begin(v); itr != std::end(v); ++itr) {
        if(itr != std::begin(v)) os << " ";
        print(*itr);
    }
    os << "]";
}

template <typename T, typename std::enable_if_t<!has_iterator<T>::value, bool> >
void print(const T &elem) { os << elem; }

template <typename T, typename... Args>
void debug_internal(int line, std::string_view context, T &&first, Args &&...args) {
    constexpr const char *open_bracket = (sizeof...(args) == 0 ? "" : "(");
    constexpr const char *close_bracket = (sizeof...(args) == 0 ? "" : ")");
    os << "[L" << line << "] " << open_bracket << context << close_bracket << ": " << open_bracket;
    print(std::forward<T>(first));
    ((os << ", ", print(std::forward<Args>(args))), ...);
    os << close_bracket << std::endl;
}

}  // namespace debug

}  // namespace algorithm

#else

#define debug(...) static_cast<void>(0)

#endif

#endif

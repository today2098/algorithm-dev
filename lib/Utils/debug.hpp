#ifndef ALGORITHM_DEBUG_HPP
#define ALGORITHM_DEBUG_HPP 1

#include <chrono>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <queue>
#include <stack>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#ifdef DEBUG

#define debug(...) algorithm::debug::debug_internal(__LINE__ __VA_OPT__(, #__VA_ARGS__, __VA_ARGS__))

namespace algorithm {

namespace debug {

constexpr std::ostream &os = std::clog;

struct has_const_iterator_impl {
    template <class T>
    static constexpr std::true_type check(typename T::const_iterator *);

    template <class T>
    static constexpr std::false_type check(...);
};

template <class T>
class has_const_iterator : public decltype(has_const_iterator_impl::check<T>(nullptr)) {};

// Prototype declaration.
template <typename Type>
auto print(const Type &) -> typename std::enable_if<!has_const_iterator<Type>::value>::type;

template <class Container>
auto print(const Container &) -> typename std::enable_if<has_const_iterator<Container>::value>::type;

void print(const std::string &);

void print(std::string_view);

template <typename... Types>
void print(const std::stack<Types...> &);

template <typename... Types>
void print(const std::queue<Types...> &);

template <typename... Types>
void print(const std::priority_queue<Types...> &);

template <typename T, typename U>
void print(const std::pair<T, U> &);

template <typename... Types>
void print(const std::tuple<Types...> &);

template <class Tuple, std::size_t... Idxes>
void print_tuple(const Tuple &, std::index_sequence<Idxes...>);

// Implementation.
void elapsed() {
    static const auto start = std::chrono::system_clock::now();
    auto t = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - start).count();
    os << "(" << std::setw(8) << t << ")";
}

template <typename Type, typename... Args>
void debug_internal(int line, std::string_view context, const Type &first, const Args &...args) {
    constexpr const char *open_bracket = (sizeof...(args) == 0 ? "" : "(");
    constexpr const char *close_bracket = (sizeof...(args) == 0 ? "" : ")");
    elapsed();
    os << " [L" << line << "] " << open_bracket << context << close_bracket << ": " << open_bracket;
    print(first);
    ((os << ", ", print(args)), ...);
    os << close_bracket << std::endl;
}

void debug_internal(int line) {
    elapsed();
    os << " [L" << line << "] (empty)" << std::endl;
}

template <typename Type>
auto print(const Type &a) -> typename std::enable_if<!has_const_iterator<Type>::value>::type {
    os << a;
}

template <class Container>
auto print(const Container &c) -> typename std::enable_if<has_const_iterator<Container>::value>::type {
    os << "[";
    for(auto iter = std::cbegin(c); iter != std::cend(c); ++iter) {
        if(iter != std::cbegin(c)) os << " ";
        print(*iter);
    }
    os << "]";
}

void print(const std::string &s) {
    os << s;
}

void print(std::string_view sv) {
    os << sv;
}

template <typename... Types>
void print(const std::stack<Types...> &st) {
    std::stack<Types...> tmp = st;
    os << "[";
    while(!tmp.empty()) {
        print(tmp.top());
        tmp.pop();
        if(!tmp.empty()) os << " ";
    }
    os << "]";
}

template <typename... Types>
void print(const std::queue<Types...> &que) {
    std::queue<Types...> tmp = que;
    os << "[";
    while(!tmp.empty()) {
        print(tmp.front());
        tmp.pop();
        if(!tmp.empty()) os << " ";
    }
    os << "]";
}

template <typename... Types>
void print(const std::priority_queue<Types...> &pque) {
    std::priority_queue<Types...> tmp = pque;
    os << "[";
    while(!tmp.empty()) {
        print(tmp.top());
        tmp.pop();
        if(!tmp.empty()) os << " ";
    }
    os << "]";
}

template <typename T, typename U>
void print(const std::pair<T, U> &p) {
    os << "{";
    print(p.first);
    os << ", ";
    print(p.second);
    os << "}";
}

template <typename... Types>
void print(const std::tuple<Types...> &t) {
    print_tuple(t, std::make_index_sequence<sizeof...(Types)>());
}

template <class Tuple, std::size_t... Idxes>
void print_tuple(const Tuple &t, std::index_sequence<Idxes...>) {
    os << "{";
    ((os << (Idxes == 0 ? "" : ", "), print(std::get<Idxes>(t))), ...);
    os << "}";
}

}  // namespace debug

}  // namespace algorithm

#else

#define debug(...) static_cast<void>(0)

#endif

#endif

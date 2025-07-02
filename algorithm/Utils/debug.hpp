#ifndef ALGORITHM_DEBUG_HPP
#define ALGORITHM_DEBUG_HPP 1

#include <chrono>
#include <iomanip>
#include <iostream>
#include <queue>
#include <ranges>
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

// Forward declaration.

template <typename Type>
void print(const Type &);

template <std::ranges::range R>
void print(const R &);

template <typename... Types>
void print(const std::basic_string<Types...> &);

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

auto elapsed() {
    static const auto start = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - start).count();
}

template <typename Type, typename... Args>
void debug_internal(int line, std::string_view context, const Type &first, const Args &...args) {
    constexpr const char *open_bracket = (sizeof...(args) == 0 ? "" : "(");
    constexpr const char *close_bracket = (sizeof...(args) == 0 ? "" : ")");
    os << "(" << std::setw(8) << elapsed() << ") [L" << line << "] " << open_bracket << context << close_bracket << ": " << open_bracket;
    print(first);
    ((os << ", ", print(args)), ...);
    os << close_bracket << std::endl;
}

void debug_internal(int line) {
    os << "(" << std::setw(8) << elapsed() << ") [L" << line << "] (empty)" << std::endl;
}

// Implementation.

template <typename Type>
void print(const Type &a) {
    os << a;
}

template <std::ranges::range R>
void print(const R &r) {
    os << "[";
    for(auto iter = std::ranges::cbegin(r); iter != std::ranges::cend(r); ++iter) {
        if(iter != std::ranges::cbegin(r)) os << " ";
        print(*iter);
    }
    os << "]";
}

template <typename... Types>
void print(const std::basic_string<Types...> &s) {
    os << s;
}

void print(std::string_view sv) {
    os << sv;
}

template <typename... Types>
void print(const std::stack<Types...> &st) {
    std::stack<Types...> tmp(st);
    os << "[";
    for(bool first = true; !tmp.empty(); tmp.pop(), first = false) {
        if(!first) os << " ";
        print(tmp.top());
    }
    os << "]";
}

template <typename... Types>
void print(const std::queue<Types...> &que) {
    std::queue<Types...> tmp(que);
    os << "[";
    for(bool first = true; !tmp.empty(); tmp.pop(), first = false) {
        if(!first) os << " ";
        print(tmp.front());
    }
    os << "]";
}

template <typename... Types>
void print(const std::priority_queue<Types...> &pque) {
    std::priority_queue<Types...> tmp(pque);
    os << "[";
    for(bool first = true; !tmp.empty(); tmp.pop(), first = false) {
        if(!first) os << " ";
        print(tmp.top());
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

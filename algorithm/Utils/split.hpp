#ifndef ALGORITHM_SPLIT_HPP
#define ALGORITHM_SPLIT_HPP 1

#include <ranges>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

namespace algorithm {

// 文字列分割．文字列sを文字delimで分割する．
std::vector<std::string> split(std::string_view sv, char delim, bool disable_empty = false) {
    std::vector<std::string> res;
    std::stringstream ss;
    ss << sv << delim;
    std::string item;
    while(std::getline(ss, item, delim)) {
        if(!(disable_empty and item.empty())) res.push_back(item);
    }
    return res;
}

// 文字列分割．文字列sを文字列delimで分割する．
std::vector<std::string> split(std::string_view sv, std::string_view delim, bool disable_empty = false) {
    std::vector<std::string> res;
    for(auto item : sv | std::ranges::views::split(delim)) {
        if(!(disable_empty and item.empty())) res.emplace_back(item.begin(), item.end());
    }
    return res;
}

}  // namespace algorithm

#endif

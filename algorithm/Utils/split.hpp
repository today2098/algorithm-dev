#ifndef ALGORITHM_SPLIT_HPP
#define ALGORITHM_SPLIT_HPP 1

#include <regex>
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
        if(!(item.empty() and disable_empty)) res.push_back(item);
    }
    return res;
}

// 文字列分割．文字列sを文字列delimで分割する．
std::vector<std::string> split(std::string_view sv, std::string_view delim, bool disable_empty = false) {
    std::vector<std::string> res;
    const std::size_t length = delim.length();
    std::size_t offset = 0;
    while(true) {
        std::size_t pos = sv.find(delim, offset);
        if(pos == std::string::npos) {
            auto item = sv.substr(offset);
            if(!(item.empty() and disable_empty)) res.push_back(std::string(item));
            break;
        }
        auto item = sv.substr(offset, pos - offset);
        if(!(item.empty() and disable_empty)) res.push_back(std::string(item));
        offset = pos + length;
    }
    return res;
}

// 文字列分割．文字列sを正規表現patternにマッチする文字列で分割する．
std::vector<std::string> split_by_regex(std::string_view s, const std::regex &pattern, bool disable_empty = false) {
    std::vector<std::string> res;
    for(std::regex_token_iterator<std::string_view::const_iterator> iter(s.cbegin(), s.cend(), pattern, -1), end; iter != end; ++iter) {
        if(!((*iter).str().empty() and disable_empty)) res.push_back((*iter).str());
    }
    return res;
}

// 文字列分割．文字列sを正規表現patternにマッチする文字列で分割する．
std::vector<std::string> split_by_regex(std::string_view sv, std::string_view pattern, bool disable_empty = false) {
    return split_by_regex(sv, std::regex(pattern.cbegin(), pattern.cend()), disable_empty);
}

}  // namespace algorithm

#endif

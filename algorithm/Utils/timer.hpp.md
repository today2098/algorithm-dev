---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Utils/timer.hpp\"\n\n\n\n#include <chrono>\n\n\
    namespace algorithm {\n\nclass Timer {\n    std::chrono::system_clock::time_point\
    \ m_start;\n\n    auto elapsed() const { return std::chrono::system_clock::now()\
    \ - m_start; }\n\npublic:\n    Timer() : m_start(std::chrono::system_clock::now())\
    \ {}\n\n    // \u8A08\u6E2C\u958B\u59CB\u6642\u9593\u3092\u4FDD\u5B58\uFF0E\n\
    \    void restart() { m_start = std::chrono::system_clock::now(); }\n    // \u7D4C\
    \u904E\u6642\u9593\u3092\u8FD4\u3059\uFF0E[millisec].\n    auto elapsed_by_millisec()\
    \ const { return std::chrono::duration_cast<std::chrono::milliseconds>(elapsed()).count();\
    \ }\n    // \u7D4C\u904E\u6642\u9593\u3092\u8FD4\u3059\uFF0E[microsec].\n    auto\
    \ elapsed_by_microsec() const { return std::chrono::duration_cast<std::chrono::microseconds>(elapsed()).count();\
    \ }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_TIMER_HPP\n#define ALGORITHM_TIMER_HPP 1\n\n#include <chrono>\n\
    \nnamespace algorithm {\n\nclass Timer {\n    std::chrono::system_clock::time_point\
    \ m_start;\n\n    auto elapsed() const { return std::chrono::system_clock::now()\
    \ - m_start; }\n\npublic:\n    Timer() : m_start(std::chrono::system_clock::now())\
    \ {}\n\n    // \u8A08\u6E2C\u958B\u59CB\u6642\u9593\u3092\u4FDD\u5B58\uFF0E\n\
    \    void restart() { m_start = std::chrono::system_clock::now(); }\n    // \u7D4C\
    \u904E\u6642\u9593\u3092\u8FD4\u3059\uFF0E[millisec].\n    auto elapsed_by_millisec()\
    \ const { return std::chrono::duration_cast<std::chrono::milliseconds>(elapsed()).count();\
    \ }\n    // \u7D4C\u904E\u6642\u9593\u3092\u8FD4\u3059\uFF0E[microsec].\n    auto\
    \ elapsed_by_microsec() const { return std::chrono::duration_cast<std::chrono::microseconds>(elapsed()).count();\
    \ }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Utils/timer.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/Utils/timer.hpp
layout: document
redirect_from:
- /library/algorithm/Utils/timer.hpp
- /library/algorithm/Utils/timer.hpp.html
title: algorithm/Utils/timer.hpp
---

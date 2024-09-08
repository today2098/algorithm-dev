---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/Utils/timer.md
    document_title: "\u51E6\u7406\u6642\u9593\u8A08\u6E2C\u30AF\u30E9\u30B9"
    links: []
  bundledCode: "#line 1 \"lib/Utils/timer.hpp\"\n\n\n\n/**\n * @brief \u51E6\u7406\
    \u6642\u9593\u8A08\u6E2C\u30AF\u30E9\u30B9\n * @docs docs/Utils/timer.md\n */\n\
    \n#include <chrono>\n\nnamespace algorithm {\n\nclass Timer {\n    std::chrono::system_clock::time_point\
    \ m_start;\n\npublic:\n    Timer() : m_start(std::chrono::system_clock::now())\
    \ {}\n\n    // \u8A08\u6E2C\u958B\u59CB\u6642\u9593\u3092\u4FDD\u5B58\uFF0E\n\
    \    void restart() { m_start = std::chrono::system_clock::now(); }\n    // \u7D4C\
    \u904E\u6642\u9593\u3092\u8FD4\u3059\uFF0E[millisec].\n    auto elapsed() const\
    \ {\n        auto now = std::chrono::system_clock::now();\n        return std::chrono::duration_cast<std::chrono::milliseconds>(now\
    \ - m_start).count();\n    }\n    // \u7D4C\u904E\u6642\u9593\u3092\u8FD4\u3059\
    \uFF0E[microsec].\n    auto elapsed_micro() const {\n        auto now = std::chrono::system_clock::now();\n\
    \        return std::chrono::duration_cast<std::chrono::microseconds>(now - m_start).count();\n\
    \    }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_TIMER_HPP\n#define ALGORITHM_TIMER_HPP 1\n\n/**\n * @brief\
    \ \u51E6\u7406\u6642\u9593\u8A08\u6E2C\u30AF\u30E9\u30B9\n * @docs docs/Utils/timer.md\n\
    \ */\n\n#include <chrono>\n\nnamespace algorithm {\n\nclass Timer {\n    std::chrono::system_clock::time_point\
    \ m_start;\n\npublic:\n    Timer() : m_start(std::chrono::system_clock::now())\
    \ {}\n\n    // \u8A08\u6E2C\u958B\u59CB\u6642\u9593\u3092\u4FDD\u5B58\uFF0E\n\
    \    void restart() { m_start = std::chrono::system_clock::now(); }\n    // \u7D4C\
    \u904E\u6642\u9593\u3092\u8FD4\u3059\uFF0E[millisec].\n    auto elapsed() const\
    \ {\n        auto now = std::chrono::system_clock::now();\n        return std::chrono::duration_cast<std::chrono::milliseconds>(now\
    \ - m_start).count();\n    }\n    // \u7D4C\u904E\u6642\u9593\u3092\u8FD4\u3059\
    \uFF0E[microsec].\n    auto elapsed_micro() const {\n        auto now = std::chrono::system_clock::now();\n\
    \        return std::chrono::duration_cast<std::chrono::microseconds>(now - m_start).count();\n\
    \    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Utils/timer.hpp
  requiredBy: []
  timestamp: '2024-09-07 17:38:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/Utils/timer.hpp
layout: document
redirect_from:
- /library/lib/Utils/timer.hpp
- /library/lib/Utils/timer.hpp.html
title: "\u51E6\u7406\u6642\u9593\u8A08\u6E2C\u30AF\u30E9\u30B9"
---
## 参考文献

1. "手を動かしてさくさく理解する C言語/C++ 処理時間計測 入門". <http://vivi.dyndns.org/tech/cpp/timeMeasurement.html>.

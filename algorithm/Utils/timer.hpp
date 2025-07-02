#ifndef ALGORITHM_TIMER_HPP
#define ALGORITHM_TIMER_HPP 1

#include <chrono>

namespace algorithm {

class Timer {
    std::chrono::system_clock::time_point m_start;

    auto elapsed() const { return std::chrono::system_clock::now() - m_start; }

public:
    Timer() : m_start(std::chrono::system_clock::now()) {}

    // 計測開始時間を保存．
    void restart() { m_start = std::chrono::system_clock::now(); }
    // 経過時間を返す．[millisec].
    auto elapsed_by_millisec() const { return std::chrono::duration_cast<std::chrono::milliseconds>(elapsed()).count(); }
    // 経過時間を返す．[microsec].
    auto elapsed_by_microsec() const { return std::chrono::duration_cast<std::chrono::microseconds>(elapsed()).count(); }
};

}  // namespace algorithm

#endif

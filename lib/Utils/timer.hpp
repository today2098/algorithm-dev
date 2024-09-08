#ifndef ALGORITHM_TIMER_HPP
#define ALGORITHM_TIMER_HPP 1

/**
 * @brief 処理時間計測クラス
 * @docs docs/Utils/timer.md
 */

#include <chrono>

namespace algorithm {

class Timer {
    std::chrono::system_clock::time_point m_start;

public:
    Timer() : m_start(std::chrono::system_clock::now()) {}

    // 計測開始時間を保存．
    void restart() { m_start = std::chrono::system_clock::now(); }
    // 経過時間を返す．[millisec].
    auto elapsed() const {
        auto now = std::chrono::system_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(now - m_start).count();
    }
    // 経過時間を返す．[microsec].
    auto elapsed_micro() const {
        auto now = std::chrono::system_clock::now();
        return std::chrono::duration_cast<std::chrono::microseconds>(now - m_start).count();
    }
};

}  // namespace algorithm

#endif

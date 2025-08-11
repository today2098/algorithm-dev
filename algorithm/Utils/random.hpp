#ifndef ALGORITHM_RANDOM_HPP
#define ALGORITHM_RANDOM_HPP 1

#include <algorithm>
#include <cassert>
#include <concepts>
#include <iterator>
#include <limits>
#include <random>

namespace algorithm {

class Random {
public:
    using seed_type = std::uint_fast64_t;
    using engine_type = std::mt19937_64;
    using size_type = std::size_t;

private:
    seed_type m_seed;
    engine_type m_engine;

public:
    Random() : Random(std::random_device()()) {}
    explicit Random(seed_type seed) : m_seed(seed), m_engine(seed) {}

    seed_type seed() const { return m_seed; }
    engine_type &engine() { return m_engine; }
    auto next() { return m_engine(); }

    template <std::integral Type>
    Type uniform(Type min = std::numeric_limits<Type>::min(), Type max = std::numeric_limits<Type>::max()) {
        std::uniform_int_distribution<Type> dist(min, max);
        return dist(m_engine);
    }
    template <std::floating_point Type>
    Type uniform(Type min = std::numeric_limits<Type>::min(), Type max = std::numeric_limits<Type>::max()) {
        std::uniform_real_distribution<Type> dist(min, max);
        return dist(m_engine);
    }
    bool bernoulli(double p = 0.5) {
        assert(0.0 <= p and p <= 1.0);
        std::bernoulli_distribution dist(p);
        return dist(m_engine);
    }
    size_type binomial(size_type t, double p = 0.5) {
        assert(0.0 <= p and p <= 1.0);
        std::binomial_distribution<size_type> dist(t, p);
        return dist(m_engine);
    }
    double normal(double mean = 0.0, double stddev = 1.0) {
        assert(stddev > 0.0);
        std::normal_distribution<double> dist(mean, stddev);
        return dist(m_engine);
    }
    double lognormal(double mean = 0.0, double stddev = 1.0) {
        assert(stddev > 0.0);
        std::lognormal_distribution<double> dist(mean, stddev);
        return dist(m_engine);
    }

    template <std::random_access_iterator Iter>
    void shuffle(Iter first, Iter last) { std::shuffle(first, last, m_engine); }
    template <std::input_iterator Iter, class Container>
    auto sample(Iter first, Iter last, size_type n, Container &c) { return std::sample(first, last, std::back_inserter(c), n, m_engine); }
};

}  // namespace algorithm

#endif

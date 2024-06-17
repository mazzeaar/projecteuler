#ifndef FACTORIAL_H
#define FACTORIAL_H

#include <cstddef>
#include <cassert>

template <size_t N>
struct small_factorial {
    static constexpr size_t value = small_factorial<N-1>::value * N;
};

template <>
struct small_factorial<0> {
    static constexpr size_t value = 1;
};

size_t runtime_small_factorial(int n);

#endif // FACTORIAL_H
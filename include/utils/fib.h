#ifndef FIB_H
#define FIB_H

#include <array>

constexpr size_t fib_constexpr(size_t n)
{
    std::array<size_t, 100> memo = { 0 };
    memo[0] = 1;
    memo[1] = 1;

    for ( size_t i = 2; i <= n; ++i ) {
        memo[i] = memo[i-1] + memo[i-2];
    }

    return memo[n];
}

#endif // FIB_H
#include "euler_utils.h"

template <size_t N>
int collatz(size_t n, std::array<int, N>& memo)
{
    if ( memo[n] != -1 ) {
        return memo[n];
    }

    int steps = 0;
    size_t iter = n;
    while ( true ) {
        if ( iter == 1 ) {
            memo[n] = steps;
            break;
        }

        if ( iter < N && memo[iter] != -1 ) {
            memo[n] = steps + memo[iter];
            break;
        }

        if ( iter % 2 == 0 ) {
            iter /= 2;
        }
        else {
            iter = 3 * iter + 1;
        }

        ++steps;
    }

    return memo[n];
}

size_t solve_problem_14()
{
    constexpr size_t n = 1000000;
    std::array<int, n> memo;
    std::fill(memo.begin(), memo.end(), -1);
    memo[1] = 1;

    size_t result = 0;
    int max_steps = 0;
    for ( size_t i = 2; i < n; ++i ) {
        if ( const int steps = collatz(i, memo); steps > max_steps ) {
            max_steps = steps;
            result = i;
        }
    }

    ASSERT_EQUAL(result, 837799);
    return result;
}

REGISTER_PROBLEM(solve_problem_14, 14)

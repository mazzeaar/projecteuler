#include "euler_utils.h"

unsigned long long binomial_coefficient(int n, int k)
{
    if ( k > n - k ) {
        k = n - k;
    }

    unsigned long long res = 1;
    for ( int i = 0; i < k; ++i ) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

// result is 2n choose 2
size_t solve_problem_15()
{
    const int grid_size = 20;
    size_t result = 1;

    int n = 2 * grid_size;
    int k = grid_size;
    for ( int i = 0; i < k; ++i ) {
        result *= (n - i);
        result /= (i + 1);
    }

    ASSERT_EQUAL(result, 137846528820);
    return result;
}

REGISTER_PROBLEM(solve_problem_15, 15)

#include "euler_utils.h"

/*
use pascal triangle

start in bottom row with (n_max, 0) := n choose k
increase k until (n, k) >= limit
    means the whole row - 2 * k is >= limit

keep k, decrease n
*/


i64 n_choose_k(i64 n, i64 k)
{
    if ( k > n - k ) k = n - k;  // symmetry
    double result = 1;
    while ( k > 0 ) {
        result *= n--;
        result /= k--;
    }
    return static_cast<i64>(result);
}

i64 solve_problem_53()
{
    const i64 max = 100;
    const i64 limit = 1000000;

    i64 result = 0;
    // start in bottom row with (100, 0)
    for ( i64 n = max, k = 0; n >= 0 && 2*k < n; --n ) {
        // increase k until (n, k) >= limit
        while ( 2 * k < n && n_choose_k(n, k) < limit ) {
            ++k;
        }

        // (n+1) = #(nums in row)
        // #(nums in row) - (2 * k) = #(nums in row) >= limit
        if ( 2 * k < n )
            result += n+1 - (2 * k);
    }

    ASSERT_EQUAL(result, 4075);
    return result;
}

REGISTER_PROBLEM(solve_problem_53, 53)

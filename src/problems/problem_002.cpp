#include <iostream>
#include "euler_utils.h"

int get_max_fib()
{
    for ( int i = 0; i < 100; ++i ) {
        if ( fib_constexpr(i) >= 4000000 ) {
            return i;
        }
    }

    return -1;
}

size_t solve_problem_2()
{
    const int max_fib = get_max_fib();
    unsigned res = 0;
    for ( int i = 0; i < max_fib; ++i ) {
        if ( const auto f = fib_constexpr(i); f % 2 == 0 )
            res += f;
    }

    ASSERT_EQUAL(res, 4613732);
    return res;
}

REGISTER_PROBLEM(solve_problem_2, 2)

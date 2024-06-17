#include <iostream>
#include "euler_utils.h"

size_t solve_problem_001()
{
    int sol = 0;
    for ( int i = 3; i < 1000; ++i ) {
        if ( i % 3 == 0 || i % 5 == 0 ) {
            sol += i;
        }
    }

    ASSERT_EQUAL(sol, 233168);
    return sol;
}

REGISTER_PROBLEM(solve_problem_001, 1)

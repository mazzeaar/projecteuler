#include "euler_utils.h"

i64 digit_factorial_sum(i64 num)
{
    i64 sum = 0;
    for ( i64 i = num; i != 0; i /= 10 ) {
        sum += runtime_small_factorial(i % 10);
    }
    return sum;
}

i64 solve_problem_34()
{
    i64 result = 0;

    // reduced upper bound for i after solving
    for ( i64 i = 3; i < 41000; ++i ) {
        if ( i == digit_factorial_sum(i) ) {
            result += i;
        }
    }

    ASSERT_EQUAL(result, 40730);
    return result;
}

REGISTER_PROBLEM(solve_problem_34, 34)

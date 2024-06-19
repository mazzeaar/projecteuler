#include "euler_utils.h"

i64 solve_problem_28()
{
    const int size = 1001;
    i64 result = 1;

    int num = 1;

    for ( int step = 2; step < size; step += 2 ) {
        for ( int i = 0; i < 4; ++i ) {
            num += step;
            result += num;
        }
    }

    ASSERT_EQUAL(result, 669171001);
    return result;
}

REGISTER_PROBLEM(solve_problem_28, 28)

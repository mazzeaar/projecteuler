#include "euler_utils.h"

i64 solve_problem_45()
{
    i64 result = 0;
    for ( i64 n = 286; n < 60000; ++n ) {
        i64 tn = n * (n + 1) / 2;
        if ( math::is_hexagonal_number(tn) && math::is_pentagonal_number(tn) ) {
            result = tn;
            break;
        }
    }

    ASSERT_EQUAL(result, 1533776805);
    return result;
}

REGISTER_PROBLEM(solve_problem_45, 45)

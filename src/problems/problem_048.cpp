#include "euler_utils.h"

i64 solve_problem_48()
{
    const i64 MOD = 10000000000;

    i64 result = 0;
    for ( i64 i = 1; i < 1001; ++i ) {
        i64 val = 1;
        for ( i64 j = 0; j < i; ++j ) {
            val = (val * i) % MOD;
        }

        result = (result + val) % MOD;
    }

    ASSERT_EQUAL(result, 9110846700);
    return result;
}

REGISTER_PROBLEM(solve_problem_48, 48)

#include "euler_utils.h"

i64 solve_problem_47()
{
    constexpr int n = 4;
    i64 result = 0;
    int counter = 0;
    for ( int i = 2; i < 999999; ++i ) {
        auto factors = PrimeGenerator::get_prime_factors(i);
        std::set<i64> s(factors.begin(), factors.end());

        if ( s.size() != n ) {
            counter = 0;
            continue;
        }

        if ( ++counter == n ) {
            result = i - n + 1;
            break;
        }
    }

    ASSERT_EQUAL(result, 134043);
    return result;
}

REGISTER_PROBLEM(solve_problem_47, 47)

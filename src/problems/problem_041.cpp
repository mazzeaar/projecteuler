#include "euler_utils.h"

i64 solve_problem_41()
{
    i64 result = 0;
    const auto primes = PrimeGenerator::get_primes(7654321);
    for ( auto it = primes.rbegin(); it != primes.rend(); ++it ) {
        if ( math::is_pandigital(*it) ) {
            result = *it;
            break;
        }
    }

    ASSERT_EQUAL(result, 7652413);
    return result;
}

REGISTER_PROBLEM(solve_problem_41, 41)

#include "euler_utils.h"

size_t solve_problem_10()
{
    size_t result = 0;

    auto primes = PrimeGenerator::get_primes(2000000);

    for ( auto p : primes ) {
        result += p;
    }

    ASSERT_EQUAL(result, 142913828922);
    return result;
}

REGISTER_PROBLEM(solve_problem_10, 10)

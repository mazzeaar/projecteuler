#include "euler_utils.h"

size_t solve_problem_007()
{
    size_t check_to = 120012;

    auto primes = PrimeGenerator::get_primes(check_to);

    ASSERT_EQUAL(primes[10000], 104743);
    return primes[10000];
}

REGISTER_PROBLEM(solve_problem_007, 7)

#include <iostream>
#include "euler_utils.h"

size_t solve_problem_003()
{
    auto factors = PrimeGenerator::get_prime_factors(600851475143);
    ASSERT_EQUAL(factors.back(), 6857);
    return factors.back();
}

REGISTER_PROBLEM(solve_problem_003, 3)

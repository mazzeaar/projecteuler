#include "euler_utils.h"

i64 solve_problem_29()
{
    std::vector<std::vector<i64>> prime_factors;

    for ( int i = 2; i <= 100; ++i ) {
        prime_factors.push_back(PrimeGenerator::get_prime_factors(i));
    }


    i64 result = 0;
    return result;
}

REGISTER_PROBLEM(solve_problem_29, 29)

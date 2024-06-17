#include <iostream>
#include "euler_utils.h"

size_t solve_problem_005()
{
    const int amount = 20;
    std::vector<int> factors_count(amount, 0);

    for ( int i = 2; i < amount; ++i ) {
        auto factors = PrimeGenerator::get_prime_factors(i);
        std::unordered_map<int, int> frequencies;
        for ( auto factor : factors ) {
            ++frequencies[factor];
        }

        for ( auto& [num, freq] : frequencies ) {
            factors_count[num] = std::max(factors_count[num], freq);
        }
    }

    size_t res = 1;
    for ( int i = 1; i < amount; ++i ) {
        res *= std::pow(i, factors_count[i]);
    }

    ASSERT_EQUAL(res, 232792560);
    return res;
}

REGISTER_PROBLEM(solve_problem_005, 5)

#include "euler_utils.h"

inline size_t get_divisor_sum(size_t n)
{
    const auto divisors = PrimeGenerator::get_divisors(n);
    size_t sum = 0;
    for ( size_t divisor : divisors ) {
        sum += divisor;
    }
    return sum;
}

inline bool is_abundand(size_t n)
{
    return get_divisor_sum(n) > n;
}

size_t solve_problem_23()
{
    const size_t max = 28123;

    std::vector<int> abundand;
    for ( int i = 1; i < max; ++i ) {
        if ( is_abundand(i) ) {
            abundand.push_back(i);
        }
    }

    std::vector<bool> is_sum(max, false);
    for ( int i = 0; i < abundand.size(); ++i ) {
        for ( int j = i; j < abundand.size(); ++j ) {
            const size_t num = abundand[i] + abundand[j];
            is_sum[num] = true;
        }
    }

    size_t result = 0;
    for ( int i = 0; i < is_sum.size(); ++i ) {
        if ( is_sum[i] == false ) {
            result += i;
        }
    }

    ASSERT_EQUAL(result, 4179871);
    return result;
}

REGISTER_PROBLEM(solve_problem_23, 23)

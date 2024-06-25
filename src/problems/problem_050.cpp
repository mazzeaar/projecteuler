#include "euler_utils.h"

i64 solve_problem_50()
{
    const int n = 1000000;
    const auto primes = PrimeGenerator::get_primes(n);

    i64 result = 0;
    i64 best_streak = 0;
    for ( int i = 0; i < primes.size(); ++i ) {
        int streak = 1;
        i64 sum = primes[i];
        for ( int j = i + 1; j < primes.size(); ++j ) {
            if ( sum > n ) {
                break;
            }

            if ( streak > best_streak && PrimeGenerator::is_prime(sum) ) {
                best_streak = streak;
                result = sum;
            }

            sum += primes[j];
            ++streak;
        }
    }

    ASSERT_EQUAL(result, 997651);
    return result;
}

REGISTER_PROBLEM(solve_problem_50, 50)

#include "euler_utils.h"

bool is_right_truncatable(i64 p)
{
    while ( p != 0 ) {
        if ( !PrimeGenerator::is_prime(p) )
            return false;

        p /= 10;
    }

    return true;
}

bool is_left_truncatable(i64 p)
{
    static i64 pow10[6] = {
        1, 10, 100, 1000, 10000, 100000
    };

    size_t size = math::count_digits(p) - 1;

    while ( p != 0 ) {
        if ( !PrimeGenerator::is_prime(p) )
            return false;

        p %= pow10[size--];
    }

    return true;
}

i64 solve_problem_37()
{
    const int N = 1000000;
    auto primes = PrimeGenerator::get_primes(N);

    primes.erase(std::remove_if(primes.begin(), primes.end(), [ ] (auto p)
    {
        return p < 10 || !is_right_truncatable(p) || !is_left_truncatable(p);
    }), primes.end());

    i64 result = std::accumulate(primes.begin(), primes.end(), 0ULL);

    ASSERT_EQUAL(result, 748317);
    return result;
}

REGISTER_PROBLEM(solve_problem_37, 37)

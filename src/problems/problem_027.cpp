#include "euler_utils.h"

/*
n^2 + na + b = n(n+a)+b = prime?

n=0: b = prime
n=1: 1 + a + b = prime

so:
b = prime
a = some_prime - 1 - b

let #p(n) be the number of primes in [2, n]
the search space in this case is #p(1000)^2 = 168^2 = 28'224
*/

i64 count_primes(const int a, const int b)
{
    auto polynomial = [&a, &b] (size_t n) -> i64
    {
        return n * (n + a) + b;
    };

    if ( !PrimeGenerator::is_prime(polynomial(0)) ) {
        return 0;
    }

    size_t n_primes = 1;
    for ( int i = 1; i < std::abs(b); ++i ) {
        const auto num = polynomial(i);
        if ( !PrimeGenerator::is_prime(num) ) {
            break;
        }

        ++n_primes;
    }

    return n_primes;
}

i64 solve_problem_27()
{
    i64 result = 0, best = 0;

    auto try_numbers = [&best, &result] (int a, int b) -> void
    {
        const auto signs = { 1, -1 };

        for ( int sign_a : signs ) {
            const auto val = count_primes(sign_a * a, b);

            if ( val > best ) {
                best = val;
                result = (sign_a * a * b);
            }
        }
    };

    const auto primes = PrimeGenerator::get_primes(1000);
    for ( auto b = primes.begin(); b != primes.end(); ++b ) {
        for ( auto a = primes.begin(); a != primes.end(); ++a ) {
            // even though a = some_prime - b - 1, its faster if we do it this way, idk why
            try_numbers(*a, *b);
        }
    }

    ASSERT_EQUAL(result, -59231);
    return result;
}

REGISTER_PROBLEM(solve_problem_27, 27)

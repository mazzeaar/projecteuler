#include "euler_utils.h"

bool is_permutation(i64 a, i64 b, i64 c)
{
    auto get_digits = [ ] (i64 n)
    {
        uint16_t digits = 0;
        while ( n != 0 ) {
            digits |= (0x1 << (n % 10));
            n /= 10;
        }
        return digits;
    };

    auto digits_a = get_digits(a);
    return digits_a == get_digits(b) && digits_a == get_digits(c);
}

i64 solve_problem_49()
{
    std::vector<i64> primes;
    for ( auto p : PrimeGenerator::get_primes(9999) ) {
        if ( p >= 1000 && p <= 10000 ) primes.push_back(p);
    }

    i64 result = 0;
    for ( auto i = 0; i < primes.size() && result == 0; ++i ) {
        for ( auto j = i + 1; j < primes.size(); ++j ) {
            const auto a = primes[i];
            const auto b = primes[j];
            const auto c = b + b - a;

            if ( c > 9999 || a == 1487 ) {
                continue; // skip example case and out of range numbers
            }

            if ( PrimeGenerator::is_prime(c) ) {
                if ( !is_permutation(a, b, c) ) {
                    continue;
                }

                result = 10000 * (10000 * a + b) + c;
                break;
            }
        }
    }

    ASSERT_EQUAL(result, 296962999629);
    return result;
}

REGISTER_PROBLEM(solve_problem_49, 49)

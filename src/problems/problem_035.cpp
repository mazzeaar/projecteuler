#include "euler_utils.h"

int count_digits(i64 n)
{
    int d = 0;
    for ( ; n != 0; n /= 10 ) ++d;
    return d-1;
}

i64 permute(i64 n, int size)
{
    static int digits[7] = {
        1, 10, 100, 1000, 10000,
        100000, 1000000
    };

    return (n / 10) + (digits[size] * (n % 10));
}

i64 solve_problem_35()
{
    const size_t N = 1000000;

    std::bitset<N> is_circular;
    is_circular.reset();

    const auto primes = PrimeGenerator::get_primes(N);
    for ( i64 p : primes ) {
        if ( is_circular[p] ) {
            continue;
        }

        std::vector<i64> cur_perms = { p };

        const int size = count_digits(p);
        i64 n = permute(p, size);
        while ( PrimeGenerator::is_prime(n) && n != cur_perms.front() ) {
            cur_perms.push_back(n);
            n = permute(n, size);
        }

        if ( n != cur_perms.front() ) {
            continue;
        }

        std::for_each(cur_perms.begin(), cur_perms.end(), [&is_circular] (const i64& p) { is_circular[p] = true; });
    }

    i64 result = is_circular.count();
    ASSERT_EQUAL(result, 55);
    return result;
}

REGISTER_PROBLEM(solve_problem_35, 35)

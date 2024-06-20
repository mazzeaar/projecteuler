#include "euler_utils.h"

#include <unordered_map>
#include <cassert>

std::vector<bool> PrimeGenerator::sieve;

bool PrimeGenerator::is_prime(i64 i)
{
    if ( i < 2 ) return false;
    if ( i >= sieve.size() ) generate_sieve(i);
    return sieve[i];
}

std::vector<i64> PrimeGenerator::get_primes(i64 max)
{
    generate_sieve(max);
    std::vector<i64> primes;
    for ( i64 i = 2; i <= max; ++i ) {
        if ( sieve[i] ) primes.push_back(i);
    }
    return primes;
}

std::vector<i64> PrimeGenerator::get_prime_factors(i64 n)
{
    std::vector<i64> factors_n;

    while ( n % 2 == 0 ) {
        factors_n.push_back(2);
        n /= 2;
    }

    for ( i64 i = 3; i * i <= n; i += 2 ) {
        while ( n % i == 0 ) {
            factors_n.push_back(i);
            n /= i;
        }
    }

    if ( n > 2 ) {
        factors_n.push_back(n);
    }

    return factors_n;
}

std::vector<i64> PrimeGenerator::get_divisors(i64 n)
{
    const auto primes = get_prime_factors(n);
    std::unordered_map<i64, i64> prime_count;
    for ( const i64 p : primes ) {
        prime_count[p]++;
    }

    std::vector<i64> divisors = { 1 };

    for ( const auto& pair : prime_count ) {
        i64 prime = pair.first;
        i64 count = pair.second;

        std::vector<i64> new_divisors;

        for ( const i64& divisor : divisors ) {
            i64 current = 1;
            for ( i64 i = 0; i <= count; ++i ) {
                new_divisors.push_back(divisor * current);
                current *= prime;
            }
        }

        divisors = new_divisors;
    }

    if ( !divisors.empty() ) {
        divisors.pop_back();
    }

    return divisors;
}

void PrimeGenerator::generate_sieve(i64 max)
{
    assert(max+1 != i64(-1) && "overflow of max in PrimeGenerator::generate_sieve(i64)?");
    if ( max < sieve.size() ) return;
    sieve.resize(max + 1, true);
    sieve[0] = false;
    sieve[1] = false;

    for ( i64 p = 2; p * p <= max; ++p ) {
        if ( sieve[p] ) {
            for ( i64 i = p * p; i <= max; i += p ) {
                sieve[i] = false;
            }
        }
    }
}

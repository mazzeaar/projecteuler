#include "utils/primes.h"
#include <unordered_map>

std::vector<bool> PrimeGenerator::sieve;

bool PrimeGenerator::is_prime(size_t i)
{
    if ( i < 2 ) return false;
    if ( i >= sieve.size() ) generate_sieve(i);
    return sieve[i];
}

std::vector<size_t> PrimeGenerator::get_primes(size_t max)
{
    generate_sieve(max);
    std::vector<size_t> primes;
    for ( size_t i = 2; i <= max; ++i ) {
        if ( sieve[i] ) primes.push_back(i);
    }
    return primes;
}

std::vector<size_t> PrimeGenerator::get_prime_factors(size_t n)
{
    std::vector<size_t> factors_n;

    while ( n % 2 == 0 ) {
        factors_n.push_back(2);
        n /= 2;
    }

    for ( size_t i = 3; i * i <= n; i += 2 ) {
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

std::vector<size_t> PrimeGenerator::get_divisors(size_t n)
{
    const auto primes = get_prime_factors(n);

    std::unordered_map<size_t, size_t> prime_count;
    for ( const size_t p : primes ) {
        prime_count[p]++;
    }

    std::vector<size_t> divisors = { 1 };

    for ( const auto& pair : prime_count ) {
        size_t prime = pair.first;
        size_t count = pair.second;

        std::vector<size_t> new_divisors;

        for ( const size_t& divisor : divisors ) {
            size_t current = 1;
            for ( size_t i = 0; i <= count; ++i ) {
                new_divisors.push_back(divisor * current);
                current *= prime;
            }
        }

        divisors = new_divisors;
    }

    return divisors;
}

void PrimeGenerator::generate_sieve(size_t max)
{
    if ( max < sieve.size() ) return;
    sieve.resize(max + 1, true);
    sieve[0] = false;
    sieve[1] = false;

    for ( size_t p = 2; p * p <= max; ++p ) {
        if ( sieve[p] ) {
            for ( size_t i = p * p; i <= max; i += p ) {
                sieve[i] = false;
            }
        }
    }
}

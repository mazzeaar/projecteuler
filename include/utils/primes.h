#ifndef PRIMES_H
#define PRIMES_H

#include <vector>
#include <cmath>
#include <iostream>

class PrimeGenerator {
public:
    static bool is_prime(i64 i);
    static std::vector<i64> get_primes(i64 max);
    static std::vector<i64> get_prime_factors(i64 n);
    static std::vector<i64> get_divisors(i64 n);

private:
    static std::vector<bool> sieve;

    static void generate_sieve(i64 max);
};

#endif // PRIMES_H

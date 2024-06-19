#ifndef PRIMES_H
#define PRIMES_H

#include <vector>
#include <cmath>
#include <iostream>

class PrimeGenerator {
public:
    static bool is_prime(int i);
    static std::vector<size_t> get_primes(size_t max);
    static std::vector<size_t> get_prime_factors(size_t n);
    static std::vector<size_t> get_divisors(size_t n);

private:
    static std::vector<bool> sieve;

    static void generate_sieve(size_t max);
};

#endif // PRIMES_H

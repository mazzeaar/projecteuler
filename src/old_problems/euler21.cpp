#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>
#include <set>

#include "../utils/primes.h"
#include "../utils/print.h"

/*
 * --------------------------------
 * Problem: '21'
 * https://projecteuler.net/problem=21
 * --------------------------------
 * @amazzetta
 */

void print(double runtime, long int solution = 0)
{
    if ( solution == 0 ) {
        std::cout << "\nSolution to problem 21 is not implemented yet!\n\n";
        return;
    }

    std::cout << "\n################################\n"
        << "#  Problem 21\n"
        << "#  Solved in: " << std::fixed << std::setprecision(0) << runtime << " µs (" << runtime / 1000 << " ms)\n"
        << "#  Solution: " << solution << "\n"
        << "################################\n";
}

// --------------------------------

template <typename T>
std::vector<T> get_divisors(T n)
{
    std::vector<T> factors = get_factors(n);
    std::set<T> divisors = { 1 };

    for ( size_t i = 1; i < factors.size(); ++i ) {
        T factor = factors[i];
        std::set<T> new_divisors;
        for ( T d : divisors ) {
            T new_divisor = d * factor;
            if ( n % new_divisor == 0 ) {
                new_divisors.insert(new_divisor);
            }
        }

        divisors.insert(new_divisors.begin(), new_divisors.end());
    }

    std::vector<T> result(divisors.begin(), divisors.end());
    std::sort(result.begin(), result.end());
    return result;
}

unsigned long solution()
{
    constexpr size_t n = 10000;

    unsigned long solution = 0;

    auto factor_sum = [n] ()
    {
        std::vector<int> sums(n, 0);
        for ( int i = 1; i < n; ++i ) {
            auto factors = get_divisors(i);
            int sum = 0;
            for ( int f : factors ) {
                sum += f;
            }
            sums[i] = sum - i;
        }
        return sums;
    }();

    std::vector<bool> checked(n, false);
    for ( int i = 0; i < n; ++i ) {
        if ( checked[i] ) {
            continue;
        }

        const int partner = factor_sum[i];
        if ( factor_sum[partner] == i ) {
            solution += i + partner;
        }
        checked[i] = true;
        checked[partner] = true;
    }

    return solution;
}

int main()
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    unsigned long sol = solution();

    double runtime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - begin).count();

    print(runtime, sol);
    return 0;
}

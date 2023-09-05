#include <iostream>
#include <chrono>
#include <iomanip>

/*
 * --------------------------------
 * Problem: '3'
 * https://projecteuler.net/problem=3
 * --------------------------------
 * @amazzetta
 *
 * ################################
 * #  Problem 3
 * #  Solved in: 2 µs (0 ms)
 * #  Solution: 6857
 * ################################
 */

void print(double runtime, long int solution = 0)
{
    if ( solution == 0 )
    {
        std::cout << "\nSolution to problem 3 is not implemented yet!\n\n";
        return;
    }

    std::cout << "\n################################\n"
        << "#  Problem 3\n"
        << "#  Solved in: " << std::fixed << std::setprecision(0) << runtime << " µs (" << runtime / 1000 << " ms)\n"
        << "#  Solution: " << solution << "\n"
        << "################################\n";
}

// --------------------------------

template <typename T>
std::vector<T> prime_factors(T n)
{
    std::vector<T> factors;

    while ( n % 2 == 0 )
    {
        factors.push_back(2);
        n /= 2;
    }

    for ( T i = 3; i <= std::sqrt(n); i += 2 )
    {
        while ( n % i == 0 )
        {
            factors.push_back(i);
            n /= i;
        }
    }

    if ( n > 2 )
    {
        factors.push_back(n);
    }

    return factors;
}

unsigned long solution()
{
    return prime_factors(600851475143).back();
}

int main()
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    unsigned long sol = solution();

    double runtime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - begin).count();

    print(runtime, sol);
    return 0;
}

// --------------------------------
// default includes

#include <iostream>
#include <chrono>
#include <iomanip>

/*
 * --------------------------------
 * Problem: '97'
 * https://projecteuler.net/problem=97
 * --------------------------------
 * @amazzetta
 *
 * ################################
 * #  Problem 97
 * #  Solved in: 58752 µs (59 ms)
 * #  Solution: 8739992577
 * ################################
 */

void print(double runtime, long int solution = 0)
{
    if ( solution == 0 )
    {
        std::cout << "\nSolution to problem 97 is not implemented yet!\n\n";
        return;
    }

    std::cout << "\n################################\n"
        << "#  Problem 97\n"
        << "#  Solved in: " << std::fixed << std::setprecision(0) << runtime << " µs (" << runtime / 1000 << " ms)\n"
        << "#  Solution: " << solution << "\n"
        << "################################\n";
}

// --------------------------------

int main()
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    long long ten_digits = 1e10;

    long long solution = 1;
    for ( int i = 0; i < 7830457; i++ )
    {
        solution *= 2;
        solution %= ten_digits;
    }

    solution *= 28433;
    solution %= ten_digits;
    solution++;

    double runtime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - begin).count();
    print(runtime, solution);

    return 0;
}
